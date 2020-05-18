//装入背包中物品重量和不超过W
#include<iostream>
#define MAXN 100
using namespace std;
//问题表示
int n = 4;                             //问题表示
int W = 6;                             //限制重量为6
int w[] = {0,5,3,2,1};                 //存放4个物品重量,不用下标0元素
int v[] = {0,4,4,3,1};                 //存放4个物品价值,不用下标0元素
//求解结果表示
int x[MAXN];                           //存放最终解
int maxv;                              //存放最优解的总价值

class AAA{
public:
	double w,v,p;
};

AAA A[] = {{0,0,0},{2,3,1.5},{3,4,1.3},{1,1,1},{5,4,0.8}};

int bound(int i,int tw,int tv)
{  //求上界
    i++; 
	while(i<=n && tw+A[i].w<=W) 
	{
		tw+=A[i].w;
		tv+=A[i].v;
		i++;
	}
	if(i<=n)
	    return tv+(W-tw)*A[i].p;
	else
	    return tv;
}

void dfs(int i,int tw,int tv,int op[])
{   //求解0/1背包问题 
	if(i>n)                            //找到一个叶子结点
	{
		maxv = tv;
		for(int j=1;j<=n;j++)
			x[j] = op[j];          //复制最优解
	}
	else                               //尚未找完所有物品
	{
		if(tw+A[i].w<=W)                 //左孩子结点剪枝
		{
			op[i] = 1;                 //选取第i个物品
			dfs(i+1,tw+A[i].w,tv+A[i].v,op);
		}
		if(bound(i,tw,tv)>maxv)              //右孩子结点剪枝
		{
			op[i] = 0;                 //不选取第i个物品,回溯
			dfs(i+1,tw,tv,op);
		}
	}
}

int main()
{
	int op[n] = {0};
	dfs(1,0,0,op);
	cout<<"最优解为：{";
	for(int j=1;j<=n;j++)
	    cout<<x[j]<<"  ";
	cout<<"}"<<endl<<"总价值为："<<maxv<<endl;
	return 0;
}


