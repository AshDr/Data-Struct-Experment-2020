#include"linkedqueue.h"
//����ͷ�ڵ�������� 
int main() {
	linkedQueue q;
	int op;
	bool flag;
	do {
		cout<<"0-�˳�"<<endl;
		cout<<"1-��ʼ������"<<endl;
		cout<<"2-�ж϶ӿ�"<<endl;
		cout<<"3-�ж϶���"<<endl;
		cout<<"4-������,����Ԫ�ز�������������Ҫ��ͷ�ļ��и���Ԫ������"<<endl;// 
		cout<<"5-����"<<endl;
		cout<<"6-ȡ����ͷԪ��"<<endl;
		cout<<"7-��ǰ������Ԫ�ظ���"<<endl;
		cout<<"8-ʵ�ֺ���"<<endl;
		cout<<"ѡ�����:";
		cin>>op;
		switch(op) {
			case 0 : 
			cout<<"<-- �����˳� -->"<<endl;  //ѡ���˳�
			break;
			
			case 1 :
				initialQueue(q);
				cout<<"��ʼ�����"<<endl;
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
				if(flag) cout<<"�����ѳ���";
				else cout<<"����Ϊ��"; 
				system("pause");
				system("cls");
				break;
			case 6:
				int temp;
				flag = getFront(q,temp);
				if(flag) cout<<temp;
				else cout<<"����Ϊ��"; 
				system("pause");
				system("cls");
				break;
			case 7:
				cout<<"����Ϊ��"<<getlen(q);
				system("pause");
				system("cls");
				break;
			case 8:
				fun(q);
				system("pause");
				system("cls");
				break;		
			default:
				cout<<"������0~8"<<endl;
				system("pause");
				system("cls");
				break; 
		}
	}while(op!=0);
	destroyQueue(q);
	return 0;
}
