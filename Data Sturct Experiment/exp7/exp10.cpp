#include"exp.h"
int main() {
	//freopen("data.in","r",stdin);
	int n,maxx;
	int t,op,cnt;
	Myqueue q;
	do {
		cout<<"---------0.�˳�����--------------"<<endl;
		cout<<"---------1.��������--------------"<<endl;
		cout<<"---------2.����3����������������--------------"<<endl;
		cout<<"---------3.ϣ������--------------"<<endl;
		cout<<"---------4.����������--------------"<<endl;
		cout<<"---------5.������--------------"<<endl;
		cout<<"---------6.��ʽ��������--------------"<<endl;
		cout<<"input:";
		cin>>op;
		switch(op) {
			case 0:
				cout<<"<--�����˳�-->"<<endl;
				break;
			case 1:
				cout<<"���������ָ���:";
				cin>>n;
				cnt = 0;
				cout<<"��������������:"<<endl;
				for(int i=1; i<=n; i++) cin>>a[i];
				quick_sort(1,n,cnt);
				for(int i=1; i<=n; i++) cout<<a[i]<<" ";
				cout<<endl<<"��������:"<<cnt;
				system("pause");
				system("cls");//���п���
				break;
			case 2:
				cout<<"���������ָ���:";
				cin>>n;
				cout<<"��������������:"<<endl;
				for(int i=1; i<=n; i++) cin>>a[i];
				fun2(n);
				for(int i=1; i<=n; i++) cout<<a[i]<<" ";//����3�������ָ�����
				system("pause");
				system("cls");
				break;
			case 3:
				cout<<"���������ָ���:";
				cin>>n;
				cout<<"��������������:"<<endl;
				for(int i=1; i<=n; i++) cin>>a[i];
				shell_sort(n);//ϣ������
				for(int i=1; i<=n; i++) cout<<a[i]<<" ";
				system("pause");
				system("cls");
				break;
			case 4:
				cout<<"���������ָ���:";
				cin>>n;
				cout<<"��������������:"<<endl;
				for(int i=1; i<=n; i++) cin>>a[i];
				tournament_sort(n);//����������
				for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
				system("pause");
				system("cls");
				break;
			case 5:
				cout<<"���������ָ���:";
				cin>>n;
				cout<<"��������������:"<<endl;
				for(int i=1; i<=n; i++) cin>>a[i];
				heap_sort(n);//������
				for(int i=1; i<=n; i++) cout<<a[i]<<" ";
				system("pause");
				system("cls");
				break;
			case 6:
				cout<<"���������ָ���:";
				cin>>n;
				maxx = 0;
				cout<<"��������������:"<<endl;
				for(int i=1; i<=n; i++) {
					cin>>t;
					q.push(t);
					maxx=max(t,maxx);
				}
				radix_sort(q,maxx);//��ʽ��������
				system("pause");
				system("cls");
				break;
			default :
				cout<<"������0~6"<<endl;
				system("pause");
				system("cls");
		}

	} while(op);
	//fclose(stdin);
	return 0;
}
