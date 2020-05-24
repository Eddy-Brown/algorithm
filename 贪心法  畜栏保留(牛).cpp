#include<iostream>
#include<string.h>
#include<algorithm> 
#define MAX 20
using namespace std;

class Cow{                                     //��ţ����������
public:
	int no;                                    //ţ���
	int b;                                     //��ʼʱ��
	int e;                                     //����ʱ��
	
	bool operator<(const Cow &s) const         //����<��ϵ����
	{
		if(e==s.e)                             //����ʱ����ͬ����ʼʱ���������
		    return b<=s.b;
		else                                   //���򰴽���ʱ���������
		    return e<=s.e;
	}
};

int n=5;
Cow A[] = {{0},{1,1,10},{2,2,4},{3,3,6},{4,5,8},{5,4,7}};

int ans[MAX];                                  //ans[i]��ʾ��A[i].noͷţ���������

void solve()
{  //��������ݻ�Ӽ�����
	sort(A+1,A+n+1);                           //A[1..n]��ָ����ʽ����
	memset(ans,0,sizeof(ans));
	int num = 1;                               //�������
	
	for(int i=1;i<=n;i++)                      //i��j��Ϊ�������±�
	{
		if(ans[i]==0)                          //��iͷţ��û�а�������
		{
			ans[i] = num;                      //��iͷţ��������num
			int preend = A[i].e;               //ǰһ�����ݻ�Ľ���ʱ��
			for(int j=i+1;j<=n;j++)            //����һ�������ݻ�Ӽ�
			{
				if(A[j].b>preend && ans[j]==0)
				{
					ans[j] = num;              //�����ݻ�Ӽ��л������num������
					preend = A[j].e;           //���½���ʱ��
				}
			}
			num++;                             //������һ�������ݻ�Ӽ�,num��1
		}
	}
}

int main()
{
	solve();
	cout<<"�������"<<endl;
	for(int i=1;i<=n;i++)
	    cout<<"    ţ"<<A[i].no<<"���ŵ�����"<<ans[i]<<endl;
}
