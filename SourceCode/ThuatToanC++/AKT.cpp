#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>
	
using namespace std;

#define MAX 10
struct nuocDi
{
	int n; //Số ô có thể đi tiếp
	int x, y; //Vị trí
};

int BanCo[MAX][MAX];
int kichThuoc;

int dx[] = { -2, -2, -1, -1,  1,  1,  2,  2 };
int dy[] = { 1, -1,  2, -2,  2, -2,  1, -1 };

nuocDi tam;
int thoat = 0;

void Xuat()
{
	int i, j;
	for (i = 1; i <= kichThuoc; i++)
	{
		for (j = 1; j <= kichThuoc; j++)
			cout << setw(3) << BanCo[i][j] << " ";
		cout << endl;
	}
	thoat = 1;
}

int tinhSoNuocDi(int x, int y)
{
	int i, j, n = 0;
	for (int k = 0; k < 8; k++)
	{
		i = x + dx[k];
		j = y + dy[k];
		if (i >= 1 && i <= kichThuoc && j >= 1 && j <= kichThuoc && BanCo[i][j] == 0)
			n++;
	}
	return n;
}


void MaDiTuan(char x, char y, int buoc)
{
	if (buoc == kichThuoc * kichThuoc)
		Xuat();
	else
	{
		int i, j, soNuocDi = 0;
		nuocDi luaChon[8];

		for (int k = 0; k < 8; k++)
		{
			i = x + dx[k];
			j = y + dy[k];
			if (i >= 1 && i <= kichThuoc && j >= 1 && j <= kichThuoc && BanCo[i][j] == 0)
			{
				tam.n = tinhSoNuocDi(i, j);
				tam.x = i;
				tam.y = j;
				luaChon[soNuocDi++] = tam;
			}
		}

		if (soNuocDi > 0)
		{
			//Sắp xếp các nước đi tăng dần theo số ô có thể đi tiếp
			for (int i = 0; i < soNuocDi - 1; i++)
				for (int j = i + 1; j < soNuocDi; j++)
					if (luaChon[i].n > luaChon[j].n)
					{
						tam = luaChon[i];
						luaChon[i] = luaChon[j];
						luaChon[j] = tam;
					};

			for (int i = 0; i < soNuocDi && !thoat; i++)
			{
				BanCo[luaChon[i].x][luaChon[i].y] = buoc + 1;
				MaDiTuan(luaChon[i].x, luaChon[i].y, buoc + 1);
				BanCo[luaChon[i].x][luaChon[i].y] = 0;
			}
		}
	}
}

int main()
{
	int x, y;
	cout << "Nhap kich thuoc ban co: ";
	cin >> kichThuoc;
	cout << "Vi tri xuat phat:" << endl;
	cout << "   dong = "; cin >> x;
	cout << "   cot  = "; cin >> y;
	BanCo[x][y] = 1;
	MaDiTuan(x, y, 1);

	system("pause");
	return 0;
}