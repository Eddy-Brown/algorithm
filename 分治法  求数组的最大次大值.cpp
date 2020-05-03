#include<iostream>
#include<algorithm>
#define N 6
#define INF 100000 
using namespace std;

void solve(int a[],int low,int high,int &max1,int &max2)
{
	if(low==high)    //区间只有一个元素 
	{
		max1 = a[low];
		max2 = -INF;    //负无穷 
	}
	else if(low==high-1)     //区间只有两个元素 
	{
		max1 = max(a[low],a[high]);
		max2 = min(a[low],a[high]);
	}
	else                    //区间有两个以上元素 
	{
		int mid = (low+high)/2;
		int lmax1,lmax2;
		solve(a,low,mid,lmax1,lmax2);       //左区间求lmax1和lmax2 
		int rmax1,rmax2;
		solve(a,mid+1,high,rmax1,rmax2);    //右区间求rmax1和rmax2 
		if(lmax1>rmax1)
		{
			max1 = lmax1;
			max2 = max(lmax2,rmax1);       //lmax1,rmax1中求次大元素 
		}
		else
		{
			max1 = rmax1;
			max2 = max(lmax1,rmax2);      //lmax1,rmax2中求次大元素 
		}
	}
}

int main()
{
	int a[N],max1,max2;
	while(cout<<"input a[]:")
	{
		for(int i=0;i<N;i++)
		    cin>>a[i];
		
		solve(a,0,N-1,max1,max2);
        cout<<max1<<" "<<max2<<endl;
	}
}
