//��νˮ�ɻ���������һ����λ�������λ���������͵��ڸ�����������153����һ��ˮ�ɻ�����
//������ʵ�ֵĹ��ܣ��ж���������Ƿ�Ϊˮ�ɻ�������������е�ˮ�ɻ�����
#include<iostream>
#include<math.h>
using namespace std;
bool judge(int x);
int main()
{
    int x,i;
	cout<<"������һ����λ����";
	cin>>x;
	if (judge(x))
		cout<<x<<"��ˮ�ɻ�����"<<endl;
	else
		cout<<x<<"����ˮ�ɻ�����"<<endl;

	cout<<"���е�ˮ�ɻ����У�"<<endl;
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
