// LibEmployeeManage.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "LibEmployeeManage.h"


// ���ǵ���������һ��ʾ��
LIBEMPLOYEEMANAGE_API int nLibEmployeeManage=0;

// ���ǵ���������һ��ʾ����
LIBEMPLOYEEMANAGE_API int fnLibEmployeeManage(void)
{
    return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� LibEmployeeManage.h
CLibEmployeeManage::CLibEmployeeManage()
{
    return;
}
