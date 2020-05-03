#include<iostream>
#define N 5
using namespace std;

int BinSearch(int a[],int low,int high,int k)      //拆半查找算法
{
	int mid;
	if(low<=high)                   //当前区间存在元素时
	{
		mid = (low+high)/2;         //求查找区间的中间位置
		if(a[mid]==k)               //找到后返回其物理下标mid
		    return mid;             
		if(a[mid]>k)               //当a[mid]>k时
		    return BinSearch(a,low,mid-1,k);
		else                      //当a[mid]<k时
		    return BinSearch(a,mid+1,high,k);
	}
	else
	    return -1;                //若当前查找区间没有元素时返回-1
}

void SelectSort(int a[], int n, int i)        //将输入数组进行选择排序 
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
