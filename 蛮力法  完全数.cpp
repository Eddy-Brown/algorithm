//��дһ���������2~1000֮�����е���ȫ��
//��ȫ��:  6=1+2+3  28=1+2+4+7+14
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
			if(m%i==0)      //i��m��һ������ 
		        s+=i;
		} 
		if(m==s)
		    cout<<m<<"  ";
	}
	cout<<endl;
	return 0;
}

