#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
const int maxn  = 1e4;
struct BST {
    int data;
    int size,num;
    BST *lson;
    BST *rson;
    BST(){}
    BST(int x) 
    :data(x),size(1),num(1),lson(NULL),rson(NULL){}
};
int a[maxn],n,t[maxn];
int get_depth(BST *u) {
	if(u==NULL) return 0;
	return max(get_depth(u->lson),get_depth(u->rson))+1;
}//����� 
int abs(int x) {return x>0?x:-x;}//����ֵ���� 
void brsearch(int x) {
    int l=1,r=n;
    while(l<=r) {
        int mid = l+r>>1;
        if(a[mid]==x) {
            cout<<x;
            return ;
        }
        else if(a[mid]<x) l = mid+1;
        else if(a[mid]>x) r = mid-1;
        cout<<a[mid]<<" "; 
    }
    cout<<"δ�ҵ�"<<endl; 
    return ;
}//���ֲ��� 
void add(BST *&u,int x) {
	if(u==NULL) {
		u = new BST;
		u->data=x;
		u->lson=NULL;
		u->rson=NULL;
		u->num=1;
		u->size=1;
		return ;
	}
	if(x==u->data) {
		u->num++;
		u->size++;
		return ;
	}
	if(x<u->data) add(u->lson,x);
	if(x>u->data) add(u->rson,x);
	u->size=u->num;
	if(u->lson!=NULL) u->size+=u->lson->size;
	if(u->rson!=NULL) u->size+=u->rson->size;
	return ;
}//��BST�����Ԫ�� 
bool del(BST *&u ,int x) {
	if(u==NULL) {
		return false;
	}
	if(u->data==x && u->num!=0) {
		u->size-=u->num;
		u->num=0;
		return true;
	}
	bool flag=false;
	if(x<u->data) flag = flag || del(u->lson,x);
	if(x>u->data) flag = flag || del(u->rson,x);
	return flag;
}//ɾ��Ԫ�� 
bool query(BST *u,int x) {
	if(u==NULL) {
		return false;
	}
	if(u->data==x && u->num!=0) {
		return true;
	}
	bool flag=false;
	if(x<u->data) flag = flag || query(u->lson,x);
	if(x>u->data) flag = flag || query(u->rson,x);
	return flag;
}//ѯ��Ԫ�� 
void LL(BST *&u) {
	BST *temp=NULL;
	temp =  u->lson;
	u->lson = temp->rson;
	temp->rson = u;
	return ;
}//LL��ת 
void RR(BST *&u) {
	BST *temp=NULL;
	temp =  u->rson;
	u->rson = temp->lson;
	temp->lson = u;
	return ;	
}//RR��ת 
void LR(BST *&u) {
	RR(u->lson);
	LL(u);
	return ;	
}//LR��ת 
void RL(BST *&u) {
	LL(u->rson);
	RR(u);
	return ;
}//RL��ת 
void build(BST *&u ,int x) {
	if(u==NULL) {
		u = new BST;
		u->data=x;
		u->lson=NULL;
		u->rson=NULL;
		u->num=1;
		u->size=1;
		return ;
	}
	if(x==u->data) {
		u->num++;
		u->size++;
		return ;
	}
	if(x<u->data){
		build(u->lson,x);
		if(abs(get_depth(u->lson)-get_depth(u->rson))>1) {
			if(x<u->lson->data) LL(u);
			else LR(u);
		}
	}
	if(x>u->data) {
		build(u->rson,x);
		if(abs(get_depth(u->lson)-get_depth(u->rson))>1) {
			if(x>u->rson->data) RR(u);
			else RL(u);
		}		
	}
	u->size=u->num;
	if(u->lson!=NULL) u->size+=u->lson->size;
	if(u->rson!=NULL) u->size+=u->rson->size;
	return ;
}//����ƽ���� 
void destroy(BST *t) {
    if(t==NULL) return ;
    destroy(t->lson);
    destroy(t->rson);
    delete t;
    return ;
}//�ݻ��� 
void init() {
	memset(a,0,sizeof(a));
    cout<<"������Ԫ�ظ���:";
    cin>>n;
    cout<<"����������Ԫ��:";
    for(int i=1; i<=n; i++) cin>>a[i];
    cout<<"��ʼ�����";
}//��ʼ�� 
