//���ܣ���1-20�Ľ׳�֮��
#include<iostream>
using namespace std;
long int factor(int x);
int main()
{
	int i,n;
	unsigned long int sum=0;
	cout<<"���������֣�";
	cin>>n;
	for (i=1;i<=n;i++)
	{
		sum+=factor(i);
	}
	cout<<n<<"�Ľ׳�Ϊ��"<<sum<<endl;
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
