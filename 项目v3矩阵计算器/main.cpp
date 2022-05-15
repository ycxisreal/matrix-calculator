#include<iostream>
#include<string>
#include"resource.h"
using namespace std;
//矩阵计算器
//设想时间2022.5.9晚
int main()
{
	/*cout <<left<< setw(12) << "35435" << setw(12) << "35435" << endl;
	cout << fixed << setprecision(2) << 2143423.4232 << endl;*/

	cout << "=============矩阵计算器=============" << endl;
	int r, c;
	cin >> r;
	cin >> c;
	mat a(r, c);
	cout << "输入矩阵：" << endl;
	a.setmat();
	cout << "伴随：" << endl;
	mat b = a.mat_comp();
	b.showmat();

	return 0;
}