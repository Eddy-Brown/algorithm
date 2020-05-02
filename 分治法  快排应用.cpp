// 已知由n（n≥2）个正整数构成的集合A={ak} （0≤k<n）
//将其划分为两个不相交的子集A1和A2，元素个数分别是n1 和n2， 
//A1和A2中元素之和分别为S1和S2。
//设计一个尽可能高效的划分算法，满足|n1-n2|最小且|S1-S2|最大 。
#include<iostream>
#define N 5
using namespace std;

int Partition(int a[],int low,int high)
{
	int i=low,j=high;
	int povit=a[low];
	
	while(i<j)
	{
		while(i<j && a[j]>=povit)
		    j--;
		a[i] = a[j];
		while(i<j && a[i]<=povit)
		    i++;
		a[j] = a[i];
	}
	a[i] = povit;
	return i;
}

int Solution(int a[],int n)
{
	int low=0,high=n-1;
	bool flag = true;
	while(flag)
	{
		int i = Partition(a,low,high);
		if(i==n/2 - 1)
		    flag = false;
		else if(n/2 - 1 > i)
		    low = i+1;
		else
		    high = i-1;
	}
	int s1=0,s2=0;
	for(int i=0;i<n/2;i++)
	    s1+=a[i];
	for(int j=n/2;j<n;j++)
	    s2+=a[j];
	return s2-s1;
}

int main()
{
	int a[N];
	while(cout<<"input a[]:")
	{
		for(int i=0;i<N;i++)
		    cin>>a[i];
		Solution(a,N);
		for(int j=0;j<N;j++)
		    cout<<a[j]<<" ";
		cout<<endl; 
		cout<<Solution(a,N)<<endl<<endl;
	}
}
