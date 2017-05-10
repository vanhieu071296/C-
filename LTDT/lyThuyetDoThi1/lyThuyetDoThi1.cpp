// lyThuyetDoThi1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;
#define max 20
int * * G, v; // Đồ thị G có v đỉnh

/*================================================================================================*/

#define Filename "input.txt"
//Doc du lieu ma tran ke cua do thi da duoc tao thanh file text luu san tren dia.
int readFile(char *fileName, int A[][max], int &V)

{
	FILE *f = fopen(fileName, "rt");
	if (f == NULL)
	{
		cout << "Doc file loi !!!" << endl;
		return 0;
	}
	fscanf(f, "%d", &V);
	for (int i = 0; i<V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			fscanf(f, "%d", &(A[i][j]));
		}
	}
	return 1;
}

// Nhap ma tran ke
void nhapmang(int a[max][max])
{
	int i, j;
	cout << " Nhap vao so dinh cua do thi : ";
	cin >> v;
	cout << " Nhap vao nua tren cua ma tran : " << endl;
	for (i = 0; i < v; i++)
	{
		for (j = i + 1; j < v; j++)
		{
			cout << " a[" << i << "][" << j << "] ";
			cin >> a[i][j];
			a[j][i] = a[i][j];
		}
		a[i][i] = 0;
	}
}
// In ma tran ke
void inmang(int a[max][max])
{
	int i, j;
	cout << " Ma tran vua nhap la : " << endl;
	for (i = 0; i< v; i++)
	{
		for (j = 0; j < v; j++)
		{
			cout << " " << a[i][j] << "\t";
		}
		cout << endl;
	}

}

void nhapMT(int a[max][max])
{
	nhapmang(a);
	inmang(a);
}

/*===============================================================================================*/

int duyet[max];
int s, Q[max], t[max];
int D, C;
// thuat toan tim kiem theo chieu rong
void BFS(int Q[max], int duyet[max], int A[max][max], int s, int v, int t[max])
{
	int i, j;
	Q[C] = s;
	duyet[s] = 1;
	for (i = 1; i <= v; i++)
	{
		for (j = 1; j <= v; j++)
			if (A[Q[D]][j] == 1 && A[j][Q[D]] == 1 && duyet[j] == 0)
			{
				C = C + 1;
				Q[C] = j;
				t[j] = Q[D];
				duyet[j] = 1;
			}
	}
}
 // Thuật toán Tìm kiếm theo chiều sâu
void DFS(int G[max][max], int duyet[max], int s, int v)
{
	int i;
	duyet[s] = 1;
	cout << " " << s << " ->";
	for (i = 0; i < v; i++)
	{
		if (G[s][i] == 1 && G[i][s] == 1 && duyet[i] == 0)
			DFS(G, duyet, i, v);
	}
}

/*==============================================================================================*/

// Chu trình Euler - Chu trình Hamilton
int v0 = 0, X[max], soCT = 0; // v0: Đỉnh khởi đầu của chu trình. X[max]: Mãng lưu lại toàn bộ chu trình. soCT: Sô chu trình thuật toán tìm được.
int ChuaXet[max];
void GhiNhan() // In kết quả một chu trình Hamilton
{

	if (soCT == 0)
		cout << "\n Cac chu trinh Hamiltom co: " << endl;
	cout << "\n";

	for (int i = 0; i <= v; i++)
		cout << " " << X[i] << " -> ";
	soCT++;
	cout << endl;
}

void Hamilton(int k, int G[max][max])
{
	for (int y = 0; y < v; y++)
		if (G[X[k - 1]][y] != 0)
			if ((k == v) && (y == v0))
				GhiNhan();
			else if (ChuaXet[y] == 0)
			{
				X[k] = y;
				ChuaXet[y] = 1;
				Hamilton(k + 1,G);
				ChuaXet[y] = 0;
			}
}

int KTDTE(int A[][20], int N) // Kết quả trả về là 0 (nếu không phải là đồ thị Euler) hoặc 1 (nếu là đồ thị Euler).
{
	//Ktra bậc của tất cả các đỉnh
	for (int i = 0; i<N; i++)
	{
		int S = 0;         //Xác định bậc đỉnh i

		for (int j = 0; j<N; j++)
			if (A[i][j] != 0)       S = S + 1;

		if (S % 2 == 1) // Bậc của đỉnh phải chẳn.
			return 0;
	}
	return 1;
}

int *CE = NULL, nCE = 0; // *CE lưu vết các đỉnh trong đường đi. nCE số phần tử trong mãng.
void Euler(int A[max][max], int N)
{
	nCE = 0;  // CE = { }
	int STACK[max], topS = 0;
	STACK[topS++] = 0;
	while (topS > 0)
	{
		int y;
		int x = STACK[topS - 1];
		for ( y = 0; y< v; y++)
			if (A[x][y] != 0)
				break;
		if (y < v)
		{
			STACK[topS++] = y;
			A[x][y] = A[y][x] = 0;
		}
		else
		{
			int x = STACK[--topS];
			CE[nCE++] = x;
		}
	}
}

/*==============================================================================================*/
// Tìm đường đi ngắn nhất Dijkstra.

void Dijkstra(int G[max][max], int v, int D, int C) {
	int DanhDau[max];
	int Nhan[max], Truoc[max], XP, min, i, j;
	for (int i = 0; i < v; i++) {
		Nhan[i] = INT_MAX;
		DanhDau[i] = 0;
		Truoc[i] = D;
	}
	Nhan[D] = 0;
	DanhDau[D] = 1;
	XP = D;
	while (XP != C) {
		for (int j = 0; j < v; j++)
			if (G[XP][j] > 0 && Nhan[j] > G[XP][j] + Nhan[XP] && DanhDau[j] == 0) {
				Nhan[j] = G[XP][j] + Nhan[XP];
				Truoc[j] = XP;
			}
		min = INT_MAX;
		for (j = 0; j < v; j++)
			if (min > Nhan[j] && DanhDau[j] == 0) {
				min = Nhan[j];
				XP = j;
			}
		DanhDau[XP] = 1;
	}
	cout << "Duong Di Ngan Nhat La:" << Nhan[C] << endl;
	cout << C + 1 << " <- " << Truoc[C] + 1;
	i = Truoc[C];
	while (i != D) {
		i = Truoc[i];
		cout << " <- " << i + 1;
	}
}



//thuat toan Prim
typedef struct Egde {
	int x, y;

};
void Prim(int A[max][max], int n) {
	char D[max];
	Egde L[max];
	int min = INT_MAX, Dem = 0, Sum = 0;
	for (int i = 0; i < n; i++)
		D[i] = 0;
	for (int j = 1; j < n; j++)
		if (min > A[0][j] && A[0][j] != 0) {
			min = A[0][j];
			L[0].y = j;
		}
	L[0].x = 0;
	D[0] = 1;
	D[L[0].y] = 1;
	Sum += min;
	Dem++;
	do {
		min = INT_MAX;
		for (int i = 0; i < n; i++)
			if (D[i] == 1) for (j = 0; j < n; j++)
				if (A[i][j] > 0 && min > A[i][j] && D[j] == 0) {
					min = A[i][j];
					L[Dem].x = i;
					L[Dem].y = j;
				}
		Sum += min;
		D[L[Dem].y] = 1;
		Dem++;
	} while (Dem < n - 1);
	cout << Sum << endl;
	for (int i = 0; i < n - 1; i++)
		cout << L[i].x + 1 - L[i].y + 1 << endl;
}
int main()
{
	int G[max][max];
	int nhapDT, duyetDT, chutrinh;
	int s;
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
		readFile(Filename, G, v);
		inmang(G);
	}
	else
	{
		nhapMT(G);
	}
/*	cout << " =====================================================================================" << endl;
	cout << " Cac thuat duyet do thi" << endl;
	cout << " 1. DFS (Tim kiem theo chieu sau)." << endl;
	cout << " 2. BFS (Tim kiem theo chieu rong)." << endl;
	cout << " Chon: ";
	for (;;)
	{
		cin >> duyetDT;
		if (duyetDT < 3 && duyetDT > 0) break;
		else
		{
			cout << " Chon sai, chon lai: ";
			continue;
		}
	}
	cout << endl;
	if (duyetDT == 1)
	{
		cout << " Tim kiem theo chieu sau" << endl;
		cout << " Nhap vao dinh xuat phat cua do thi : ";
		cin >> s;
		DFS(G, duyet, s, v);
		for (int u = 0; u < v; u++)
		{
			if (duyet[u] == 0)
				DFS(G, duyet, u, v);
		}
		cout << endl;
	}
	else if (duyetDT == 2)
	{
		cout << " Tim kiem theo chieu rong" << endl;
		cout << " Nhap vao dinh xuat phat cua do thi : ";
		cin >> s;
		BFS(Q, duyet, G, s, v, t);
		for (int u = 0; u< v; u++)
		{
			if (duyet[u] == 0)
			{
				C++;
				BFS(Q, duyet, G, u, v, t);
			}
		}
		for (int u = 0; u < v; u++)
		{
			cout << " " << Q[u] << " -> ";
		}
	}
	cout << endl;*/
/*	cout << " =====================================================================================" << endl;
	cout << " Chu trinh Hamilton - Euler" << endl;
	cout << " 1. Chu trinh Hamilton." << endl;
	cout << " 2. Chu trinh Euler." << endl;
	cout << " Chon: ";
	for (;;)
	{
		cin >> chutrinh;
		if (chutrinh < 3 && chutrinh > 0) break;
		else
		{
			cout << " Chon sai, chon lai: ";
			continue;
		}
	}
	cout << endl;
	if (chutrinh == 1)
	{
		X[0] = v0 = 0;
		ChuaXet[v0] = 1;
		Hamilton(1,G);
		cout << endl;
		if (soCT == 0)
			cout << "\nKhong co chu trinh Hamiltom nao ca.\n";
	}
	else
	{
		if (KTDTE(G, v) == 0)
		{
			cout << "Do thi khong phai la do thi Euler\n";
		}
		else
		{
			CE = new int[v*v];
			cout << "Do thi la do thi Euler\n";
			Euler(G, v);
			cout << "Chu trinh Euler nhu sau:";
			for (int k = 0; k < nCE; k++)
				cout << " " << CE[k] << " -> ";
			cout << "\n";
			delete CE;
		}
	}*/
	cout << " =====================================================================================" << endl;
	cout << " Tim duong di ngan nhat - Thuat toan Dijkstra" << endl;
	int D, C;
	cout << " Nhap dinh dau: "; cin >> D;
	cout << " Nhap dinh cuoi: "; cin >> C;
	Dijkstra(G, v, D, C);
	_getch();
	return 0;
}


