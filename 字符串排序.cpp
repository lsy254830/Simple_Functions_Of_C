//Ӣ���ַ�������
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s[5],p;
	int i,j;
	cout<<"������5��Ӣ���ַ�����"<<endl;
	for (i=0;i<5;i++)
	{
		cin>>s[i];
	}
	for (i=0;i<5;i++)
	{
		for (j=i;j<5;j++)
		{
			if (s[i]>s[j])
			{
				s[j].swap(s[i]);
			}
		}
	}
	cout<<"������Ϊ��"<<endl;
	for (i=0;i<5;i++)
	{
		cout<<s[i]<<endl;
	}
	return 0;
}
