//多机调度问题要求给出一种作业调度方案，
//使所给的n个作业在尽可能短的时间内由m台机器加工处理完成。 
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<queue>
using namespace std;

//问题表示
int n=7;                                         //作业总数 
int m=3;                                         //机器总数 
class NodeType{                                  //优先队列结点类型
public:  
	int no;                                      //作业序号
	int t;                                       //执行时间
	int mno;                                     //机器序号
	 
	bool operator<(const NodeType &s) const
	{
		return t>s.t;                            //按t越小越优先出队
	}
};

NodeType A[] = {{1,2},{2,14},{3,4},{4,16},{5,6},{6,5},{7,3}};

void solve()
{  //求解多机调度问题
	NodeType e;
	if(n<=m)
	{
		cout<<"为每一个作业分配一台机器"<<endl;
		return;
	}
	sort(A,A+n);                                //按t递减排序
	priority_queue<NodeType> qu;                //小根堆
	for(int i=0;i<m;i++)                        //先分配m个作业，每台机器一个作业
	{
		A[i].mno = i+1;                         //作业对应的机器编号
		cout<<"给机器 "<<A[i].mno<<" 分配作业 "<<A[i].no
            <<" 执行时间为 "<<setw(2)<<A[i].t<<" 占用时间段 [0,"<<A[i].t<<"]"<<endl<<endl; 
        qu.push(A[i]);
	}
	for(int j=m;j<n;j++)                        //分配余下作业
	{
		e=qu.top();
		qu.pop();                               //出队e
		cout<<"给机器 "<<e.mno<<" 分配作业 "<<A[j].no
            <<" 执行时间为 "<<setw(2)<<A[j].t<<" 占用时间段 ["<<e.t<<","<<e.t+A[j].t<<"]"<<endl<<endl;
        e.t += A[j].t;
        qu.push(e);                             //e进队
	}
}

int main()
{
	solve();
}
