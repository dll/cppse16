#ifndef STACKCALCULATOR_H
#define STACKCALCULATOR_H
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cstdlib>

using namespace std;

class StackCalculator {
	struct OPERATOR {
		char oper;			//�����
		int priority_left;	//�ȳ��ֵ�����������ȼ�
		int priority_right;	//����ֵ�����������ȼ�
	};
	
	int operator_loc(vector<OPERATOR>& ov, char c) {
		int i = 0;
		for (vector<OPERATOR>::const_iterator it = ov.begin(); it != ov.end(); ++it) {
			if (it->oper == c) break;
			++i;
		}
		return i;
	}
	
	double calc(char oper, double num1, double num2) {
		double num = 0;
		switch (oper) {
		case '+': num = num1 + num2; break;
		case '-': num = num1 - num2; break;
		case '*': num = num1 * num2; break;
		case '/': num = num1 / num2; break;
		}
		return num;
	}
	
public:
	double operator()(string equation) {
		//����ʽ������������0~9��.�����������+��-��*��/��(��)�����ԡ�=����β
		//Ϊ����ʽ�а��������ֺ�������ֱ�ջ
		//���ջջ����������¶�����������������ȼ��Ƚϣ�����¶����������ȼ��߾�ѹ��ջ��
		//����¶������������ȼ��;�����ջ�ڵ�������м��㣬����������ѹ������ջ
		vector<OPERATOR> operator_vector = { { '+', 2, 1 },{ '-', 2, 1 },{ '*', 4, 3 },{ '/', 4, 3 },{ '(', 0, 5 },{ ')', 4, 0 },{ '=', 0, 0 } };
		stack<char> operator_stack;	//���ջ
		operator_stack.push('=');	//���ջ��Ԥ��ѹ��'='������������Ƚϲ���������ʽ��������'='ʱ���������
		stack<double> operand_stack;//����ջ
		
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
				if (operator_loc(operator_vector, c) != operator_vector.size()) { //���
					while (true) {
						char ct = operator_stack.top();
						int i = operator_loc(operator_vector, ct);	//���ջջ��Ԫ���ڲ����������е�λ��
						int j = operator_loc(operator_vector, c);	//�ն���Ĳ������ڲ����������е�λ��
						
						if (operator_vector[i].priority_left < operator_vector[j].priority_right) {
							//�¶����������ȼ��ߣ������ջ
							operator_stack.push(c);
							break;
						}
						else if (operator_vector[i].priority_left > operator_vector[j].priority_right) {
							//�¶����������ȼ��ͣ�����ջ���������
							double num2 = operand_stack.top();
							operand_stack.pop();
							double num1 = operand_stack.top();
							operand_stack.pop();
							double num = calc(ct, num1, num2);
							operand_stack.push(num);
							operator_stack.pop();
						}
						else if (operator_vector[i].priority_left == operator_vector[j].priority_right) {
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
};

#endif

