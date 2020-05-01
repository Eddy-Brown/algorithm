#include<iostream>
#define N 5
using namespace std;

void BubbleSort(int a[], int n, int i)
{
	int j;
	bool exchange;
	if(i==n-1)
	    return;
	else
	{
		exchange = false;
		for(j=n-1;j>i;j--)
		    if(a[j]<a[j-1])
		    {
		    	swap(a[j],a[j-1]);
		    	exchange = true;
			}
		if(exchange==false)
		    return;
		else
		    BubbleSort(a,n,i+1);
	}
}

int main()
{
	int a[N];
	while(cout<<"input a[]:")
	{
		for(int i=0;i<N;i++)
		    cin>>a[i];
		    
		BubbleSort(a,N,0);
		
		for(int j=0;j<N;j++)
		    cout<<a[j]<<" ";
		cout<<endl<<endl; 
	}
}
