#ifndef PriorityCalcultor_H
#define PriorityCalcultor_H
class PriorityCalcultor{
public:	
	//���ַ����ı��ʽ�У���������ת�������� 
	double toNum(char*s, int &k);
	//�����������ȼ���������*/,+-,=�ȹ��ļ�
	int priority(char c);
	//˫ջ�����������ʽ
	void Calculator();
};
#endif

