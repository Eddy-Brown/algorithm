//��·�鲢 
#include<iostream>
#include<stdlib.h>     //malloc����ͷ�ļ� 
#define N 5
using namespace std;

void Merge(int a[],int low,int mid,int high) 
{
	int *tmpa;
	int i = low,j = mid+1, k=0;
    tmpa=(int *)malloc((high - low + 1)*sizeof(int));//��̬�ڴ���� 
	
	while(i<=mid && j<=high)
	    if(a[i]<=a[j])      //����1�ӱ��е�Ԫ�ط���tmpa��
	    {
	    	tmpa[k] = a[i];
	    	i++;  k++;
		}
	    else              //����2�ӱ��е�Ԫ�ط���tmpa��
	    {
	    	tmpa[k] = a[j];
	    	j++;  k++;
		}
	while(i<=mid)        //����1�ӱ����²��ָ��Ƶ�tmpa
	{
		tmpa[k] = a[i];
		i++;  k++;
	}
	while(j<=high)      //����2�ӱ����²��ָ��Ƶ�tmpa
	{
		tmpa[k] = a[j];
		j++;  k++;
	}
	for(k=0,i=low;i<=high;k++,i++)      //��tmpa���ƻ�a��
	    a[i] = tmpa[k];
	free(tmpa);                        //�ͷ�tmpa��ռ�ڴ�ռ�
}

void MergePass(int a[],int length,int n)
{
	int i;
	for(i=0;i+2*length-1<n;i=i+2*length)        //�鲢length�����������ӱ�
	    Merge(a,i,i+length-1,i+2*length-1);
	
	if(i+length-1<n)                         //���������ӱ����߳���С��length
	    Merge(a,i,i+length-1,n-1);           //�鲢�������ӱ�
}

void MergeSort(int a[],int n)               //��·�鲢�㷨
{
	int length;
	for(length=1;length<n;length=2*length)
	    MergePass(a,length,n);
}

int main()
{
	int a[N];
	while(cout<<"input a[]:")
	{
		for(int i=0;i<N;i++)
		    cin>>a[i];
		
		MergeSort(a,N);
		
		for(int j=0;j<N;j++)
		    cout<<a[j]<<"  ";
		cout<<endl<<endl;
	}
}
