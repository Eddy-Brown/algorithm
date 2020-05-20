#include<iostream>
#include<queue>
#define INF 0x3f3f3f3f             //表示无穷大
#define MAXN 51
using namespace std; 
//问题表示
int n=5;                           //图顶点个数
int a[MAXN][MAXN]={0,INF,10,INF,30,100,
                   INF,0,4,INF,INF,INF,
				   INF,INF,0,50,INF,INF,
				   INF,INF,INF,0,INF,10,
				   INF,INF,INF,20,0,60,
				   INF,INF,INF,INF,INF,0};                 //图的邻接矩阵
int v;                             //源点

//求解结果表示
int dist[MAXN];                    //dist[i]源点到顶点i的最短路径长度
int prev[MAXN];                    //prev[i]表示源点到j的最短路径中顶点j的前驱顶点

class NodeType{                    //队列结点类型 
	public:
		int vno;                   //顶点编号
		int length;                //路径长度 
}; 

void bfs(int v)
{ //求解算法
    NodeType e,e1;
	queue<NodeType> pqu;
	e.vno = v;                     //建立源点结点e(根结点)
	e.length = 0;
	pqu.push(e);                   //源点结点e进队
	dist[v] = 0;
	
	while(!pqu.empty())            //队列不空循环 
	{
		e = pqu.front();
		pqu.pop();                //出队列结点e 
		for(int j=0;j<n;j++)
		{
			if(a[e.vno][j]<INF && e.length+a[e.vno][j]<dist[j])
			{ //剪枝：e.vno到顶点j有边并且路径长度更短
			    dist[j] = e.length+a[e.vno][j];
				prev[j] = e.vno;
				e1.vno = j;       //建立相邻顶点j的结点e1 
				e1.length = dist[j];
				pqu.push(e1);     //结点e1进队 
				
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
