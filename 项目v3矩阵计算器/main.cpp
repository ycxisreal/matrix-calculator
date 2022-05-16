#include<iostream>
#include<string>
#include"resource.h"
#include"cacul.h"
using namespace std;
//矩阵计算器
//设想时间2022.5.9晚
int main()
{
	system("mode con cols=50 lines=25");
	/*cout <<left<< setw(12) << "35435" << setw(12) << "35435" << endl;
	cout << fixed << setprecision(2) << 2143423.4232 << endl;*/
	while (true)
	{
		system("cls");
		cout << "=============矩阵计算器=============" << endl;
		char choice;
		cout << "【1】添加矩阵A" << endl;
		cout << "【0】退出计算器" << endl;
		cout << "【p】了解程序^" << endl;
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
			cout << "注意事项：" << endl;
			cout << "    不要在需要输入数字的情况输入非数字字符，否则会出现无限循环的情况。" << endl;
			cout << "    在使用过程中遇到未知bug请及时与作者联系，qq1634770529" << endl;
			system("pause");
			break;
		default:
			cout << "【请输入合适的选项哦】" << endl;
			system("pause");
			break;
		}
	}
	

	return 0;
}
