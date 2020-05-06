//编写一个程序输出2~1000之间所有的完全数
//完全数:  6=1+2+3  28=1+2+4+7+14
#include<iostream>
using namespace std;

int main()
{
	int m,i,s;
	for(m=2;m<=1000;m++)
	{
		s=0;
		for(i=1;i<=m/2;i++)
		{
			if(m%i==0)      //i是m的一个因子 
		        s+=i;
		} 
		if(m==s)
		    cout<<m<<"  ";
	}
	cout<<endl;
	return 0;
}

