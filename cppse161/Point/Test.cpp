#include"Point.h"
//��3����ʹ���࣬�������󣬵��÷���
int main() {

	std::cout << "����ֱ�ӷ���" << std::endl;
	Point pnt("������",118.18F, 32.18F);//pnt����һ����Point��ʵ�����ĵ�
	pnt.ShowPoint();//��ʾ

	std::cout << "\n\n4���캯��������ʾ" << std::endl;
	Point pnt1;
	pnt1.ShowPoint();

	Point pnt2("ͼ���");
	pnt2.ShowPoint();

	Point pnt3(pnt);
	pnt3.ShowPoint();

	//ָ������ļ�ӷ�����ʾ
	std::cout << "\n\n1��ָ�����pPnt�ļ�ӷ���" << std::endl;
	Point * pPnt = &pnt;
	pPnt->ShowPoint();

	pPnt = &pnt1;
	pPnt->ShowPoint();

	pPnt = &pnt2;
	(*pPnt).ShowPoint();

	//���ñ�����Ӧ�ã�ȡ��ָ�룩
	std::cout << "\n\n������ñ���rPnt1,rPnt2,...��ֱ�ӷ��ʶ�Ӧ��������" << std::endl;
	Point & rPnt = pnt;
	rPnt.ShowPoint();

	Point & rPnt1 = pnt1;
	rPnt1.ShowPoint();

	Point & rPnt2 = pnt2;
	rPnt2.ShowPoint();

	system("pause");//��ͣ

	return 0;
}