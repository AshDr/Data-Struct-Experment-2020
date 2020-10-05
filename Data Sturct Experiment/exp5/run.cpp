#include"Forest.h"
using namespace std;
int main(int argc, char* argv[])
{
	pTree T1;    //˫�ױ�ʾ������ɭ�֣� 
	csNode *T;   //�����ֵ������ʾ����
	int  nR=0;
	int i;
	int nChoice;
	char strFileName[100];
	T1.n=0;
	T=NULL;
	do
	{
		//�����˵�
		cout<<"*** �����ֵ������ʾ������ɭ�֣����Գ��� ***"<<endl;
		cout<<"*  0--�˳�                                 *"<<endl;
		cout<<"*  1--�ļ�����ɭ��                         *"<<endl;	
		cout<<"*  2--��������ɭ�֣�                       *"<<endl;
		cout<<"*------------------------------------------*"<<endl;
		cout<<"*  3--����ɭ��                             *"<<endl;
		cout<<"*  4--��������                           *"<<endl;
		cout<<"*  5--��Ҷ�������                         *"<<endl;
		cout<<"*  6--��ɭ�ָ߶�                           *"<<endl;
		cout<<"*  7--��ɭ�ֵĶ�                           *"<<endl;
		cout<<"*  8--���������㼰���                   *"<<endl;
		cout<<"*  9--���������ʾ����                   *"<<endl;
		cout<<"*                                          *"<<endl;
		cout<<"********************************************"<<endl;
		cout<<"��ѡ�����(0-8)��";
		cin>>nChoice;
		switch(nChoice)
		{
		case 0:  //�˳�����
			system("cls");  //�����Ļ
			cout<<"<-- �����˳� -->"<<endl;  //ѡ���˳�
			break;
		case 1:
			system("cls");  //�����Ļ
			if(T!=NULL )     //��ֹ�ظ�����������ڴ�й¶
			{
				cout<<"����ɭ�֣��Ѿ����ڣ��������´��������������ٴ�����"<<endl;
				break;
			}
			char strFileName[100];
			cout<<"����������ɭ�֣������ļ���(i.e. tree6.tre)��";
			cin>>strFileName;  //����̨���������ļ���
			
			if(!CreateTreeFromFile(strFileName,T1))     //�Ը��ӽ���Ϊ�������ݣ�����˫�ױ�ʾ����T1
			{
				cout<<"����ɭ�֣�����ʧ�ܡ�"<<endl;
				break;
			
			}
			createCsTree(T,T1);                         //��˫�ױ�ʾ������ɭ�֣��������������ʾ������ɭ�֣�
			cout<<"<-- ����ɭ�֣�������� -->"<<endl; 
			break;
		case 2:  //��������ɭ�֣�
			system("cls");  //�����Ļ
			if (T!=NULL)
				destroyTree(T);  //���ٶ�����			
			cout<<"<-- ����ɭ�֣��Ѿ����٣�-->"<<endl;
			break;
		case 3:  //��������ɭ�֣�
			system("cls");  //�����Ļ
			
			if(T==NULL)
			{
				cout<<"<--����ɭ�֣�Ϊ�ա�-->"<<endl;
				break;
			}
			cout<<"����ɭ�֣����������"<<endl;
			cout<<"�������";
			preOrder(T);   //�ݹ��������
			cout<<endl;
			cout<<"�������";
			postOrder(T);  //�ݹ�������
			cout<<endl;
			cout<<"��δ���";
			hieOrder(T);
			cout<<endl;
			break;
		case 4:  //������
			system("cls");  //�����Ļ
			nR=nodeNum(T);
			cout<<"����ɭ�֣��Ľ������"<<nR<<endl;
			break;
		case 5:  //��Ҷ�ӽ����
			system("cls");  //�����Ļ
			nR=0;
			leafNum(T,nR);
			cout<<"����ɭ�֣���Ҷ�ӽ������"<<nR<<endl;
			break;			
		case 6:  //������ɭ�֣��߶�
			system("cls");  //�����Ļ
			nR=height(T);
			cout<<"����ɭ�֣��ĸ߶ȣ�"<<nR<<endl;
			break;	
		case 7:  //������ɭ�֣��Ķ�
			system("cls");  //�����Ļ
			nR=0;
			width(T,nR);
			cout<<"����ɭ�֣��Ķȣ�"<<nR<<endl;
			break;									
		case 8:  //����������ֵ����� 
			system("cls");  //�����Ļ
			if(T==NULL)
			{
				cout<<"<--����ɭ�֣�Ϊ�ա�-->"<<endl;
				break;
			}

			cout<<"<--����ɭ�֣��������м���Σ�"<<endl;
			outPreOrder(T,1);    //����������ֵ�����
			cout<<endl;
			break;
		case 9:  //�������ʽ�����������
			system("cls");  //�����Ļ
			if(T==NULL)
			{
				cout<<"<--����ɭ�֣�Ϊ�ա�-->"<<endl;
				break;
			}

			cout<<"����ɭ�֣��������ʽ�����"<<endl;
			cout<<"(";       //Ϊ�����һ���������
			outGList(T);     //�������ʽ���
			cout<<endl;
			break;
		default:
			cout<<"����ѡ���������0��9֮��ѡ��==>"<<endl;
			break;
		}
	
	}while(nChoice!=0);  //ѭ����ʾ�˵���nMenu==0�˳�

	if (T!=NULL)
	   destroyTree(T);    //������(ɭ��)
	return 0;
}

