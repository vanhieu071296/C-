// 123.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

int main()
{
	double diem;
	string xepLoai;
	cout << "Nhap diem: "; cin >> diem;
	xepLoai = (diem >= 5) ? "Dau" : "Rot";
	cout << xepLoai;
    return 0;
}

