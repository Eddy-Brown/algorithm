//任务分配问题
#include<iostream>
#include<vector>
#define MAXN 10 
using namespace std;

int n =4;
int c[MAXN][MAXN] = {{9,2,7,8},{6,4,3,7},{5,8,1,8},{7,6,9,4}};
vector<vector<int> >ps;    

void Insert(vector<int> s,int i,vector<vector<int> >&ps1)
{//在每个集合元素中间插入i得到ps1 
	vector<int> s1;
	vector<int>::iterator it;
	for(int j=0;j<i;j++)              //在s（含i-1个整数）的每个位置插入i 
	{
		s1 = s;
		it = s1.begin()+j;            //求出插入位置 
		s1.insert(it,i);              //插入整数i 
	    ps1.push_back(s1);            //添加到ps1中 
	} 
}

void Perm(int n)                      //求1~n的所有全排列 
{
	vector<vector<int> > ps1;         //临时存放子排列 
	vector<vector<int> >::iterator it; //全排列迭代器 
	vector<int> s,s1;
	s.push_back(1);
	ps.push_back(s);                   //添加{1}集合元素 
	
	for(int i=2;i<=n;i++)              //循环添加1~n 
	{
		ps1.clear();                    //ps1存放插入i的结果 
		for(it = ps.begin();it!=ps.end();++it)
		    Insert(*it,i,ps1);          //在每个集合元素中间插入i得到ps1 
		ps = ps1;
	}
}

void Allocate(int n,int &mini,int &minc)
{//求任务分配问题的最优方案 
	Perm(n);                           //求出全排列ps 
	
	for(int i=0;i<ps.size();i++)       //求每个方案的成本 
	{
		int cost = 0;
		for(int j=0;j<ps[i].size();j++)
		    cost+=c[j][ps[i][j]-1];
		if(cost<minc)                 //比较求最小成本的方案 
		{ 
			minc = cost;
			mini = i;
		}
	}
}

int main()
{
	int mincost,mini;
	Allocate(n,mini,mincost);
	cout<<"最优方案"<<endl<<endl;
	for(int k=0;k<ps[mini].size();k++)
	    cout<<"  第"<<k+1<<"个人安排任务"<<ps[mini][k]<<endl;
	cout<<endl<<"  总成本 = "<<mincost<<endl;
} 
