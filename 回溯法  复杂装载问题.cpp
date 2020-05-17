#include<iostream>
#include<string.h>
#define MAXN 20                              //最多集装箱个数 
using namespace std;
//问题表示 
int w[] = {0,10,40,50};                      //各集装箱重量，不用下标0的元素 
int n = 3;
int c1 = 50,c2 = 50;
int maxw = 0;                                //存放第一艘轮船最优解的总重量 
int x[MAXN];                                 //存放第一艘轮船最优解向量


void dfs(int i,int tw,int rw,int op[])
{   //求解简单的装载问题 
	if(i>n)                            //找到一个叶子结点
	{
		if(tw>maxw)                    
		{
			maxw = tw;                 //找到一个满足条件的更优解,保存
			for(int j=1;j<=n;j++)
			    x[j] = op[j];          //复制最优解
		}
	}
	else                               //尚未找完所有物品
	{
		if(tw+w[i]<=c1)                 //左孩子结点剪枝
		{
			op[i] = 1;                 //选取第i个物品
			dfs(i+1,tw+w[i],rw-w[i],op);
		}
		if(tw+rw-w[i]>maxw)              //右孩子结点剪枝
		{
			op[i] = 0;                 //不选取第i个物品,回溯
			dfs(i+1,tw,rw-w[i],op);
		}
	}
} 

bool solve()
{//求解复杂装载问题 
	int sum = 0;                     //累计第一艘轮船装完后剩余的集装箱重量 
	for(int j=1;j<=n;j++)
	    if(x[j]==0)
	        sum+=w[j];
	if(sum<=c2)                     //第二艘轮船可以装完 
	    return true;
	else                            //第二艘轮船不能装完 
	    return false;
}

int main()
{
	int op[MAXN];
	memset(op,0,sizeof(op));
	int rw = 0;
	for(int i=1;i<=n;i++)
	    rw+=w[i];
	dfs(1,0,rw,op);
	cout<<"求解结果"<<endl<<endl;
	
	if(solve())
	{
		cout<<"最优方案"<<endl;
		cout<<"    第一艘船 { ";
		for(int j=1;j<=n;j++)
	    cout<<x[j]<<" ";
	    cout<<"}"<<endl;
	    cout<<"    余下的集装箱装入第二艘船"<<endl;
	}
	else
	    cout<<"    没有合适的装载方案"<<endl;
} 
