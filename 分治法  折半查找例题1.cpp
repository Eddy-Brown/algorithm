//设a[]是一个已排好序的数组,在数组中查找x
//若a中不存在值为x的元素，返回-1
//若a中恰好存在一个值为x的元素，返回其下标
//若a中存在多个值为x的元素，返回最左边的x的下标 

#include<iostream>
#define N 5

using namespace std;

int BinSearch1(int a[],int n,int x)
{
    int mid,low = 0,high = n-1;
    while(low<high)                //区间存在2个以上的元素 
    {
    	mid = (low+high)/2;
    	if(x<=a[mid])
    	    high = mid;
    	else
    	    low = mid +1;
	}
	if(low>high)                  //区间为空，没有找到x 
	    return -1;
	else if(a[low]!=x)            //区间不空，一个元素不为x 
	    return -1;
	else                          //区间不空，一个元素恰好为x 
	    return low;
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
