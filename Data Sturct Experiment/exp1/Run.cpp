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
	
	int nChoice=1; //����ѡ��
	do
	{
		//��ʾ���˵�
		cout<<"**********˳�����Գ���***********"<<endl;
		cout<<"* 0-�˳�                          *"<<endl;
		cout<<"* 1-��������˳���                *"<<endl;
		cout<<"* 2-��˳����е�i��Ԫ��           *"<<endl;
		cout<<"* 3-�ڵ�i��Ԫ��λ�ò���ֵΪx��Ԫ��*"<<endl;
		cout<<"* 4-ɾ��˳����е�i��Ԫ�ؽ��     *"<<endl;
		cout<<"*---------------------------------*"<<endl;
		cout<<"* 5-��һ�����������˳���L�в���һ��ֵΪx��Ԫ�أ��������������������*"<<endl;
		cout<<"* 6-��������ż�����Ϊ2���±�Ȼ��ԭ����±�Ԫ��ͬʱ�������Ļ��*"<<endl;
		cout<<"* 7-��������������˳���L1��L2�еĹ���Ԫ�أ������µ�˳���L3*"<<endl;
		cout<<"* 8-ɾ����������˳����е��ظ�Ԫ�أ���ͳ���ƶ�Ԫ�ش���*"<<endl;
		cout<<"* 9-����ִ����Ԫ��*"<<endl; 
		cout<<"***********************************"<<endl;

		cout<<"����������ѡ�������";
		cin>>nChoice;

		switch(nChoice)
		{
		case 0:  //�˳�
			cout<<"��ǰѡ��������˳���"<<endl;
			cout<<"<-- �����˳� -->"<<endl;  //ѡ���˳�
			break;

		case 1:
			system("cls");
			listbuild(&A);//�½�һ���� 
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			cout<<"Input i:";
			cin>>i;
			if(getElement(&A,i,&x))
				cout<<"��"<<i<<"��Ԫ��Ϊ��"<<x<<endl;
			else cout<<"��ȡʧ��"; 
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			cout<<"Input i��x:";
			cin>>i>>x;
			if(listInsert(&A,x,i)==2) cout<<"����ɹ�"<<endl;
			else cout<<"����ʧ��";
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			cout<<"Input i:";
			cin>>i;
			if(listDelete(&A,i)==2) cout<<"ɾ���ɹ�"<<endl;
			else cout<<"ɾ��ʧ��";
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			cout<<"Input x:";
			cin>>x;
			listbuild(&A);//�½�һ���� 
			IncreaseingListInsert(&A,x);
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			listbuild(&A);//�½�һ����
			ListSplit(&A,&P,&M);
			cout<<"Done";
			system("pause");
			system("cls");
			break;
		case 7:
			system("cls");
			listbuild(&A);
			listbuild(&P);//Ϊ��ʵ������ĺ������½������� 
			Intersection(&A,&P,&M);
			cout<<"M���Ѿ���Ϊ����"<<endl;
			system("pause");
			system("cls");
			break;
		case 8:
			system("cls");
			listbuild(&A);
			cout<<"�ƶ�����Ϊ"<<Delete7(&A)<<endl;
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
			cout<<"����ѡ���������0��10֮��ѡ��==>"<<endl;
			break;
        }
	
	}while(nChoice!=0);
	
	return 0;
}
