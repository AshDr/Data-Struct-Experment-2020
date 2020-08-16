#ifndef _SEQLIST_H_
#define _SEQLIST_H_


#include<iostream>
#include<string.h>
#include<stdio.h>

#define MAXLEN 100  //定义线性表的最大容量

typedef int elementType; //定义数据元素的数据类型 

//*********************************************//
//*          定义顺序表的结构                 *//
//*   2个分量组成，data[]数组存放数据元素     *//
//*                listLen表示表中元素个数    *//
//*   用typedef将其定义为数据类型seqList      *//
//*********************************************//

typedef struct sList
{
	elementType data[MAXLEN];
	int listLen;
} seqList;

//1. 初始化表
//*********************************************//
//* 函数功能：初始化顺序表--置空表            *//
//* 函数参数：seqList类型指针，指向顺序表     *//
//* 返 回 值：空                              *//
//* 文 件 名：seqList.h  函 数 名：listInitial*//
//*********************************************//
void initialList(seqList *L)
{
	L->listLen=0;
}

//2. 求表长度
//*********************************************//
//* 函数功能：求表长度，即元素个数            *//
//* 函数参数：seqList类型变量                 *//
//* 返 回 值：整型，表的长度                  *//
//* 文 件 名：seqList.h  函 数 名：listLength *//
//*********************************************//
int listLength(seqList L)
{
	return L.listLen;
}

//3. 获取元素
//*********************************************//
//* 函数功能：按给定序号，取出表中元素        *//
//* 输入参数：seqList L，为当前顺序表         *//
//*           int i, 指定元素序号             *//
//* 输出参数：elementType* x，返回获取的元素  *// 
//* 返 回 值：bool，0：取元素失败，1成功      *//
//* 文 件 名：seqList.h  函 数 名：getElement *//
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
//4. 插入元素
//*********************************************//
//* 函数功能：在给定位置，插入给定元素        *//
//* 输入参数：seqList* L，为当前顺序表指针    *//
//*           elementType x，给定的插入元素   *//
//*           int i，给定的插入位置           *//
//* 输出参数：seqList* L，为当前顺序表指针    *// 
//* 返 回 值：整型数，0：表满；1：插入位置非法*//
//*           2：插入成功                     *//
//* 文 件 名：seqList.h  函 数 名：listInsert *//
//*********************************************//
int listInsert(seqList *L, elementType x, int i)
{
	int j;
	
	if(L->listLen==MAXLEN)
		return 0;  //表满，返回0
	else if(i<1 || i>L->listLen+1)
		return 1;  //序号超出范围，返回1
	else
	{
		for(j=L->listLen-1; j>=i-1; j--)
			L->data[j+1]=L->data[j];   //循环后移表元素
		L->data[i-1]=x;   //插入元素 x
		L->listLen++;     //表长度增1  
		return 2;         //成功插入，返回值2  
	}
}

//5.删除元素
//*********************************************//
//* 函数功能：删除表中指定位置的元素          *//
//* 输入参数：seqList* L，为当前顺序表指针    *//
//*           int i，给定的删除位置           *//
//* 输出参数：seqList* L，为当前顺序表指针    *// 
//* 返 回 值：整型数，0：表满；1：删除位置非法*//
//*           2：删除成功                     *//
//* 文 件 名：seqList.h  函 数 名：listDelete *//
//*********************************************//
int listDelete(seqList *L, int i )
{
	int j;
	if(L->listLen<=0)
		return 0; //空表，返回值0
	else if(i<1 || i>L->listLen)
		return 1;  //删除的序号不在有效范围内
	else
	{
		for(j=i; j<L->listLen; j++ )
			L->data[j-1]=L->data[j]; //循环前移表元素
		L->listLen--;  //修改表长度
		return 2;  //成功删除，返回值2.
	}
}
//6.在一个递增序列中加入元素保证序列仍然递增 
//*********************************************//
//* 函数功能：在一个递增序列中加入元素保证序列仍然递增*//
//* 输入参数：seqList* L，为当前顺序表指针    *//
//*           int x，给定的元素               *//
//* 输出参数：seqList* L，为当前顺序表指针    *// 
//* 返 回 值：无                              *//
//*                                           *//
//* 文 件 名：seqList.h  函 数 名：IncreaseingListInsert*//
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

//7.拆分表 
//*********************************************//
//* 函数功能：按奇数、偶数拆分为2个新表。然后将原表和新表元素同时输出到屏幕上*//
//* 输入参数：seqList* L，为当前顺序表指针    *//
//*           seqlist* A，seqlist* B给出拆分后的新表           *//
//* 输出参数：新表的元素                      *// 
//* 返 回 值：无                               //
//*                                			  *//
//* 文 件 名：seqList.h  函 数 名：listSplit *//
//*********************************************//

void ListSplit(seqList* L, seqList* A, seqList* B) {
	int k=0;
	int p=0,q=0;
	A->listLen=0;
	B->listLen=0;
	while(k<L->listLen) {
		if(k%2) A->data[p++] = L->data[k++];//奇数位存入A 
		else B->data[q++] = L->data[k++];//偶数位存入B 
	}
	A->listLen=p;
	B->listLen=q;
	for(int i=0; i<L->listLen; i++){
	 printf("%d ",L->data[i]);//输出L 
	}
	printf("\n");
	for(int i=0; i<A->listLen; i++){
	 printf("%d ",A->data[i]);//输出A 
	}
	printf("\n");
	
	for(int i=0; i<B->listLen; i++){
	 printf("%d ",B->data[i]);//输出B
	}
	printf("\n");	
	return ;
}
//8.求交集 
//*********************************************//
//* 函数功能：求两个递增有序顺序表L1和L2中的公共元素，放入新的顺序表L3中。*//
//* 输入参数：seqList* A，为当前顺序表指针    *//
//*           seqlist* B，给定的删除位置
//*           seqList*C                       *//
//* 输出参数：seqList* L，为当前顺序表指针    *// 
//* 返 回 值：整型数，0：无交集 1：有交集     *//
//*                                           *//
//* 文 件 名：seqList.h  函 数 名：Intersection *//
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
//9.删除递增有序顺序表中的重复元素，并统计移动元素次数 
//*********************************************//
//* 函数功能：求两个递增有序顺序表L1和L2中的公共元素，放入新的顺序表L3中。*//
//* 输入参数：seqList* A，为当前顺序表指针    *//            
//*                                           *//
//* 输出参数：seqList* L，为当前顺序表指针    *// 
//* 返 回 值：整型数，移动元素的次数          *//
//*                                           *//
//* 文 件 名：seqList.h  函 数 名：Delete7    *//
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
//10.输出顺序表 
//*********************************************//
//* 函数功能：求两个递增有序顺序表L1和L2中的公共元素，放入新的顺序表L3中。*//
//* 输入参数：seqList* A，为当前顺序表指针    *//            
//*                                           *//
//* 输出参数：无                              *// 
//* 返 回 值：无                              *//
//*                                           *//
//* 文 件 名：seqList.h  函 数 名：printList    *//
//*********************************************//
void printList(seqList* L) {
	for(int i=0; i<L->listLen; i++) {
		printf("%d ",L->data[i]);
	}
	return ;
}
//11.创建顺序表 
void listbuild(seqList* A) {
	int n;
	printf("请输入表中元素个数");
	scanf("%d",&n);
	A->listLen=n;
	printf("Input:");
	for(int i=0; i<n; i++)
		scanf("%d",&A->data[i]);
	printf("Done!");
	return ;
} 
#endif 
