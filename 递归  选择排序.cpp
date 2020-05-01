#include<iostream>
#define N 5
using namespace std;

void SelectSort(int a[], int n, int i)
{
	int j,k;
	if(i==n-1)
	    return;
	else
	{
		k = i;
		for(j=i+1;j<n;j++)
		    if(a[j]<a[k])
		        k = j;
		if(k!=i)
		    swap(a[i],a[k]);
		    
		SelectSort(a,n,i+1);
	}
}

int main()
{
	int a[N];
	while(cout<<"input a[]:")
	{
		for(int i=0;i<N;i++)
		    cin>>a[i];
		    
		SelectSort(a,N,0);
		
		for(int j=0;j<N;j++)
		    cout<<a[j]<<" ";
		cout<<endl<<endl; 
	}
}
