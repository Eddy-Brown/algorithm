#include<iostream>
#include<algorithm>
#include<string.h>
#define MAXN 20
using namespace std;

//�����ʾ
int n=5;
double W=100;                                      //����
class NodeType{
public:
	double w;
	double v;
	double p;                                       //p=v/w
	
	bool operator<(const NodeType &s) const
	{
		return p>s.p;                               //��p�ݼ�����
	}
};
NodeType A[] = {{0},{10,20},{20,30},{30,66},{40,40},{50,60}};
//�������ʾ
double V;                                           //����ֵ
double x[MAXN];

void Knap()
{  //��ⱳ�����Ⲣ�����ܼ�ֵ
	V=0;                                            //V��ʼ��Ϊ0
	double weight = W;                              //��������װ�����������
	memset(x,0,sizeof(x));
	int i=1;
	while(A[i].w<weight)                            //��Ʒi�ܹ�ȫ��װ��ʱѭ��
	{
		x[i] = 1;                                   //װ����Ʒi
		weight-=A[i].w;                             //���ٱ�������װ�����������
		V+=A[i].v;                                  //�ۼ��ܼ�ֵ
		i++;                                        //����ѭ��
	}
	if(weight>0)                                    //��������������0
	{
		x[i] = weight/A[i].w;                       //����Ʒi��һ����װ��
		V+=x[i]*A[i].v;                             //�ۼ��ܼ�ֵ
	}
}

void dispA()
{  //��ӡA���� 
	cout<<"    ���"<<'\t'<<"����"<<'\t'<<"��ֵ"<<'\t'<<"��λ��ֵ"<<endl;
	for(int i=1;i<=n;i++)
		cout<<"    "<<i<<'\t'<<'\t'<<A[i].w<<'\t'<<A[i].v<<'\t'<<A[i].p<<endl;
	    
}

int main()
{
	cout<<"�����̣�"<<endl<<endl;
	for(int i=1;i<=n;i++)
	    A[i].p = A[i].v/A[i].w;                     //��v/w
	cout<<"����ǰ"<<endl;
	dispA();
	
	sort(A+1,A+1+n);                                //A[1..n]����
	cout<<endl<<"�����"<<endl;
	dispA();
	Knap();
    cout<<endl<<"�������"<<endl;                 //������
    cout<<"    x: [ ";
    for(int j=1;j<n;j++)
        cout<<x[j]<<", ";
    cout<<x[n]<<"]"<<endl<<endl;
    cout<<"�ܼ�ֵΪ"<<V<<endl;
}

