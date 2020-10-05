//二叉树实验 
//此次实验设计的二叉树都是包含一个头结点的二叉树 
#include"Bitree.h"
const int maxn = 100;
int main() {
	btnode *root,*temp;
	elementType x;
	int op,n,flag,pos,len;
	node a[maxn]; 
	root = new btnode;
	root->data = '#';
	root->lchild=NULL;
	root->rchild=NULL;
	do {
		cout<<"0-退出"<<endl;
		cout<<"1-按先序遍历构建二叉树"<<endl;
		cout<<"2-打印出二叉树的三种遍历序"<<endl;
		cout<<"3-按中序次序输出二叉树中各结点的值及其所对应的层次数"<<endl;
		cout<<"4-求二叉树的高度"<<endl;
		cout<<"5-求二叉树的结点数"<<endl;// 
		cout<<"6-求二叉树的叶子结点数"<<endl;
		cout<<"7-求二叉树的度为2的结点数"<<endl;
		cout<<"8-键盘输入一个元素x，求其父节点、兄弟结点、子结点的值，不存在时给出相应提示信息"<<endl;
		cout<<"9-键盘输入一个元素x，求其在树中的层次,不存在时给出信息"<<endl;
		cout<<"10-将按顺序方式存储在数组中的二叉树转换为二叉链表形式"<<endl;
		cout<<"11-交换二叉树中每个结点的左右孩子指针的值"<<endl;
		cout<<"选择操作:";
		cin>>op;
		switch(op) {
			case 0 : 
			cout<<"<-- 程序退出 -->"<<endl;  //选择退出
			break;
			case 1 ://建树 
				destroyBt(root->lchild);
				createSubTree(root,1);
				cout<<"构建完成"<<endl;
				system("pause");
				system("cls");
				break;
			case 2://遍历 
				cout<<"前序:";
				preTraverse(root->lchild);
				cout<<endl;
				cout<<"中序:";
				inTraverse(root->lchild);
				cout<<endl;
				cout<<"后序:";
				postTraverse(root->lchild);	
				system("pause");
				system("cls");
				break;
			case 3://按中序输出 
				Inordervalue(root->lchild,1);	
				system("pause");
				system("cls");
				break;
			case 4://求高度 
				cout<<"二叉树高度"<<btHeight(root->lchild);
				system("pause");
				system("cls");
				break;
			case 5://求结点数 
				n = 0;
				getNodeNumber(root->lchild,n);
				cout<<"结点数："<<n; 
				system("pause");
				system("cls");
				break;
			case 6://求叶结点数 
				n=0;
				getLeafNumber(root->lchild,n);
				cout<<"叶子结点数："<<n; 
				system("pause");
				system("cls");
				break;
			case 7://求度数为2的数 
				n=0;
				get2DegreeNumber(root->lchild,n);
				cout<<"度数为2的结点数为:"<<n;
				system("pause");
				system("cls");
				break;
			case 8://求一个值的父亲 兄弟 儿子 
				cout<<"请输入元素的值：";
				cin>>x; 
				flag=0;
				getInformation(root->lchild,x,flag);
				system("pause");
				system("cls");
				break;
			case 9://求元素所在层数 
				cout<<"请输入元素的值：";
				cin>>x; 
				flag=0;
				search(root->lchild,x,1,flag);
				if(!flag) cout<<"do not exist!"<<endl; 
				system("pause");
				system("cls");
				break;
			case 10://将数组->二叉链表 
				cout<<"请输入元素的个数：";
				cin>>len; 
				initarray(a,len);
				temp = new btnode;
				temp->lchild=NULL;
				temp->rchild=NULL;
				temp->lchild = arraytotree(a,1,pos);
				system("pause");
				system("cls");
				break;
			case 11://翻转二叉树 
				root->lchild = inversetree(root->lchild);
				system("pause");
				system("cls");
				break;								
			default:
				cout<<"请输入0~11"<<endl;
				system("pause");
				system("cls");
				break; 
		}
	}while(op!=0);
	destroyBt(root);
	destroyBt(temp);
	return 0;
}
