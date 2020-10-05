#ifndef _SEQLIST_H_
#define _SEQLIST_H_


#include<iostream>
#include<string.h>
#include<stdio.h>

#define MAXLEN 100  //�������Ա���������

typedef int elementType; //��������Ԫ�ص��������� 

//*********************************************//
//*          ����˳���Ľṹ                 *//
//*   2��������ɣ�data[]����������Ԫ��     *//
//*                listLen��ʾ����Ԫ�ظ���    *//
//*   ��typedef���䶨��Ϊ��������seqList      *//
//*********************************************//

typedef struct sList
{
	elementType data[MAXLEN];
	int listLen;
} seqList;

//1. ��ʼ����
//*********************************************//
//* �������ܣ���ʼ��˳���--�ÿձ�            *//
//* ����������seqList����ָ�룬ָ��˳���     *//
//* �� �� ֵ����                              *//
//* �� �� ����seqList.h  �� �� ����listInitial*//
//*********************************************//
void initialList(seqList *L)
{
	L->listLen=0;
}

//2. �����
//*********************************************//
//* �������ܣ�����ȣ���Ԫ�ظ���            *//
//* ����������seqList���ͱ���                 *//
//* �� �� ֵ�����ͣ���ĳ���                  *//
//* �� �� ����seqList.h  �� �� ����listLength *//
//*********************************************//
int listLength(seqList L)
{
	return L.listLen;
}

//3. ��ȡԪ��
//*********************************************//
//* �������ܣ���������ţ�ȡ������Ԫ��        *//
//* ���������seqList L��Ϊ��ǰ˳���         *//
//*           int i, ָ��Ԫ�����             *//
//* ���������elementType* x�����ػ�ȡ��Ԫ��  *// 
//* �� �� ֵ��bool��0��ȡԪ��ʧ�ܣ�1�ɹ�      *//
//* �� �� ����seqList.h  �� �� ����getElement *//
//*********************************************//
bool getElement(seqList* L, int i, elementType* x)
{
	if(i<1 || i>L->listLen)
		return 0;
	else
	{
		(*x)=L->data[i-1];
		return 1;
	}		
}
//4. ����Ԫ��
//*********************************************//
//* �������ܣ��ڸ���λ�ã��������Ԫ��        *//
//* ���������seqList* L��Ϊ��ǰ˳���ָ��    *//
//*           elementType x�������Ĳ���Ԫ��   *//
//*           int i�������Ĳ���λ��           *//
//* ���������seqList* L��Ϊ��ǰ˳���ָ��    *// 
//* �� �� ֵ����������0��������1������λ�÷Ƿ�*//
//*           2������ɹ�                     *//
//* �� �� ����seqList.h  �� �� ����listInsert *//
//*********************************************//
int listInsert(seqList *L, elementType x, int i)
{
	int j;
	
	if(L->listLen==MAXLEN)
		return 0;  //����������0
	else if(i<1 || i>L->listLen+1)
		return 1;  //��ų�����Χ������1
	else
	{
		for(j=L->listLen-1; j>=i-1; j--)
			L->data[j+1]=L->data[j];   //ѭ�����Ʊ�Ԫ��
		L->data[i-1]=x;   //����Ԫ�� x
		L->listLen++;     //������1  
		return 2;         //�ɹ����룬����ֵ2  
	}
}

//5.ɾ��Ԫ��
//*********************************************//
//* �������ܣ�ɾ������ָ��λ�õ�Ԫ��          *//
//* ���������seqList* L��Ϊ��ǰ˳���ָ��    *//
//*           int i��������ɾ��λ��           *//
//* ���������seqList* L��Ϊ��ǰ˳���ָ��    *// 
//* �� �� ֵ����������0��������1��ɾ��λ�÷Ƿ�*//
//*           2��ɾ���ɹ�                     *//
//* �� �� ����seqList.h  �� �� ����listDelete *//
//*********************************************//
int listDelete(seqList *L, int i )
{
	int j;
	if(L->listLen<=0)
		return 0; //�ձ�����ֵ0
	else if(i<1 || i>L->listLen)
		return 1;  //ɾ������Ų�����Ч��Χ��
	else
	{
		for(j=i; j<L->listLen; j++ )
			L->data[j-1]=L->data[j]; //ѭ��ǰ�Ʊ�Ԫ��
		L->listLen--;  //�޸ı���
		return 2;  //�ɹ�ɾ��������ֵ2.
	}
}
//6.��һ�����������м���Ԫ�ر�֤������Ȼ���� 
//*********************************************//
//* �������ܣ���һ�����������м���Ԫ�ر�֤������Ȼ����*//
//* ���������seqList* L��Ϊ��ǰ˳���ָ��    *//
//*           int x��������Ԫ��               *//
//* ���������seqList* L��Ϊ��ǰ˳���ָ��    *// 
//* �� �� ֵ����                              *//
//*                                           *//
//* �� �� ����seqList.h  �� �� ����IncreaseingListInsert*//
//*********************************************//

void IncreaseingListInsert(seqList *L, elementType x) 
{	int i=0;
	while(L->data[i]<x) i++;
	for(int j=L->listLen-1; j>=i+1; j-- ) {
		L->data[j+1] = L->data[j];
	}
	L->data[i] = x;
	L->listLen++;
}

//7.��ֱ� 
//*********************************************//
//* �������ܣ���������ż�����Ϊ2���±�Ȼ��ԭ����±�Ԫ��ͬʱ�������Ļ��*//
//* ���������seqList* L��Ϊ��ǰ˳���ָ��    *//
//*           seqlist* A��seqlist* B������ֺ���±�           *//
//* ����������±��Ԫ��                      *// 
//* �� �� ֵ����                               //
//*                                			  *//
//* �� �� ����seqList.h  �� �� ����listSplit *//
//*********************************************//

void ListSplit(seqList* L, seqList* A, seqList* B) {
	int k=0;
	int p=0,q=0;
	A->listLen=0;
	B->listLen=0;
	while(k<L->listLen) {
		if(k%2) A->data[p++] = L->data[k++];//����λ����A 
		else B->data[q++] = L->data[k++];//ż��λ����B 
	}
	A->listLen=p;
	B->listLen=q;
	for(int i=0; i<L->listLen; i++){
	 printf("%d ",L->data[i]);//���L 
	}
	printf("\n");
	for(int i=0; i<A->listLen; i++){
	 printf("%d ",A->data[i]);//���A 
	}
	printf("\n");
	
	for(int i=0; i<B->listLen; i++){
	 printf("%d ",B->data[i]);//���B
	}
	printf("\n");	
	return ;
}
//8.�󽻼� 
//*********************************************//
//* �������ܣ���������������˳���L1��L2�еĹ���Ԫ�أ������µ�˳���L3�С�*//
//* ���������seqList* A��Ϊ��ǰ˳���ָ��    *//
//*           seqlist* B��������ɾ��λ��
//*           seqList*C                       *//
//* ���������seqList* L��Ϊ��ǰ˳���ָ��    *// 
//* �� �� ֵ����������0���޽��� 1���н���     *//
//*                                           *//
//* �� �� ����seqList.h  �� �� ����Intersection *//
//*********************************************//
int Intersection(seqList* A,seqList* B,seqList* C) {
	int i=0,j=0,flag=0;
	C->listLen = 0;
	while(i<A->listLen && j<B->listLen) {
		if(A->data[i]==B->data[j]) {
			C->data[C->listLen++] = A->data[i];
			i++;
			j++;
			flag= 1;
		}
		else if(A->data[i]<B->data[j]) {
			i++;
		}
		else j++;
	}
	return flag==1?1:0;
}
//9.ɾ����������˳����е��ظ�Ԫ�أ���ͳ���ƶ�Ԫ�ش��� 
//*********************************************//
//* �������ܣ���������������˳���L1��L2�еĹ���Ԫ�أ������µ�˳���L3�С�*//
//* ���������seqList* A��Ϊ��ǰ˳���ָ��    *//            
//*                                           *//
//* ���������seqList* L��Ϊ��ǰ˳���ָ��    *// 
//* �� �� ֵ�����������ƶ�Ԫ�صĴ���          *//
//*                                           *//
//* �� �� ����seqList.h  �� �� ����Delete7    *//
//*********************************************//
int Delete7(seqList *A) {
	int index = 0;
	int changelen=0;
	for(int i=1; i<A->listLen; i++) {
		if(A->data[i] != A->data[index]) {
			A->data[++index] = A->data[i];	
		}                        
		else changelen++;
	}
	A->listLen-=changelen;            
	return changelen;
}
//10.���˳��� 
//*********************************************//
//* �������ܣ���������������˳���L1��L2�еĹ���Ԫ�أ������µ�˳���L3�С�*//
//* ���������seqList* A��Ϊ��ǰ˳���ָ��    *//            
//*                                           *//
//* �����������                              *// 
//* �� �� ֵ����                              *//
//*                                           *//
//* �� �� ����seqList.h  �� �� ����printList    *//
//*********************************************//
void printList(seqList* L) {
	for(int i=0; i<L->listLen; i++) {
		printf("%d ",L->data[i]);
	}
	return ;
}
//11.����˳��� 
void listbuild(seqList* A) {
	int n;
	printf("���������Ԫ�ظ���");
	scanf("%d",&n);
	A->listLen=n;
	printf("Input:");
	for(int i=0; i<n; i++)
		scanf("%d",&A->data[i]);
	printf("Done!");
	return ;
} 
#endif 
