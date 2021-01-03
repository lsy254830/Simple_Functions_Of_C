//所谓水仙花数，就是一个三位数，其各位数字立方和等于该数本身。例如153就是一个水仙花数。
//本函数实现的功能：判断输入的数是否为水仙花数，并输出所有的水仙花数。
#include<iostream>
#include<math.h>
using namespace std;
bool judge(int x);
int main()
{
    int x,i;
	cout<<"请输入一个三位数：";
	cin>>x;
	if (judge(x))
		cout<<x<<"是水仙花数！"<<endl;
	else
		cout<<x<<"不是水仙花数！"<<endl;

	cout<<"所有的水仙花数有："<<endl;
	for (i=100;i<1000;i++)
	{
		if (judge(i))
			cout<<i<<"  ";
	}
    return 1;

}
bool judge(int x)
{
	int m,sum=0;
	int self=x;
	while (x>0)
	{
		m=x%10;
		x/=10;
		sum+=pow(m,3);
	}
	if (sum==self)
		return 1;
	else
		return 0;
}
