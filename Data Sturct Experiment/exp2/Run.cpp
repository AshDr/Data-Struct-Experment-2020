//��ͷ�ڵ㵥������Գ���
#include"linkedList.h"
using namespace std;
int main()
{
	node *L=NULL, *P=NULL;
	//initialList(L);

	int nChoice=-1; //����ѡ��
	do
	{
		//��ʾ���˵�
		cout<<"**********��������Գ���***********"<<endl;
		cout<<"* 0-�˳�                          *"<<endl;
		cout<<"* 1-����β�巨��������            *"<<endl;
		cout<<"* 2-����ͷ�巨��������            *"<<endl;
		cout<<"* 3-��������                      *"<<endl;
		cout<<"* 4-��������                    *"<<endl;
		cout<<"* 5-���i��Ԫ��                   *"<<endl;
		cout<<"*---------------------------------*"<<endl;
		cout<<"* 6-�ڵ�i�����ǰ����x            *"<<endl;
		cout<<"* 7-����ֵΪx�Ľ��,�ɹ����ؽ��ָ��*"<<endl;
		cout<<"* 8-ɾ���������i��Ԫ�ؽ��       *"<<endl;
		cout<<"* 9-��һ���������������в���x������������*"<<endl;
		cout<<"* 10-����L��Ԫ�ذ���ż�ֿ������  *"<<endl;
		cout<<"* 11-��������Ĺ���Ԫ��           *"<<endl;
		cout<<"* 12-ɾ���������������е��ظ�Ԫ��*"<<endl;
		cout<<"* 13-��������������������о͵غϲ�*"<<endl;
		cout<<"* 14-�������                      *"<<endl;
		cout<<"***********************************"<<endl;

		cout<<"����������ѡ�������";
		cin>>nChoice;

		switch(nChoice)
		{
		case 0:  //�˳�
			cout<<"��ǰѡ��������˳���"<<endl;
			cout<<"<-- �����˳� -->"<<endl;  //ѡ���˳�
			break;

		case 1:  //����β�崴������
			system("cls");  //�����Ļ
			if(L!=NULL)
				DestroyList(L);    //������ԭ����			

			CreateListRear(L);       
			PrintList(L);
			system("pause");
			break;
		case 2:  //����ͷ�崴������
			system("cls");  //�����Ļ

			if(L!=NULL)
			DestroyList(L);    //������ԭ����
			CreateListHead(L);
			PrintList(L);
			system("pause");
			break;
			
		case 3:  //�������� 
			system("cls");  //�����Ļ
			DestroyList(L);
			break;		
		case 4:  //��� 
			system("cls");  //�����Ļ
			if(L==NULL)
			{
				cout<<"��Lδ��ʼ�������ȳ�ʼ����������Ԫ�ء�"<<endl;
				break;
			}			
			cout<<"����"<<listLen(L); 
			system("pause");
			break;			
		
		case 5:  //��Ԫ��ֵ 
			system("cls");  //�����Ļ
			if(L==NULL)
			{
				cout<<"��L�����ڡ�"<<endl;
				break;
			}
			ElementType temp;
			bool flag1;
			flag1 = Pos_Value(L,temp);
			if(flag1==false) cout<<"error";
			else cout<<"Value:"<<temp;
			system("pause");	
			break;		
		case 6://����Ԫ�� 
			system("cls");  //�����Ļ
			if(L==NULL)
			{
				cout<<"��L�����ڡ�"<<endl;
				break;
			}
			Insert(L);
			system("pause");
			break;			
		case 7:  //��ѯ
			system("cls");  //�����Ļ
			if(L==NULL)
			{
				cout<<"��L�����ڡ�"<<endl;
				break;
			}
			node *t;
			bool flag;
			flag =  Search(L,t);
			if(flag==false) cout<<"error";
			else cout<<"done";
			system("pause");
			break;
		case 8://ɾ��Ԫ�� 
			system("cls");  //�����Ļ
			if(L==NULL)
			{
				cout<<"��L�����ڡ�"<<endl;
				break;
			}
			bool flag2;
			flag2 =  Delete(L);
			if(flag2==false) cout<<"error";
			else cout<<"done";
			system("pause");
			break;
		case 9:  //���������
            system("cls");  //�����Ļ
			DestroyList(L);
			CreateListRear(L);
			InceasingInsert(L);
			system("pause");
			break;
		case 10:  //����ż�ֿ� 
			system("cls");  //�����Ļ
			DestroyList(L);
			CreateListRear(L);
			Divide(L);
			system("pause");
			break;
		case 11:  //����ͬԪ�� 
			system("cls");  //�����Ļ
			cout<<"Bulid List";
			DestroyList(L);
			DestroyList(P);
			CreateListRear(L);
			CreateListRear(P);
			GerIntersection(L,P);
			system("pause");
			break;
		case 12:  //ɾ���ظ�Ԫ�� 
			system("cls");  //�����Ļ
			DestroyList(L);
			CreateListRear(L);
			DeleteSameEle(L);
			system("pause");
			break;
		case 13:  //�ϲ� 
			system("cls");  //�����Ļ
			DestroyList(L);
			DestroyList(P);
			CreateListRear(L);
			CreateListRear(P);
			Merge(L,P);
			system("pause");
			break;
		case 14://��ӡ���� 
			PrintList(L);
			system("pause");
			break;
		default:
			cout<<"����ѡ���������0��14֮��ѡ��==>"<<endl;
			system("pause");
			break;
        }
	
	}while(nChoice!=0);
	DestroyList(L);
	return 0;
}
