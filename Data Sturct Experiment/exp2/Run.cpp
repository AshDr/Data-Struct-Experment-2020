//带头节点单链表测试程序
#include"linkedList.h"
using namespace std;
int main()
{
	node *L=NULL, *P=NULL;
	//initialList(L);

	int nChoice=-1; //操作选择
	do
	{
		//显示主菜单
		cout<<"**********单链表测试程序***********"<<endl;
		cout<<"* 0-退出                          *"<<endl;
		cout<<"* 1-交互尾插法创建链表            *"<<endl;
		cout<<"* 2-交互头插法创建链表            *"<<endl;
		cout<<"* 3-销毁链表                      *"<<endl;
		cout<<"* 4-求链表长度                    *"<<endl;
		cout<<"* 5-求第i个元素                   *"<<endl;
		cout<<"*---------------------------------*"<<endl;
		cout<<"* 6-在第i个结点前插入x            *"<<endl;
		cout<<"* 7-查找值为x的结点,成功返回结点指针*"<<endl;
		cout<<"* 8-删除单链表第i个元素结点       *"<<endl;
		cout<<"* 9-在一个递增有序链表中插入x，保持其有序*"<<endl;
		cout<<"* 10-将表L中元素按积偶分开并输出  *"<<endl;
		cout<<"* 11-求两个表的公共元素           *"<<endl;
		cout<<"* 12-删除递增有序单链表中的重复元素*"<<endl;
		cout<<"* 13-对两个递增有序单链表进行就地合并*"<<endl;
		cout<<"* 14-输出链表                      *"<<endl;
		cout<<"***********************************"<<endl;

		cout<<"请输入数字选择操作：";
		cin>>nChoice;

		switch(nChoice)
		{
		case 0:  //退出
			cout<<"当前选择操作：退出。"<<endl;
			cout<<"<-- 程序退出 -->"<<endl;  //选择退出
			break;

		case 1:  //交互尾插创建链表
			system("cls");  //清除屏幕
			if(L!=NULL)
				DestroyList(L);    //先销毁原链表			

			CreateListRear(L);       
			PrintList(L);
			system("pause");
			break;
		case 2:  //交互头插创建链表
			system("cls");  //清除屏幕

			if(L!=NULL)
			DestroyList(L);    //先销毁原链表
			CreateListHead(L);
			PrintList(L);
			system("pause");
			break;
			
		case 3:  //销毁链表 
			system("cls");  //清除屏幕
			DestroyList(L);
			break;		
		case 4:  //求表长 
			system("cls");  //清除屏幕
			if(L==NULL)
			{
				cout<<"表L未初始化。请先初始化，再输入元素。"<<endl;
				break;
			}			
			cout<<"表长："<<listLen(L); 
			system("pause");
			break;			
		
		case 5:  //求元素值 
			system("cls");  //清除屏幕
			if(L==NULL)
			{
				cout<<"表L不存在。"<<endl;
				break;
			}
			ElementType temp;
			bool flag1;
			flag1 = Pos_Value(L,temp);
			if(flag1==false) cout<<"error";
			else cout<<"Value:"<<temp;
			system("pause");	
			break;		
		case 6://插入元素 
			system("cls");  //清除屏幕
			if(L==NULL)
			{
				cout<<"表L不存在。"<<endl;
				break;
			}
			Insert(L);
			system("pause");
			break;			
		case 7:  //查询
			system("cls");  //清除屏幕
			if(L==NULL)
			{
				cout<<"表L不存在。"<<endl;
				break;
			}
			node *t;
			bool flag;
			flag =  Search(L,t);
			if(flag==false) cout<<"error";
			else cout<<"done";
			system("pause");
			break;
		case 8://删除元素 
			system("cls");  //清除屏幕
			if(L==NULL)
			{
				cout<<"表L不存在。"<<endl;
				break;
			}
			bool flag2;
			flag2 =  Delete(L);
			if(flag2==false) cout<<"error";
			else cout<<"done";
			system("pause");
			break;
		case 9:  //递增表插入
            system("cls");  //清除屏幕
			DestroyList(L);
			CreateListRear(L);
			InceasingInsert(L);
			system("pause");
			break;
		case 10:  //按积偶分开 
			system("cls");  //清除屏幕
			DestroyList(L);
			CreateListRear(L);
			Divide(L);
			system("pause");
			break;
		case 11:  //求相同元素 
			system("cls");  //清除屏幕
			cout<<"Bulid List";
			DestroyList(L);
			DestroyList(P);
			CreateListRear(L);
			CreateListRear(P);
			GerIntersection(L,P);
			system("pause");
			break;
		case 12:  //删除重复元素 
			system("cls");  //清除屏幕
			DestroyList(L);
			CreateListRear(L);
			DeleteSameEle(L);
			system("pause");
			break;
		case 13:  //合并 
			system("cls");  //清除屏幕
			DestroyList(L);
			DestroyList(P);
			CreateListRear(L);
			CreateListRear(P);
			Merge(L,P);
			system("pause");
			break;
		case 14://打印链表 
			PrintList(L);
			system("pause");
			break;
		default:
			cout<<"功能选择错误，请在0到14之间选择，==>"<<endl;
			system("pause");
			break;
        }
	
	}while(nChoice!=0);
	DestroyList(L);
	return 0;
}
