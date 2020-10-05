#ifndef _SEQQUEUE_H_
#define _SEQQUEUE_H_
//顺序循环队列的定义和运算实现

#include <iostream>
#include<cstdio>
//----------------------------------------------------------------------
//定义相关符号
#define MAXLEN 100
typedef int elementType;

//----------------------------------------------------------------------
//顺序队列存储结构定义
typedef struct sQueue
{
	elementType data[MAXLEN];
	int front,rear;
}seqQueue;

using namespace std;
//----------------------------------------------------------------------
//1. 初始化顺序队列
void initialQueue(seqQueue &Q)
{
	Q.front=0; 
	Q.rear=0;
}
//----------------------------------------------------------------------
//2. 判队空
bool queueEmpty(seqQueue &Q)
{
	if(Q.front==Q.rear)
		return true;  //队空，返回true
	else
		return false;  //队不空
}
//----------------------------------------------------------------------
//3. 判队满
bool queueFull(seqQueue &Q)
{
	if(((Q.rear+1) % MAXLEN)==Q.front)
		return true;  //队满，返回true
	else
		return false;  //不满，返回false
}
//----------------------------------------------------------------------
//4. 取队头元素
bool getFront(seqQueue &Q, elementType &x)
{
	if(queueEmpty(Q))
		return false; //队空
	else
	{
		x=Q.data[(Q.front+1) % MAXLEN];  //front指示的下一个单元才是队头元素
	    return true;
	}
}
//----------------------------------------------------------------------
//5. 入队（插入）
bool enQueue(seqQueue &Q, elementType x)
{
	if(queueFull(Q))
		return false;    //队列已满
	else
	{
		Q.rear=((Q.rear)+1) % MAXLEN;  //后移rear
		Q.data[Q.rear]=x;  //填入数据x
		return  true;
	}
}
//----------------------------------------------------------------------
//6. 出队（删除）
bool outQueue(seqQueue& Q)
{
	if(queueEmpty(Q))
		return false;  //空队列，没有元素可供出队！
	else
	{
		Q.front=(Q.front+1) % MAXLEN;
		return true;
	}
}

//打印队元素
void printQueue(seqQueue &Q)
{
	int i;
	if(Q.front==Q.rear)
		cout<<"空队列。";
	else
	{
		cout<<"队列元素数："<<(Q.rear-Q.front+MAXLEN)%MAXLEN<<"。"<<endl;
		cout<<"队列元素：";
		i=(Q.front+1)%MAXLEN;   //i指第一个元素
		while(i!=Q.rear)
		{
			cout<<Q.data[i]<<"\t";
			i=(i+1)%MAXLEN;		
		}
		cout<<Q.data[Q.rear]<<"\t";  //打印队尾元素				
	}
	cout<<endl<<endl;
}

//交互循环压入元素
void createSeqQueue(seqQueue &Q)
{		
	elementType x;
	
	cout<<"请输入数据元素(整数，-9999退出):"<<endl;
	cout<<"x=";
	cin>>x;

	while(x!=-9999 && (Q.rear+1)%MAXLEN!=Q.front)   //非结束符，且队未满，循环入队
	{
		Q.rear=(Q.rear+1)%MAXLEN;   //队尾循环后移
		Q.data[Q.rear]=x;

		cout<<"x=";
		cin>>x;
	}
	if((Q.rear+1)%MAXLEN==Q.front)
		cout<<"队满，不能再进行元素入队。"<<endl;
}
int getlen(seqQueue &Q) {
	 return (Q.rear-Q.front+MAXLEN)%MAXLEN;
}
void fun(seqQueue &Q) {
	int temp;
	cout<<"输入元素：";
	cin>>temp;
	initialQueue(Q);//初始化 
	while(temp!=0) {
		if((Q.rear+1)%MAXLEN==Q.front){
			cout<<"队满，不能再进行元素入队。"<<endl;
			break;	
		}
		if(temp%2) {
			enQueue(Q,temp);	
		}
		else {
			outQueue(Q);
		}//操作 
		printQueue(Q);//输出 
		cout<<"输入元素：";
		cin>>temp;
	}
	return ;
}
#endif
