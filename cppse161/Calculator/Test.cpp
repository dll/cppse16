#include "Calculator.hpp"

using namespace dll;
using namespace std;

void Test_calChoose_exp2() {
	try {// 检测
		Calculator cacl5(2, '/', 0);		// 测试被0除操作
		cout << "计算结果为：" << cacl5.calChoose_exp2() << endl;
	}
	catch (int) {				// 再捕获并处理int类型异常
		cerr << "除数为0" << endl;
	}
}
void Test_calChoose_exp3() {
	try {
		Calculator cacl3(2, 'A', 3);				// 测试不存在操作
		std::cout << "计算结果为：" << cacl3.calChoose_exp3() << std::endl;
		Calculator cacl4(2, '/', 0);				// 测试被0除
		std::cout << "计算结果为：" << cacl4.calChoose_exp3() << std::endl;
	}
	catch (int) {						// 捕获并处理int类型异常
		cerr << "除数为0" << endl;
	}
	catch (char) { 						// 捕获并处理char类型异常
		cerr << "操作符输入错误!" << endl;
	}
}
void Test_calChoose_exp4() {
	try {
		Calculator cacl3(2, 'A', 3);		// 生成一个计算器对象
		std::cout << "计算结果为：" << cacl3.calChoose_exp4() << std::endl;
		Calculator cacl4(2, '/', 0);		// 生成一个计算器对象
		std::cout << "计算结果为：" << cacl4.calChoose_exp4() << std::endl;
	}
	catch (DivideByZeroException ex) {		// 捕获并处理int类型异常
		cerr << "除数为0" << endl;
	}
	catch (char) { 				// 捕获并处理char类型异常
		cerr << "操作符输入错误!" << endl;
	}
}
void Test_calChoose_exp5() {
	//测试被0除的主函数
	try {
		Calculator cacl4(2, '/', 0);		// 生成一个计算器对象
		std::cout << "计算结果为：" << cacl4.calChoose_exp5() << std::endl;
	}
	catch (DivideByZero) {			// 捕获0除异常并处理	
		std::cout << "除数为0！" << std::endl;
	}
	catch (OperationTypeNoExist) {	// 捕获无操作类型异常并处理
		std::cout << "没有这种操作类型！" << std::endl;
	}
	//测试操作类型不存在
	try {
		Calculator cacl4(2, 'A', 3);		// 生成一个计算器对象
		std::cout << "计算结果为：" << cacl4.calChoose_exp5() << std::endl;
	}
	catch (DivideByZero) {
		std::cout << "除数为0！" << std::endl;
	}
	catch (OperationTypeNoExist) {
		std::cout << "没有这种操作类型！" << std::endl;
	}
}
void Test_calChoose_mulExpress1() {
	double number1, number2, result;
	char op;
	std::cout << "多算式1：数据成员number1存储中间结果\n请输入一个算式：";
	std::cin >> number1 >> op >> number2;
	dll::Calculator cacl1(number1, op, number2);
	std::cout << "计算结果为：" << (number1 = cacl1.Calculate()) << std::endl;
	std::cin >> op >> number2;
	dll::Calculator cacl2(op, number2);//重载构造函数
	std::cout << "计算结果为：" << (number1 = cacl2.Calculate()) << std::endl;
	std::cin >> op >> number2;
	dll::Calculator cacl3(op, number2);//重载构造函数
	std::cout << "计算结果为：" << cacl3.Calculate() << std::endl;
}
void Test_calChoose_mulExpress2() {
	double number1, number2, result;
	char op;
	std::cout << "\n\n多算式2：静态局部变量存储中间结果\n请输入一个算式：";
	std::cin >> number1 >> op >> number2;
	dll::Calculator cacl11(number1, op, number2);
	std::cout << "计算结果为：" << cacl11.Calculate() << std::endl;
	std::cin >> op >> number2;
	dll::Calculator cacl22(op, number2);//重载构造函数
	std::cout << "计算结果为：" << cacl22.Calculate() << std::endl;
	std::cin >> op >> number2;
	dll::Calculator cacl33(op, number2);//重载构造函数
	std::cout << "计算结果为：" << cacl33.Calculate() << std::endl;
	}
void Test_calChoose_mulExpress3() {
		double number1, number2, result;
		char op;
		std::cout << "\n\n多算式3：静态成员变量存储中间结果\n请输入一个算式：";
		std::cin >> number1 >> op >> number2;
		dll::Calculator cacl111(number1, op, number2);
		std::cout << "计算结果为：" << cacl111.Calculate() << std::endl;
		std::cin >> op >> number2;
		dll::Calculator cacl222(op, number2);//重载构造函数
		std::cout << "计算结果为：" << cacl222.Calculate() << std::endl;
		std::cin >> op >> number2;
		dll::Calculator cacl333(op, number2);//重载构造函数
		std::cout << "计算结果为：" << cacl333.Calculate() << std::endl;
	}

void Test_calChoose_mulExpress4() {
		double number1, number2, result;
		char op;
		std::cout << "\n\n任意多算式4：重复结构while\n请输入一个算式：";
		try {			std::cin >> number1 >> op >> number2;			Calculator cal444(number1, op, number2);			result = cal444.Calculate();			while (std::cin >> op, op != '=') {				std::cin >> number2;				Calculator cal444(op, number2);				result = cal444.Calculate();				std::cout << "计算结果：" << result << std::endl;			}
		}
		catch (DivideByZero) {
			std::cout << "除数为0！" << std::endl;
		}
		catch (dll::OperationTypeNoExist) {
			std::cout << "没有这种操作类型！" << std::endl;
		}
		catch (...) {
			std::cout << "出现其它异常！" << std::endl;
		}
		std::cout << "计算结果：" << result << std::endl;
	}

void Test_calChoose_mulExpress5() {
		double number1, number2, result;
		char op;
		std::cout << "\n\n任意多算式5：重复结构do-while\n";
		try {			std::cout << "请输入被操作数和操作符：";			std::cin >> result >> op;			/*while (std::cin >> op, op != '=') {*/			do {				std::cout << "请输入操作数:" << std::endl;				std::cin >> number2;				Calculator cal555(result, op, number2);				result = cal555.Calculate();				std::cout << "此步骤计算结果：" << result << std::endl;				std::cout << "请输入操作符:" << std::endl;			} while (std::cin >> op, op != '=');//有分号
		}
		catch (DivideByZero) {
			std::cout << "除数为0！" << std::endl;
		}
		catch (dll::OperationTypeNoExist) {
			std::cout << "没有这种操作类型！" << std::endl;
		}
		catch (...) {
			std::cout << "出现其它异常！" << std::endl;
		}
		std::cout << "最后计算结果：" << result << std::endl;
	}

int main () {
	//Calculator cacl0(2,'A',3);//生成一个计算器对象
	//cout <<"计算结果为:"<< cacl0.calChoose_ie() << endl;
	Calculator cacl1(2,'+',3);		
	cout<<"计算结果为："<< cacl1.calChoose_ie() << endl;
	Calculator cacl2(2,'-',3);		
	cout<<"计算结果为："<< cacl2.calChoose_ie() << endl;
	Calculator cacl3(2,'*',3);		

	cout<<"计算结果为："<< cacl3.calChoose_sc() << endl;
	Calculator cacl4(2,'/',3);		
	cout<<"计算结果为："<< cacl4.calChoose_sc() << endl;
	
	//Calculator cacl5 (2,'/', 0);
	//cout <<"计算结果为："<< cacl5.calChoose_ie() << endl;
	//cout << "计算结果为：" << cacl5.calChoose_sc() << endl;
	//cout <<"计算结果为："<< cacl5.calChoose_exp() << endl;
	//cout <<"计算结果为："<< cacl5.calChoose_exp1() << endl;
	
	Test_calChoose_exp2();
	/*Test_calChoose_exp3();
	Test_calChoose_exp4();
	Test_calChoose_exp5();

	Test_calChoose_mulExpress1();
	Test_calChoose_mulExpress2();
	Test_calChoose_mulExpress3();
	Test_calChoose_mulExpress4();
	Test_calChoose_mulExpress5();
	*/
	std::system("pause");//暂停，避免直接退出系统，方便观察结果

	return 0;
}
