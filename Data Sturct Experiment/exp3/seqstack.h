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
bool stackEmpty(seqStack &S) //传值、指针、引用
{
	if(S.top==-1)
		return true;
	else
		return false;
}
bool getTop(seqStack &S, elementType &x)
{
	if(stackEmpty(S))
		return false; //空栈，返回false
	else
	{
		x=S.data[S.top];
		return true;  //取得栈顶，返回true；取得的值有 x 传递。
	}
}
bool stackFull(seqStack &S)
{
	if(S.top==MAXLEN-1)
		return true; //栈满，返回true
	else
		return false; //栈未满，返回false
}
bool push(seqStack &S, elementType x)
{
	if(stackFull(S))
		return false; //栈满，不能入栈，返回false
	else
	{
		S.top++; //增加栈顶
		S.data[S.top]=x; //数据入栈
		return true;
	}
}
bool pop(seqStack &S) //r带回弹出的元素
{
	if(stackEmpty(S)) //空栈，没元素出栈，返回false
		return false;
	else
	{
		S.top--;
		return true;
	}
}
void printStack(seqStack &S)//打印栈元素 
{
	int i;
	if(S.top==-1)
		cout<<"空栈。";
	else
	{
		cout<<"栈内元素数："<<S.top+1<<"。"<<std::endl;
		cout<<"栈元素：";
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
bool parenthesis_match(seqStack &s,string s1) {//括号匹配 
	while(!stackEmpty(s)) pop(s);
	int len  = s1.length();
	int k=0;
	int temp,t;
	while(k<len) {
		char ch= s1[k];
		if(ch=='{'||ch=='['||ch=='(') {
			temp = (int)ch;
			push(s,temp);
		}//这种情况直接压栈 
		else {//否则逐一比较 
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
	else return false;//最后处理 
}
#endif
