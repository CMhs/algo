#include <stdio.h>
int fib(int n)
{
	if(n<=1)
		return n;
	else
		return fib(n-1)+fib(n-2);
}
int main()
{
	time_t t1,t2;

	int a[10]={33,34,35,36,37,38,39,40,41,42};
	for(int i=0;i<10;i++)
	{
		t1=clock();
		fib(a[i]);
		t2=clock();
		float totalTime=(float)(t2-t1)/1000;
		float runTime = (float)((totalTime)/a[i]);
		printf("total time =%f  run Time = %f\n",totalTime,runTime);
	}
	return 0;
}
