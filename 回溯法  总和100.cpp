#include<iostream>
#define N 9
using namespace std;

void fun(char op[],int sum,int prevadd,int a[],int i)
{
	if(i==N)                           //ɨ��������λ�� 
	{
		if(sum==100)                   //�ҵ�һ���� 
		{
			cout<<"   "<<a[0];         //����� 
			for(int j=1;j<N;j++)
			{
				if(op[j]!=' ')
				    cout<<op[j];
				cout<<a[j];
			}
			cout<<"=100"<<endl;
		}
		return;
	}
	else
	{
		op[i]='+';                    //λ��i����'+' 
	    sum += a[i];                  //������ 
	    fun(op,sum,a[i],a,i+1);       //����������һ��λ�� 
	    sum -= a[i];                  //���� 
	
	op[i]='-';                        //λ��i����'-' 
	sum -= a[i];                      //������ 
	fun(op,sum,-a[i],a,i+1);          //����������һ��λ�� 
	sum += a[i];                      //���� 
	
	op[i]=' ';                        //λ��i����' '
	sum -= prevadd;                   //�ȼ�ȥǰ���Ԫ��ֵ 
	int tmp;                          //������Ԫ��ֵ 
	if(prevadd>0)
	    tmp = prevadd*10 + a[i];      //��prevadd=5,a[i]=6,���Ϊ56
	else
	    tmp = prevadd*10 - a[i];      //��prevadd=-5,a[i]=6,���Ϊ-56
	sum += tmp;                       //����ϲ����
	fun(op,sum,tmp,a,i+1);            //����������һ��λ��
	sum -= tmp;                       //����sum
	sum += prevadd;
	}

}

int main()
{
	int a[N];
	char op[N];                       //op[i]��ʾ��λ��i���������
	for(int i=0;i<N;i++)              //Ϊa��ֵΪ1,2��...,9
	    a[i]=i+1;
	cout<<"�������"<<endl;
	fun(op,a[0],a[0],a,1);            //����λ��i��1��ʼ
	return 0; 
}
