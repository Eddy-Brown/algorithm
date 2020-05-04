//a[n]是一个已排好序的数组，并且所有元素值不相同，查找x 
//当 x不在数组中时，返回小于x 的最大元素的位置i和大于x的最小元素位置j
//当x在数组中是，i和j相同，均为x在数组中的位置 
#include<iostream>
#define N 5
using namespace std;

int BinSearch2(int a[],int n,int x,int &i,int &j)      //拆半查找算法
{
	int mid,low=0,high=n-1;
	while(low<=high)                   //当前区间含有一个或以上的元素时
	{
		mid = (low+high)/2;         
		if(x==a[mid])                //找到值为x 的元素a[mid] 
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
		return -1;               //若当前查找区间没有元素时返回-1
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
