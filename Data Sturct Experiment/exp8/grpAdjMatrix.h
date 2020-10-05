//************************************************************//
//*    图的邻接矩阵存储的头文件，文件名：grpAdjMatrix.h      *//
//*                                                          *//
//************************************************************//

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include "string.h"
#include<queue>
#include<stack>

#define INF 65535          //定义无穷大
#define MaxVerNum  100     //定义最大顶点个数
//typedef int elementType;  //定义图中顶点的数据类型
typedef char elementType;  //定义图中顶点的数据类型
typedef int cellType;      //定义邻接矩阵中元素的数据类型
                           //对无权图，1-相邻（有边），0-不相邻（无边）
                           //对有权图，为边的权值，特别是无穷大。
                           //枚举图的类型--无向图(UDG)，无向网(UDN)，有向图(DG)，有向网(DN)
typedef enum{UDG, UDN, DG, DN} GraphKind;  
using namespace std;

bool visited[MaxVerNum+1];  //全局数组，标记顶点是否已经访问，visited[0]单元不用

//****************************************************//
//*  定义邻接矩阵表示的图结构。5个分量组成：         *//
//*      data[]数组保存图中顶点数据元素              *//
//*      AdjMatrix[][]邻接矩阵                       *//
//*      VerNum顶点个数                              *//
//*      ArcNum边（弧）条数                          *//
//*      gKind枚举图的类型                           *//
//*  考虑到名称的统一性，图类型名称定义为Graph       *//
//****************************************************//
typedef struct GraphAdjMatrix
{
	elementType Data[MaxVerNum+1];                 //顶点数组，存放顶点元素的值，Data[0]单元不用
	cellType AdjMatrix[MaxVerNum+1][MaxVerNum+1];  //邻接矩阵，数组下标为0单元不用，从AdjMatrix[1][1]单元开始
	int VerNum;       //顶点数
	int ArcNum;       //弧（边）数
	GraphKind gKind;  //图的类型:0-无向图；1-无向网；2-有向图；3-有向网
} Graph;  //图的类型名
typedef struct minEdgeType {
	int v;
	cellType eWeight;
}MinEdgeType ;
typedef struct edgetype {
	int vbegin;
	int vend;
	cellType eWeight;
}EdgeType;
//******************* 访问图中顶点的函数*********************//
//* 函数功能：打印图中顶点元素，并标记为已经访问            *//
//* 入口参数  Graph G，待访问的图；int verID 目标顶点编号   *//
//* 出口参数：无                                            *//
//* 返 回 值：空                                            *//
//* 函 数 名：visit(Graph &G, int verID)                    *//
//***********************************************************//
void visit(Graph &G, int verID)
{        //顶点编号从1开始，数组0单元不用
	cout<<G.Data[verID]<<"\t";
	visited[verID]=true;
}

//*******************  图中查找目标顶点 *********************//
//* 函数功能：给定顶点元素，在图中查找此顶点元素            *//
//* 入口参数  Graph G，待访问的图；elementType v 目标顶点   *//
//* 出口参数：无                                            *//
//* 返 回 值：int。如果目标顶点存在，返回顶点编号，         *//
//*                顶点编号从1开始；否则返回-1              *//
//* 函 数 名：visit(Graph &G, int verID)                    *//
//***********************************************************//
int LocateVertex(Graph &G, elementType v)
{
	for(int i=1;i<=G.VerNum;i++)
	{
		if( G.Data[i]==v )
			return i;
	}
	return -1;
}
//求顶点v的第一个邻接点
int firstAdj(Graph &G,int v)
{
	int w;
	for(w=1;w<=G.VerNum;w++)
	{
		if((G.AdjMatrix[v][w]>=1)   &&
		   (G.AdjMatrix[v][w])<INF)
		   return w;    //返回第一个邻接点编号
	}
	 return 0;          //未找到邻接点，返回0
}
//求顶点v的位于邻接点w后的下一个邻接点
int nextAdj(Graph &G,int v,int w)
{
	int k;
	for(k=w+1;k<=G.VerNum;k++)
	{
		if((G.AdjMatrix[v][k]>=1)   &&
		   (G.AdjMatrix[v][k])<INF)
		   return k;    //返回v的位于w之后的下一个邻接点k
	}
	return 0;           //不存在下一个邻接点，返回0
}



//******************** 打印图的相关信息 *********************//
//* 函数功能：打印图的相关信息                              *//
//* 入口参数：Graph G，待打印的图                           *//
//* 出口参数：无                                            *//
//* 返 回 值：空                                            *//
//* 函 数 名：GraphPrint(Graph &G)                          *//
//***********************************************************//
void printGraph(Graph &G)
{
	int i=0,j=0;
	//打印图的类型
	switch(G.gKind)
	{
	case UDG:
		cout<<"图类型：无向图"<<endl;
		break;
	case UDN:
		cout<<"图类型：无向网"<<endl;
		break;
	case DG:
  	    cout<<"图类型：有向图"<<endl;
		break;
	case DN:
		cout<<"图类型：有向网"<<endl;
		break;
	default:
		cout<<"图类型错误。"<<endl;
		break;
	}
	//打印图的顶点数
	cout<<"顶点数："<<G.VerNum<<endl;
	//打印图的边数
	cout<<"边  数："<<G.ArcNum<<endl;
	//打印顶点及其编号
	cout<<"编  号：";
	for(i=1;i<=G.VerNum;i++)
	{
		cout<<i<<"\t";
	}
	cout<<endl;
	cout<<"顶  点：";
	for(i=1;i<=G.VerNum;i++)
	{
		cout<<G.Data[i]<<"\t";
	}
	cout<<endl;

	//打印邻接矩阵
	cout<<"图的邻接矩阵："<<endl;
	for(i=1;i<=G.VerNum;i++)
	{   
		cout<<"\t";
		for(j=1;j<=G.VerNum;j++)
		{
			if((G.gKind==UDN || G.gKind==DN) && G.AdjMatrix[i][j]==INF)
				cout<<"INF"<<"\t";  //网，无穷大时，打印“INF”表示
			else
				cout<<G.AdjMatrix[i][j]<<"\t";
		}
		cout<<endl;
	}

}
void dfs(Graph G,int u) {
	int v;
	visit(G,u);
	v = firstAdj(G,u);
	while(v) {
		if(!visited[v]) dfs(G,v);
		v = nextAdj(G,u,v);
	}
}
void bfs(Graph &G,int start) {
	int u,v; queue<int> q;
	visit(G,start);
	q.push(start);
	while(!q.empty()) {
		u = q.front();
		q.pop();
		v = firstAdj(G,u);
		while(v) {
			if(!visited[v]) {
				visit(G,v);
				q.push(v);
			}
			v = nextAdj(G,u,v);
		}
	}
}
//求边数 
int getEdgeNum(Graph &G) {
	return G.ArcNum;
}
//从v开始dfs遍历并生成树
void DfsTrav(Graph G, int u) {
	dfs(G,u);
}
//从v开始bfs遍历并生成树
void BfsTrav(Graph G, int u) {
	bfs(G,u);
}
//确定是否有边 
bool HasEdge(Graph &G,int vbegin, int vend, cellType &eWeight) {
	int f = false;
	eWeight = INF;
	if(G.AdjMatrix[vbegin][vend]>=1 && G.AdjMatrix[vbegin][vend]<INF) f = true,eWeight = G.AdjMatrix[vbegin][vend];
	return f;	
}
//初始化侯选边数组 
void InitialTE(Graph G,MinEdgeType TE[], int vid) {
	cellType eWeight;
	for(int i=1; i<=G.VerNum; i++) {
		if(HasEdge(G,vid,i,eWeight)) {
			TE[i].v = vid;
			TE[i].eWeight = eWeight; 
		}
		else {
			TE[i].eWeight = INF; 
		}
	}
}
//求得最小边 
int GetMinEdge(Graph G,MinEdgeType TE[] ) {
	cellType eMin = INF;
	int j = 0;
	for(int i=1; i<=G.VerNum; i++) {
		if(!visited[i] && TE[i].eWeight<eMin) {
			j = i;
			eMin = TE[i].eWeight;
		} 
	}
	return j;
}
//更新TE数组 
void UpdateTE(Graph &G, MinEdgeType TE[], int vid) {
	cellType eWeight;
	for(int i=1; i<=G.VerNum; i++) {
		if(!visited[i]) {
			if(HasEdge(G,vid,i,eWeight) && eWeight<TE[i].eWeight) {
				TE[i].v = vid;
				TE[i].eWeight = eWeight;
			}
		}
	}
}
//Prim算法 
void Prim(Graph &G, int vid) {
	MinEdgeType TE[MaxVerNum];
	int curid;
	InitialTE(G,TE,vid);
	visited[vid] = true;
	for(int i=1; i<=G.VerNum; i++) {
		curid = GetMinEdge(G,TE);
		visited[curid] = true;
		UpdateTE(G,TE,curid);
	}
	for(int i=2; i<=G.VerNum; i++) cout<<G.Data[TE[i].v]<<"->"<<G.Data[i]<<"="<<TE[i].eWeight<<endl;
}
//存储边 
void GetEdges(Graph &G,EdgeType edges[]) {
	int k = 1;
	for(int i=1; i<=G.VerNum; i++) {
		for(int j=1; j<=G.VerNum; j++) {
			if(G.AdjMatrix[i][j]>=1 && G.AdjMatrix[i][j]<INF) {
				edges[k].vbegin = i;
				edges[k].vend = j;
				edges[k].eWeight = G.AdjMatrix[i][j];
				k++;
			}
		}
	}
}
//取得最小边 
EdgeType getMinEdge(Graph &G, EdgeType edges[],int edgeUsed[],int &n) {
	EdgeType minedge;
	cellType wMin = INF;
	int M;
	if(G.gKind==UDG || G.gKind==UDN) 
		M = G.ArcNum*2;
	else M = G.ArcNum;
	for(int i=1; i<=M; i++) {
		if(!edgeUsed[i] && edges[i].eWeight<wMin) {
			wMin = edges[i].eWeight;
			minedge.eWeight = edges[i].eWeight;
			minedge.vbegin = edges[i].vbegin;
			minedge.vend = edges[i].vend;
			n = i;
		}
	}
	return minedge;
}
//Kruskal 
void Kruskal(Graph &G) {
	int conVerID[MaxVerNum];
	EdgeType edges[MaxVerNum*MaxVerNum];
	EdgeType treeEdges[MaxVerNum];
	int edgeUsed[MaxVerNum*MaxVerNum];
	EdgeType minedge;
	int conid,n;
	GetEdges(G,edges);
	int M;
	if(G.gKind==UDG|| G.gKind==UDN)
		M = G.ArcNum*2;
	else M = G.ArcNum;
	for(int i=0; i<=M; i++) {
		edgeUsed[i] = 0;
	}
	for(int i=1; i<=G.VerNum; i++)
		conVerID[i] = i;
	for(int i=1; i<G.VerNum; i++) {
		minedge = getMinEdge(G,edges,edgeUsed,n);
		while(conVerID[minedge.vbegin]==conVerID[minedge.vend]) {
			edgeUsed[n] = 1;
			minedge = getMinEdge(G,edges,edgeUsed,n);
		}
		treeEdges[i] = minedge;
		conid = conVerID[minedge.vend];
		for(int j=1; j<=G.VerNum; j++) {
			if(conVerID[j]==conid) conVerID[j] = conVerID[minedge.vbegin];
		}
		edgeUsed[n] = 1;
	}
	for(int i=1; i<G.VerNum; i++) cout<<treeEdges[i].vbegin<<"->"<<treeEdges[i].vend<<"="<<treeEdges[i].eWeight<<endl;
}
//Djikstra 
void Djikstra(Graph &G,int path[],int dis[],int vid) {
	int solved[MaxVerNum];
	cellType mindis;
	for(int i=1; i<=G.VerNum; i++) {
		solved[i] = 0;
		dis[i] = G.AdjMatrix[vid][i];
		if(dis[i]!=INF)
			path[i] = vid;
		else path[i] = -1;
	}
	int v;
	solved[vid] = 1;
	dis[vid] = 0;
	path[vid] = -1;
	for(int i=1; i<G.VerNum; i++) {
		mindis = INF;
		for(int j=1; j<=G.VerNum; j++) {
			if(!solved[j] && dis[j]<mindis) {
				v = j;
				mindis = dis[j];		
			}
		}
		if(mindis==INF) return ;
		solved[v] = 1;
		for(int j=1; j<=G.VerNum; j++) {
			if(!solved[j] && (mindis+G.AdjMatrix[v][j]<dis[j])) {
				dis[j] = mindis+G.AdjMatrix[v][j];
				path[j] = v;//更新前驱 
			}
		}
	}
}
//打印路径 
void PrintDjiksta(Graph &G,int path[],int dis[],int vid) {
	int spath[MaxVerNum];
	int vpre;
	int top = 0;
	for(int i=1; i<=G.VerNum; i++) {
		cout<<G.Data[vid]<<"to"<<G.Data[i]<<":"<<endl;
		if(dis[i]==INF) cout<<"Can't get"<<endl;
		else {
			cout<<"min_dis:"<<dis[i]<<endl;
			cout<<"path:";
			top++;
			spath[top] = i;
			vpre = path[i];
			while(vpre!=-1) {
				top++;
				spath[top] = vpre;
				vpre = path[vpre];
			}
			if(dis[i]!=INF) {
				for(int j=top; j>=1; j--) {
					cout<<G.Data[spath[j]]<<" ";
				}
			}
		}
		top = 0;
		cout<<endl;
		cout<<endl;
	}
}
//Floyed算法 
void Floyed(Graph &G,int dis[MaxVerNum][MaxVerNum]) {
	for(int i=1; i<=G.VerNum; i++) {
		for(int j=1; j<=G.VerNum; j++) {
			dis[i][j] = G.AdjMatrix[i][j];
		}
	}
	for(int k=1; k<=G.VerNum; k++) {
		for(int i=1; i<=G.VerNum; i++) {
			for(int j=1; j<=G.VerNum; j++) {
				if(i==j) dis[i][j] = 0;
				if(i!=j && dis[i][k]+dis[k][j]<dis[i][j]) {
					dis[i][j] = dis[i][k]+dis[k][j];
				}
			}
		}
	}
	for(int i=1; i<=G.VerNum; i++) {
		for(int j=1; j<=G.VerNum; j++) {
			cout<<G.Data[i]<<"->"<<G.Data[j]<<"="<<dis[i][j]<<endl;
		}
	}
}
//求入度数组 
void GetInDegree(Graph &G, int in[]) {
	for(int i=1; i<=G.VerNum; i++) {
		for(int j=1; j<=G.VerNum; j++) {
			if(G.AdjMatrix[j][i]) in[i]++;
		}
	}
}
//拓扑排序 
bool toposort(Graph &G,int topo[]) {
	int in[MaxVerNum];
	stack<int> s;
	int v,vcount=0;
	memset(in,0,sizeof in);
	for(int i=1; i<G.VerNum; i++) {
		topo[i] = -1;
	}
	GetInDegree(G,in);
	for(int i=1; i<=G.VerNum; i++) if(in[i]==0) s.push(i);
	while(!s.empty()) {
		v = s.top();
		s.pop();
		topo[vcount] = v;
		vcount++;
		for(int i=1; i<=G.VerNum; i++) {
			if(G.AdjMatrix[v][i]>=1 && G.AdjMatrix[v][i]<INF) {
				in[i]--;
				if(in[i]==0) s.push(i);	
			}
		}
	}
	if(vcount==G.VerNum) return 1;
	else return 0;
}
//关键路径 
void KeyPath(Graph &G,int vet[],int vlt[],int topo[]) {
	bool f = toposort(G,topo);
	if(!f)  {
		cout<<"Failed"<<endl;
		return ;
	}
	int vpre,vsuf;
	for(int i=1; i<=G.VerNum; i++) vet[i] = 0;
	for(int i=1; i<=G.VerNum; i++) {
		vpre = topo[i-1];
		for(int j=1; j<=G.VerNum; j++) {
			if(G.AdjMatrix[vpre][j]>=1 && G.AdjMatrix[vpre][j]<INF) {
				if(vet[j]<vet[vpre]+G.AdjMatrix[vpre][j]) vet[j] = vet[vpre]+G.AdjMatrix[vpre][j];
			}
		}
	}
	for(int i=1; i<=G.VerNum; i++) vlt[i] = vet[G.VerNum];
	for(int i=G.VerNum; i>=1; i--) {
		vsuf = topo[i-1];
		for(int j=G.VerNum; j>=1; j--) {
			if(G.AdjMatrix[j][vsuf]>=1 && G.AdjMatrix[j][vsuf]<INF) {
				if(vlt[j]>vlt[vsuf]-G.AdjMatrix[j][vsuf]) {
					vlt[j]=vlt[vsuf]-G.AdjMatrix[j][vsuf];
				} 
			}
		}
	}
}
//打印关键路径 
void PrintKeyPath(Graph &G,int topo[],int vet[],int vlt[]) {
	cout<<"KeyPath: ";
	int v = topo[0];
	cout<<G.Data[v]<<" ";
	int w;
	while(v) {
		w = firstAdj(G,v);
		while(w) {
			if(vet[w]==vlt[w]) {
				cout<<G.Data[w]<<" ";
				break;
			}
			else w = nextAdj(G,v,w);
		}
		v = w;
	}
}
