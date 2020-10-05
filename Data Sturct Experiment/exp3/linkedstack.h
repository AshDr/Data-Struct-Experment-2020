#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_
#include<iostream>
#include<cstdlib>
#include<cstdio>
typedef int elementType;  //elementType ����Ϊ��������

typedef struct lsNode
{
	elementType data;     //��ջ���������
	struct lsNode *next;  //��ջ���ָ����
} node, *linkedStack;
using namespace std;
void initlinkstack(node*& top) {
	top = new node;
	top->next=NULL;
	return ;
}
bool stackEmpty(node* top)
{
	if(top->next==NULL)
		return true;  //ջ�գ�����true
	else
		return false;   //ջ���գ�����false
}
//ȡջ��Ԫ��
bool getTop(node * top, elementType &x)
{
	if(top->next==NULL)
		return false;  //ջ�գ�����false
	else
	{
		x=top->data;   //ȡջ��Ԫ�أ��ò���x����
		return true;   //ȡջ���ɹ�������true
	}
}
//��ջ
void push(node *& top, elementType x)
{
	node* s;
	
	s=new node;
	s->data=x;
	s->next=top;
	top=s;

}
//��ջ
bool pop(node *& top)
{
	node* u;
	if(top->next==NULL)
		return false;   //ջ�գ�����false
	else
	{
		u=top;          //ջ��ָ�뱣�浽u
		top=top->next;  //ջ��ָ�����һ��Ԫ�ؽ��
		delete u;       //�ͷ�ԭջ�����
		return true;    //��ջ�ɹ�������true
	}
}
void destroyStack(node *& top)
{
	node *p,*u;
	p=top;
	while(p)
	{
		u=p;
		p=p->next;
		delete(u);		
	}
	top=NULL;
}
//��ӡջ��Ԫ��
void printStack(linkedStack top)
{
	node* p=top;
	if(stackEmpty(top))
		cout<<"��ջ��"<<endl;
	else
	{
		cout<<"ջ��Ԫ�أ���ջ����ջ�ף���"<<endl;
		while(p!=NULL)
		{
			cout<<p->data<<"\t";
			p=p->next;
		}
		cout<<endl;
	}
}
void change_radix(node *& top, int x) {//����ת�� 
	while(!stackEmpty(top)) pop(top);
	while(x) {
		push(top,x%16);
		x /=16; 	
	}//��ջ 
	int t;
	char temp;
	while(!stackEmpty(top)) {
		getTop(top,t);
		pop(top);
		if(t<10) temp = '0'+t;
		else temp = 'A'+t-10; 
		cout<<temp;
	}//��ջ 
	return ;
}
bool parenthesis_match(node *&top, string s1){//����ƥ�� 
	while(!stackEmpty(top)) pop(top);
	int len = s1.length();
	int k=0;
	int temp,t;
	while(k<len) {
		char ch= s1[k];
		if(ch=='{'||ch=='['||ch=='(') {
			temp = (int)ch;
			push(top,temp);
		}//ֱ��ѹջ 
		else {//����Ƚ� 
			if(stackEmpty(top)) return false;
			getTop(top,t);
			if(ch==']') {
				if(t!=(int)'[') return false;
				pop(top);
			}
			else if(ch=='}') {
				if(t!=(int)'{') return false;
				pop(top);
			}
			else if(ch==')') {
				if(t!=(int)'(') return false;
				pop(top);
			}
		}
		k++;  
	}
	if(stackEmpty(top)) return true;
	else return false;//�ж� 
}
#endif
