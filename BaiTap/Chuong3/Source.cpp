
#include<iostream>
#include<math.h>
#include<conio.h>
#include <stdio.h>
using namespace std;
int max(int a, int b)
{
	int max;
	if (a > b)max = a;
	else max = b;
	return max;
}
int main()
{// bai 3.2 dien tich tam giac
	/*double a, b, c, h, p, S;
	cout << "nhap ba canh tam giac: " << endl;
	cin >> a; cin >> b; cin >> c; 
	if (a > 0 && b > 0 && c > 0 && a + b > c && b + c > a && c + a > b)
	{
		cout << "tam giac ABC" << endl;
		p = (a + b + c) / 2;
		S = sqrt(p*(p - a)*(p - b)*(p - c));
		h = (2 * S) / a;
		cout << "dien tich tam giac ABC la: " << S << endl;
		cout << "chieu cao tam ABC la: " << h << endl;
	}
	else cout << "khong phai la mot tam giac." << endl;*/
	// bai 3,5 phuong trinh bac hai.
	/*float a, b, c;
	cout << "nhap ba gia tri a, b, c: " << endl;
	cin >> a; cin >> b; cin >> c;
	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
				cout << "phuong trinh vo so nghiem." << endl;
			else cout << "phuong trinh vo nghiem." << endl;
		}
		else
		{
			float x= -c/b;
			cout << "phuong trinh co mot nghiem la: " << x << endl;
		}
	}
	else
	{
		double denta = b*b - 4 * a*c;
//		float x1, x2;
		if (denta == 0)
			cout << "phuong trinh co nghiem kep la" << (-b /2*a) << endl;
		else if (denta < 0)
			cout << "phuong trinh vo nghiem" << endl;
		else if (denta > 0)
		{
			cout << "nghiem x1 la: " << (double((sqrt(denta) - b) / 2 * a)) << endl;
			cout << "nghiem x2 la: " << (double((-sqrt(denta) - b) / 2 * a)) << endl;
		}
	}*/
	//bai 3.1
/*	char name[100];
	float d1, d2, d3, d, kq;
	cout << "Nhap ten thi sinh: "; cin >> name;
	cout << "Nhap diem mon thu nhat D1: "; cin >> d1;
	cout << "Nhap diem mon thu hai D2: "; cin >> d2;
	cout << "Nhap diem mon trac nghiem tong hop D3: "; cin >> d3;

	d = ((d1 / 3) + (d2 / 3) + (d3 / 3));
	kq = max(d, d3); // dung ham max so sanh d va d3

	if (d1 > 10 && d2 > 10 && d3 > 10) cout << "Nhap sai diem";
	else if (d1 <= 10 && d2 <= 10 && d3 <= 10 && kq >= 5)
	{
		cout << "Diem ket qua: " << kq << endl;
		cout << "Thi sinh " << name << " da dau." << endl;
	}
	else cout << "Thi sinh "<<name<< " khong dau." << endl;
*/	


	_getch();
	return 0;
}