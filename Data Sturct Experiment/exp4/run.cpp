//������ʵ�� 
//�˴�ʵ����ƵĶ��������ǰ���һ��ͷ���Ķ����� 
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
		cout<<"0-�˳�"<<endl;
		cout<<"1-�������������������"<<endl;
		cout<<"2-��ӡ�������������ֱ�����"<<endl;
		cout<<"3-�������������������и�����ֵ��������Ӧ�Ĳ����"<<endl;
		cout<<"4-��������ĸ߶�"<<endl;
		cout<<"5-��������Ľ����"<<endl;// 
		cout<<"6-���������Ҷ�ӽ����"<<endl;
		cout<<"7-��������Ķ�Ϊ2�Ľ����"<<endl;
		cout<<"8-��������һ��Ԫ��x�����丸�ڵ㡢�ֵܽ�㡢�ӽ���ֵ��������ʱ������Ӧ��ʾ��Ϣ"<<endl;
		cout<<"9-��������һ��Ԫ��x�����������еĲ��,������ʱ������Ϣ"<<endl;
		cout<<"10-����˳��ʽ�洢�������еĶ�����ת��Ϊ����������ʽ"<<endl;
		cout<<"11-������������ÿ���������Һ���ָ���ֵ"<<endl;
		cout<<"ѡ�����:";
		cin>>op;
		switch(op) {
			case 0 : 
			cout<<"<-- �����˳� -->"<<endl;  //ѡ���˳�
			break;
			case 1 ://���� 
				destroyBt(root->lchild);
				createSubTree(root,1);
				cout<<"�������"<<endl;
				system("pause");
				system("cls");
				break;
			case 2://���� 
				cout<<"ǰ��:";
				preTraverse(root->lchild);
				cout<<endl;
				cout<<"����:";
				inTraverse(root->lchild);
				cout<<endl;
				cout<<"����:";
				postTraverse(root->lchild);	
				system("pause");
				system("cls");
				break;
			case 3://��������� 
				Inordervalue(root->lchild,1);	
				system("pause");
				system("cls");
				break;
			case 4://��߶� 
				cout<<"�������߶�"<<btHeight(root->lchild);
				system("pause");
				system("cls");
				break;
			case 5://������ 
				n = 0;
				getNodeNumber(root->lchild,n);
				cout<<"�������"<<n; 
				system("pause");
				system("cls");
				break;
			case 6://��Ҷ����� 
				n=0;
				getLeafNumber(root->lchild,n);
				cout<<"Ҷ�ӽ������"<<n; 
				system("pause");
				system("cls");
				break;
			case 7://�����Ϊ2���� 
				n=0;
				get2DegreeNumber(root->lchild,n);
				cout<<"����Ϊ2�Ľ����Ϊ:"<<n;
				system("pause");
				system("cls");
				break;
			case 8://��һ��ֵ�ĸ��� �ֵ� ���� 
				cout<<"������Ԫ�ص�ֵ��";
				cin>>x; 
				flag=0;
				getInformation(root->lchild,x,flag);
				system("pause");
				system("cls");
				break;
			case 9://��Ԫ�����ڲ��� 
				cout<<"������Ԫ�ص�ֵ��";
				cin>>x; 
				flag=0;
				search(root->lchild,x,1,flag);
				if(!flag) cout<<"do not exist!"<<endl; 
				system("pause");
				system("cls");
				break;
			case 10://������->�������� 
				cout<<"������Ԫ�صĸ�����";
				cin>>len; 
				initarray(a,len);
				temp = new btnode;
				temp->lchild=NULL;
				temp->rchild=NULL;
				temp->lchild = arraytotree(a,1,pos);
				system("pause");
				system("cls");
				break;
			case 11://��ת������ 
				root->lchild = inversetree(root->lchild);
				system("pause");
				system("cls");
				break;								
			default:
				cout<<"������0~11"<<endl;
				system("pause");
				system("cls");
				break; 
		}
	}while(op!=0);
	destroyBt(root);
	destroyBt(temp);
	return 0;
}
