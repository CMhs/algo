#include <stdio.h>
int fib2(int n)
{
	int i;
	int f[n];
	f[0]=0;
	if(n>0)
	{
		f[1]=1;
		for(i=2;i<=n;i++)
			f[i]= f[i-1]+f[i-2];
	}
	return f[n];
}
int main()
{
	for(int i=0;i<20;i++)
	{
		double  t1,t2,result;
		t1=clock();
		for(int j=0;j<10000000;j++)
			fib2(i);
		t2=clock();
		result = t2-t1;
		printf("%e\n",result);
	}
	return 0;
}

