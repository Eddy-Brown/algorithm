#include<iostream> 
#define N 5

using namespace std;

int QuickSelect(int a[],int s,int t,int k)
{
	int i=s,j=t,tmp;
	if(s<t)
	{
		tmp = a[s];
		while(i!=j)
		{
			while(j>i && a[j]>=tmp)
			    j--;
			a[i] = a[j];
			while(i<j && a[i]<=tmp)
			    i++;
			a[j] = a[i];
		}
		a[i] = tmp;
		
		if(k-1==i)
		    return a[i];
		else if(k-1<i)
		    return QuickSelect(a,s,i-1,k);
		else 
		    return QuickSelect(a,i+1,t,k);
	}
	else if(s==t && s==k-1)
	    return a[k-1];
}

int main()
{
	int a[N],k;
	cout<<"input a[N]£º";
	for(int i=0;i<N;i++)
	    cin>>a[i];
	while(cout<<endl<<"input k£º")
	{
		cin>>k;
		cout<<QuickSelect(a,0,N-1,k);
	}
	return 0;
}
