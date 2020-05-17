//判断子集和问题是否存在解
#include<iostream>
using namespace std;

int count;                             //全局变量，累计解个数 
int n = 4,W;
int w[] = {0,11,13,24,7};

void dfs(int i,int tw,int rw)
{   //求解子集合 
	if(i>n)                            //找到一个叶子结点
	{
		if(tw==W)                    
		{
			count++;                 //找到一个满足条件的解,解个数加1 
		}
	}
	else                               //尚未找完所有物品
	{
		if(tw+w[i]<=W)                 //左孩子结点剪枝
		{
			dfs(i+1,tw+w[i],rw-w[i]);
		}
		if(tw+rw-w[i]>=W)              //右孩子结点剪枝
		{
            dfs(i+1,tw,rw-w[i]);      //不选取第i个物品,回溯
		}
	}
}

bool solve()
{//判断子集合问题是否存在解 
	count = 0;
	int rw = 0;
	for(int j=1;j<=n;j++)            
	    rw+=w[j];                    //求解rw 
	dfs(1,0,rw);
	if(count>0)
	    return true;
	else
	    return false;
}

int main()
{
	if(solve())
	    cout<<"存在子集合"<<endl;
	else
	    cout<<"不存在子集合"<<endl;
	return 0;
}
