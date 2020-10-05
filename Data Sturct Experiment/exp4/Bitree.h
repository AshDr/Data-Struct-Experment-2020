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
//���̽����ݹ鴴����������������
void createSubTree(btnode *&p, int k) {
	//k=1--��������k=2--������
	btnode *s;
	elementType x;
	int k1,k2;
	cout<<"��������Ԫ����ֵ�������Һ��ӱ�ע��";
	cin>>x>>k1>>k2;
	s=new btnode;
	s->data=x;
	s->lchild=NULL;
	s->rchild=NULL;
	s->parent=NULL;
	s->parent=p;
	if(k==1) {
		cout<<"��ǰ���Ϊ"<<p->data<<"������"<<endl;
		p->lchild=s;     //s�ӵ�p������
	}
	if(k==2) {
		cout<<"��ǰ���Ϊ"<<p->data<<"���Һ���"<<endl;
		p->rchild=s;     //s��Ϊp���Һ���
	}
	if(k1) createSubTree(s,1);  //�ݹ鴴��s��������
	if(k2) createSubTree(s,2);  //�ݹ鴴��s��������
}
//�ݹ��������
void preTraverse(btnode *T) {
	if(T) {
		cout<<T->data<<" ";         //���ʸ���㡣��ӡ��ǰ���Ԫ��ֵ�����visit(T)����
		preTraverse(T->lchild);     //�������������
		preTraverse(T->rchild);     //�������������
	}
}
//�������--�ݹ�
void inTraverse(btnode *T) {
	if(T) {
		inTraverse(T->lchild);      //�������������
		cout<<T->data<<" ";         //���ʸ���㡣��ӡ��ǰ���Ԫ��ֵ�����visit(T)����
		inTraverse(T->rchild);      //�������������
	}
}
//�������--�ݹ�
void postTraverse(btnode *T) {
	if(T) {
		postTraverse(T->lchild);      //�������������
		postTraverse(T->rchild);      //�������������
		cout<<T->data<<" ";         //���ʸ���㡣��ӡ��ǰ���Ԫ��ֵ�����visit(T)����
	}
}
//������������ֵ�Ͳ��� 
void Inordervalue(btnode *T, int level) {
	if(T==NULL) {
		cout<<"������δ����"<<endl;
		return ;
	}
	if(T->lchild!=NULL) Inordervalue(T->lchild,level+1);
	cout<<"Value: "<<T->data<<" "<<"Level: "<<level<<endl;
	if(T->rchild!=NULL) Inordervalue(T->rchild,level+1);
	return ;
}
//�������ܽ����
void getNodeNumber(btnode *T, int &num) {
	//��������������������
	if(T) {
		num++;    //���������
		getNodeNumber(T->lchild,num);    //�ۼ����������
		getNodeNumber(T->rchild,num);    //�ۼ����������
	}
}
//��Ҷ�ӽ����
void getLeafNumber(btnode *T,int &num) {
	if(T) {
		if(T->lchild==NULL && T->rchild==NULL)
			num++;
		getLeafNumber(T->lchild,num);
		getLeafNumber(T->rchild,num);
	}
}
//��2�Ƚ����
void get2DegreeNumber(btnode *T,int &num) {
	if(T) {
		if(T->lchild && T->rchild)
			num++;
		get2DegreeNumber(T->lchild,num);
		get2DegreeNumber(T->rchild,num);
	}
}
//��������߶ȣ���ȣ�
int btHeight(btnode *T) {
	int lh,rh;
	if(!T)
		return 0;
	else {
		lh=btHeight(T->lchild);   //���������߶�
		rh=btHeight(T->rchild);   //���������߶�
		return (lh>rh?lh:rh)+1;  //����д��
	}
}
//��ѯ���� �ֵ� ���� 
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

		if(T->parent->lchild!=NULL && T->data==T->parent->lchild->data) {//�ر�ע������Ҫʹ��&������Ķ�·���� 
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
//��ѯ��Ϣ 
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
//����ת��Ϊ������ 
btnode* arraytotree(node a[],int i,int &pos) {//�±��1��ʼ 
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
//��ת������ 
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
//��ʼ������
void initarray(node a[],int len) {
	cout<<"�밴�����������������"<<endl;
	for(int i=1; i<=len; i++) {
		cout<<"���ֵ:";
		cin>>a[i].data;
		cout<<"������Ƿ����"<<endl;
		cin>>a[i].lchild;
		cout<<"�Ҷ����Ƿ����"<<endl;
		cin>>a[i].rchild;
	}
	return ;
}
//���ٶ�����
void destroyBt(btnode *&T) {
	if(T) {
		destroyBt(T->lchild);
		destroyBt(T->rchild);
		delete T;
	}
	T=NULL;
}
