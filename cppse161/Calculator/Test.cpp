#include "Calculator.hpp"
int main() {
	//Calculator cacl0(2,'A',3);//生成一个计算器对象
	//cout <<"计算结果为:"<< cacl0.calChoose_ie() << endl;
	/*
	Calculator cacl1(2,'+',3);		// 生成一个计算器对象
	cout<<"计算结果为："<< cacl1.calChoose_ie() << endl;
	Calculator cacl2(2,'-',3);		// 生成一个计算器对象
	cout<<"计算结果为："<< cacl2.calChoose_ie() << endl;
	Calculator cacl3(2,'*',3);		// 生成一个计算器对象
	cout<<"计算结果为："<< cacl3.calChoose_sc() << endl;
	Calculator cacl4(2,'/',3);		// 生成一个计算器对象
	cout<<"计算结果为："<< cacl4.calChoose_sc() << endl;

	Calculator cacl5 (2,'/', 0); // 生成一个计算器对象
	//cout <<"计算结果为："<< cacl5.calChoose_sc() << endl;
	//cout <<"计算结果为："<< cacl5.calChoose_exp() << endl;
	cout <<"计算结果为："<< cacl5.calChoose_exp1() << endl;

	try{					// 检测
		Calculator cacl5 (2,'/',0);		// 测试被0除操作
		cout << "计算结果为："<< cacl5.calChoose_exp2() << endl;
	}
	catch (int){				// 再捕获并处理int类型异常
		cerr << "除数为0" << endl;
	}

	try{
		Calculator cacl3 (2,'A',3);				// 测试不存在操作
		std::cout << "计算结果为："<< cacl3.calChoose_exp3() << std::endl;
		Calculator cacl4 (2,'/',0);				// 测试被0除
		std::cout << "计算结果为："<< cacl4.calChoose_exp3() << std::endl;
	}
	catch (int){						// 捕获并处理int类型异常
		cerr << "除数为0" << endl;
	}
	catch(char){ 						// 捕获并处理char类型异常
		cerr << "操作符输入错误!" << endl;
	}

	try{
		Calculator cacl3 (2,'A',3);		// 生成一个计算器对象
		std::cout << "计算结果为："<< cacl3.calChoose_exp4() << std::endl;
		Calculator cacl4 (2,'/',0);		// 生成一个计算器对象
		std::cout << "计算结果为："<< cacl4.calChoose_exp4() << std::endl;
	}
	catch (DivideByZeroException ex){		// 捕获并处理int类型异常
		cerr << "除数为0" << endl;
	}
	catch(char){ 				// 捕获并处理char类型异常
		cerr << "操作符输入错误!" << endl;
	}
	//测试被0除的主函数
	try{
		Calculator cacl4 (2,'/',0);		// 生成一个计算器对象
		std::cout << "计算结果为："<< cacl4.calChoose_exp5() << std::endl;
	}
	catch(DivideByZero){			// 捕获0除异常并处理
		std::cout << "除数为0！" << std::endl;
	}
	catch(OperationTypeNoExist)	{	// 捕获无操作类型异常并处理
		std::cout << "没有这种操作类型！" << std::endl;
	}
	//测试操作类型不存在
	try{
		Calculator cacl4 (2,'A',3);		// 生成一个计算器对象
		std::cout << "计算结果为："<< cacl4.calChoose_exp5() << std::endl;
	}
	catch(DivideByZero){
		std::cout << "除数为0！" << std::endl;
	}
	catch(OperationTypeNoExist)	{
		std::cout << "没有这种操作类型！" << std::endl;
	}*/

	//捕获任何异常...
	int number1, number2;
	char op;

	std::cout << "请输入一个算式：";
	std::cin >> number1 >> op >> number2;

	try {
		Calculator cacl(number1, op, number2);
		std::cout << "计算结果为：" << cacl.calChoose_exp5() << std::endl;
	}
	catch (DivideByZero) {
		std::cout << "除数为0！" << std::endl;
	}
	catch (OperationTypeNoExist) {
		std::cout << "没有这种操作类型！" << std::endl;
	}
	catch (...) {
		std::cout << "出现其它异常！" << std::endl;
	}

	return 0;
}