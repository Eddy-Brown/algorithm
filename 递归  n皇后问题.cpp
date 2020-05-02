//n�ʺ����⣺��n*n�������Ϸ�n���ʺ�ÿ���ʺ�ͬ�С���ͬ�С���ͬ���ҶԽ��� 

#include<iostream>
#include<math.h> 
#define N 4

using namespace std;

int q[N+1] = {0};

void dispasolution(int n)
{
	for (int i=1;i<=n;++i)
		cout<<"("<<i<<", "<<q[i]<<")\t";
		
	cout <<endl;
}
bool place(int i, int j)   //����(i,j)λ���ܷ���ûʺ� 
{
	if(i==1)               //��һ���ʺ����ܷ��� 
	    return true;
	int k = 1;
	while(k<i)            //k=1~i-1���Ѿ������˻ʺ���� 
	{
		if((q[k]==j)||(abs(q[k]-j)==abs(i-k)))
		    return false;
		k++;
	}
	return true;
}

void queen(int i,int n)        //����1~n���ʺ� 
{
	if(i>n)
	    dispasolution(n);    //���лʺ���ý��� 
	else
	{
		for(int j=1;j<=n;j++)      //�ڵ�i����̽ÿһ����j 
		    if(place(i,j))         //�ڵ�i�����ҵ�һ������λ�ã�i,j�� 
		    {
		    	q[i] = j;
		    	queen(i+1,n);
			}
	}
	
}

int main()
{
	cout << N << "�ʺ�������н⣺\n";
	queen(1,N);
	//system("pause");     //�������� 
	return 0;
}
