//�򵥵�װ������ 
#include<iostream>
#define MAXN 100
using namespace std;
//�����ʾ
int n = 5;                            
int W = 10;  
int w[] = {0,5,2,6,4,3};                //����װ�������������±�0Ԫ�� 
              
//�������ʾ
int x[MAXN];                           //������ս�
int maxw;                              //������Ž��������

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
		if(tw+w[i]<=W)                 //���ӽ���֦
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

int main()
{
	int op[n] = {0};
	dfs(1,0,20,op);
	cout<<"���Ž�Ϊ��{";
	for(int j=1;j<=n;j++)
	    cout<<x[j]<<"  ";
	cout<<"}"<<endl<<"������Ϊ��"<<maxw<<endl;
	return 0;
}
