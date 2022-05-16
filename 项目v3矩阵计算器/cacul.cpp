#include<iostream>
#include<string>
#include"cacul.h"
using namespace std;
void Aoperation()
{
	system("cls");
	cout << "输入矩阵行:" << endl;
	int r, c;
	cin >> r;
	cout << "输入矩阵列：" << endl;
	cin >> c;
	mat a(r, c);
	cout << "请依次输入矩阵A数字：" << endl;
	a.setmat();
	while (true)
	{
		system("cls");
		cout << "您输入的矩阵A如下：" << endl;
		a.showmat();
		cout << "===============================" << endl;
		cout << "选择计算类型：" << endl;
		cout << "【1】两矩阵四则运算+ - *" << endl;
		cout << "【2】行列式 |A|" << endl;
		cout << "【3】逆矩阵 " << endl;
		cout << "【4】伴随矩阵 A*" << endl;
		cout << "【5】数乘矩阵 2*A" << endl;
		cout << "【0】重新输入矩阵 or 退出" << endl;
		char choice;
		mat b(a.getr(), a.getc());
		cin >> choice;
		getchar();
		switch (choice)
		{
		case '1':
			AB(a);
			break;
		case '2':
			if (a.getc() != a.getr())
			{
				cout << "【此矩阵不是方阵，无法求其行列式！】" << endl;
				break;
			}
			cout << "【矩阵A的行列式的值为【 " << a.evaluation() << " 】" << endl;
			break;
		case '3':
			if (a.getc() != a.getr())
			{
				cout << "【此矩阵不是方阵，无法求其逆矩阵！】" << endl;
				break;
			}
			if (a.evaluation() == 0)
			{
				cout << "【该矩阵行列式为 0，无法求其逆矩阵！】" << endl;
			}
			cout << "【矩阵A的逆矩阵为：】" << endl;
			b = a.mat_inverse();
			b.showmat();
			break;
		case '4':
			if (a.getc() != a.getr())
			{
				cout << "【此矩阵不是方阵，无法求其伴随矩阵！】" << endl;
				break;
			}
			cout << "【矩阵A的伴随矩阵为：】" << endl;
			b = a.mat_comp();
			b.showmat();
			break;
		case '5':
			double num;
			cout << "[输入要乘以的数:";
			cin >> num;
			cout << endl;
			cout << "【A * " << num << "】= "<< endl;
			b = a * num;
			b.showmat();
			break;
		case '0':
			return;
		default:
			cout << "【请输入合适的数哦】" << endl;
				break;
		}
		system("pause");
	}
	
}
void AB(mat a)
{
	mat b,d;
	int r, c;
	string op=" ";
	string obj = " ";
	while (true)
	{
		system("cls");
		cout << "===============================" << endl;
		if (b.getc() != 0)
		{
			cout << "【A:】" << endl;
			a.showmat();
			cout << "【B:】" << endl;
			b.showmat();
		}
		if (op == " ")
		{
			cout << "支持的运算符* + -" << endl;
			cout << "运算格式 A   */+/-   矩阵B/数字" << endl;
			cout << "===============================" << endl;
		}
		cout << "运算式: A ";
		if (op == " ")
		{
			cin >> op;
			if (op != "*" && op != "+" && op != "-")
			{
				cout << "\n【请输入支持的运算符】" << endl;
				return;
			}
		}
		else
		{
			cout << op << " ";
		}
		if (b.getc() == 0)
		{
			if (op == "*")
			{
				cout << endl;
				cout << "输入矩阵B的行数：" << endl;
				cin >> r;
				cout << "输入矩阵B的列数：" << endl;
				cin >> c;
				b.setr(r);
				b.setc(c);
			}
			else
			{
				cout << endl;
				r = a.getr();
				c = a.getc();
				b.setr(r);
				b.setc(c);
			}

			cout << "请依次输入矩阵B数字：" << endl;
			b.setmat();
		}
		else
		{
			cout << "B =" << endl;
			if (op == "*")
			{
				if (a.getc() != b.getr())
				{
					cout << "【两矩阵行与列不对应！无法执行乘法操作。】" << endl;
					return;
				}
				d = a * b;
				d.showmat();
			}
			else if(op == "+")
			{
				d = a + b;
				d.showmat();
			}
			else if (op == "-")
			{
				d = a - b;
				d.showmat();
			}
			return;
		}
	}
}