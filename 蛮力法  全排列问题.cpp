//求解全排列问题
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > ps;

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

int main()
{
	int n;
	vector<vector<int> >::iterator it;
	vector<int>::iterator sit;
	cin>>n;
	Perm(n);
	
	for(it=ps.begin();it!=ps.end();++it)
	{
		for(sit=(*it).begin();sit!=(*it).end();++sit)
		{
			printf("%d",*sit);
		}
		cout<<" ";
	}
}
