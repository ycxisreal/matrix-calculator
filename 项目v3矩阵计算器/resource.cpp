#include<iostream>
#include<string>
#include<cmath>
#include"resource.h"
using namespace std;

void mat::showmat()//�������
{
	
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			cout << matrix[i][j]<<"  ";
		cout << endl;
	}
		
}
void mat::setmat()//д�����
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
mat operator *(int a, mat b)//����
{
	for(int i=0;i<b.r;i++)
		for (int j = 0; j < b.c; j++)
			b.matrix[i][j] = a * b.matrix[i][j];
	return b;
}
mat operator *(mat b,int a)//��������
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
mat mat::mat_inverse()//�������
{
	mat a(r, c);

	return a;
}
mat mat::mat_comp()//��������
{
	mat a(r,c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			mat b(r - 1, c - 1);//��������ʽ����b
			//�����������ʽ
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
			//���������ʽֵ
			a.matrix[i][j] = pow(-1,i+j)*b.evaluation();
		}
	}
	return a;
}
double mat::evaluation(int ran)//������ʽ��ֵ,�Ӻ���
{
	//�ݹ��������ʽ��ֵ
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
		//ʹ���һ���г����һ���⣬ȫ����Ϊ0��
		//Ҫ�½�һ�����󱣴���Ϣ��Ȼ���ٴ����ݹ麯��ʹ�ã�
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
double mat::evaluation()//������ʽ��ֵ��������
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