#include <iostream>
#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
	char name[100];
	char loaiLD;
	float  nLV, tienThuong;
	cout << "Nhap ho ten cong nhan: "; cin >> name;
	cout << "Loai lao dong: "; cin >> loaiLD;
	cout << "Noi lam viec: "; cin >> nLV;
	
	if (nLV == 1)
	{
		switch (loaiLD)
		{
		case 'A': tienThuong = 4 * 12000; break;
		case 'a': tienThuong = 4 * 12000; break;
		case 'B': tienThuong = 3 * 12000; break;
		case 'b': tienThuong = 3 * 12000; break;
		case 'C': tienThuong = 2 * 12000; break;
		case 'c': tienThuong = 2 * 12000; break;
		}
	}
	else if (nLV == 2)
	{
		switch (loaiLD)
		{
		case 'A': tienThuong = 5 * 12000; break;
		case 'a': tienThuong = 5 * 12000; break;
		case 'B': tienThuong = 3.5 * 12000; break;
		case 'b': tienThuong = 3.5 * 12000; break;
		case 'C': tienThuong = 2.5 * 12000; break;
		case 'c': tienThuong = 2.5 * 12000; break;
		}
	}
	cout << "Tien Thuong: " << tienThuong << endl;
	_getch();
	return 0;
}