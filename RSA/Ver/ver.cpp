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
	cout << "Xac minh chu ky." << endl;
	long  c, d, a, m;
	char chuoi[1000];
	cout << "Nhap chuoi ham bam: "; cin >> chuoi;
	cout << "Chuoi sau khi chuyen doi: " << Timkiemthaythe(chuoi) << endl;
	cout << "Giai ma" << endl;
	cout << "Nhap khoa bi mat:\nd = "; cin >> d;
	cout << "a = "; cin >> a;
	cout << "Nhap doan chu ky co 4 ky tu." << endl;
	cout << "============================================================" << endl;
	for (;;)
	{

		cout << "c = "; cin >> c;
		if (c > 0)
		{

			m = mod(c, d, a);
			cout << "Doan giai ma m = " << m << endl;
			continue;
		}
		else break;
	}
	_getch();
}