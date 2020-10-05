#include"exp9.h"
int main(int argc,char *argv[]) {
    int op,x;
    BST *root=NULL;
    BST *balance = NULL;
    do {
    	cout<<"******************************************"<<endl;
        cout<<"0------�˳�------"<<endl;
        cout<<"1------��ʼ������Ԫ��------"<<endl;
        cout<<"2------���ж��ֲ���------"<<endl;
        cout<<"3------��������������------"<<endl;
        cout<<"4------��ѯ������������ֵ ------"<<endl;
        cout<<"5------ɾ��������������ֵ ------"<<endl;
		cout<<"6------����һ��ƽ�������------"<<endl;
        cout<<"******************************************"<<endl;
		cout<<"������������(0~5):";
        cin>>op;     
        switch(op) {
            case 0 :
            	system("cls");
                cout<<"<--�����˳�-->";
                break;
            case 1: 
                init();
                system("pause");
                system("cls");
                break;
            case 2: 
                cout<<"�������ֵ";
                cin>>x;
                brsearch(x);
                system("pause");
                system("cls");
                break;
            case 3:
                int n;
                if(root!=NULL) {
                	destroy(root);
                	root = NULL;
				}
                cout<<"�������ڵ������:";
                cin>>n;
                while(n--){
                    cout<<"����ڵ�ֵ��";
                    cin>>x;
                    add(root,x);
                }
                cout<<"�������";
				system("pause");
                system("cls");
                break;
            case 4:
                cout<<"�����ѯԪ��";
                cin>>x;
                bool flag;
                flag = query(root,x);
                if(flag) cout<<"����";
                else cout<<"������";
                system("pause");
                system("cls");
                break;
            case 5:
                cout<<"����ɾ��Ԫ��";
                cin>>x;
                bool f;
                f = del(root,x);
                if(f) cout<<"����,ɾ���ɹ�";
                else cout<<"������,ɾ��ʧ��";
                system("pause");
                system("cls");
                break;
            case 6: 
            	cout<<"����������26��Ԫ��";
            	for(int i=1; i<=26; i++) {
            		cin>>t[i];
				}
				for(int i=1; i<=26; i++) {
					build(balance,t[i]);	
				}
                cout<<"ƽ������������ɹ�"<<endl;
                system("pause");
                system("cls");
                break;
            default :
            	cout<<"����ѡ�����"<<endl;
            	system("pause");
            	system("cls");
            	break;
        }
    }while(op!=0);
    destroy(root); 
    destroy(balance);//ɾ���� 
    return 0;
}
