/*
    �˻ʺ�������һ�����϶����������⣬�ǻ����㷨����̽�㷨���ĵ������⡣��������19������������ѧ�Ҹ�˹��1850�������
    ��8��8��Ĺ��������ϰڷ�8���ʺ�ʹ�䲻���໥���ƣ������������ʺ󶼲��ܴ���ͬһ�С�ͬһ�л�ͬһб���ϣ����ж����ְڷ���

    ������ʵ�ֵĹ��ܣ���ָʾ�û������һ���ʺ��λ��ʱ������������Ϊ[0,7]�����ڵ�������
      ֻҪ�������һ���ʺ����������ͬ��0~7��8��λ�õ�����������Ϊ�˻ʺ������ȫ�����з�����Ŀ��
*/

#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;
const int N=8;
int chess[N][N]={0};//���ڴ������
int path[92][N];//���ڴ��·��������92��
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
        cout<<"�������һ���ʺ��ڵ�һ�е�����(������0-7�ڵ�����):";
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

bool Find_all(PoseType start)//ֻҪ�����һ���ʺ������ͬ��0~7��8��λ�õ���������
                                        //��Ϊ�˻ʺ������ȫ�����з�����Ŀ
{
        int i;
        int step=0;
        for (i=0;i<N-1;i++)
        {
            start.line++;
            start.line%=N;
            Traverse(start,step);
            Clean_chess();//���chess
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
        chess[curpos.row][curpos.line]=1;//�������ûʺ�֮����1����ʾ��
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
            if (Find_next(next))//���Ӧ����ôд��������bug��step���ظ�������Ϊ&��ԭ��
            {
                    Traverse(next,step);
            }
        }
			//����ѭ����ζ���ڵ�ǰ��curpos����£���һ���ʺ��޷��ڷš�

            step--;
            chess[curpos.row][curpos.line]=2;//2����˼���ǲ��ϸ񣬲��ʺ���Ϊ�ڷŻʺ�ĵط���
            Clean_next(curpos);//�����ǰ·�������һ�еı�ǡ�
            path[count][curpos.row]=0;//���·���ļ�¼��
            return 0;

    }
    return 1;
}



bool Pass(PoseType curpos)
{
    int i;
	if (chess[curpos.row][curpos.line])//��Ϊ���ǵ�����2�������
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
	next.row=(curpos.row+1)%N;//������Ϊ��ȷ������������©��
	next.line=0;//���ﻹ����д0����
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

bool Print_way(int count)//�����⣡
{
	int i,j;
	if (!count)
		return 0;
    cout<<"��"<<count<<"�����з�ʽ���£�"<<endl;

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

bool Clean_next(PoseType curpos)//��������������������ǰ·������һ����ɵı�ǣ����ڱ����Ѿ�֤�����󡣡�������
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



