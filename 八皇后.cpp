/*
    八皇后问题是一个古老而著名的问题，是回溯算法（试探算法）的典型例题。该问题是19世纪著名的数学家高斯于1850年提出：
    在8×8格的国际象棋上摆放8个皇后，使其不能相互共计，即任意两个皇后都不能处于同一行、同一列或同一斜线上，问有多少种摆法。

    本函数实现的功能：当指示用户输入第一个皇后的位置时，行列数必须为[0,7]区间内的整数；
      只要计算出第一个皇后放在任意相同列0~7行8种位置的排列总数即为八皇后问题的全部排列方案数目。
*/

#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;
const int N=8;
int chess[N][N]={0};//用于存放棋盘
int path[92][N];//用于存放路径，共有92条
struct PoseType
{
    int row;
    int line;
};
int count=0;
int stop=0;
bool Find_way();
bool Find_all(PoseType start);
bool Traverse(PoseType curpos,int step);
bool Clean_next(PoseType curpos);
bool Clean_chess();
bool Pass(PoseType curpos);
bool Find_next(PoseType &curpos);
bool Print_way(int count);
bool Copy_path(int count);

int main()
{
    Find_way();
    return 0;
}

bool Find_way()
{
    int step=0;
    PoseType start;
	PoseType curpos;
	int t;
	do
    {
        cout<<"请输入第一个皇后在第一行的列数(请输入0-7内的整数):";
        cin>>t;
        t=(int)t;
    }while(t<0||t>7);

    start.line=t-1;
    start.row=0;
    curpos=start;
    Traverse(start,step);
    Clean_chess();
    system("pause");
    Find_all(start);
    return 1;
}

bool Find_all(PoseType start)//只要求出第一个皇后放在相同列0~7行8种位置的排列总数
                                        //即为八皇后问题的全部排列方案数目
{
        int i;
        int step=0;
        for (i=0;i<N-1;i++)
        {
            start.line++;
            start.line%=N;
            Traverse(start,step);
            Clean_chess();//清除chess
            system("pause");
        }
        return 1;
}

bool Traverse(PoseType curpos,int step)
{
    int j=0;
    PoseType next=curpos;
    if (Pass(curpos)&&!stop)
    {
        path[count][curpos.row]=curpos.line;
        chess[curpos.row][curpos.line]=1;//正常放置皇后之后用1来表示。
        step++;
        if (step==N)
        {
            count++;
            Print_way(count);
            Copy_path(count);
            if (count==92)
                stop=1;
            return 1;
        }
        for (j=0;j<N-step+1;j++)
        {
            next=curpos;
            if (Find_next(next))//这块应该这么写，否则会出bug，step会重复减，因为&的原因。
            {
                    Traverse(next,step);
            }
        }
			//跳出循环意味着在当前的curpos情况下，下一个皇后无法摆放。

            step--;
            chess[curpos.row][curpos.line]=2;//2的意思就是不合格，不适合作为摆放皇后的地方。
            Clean_next(curpos);//清除当前路径块对下一行的标记。
            path[count][curpos.row]=0;//清除路径的记录。
            return 0;

    }
    return 1;
}



bool Pass(PoseType curpos)
{
    int i;
	if (chess[curpos.row][curpos.line])//因为考虑到还有2的情况。
		return 0;
    for (i=0;i<curpos.row;i++)
    {
        if  (abs(path[count][i]-curpos.line)==abs(i-curpos.row))
            return 0;
        if  ( (path[count][i]==curpos.line)||(i==curpos.row) )
            return 0;
    }
    return 1;
}

bool Find_next(PoseType &curpos)
{
	PoseType next;
	next.row=(curpos.row+1)%N;//这里是为了确保，不至于遗漏。
	next.line=0;//这里还是先写0试试
	for (;next.line<N;next.line++)
	{
		if (Pass(next))
		{
 		    curpos=next;
			return 1;
		}
	}
	return 0;
}

bool Print_way(int count)//有问题！
{
	int i,j;
	if (!count)
		return 0;
    cout<<"第"<<count<<"种排列方式如下："<<endl;

    for (i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if (path[count-1][i]==j)
            {
                cout<<1<<" ";
            }
            else
                cout<<0<<" ";
        }
        cout<<endl;
    }

	return 1;
}

bool Clean_next(PoseType curpos)//这个函数的作用是清除当前路径对下一行造成的标记，由于本行已经证明错误。。。。。
{
    int i=curpos.row+1;
    for (int j=0;j<N;j++)
    {
        chess[i][j]=0;
    }
    return 1;
}

bool Copy_path(int count)
{
    int i;
    for (i=0;i<N;i++)
    {
        path[count][i]=path[count-1][i];
    }
    return 1;
}

bool Clean_chess()
{
    int i,j;
    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
            chess[i][j]=0;
    }
    return 1;
}



