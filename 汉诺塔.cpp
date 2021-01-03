/*
    据说古代有一个梵塔，塔内有3个座：A、B、C。A座上有64个圆盘，圆盘大小不等，大的在下，小的在上。
    有一个和尚想把这64个圆盘从A座移到C座，但每次只能移动一个圆盘，并在移动过程中始终保持大盘在下，小盘在上。
    在移动过程中只能利用B座。现在需要写出移动的步骤。这就是汉诺塔问题。

    本函数实现的功能有：输入汉诺塔的层数，给出对应的移动步骤。
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
	cout<<"请输入汉诺塔的层数：";
	cin>>i;
	cout<<"移动步骤如下所示："<<endl;
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
		hanoi(i-1,x,z,y);//先把n-1个圆盘从A移动到B
		cout<<x<<"-->"<<z<<"    ";//再把第n个圆盘从A移动到C
		hanoi(i-1,y,x,z);//最后把n-1个圆盘从B移动到C
		cout<<endl;
	}
	return 0;
}
