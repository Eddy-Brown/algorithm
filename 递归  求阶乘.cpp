#include<iostream>
using namespace std;

int fun(int n)
{
	if(n==1)
	    return (1);
	else
	    return(fun(n-1)*n);
}

int main()
{
	int n;
	while(cout<<"input n:")
	{
		cin>>n;
		if(n>0)
			cout<<"n! = "<<fun(n)<<endl<<endl;
		else
		    cout<<"wrong input!"<<endl<<endl;
	}
	return 0;
}
