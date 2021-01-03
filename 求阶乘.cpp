//功能：求1-20的阶乘之和
#include<iostream>
using namespace std;
long int factor(int x);
int main()
{
	int i,n;
	unsigned long int sum=0;
	cout<<"请输入数字：";
	cin>>n;
	for (i=1;i<=n;i++)
	{
		sum+=factor(i);
	}
	cout<<n<<"的阶乘为："<<sum<<endl;
	return 0;
}
long int factor(int x)
{
	int i;
	long int sum=1;
	for (i=1;i<=x;i++)
	{
		sum*=i;
	}
	return sum;
}
