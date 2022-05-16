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
	//赋值部分
	void setr(int a) { r = a; }
	void setc(int a) { c = a; }
	int getc() { return c; }
	int getr() { return r; }
	void setmat();
	void showmat();
	//运算部分
	friend mat operator *(mat a,mat b);//乘法
	friend mat operator *(double a, mat b);//左数乘
	friend mat operator *(mat b, double a);//右数乘
	friend mat operator +(mat a,mat b);//加法
	friend mat operator -(mat a,mat b);//减法
	mat mat_inverse();//求逆矩阵
	mat mat_comp();//求伴随矩阵
	double evaluation();//求行列式的值
	double evaluation(int ran);//求行列式的值,递归用子函数
	void operator =(mat b);
};