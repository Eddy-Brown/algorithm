//��a[]��һ�����ź��������,�������в���x
//��a�в�����ֵΪx��Ԫ�أ�����-1
//��a��ǡ�ô���һ��ֵΪx��Ԫ�أ��������±�
//��a�д��ڶ��ֵΪx��Ԫ�أ���������ߵ�x���±� 

#include<iostream>
#define N 5

using namespace std;

int BinSearch1(int a[],int n,int x)
{
    int mid,low = 0,high = n-1;
    while(low<high)                //�������2�����ϵ�Ԫ�� 
    {
    	mid = (low+high)/2;
    	if(x<=a[mid])
    	    high = mid;
    	else
    	    low = mid +1;
	}
	if(low>high)                  //����Ϊ�գ�û���ҵ�x 
	    return -1;
	else if(a[low]!=x)            //���䲻�գ�һ��Ԫ�ز�Ϊx 
	    return -1;
	else                          //���䲻�գ�һ��Ԫ��ǡ��Ϊx 
	    return low;
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
	int a[N],x;
	cout<<"input a[]:";
    for(int i=0;i<N;i++)
		cin>>a[i];
	SelectSort(a,N,0);
	
	while(cout<<endl<<"input x:")
	{
		cin>>x;
        cout<<BinSearch1(a,N,x)<<endl;
	}
	return 0;
}
