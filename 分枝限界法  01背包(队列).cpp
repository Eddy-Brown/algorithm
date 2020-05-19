//0/1����   ���ȶ���ʽ��֦�޽編��� 
#include<iostream>
#include<queue>
#define MAXN   20
using namespace std;

int n=3,W=30;
int w[]={0,16,15,15};               //���� 
int v[]={0,45,25,25};               //��ֵ 

int maxv = -999;
int bestx[MAXN];
int total = 1;

class NodeType{                    //�����еĽ������ 
	public:
		int no;                    //����ţ���1��ʼ 
		int i;                     //��ǰ����������ռ��еĲ�� 
		int w;                     //��ǰ���������� 
		int v;                     //��ǰ�����ܼ�ֵ 
		int x[MAXN];               //��ǰ�������Ľ����� 
		double ub;                 //�Ͻ� 
};

void bound(NodeType &e)
{ //�����֦���e���Ͻ� 
	int i = e.i+1;                //���ǽ��e��������Ʒ 
	int sumw = e.w;               //����װ��������� 
	double sumv = e.v;            //����װ����ܼ�ֵ 
	while((sumw+w[i]<=W) && i<=n)
	{
		sumw += w[i];             //���㱳����װ������ 
		sumv += v[i];             //���㱳����װ���ֵ 
		i++;
	}
	if(i<=n)                      //������Ʒֻ�ܲ���װ�� 
	    e.ub = sumv+(W-sumw)*v[i]/w[i];
	else                          //������Ʒȫ������װ�� 
	    e.ub = sumv;
}

void EnQueue(NodeType e,queue<NodeType> &qu)
{ //���e����qu 
	if(e.i==n)                    //����Ҷ�ӽ�� 
	{
		if(e.v>maxv)              //�ҵ������ֵ�Ľ� 
		{
			maxv = e.v;
			for(int j=1;j<=n;j++)
			    bestx[j] = e.x[j];
		}
	}
	else
	    qu.push(e);               //��Ҷ�ӽ����� 
}

void bfs()
{ //���0/1���������Ž� 
	int j;
	NodeType e,e1,e2;             //����������� 
	queue<NodeType> qu;           //����һ������ 
	
	e.i = 0;                      //������ó�ֵ�����μ�Ϊ0 
	e.w = 0;
	e.v = 0;
	e.no = total++;
	for(j=1;j<=n;j++)
	    e.x[j] = 0;
	bound(e);                     //��������Ͻ� 
	qu.push(e);                   //�������� 
	while(!qu.empty())            //�Ӳ���ѭ�� 
	{
		e = qu.front();           //���ӽ��e 
		qu.pop();
		if(e.w+w[e.i+1]<=W)       //��֦��������ӽ�� 
		{
			e1.no = total++;      //�������ӽ�� 
			e1.i = e.i+1;
			e1.w = e.w+w[e1.i];
			e1.v = e.v+v[e1.i];
			for(j=1;j<=n;j++)     //���ƽ����� 
			    e1.x[j] = e.x[j];
			e1.x[e1.i] = 1;
			bound(e1);            //�����ӽ����Ͻ� 
			EnQueue(e1,qu);       //���ӽ����Ӳ��� 
		}
		e2.no = total++;          //�����Һ��ӽ�� 
		e2.i = e.i+1;
		e2.w = e.w;
		e2.v = e.v;
		for(j=1;j<=n;j++)        //���ƽ����� 
		    e2.x[j] = e.x[j];
		e2.x[e2.i] = 0;
		bound(e2);               //���Һ��ӽ����Ͻ� 
		
		if(e2.ub>maxv)           //���Һ��ӽ����У�����ӣ����򱻼�֦ 
		    EnQueue(e2,qu);
	}
}

int main()
{
	bfs();
	cout<<"���Ž�Ϊ��{  ";
	for(int j=1;j<=n;j++)
	    cout<<bestx[j]<<"  ";
	cout<<"}"<<endl<<endl<<"�ܼ�ֵΪ��"<<maxv<<endl;
	return 0;
}



