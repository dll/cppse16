#include "CElevationNet.h"


void CElevationNet::input()
{  int a,b,c,i;
double z,l,g;
cout<<"请对已知点和未知点进行编号，注意已知点的编号应小于未知点的编号！"<<endl<<endl;
cout<<"请输入控制网中水准点总数和已知点数：";
cin>>a>>b;
numPoints=a;
numKnPoint=b;
for(i=0;i<numPoints;i++)
{ lpVec[i].index=i+1;
lpVec[i].eleValue=0.0;
lpVec[i].dv=0.0;
lpVec[i].isKnown=0;
}
for(i=0;i<numKnPoint;i++)
{ cout<<"请输入第"<<i+1<<"个已知点高程值：";
cin>>z;
lpVec[i].eleValue=z;
lpVec[i].isKnown=1;
}
cout<<"请输入观测值个数：";
cin>>c;
numElvDif=c;
for(i=0;i<numElvDif;i++)
{  cout<<"请输入第"<<i+1<<"段观测段的高差值(单位米)、长度(单位千米)、起始点编号和终点编号："<<endl;
cin>>g>>l>>a>>b;
edVec[i].value=g;
edVec[i].weight=l;
edVec[i].startPoint=a;
edVec[i].endPoint=b;
}
}

void CElevationNet::output()
{
	int i;
	for(i=0;i<this->numPoints;i++)
		cout<<"编号为"<<this->lpVec[i].index<<"的点的高程值为："<<this->lpVec[i].eleValue<<endl;
	for(i=0;i<this->numElvDif;i++)
		cout<<"观测段"<<i+1<<"的平差后的值为："<<this->edVec[i].value<<endl;
}
void  CElevationNet::jsgc()
{    int i,j;
for(i=0;i<this->numElvDif;i++)
{  if((lpVec[edVec[i].startPoint-1].eleValue!=0.0)&&(lpVec[edVec[i].endPoint-1].eleValue==0.0))
{lpVec[edVec[i].endPoint-1].eleValue=(lpVec[edVec[i].startPoint-1].eleValue)+(edVec[i].value);}
else if(lpVec[edVec[i].startPoint-1].eleValue==0.0&&lpVec[edVec[i].endPoint-1].eleValue!=0.0)
{lpVec[edVec[i].startPoint-1].eleValue=(lpVec[edVec[i].endPoint-1].eleValue)-(edVec[i].value);}
}

for(j=numKnPoint;j<this->numPoints;j++)
{ 
	if(this->lpVec[j].eleValue==0.0)
	{
		for(i=0;i<this->numElvDif;i++)
		{  if(this->edVec[i].startPoint==lpVec[j].index&&this->lpVec[this->edVec[i].endPoint-1].eleValue!=0.0)
			this->lpVec[j].eleValue=this->lpVec[this->edVec[i].endPoint-1].eleValue-this->edVec[i].value;
		else  if(this->edVec[i].endPoint==lpVec[j].index&&this->lpVec[this->edVec[i].startPoint-1].eleValue!=0.0)
		{this->lpVec[j].eleValue=this->lpVec[this->edVec[i].startPoint-1].eleValue+this->edVec[i].value;}
		}
	}
	//cout<<"第"<<this->lpVec[j].index<<"个点的高程近似值："<<this->lpVec[j].eleValue<<endl;
}

}

void xishu(CMatrix& B, CMatrix& X,CElevationNet A)
{
	int i,j;
	for(i=1;i<=B.getRow();i++)
		for(j=1;j<=B.getColumn();j++)
	{ B.setValue(i,j,0);}
		for(i=0;i<A.numElvDif;i++)
		{  if(A.lpVec[A.edVec[i].startPoint-1].isKnown==1&&A.lpVec[A.edVec[i].endPoint-1].isKnown==0)
		{B.setValue(i+1,A.edVec[i].endPoint-A.numKnPoint,1);}
		else  if(A.lpVec[A.edVec[i].startPoint-1].isKnown==0&&A.lpVec[A.edVec[i].endPoint-1].isKnown==1)
		{  B.setValue(i+1,A.edVec[i].startPoint-A.numKnPoint,-1);}
		else  if(A.lpVec[A.edVec[i].startPoint-1].isKnown==0&&A.lpVec[A.edVec[i].endPoint-1].isKnown==0)
		{ B.setValue(i+1,A.edVec[i].endPoint-A.numKnPoint,1);
		B.setValue(i+1,A.edVec[i].startPoint-A.numKnPoint,-1);
		}
		}  
		for(i=0;i<X.getRow();i++)
			X.setValue(i+1,1,A.lpVec[A.numKnPoint+i].eleValue);
		
}

void  quanzhen(CMatrix& Q, CElevationNet A)
{
	int i,j;
	double sum=0.0;
	for(i=0;i<A.numElvDif;i++)  
		sum+=A.edVec[i].weight;
	sum=sum/A.numElvDif;
	for(i=1;i<=Q.getRow();i++)
		for(j=1;j<=Q.getColumn();j++)
	{ Q.setValue(i,j,0);}
		for(i=1;i<=Q.getRow();i++)
			Q.setValue(i,i,sum/A.edVec[i-1].weight);
}

void  l_zhen(  CMatrix& l ,CMatrix& L, CElevationNet A)
{   
	int i;
	double m;
	for(i=0;i<A.numElvDif;i++)
		L.setValue(i+1,1,A.edVec[i].value);	  
	for(i=0;i<l.getRow();i++)
	{
		m=(A.lpVec[A.edVec[i].startPoint-1].eleValue+A.edVec[i].value-A.lpVec[A.edVec[i].endPoint-1].eleValue)*1000;
		l.setValue(i+1,1,m);
	}	
}
