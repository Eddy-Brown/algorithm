//����������ʮ������n�ĸ�λ����
#include<iostream>
using namespace std;

void digits(int n)
{
    if(n!=0)
    {
    	digits(n/10);
    	cout<<n%10<<endl;
	}
} 

int main()
{
	int n;
	while(cout<<"input n:")
	{
		cin>>n;
		digits(n);
		cout<<endl; 
	}
	return 0;
}
