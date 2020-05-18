//װ�뱳������Ʒ�����Ͳ�����W
#include<iostream>
#define MAXN 100
using namespace std;
//�����ʾ
int n = 4;                             //�����ʾ
int W = 6;                             //��������Ϊ6
int w[] = {0,5,3,2,1};                 //���4����Ʒ����,�����±�0Ԫ��
int v[] = {0,4,4,3,1};                 //���4����Ʒ��ֵ,�����±�0Ԫ��
//�������ʾ
int x[MAXN];                           //������ս�
int maxv;                              //������Ž���ܼ�ֵ

class AAA{
public:
	double w,v,p;
};

AAA A[] = {{0,0,0},{2,3,1.5},{3,4,1.3},{1,1,1},{5,4,0.8}};

int bound(int i,int tw,int tv)
{  //���Ͻ�
    i++; 
	while(i<=n && tw+A[i].w<=W) 
	{
		tw+=A[i].w;
		tv+=A[i].v;
		i++;
	}
	if(i<=n)
	    return tv+(W-tw)*A[i].p;
	else
	    return tv;
}

void dfs(int i,int tw,int tv,int op[])
{   //���0/1�������� 
	if(i>n)                            //�ҵ�һ��Ҷ�ӽ��
	{
		maxv = tv;
		for(int j=1;j<=n;j++)
			x[j] = op[j];          //�������Ž�
	}
	else                               //��δ����������Ʒ
	{
		if(tw+A[i].w<=W)                 //���ӽ���֦
		{
			op[i] = 1;                 //ѡȡ��i����Ʒ
			dfs(i+1,tw+A[i].w,tv+A[i].v,op);
		}
		if(bound(i,tw,tv)>maxv)              //�Һ��ӽ���֦
		{
			op[i] = 0;                 //��ѡȡ��i����Ʒ,����
			dfs(i+1,tw,tv,op);
		}
	}
}

int main()
{
	int op[n] = {0};
	dfs(1,0,0,op);
	cout<<"���Ž�Ϊ��{";
	for(int j=1;j<=n;j++)
	    cout<<x[j]<<"  ";
	cout<<"}"<<endl<<"�ܼ�ֵΪ��"<<maxv<<endl;
	return 0;
}


