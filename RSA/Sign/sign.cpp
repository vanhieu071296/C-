#include <iostream>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <string>
using namespace std;
/*
	thuat toan ma hoa Z26
	abcde....xyz
	01234....232425
*/
std::string Timkiemthaythe(std::string chuoi) 
{
	string output;
	for (int i = 0; i < chuoi.length(); i += 1)
	{
		if (chuoi[i] >= 'a' && chuoi[i] <= 'z')
			output += std::to_string(chuoi[i] - 'a');
		else output += std::to_string(chuoi[i] - '0');
	}
	return output;

}
long mod(long m, long e, long n) // thuat toan binh phuong - nhan.
{
	long a[100];
	long k = 0;
	do
	{
		a[k] = e % 2;
		k++;
		e = e / 2;
	} while (e != 0);

	//Qua trinh lay du
	long kq = 1;
	for (int i = k - 1; i >= 0; i--)
	{
		kq = (kq * kq) % n;
		if (a[i] == 1)
			kq = (kq * m) % n;
	}
	return kq;
}
int main()
{
	long a, c, e, m;

	char chuoi[1000];
	cout << "Giai thuat ky" << endl;
	cout << "Nhap chuoi can ma hoa: "; cin >> chuoi;
	cout << "Chuoi sau khi chuyen doi: " << Timkiemthaythe(chuoi) << endl;

	cout << "Nhap khoa cong khai:" << endl;
	cout << "e = "; cin >> e;
	cout << "a = "; cin >> a;
	cout << "Chia chuoi thanh nhieu doan nho, moi doan chua 3 ky tu." << endl;
	cout << "============================================================" << endl;
	for (;;)
	{
		cout << "m = "; cin >> m;
		if (m > 0)
		{

			c = mod(m, e, a);
			cout << "Doan chu ky C = " << c << endl;
			continue;
		}
		else break;
	}
	_getch();
	return 0;
}