#include"seqstack.h"
int main() {
	seqStack s;
	string s1;
	bool flag;
	int op;
	do {
		cout<<"0-�˳�"<<endl;
		cout<<"1-����ת��"<<endl;
		cout<<"2-����ƥ��"<<endl;
		cout<<"ѡ�����:";
		cin>>op;
		switch(op) {
			case 0 : 
			cout<<"<-- �����˳� -->"<<endl;  //ѡ���˳�
			break;
			
			case 1 :
				cout<<"��������Ҫת��Ϊ16���Ƶ�10������"<<endl;
				int x;
				cin>>x;
				change_radix(s,x);
				system("pause");
				system("cls");
				break;
			case 2:
				cout<<"��������������"<<endl; 
				cin>>s1;
				flag = parenthesis_match(s,s1);
				if(flag) cout<<"yes";
				else cout<<"no";
				
				system("pause");
				system("cls");
				break;
				
			default:
					cout<<"������0~2"<<endl;
					system("pause");
					system("cls");
					break; 
		}
	}while(op!=0);
	return 0;
}
