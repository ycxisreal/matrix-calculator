#pragma once
#include<iostream>

class mat
{
private:
	int r;
	int c;
public:
	double matrix[20][20]{};
	mat() :
		r(0),c(0) {}
	mat(int a,int b):
		r(a),c(b) {}
	//��ֵ����
	void setr(int a) { r = a; }
	void setc(int a) { c = a; }
	int getc() { return c; }
	int getr() { return r; }
	void setmat();
	void showmat();
	//���㲿��
	friend mat operator *(mat a,mat b);//�˷�
	friend mat operator *(double a, mat b);//������
	friend mat operator *(mat b, double a);//������
	friend mat operator +(mat a,mat b);//�ӷ�
	friend mat operator -(mat a,mat b);//����
	mat mat_inverse();//�������
	mat mat_comp();//��������
	double evaluation();//������ʽ��ֵ
	double evaluation(int ran);//������ʽ��ֵ,�ݹ����Ӻ���
	void operator =(mat b);
};