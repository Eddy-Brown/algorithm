//�����ַ���s��t����t��s�Ӵ���
//����t��s�е�λ�ã�t�����ַ���s�ж�Ӧ���±꣩�����򷵻�-1��
#include<iostream>
#include<string>
using namespace std;

int BF(string s,string t)
{
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
	}
	if(j==t.length())
	    return i-j;
	else
	    return -1;
}

int main()
{
	string s,t;
	cin>>s>>t;
	cout<<BF(s,t)<<endl;
	return 0;
	
}
