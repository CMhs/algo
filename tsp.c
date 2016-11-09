#include <stdio.h>
#define inf 9999999
#define n 4
int min(int a, int b,int *c)
{
	if (a > b)
	{
		*c = 2;
		return b;
	}
	else
	{
		*c = 1;
		return a;
	}
}
int mmin(int a, int b,int c,int *d)
{
	if (a < b&&a < c)
	{
		*d = 1;
		return a;
	}
	if (b < a&&b < c)
	{
		*d = 2;
		return b;
	}
	if (c < a&&c < b)
	{
		*d = 3;
		return c;
	}
}
int main()
{
	int V[5]= {0,1,2,3,4};
	int W[5][5] = {0,0,0,0,0,0,0,2,9,inf,0,1,0,6,4,0,inf,7,0,8,0,6,3,inf,0 };
	//int W[5][5] = { 0,0,0,0,0,0,0,3,inf,2,0,4,0,1,6,0,inf,7,0,5,0,1,inf,3,0 };
	//int W[5][5] =   {0,0,0,0,0,0,0,inf,5,4,0,2,0,11,7,0,inf,8,0,22,0,6,inf,31,0 };
	int D[5][31] = {};
	int P[5][31] = {};
	int MaxA = 30;
	int A;
	int minlength;
	int i;
	int comp;
	int a, b, c;
	int p1, p2, p3;
	for (int i = 2; i <= 4; i++)
		D[i][0] = W[i][1];
	for (int k = 1; k <= n - 2; k++)
		for (A = 6; A < MaxA; A += 4)
			for (i = 2; i <= n; i++)
			{
				if (A & (1 << i))
					continue;
				if (A == 6)
				{
					D[i][A] = W[i][1];
					P[i][A] = 2;
				
				}
				if (A == 10)
				{
					D[i][A] = W[i][3] + W[3][1];
					P[i][A] = 3;
					
				}
				if (A == 14)
				{
					D[i][A] = min(W[i][2] + W[2][3] + W[3][1], W[i][3] + W[3][2] + W[2][1],&comp);
					switch (comp)
					{
					case 1:
						P[i][A] = 2;
						break;
					case 2:
						P[i][A] = 3;
						break;
					}
					
				}
				if (A == 18)
				{
					D[i][A] = W[i][4] + W[4][1];
					P[i][A] = 4;
				
				}
				if (A == 22)
				{
					D[i][A] = min(W[i][4] + W[4][2] + W[2][1], W[i][2] + W[2][4] + W[4][1], &comp);
					switch (comp)
					{
					case 1:
						P[i][A] = 4;
						break;
					case 2:
						P[i][A] = 2;
						break;
					}
					
				}
				if (A == 26)
				{
					D[i][A] = min(W[i][4] + W[4][3] + W[3][1], W[i][3] + W[3][4] + W[4][1], &comp);
					switch (comp)
					{
					case 1:
						P[i][A] = 4;
						break;
					case 2:
						P[i][A] = 3;
						break;
					}
					
				}
			}

	D[1][30] = mmin(W[1][2] + D[2][26], W[1][3] + D[3][22], W[1][4] + D[4][14],&comp);
	if (comp == 1)
		P[1][30] = 2;
	if (comp == 2)
		P[1][30] = 3;
	if (comp == 3)
		P[1][30] = 4;

	minlength = D[1][30];
	printf("minlength = %d\n", minlength);

	a = P[1][30];
	switch (a)
	{
	case 2:
		p1 = 26;
		break;
	case 3:
		p1 = 22;
		break;
	case 4:
		p1 = 14;
		break;
	}
	b = P[a][p1];
	if (a == 2 && b == 3)
		p2 = 18;
	if (a == 2 && b == 4)
		p2 = 10;
	if (a == 3 && b == 4)
		p2 = 6;
	if (a == 4 && b == 2)
		p2 = 10;
	if (a == 4 && b == 3)
		p2 = 6;
	if (a == 3 && b == 2)
		p2 = 18;
	c = P[b][p2];
	printf("V1 V%d V%d V%d V1\n", a, b, c);
}
