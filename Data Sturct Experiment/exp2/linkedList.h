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
void CreateListRear(node*& L) {//β�巨�������� 
	node* p;
	node* q;
	L = new node;
	L->next=NULL;
	q=L;
	ElementType temp;
	int n;
	printf("������ڵ����");
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		printf("��������ֵ:");
		scanf("%d",&temp);
		p=new node;
		p->data=temp;
		p->next = NULL;
		q->next = p;
		q=p;
	}//����ϸ�� 
	return ;
}
void CreateListHead(node*& L) {//ͷ�巨�������� 
	node* p;
	L=new node;
	L->next = NULL;
	ElementType temp;
	int n;
	cout<<"������ڵ����";
	cin>>n;
	for(int i=1; i<=n; i++) {
		cout<<"��������ֵ:";
		cin>>temp;
		p=new node;
		p->data = temp;
		p->next = L->next;
		L->next = p;
	}//����ϸ�� 
	return ;
}
void PrintList(node* L) {//��ӡ���� 
	if(L==NULL || L->next==NULL) {
		printf("error");
		return ; 
	}//����վͲ���ӡ 
	else {
		node* p =L->next;
		while(p!=NULL) {
			printf("%d",p->data);
			p=p->next;
		}
		return ;
	}//��ӡ 
}
void DestroyList(node* L) {//�ݻ����� 
	node* p = L;
	node* q = L;
	while(p!=NULL) {
		p=p->next;
		delete q;
		q=p;
	}
	return ;
}
int listLen(node* L) {//��� 
	node* p = L->next;
	int len;
	while(p!=NULL) {
		len++;
		p=p->next;
	}
	return len; 
}
bool Pos_Value(node* L,ElementType &x) {//���ض�λ�õ�Ԫ�� 
	cout<<"������λ�ã�";
	int i;
	cin>>i;
	if(i>listLen(L)||i==0) {
		return false;
	}//���λ�ô��ڳ��Ȼ���Ϊ0�ͱ��� 
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
void Insert(node* L) {//����Ԫ�� 
	int k;
	ElementType x;
	cout<<"������λ��i��";
	cin>>k;
	cout<<"��������x��ֵ:";
	cin>>x; 
	if(k>listLen(L) || k==0) {
		cout<<"error";
		return ;
	}//������ 
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
	}//����ϸ�� 
}
bool Search(node* L,node*& temp) {//����Ԫ�� 
	ElementType x;
	cout<<"������x��";
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
bool Delete(node* L ) {//ɾ��Ԫ�� 
	int i;
	cout<<"������i:";
	cin>>i;
	if(i>listLen(L)||i==0) return false;//������ 
	else {
		node* p = L;
		int k=0;
		while(k!=i-1) {
			p=p->next;
			k++;
		}//����ǰһ��Ԫ�� 
		node* s;
		s = p->next;
		p->next = s->next;//ɾ��ϸ�� 
		delete s;
		return true;
	}
}
void InceasingInsert(node* L) {//��һ�����������в���Ԫ�� 
	ElementType x;
	int n;
	cout<<"������������n��";
	cin>>n;
	for(int i=1; i<=n; i++) {
		cout<<"������x:";
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
	}//���������Բ��� 
	return ;
}
void Divide(node* L) {//����ż�Էֿ����� 
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
	DestroyList(s);//�ݻ����� 
	return ;
}
void GerIntersection(node* L, node* P) {//������������Ĺ���Ԫ�� 
	node *p = L->next;
	node *q = P->next;
	node *s = new node;
	s->next=NULL;
	node *hs=s,*ts=NULL;
	while(p!=NULL&&q!=NULL) {//�ֱ�������ָ�룬���õ������ʼ��� 
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
	PrintList(s); //��ӡ 
	return ;
}
void DeleteSameEle(node* L) {//ɾ��һ�����е���ͬԪ�� 
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
void Merge(node *&L,node *&P) {//�ϲ����������� 
	node *pre = L;//��¼���ӵ���һ��λ�� 
	node *p = L->next;
	node *q = P->next;
	node *temp;
	delete P;//��ɾ��P���ͷ�ڵ� 
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
		}//���õ������� 
	}
	if(p!=NULL) {
		pre->next=p;
	}//���û������Ĵ��� 
	if(q!=NULL) {
		pre->next=q;
	}//���û������Ĵ��� 
	PrintList(L);
}
#endif
