#include<iostream>
#include<cstdio>
#include<cstdlib>
typedef char elementType;
typedef struct btnode {
	elementType data;
	struct btnode *lchild,*rchild,*parent;

} btnode,*Bitree;
typedef struct node {
	elementType data;
	int lchild,rchild;
}node;
using namespace std;
//键盘交互递归创建二叉树子树函数
void createSubTree(btnode *&p, int k) {
	//k=1--左子树；k=2--右子树
	btnode *s;
	elementType x;
	int k1,k2;
	cout<<"请输入结点元素数值并对左右孩子标注：";
	cin>>x>>k1>>k2;
	s=new btnode;
	s->data=x;
	s->lchild=NULL;
	s->rchild=NULL;
	s->parent=NULL;
	s->parent=p;
	if(k==1) {
		cout<<"当前结点为"<<p->data<<"的左孩子"<<endl;
		p->lchild=s;     //s接到p的左孩子
	}
	if(k==2) {
		cout<<"当前结点为"<<p->data<<"的右孩子"<<endl;
		p->rchild=s;     //s接为p的右孩子
	}
	if(k1) createSubTree(s,1);  //递归创建s的左子树
	if(k2) createSubTree(s,2);  //递归创建s的右子树
}
//递归先序遍历
void preTraverse(btnode *T) {
	if(T) {
		cout<<T->data<<" ";         //访问根结点。打印当前结点元素值，替代visit(T)函数
		preTraverse(T->lchild);     //先序遍历左子树
		preTraverse(T->rchild);     //先序遍历右子树
	}
}
//中序遍历--递归
void inTraverse(btnode *T) {
	if(T) {
		inTraverse(T->lchild);      //中序遍历左子树
		cout<<T->data<<" ";         //访问根结点。打印当前结点元素值，替代visit(T)函数
		inTraverse(T->rchild);      //中序遍历右子树
	}
}
//后序遍历--递归
void postTraverse(btnode *T) {
	if(T) {
		postTraverse(T->lchild);      //后序遍历左子树
		postTraverse(T->rchild);      //后序遍历右子树
		cout<<T->data<<" ";         //访问根结点。打印当前结点元素值，替代visit(T)函数
	}
}
//按中序遍历输出值和层数 
void Inordervalue(btnode *T, int level) {
	if(T==NULL) {
		cout<<"二叉树未建立"<<endl;
		return ;
	}
	if(T->lchild!=NULL) Inordervalue(T->lchild,level+1);
	cout<<"Value: "<<T->data<<" "<<"Level: "<<level<<endl;
	if(T->rchild!=NULL) Inordervalue(T->rchild,level+1);
	return ;
}
//求树上总结点数
void getNodeNumber(btnode *T, int &num) {
	//改造先序遍历计数结点数
	if(T) {
		num++;    //计数根结点
		getNodeNumber(T->lchild,num);    //累计左子树结点
		getNodeNumber(T->rchild,num);    //累计右子树结点
	}
}
//求叶子结点数
void getLeafNumber(btnode *T,int &num) {
	if(T) {
		if(T->lchild==NULL && T->rchild==NULL)
			num++;
		getLeafNumber(T->lchild,num);
		getLeafNumber(T->rchild,num);
	}
}
//求2度结点数
void get2DegreeNumber(btnode *T,int &num) {
	if(T) {
		if(T->lchild && T->rchild)
			num++;
		get2DegreeNumber(T->lchild,num);
		get2DegreeNumber(T->rchild,num);
	}
}
//求二叉树高度（深度）
int btHeight(btnode *T) {
	int lh,rh;
	if(!T)
		return 0;
	else {
		lh=btHeight(T->lchild);   //求左子树高度
		rh=btHeight(T->rchild);   //求右子树高度
		return (lh>rh?lh:rh)+1;  //简略写法
	}
}
//查询父亲 兄弟 儿子 
void getInformation(btnode *T,elementType x,int &flag) {
	if(T==NULL) return ;
	if(flag) return ;
	if(T->data==x) {
		flag=1;
		if(T->parent!=NULL) {
			cout<<"Parent: "<<T->parent->data<<endl;
		} else cout<<"Parent do not exist"<<endl;

		if(T->lchild!=NULL) {
			cout<<"lchild: "<<T->lchild->data<<endl;
		} else cout<<"lchild do not exist"<<endl;
		
		if(T->rchild!=NULL) {
			cout<<"rchild: "<<T->rchild->data<<endl;
		} else cout<<"rchild do not exist"<<endl;

		if(T->parent->lchild!=NULL && T->data==T->parent->lchild->data) {//特别注意这里要使用&运算符的短路性质 
			if(T->parent->rchild!=NULL) {
				cout<<"RightBrother: "<<T->parent->rchild->data<<endl;
			} else cout<<"RightBrother do not exist"<<endl;
		}
		if(T->parent->rchild!=NULL&&T->data==T->parent->rchild->data) {
			if(T->parent->lchild!=NULL) {
				cout<<"LeftBrother: "<<T->parent->lchild->data<<endl;
			} else cout<<"LeftBrother do not exist"<<endl;
		}
	} 
	else {
		getInformation(T->lchild,x,flag);
		getInformation(T->rchild,x,flag);
	}
	return ;
}
//查询信息 
void search(btnode *T,elementType x, int level,int &flag) {
	if(T==NULL) return ;
	if(flag) return;
	if(T->data==x) {
		flag = 1;
		cout<<level;
		return ;
	}
	search(T->lchild,x,level+1,flag);
	search(T->rchild,x,level+1,flag);
	return ;
}
//数组转化为二叉树 
btnode* arraytotree(node a[],int i,int &pos) {//下标从1开始 
	btnode *s=NULL;
	s=new btnode;
	s->data=a[i].data;
	s->lchild=NULL;
	s->rchild=NULL;
	pos = i;
	if(a[i].lchild){
		s->lchild = arraytotree(a,i+1,pos);	
	}
	if(a[i].rchild){
		s->rchild = arraytotree(a,pos+1,pos);
	}
	cout<<"done"<<endl;
	return s;
}
//翻转二叉树 
btnode* inversetree(btnode *&t) {
	if(t==NULL) {
		return NULL;
	}
	btnode *tl = inversetree(t->rchild);
	btnode *tr = inversetree(t->lchild);
	t->lchild = tl;
	t->rchild = tr;
	return t;
}
//初始化数组
void initarray(node a[],int len) {
	cout<<"请按照先序遍历输入结点数"<<endl;
	for(int i=1; i<=len; i++) {
		cout<<"结点值:";
		cin>>a[i].data;
		cout<<"左儿子是否存在"<<endl;
		cin>>a[i].lchild;
		cout<<"右儿子是否存在"<<endl;
		cin>>a[i].rchild;
	}
	return ;
}
//销毁二叉树
void destroyBt(btnode *&T) {
	if(T) {
		destroyBt(T->lchild);
		destroyBt(T->rchild);
		delete T;
	}
	T=NULL;
}
