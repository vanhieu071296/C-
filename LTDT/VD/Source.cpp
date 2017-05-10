#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <stdio.h>
#include <conio.h>
#define max 100

#define FileIn "D:\\G.txt"

using namespace std;
int chuaXet[max];

// A: ma tran ke cua G, n: so dinh
int A[max][max], n;

// doc file chua do thi G luu vao ma tran A

void Doc_File(int A[max][max], int &n) {
	FILE *f = fopen(FileIn, "rb");
	fscanf(f, "%d", &n);
	cout << "\n So dinh: " << n << "\n Ma tran ke: " << endl;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			fscanf(f, "%d", &A[i][j]);
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	fclose(f);
}

// Khoi tao chua xet
void KhoiTao_ChuaXet() {
	for (int i = 0; i<max; i++)
		chuaXet[i] = 1;
}

// thuat toan DFS
void DFS(int u) {
	// xet dinh u
	chuaXet[u] = 0;
	cout << u << "->";
	for (int v = 0; v<n; v++)
		if (chuaXet[v] == 1 && A[u][v] == 1)
		{
			DFS(v);
		}
}


// thuat toan BFS

void BFS(int u) {
	int queue[max], dau = 0, cuoi = 0;
	for (int i = 0; i<max; i++) queue[i] = 0;
	queue[cuoi] = u;
	chuaXet[u] = 0;
	cout << u << "->";

	while (dau >= cuoi)
	{
		int p = queue[cuoi];
		cuoi++;
		for (int v = 0; v<n; v++)
			if (chuaXet[v] == 1 && A[p][v] == 1)
			{
				dau++;
				queue[dau] = v;
				chuaXet[v] = 0;
				cout << v << "->";
			}
	}
}

// Kiem tra chuaXet
int KT_ChuaXet() {
	for (int i = 0; i<n; i++)
		if (chuaXet[i] == 1) return i;
	return -1;
}


// Dem so thanh phan lien thong

int DemSLT() {
	int slt = 0;
	KhoiTao_ChuaXet();
	while (KT_ChuaXet() != -1)
	{
		int i = KT_ChuaXet();
		DFS(i);
		slt++;
	}
	cout << "\n So lien thong: " << slt;
	return slt;
}

// tim bac cac dinh
int Deg(int i) {
	int deg = 0;
	for (int j = 0; j<n; j++)
	{
		deg += A[i][j];
	}
	return deg;
}


// Kiem tra do thi Euler

void Test_Euler() {
	if (DemSLT() == 1) {
		// tim bac cua do thi
		int soDinhLe = 0;
		for (int i = 0; i<n; i++)
			if (Deg(i) % 2 != 0)
				soDinhLe++;
		if (soDinhLe == 0)
			cout << "\n Do thi la Euler";
		else
			if (soDinhLe == 2)
				cout << "\n Do thi la nua Euler";
			else
				cout << "\n Do thi khong phai Euler";
	}
	else
		cout << "\n Do thi khong la Euler";
}

// ham chinh

int main() {
	// doc ma tran
	Doc_File(A, n);
	// Duyet do thi DFS
	KhoiTao_ChuaXet();
	cout << "\n Duyet do thi DFS: ";
	DFS(0);
	// Duyet do thi BFS
	KhoiTao_ChuaXet();
	cout << "\n Duyet do thi BFS: ";
	BFS(0);

	// Dem so lien thong
	DemSLT();

	// Kiem tra Euler
	Test_Euler();
	return 0;
}