/*
    ��˵�Ŵ���һ��������������3������A��B��C��A������64��Բ�̣�Բ�̴�С���ȣ�������£�С�����ϡ�
    ��һ�����������64��Բ�̴�A���Ƶ�C������ÿ��ֻ���ƶ�һ��Բ�̣������ƶ�������ʼ�ձ��ִ������£�С�����ϡ�
    ���ƶ�������ֻ������B����������Ҫд���ƶ��Ĳ��衣����Ǻ�ŵ�����⡣

    ������ʵ�ֵĹ����У����뺺ŵ���Ĳ�����������Ӧ���ƶ����衣
*/
#include<iostream>
using namespace std;
bool hanoi(int i,char x,char y,char z);
int main()
{
	char x,y,z;
	x='A';
	y='B';
	z='C';
	int i;
	cout<<"�����뺺ŵ���Ĳ�����";
	cin>>i;
	cout<<"�ƶ�����������ʾ��"<<endl;
	hanoi(i,x,y,z);
	return 1;
}
bool hanoi(int i,char x,char y,char z)
{
	if (i==1)
	{
		cout<<x<<"-->"<<z<<"    ";
		return 1;
	}
	else
	{
		hanoi(i-1,x,z,y);//�Ȱ�n-1��Բ�̴�A�ƶ���B
		cout<<x<<"-->"<<z<<"    ";//�ٰѵ�n��Բ�̴�A�ƶ���C
		hanoi(i-1,y,x,z);//����n-1��Բ�̴�B�ƶ���C
		cout<<endl;
	}
	return 0;
}
