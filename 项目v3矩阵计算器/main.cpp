#include<iostream>
#include<string>
#include"resource.h"
#include"cacul.h"
using namespace std;
//���������
//����ʱ��2022.5.9��
int main()
{
	system("mode con cols=50 lines=25");
	/*cout <<left<< setw(12) << "35435" << setw(12) << "35435" << endl;
	cout << fixed << setprecision(2) << 2143423.4232 << endl;*/
	while (true)
	{
		system("cls");
		cout << "=============���������=============" << endl;
		char choice;
		cout << "��1����Ӿ���A" << endl;
		cout << "��0���˳�������" << endl;
		cout << "��p���˽����^" << endl;
		cin >> choice;
		getchar();
		switch (choice)
		{
		case '1':
			Aoperation();
			break;
		case '0':
			return 0;
		case 'p':
			cout << "====================================" << endl;
			cout << "ע�����" << endl;
			cout << "    ��Ҫ����Ҫ�������ֵ��������������ַ���������������ѭ���������" << endl;
			cout << "    ��ʹ�ù���������δ֪bug�뼰ʱ��������ϵ��qq1634770529" << endl;
			system("pause");
			break;
		default:
			cout << "����������ʵ�ѡ��Ŷ��" << endl;
			system("pause");
			break;
		}
	}
	

	return 0;
}
