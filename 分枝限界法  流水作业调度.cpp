#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#define MAX 20
#define INF 9999
using namespace std;

//�����ʾ
int n=4;                                         //��ҵ��
int a[MAX] = {0,5,12,4,8};                       //M1�ϵ�ִ��ʱ��,�����±�0��Ԫ��
int b[MAX] = {0,6,2,14,7};                       //M2�ϵ�ִ��ʱ��,�����±�0��Ԫ��
//�������ʾ
int bestf = INF;                                 //������ŵ���ʱ��
int bestx[MAX];                                  //��ŵ�ǰ��ҵ��ѵ���
int total = 1;                                   //�������ۼ�

class NodeType{                                  //���н������
public:
	int no;                                      //�����
	int x[MAX];                                  //x[i]��ʾ��i��������ҵ���
	int y[MAX];                                  //y[i]=1��ʾ���Ϊi����ҵ�Ѿ�����
	int i;                                       //������
	int f1;                                      //�Ѿ�������ҵM1��ִ��ʱ��
	int f2;                                      //�Ѿ�������ҵM2��ִ��ʱ��
	int lb;                                      //�½�
	
	bool operator<(const NodeType &s) const      //����<��ϵ����
	{
		return lb > s.lb;                        //lbԽСԽ���ȳ���
	}
};

void bound(NodeType &e)
{  //����e���޽�ֵ
	int sum = 0;
	for(int i=1;i<=n;i++)                        //ɨ��������ҵ
	    if(e.y[i]==0)
	        sum += b[i];                         //���ۼ�e.x�л�û�з������ҵ��bʱ��
	e.lb = e.f2+sum;
}

void bfs()
{  //�����ˮ��ҵ��������
	NodeType e,e1;
	priority_queue<NodeType> qu;
	memset(e.x,0,sizeof(e.x));                   //��ʼ��������x
	memset(e.y,0,sizeof(e.y));                   //��ʼ��������y
	e.i = 0;                                     //�����
	e.f1 = 0;
	e.f2 = 0;
	bound(e);
	e.no = total++;
	qu.push(e);                                  //����������
	
	while(!qu.empty())
	{
		e=qu.top();
		qu.pop();                                //���ӽ��e
		e1.i = e.i+1;                            //��չ������һ���������ҵ��e1
		for(int j=1;j<=n;j++)                    //����n����ҵ
		{
			if(e.y[j]==1)
			    continue;                        //��ҵj�Ƿ��ѷ���,���ѷ��䣬����
			for(int i1=1;i1<=n;i1++)             //����e.x�õ�e1.x
			    e1.x[i1] = e.x[i1];
			for(int i2=1;i2<=n;i2++)             //����e.y�õ�e1.y
			    e1.y[i2] = e.y[i2];
			    
			e1.x[e1.i] = j;                      //Ϊ��i��������ҵj
			e1.y[j] = 1;                         //��ʾ��ҵj�Ѿ�����
			e1.f1 = e.f1+a[j];
			e1.f2 = max(e.f2,e1.f1)+b[j];
			bound(e1);
			
			if(e1.i==n)                          //�ﵽҶ�ӽ��
			{
				if(e1.f2 < bestf)                //�Ƚ������Ž�
				{
					bestf = e1.f2;
					for(int j1=1;j1<=n;j1++)
					    bestx[j1] = e1.x[j1];
				}
			}
			else if(e1.lb < bestf)                //��֦
			{
				e1.no = total++;                  //���������1
				qu.push(e1);
			}
		}
	}
}

int main()
{
	bfs();
	cout<<"���ŷ�����"<<endl;
	for(int i=1;i<=n;i++)
	    cout<<"        ��"<<i<<"��ִ����ҵ"<<bestx[i]<<endl;
	cout<<"��ʱ��Ϊ"<<bestf<<endl;
	return 0;
}
