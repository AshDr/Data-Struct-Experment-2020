#ifndef _SEQQUEUE_H_
#define _SEQQUEUE_H_
//˳��ѭ�����еĶ��������ʵ��

#include <iostream>
#include<cstdio>
//----------------------------------------------------------------------
//������ط���
#define MAXLEN 100
typedef int elementType;

//----------------------------------------------------------------------
//˳����д洢�ṹ����
typedef struct sQueue
{
	elementType data[MAXLEN];
	int front,rear;
}seqQueue;

using namespace std;
//----------------------------------------------------------------------
//1. ��ʼ��˳�����
void initialQueue(seqQueue &Q)
{
	Q.front=0; 
	Q.rear=0;
}
//----------------------------------------------------------------------
//2. �жӿ�
bool queueEmpty(seqQueue &Q)
{
	if(Q.front==Q.rear)
		return true;  //�ӿգ�����true
	else
		return false;  //�Ӳ���
}
//----------------------------------------------------------------------
//3. �ж���
bool queueFull(seqQueue &Q)
{
	if(((Q.rear+1) % MAXLEN)==Q.front)
		return true;  //����������true
	else
		return false;  //����������false
}
//----------------------------------------------------------------------
//4. ȡ��ͷԪ��
bool getFront(seqQueue &Q, elementType &x)
{
	if(queueEmpty(Q))
		return false; //�ӿ�
	else
	{
		x=Q.data[(Q.front+1) % MAXLEN];  //frontָʾ����һ����Ԫ���Ƕ�ͷԪ��
	    return true;
	}
}
//----------------------------------------------------------------------
//5. ��ӣ����룩
bool enQueue(seqQueue &Q, elementType x)
{
	if(queueFull(Q))
		return false;    //��������
	else
	{
		Q.rear=((Q.rear)+1) % MAXLEN;  //����rear
		Q.data[Q.rear]=x;  //��������x
		return  true;
	}
}
//----------------------------------------------------------------------
//6. ���ӣ�ɾ����
bool outQueue(seqQueue& Q)
{
	if(queueEmpty(Q))
		return false;  //�ն��У�û��Ԫ�ؿɹ����ӣ�
	else
	{
		Q.front=(Q.front+1) % MAXLEN;
		return true;
	}
}

//��ӡ��Ԫ��
void printQueue(seqQueue &Q)
{
	int i;
	if(Q.front==Q.rear)
		cout<<"�ն��С�";
	else
	{
		cout<<"����Ԫ������"<<(Q.rear-Q.front+MAXLEN)%MAXLEN<<"��"<<endl;
		cout<<"����Ԫ�أ�";
		i=(Q.front+1)%MAXLEN;   //iָ��һ��Ԫ��
		while(i!=Q.rear)
		{
			cout<<Q.data[i]<<"\t";
			i=(i+1)%MAXLEN;		
		}
		cout<<Q.data[Q.rear]<<"\t";  //��ӡ��βԪ��				
	}
	cout<<endl<<endl;
}

//����ѭ��ѹ��Ԫ��
void createSeqQueue(seqQueue &Q)
{		
	elementType x;
	
	cout<<"����������Ԫ��(������-9999�˳�):"<<endl;
	cout<<"x=";
	cin>>x;

	while(x!=-9999 && (Q.rear+1)%MAXLEN!=Q.front)   //�ǽ��������Ҷ�δ����ѭ�����
	{
		Q.rear=(Q.rear+1)%MAXLEN;   //��βѭ������
		Q.data[Q.rear]=x;

		cout<<"x=";
		cin>>x;
	}
	if((Q.rear+1)%MAXLEN==Q.front)
		cout<<"�����������ٽ���Ԫ����ӡ�"<<endl;
}
int getlen(seqQueue &Q) {
	 return (Q.rear-Q.front+MAXLEN)%MAXLEN;
}
void fun(seqQueue &Q) {
	int temp;
	cout<<"����Ԫ�أ�";
	cin>>temp;
	initialQueue(Q);//��ʼ�� 
	while(temp!=0) {
		if((Q.rear+1)%MAXLEN==Q.front){
			cout<<"�����������ٽ���Ԫ����ӡ�"<<endl;
			break;	
		}
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
