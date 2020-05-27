//田忌赛马
/*【问题描述】二千多年前的战国时期，齐威王与大将田忌赛马。
   双方约定每人各出300匹马，并且在上、中、下三个等级中各选一匹进行比赛，
   由于齐威王每个等级的马都比田忌的马略强，比赛的结果可想而知。
   现在双方各n匹马，依次派出一匹马进行比赛，
   每一轮获胜的一方将从输的一方得到200银币，平局则不用出钱，
   田忌已知所有马的速度值并可以安排出场顺序，问他如何安排比赛获得的银币最多。
   
输入：输入包含多个测试用例，
	每个测试用例的第一行正整数n（n≤1000）马的数量，
	后两行分别是n个整数，表示田忌和齐威王的马的速度值。输入n=0结束。
	
输出：每个测试用例输出一行，表示田忌获得的最多银币数。
*/ 
#include<iostream>
#include<algorithm>
#define MAX 1000
using namespace std;

int n;                                       //马的数量 
int a[MAX];                                  //田忌的马的速度 
int b[MAX];                                  //齐威王的马的速度 
 
int ans;                                     //田忌获得的银币数 

void solve()
{
	sort(a,a+n);                             //对a递增排序
	sort(b,b+n);                             //对b递增排序
	ans = 0;
	int lefta=0,leftb=0;
	int righta=n-1,rightb=n-1;
	
	while(lefta<=righta)                     //比赛直到结束
	{
		if(a[righta] > b[rightb])            //田忌最快的马比齐威王最快的马快，两者比赛
		{
			ans += 200;
			righta--;
			rightb--;
		} 
		else if(a[righta] < b[rightb])       //田忌最快的马比齐威王最快的马慢
		{
			ans -= 200;                      //选择田忌最慢的马与比齐威王最快的马比赛
			lefta++;
			rightb--;
		}
		else                                 //田忌最快的马与齐威王最快的马的速度相同
		{
			if(a[lefta] > b[leftb])          //田忌最慢的马比齐威王最慢的马快，两者比赛
			{
				ans += 200;
				lefta++;
				leftb++;
			}
			else
			{
				if(a[lefta] < b[leftb])      //否则，用田忌最慢的马与齐威王最快的马比赛
				    ans -= 200;
				lefta++;
				rightb--;
			}
		}
	}
}

int main()
{
	while(true)
	{
		cout<<"请输入马的数量：";
		cin>>n;
		if(n==0)
		    break;
		cout<<endl<<"请输入田忌的马的速度：";
		for(int i=0;i<n;i++)
		    cin>>a[i];
		cout<<endl<<"请输入齐威王的马的速度：";	
		for(int j=0;j<n;j++)
		    cin>>b[j];
		solve();
		cout<<endl<<"    田忌获得的最多银币数为"<<ans<<endl<<endl;
	}
}
