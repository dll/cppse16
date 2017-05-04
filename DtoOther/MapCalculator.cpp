#include "MapCalculator.h"

MapCalculator::MapCalculator() {
	mapping.insert({1,"+"}); 
	mapping.insert({1,"-"}); 
	mapping.insert({2,"*"}); 
	mapping.insert({2,"%"}); 
	mapping.insert({2,"/"}); 
	mapping.insert({3,"^"}); 
	mapping.insert({0,"("}); 
	mapping.insert({0,")"}); 
	mapping.insert({-1,"|"}); 
}


void MapCalculator::transform(string expStr){ 
		string chs=expStr; 
		for(int i=0;i<chs.length();i++){ 
			string s=string.valueOf(chs[i]); 
			if(!mapping.containsKey(s)){ 
				exps.add(s); 
			}else{ 
				if("(".equals(s)){ 
					oper.add(s); 
				}else if(")".equals(s)){ 
					while(oper.size()>0 && !oper.peek().equals("(")){ 
						exps.add(oper.pop()); 
					} 
					oper.pop(); 
				}else{ 
					if(oper.isEmpty()){ 
						oper.add(s); 
					}else{ 
						int curOp=mapping.get(s); 
						int topOp=mapping.get(oper.peek()); 
						if(curOp>topOp){ 
							oper.add(s); 
						}else{ 
							do{ 
								exps.add(oper.pop()); 
							}while(oper.size()>0 && (curOp<=mapping.get(oper.peek()))); 
							oper.add(s); 
						} 
					} 
				} 
			} 
		} 
		while(oper.size()>0){ 
			exps.push(oper.pop()); 
		} 
		
		while(exps.size()>0){ 
			oper.push(exps.pop()); 
		} 
		printExp(); 
		calculate(); 
		System.out.println(exps.toString()); 
	} 
	
void MapCalculator::calculate(){ 
		while(oper.size()>0){ 
			string op=oper.pop(); 
			if(mapping.containsKey(op)){ 
				double d=calculate(op,Double.parseDouble(exps.pop()),Double.parseDouble(exps.pop())); 
				System.out.println(d); 
				exps.push(string.valueOf(d)); 
			}else{ 
				exps.push(op); 
			} 
		} 
	} 

void MapCalculator::printExp(){ 
		cout<<exps<<endl; 
} 
	
double MapCalculator::calculate(string op,double d1, double d2){ 
		if(op.compare("+")){ 
			return d1+d2; 
		} 
		if(op.compare("-")){ 
			return d1-d2; 
		} 
		if(op.compare("*")){ 
			return d1*d2; 
		} 
		if(op.compare("/")){ 
			return d1/d2; 
		} 
		if(op.compare("%")){ 
			return (int)d1%(int)d2; 
		} 
		if(op.compare("^")){ 
			return Math.pow((int)d1, (int)d2); 
		} 
		return 0; 
} 
