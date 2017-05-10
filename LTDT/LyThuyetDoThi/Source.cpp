#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <string>
#define Filename "input.txt"
#define max 100
#define maxV 100 // So dinh toi da
#define TRUE 1 
#define FALSE 0
using namespace std;
struct topType {
	int stt;
	int bac;
	int mau;
};
topType myTop[max];
// G: ma tran ke cua do thi G, n: so dinh
int G[max][max], n;
int chuaxet[maxV], QUEUE[maxV];


void readFile(char * name, int G[max][max], int &n) 
{
	/**< Ham dung de lay thong tin tu file */
	ifstream myFile(name);
	if (!myFile) 
	{
		cout << "tap tin " << name << " khong ton tai, hay tao ngay! ";
		return;
	}
	myFile >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			myFile >> G[i][j];
}

void printMatrix(int G[max][max], int n) {
	/**< Ham dung de in ra ma tran  */
	int i, j;
	for ( i = 0; i < n; i++) 
	{
		for ( j = 0; j < n; j++) 
		{
			cout << " " << G[i][j] << "\t";
		}
		cout << endl;
	}
}
// Inport File
void importFile(int a[max][max])
{
	readFile("input.txt", a, n);
	printMatrix(a, n);
}
// Nhap ma tran ke
void nhapmang(int a[][max])
{
	int i, j;
	cout << " Nhap vao so dinh cua do thi : ";
	cin >> n;
	cout << " Nhap vao nua tren cua ma tran : " << endl;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			cout << " a[" << i << "][" << j << "] ";
			cin >> a[i][j];
			a[j][i] = a[i][j];
		}
		a[i][i] = 0;
	}
}
// In ma tran ke
void inmang(int a[][max])
{
	int i, j;
	cout << " Ma tran vua nhap la : " << endl;
	for (i = 0; i< n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << " " << a[i][j] << "\t";
		}
		cout << endl;
	}
	
}

void nhapMT(int a[][max])
{
	nhapmang(a);
	inmang(a);
}
/*
	Tìm đường đi Euler
*/
int Dem = 0, SoCanh = 0; //dem so duong di va luu so canh cua do thi
int L[max]; //luu dinh da di qua
int XuatPhat = 0; //dinh xuat phat la dinh bac le neu do thi co dinh bac le

// In ra duong di Euler
void InDuongDi() {
	Dem++;
	cout << endl << XuatPhat + 1;
	for (int i = 1; i <= SoCanh; i++)
		cout << " -> " << L[i] + 1;
}

//thu tuc tim kiem de quy
void Try(int Canh) {
	if (Canh > SoCanh) //tim du so canh thi xuat duong di
		InDuongDi();
	else {
		for (int i = 0; i < n; i++)
			if (A[L[Canh - 1]][i] > 0) {
				L[Canh] = i;
				A[L[Canh - 1]][i] = A[i][L[Canh - 1]] = 0; //xoa canh
				Try(Canh + 1); //tim canh tiep theo
				A[L[Canh - 1]][i] = A[i][L[Canh - 1]] = 1; //phuc hoi canh
				L[Canh] = 0;
			}
	}
}

void euler(int G[max][max])
{
	InDuongDi();
	Try(1);
}

int main()
{
	int nhapDT, duyetDT;
	cout << " =========================Nhap ma tran ke cua do thi G================================" << endl;
	cout << " 1. Import File(input.txt).\n 2. Nhap ma tran thu cong.\n Chon: "; 
	for (;;)
	{
		cin >> nhapDT;
		if (nhapDT < 3 && nhapDT >0) break;
		else
		{
			cout << " Chon sai, chon lai: ";
			continue;
		}
	}
	cout << endl;
	if (nhapDT == 1) 
	{
		cout << " Ma tran ke cua do thi G la: " << endl;
		importFile(G);
	}
	else if (nhapDT == 2)
	{
		nhapMT(G);
	}
	else cout << " Nhap sai." << endl;
	cout << " =====================================================================================" << endl;
	cout << " Cac thuat toan duong di " << endl;
	cout << " 1. Duong di Euler." << endl;
	cout << " 2. Duong di Haminton." << endl; 
	cout << " Chon: ";
	for (;;)
	{
		cin >> duyetDT;
		if (nhapDT < 3 && nhapDT >0) break;
		else
		{
			cout << " Chon sai, chon lai: ";
			continue;
		}
	}
	cout << endl;
	euler(G);
	_getch();
	return 0;
}
