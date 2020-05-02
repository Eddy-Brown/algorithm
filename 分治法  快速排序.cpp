#include<iostream>
#define N 5
using namespace std;

int Partition(int a[],int s,int t)    //�����㷨
{
	int i=s;
	int j=t;
	int tmp=a[s];        //�����еĵ�1����¼��Ϊ��׼
	while(i!=j)          //���������˽������м�ɨ�裬ֱ��i=jΪֹ  
	{
		while(j>i && a[j]>=tmp)
		    j--;       //��������ɨ�裬�ҵ�1���ؼ���С��tmp��a[j]
		a[i] = a[j];   //��a[j]ǰ�Ƶ�a[i]��λ��
		while(i<j && a[i]<=tmp)
		    i++;        //��������ɨ�裬�ҵ�1���ؼ��ִ���tmp��a[i]
		a[j] = a[i];    //��a[i]���Ƶ�a[j]��λ��
	}
	a[i] = tmp;
	return i;
}

void QuickSort(int a[],int s,int t)    //��a[s..t]Ԫ�����н��е�������
{ 
	if(s<t)                           //���������ٴ���2��Ԫ�ص����
	{
		int i = Partition(a,s,t);
		QuickSort(a,s,i-1);           //���������еݹ�����
		QuickSort(a,i+1,t);           //���������еݹ�����
	}
}

int main()
{
	int a[N];
	while(cout<<"input a[]:")
	{
		for(int i=0;i<N;i++)
		    cin>>a[i];
		    
		QuickSort(a,0,N-1);
		
		for(int j=0;j<N;j++)
		    cout<<a[j]<<" ";
		cout<<endl<<endl; 
	}
}
