#include<iostream>
#define N 5
using namespace std;

int maxSubSum3(int a[],int n)
{
	int j,maxSum=0,thisSum=0;
	for(j=0;j<n;j++)
	{
		thisSum+=a[j];
		if(thisSum<0)         //����ǰ�����к�Ϊ���������¿�ʼ��һ������ 
		    thisSum = 0;
		if(maxSum<thisSum)    //�Ƚ���������������к� 
		    maxSum = thisSum;
	}
	return maxSum;
}

int main()
{
	int a[N];
	for(int i=0;i<N;i++)
	    cin>>a[i];
	cout<<maxSubSum3(a,N-1);
	return 0;
}
