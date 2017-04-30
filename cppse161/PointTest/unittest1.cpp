#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Point/Point.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PointTest
{		
	TEST_CLASS(UnitTest1)
	{
	private:
		Point *p1, *p2;
	public:
		TEST_METHOD_INITIALIZE(SetUp)
		{
			p1 = new Point("1",1,1);
			p2 = new Point("2",2,2);
			Logger::WriteMessage("Test initialized.\n"); //用于输出信息  
		}
		TEST_METHOD_CLEANUP(TearDown)
		{
			delete p1;
			delete p2;
			Logger::WriteMessage("Test completed.\n");
		}
		TEST_METHOD(TestisEqual)
		{
			// TODO: 在此输入测试代码
			Assert::AreEqual<bool>(false, p1->isEqual(*p2));
			Logger::WriteMessage("isEqual tested.\n");
		}

	};
}