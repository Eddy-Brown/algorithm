//n皇后问题：在n*n的棋盘上放n各皇后，每个皇后不同行、不同列、不同左右对角线 

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
bool place(int i, int j)   //测试(i,j)位置能否放置皇后 
{
	if(i==1)               //第一个皇后总能放置 
	    return true;
	int k = 1;
	while(k<i)            //k=1~i-1是已经放置了皇后的行 
	{
		if((q[k]==j)||(abs(q[k]-j)==abs(i-k)))
		    return false;
		k++;
	}
	return true;
}

void queen(int i,int n)        //放置1~n个皇后 
{
	if(i>n)
	    dispasolution(n);    //所有皇后放置结束 
	else
	{
		for(int j=1;j<=n;j++)      //在第i行试探每一个列j 
		    if(place(i,j))         //在第i行上找到一个合适位置（i,j） 
		    {
		    	q[i] = j;
		    	queen(i+1,n);
			}
	}
	
}

int main()
{
	cout << N << "皇后问题可行解：\n";
	queen(1,N);
	//system("pause");     //冻屏函数 
	return 0;
}
