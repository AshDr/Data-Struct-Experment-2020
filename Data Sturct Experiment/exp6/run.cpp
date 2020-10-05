#include"exp9.h"
int main(int argc,char *argv[]) {
    int op,x;
    BST *root=NULL;
    BST *balance = NULL;
    do {
    	cout<<"******************************************"<<endl;
        cout<<"0------退出------"<<endl;
        cout<<"1------初始化数组元素------"<<endl;
        cout<<"2------进行二分查找------"<<endl;
        cout<<"3------构建二叉排序树------"<<endl;
        cout<<"4------查询二叉排序树的值 ------"<<endl;
        cout<<"5------删除二叉排序树的值 ------"<<endl;
		cout<<"6------构建一棵平衡二叉树------"<<endl;
        cout<<"******************************************"<<endl;
		cout<<"请输入操作编号(0~5):";
        cin>>op;     
        switch(op) {
            case 0 :
            	system("cls");
                cout<<"<--程序退出-->";
                break;
            case 1: 
                init();
                system("pause");
                system("cls");
                break;
            case 2: 
                cout<<"输入查找值";
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
                cout<<"输入插入节点的数量:";
                cin>>n;
                while(n--){
                    cout<<"输入节点值：";
                    cin>>x;
                    add(root,x);
                }
                cout<<"插入完成";
				system("pause");
                system("cls");
                break;
            case 4:
                cout<<"输入查询元素";
                cin>>x;
                bool flag;
                flag = query(root,x);
                if(flag) cout<<"存在";
                else cout<<"不存在";
                system("pause");
                system("cls");
                break;
            case 5:
                cout<<"输入删除元素";
                cin>>x;
                bool f;
                f = del(root,x);
                if(f) cout<<"存在,删除成功";
                else cout<<"不存在,删除失败";
                system("pause");
                system("cls");
                break;
            case 6: 
            	cout<<"请依次输入26个元素";
            	for(int i=1; i<=26; i++) {
            		cin>>t[i];
				}
				for(int i=1; i<=26; i++) {
					build(balance,t[i]);	
				}
                cout<<"平衡二叉树构建成功"<<endl;
                system("pause");
                system("cls");
                break;
            default :
            	cout<<"功能选择错误"<<endl;
            	system("pause");
            	system("cls");
            	break;
        }
    }while(op!=0);
    destroy(root); 
    destroy(balance);//删除树 
    return 0;
}
