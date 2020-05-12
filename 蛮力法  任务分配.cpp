//�����������
#include<iostream>
#include<vector>
#define MAXN 10 
using namespace std;

int n =4;
int c[MAXN][MAXN] = {{9,2,7,8},{6,4,3,7},{5,8,1,8},{7,6,9,4}};
vector<vector<int> >ps;    

void Insert(vector<int> s,int i,vector<vector<int> >&ps1)
{//��ÿ������Ԫ���м����i�õ�ps1 
	vector<int> s1;
	vector<int>::iterator it;
	for(int j=0;j<i;j++)              //��s����i-1����������ÿ��λ�ò���i 
	{
		s1 = s;
		it = s1.begin()+j;            //�������λ�� 
		s1.insert(it,i);              //��������i 
	    ps1.push_back(s1);            //��ӵ�ps1�� 
	} 
}

void Perm(int n)                      //��1~n������ȫ���� 
{
	vector<vector<int> > ps1;         //��ʱ��������� 
	vector<vector<int> >::iterator it; //ȫ���е����� 
	vector<int> s,s1;
	s.push_back(1);
	ps.push_back(s);                   //���{1}����Ԫ�� 
	
	for(int i=2;i<=n;i++)              //ѭ�����1~n 
	{
		ps1.clear();                    //ps1��Ų���i�Ľ�� 
		for(it = ps.begin();it!=ps.end();++it)
		    Insert(*it,i,ps1);          //��ÿ������Ԫ���м����i�õ�ps1 
		ps = ps1;
	}
}

void Allocate(int n,int &mini,int &minc)
{//�����������������ŷ��� 
	Perm(n);                           //���ȫ����ps 
	
	for(int i=0;i<ps.size();i++)       //��ÿ�������ĳɱ� 
	{
		int cost = 0;
		for(int j=0;j<ps[i].size();j++)
		    cost+=c[j][ps[i][j]-1];
		if(cost<minc)                 //�Ƚ�����С�ɱ��ķ��� 
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
	cout<<"���ŷ���"<<endl<<endl;
	for(int k=0;k<ps[mini].size();k++)
	    cout<<"  ��"<<k+1<<"���˰�������"<<ps[mini][k]<<endl;
	cout<<endl<<"  �ܳɱ� = "<<mincost<<endl;
} 
