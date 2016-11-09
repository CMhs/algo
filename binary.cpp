#include <iostream>
using namespace std;
void binsearch(int n ,const int S[], int x, int& location)
{
	int low,high,mid;
	low=1;
	high=n;
	location=0;
	while(low<=high&&(location)==0)
	{
		mid=(low+high)/2;
		if(x==S[mid])
			location=mid;
		else if(x<S[mid])
			high=mid-1;
		else low = mid + 1;
	}
}
int main()
{
	const long r[20] = { 3000000, 3000000, 2000000, 2000000, 1000000, 1000000,
		1000000, 800000, 800000, 500000, 500000, 250000, 150000, 150000, 100000, 75000,
		70000, 60000, 50000, 50000 };

	int pos = 0;
	int arr[1001], n[20];

	for (int k = 0; k <= 1000; k++)
		arr[k] = k;

	for (int j = 0; j<10; j++) {
		n[j] = 10 * j;
		n[j + 10] = 800 * (j + 1);
	}

	cout << " n     totalTime     runTime" << endl;
	for (int i = 0; i<20; i++) {
		float start, stop;
		start = clock();
		for (long b = 1; b <= r[i]; b++)
			binsearch(sizeof(arr) / sizeof(int), arr, n[i], pos);
		stop = clock();
		float totalTime = (stop - start);
		float runTime = (totalTime) / (float)(r[i]);
		cout.precision(11);
		cout << "        " <<runTime << endl;
	}

	return 0;
}
