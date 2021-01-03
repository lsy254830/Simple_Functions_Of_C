//Ó¢ÎÄ×Ö·û´®ÅÅÐò
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s[5],p;
	int i,j;
	cout<<"ÇëÊäÈë5¸öÓ¢ÎÄ×Ö·û´®£º"<<endl;
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
	cout<<"ÅÅÐò½á¹ûÎª£º"<<endl;
	for (i=0;i<5;i++)
	{
		cout<<s[i]<<endl;
	}
	return 0;
}
