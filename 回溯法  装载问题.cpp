//简单的装载问题 
#include<iostream>
#define MAXN 100
using namespace std;
//问题表示
int n = 5;                            
int W = 10;  
int w[] = {0,5,2,6,4,3};                //各集装箱重量，不用下标0元素 
              
//求解结果表示
int x[MAXN];                           //存放最终解
int maxw;                              //存放最优解的总重量

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
		if(tw+w[i]<=W)                 //左孩子结点剪枝
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

int main()
{
	int op[n] = {0};
	dfs(1,0,20,op);
	cout<<"最优解为：{";
	for(int j=1;j<=n;j++)
	    cout<<x[j]<<"  ";
	cout<<"}"<<endl<<"总重量为："<<maxw<<endl;
	return 0;
}
