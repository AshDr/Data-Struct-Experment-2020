#ifndef _SEQSTACK_H_
#define _SEQSTACK_H_
#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXLEN 100
typedef int elementType;
typedef struct sStack
{
	elementType data[MAXLEN];
	int top;
}seqStack;
using namespace std;
void initialStack(seqStack &S)
{
	S.top=-1;
}
bool stackEmpty(seqStack &S) //��ֵ��ָ�롢����
{
	if(S.top==-1)
		return true;
	else
		return false;
}
bool getTop(seqStack &S, elementType &x)
{
	if(stackEmpty(S))
		return false; //��ջ������false
	else
	{
		x=S.data[S.top];
		return true;  //ȡ��ջ��������true��ȡ�õ�ֵ�� x ���ݡ�
	}
}
bool stackFull(seqStack &S)
{
	if(S.top==MAXLEN-1)
		return true; //ջ��������true
	else
		return false; //ջδ��������false
}
bool push(seqStack &S, elementType x)
{
	if(stackFull(S))
		return false; //ջ����������ջ������false
	else
	{
		S.top++; //����ջ��
		S.data[S.top]=x; //������ջ
		return true;
	}
}
bool pop(seqStack &S) //r���ص�����Ԫ��
{
	if(stackEmpty(S)) //��ջ��ûԪ�س�ջ������false
		return false;
	else
	{
		S.top--;
		return true;
	}
}
void printStack(seqStack &S)//��ӡջԪ�� 
{
	int i;
	if(S.top==-1)
		cout<<"��ջ��";
	else
	{
		cout<<"ջ��Ԫ������"<<S.top+1<<"��"<<std::endl;
		cout<<"ջԪ�أ�";
		for(i=0;i<=S.top;i++)
		{
			cout<<S.data[i]<<"\t";			
		}		
	}
	cout<<endl;
}
void change_radix(seqStack &s,int x) {
	while(!stackEmpty(s)) pop(s);
	while(x) {
		push(s,x%16);
		x/=16;
	}
	int t;
	char temp;
	while(!stackEmpty(s)) {
		getTop(s,t);
		pop(s);
		if(t<10) temp = '0'+t;
		else temp = 'A'+t-10; 
		cout<<temp;
	}
	return ;
}
bool parenthesis_match(seqStack &s,string s1) {//����ƥ�� 
	while(!stackEmpty(s)) pop(s);
	int len  = s1.length();
	int k=0;
	int temp,t;
	while(k<len) {
		char ch= s1[k];
		if(ch=='{'||ch=='['||ch=='(') {
			temp = (int)ch;
			push(s,temp);
		}//�������ֱ��ѹջ 
		else {//������һ�Ƚ� 
			if(stackEmpty(s)) return false;
			getTop(s,t);
			if(ch==']') {
				if(t!=(int)'[') return false;
				pop(s);
			}
			else if(ch=='}') {
				if(t!=(int)'{') return false;
				pop(s);
			}
			else if(ch==')') {
				if(t!=(int)'(') return false;
				pop(s);
			}
		}
		k++;  
	}
	if(stackEmpty(s)) return true;
	else return false;//����� 
}
#endif
