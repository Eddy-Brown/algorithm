//�������ַ���s��t�����һ���㷨��t��s�г��ֵĴ�����
//���磬s="abababa"��t="aba"����t��s�г���2�Ρ�
#include<iostream>
#include<string>
using namespace std;

int Count(string s,string t)
{
	int num = 0;
	int i=0,j=0;
	while(i<s.length() && j<t.length())
	{
		if(s[i]==t[j])
		{
			i++;
			j++;
		}
		else
		{
			i=i-j+1; 
			j = 0;
		}
		if(j==t.length())
	    {
		    num++;
		    j = 0;
	    }
	}
	return num;
}

int main()
{
	string s,t;
	cin>>s>>t;
	cout<<Count(s,t)<<endl;
	return 0;
	
}
