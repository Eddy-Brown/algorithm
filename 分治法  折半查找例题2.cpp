//a[n]��һ�����ź�������飬��������Ԫ��ֵ����ͬ������x 
//�� x����������ʱ������С��x �����Ԫ�ص�λ��i�ʹ���x����СԪ��λ��j
//��x���������ǣ�i��j��ͬ����Ϊx�������е�λ�� 
#include<iostream>
#define N 5
using namespace std;

int BinSearch2(int a[],int n,int x,int &i,int &j)      //�������㷨
{
	int mid,low=0,high=n-1;
	while(low<=high)                   //��ǰ���京��һ�������ϵ�Ԫ��ʱ
	{
		mid = (low+high)/2;         
		if(x==a[mid])                //�ҵ�ֵΪx ��Ԫ��a[mid] 
		{
			i=j=mid;
			return mid;
		}          
		if(x<a[mid])               
		    high = mid-1;
		else                      
		    low = mid+1;
	}
		i=high; j=low;             
		return -1;               //����ǰ��������û��Ԫ��ʱ����-1
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
	int a[N],x,i=0,j=0;
	cout<<"input a[]:";
    for(int i=0;i<N;i++)
		cin>>a[i];
	SelectSort(a,N,0);
	
	while(cout<<endl<<"input x:")
	{
		cin>>x;
		BinSearch2(a,N,x,i,j);
        cout<<i<<" "<<j<<endl<<endl;
	}
	return 0;
}
