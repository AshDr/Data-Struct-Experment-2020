#include"seqlist.h"
using namespace std;

int main(int argc, char* argv[])
{
	seqList A;
	seqList P;
	seqList M;
	int i;
	elementType x;
	A.listLen=0;
	
	int nChoice=1; //操作选择
	do
	{
		//显示主菜单
		cout<<"**********顺序表测试程序***********"<<endl;
		cout<<"* 0-退出                          *"<<endl;
		cout<<"* 1-交互创建顺序表                *"<<endl;
		cout<<"* 2-求顺序表中第i个元素           *"<<endl;
		cout<<"* 3-在第i个元素位置插入值为x的元素*"<<endl;
		cout<<"* 4-删除顺序表中第i个元素结点     *"<<endl;
		cout<<"*---------------------------------*"<<endl;
		cout<<"* 5-在一个递增有序的顺序表L中插入一个值为x的元素，并保持其递增有序特性*"<<endl;
		cout<<"* 6-按奇数、偶数拆分为2个新表。然后将原表和新表元素同时输出到屏幕上*"<<endl;
		cout<<"* 7-求两个递增有序顺序表L1和L2中的公共元素，放入新的顺序表L3*"<<endl;
		cout<<"* 8-删除递增有序顺序表中的重复元素，并统计移动元素次数*"<<endl;
		cout<<"* 9-输出现存表中元素*"<<endl; 
		cout<<"***********************************"<<endl;

		cout<<"请输入数字选择操作：";
		cin>>nChoice;

		switch(nChoice)
		{
		case 0:  //退出
			cout<<"当前选择操作：退出。"<<endl;
			cout<<"<-- 程序退出 -->"<<endl;  //选择退出
			break;

		case 1:
			system("cls");
			listbuild(&A);//新建一个表 
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			cout<<"Input i:";
			cin>>i;
			if(getElement(&A,i,&x))
				cout<<"第"<<i<<"个元素为："<<x<<endl;
			else cout<<"获取失败"; 
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			cout<<"Input i、x:";
			cin>>i>>x;
			if(listInsert(&A,x,i)==2) cout<<"插入成功"<<endl;
			else cout<<"插入失败";
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			cout<<"Input i:";
			cin>>i;
			if(listDelete(&A,i)==2) cout<<"删除成功"<<endl;
			else cout<<"删除失败";
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			cout<<"Input x:";
			cin>>x;
			listbuild(&A);//新建一个表 
			IncreaseingListInsert(&A,x);
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			listbuild(&A);//新建一个表
			ListSplit(&A,&P,&M);
			cout<<"Done";
			system("pause");
			system("cls");
			break;
		case 7:
			system("cls");
			listbuild(&A);
			listbuild(&P);//为了实现下面的函数，新建两个表 
			Intersection(&A,&P,&M);
			cout<<"M表已经成为交集"<<endl;
			system("pause");
			system("cls");
			break;
		case 8:
			system("cls");
			listbuild(&A);
			cout<<"移动次数为"<<Delete7(&A)<<endl;
			system("pause");
			system("cls");
			break;
		case 9:
			system("cls");
			printList(&A);
			system("pause");
			system("cls");
			break;
		default:
			cout<<"功能选择错误，请在0到10之间选择，==>"<<endl;
			break;
        }
	
	}while(nChoice!=0);
	
	return 0;
}
