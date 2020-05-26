#include<iostream>
#include<algorithm>
#include<string.h>
#define MAXN 20
using namespace std;

//问题表示
int n=5;
double W=100;                                      //限重
class NodeType{
public:
	double w;
	double v;
	double p;                                       //p=v/w
	
	bool operator<(const NodeType &s) const
	{
		return p>s.p;                               //按p递减排序
	}
};
NodeType A[] = {{0},{10,20},{20,30},{30,66},{40,40},{50,60}};
//求解结果表示
double V;                                           //最大价值
double x[MAXN];

void Knap()
{  //求解背包问题并返回总价值
	V=0;                                            //V初始化为0
	double weight = W;                              //背包中能装入的余下重量
	memset(x,0,sizeof(x));
	int i=1;
	while(A[i].w<weight)                            //物品i能够全部装入时循环
	{
		x[i] = 1;                                   //装入物品i
		weight-=A[i].w;                             //减少背包中能装入的余下重量
		V+=A[i].v;                                  //累计总价值
		i++;                                        //继续循环
	}
	if(weight>0)                                    //当余下重量大于0
	{
		x[i] = weight/A[i].w;                       //将物品i的一部分装入
		V+=x[i]*A[i].v;                             //累计总价值
	}
}

void dispA()
{  //打印A数组 
	cout<<"    序号"<<'\t'<<"重量"<<'\t'<<"价值"<<'\t'<<"单位价值"<<endl;
	for(int i=1;i<=n;i++)
		cout<<"    "<<i<<'\t'<<'\t'<<A[i].w<<'\t'<<A[i].v<<'\t'<<A[i].p<<endl;
	    
}

int main()
{
	cout<<"求解过程："<<endl<<endl;
	for(int i=1;i<=n;i++)
	    A[i].p = A[i].v/A[i].w;                     //求v/w
	cout<<"排序前"<<endl;
	dispA();
	
	sort(A+1,A+1+n);                                //A[1..n]排序
	cout<<endl<<"排序后"<<endl;
	dispA();
	Knap();
    cout<<endl<<"求解结果："<<endl;                 //输出结果
    cout<<"    x: [ ";
    for(int j=1;j<n;j++)
        cout<<x[j]<<", ";
    cout<<x[n]<<"]"<<endl<<endl;
    cout<<"总价值为"<<V<<endl;
}

