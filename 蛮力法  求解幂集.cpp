//求解幂集（子集）问题
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > ps;

void Pset(int n)                       //求1~n的幂集ps 
{
	vector<vector<int> >ps1;          //子幂集 
	vector<vector<int> >::iterator it;//幂集迭代器 
	vector<int> s;
	ps.push_back(s);                  //添加{}空集合元素 
	
	for(int i=1;i<=n;i++)             //循环添加1~n
	{
		ps1 = ps;                     //ps1存放上一步得到的幂集 
		for(it = ps1.begin();it!=ps1.end();++it)
		    (*it).push_back(i);       //在ps1的每个集合元素末尾添加i 
		for(it = ps1.begin();it!=ps1.end();++it)
		    ps.push_back(*it);        //将ps1的每个集合元素添加到ps中 
	}
}


int main() 
{
	int n;
	vector<vector<int> >::iterator it;
	vector<int>::iterator sit;
	cin>>n;
	Pset(n);
	
	for(it=ps.begin();it!=ps.end();++it)    //输出 
	{
		printf("{");
		for(sit=(*it).begin();sit!=(*it).end();++sit)
		{
			printf("%d",*sit);
		}
		printf("} ");
	}

}

