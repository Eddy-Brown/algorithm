//�ж��Ӽ��������Ƿ���ڽ�
#include<iostream>
using namespace std;

int count;                             //ȫ�ֱ������ۼƽ���� 
int n = 4,W;
int w[] = {0,11,13,24,7};

void dfs(int i,int tw,int rw)
{   //����Ӽ��� 
	if(i>n)                            //�ҵ�һ��Ҷ�ӽ��
	{
		if(tw==W)                    
		{
			count++;                 //�ҵ�һ�����������Ľ�,�������1 
		}
	}
	else                               //��δ����������Ʒ
	{
		if(tw+w[i]<=W)                 //���ӽ���֦
		{
			dfs(i+1,tw+w[i],rw-w[i]);
		}
		if(tw+rw-w[i]>=W)              //�Һ��ӽ���֦
		{
            dfs(i+1,tw,rw-w[i]);      //��ѡȡ��i����Ʒ,����
		}
	}
}

bool solve()
{//�ж��Ӽ��������Ƿ���ڽ� 
	count = 0;
	int rw = 0;
	for(int j=1;j<=n;j++)            
	    rw+=w[j];                    //���rw 
	dfs(1,0,rw);
	if(count>0)
	    return true;
	else
	    return false;
}

int main()
{
	if(solve())
	    cout<<"�����Ӽ���"<<endl;
	else
	    cout<<"�������Ӽ���"<<endl;
	return 0;
}
