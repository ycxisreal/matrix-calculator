#include<iostream>
#include<string>
#include"resource.h"
using namespace std;
//���������
//����ʱ��2022.5.9��
int main()
{
	/*cout <<left<< setw(12) << "35435" << setw(12) << "35435" << endl;
	cout << fixed << setprecision(2) << 2143423.4232 << endl;*/

	cout << "=============���������=============" << endl;
	int r, c;
	cin >> r;
	cin >> c;
	mat a(r, c);
	cout << "�������" << endl;
	a.setmat();
	cout << "���棺" << endl;
	mat b = a.mat_comp();
	b.showmat();

	return 0;
}