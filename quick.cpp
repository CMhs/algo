#include <iostream>
using namespace std;
int S[9]={10,9,8,7,6,5,4,2,3};
int pivotpoint;
void partition(int low, int high, int& pivotpoint)
{
	int i,j;
	int pivotitem;
	int temp;
	pivotitem = S[low];
	j=low;
	for(i=low+1;i<=high;i++)
	{
		if(S[i] < pivotitem)
		{
			j++;
			temp=S[i];
			S[i]=S[j];
			S[j]=temp;
		}
	}
		pivotpoint = j;
		temp=S[low];
		S[low]=S[pivotpoint];
		S[pivotpoint]=temp;
}
void quicksort(int low, int high)
{
	if(high>low)
	{
		partition(low,high,pivotpoint);
		quicksort(low,pivotpoint-1);
		quicksort(pivotpoint+1,high);
	}
} 
int main()
{
	quicksort(0,8);
	for(int i=0;i<9;i++)
		cout<<" "<<S[i];
	return 0;
}
