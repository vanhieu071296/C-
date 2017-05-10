#include <iostream>
#include <conio.h>
#include <math.h>
#include <stdio.h>
using namespace std;
int GCD(int a, int b) //Tim uoc chung lon nhat
{
	while (b != 0)
	{
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}
int main()
{
	int p, q, a, b, d, e, x;
	cout << "Nhap 2 so nguyen q va p.\n";
	cout << "q = "; cin >> q;
	cout << "p = "; cin >> p;
	a = q*p; b = (p - 1)*(q - 1);
	cout << "chon e ( 1 < e < " << b << " && UCLN(e," << b << ") = 1 ): "; cin >> e;
	x = GCD(e, b);
	if (x = 1)
	{
		for (int i = 1; i < a; i++)
		{
			if ((i*e) % b == 1)
			{
				d = i;
				cout << "Private Key d =" << d << "." << endl;
				cout << "Public Key e =" << e << ", a = " << a << "." << endl;
				break;
			}
		}
	}

	_getch();
	return 0;

}