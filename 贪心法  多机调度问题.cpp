//�����������Ҫ�����һ����ҵ���ȷ�����
//ʹ������n����ҵ�ھ����̵ܶ�ʱ������m̨�����ӹ�������ɡ� 
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<queue>
using namespace std;

//�����ʾ
int n=7;                                         //��ҵ���� 
int m=3;                                         //�������� 
class NodeType{                                  //���ȶ��н������
public:  
	int no;                                      //��ҵ���
	int t;                                       //ִ��ʱ��
	int mno;                                     //�������
	 
	bool operator<(const NodeType &s) const
	{
		return t>s.t;                            //��tԽСԽ���ȳ���
	}
};

NodeType A[] = {{1,2},{2,14},{3,4},{4,16},{5,6},{6,5},{7,3}};

void solve()
{  //�������������
	NodeType e;
	if(n<=m)
	{
		cout<<"Ϊÿһ����ҵ����һ̨����"<<endl;
		return;
	}
	sort(A,A+n);                                //��t�ݼ�����
	priority_queue<NodeType> qu;                //С����
	for(int i=0;i<m;i++)                        //�ȷ���m����ҵ��ÿ̨����һ����ҵ
	{
		A[i].mno = i+1;                         //��ҵ��Ӧ�Ļ������
		cout<<"������ "<<A[i].mno<<" ������ҵ "<<A[i].no
            <<" ִ��ʱ��Ϊ "<<setw(2)<<A[i].t<<" ռ��ʱ��� [0,"<<A[i].t<<"]"<<endl<<endl; 
        qu.push(A[i]);
	}
	for(int j=m;j<n;j++)                        //����������ҵ
	{
		e=qu.top();
		qu.pop();                               //����e
		cout<<"������ "<<e.mno<<" ������ҵ "<<A[j].no
            <<" ִ��ʱ��Ϊ "<<setw(2)<<A[j].t<<" ռ��ʱ��� ["<<e.t<<","<<e.t+A[j].t<<"]"<<endl<<endl;
        e.t += A[j].t;
        qu.push(e);                             //e����
	}
}

int main()
{
	solve();
}
