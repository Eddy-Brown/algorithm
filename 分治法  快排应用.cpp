// ��֪��n��n��2�������������ɵļ���A={ak} ��0��k<n��
//���仮��Ϊ�������ཻ���Ӽ�A1��A2��Ԫ�ظ����ֱ���n1 ��n2�� 
//A1��A2��Ԫ��֮�ͷֱ�ΪS1��S2��
//���һ�������ܸ�Ч�Ļ����㷨������|n1-n2|��С��|S1-S2|��� ��
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
