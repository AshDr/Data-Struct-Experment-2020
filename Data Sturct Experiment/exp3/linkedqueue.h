#ifndef _LINKEDQUEUE_H_
#define _LINKEDQUEUE_H_
//�����ж��弰����ʵ��
#include<iostream>
#include<cstdio>
#include<cstdlib>
typedef int elementType;  //elementType ����Ϊ��������



//�������ӽڵ�
typedef struct LNode
{
	elementType data;
	struct LNode *next;
} node;
 
//��������ָ��ṹ
typedef struct 
{
	node* front;
	node* rear;
}linkedQueue;
using namespace std;
//--1.���ӳ�ʼ��------------------------------------------------
void initialQueue(linkedQueue &Q)
{
	Q.rear=Q.front=NULL;//����ͷ�ڵ㣬���迪�ٿռ� 
}

//--2.�ж϶ӿ�--------------------------------------------------
bool queueEmpty(linkedQueue &Q)
{
	return (Q.front==NULL);
}

//--3.ȡ��ͷԪ��------------------------------------------------
bool getFront(linkedQueue &Q, elementType &x)
{
	if(queueEmpty(Q))
		return false;  //�ն��У��޷�ȡ��ͷԪ��
	else
	{
		x=Q.front->data;
		return true;
	}
}

//--4.���-------------------------------------------------------
void enQueue(linkedQueue &Q, elementType x)
{
	node* P=new node;  //�����ڴ棬�����½ڵ�
	P->data=x;
	P->next=NULL;
	if(queueEmpty(Q)) {
		Q.front = P;
		Q.rear = P;
	}//���⴦�� 
	else {
		Q.rear->next=P;
		Q.rear=P; //βָ��ָ���µĽڵ㣨�¶�β��	
	}
}

//--5.����-------------------------------------------------------
bool outQueue(linkedQueue &Q)
{
	node* u; //����ָ��ɾ���ڵ�
	if(queueEmpty(Q))
		return false;    //�ӿգ��޷�ִ�г��Ӳ���
	else
	{
		u=Q.front;          //uָ��front
		Q.front=Q.front->next;
		delete u;                 //ɾ��ԭ��ͷ���ͷ��ڴ�
		return true;
	}
}


//--6.���ٶ��У��ͷ��ڴ�
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


//����ѭ��Ԫ�����
void createLinkedQueue(linkedQueue &Q)
{		
	elementType x;
	node *p;	
	if(Q.front!=NULL)   //δ��ʼ�����Ƚ��г�ʼ��
	{
		Q.front=NULL;
		Q.rear=Q.front;	
	}	
	
	cout<<"����������Ԫ��(������-9999�˳�):"<<endl;
	cout<<"x=";
	cin>>x;
	while(x!=-9999)   //�ǽ�������ѭ����ջ
	{
		p=new node;
		p->data=x;
                        //β�����
		p->next=NULL;   //��p->next=Q.rear->next;
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

//��ӡ����Ԫ��
void printQueue(linkedQueue &Q)
{
	node* p;
	if(queueEmpty(Q))
		cout<<"���пգ�"<<endl;
	else
	{
		p=Q.front;
		cout<<"����Ԫ�أ��Ӷ�ͷ����β����"<<endl;
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
}//�󳤶� 
void fun(linkedQueue &Q) {
	int temp;
	cout<<"����Ԫ�أ�";
	cin>>temp;
	initialQueue(Q);//��ʼ�� 
	while(temp!=0) {
		if(temp%2) {
			enQueue(Q,temp);	
		}
		else {
			outQueue(Q);
		}//���� 
		printQueue(Q);//��� 
		cout<<"����Ԫ�أ�";
		cin>>temp;
	}
	return ;
}
#endif
