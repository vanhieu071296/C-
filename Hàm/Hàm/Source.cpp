#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>
#include <stdio.h>
#define max 100
using namespace std;

// Kiem tra so nguyen to
bool ktnt(int n)
{
	if (n<2) return false;
	int temp = (int)sqrt(n);
	for (int i = 2; i <= temp; i++)
		if (n%i == 0) return false;
	return true;
}

// ham chuyen he so 10 sang 2
void dectobin(int n) 
{
	if (n > 0) 
	{
		dectobin(n / 2);
		cout << n % 2;
	}
}

//Ham chuyen he so 2 sang 10
int bintodec(int n) 
{
	int s = 0; int pow;
	for (int i = 0; n > 0; ++i) 
	{
		pow = 1;
		for (int j = 0; j < i; ++j) pow *= 2;
		s += pow*(n % 10);
		n /= 10;
	}
	return s;
}

// Ham tinh n giai thua
float giaithua(float n)
{
	float gt=1;
	for (int i = 1; i <= n; i++)
		gt = gt * i;
	return gt;
}

//Tim uoc chung lon nhat
int GCD(int a, int b)		
{
	while (b != 0)
	{
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}

// Tim boi chung nho nhat
int LCM(int a, int b)
{
	return abs(a * b) / GCD(a, b);
}

/*
thuat toan ma hoa Z26
abc....xyz
012....232425
*/
std::string z26(std::string chuoi)
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

// thuat toan binh phuong - nhan.
long mod(long m, long e, long n) 
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

// Ham nhap mang
void nhapmang(int a[max], int n)	
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu A[" << i << "] = ";
		cin >> a[i];
	}
}

// Nhap mang 2 chieu
void nhapmang2(int mang[max][max], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			cout << "Moi ban nhap gia tri cho phan tu a[" << i << j << "] trong mang: ";
			cin >> mang[i][j];
		}
	}
}

// Ham xuat mang
void xuatmang(int a[max], int n)	
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
}

// Xuat mang 2 chieu
void xuatmang2(int mang[max][max], int dong, int cot)
{
	for (int i = 0; i < dong; ++i)
	{
		for (int j = 0; j < cot; ++j)
		{
			cout << "  " << mang[i][j] << "\t";
		}
		cout << endl;
	}
}

// Ham doi cho
void swap(int &a, int &b)	
{
	int temp = a;
	a = b;
	b = temp;
}

void QuickSort(int a[max], int left, int right) //mang a[], left = 0, right = n-1
{
	int    i, j;
	int    x;
	x = a[(left + right) / 2];        // chọn phần tử giữa làm gốc
	i = left;
	j = right;
	do {
		while (a[i] < x) i++;		// lặp đến khi a[i] >= x
		while (a[j] > x) j--;		// lặp đến khi a[i] <= x
		if (i <= j)					// nếu có 2 phần tử a[i] và a[j] ko theo thứ tự
		{
			swap(a[i], a[j]);
			i++;					// qua phần tử kế tiếp
			j--;					// qua phần tử đứng trước
		}
	} while (i<j);
	if (left < j)					// phân hoạch đoạn bên trái
		QuickSort(a, left, j);
	if (right > i)					// phân hoạch đoạn bên phải
		QuickSort(a, i, right);
}

void BubbleSort(int a[max], int n)		// mang a[] voi n phan tu
{
	for (int i = 0; i < (n-1); i++)
	{
		for (int j = (n - 1); j > i; j--)
		{
			if (a[j] < a[j - 1])	//Co nghich the.
				swap(a[j], a[j - 1]);
		}
	}
}

void SelectionSort(int a[max], int n)
{
	for (int i = 0; i < (n - 1); i++)
	{
		int min = i;		// Gia su so dau tien trong day dang xet nho nhat
		for (int j = (i + 1); j < n; j++)	// Tim so nho nhat trong day dang xet
		{
			if (a[j] < a[min])
				min = j;
		}
		if (min != i)		// Neu co so nao nho hon so dau trong day dang xet thi thay doi vi tri cho nhau
		{
			swap(a[i], a[min]);
		}
	}
}

int main()
{
	cout << "Hello" << endl;
	_getch();
	return 0;
}