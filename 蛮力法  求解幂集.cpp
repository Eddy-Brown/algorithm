//����ݼ����Ӽ�������
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > ps;

void Pset(int n)                       //��1~n���ݼ�ps 
{
	vector<vector<int> >ps1;          //���ݼ� 
	vector<vector<int> >::iterator it;//�ݼ������� 
	vector<int> s;
	ps.push_back(s);                  //���{}�ռ���Ԫ�� 
	
	for(int i=1;i<=n;i++)             //ѭ�����1~n
	{
		ps1 = ps;                     //ps1�����һ���õ����ݼ� 
		for(it = ps1.begin();it!=ps1.end();++it)
		    (*it).push_back(i);       //��ps1��ÿ������Ԫ��ĩβ���i 
		for(it = ps1.begin();it!=ps1.end();++it)
		    ps.push_back(*it);        //��ps1��ÿ������Ԫ����ӵ�ps�� 
	}
}


int main() 
{
	int n;
	vector<vector<int> >::iterator it;
	vector<int>::iterator sit;
	cin>>n;
	Pset(n);
	
	for(it=ps.begin();it!=ps.end();++it)    //��� 
	{
		printf("{");
		for(sit=(*it).begin();sit!=(*it).end();++sit)
		{
			printf("%d",*sit);
		}
		printf("} ");
	}

}

