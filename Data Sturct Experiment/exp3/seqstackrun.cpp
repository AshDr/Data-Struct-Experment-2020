#include"seqstack.h"
int main() {
	seqStack s;
	string s1;
	bool flag;
	int op;
	do {
		cout<<"0-退出"<<endl;
		cout<<"1-进制转换"<<endl;
		cout<<"2-括号匹配"<<endl;
		cout<<"选择操作:";
		cin>>op;
		switch(op) {
			case 0 : 
			cout<<"<-- 程序退出 -->"<<endl;  //选择退出
			break;
			
			case 1 :
				cout<<"请输入需要转化为16进制的10进制数"<<endl;
				int x;
				cin>>x;
				change_radix(s,x);
				system("pause");
				system("cls");
				break;
			case 2:
				cout<<"请输入括号序列"<<endl; 
				cin>>s1;
				flag = parenthesis_match(s,s1);
				if(flag) cout<<"yes";
				else cout<<"no";
				
				system("pause");
				system("cls");
				break;
				
			default:
					cout<<"请输入0~2"<<endl;
					system("pause");
					system("cls");
					break; 
		}
	}while(op!=0);
	return 0;
}
