#include"Forest.h"
using namespace std;
int main(int argc, char* argv[])
{
	pTree T1;    //双亲表示的树（森林） 
	csNode *T;   //孩子兄弟链表表示的树
	int  nR=0;
	int i;
	int nChoice;
	char strFileName[100];
	T1.n=0;
	T=NULL;
	do
	{
		//创建菜单
		cout<<"*** 孩子兄弟链表表示的树（森林）测试程序 ***"<<endl;
		cout<<"*  0--退出                                 *"<<endl;
		cout<<"*  1--文件创建森林                         *"<<endl;	
		cout<<"*  2--销毁树（森林）                       *"<<endl;
		cout<<"*------------------------------------------*"<<endl;
		cout<<"*  3--遍历森林                             *"<<endl;
		cout<<"*  4--求结点总数                           *"<<endl;
		cout<<"*  5--求叶结点总数                         *"<<endl;
		cout<<"*  6--求森林高度                           *"<<endl;
		cout<<"*  7--求森林的度                           *"<<endl;
		cout<<"*  8--先序输出结点及层次                   *"<<endl;
		cout<<"*  9--输出广义表表示的树                   *"<<endl;
		cout<<"*                                          *"<<endl;
		cout<<"********************************************"<<endl;
		cout<<"请选择操作(0-8)：";
		cin>>nChoice;
		switch(nChoice)
		{
		case 0:  //退出程序
			system("cls");  //清除屏幕
			cout<<"<-- 程序退出 -->"<<endl;  //选择退出
			break;
		case 1:
			system("cls");  //清除屏幕
			if(T!=NULL )     //防止重复创建，造成内存泄露
			{
				cout<<"树（森林）已经存在，若需重新创建，请先销毁再创建。"<<endl;
				break;
			}
			char strFileName[100];
			cout<<"请输入树（森林）数据文件名(i.e. tree6.tre)：";
			cin>>strFileName;  //控制台输入数据文件名
			
			if(!CreateTreeFromFile(strFileName,T1))     //以父子结点对为输入数据，创建双亲表示的树T1
			{
				cout<<"树（森林）创建失败。"<<endl;
				break;
			
			}
			createCsTree(T,T1);                         //从双亲表示的树（森林）创建二叉链表表示的树（森林）
			cout<<"<-- 树（森林）创建完成 -->"<<endl; 
			break;
		case 2:  //销毁树（森林）
			system("cls");  //清除屏幕
			if (T!=NULL)
				destroyTree(T);  //销毁二叉树			
			cout<<"<-- 树（森林）已经销毁！-->"<<endl;
			break;
		case 3:  //遍历树（森林）
			system("cls");  //清除屏幕
			
			if(T==NULL)
			{
				cout<<"<--树（森林）为空。-->"<<endl;
				break;
			}
			cout<<"树（森林）遍历结果："<<endl;
			cout<<"先序次序：";
			preOrder(T);   //递归先序遍历
			cout<<endl;
			cout<<"后序次序：";
			postOrder(T);  //递归后序遍历
			cout<<endl;
			cout<<"层次次序：";
			hieOrder(T);
			cout<<endl;
			break;
		case 4:  //求结点数
			system("cls");  //清除屏幕
			nR=nodeNum(T);
			cout<<"树（森林）的结点数："<<nR<<endl;
			break;
		case 5:  //求叶子结点数
			system("cls");  //清除屏幕
			nR=0;
			leafNum(T,nR);
			cout<<"树（森林）的叶子结点数："<<nR<<endl;
			break;			
		case 6:  //求树（森林）高度
			system("cls");  //清除屏幕
			nR=height(T);
			cout<<"树（森林）的高度："<<nR<<endl;
			break;	
		case 7:  //求树（森林）的度
			system("cls");  //清除屏幕
			nR=0;
			width(T,nR);
			cout<<"树（森林）的度："<<nR<<endl;
			break;									
		case 8:  //先序输出结点值及层层 
			system("cls");  //清除屏幕
			if(T==NULL)
			{
				cout<<"<--树（森林）为空。-->"<<endl;
				break;
			}

			cout<<"<--树（森林）先序序列及层次："<<endl;
			outPreOrder(T,1);    //先序输出结点值及层次
			cout<<endl;
			break;
		case 9:  //广义表形式输出先序序列
			system("cls");  //清除屏幕
			if(T==NULL)
			{
				cout<<"<--树（森林）为空。-->"<<endl;
				break;
			}

			cout<<"树（森林）广义表形式输出："<<endl;
			cout<<"(";       //为与最后一个括号配对
			outGList(T);     //广义表形式输出
			cout<<endl;
			break;
		default:
			cout<<"功能选择错误，请在0到9之间选择，==>"<<endl;
			break;
		}
	
	}while(nChoice!=0);  //循环显示菜单，nMenu==0退出

	if (T!=NULL)
	   destroyTree(T);    //销毁树(森林)
	return 0;
}

