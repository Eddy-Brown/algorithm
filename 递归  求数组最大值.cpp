#include<iostream>
#include<algorithm> //max min ����ͷ�ļ� 
#define N 5
using namespace std;

int fmax(int a[],int i)
{
	if(i==1)
	    return a[0];
	else
	    return max(fmax(a,i-1),a[i-1]); // ����ǰn-1��ֵ�뵱ǰֵ�Ƚϴ���Ǹ��� 
}

int main()
{
	int a[N];
	while(cout<<"input a[N]:")
	{
		for(int j=0;j<N;j++)
		cin>>a[j];
	    cout<<"the max nauber is "<<fmax(a,N)<<endl<<endl;
	}
	
	return 0;
}
