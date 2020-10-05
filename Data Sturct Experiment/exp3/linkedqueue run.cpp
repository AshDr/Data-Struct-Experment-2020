#include"linkedqueue.h"
//不带头节点的链队列 
int main() {
	linkedQueue q;
	int op;
	bool flag;
	do {
		cout<<"0-退出"<<endl;
		cout<<"1-初始化队列"<<endl;
		cout<<"2-判断队空"<<endl;
		cout<<"3-判断队满"<<endl;
		cout<<"4-入队如果,输入元素不是整数，则需要在头文件中更改元素类型"<<endl;// 
		cout<<"5-出队"<<endl;
		cout<<"6-取出队头元素"<<endl;
		cout<<"7-求当前队列中元素个数"<<endl;
		cout<<"8-实现函数"<<endl;
		cout<<"选择操作:";
		cin>>op;
		switch(op) {
			case 0 : 
			cout<<"<-- 程序退出 -->"<<endl;  //选择退出
			break;
			
			case 1 :
				initialQueue(q);
				cout<<"初始化完成"<<endl;
				system("pause");
				system("cls");
				break;
			case 2:
				flag = queueEmpty(q);
				if(flag) cout<<"yes";
				else cout<<"no";	
				system("pause");
				system("cls");
				break;
			case 3:
				flag = 0;
				if(flag) cout<<"yes";
				else cout<<"no";	
				system("pause");
				system("cls");
				break;
			case 4:
				createLinkedQueue(q);
				system("pause");
				system("cls");
				break;
			case 5:
				flag = outQueue(q);
				if(flag) cout<<"队首已出队";
				else cout<<"队列为空"; 
				system("pause");
				system("cls");
				break;
			case 6:
				int temp;
				flag = getFront(q,temp);
				if(flag) cout<<temp;
				else cout<<"队列为空"; 
				system("pause");
				system("cls");
				break;
			case 7:
				cout<<"长度为："<<getlen(q);
				system("pause");
				system("cls");
				break;
			case 8:
				fun(q);
				system("pause");
				system("cls");
				break;		
			default:
				cout<<"请输入0~8"<<endl;
				system("pause");
				system("cls");
				break; 
		}
	}while(op!=0);
	destroyQueue(q);
	return 0;
}
