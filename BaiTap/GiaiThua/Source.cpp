#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;
// Ham tinh n giai thua
float giaithua(float n)
{
	float kq = 1;
	for (int i = 1; i <= n; i++)
		kq = kq * i;
	return kq;
}
int main()
{
	float n;
	cin >> n;
	cout << giaithua(n);
	_getch();
}