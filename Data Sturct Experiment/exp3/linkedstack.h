#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_
#include<iostream>
#include<cstdlib>
#include<cstdio>
typedef int elementType;  //elementType 定义为整数类型

typedef struct lsNode
{
	elementType data;     //链栈结点数据域
	struct lsNode *next;  //链栈结点指针域
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
		return true;  //栈空，返回true
	else
		return false;   //栈不空，返回false
}
//取栈顶元素
bool getTop(node * top, elementType &x)
{
	if(top->next==NULL)
		return false;  //栈空，返回false
	else
	{
		x=top->data;   //取栈顶元素，用参数x返回
		return true;   //取栈顶成功，返回true
	}
}
//入栈
void push(node *& top, elementType x)
{
	node* s;
	
	s=new node;
	s->data=x;
	s->next=top;
	top=s;

}
//出栈
bool pop(node *& top)
{
	node* u;
	if(top->next==NULL)
		return false;   //栈空，返回false
	else
	{
		u=top;          //栈顶指针保存到u
		top=top->next;  //栈顶指针后移一个元素结点
		delete u;       //释放原栈顶结点
		return true;    //出栈成功，返回true
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
//打印栈内元素
void printStack(linkedStack top)
{
	node* p=top;
	if(stackEmpty(top))
		cout<<"空栈！"<<endl;
	else
	{
		cout<<"栈内元素（从栈顶到栈底）："<<endl;
		while(p!=NULL)
		{
			cout<<p->data<<"\t";
			p=p->next;
		}
		cout<<endl;
	}
}
void change_radix(node *& top, int x) {//进制转换 
	while(!stackEmpty(top)) pop(top);
	while(x) {
		push(top,x%16);
		x /=16; 	
	}//入栈 
	int t;
	char temp;
	while(!stackEmpty(top)) {
		getTop(top,t);
		pop(top);
		if(t<10) temp = '0'+t;
		else temp = 'A'+t-10; 
		cout<<temp;
	}//出栈 
	return ;
}
bool parenthesis_match(node *&top, string s1){//括号匹配 
	while(!stackEmpty(top)) pop(top);
	int len = s1.length();
	int k=0;
	int temp,t;
	while(k<len) {
		char ch= s1[k];
		if(ch=='{'||ch=='['||ch=='(') {
			temp = (int)ch;
			push(top,temp);
		}//直接压栈 
		else {//否则比较 
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
	else return false;//判断 
}
#endif
