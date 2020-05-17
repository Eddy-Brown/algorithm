#include<iostream>
#include<string.h>
#define MAXN 20                              //��༯װ����� 
using namespace std;
//�����ʾ 
int w[] = {0,10,40,50};                      //����װ�������������±�0��Ԫ�� 
int n = 3;
int c1 = 50,c2 = 50;
int maxw = 0;                                //��ŵ�һ���ִ����Ž�������� 
int x[MAXN];                                 //��ŵ�һ���ִ����Ž�����


void dfs(int i,int tw,int rw,int op[])
{   //���򵥵�װ������ 
	if(i>n)                            //�ҵ�һ��Ҷ�ӽ��
	{
		if(tw>maxw)                    
		{
			maxw = tw;                 //�ҵ�һ�����������ĸ��Ž�,����
			for(int j=1;j<=n;j++)
			    x[j] = op[j];          //�������Ž�
		}
	}
	else                               //��δ����������Ʒ
	{
		if(tw+w[i]<=c1)                 //���ӽ���֦
		{
			op[i] = 1;                 //ѡȡ��i����Ʒ
			dfs(i+1,tw+w[i],rw-w[i],op);
		}
		if(tw+rw-w[i]>maxw)              //�Һ��ӽ���֦
		{
			op[i] = 0;                 //��ѡȡ��i����Ʒ,����
			dfs(i+1,tw,rw-w[i],op);
		}
	}
} 

bool solve()
{//��⸴��װ������ 
	int sum = 0;                     //�ۼƵ�һ���ִ�װ���ʣ��ļ�װ������ 
	for(int j=1;j<=n;j++)
	    if(x[j]==0)
	        sum+=w[j];
	if(sum<=c2)                     //�ڶ����ִ�����װ�� 
	    return true;
	else                            //�ڶ����ִ�����װ�� 
	    return false;
}

int main()
{
	int op[MAXN];
	memset(op,0,sizeof(op));
	int rw = 0;
	for(int i=1;i<=n;i++)
	    rw+=w[i];
	dfs(1,0,rw,op);
	cout<<"�����"<<endl<<endl;
	
	if(solve())
	{
		cout<<"���ŷ���"<<endl;
		cout<<"    ��һ�Ҵ� { ";
		for(int j=1;j<=n;j++)
	    cout<<x[j]<<" ";
	    cout<<"}"<<endl;
	    cout<<"    ���µļ�װ��װ��ڶ��Ҵ�"<<endl;
	}
	else
	    cout<<"    û�к��ʵ�װ�ط���"<<endl;
} 
