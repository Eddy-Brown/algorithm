#include<iostream>
#include<queue>
#define INF 0x3f3f3f3f             //��ʾ�����
#define MAXN 51
using namespace std; 
//�����ʾ
int n=5;                           //ͼ�������
int a[MAXN][MAXN]={0,INF,10,INF,30,100,
                   INF,0,4,INF,INF,INF,
				   INF,INF,0,50,INF,INF,
				   INF,INF,INF,0,INF,10,
				   INF,INF,INF,20,0,60,
				   INF,INF,INF,INF,INF,0};                 //ͼ���ڽӾ���
int v;                             //Դ��

//�������ʾ
int dist[MAXN];                    //dist[i]Դ�㵽����i�����·������
int prev[MAXN];                    //prev[i]��ʾԴ�㵽j�����·���ж���j��ǰ������

class NodeType{                    //���н������ 
	public:
		int vno;                   //������
		int length;                //·������ 
}; 

void bfs(int v)
{ //����㷨
    NodeType e,e1;
	queue<NodeType> pqu;
	e.vno = v;                     //����Դ����e(�����)
	e.length = 0;
	pqu.push(e);                   //Դ����e����
	dist[v] = 0;
	
	while(!pqu.empty())            //���в���ѭ�� 
	{
		e = pqu.front();
		pqu.pop();                //�����н��e 
		for(int j=0;j<n;j++)
		{
			if(a[e.vno][j]<INF && e.length+a[e.vno][j]<dist[j])
			{ //��֦��e.vno������j�б߲���·�����ȸ���
			    dist[j] = e.length+a[e.vno][j];
				prev[j] = e.vno;
				e1.vno = j;       //�������ڶ���j�Ľ��e1 
				e1.length = dist[j];
				pqu.push(e1);     //���e1���� 
				
			}
		}
	} 
} 

int main()
{
	bfs(0);
	for(int i=0;i<n;i++)
	    cout<<dist[i]<<" ";
	cout<<endl<<endl;
	for(int j=0;j<n;j++)
	    cout<<prev[j]<<" ";
	cout<<endl;
	return 0;
} 
