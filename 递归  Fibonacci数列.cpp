#include<iostream>
using namespace std;

int Fib(int n)
{
	if(n==1||n==2)
	    return 1;
	else
	    return Fib(n-1)+Fib(n-2);
}
int main()
{
	int n;
	while(cout<<"input n:")
	{
		cin>>n;
		if(n<=0)
		    cout<<"wrong input!"<<endl<<endl;
		else
		    cout<<"Fib("<<n<<") = "<<Fib(n)<<endl<<endl;
	}
	return 0;
}
