#pragma once
#include <iostream>
#include <string>						// Ƕ���ַ���������

namespace dll {
	class DivideByZeroException {			// �����쳣��
		std::string message;				// �쳣��Ϣ
	public:
		DivideByZeroException() : message("����Ϊ�㣡") {};	// ���캯��
		std::string what() { return message; }
	};


	class DivideByZero {};				// ����һ�����࣬0������
	class OperationTypeNoExist {};		// ����һ�����࣬�������Ͳ�����
}