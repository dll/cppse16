#include "CMatrix.h"

void CMatrix::input()  //����   
{   cout<<"��ʼ�������ֵ��"<<endl;
int  i, j;
double  z;
for(i=0;i<row;i++)
{  cout<<"�������"<<i+1<<"�е�ֵ��"<<endl;
for(j=0;j<column;j++)
{	cin>>z;
A[i][j]=z;
}
}
cout<<endl;
}

CMatrix::CMatrix(const CMatrix& m)   // ���ƹ��캯��
{      int  i, j;
for(i=0;i<m.row;i++)
	for(j=0;j<m.column;j++)
	this->A[i][j]=m.A[i][j];
	
}

CMatrix&  CMatrix::operator=(const CMatrix& m)  // ��ֵ�����
{  
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
			A[i][j]=m.A[i][j];
	}
	return *this;
}

bool CMatrix::operator ==(const CMatrix& m)  // �����������
{   int i,j,k;
for(i=0;i<m.row;i++)
{ for(j=0;j<m.column;j++)
	if(this->A[i][j]=m.A[i][j])   k=1;
	else k=0;
}
if(k=1)  return true;
else   return false;

}

bool CMatrix::operator !=(const CMatrix& m)  // �����������
{   int i,j,k;
for(i=0;i<m.row;i++)
{ for(j=0;j<m.column;j++)
	if(this->A[i][j]=m.A[i][j])   k=1;
	else k=0;
}
if(k=0)  return true;
else   return false;

}

CMatrix CMatrix::operator+(const CMatrix& m)// �������
{  int i,j;
if((this->row==m.row)&&(this->column==m.column))
{  for(i=0;i<m.row;i++)
	for(j=0;j<m.column;j++)  
	this->A[i][j]+=m.A[i][j];
	
}  
else  {  cout<<"������������ӣ����飡"<<endl; }
return *this;
}

CMatrix CMatrix::operator-(const CMatrix& m)// �������
{  int i,j;
if((this->row==m.row)&&(this->column==m.column))
{  for(i=0;i<m.row;i++)
	for(j=0;j<m.column;j++)  
	this->A[i][j]-=m.A[i][j];
	
}  
else  {  cout<<"������������ӣ����飡"<<endl; }
return *this;
}

CMatrix& CMatrix::operator+=(const CMatrix& m)  //�Լ������
{  int i,j;
for(i=0;i<m.row;i++)
	for(j=0;j<m.column;j++)  
	this->A[i][j]=2*m.A[i][j];
	
	return *this;
}

CMatrix& CMatrix::operator-=(const CMatrix& m)   //�Լ������
{  int i,j;
for(i=0;i<m.row;i++)
	for(j=0;j<m.column;j++)  
	this->A[i][j]=m.A[i][j]-m.A[i][j];
	
	return *this;
}

void CMatrix::find(int& f)const
{   int i;
for(i=0;i<this->row;i++)
	if(this->A[i][i]!=0) f=1;
	else  f=0;
}

CMatrix CMatrix::operator-()   // ȡ����
{   int i,j;
for(i=0;i<this->row;i++)
	for(j=0;j<this->column;j++)  
	this->A[i][j]=-this->A[i][j];
	return *this;
}

CMatrix& CMatrix::operator*(const CMatrix& m) // �˷������
{   int i,j,t;
CMatrix n;	
if(this->column==m.row)
{   
	for(i=0;i<this->row;i++)
		for(j=0;j<m.column;j++)
	{	double sum=0.0;
	for(t=0;t<m.row;t++)
		sum+=this->A[i][t]*m.A[t][j];
		n.A[i][j]=sum;
	}
}
else {cerr<<"������������ˣ����飡"<<endl; exit(1);}
return n;
}

void CMatrix::outputMatrix()// ����þ���
{  int i,j;
for(i=1;i<=row;i++)
{ for(j=1;j<=column;j++)
	cout<<A[i-1][j-1]<<"      ";
	cout<<endl;
}
}

CMatrix& CMatrix::transpose()// ����ת��
{  int i,j;
CMatrix  m(this->column,this->row);
for(i=0;i<this->row;i++)
	for(j=0;j<this->column;j++)
{ m.A[j][i]=this->A[i][j];}
	return m;
	
}


void  jocabi(const CMatrix& a)    //��˹�������
{    int f=1;
a.find(f);
if(f==0)  {cerr<<"�þ�������������������"<<endl; exit(1); }
else
{
	CMatrix x,w;
	x.setColunm(1);
	x.setRow(a.getColumn());
	w.setColunm(1);
	w.setRow(a.getColumn());
	int i;
	double z;
	for(i=1;i<=x.row;i++)
	{ cout<<"�������ʽ�Ҳ�ĵ�"<<i<<"��ֵ��";
	cin>>z;
	w.A[i-1][0]=z;
	}
	for(i=1;i<=x.row;i++)
	{   cout<<"������X"<<i<<"�Ľ���ֵ��";
	cin>>z;
	x.setValue(i, 1, z);
	}
	
	i=1;
	while(i<=20)
	{  int j, k;		
	for(j=1;j<=x.row;j++)
	{   double sum=0.0;
	for(k=1;k<j;k++)
	{sum=sum-(a.A[j-1][k-1])*(x.A[k-1][0]);}
	for(k=j+1;k<=x.row;k++)
	{sum=sum-(a.A[j-1][k-1])*(x.A[k-1][0]);}
	sum+=w.A[j-1][0];
	x.A[j-1][0]=sum/a.A[j-1][j-1];
	}
	i++;
	}	
	for(i=1;i<=x.row;i++)
		  cout<<"X"<<i<<" = "<<x.A[i-1][0]<<endl;
}
}

double jdz(double a)   //����ֵ
{  if(a>0.0)  return a;
else  return -a;
}

CMatrix& CMatrix::change(int i, int j)//�����������
{  int k;
double z;
for(k=1;k<=this->column;k++)
{	z=A[i-1][k-1];
A[i-1][k-1]=A[j-1][k-1];
A[j-1][k-1]=z;
}
return *this;
}

void  CMatrix::lzys()                  //����Ԫ�ط����
{   CMatrix x,w;
x.setColunm(1);
x.setRow(getColumn());
w.setColunm(1);
w.setRow(getColumn());
int i;
double z;
for(i=0;i<row;i++)
{for(int j=0;j<row; j++)
	w.A[i][j]=0.0;
}
for(i=1;i<=x.row;i++)
	x.setValue(i, 1, 0.0);
for(i=1;i<=x.row;i++)
{ cout<<"�������ʽ�Ҳ�ĵ�"<<i<<"��ֵ��";
cin>>z;
w.A[i-1][0]=z;
}
i=0;
while(i<x.row-1)
{  int j,t,h=i;
for(j=i;j<x.row-1;j++)
{	if(jdz(A[j][i])<jdz(A[j+1][i]))  h=j+1;  }
this->change(i+1,h+1);
w.change(i+1,1);
for(j=i+1;j<row;j++)
{  double k;
k=A[j][i]/A[i][i];
for(t=i;t<column;t++)
{
	A[j][t]=A[j][t]-k*A[i][t];
}	  
w.A[j][0]=w.A[j][0]-k*w.A[i][0];
}
i++;    
}
if(this->A[row-1][column-1]==0)
{cerr<<"�˾����Ӧ�ķ�����������⣡"<<endl;  exit(1);}
i=column-1;
while(i>0)
{  int j, t;
for(j=i-1;j>=0;j--)
{  double k;
k=A[j][i]/A[i][i];
for(t=i;t>j;t--)
{ A[j][t]=A[j][t]-k*A[i][t];  }	 
w.A[j][0]=w.A[j][0]-k*w.A[i][0];
}
i--;    
}
int  j;
for(j=0;j<x.row;j++)
{
	x.A[j][0]=w.A[j][0]/this->A[j][j];
}
for(i=1;i<=x.row;i++)
	cout<<"X"<<i<<" = "<<x.A[i-1][0]<<endl;
};


CMatrix& CMatrix::inverse()   //��������
{   if(this->row!=this->column)  {cerr<<"�þ��󲻷�������������"<<endl;  exit(1);}
else
{
	CMatrix w;	
	w.setColunm(this->getRow());
	w.setRow(getColumn());
	int i;
	for(i=0;i<row;i++)
	{
		for(int j=0;j<row; j++)
		{w.A[i][j]=0.0;}
		w.A[i][i]=1;
	}			
	i=0;
	while(i<column-1)
	{  int j,t,h=i;
	for(j=i;j<row-1;j++)
	{
		if(jdz(A[j][i])<jdz(A[j+1][i]))  
			h=j+1;
	}
	this->change(i+1,h+1);
	w.change(i+1,h+1);
	for(j=i+1;j<row;j++)
	{  double k;
	k=A[j][i]/A[i][i];
	for(t=i;t<column;t++)
	{
		A[j][t]=A[j][t]-k*A[i][t];
		w.A[j][t]=w.A[j][t]-k*w.A[i][t];
	}	   
	}
	i++;    
	}
	if(this->A[row-1][column-1]==0)
	{cerr<<"�˾������治�ɹ���������Ӧ�ķ�����������⣡"<<endl;  exit(1);}
	i=column-1;
	while(i>0)
	{  int j, t;
	for(j=i-1;j>=0;j--)
	{  double k;
	k=A[j][i]/A[i][i];
	for(t=i;t>j;t--)
	{ A[j][t]=A[j][t]-k*A[i][t];  }	 
	for(t=column-1;t>=0;t--)
	{w.A[j][t]=w.A[j][t]-k*w.A[i][t];}
	}
	i--;    
	}
	int j,k;
	for(j=0;j<row;j++)
	{	for(k=0;k<w.column;k++)
	{w.A[j][k]=w.A[j][k]/this->A[j][j];}
	this->A[j][j]=this->A[j][j]/this->A[j][j];
	}
	return w;	
}
}

void  CMatrix::solve() //�������Ծ������
{  
	CMatrix x,w,c;
	x.setColunm(1);
	x.setRow(getColumn());
	w.setColunm(1);
	w.setRow(getColumn());
	c.setColunm(getColumn());
	c.setRow(getRow());
	int i;
	double z;
	for(i=1;i<=x.row;i++)
	{ cout<<"�������ʽ�Ҳ�ĵ�"<<i<<"��ֵ��";
	cin>>z;
	w.A[i-1][0]=z;
	}
	c.operator =(this->inverse());
	x.operator =(c.operator *(w));
	cout<<"�������"<<endl;
	for(i=1;i<=x.row;i++)
		cout<<"X"<<i<<" = "<<x.A[i-1][0]<<endl;
		
}

void CMatrix::qxnh()    //�������
{
	cout<<"�þ���������ϣ�"<<endl;
	int i, j,k,t;
	double x, y;
	cout<<"��������֪�����ĸ�����";
	cin>>i;
	CMatrix a(i,1), g(i,i) , w(i,1),c(i,i),q(i,i),p(i,i);
	for(j=1;j<=i;j++)
	{  cout<<"�������"<<j<<"����֪������(�Ⱥ������������)��";
	cin>>x>>y;
	w.A[j-1][0]=y;
	g.A[j-1][0]=1.0;
	for(k=1;k<i;k++)
	{  g.setValue(j,k+1,1.0);
	for(t=1;t<=k;t++)
		g.A[j-1][k]*=x;
	}  
	}  
	
	c=g.transpose();
	q=c*g;
	p=q.inverse();
	w=c*w;
	a=p*w;
	cout<<"Y="<<a.A[0][0];
	for(j=1;j<i;j++)
	{ cout<<'+'<<'('<<a.A[j][0]<<')';
	for(k=0;k<j;k++)
		cout<<"*x"; 	
	}
	cout<<endl;
	cout<<" 1 .��ȡ���������� 0. �˳� "<<endl;
	while(1)
	{  cout<<"��ѡ��";
	cin>>k;
	switch(k)
	{  case 1:
	{  double x, y,sum;
	cout<<"����������ĺ����꣨x����";
	cin>>x;
	y=a.A[0][0];
	for(j=1;j<i;j++)
	{	sum=a.A[j][0];
	for(k=0;k<j;k++)
	{sum*=x;}
	y+=sum;
	}
	cout<<"�����꣺y="<<y<<endl;
	break;
	}
	case 0: 
	{
		cerr<<"ллʹ�ã�"<<endl; exit(1);
		break;
	}
	default: cout<<"ѡ���������飡"<<endl;  break;
	}  
	}
}
