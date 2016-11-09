#include <stdio.h>
int main()
{
	int arr[50],k,i,l,pos=0;
	printf("Enter limit for SEQUENTIAL SEARCH\n");
	scanf("%d",&l);
	printf("Enter %d elements \n",l);
	for(i=0;i<l;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter a number to be search\n");
	scanf("%d",&k);
	for(i=0;i<l;i++)
	{
		if(arr[i]==k)
		{
			pos=i+1;
			break;
		}
	}
	if(pos!=0)
		printf("%d is found in the list, at position %d\n",k,pos);
	else
		printf("%d is not int the list\n",k);
}
