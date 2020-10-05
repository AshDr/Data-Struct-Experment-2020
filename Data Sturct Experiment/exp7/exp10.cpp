#include"exp.h"
int main() {
	//freopen("data.in","r",stdin);
	int n,maxx;
	int t,op,cnt;
	Myqueue q;
	do {
		cout<<"---------0.退出程序--------------"<<endl;
		cout<<"---------1.快速排序--------------"<<endl;
		cout<<"---------2.按对3的余数将序列排序--------------"<<endl;
		cout<<"---------3.希尔排序--------------"<<endl;
		cout<<"---------4.锦标赛排序--------------"<<endl;
		cout<<"---------5.堆排序--------------"<<endl;
		cout<<"---------6.链式基数排序--------------"<<endl;
		cout<<"input:";
		cin>>op;
		switch(op) {
			case 0:
				cout<<"<--程序退出-->"<<endl;
				break;
			case 1:
				cout<<"请输入数字个数:";
				cin>>n;
				cnt = 0;
				cout<<"请依次输入数字:"<<endl;
				for(int i=1; i<=n; i++) cin>>a[i];
				quick_sort(1,n,cnt);
				for(int i=1; i<=n; i++) cout<<a[i]<<" ";
				cout<<endl<<"交换次数:"<<cnt;
				system("pause");
				system("cls");//进行快排
				break;
			case 2:
				cout<<"请输入数字个数:";
				cin>>n;
				cout<<"请依次输入数字:"<<endl;
				for(int i=1; i<=n; i++) cin>>a[i];
				fun2(n);
				for(int i=1; i<=n; i++) cout<<a[i]<<" ";//按对3的余数分割数组
				system("pause");
				system("cls");
				break;
			case 3:
				cout<<"请输入数字个数:";
				cin>>n;
				cout<<"请依次输入数字:"<<endl;
				for(int i=1; i<=n; i++) cin>>a[i];
				shell_sort(n);//希尔排序
				for(int i=1; i<=n; i++) cout<<a[i]<<" ";
				system("pause");
				system("cls");
				break;
			case 4:
				cout<<"请输入数字个数:";
				cin>>n;
				cout<<"请依次输入数字:"<<endl;
				for(int i=1; i<=n; i++) cin>>a[i];
				tournament_sort(n);//锦标赛排序
				for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
				system("pause");
				system("cls");
				break;
			case 5:
				cout<<"请输入数字个数:";
				cin>>n;
				cout<<"请依次输入数字:"<<endl;
				for(int i=1; i<=n; i++) cin>>a[i];
				heap_sort(n);//堆排序
				for(int i=1; i<=n; i++) cout<<a[i]<<" ";
				system("pause");
				system("cls");
				break;
			case 6:
				cout<<"请输入数字个数:";
				cin>>n;
				maxx = 0;
				cout<<"请依次输入数字:"<<endl;
				for(int i=1; i<=n; i++) {
					cin>>t;
					q.push(t);
					maxx=max(t,maxx);
				}
				radix_sort(q,maxx);//链式基数排序
				system("pause");
				system("cls");
				break;
			default :
				cout<<"请输入0~6"<<endl;
				system("pause");
				system("cls");
		}

	} while(op);
	//fclose(stdin);
	return 0;
}
