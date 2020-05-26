#include<iostream>
#include<algorithm>
#include<string.h>
#define MAXN 20
using namespace std;


int w[] = {0,5,2,6,4,3};
int n=5,W=10;

int maxw;                                     //������Ž��������
int x[MAXN];                                  //������Ž�����

void solve()
{  //�������װ������
	memset(x,0,sizeof(x));
	sort(w+1,w+1+n);                          //w[1..n]��������
	maxw = 0;
	int restw = W;                            //ʣ������
	for(int i=1;i<=n && w[i]<=restw;i++)
	{
		x[i] = 1;                             //ѡ��װ��i
		restw -= w[i];                        //����ʣ������
		maxw += w[i];                         //�ۼ�װ��������
	}
}

int main()
{
	solve();
	cout<<"���ŷ�����"<<endl<<endl;
	for(int i=1;i<=n;i++)
	    if(x[i] == 1)
	    	cout<<"  ѡȡ����Ϊ"<<w[i]<<"�ļ�װ��"<<endl;
	cout<<endl<<"������Ϊ"<<maxw<<endl; 
}
