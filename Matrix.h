#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Matrix
{
public:
	Matrix();
	~Matrix();
	void inputMatrix();
	friend Matrix multiplyMatrix(Matrix&, Matrix&);
	Matrix operator=(Matrix);
	void outputMatrix();
	bool existOrNot();
private:
	int row, col;
	int* matrix;
	bool exist;
};
