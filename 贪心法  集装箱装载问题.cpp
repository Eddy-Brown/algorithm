#include<iostream>
#include<algorithm>
#include<string.h>
#define MAXN 20
using namespace std;


int w[] = {0,5,2,6,4,3};
int n=5,W=10;

int maxw;                                     //存放最优解的总重量
int x[MAXN];                                  //存放最优解向量

void solve()
{  //求解最优装载问题
	memset(x,0,sizeof(x));
	sort(w+1,w+1+n);                          //w[1..n]递增排序
	maxw = 0;
	int restw = W;                            //剩余重量
	for(int i=1;i<=n && w[i]<=restw;i++)
	{
		x[i] = 1;                             //选择集装箱i
		restw -= w[i];                        //减少剩余重量
		maxw += w[i];                         //累计装载总重量
	}
}

int main()
{
	solve();
	cout<<"最优方案："<<endl<<endl;
	for(int i=1;i<=n;i++)
	    if(x[i] == 1)
	    	cout<<"  选取重量为"<<w[i]<<"的集装箱"<<endl;
	cout<<endl<<"总重量为"<<maxw<<endl; 
}
