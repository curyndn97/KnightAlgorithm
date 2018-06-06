#include <iostream>
#include "stdio.h"
#include <iomanip>
#include <conio.h>
using namespace std;
#define NMAX 10

int dem = 0;
int Banco[NMAX][NMAX];
int kichthuoc;
int Dx[] = { -2,-2,-1,1,2,2,1,-1 };
int Dy[] = { -1,1,2,2,1,-1,-2,-2 };


void KhoiTao()
{
	for (int i = 0; i<kichthuoc; i++)
	{
		for (int j = 0; j < kichthuoc; j++)
			Banco[i][j] = 0;
	}
}

void Xuat()
{
	printf("Giai Phap : %d \n", dem++);
	for (int i = 0; i<kichthuoc; i++)
	{
		for (int j = 0; j<kichthuoc; j++)
			printf("%5d", Banco[i][j]);
		printf("\n");
	}
	printf("\n");
	//system("pause");
}

bool TrienVong(int d, int c, int i) {
	if (Banco[d + Dx[i]][c + Dy[i]] == 0
		&& d + Dx[i] >= 0 && d + Dx[i] < kichthuoc
		&& c + Dy[i] >= 0 && c + Dy[i] < kichthuoc) return true;
	return false;
}

void MaDiTuan(int d, int c, int k)
{
	if (k == kichthuoc* kichthuoc) {
		Xuat();
		return;
	}
	else {
		for (int i = 0; i<8; i++)
			if (TrienVong(d,c,i))
			{
				Banco[d + Dx[i]][c + Dy[i]] = k;
				MaDiTuan( d + Dx[i], c + Dy[i], k + 1);
				Banco[d + Dx[i]][c + Dy[i]] = 0;
			}
	}
}

int main()
{

	int x, y,n;
	cout << "Nhap kich thuoc ban co: ";
	cin >> kichthuoc;
	cout << "Vi tri xuat phat:" << endl;
	cout << "   dong = "; cin >> x;
	cout << "   cot  = "; cin >> y;
	KhoiTao();
	Banco[x][y] = 1;
	Xuat();
	MaDiTuan(x, y, 2);

	printf("Co tong cong %d truong hop\n", dem);
	system("pause");
	return 0;
}