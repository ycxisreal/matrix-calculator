#include<iostream>
#include<string>
#include<cmath>
#include"resource.h"
using namespace std;

void mat::showmat()//输出矩阵
{
	
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			cout << matrix[i][j]<<"  ";
		cout << endl;
	}
		
}
void mat::setmat()//写入矩阵
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> matrix[i][j];
}
void mat::operator =(mat b)
{
	this->r = b.r;
	this->c = b.c;
	for (int i = 0; i < b.r; i++)
		for (int j = 0; j < b.c; j++)
			this->matrix[i][j] = b.matrix[i][j];
}
mat operator *(int a, mat b)//数乘
{
	for(int i=0;i<b.r;i++)
		for (int j = 0; j < b.c; j++)
			b.matrix[i][j] = a * b.matrix[i][j];
	return b;
}
mat operator *(mat b,int a)//数乘逆序
{
	for (int i = 0; i < b.r; i++)
		for (int j = 0; j < b.c; j++)
			b.matrix[i][j] = a * b.matrix[i][j];
	return b;
}
mat operator *(mat a,mat b)
{
	mat c(a.r,b.c);
	double temp=0;
	for (int i = 0; i < a.r; i++)
	{
		for (int k = 0; k < b.c; k++)
		{
			for (int j = 0; j < a.c; j++)
				temp += a.matrix[i][j] * b.matrix[j][k];
			c.matrix[i][k] = temp;
			temp = 0;
		}
	}
	return c;
}
mat operator +(mat a,mat b)
{
	mat c(a.r,a.c);
	for (int i = 0; i < c.r; i++)
		for (int j = 0; j < c.c; j++)
			c.matrix[i][j] = a.matrix[i][j] + b.matrix[i][j];
	return c;
}
mat operator -(mat a,mat b)
{
	mat c = a + -1 * b;
	return c;
}
mat mat::mat_inverse()//求逆矩阵
{
	mat a(r, c);

	return a;
}
mat mat::mat_comp()//求伴随矩阵
{
	mat a(r,c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			mat b(r - 1, c - 1);//代数余子式矩阵b
			//构造代数余子式
			int column = 0;
			int row = 0;
			for (int k = 0; k < r; k++)
			{
				if (k == i)
					continue;
				for (int l = 0; l < c; l++)
				{
					if (l == j)
						continue;
					b.matrix[row][column] = matrix[k][l];
					column++;
				}
				column = 0;
				row++;
			}
			//求代数余子式值
			a.matrix[i][j] = pow(-1,i+j)*b.evaluation();
		}
	}
	return a;
}
double mat::evaluation(int ran)//求行列式的值,子函数
{
	//递归求解行列式的值
	double A=0;
	int rank = ran;
	if (rank == 1)
	{
		return matrix[0][0];
	}
	else if (rank == 2)
	{
		return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
	}
	else if (rank == 3)
	{
		double a = matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[1][0] * matrix[2][1] * matrix[0][2] + matrix[2][0] * matrix[0][1] * matrix[1][2];
		double b = matrix[2][0] * matrix[1][1] * matrix[0][2] + matrix[1][0] * matrix[0][1] * matrix[2][2] + matrix[0][0] * matrix[2][1] * matrix[1][2];
		return a - b;
	}
	else if (rank > 3)
	{
		//使最后一列中除最后一行外，全部消为0。
		//要新建一个矩阵保存信息，然后再传给递归函数使用！
		for (int i = 0; i < rank - 1; i++)
		{
			double a = matrix[i][rank - 1];
			for (int j = 0; j < rank; j++)
			{
				matrix[i][j] -= matrix[rank - 1][j] * matrix[i][rank - 1] / matrix[rank - 1][rank - 1];
				/*matrix[i][j] = matrix[i][j] * matrix[rank - 1][rank - 1] / matrix[i][rank - 1] ;
				matrix[i][j] -= matrix[rank - 1][j];*/
				/*if(a!= matrix[rank - 1][rank - 1])5
					matrix[i][j] *= a;*/
			}
		}
		return pow(-1, rank * rank) * matrix[rank-1][rank-1] * evaluation(rank - 1);
	}
}
double mat::evaluation()//求行列式的值，主函数
{
	double A;
	double M[20][20];
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			M[i][j] = matrix[i][j];
	A = evaluation(r);
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			matrix[i][j] = M[i][j];
	return A;
}