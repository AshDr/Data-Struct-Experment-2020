#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf = 2147483647;
const int maxn = 1e3;
struct node {
	int val,index;
} tree[maxn<<2];//锦标赛排序所需要的树结点类型 
struct linknode {
	int data;
	linknode *next;
};//普通的链式结点 
int a[maxn],ans[maxn],out[maxn],tong[10];
int num,leafnum,treenum;
void quick_sort(int l, int r,int &cnt) {
	if(l>=r) return ;
	int f = a[l];
	int i=l,j=r;
	while(i<j) {
		while(i<j && a[j]>=f) j--;
		a[i] = a[j];
		cnt++;
		while(i<j && a[i]<=f) i++;
		a[j] = a[i];
		cnt++;
	}
	a[i] = f;
	quick_sort(l,i-1,cnt);
	quick_sort(i+1,r,cnt);
}//快排 
void fun2(int n) {
	int low=1,high=n;
	for(int i=1; i<=n; i++) {
		if(a[i]%3==0) {
			swap(a[low],a[i]);
			low++;
		}
	}
	for(int i=n; i>=low; i--) {
		if(a[i]%3==2) {
			swap(a[high],a[i]);
			high--;
		}
	}
}//实现功能2 
void shell_sort(int n) {
	int d = n/2;
	while(d) {
		for(int i=d+1; i<=n; i++) {
			int j=i-d;
			int t = a[i];
			while(t<a[j] && j>0) {
				a[j+d] = a[j];
				j-=d;
			}
			a[j+d] = t;
		}
		d/=2;
	}
}//希尔排序 
void inittree(int n) {
	leafnum=1;
	while(leafnum<n) leafnum*=2;
	treenum = leafnum*2-1;
	for(int i=treenum,j=n; i>=leafnum; i--,j--) {
		if(j>=1) {
			tree[i].val = a[j];
			tree[i].index = j;
		} else {
			tree[i].val = inf;
			tree[i].index = -1;
		}
	}
	for(int i=treenum; i>=3; i-=2) {
		if(tree[i-1].val<=tree[i].val) tree[i/2] = tree[i-1];
		else tree[i/2] = tree[i];
	}//初始化
}
void update(int index) {
	while(index>1) {
		if(index%2) {
			if(tree[index-1].val<=tree[index].val) tree[index/2] = tree[index-1];
			else tree[index/2] = tree[index];
		} else {
			if(tree[index].val<=tree[index+1].val) tree[index/2] = tree[index];
			else tree[index/2] = tree[index+1];
		}
		index = index/2;
	}
}//锦标赛排序每次更新 
void tournament_sort(int n) {
	inittree(n);
	int i;
	for( i=1; i<n; i++) {
		ans[i] = tree[1].val;
		cout<<"cnt"<<i<<":" <<tree[1].val<<endl;
		int t = treenum-n+tree[1].index;
		tree[t].val = inf;//修改节点值 
		update(t);
	}
	cout<<"cnt"<<i<<":" <<tree[1].val<<endl;
	ans[i] = tree[1].val;
}//锦标赛排序 
void sift(int pos,int n) {
	int t = a[pos];
	bool flag = false;
	int i=pos,j=2*i;
	while(j<=n && !flag) {
		if(j<n && a[j]<a[j+1]) j = j+1;
		if(t>a[j]) flag = true;
		else {
			swap(a[i],a[j]);
			i=j;
			j = i*2;
		}
	}
	a[i] = t;
}//堆排sift 
void initheap(int n) {
	for(int i=n/2; i>=1; i--) {
		sift(i,n);
	}
}//初始化堆 
void heap_sort(int n) {
	initheap(n);
	for(int i=n; i>=2; i--) {
		int t = a[i];
		a[i]  = a[1];
		a[1]  = t;
		sift(1,i-1);
	}
}//堆排 
/*void radix_sort(int maxx) {
    int exp = 1;
    while(exp<=maxx) {
         memset(tong,0,sizeof(tong));
         for(int i=1; i<=n; i++) {
             tong[(a[i]/exp)%10]++;
         }
         for(int i=1; i<10; i++) tong[i] += tong[i-1];
         for(int i=n; i>=1; i--)  {
             out[tong[(a[i]/exp)%10]] = a[i];
             tong[(a[i]/exp)%10]--;
         }
         for(int i=1; i<=n; i++) a[i] = out[i];
         exp*=10;
    }
}*///基数排序普通版
 
class Myqueue {//自建链队列 
	public :
		linknode *rear;
		linknode *head;
		Myqueue() {
			linknode *p  = new linknode;
			p->data=0;
			p->next=NULL;
			head = p;
			rear = p;
		}
		~Myqueue() {
			linknode *p = head;
			linknode *q;
			while(p) {
				q = p;
				p = p->next;
				delete q;
			}
		}//析构函数 
		void push(int x) {
			linknode *p = new linknode;
			p->data = x;
			p->next = NULL;
			rear->next = p;
			rear = p;
		}
		void push(linknode *x) {
			x->next = NULL;
			rear->next = x;
			rear = x;
		}
		bool empty() {
			return head==rear;
		}
		void clear() {
			head->next = NULL;
			rear = head;
		}
		void print() {
			linknode *p = head->next;
			while(p) {
				cout<<p->data<<" ";
				p=p->next;
			}
		}
};
void radix_sort(Myqueue &que,int maxx) {
	Myqueue *tong[10];
	for(int i=0; i<10; i++) tong[i] = new Myqueue;
	int exp=1;
	while(exp<=maxx) {
		linknode *p = que.head->next;
		linknode *q;
		int k;
		while(p) {
			k  =(p->data/exp)%10;
			q = p->next;
			tong[k]->push(p);
			p=q;
		}//放入桶里 
		que.clear();//清空队列 
		for(int i=0; i<10; i++) {
			if(!tong[i]->empty()) {
				linknode *p = tong[i]->head->next;
				linknode *q;
				while(p) {
					q=p->next;
					que.push(p);
					p=q;
				}
			}
		}//从桶里往外拿 
		for(int i=0; i<10; i++) tong[i]->clear();
		exp*=10;//改变exp 
	}
	que.print();//打印 
}//链式基数排序 
