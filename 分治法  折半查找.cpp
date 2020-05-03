#include<iostream>
#define N 5
using namespace std;

int BinSearch(int a[],int low,int high,int k)      //�������㷨
{
	int mid;
	if(low<=high)                   //��ǰ�������Ԫ��ʱ
	{
		mid = (low+high)/2;         //�����������м�λ��
		if(a[mid]==k)               //�ҵ��󷵻��������±�mid
		    return mid;             
		if(a[mid]>k)               //��a[mid]>kʱ
		    return BinSearch(a,low,mid-1,k);
		else                      //��a[mid]<kʱ
		    return BinSearch(a,mid+1,high,k);
	}
	else
	    return -1;                //����ǰ��������û��Ԫ��ʱ����-1
}

void SelectSort(int a[], int n, int i)        //�������������ѡ������ 
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
	int a[N],k;
	cout<<"input a[]:";
    for(int i=0;i<N;i++)
		cin>>a[i];
	SelectSort(a,N,0);
	
	while(cout<<endl<<"input k:")
	{
		cin>>k;
        cout<<BinSearch(a,0,N-1,k)<<endl;
	}
	return 0;
}
