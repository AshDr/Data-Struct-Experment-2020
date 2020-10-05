#ifndef _LINKEDQUEUE_H_
#define _LINKEDQUEUE_H_
//链队列定义及运算实现
#include<iostream>
#include<cstdio>
#include<cstdlib>
typedef int elementType;  //elementType 定义为整数类型



//定义链队节点
typedef struct LNode
{
	elementType data;
	struct LNode *next;
} node;
 
//定义链队指针结构
typedef struct 
{
	node* front;
	node* rear;
}linkedQueue;
using namespace std;
//--1.链队初始化------------------------------------------------
void initialQueue(linkedQueue &Q)
{
	Q.rear=Q.front=NULL;//不带头节点，无需开辟空间 
}

//--2.判断队空--------------------------------------------------
bool queueEmpty(linkedQueue &Q)
{
	return (Q.front==NULL);
}

//--3.取队头元素------------------------------------------------
bool getFront(linkedQueue &Q, elementType &x)
{
	if(queueEmpty(Q))
		return false;  //空队列，无法取队头元素
	else
	{
		x=Q.front->data;
		return true;
	}
}

//--4.入队-------------------------------------------------------
void enQueue(linkedQueue &Q, elementType x)
{
	node* P=new node;  //申请内存，产生新节点
	P->data=x;
	P->next=NULL;
	if(queueEmpty(Q)) {
		Q.front = P;
		Q.rear = P;
	}//特殊处理 
	else {
		Q.rear->next=P;
		Q.rear=P; //尾指针指向新的节点（新队尾）	
	}
}

//--5.出队-------------------------------------------------------
bool outQueue(linkedQueue &Q)
{
	node* u; //用以指向删除节点
	if(queueEmpty(Q))
		return false;    //队空，无法执行出队操作
	else
	{
		u=Q.front;          //u指向front
		Q.front=Q.front->next;
		delete u;                 //删除原队头，释放内存
		return true;
	}
}


//--6.销毁队列，释放内存
void destroyQueue(linkedQueue &Q)
{
	node *p,*u;
	p=Q.front;
	while(p!=NULL)
	{
		u=p;
		p=p->next;
		delete(u);
	}
	Q.front=NULL;
	Q.rear=NULL;
}


//交互循环元素入队
void createLinkedQueue(linkedQueue &Q)
{		
	elementType x;
	node *p;	
	if(Q.front!=NULL)   //未初始化，先进行初始化
	{
		Q.front=NULL;
		Q.rear=Q.front;	
	}	
	
	cout<<"请输入数据元素(整数，-9999退出):"<<endl;
	cout<<"x=";
	cin>>x;
	while(x!=-9999)   //非结束符，循环入栈
	{
		p=new node;
		p->data=x;
                        //尾插入队
		p->next=NULL;   //或p->next=Q.rear->next;
		if(Q.front==NULL) {
			Q.front = p;
			Q.rear = p;
			cout<<"x=";
			cin>>x;	
		}
		else {
			Q.rear->next=p;
			Q.rear=p;
			cout<<"x=";
			cin>>x;	
		}
	}
}

//打印队列元素
void printQueue(linkedQueue &Q)
{
	node* p;
	if(queueEmpty(Q))
		cout<<"队列空！"<<endl;
	else
	{
		p=Q.front;
		cout<<"队列元素（从队头到队尾）："<<endl;
		while(p!=NULL)
		{
			cout<<p->data<<"\t";
			p=p->next;
		}
		cout<<endl;
	}
}
int getlen(linkedQueue &Q) {
	node *p =Q.front;
	int len=0;
	while(p!=NULL) {
		len++;
		p=p->next;
	} 
	return len;
}//求长度 
void fun(linkedQueue &Q) {
	int temp;
	cout<<"输入元素：";
	cin>>temp;
	initialQueue(Q);//初始化 
	while(temp!=0) {
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
