#include "StackCalculator1.h"

double StackCalculator1::operator()(const string& equation) {
	//����ʽ������������0~9��.�����������+��-��*��/��(��)�����ԡ�=����β
	//Ϊ����ʽ�а��������ֺ�������ֱ�ջ
	//���ջջ����������¶�����������������ȼ��Ƚϣ�����¶����������ȼ��߾�ѹ��ջ��
	//����¶������������ȼ��;�����ջ�ڵ�������м��㣬����������ѹ������ջ
	stack<double> operand_stack;//����ջ
	stack<char> operator_stack;	//���ջ
	operator_stack.push('=');	//���ջ��Ԥ��ѹ��'='������������Ƚϲ���������ʽ��������'='ʱ���������
	
	string num;
	for (char c : equation) {
		if (c >= '0' && c <= '9' || c == '.') { //����
			num += c;
		}
		else {
			if (num != "") { //����һ��������
				operand_stack.push(atof(num.c_str()));
				num = "";
			}
			if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '=' ) { //���
				while (true) {
					char ct = operator_stack.top();
					
					if (precede(ct, c) < 0) {
						//�¶����������ȼ��ߣ������ջ
						operator_stack.push(c);
						break;
					}
					else if (precede(ct, c) > 0) {
						//�¶����������ȼ��ͣ�����ջ���������
						double num2 = operand_stack.top();
						operand_stack.pop();
						double num1 = operand_stack.top();
						operand_stack.pop();
						double num = calc(ct, num1, num2);
						operand_stack.push(num);
						operator_stack.pop();
					}
					else if (precede(ct, c) == 0) {
						//����¶�������Ϊ������'='�����Ӧ�����ջջ��ΪԤ��ѹ��Ľ�����'='
						//����¶�������Ϊ')'�����Ӧ�����ջջ��Ϊ'('
						operator_stack.pop();
						break;
					}
				}
			}
		}
	}
	
	return operand_stack.top();
}

int StackCalculator1::precede(char c1, char c2) {
	struct OPERATOR {
		char oper;			//�����
		int priority_left;	//�ȳ��ֵ�����������ȼ�
		int priority_right;	//����ֵ�����������ȼ�
	} operators[] = { { '+', 2, 1 }, { '-', 2, 1 }, { '*', 4, 3 }, { '/', 4, 3 }, { '(', 0, 5 }, { ')', 4, 0 }, { '=', 0, 0 } };
	
	auto it1 = find_if(begin(operators), end(operators), [c1](const OPERATOR& op) { return op.oper == c1; });
	auto it2 = find_if(begin(operators), end(operators), [c2](const OPERATOR& op) { return op.oper == c2; });
	return it1->priority_left - it2->priority_right;
}

double StackCalculator1::calc(char oper, double num1, double num2) {
	switch (oper) {
	case '+': return num1 + num2;
	case '-': return num1 - num2;
	case '*': return num1 * num2;
	case '/': return num1 / num2;
	}
}
