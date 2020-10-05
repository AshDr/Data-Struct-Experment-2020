#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_


#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef int ElementType;

typedef struct sLNode
{
	ElementType data;
	struct sLNode* next;
} node;
void CreateListRear(node*& L) {//尾插法创建链表 
	node* p;
	node* q;
	L = new node;
	L->next=NULL;
	q=L;
	ElementType temp;
	int n;
	printf("请输入节点个数");
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		printf("请输入结点值:");
		scanf("%d",&temp);
		p=new node;
		p->data=temp;
		p->next = NULL;
		q->next = p;
		q=p;
	}//插入细节 
	return ;
}
void CreateListHead(node*& L) {//头插法创建链表 
	node* p;
	L=new node;
	L->next = NULL;
	ElementType temp;
	int n;
	cout<<"请输入节点个数";
	cin>>n;
	for(int i=1; i<=n; i++) {
		cout<<"请输入结点值:";
		cin>>temp;
		p=new node;
		p->data = temp;
		p->next = L->next;
		L->next = p;
	}//插入细节 
	return ;
}
void PrintList(node* L) {//打印链表 
	if(L==NULL || L->next==NULL) {
		printf("error");
		return ; 
	}//若表空就不打印 
	else {
		node* p =L->next;
		while(p!=NULL) {
			printf("%d",p->data);
			p=p->next;
		}
		return ;
	}//打印 
}
void DestroyList(node* L) {//摧毁链表 
	node* p = L;
	node* q = L;
	while(p!=NULL) {
		p=p->next;
		delete q;
		q=p;
	}
	return ;
}
int listLen(node* L) {//求表长 
	node* p = L->next;
	int len;
	while(p!=NULL) {
		len++;
		p=p->next;
	}
	return len; 
}
bool Pos_Value(node* L,ElementType &x) {//求特定位置的元素 
	cout<<"请输入位置：";
	int i;
	cin>>i;
	if(i>listLen(L)||i==0) {
		return false;
	}//如果位置大于长度或者为0就报错 
	else {
		node* p = L->next; 
		int k=1;
		while(i!=k && p!=NULL) {
			p=p->next;
			k++;
		}
		x = p->data;
		return true;
	}
}
void Insert(node* L) {//插入元素 
	int k;
	ElementType x;
	cout<<"请输入位置i：";
	cin>>k;
	cout<<"请输入结点x的值:";
	cin>>x; 
	if(k>listLen(L) || k==0) {
		cout<<"error";
		return ;
	}//报错处理 
	else {
		int i=0;
		node* p=L;
		while(i!=k-1 && p!=NULL) {
			p=p->next;
			i++;
		}
		node* s;
		s=new node;
		s->data = x;
		s->next = p->next;
		p->next = s;
		return ;
	}//插入细节 
}
bool Search(node* L,node*& temp) {//查找元素 
	ElementType x;
	cout<<"请输入x：";
	cin>>x;
	node* p  = L->next;
	while(p!=NULL) {
		if(p->data==x) {
			temp = p;
			return true;
		}
		p=p->next;
	}
	return false;
}
bool Delete(node* L ) {//删除元素 
	int i;
	cout<<"请输入i:";
	cin>>i;
	if(i>listLen(L)||i==0) return false;//报错处理 
	else {
		node* p = L;
		int k=0;
		while(k!=i-1) {
			p=p->next;
			k++;
		}//到达前一个元素 
		node* s;
		s = p->next;
		p->next = s->next;//删除细节 
		delete s;
		return true;
	}
}
void InceasingInsert(node* L) {//在一个递增链表中插入元素 
	ElementType x;
	int n;
	cout<<"请输入插入个数n：";
	cin>>n;
	for(int i=1; i<=n; i++) {
		cout<<"请输入x:";
		cin>>x;
		node* p = L;
		node* s; 
	while(p->next!=NULL && (p->next->data)<x) {
			p=p->next;
		}
		s = new node;
		s->data = x;
		s->next = p->next;
		p->next = s;	
	}//利用有序性插入 
	return ;
}
void Divide(node* L) {//按积偶性分开链表 
	node* m = L->next;
	node* p=new node;
	p->next=NULL;
	node *hp=p,*tp=NULL;
	node *s=new node;
	s->next=NULL;
	node *hs=s,*ts=NULL;
	while(m!=NULL) {
		if(m->data%2==0) {
			tp = new node;
			tp->data = m->data;
			tp->next=NULL;
			hp->next = tp;
			hp=tp;
		}
		else {
			if(m->data%2==1) {
			ts = new node;
			ts->data = m->data;
			ts->next=NULL;
			hs->next = ts;
			hs=ts;
			}
		}
		m=m->next; 
	}
	PrintList(L);
	puts("");
	PrintList(p);
	puts("");
	PrintList(s);
	puts(""); 
	DestroyList(p);
	DestroyList(s);//摧毁链表 
	return ;
}
void GerIntersection(node* L, node* P) {//求两个递增表的公共元素 
	node *p = L->next;
	node *q = P->next;
	node *s = new node;
	s->next=NULL;
	node *hs=s,*ts=NULL;
	while(p!=NULL&&q!=NULL) {//分别定义两个指针，利用递增性质即可 
		if(p->data == q->data) {
			ts = new node;
			ts->data = q->data;
			ts->next=NULL;
			hs->next=ts;
			hs = ts;
			p=p->next;
			q=q->next;
		}
		else {
			if(p->data > q->data) q=q->next;
			else p=p->next;
		}
	}
	PrintList(s); //打印 
	return ;
}
void DeleteSameEle(node* L) {//删除一个表中的相同元素 
	node *p = L->next;
	node *q=p->next;
	node *u;
	while(q!=NULL) {
		if(q->data==p->data) {
			u=q;
			p->next=q->next;
			q=q->next;	
			delete u;
		}
		else {
			p=q;
			q=p->next;			
		}
	}
	PrintList(L);
	return ;	
}
void Merge(node *&L,node *&P) {//合并两个递增表 
	node *pre = L;//记录连接的上一个位置 
	node *p = L->next;
	node *q = P->next;
	node *temp;
	delete P;//先删除P表的头节点 
	while(p!=NULL&&q!=NULL) {
		if(p->data==q->data) {
			pre->next=p;
			pre=p;
			temp = q;
			p=p->next;
			q=q->next;
			delete temp;
		}
		else {
			if((p->data)<(q->data)) {
				pre->next=p;
				pre=p;
				p=p->next;			
			}
			else if((p->data)>(q->data)) {
				pre->next=q;
				pre=q;
				q=q->next;			
			}
		}//利用递增性质 
	}
	if(p!=NULL) {
		pre->next=p;
	}//如果没遍历完的处理 
	if(q!=NULL) {
		pre->next=q;
	}//如果没遍历完的处理 
	PrintList(L);
}
#endif
