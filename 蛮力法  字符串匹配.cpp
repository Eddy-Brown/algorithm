//对于字符串s和t，若t是s子串，
//返回t在s中的位置（t的首字符在s中对应的下标），否则返回-1。
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
