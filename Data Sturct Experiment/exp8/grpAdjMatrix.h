//************************************************************//
//*    ͼ���ڽӾ���洢��ͷ�ļ����ļ�����grpAdjMatrix.h      *//
//*                                                          *//
//************************************************************//

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include "string.h"
#include<queue>
#include<stack>

#define INF 65535          //���������
#define MaxVerNum  100     //������󶥵����
//typedef int elementType;  //����ͼ�ж������������
typedef char elementType;  //����ͼ�ж������������
typedef int cellType;      //�����ڽӾ�����Ԫ�ص���������
                           //����Ȩͼ��1-���ڣ��бߣ���0-�����ڣ��ޱߣ�
                           //����Ȩͼ��Ϊ�ߵ�Ȩֵ���ر��������
                           //ö��ͼ������--����ͼ(UDG)��������(UDN)������ͼ(DG)��������(DN)
typedef enum{UDG, UDN, DG, DN} GraphKind;  
using namespace std;

bool visited[MaxVerNum+1];  //ȫ�����飬��Ƕ����Ƿ��Ѿ����ʣ�visited[0]��Ԫ����

//****************************************************//
//*  �����ڽӾ����ʾ��ͼ�ṹ��5��������ɣ�         *//
//*      data[]���鱣��ͼ�ж�������Ԫ��              *//
//*      AdjMatrix[][]�ڽӾ���                       *//
//*      VerNum�������                              *//
//*      ArcNum�ߣ���������                          *//
//*      gKindö��ͼ������                           *//
//*  ���ǵ����Ƶ�ͳһ�ԣ�ͼ�������ƶ���ΪGraph       *//
//****************************************************//
typedef struct GraphAdjMatrix
{
	elementType Data[MaxVerNum+1];                 //�������飬��Ŷ���Ԫ�ص�ֵ��Data[0]��Ԫ����
	cellType AdjMatrix[MaxVerNum+1][MaxVerNum+1];  //�ڽӾ��������±�Ϊ0��Ԫ���ã���AdjMatrix[1][1]��Ԫ��ʼ
	int VerNum;       //������
	int ArcNum;       //�����ߣ���
	GraphKind gKind;  //ͼ������:0-����ͼ��1-��������2-����ͼ��3-������
} Graph;  //ͼ��������
typedef struct minEdgeType {
	int v;
	cellType eWeight;
}MinEdgeType ;
typedef struct edgetype {
	int vbegin;
	int vend;
	cellType eWeight;
}EdgeType;
//******************* ����ͼ�ж���ĺ���*********************//
//* �������ܣ���ӡͼ�ж���Ԫ�أ������Ϊ�Ѿ�����            *//
//* ��ڲ���  Graph G�������ʵ�ͼ��int verID Ŀ�궥����   *//
//* ���ڲ�������                                            *//
//* �� �� ֵ����                                            *//
//* �� �� ����visit(Graph &G, int verID)                    *//
//***********************************************************//
void visit(Graph &G, int verID)
{        //�����Ŵ�1��ʼ������0��Ԫ����
	cout<<G.Data[verID]<<"\t";
	visited[verID]=true;
}

//*******************  ͼ�в���Ŀ�궥�� *********************//
//* �������ܣ���������Ԫ�أ���ͼ�в��Ҵ˶���Ԫ��            *//
//* ��ڲ���  Graph G�������ʵ�ͼ��elementType v Ŀ�궥��   *//
//* ���ڲ�������                                            *//
//* �� �� ֵ��int�����Ŀ�궥����ڣ����ض����ţ�         *//
//*                �����Ŵ�1��ʼ�����򷵻�-1              *//
//* �� �� ����visit(Graph &G, int verID)                    *//
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
//�󶥵�v�ĵ�һ���ڽӵ�
int firstAdj(Graph &G,int v)
{
	int w;
	for(w=1;w<=G.VerNum;w++)
	{
		if((G.AdjMatrix[v][w]>=1)   &&
		   (G.AdjMatrix[v][w])<INF)
		   return w;    //���ص�һ���ڽӵ���
	}
	 return 0;          //δ�ҵ��ڽӵ㣬����0
}
//�󶥵�v��λ���ڽӵ�w�����һ���ڽӵ�
int nextAdj(Graph &G,int v,int w)
{
	int k;
	for(k=w+1;k<=G.VerNum;k++)
	{
		if((G.AdjMatrix[v][k]>=1)   &&
		   (G.AdjMatrix[v][k])<INF)
		   return k;    //����v��λ��w֮�����һ���ڽӵ�k
	}
	return 0;           //��������һ���ڽӵ㣬����0
}



//******************** ��ӡͼ�������Ϣ *********************//
//* �������ܣ���ӡͼ�������Ϣ                              *//
//* ��ڲ�����Graph G������ӡ��ͼ                           *//
//* ���ڲ�������                                            *//
//* �� �� ֵ����                                            *//
//* �� �� ����GraphPrint(Graph &G)                          *//
//***********************************************************//
void printGraph(Graph &G)
{
	int i=0,j=0;
	//��ӡͼ������
	switch(G.gKind)
	{
	case UDG:
		cout<<"ͼ���ͣ�����ͼ"<<endl;
		break;
	case UDN:
		cout<<"ͼ���ͣ�������"<<endl;
		break;
	case DG:
  	    cout<<"ͼ���ͣ�����ͼ"<<endl;
		break;
	case DN:
		cout<<"ͼ���ͣ�������"<<endl;
		break;
	default:
		cout<<"ͼ���ʹ���"<<endl;
		break;
	}
	//��ӡͼ�Ķ�����
	cout<<"��������"<<G.VerNum<<endl;
	//��ӡͼ�ı���
	cout<<"��  ����"<<G.ArcNum<<endl;
	//��ӡ���㼰����
	cout<<"��  �ţ�";
	for(i=1;i<=G.VerNum;i++)
	{
		cout<<i<<"\t";
	}
	cout<<endl;
	cout<<"��  �㣺";
	for(i=1;i<=G.VerNum;i++)
	{
		cout<<G.Data[i]<<"\t";
	}
	cout<<endl;

	//��ӡ�ڽӾ���
	cout<<"ͼ���ڽӾ���"<<endl;
	for(i=1;i<=G.VerNum;i++)
	{   
		cout<<"\t";
		for(j=1;j<=G.VerNum;j++)
		{
			if((G.gKind==UDN || G.gKind==DN) && G.AdjMatrix[i][j]==INF)
				cout<<"INF"<<"\t";  //���������ʱ����ӡ��INF����ʾ
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
//����� 
int getEdgeNum(Graph &G) {
	return G.ArcNum;
}
//��v��ʼdfs������������
void DfsTrav(Graph G, int u) {
	dfs(G,u);
}
//��v��ʼbfs������������
void BfsTrav(Graph G, int u) {
	bfs(G,u);
}
//ȷ���Ƿ��б� 
bool HasEdge(Graph &G,int vbegin, int vend, cellType &eWeight) {
	int f = false;
	eWeight = INF;
	if(G.AdjMatrix[vbegin][vend]>=1 && G.AdjMatrix[vbegin][vend]<INF) f = true,eWeight = G.AdjMatrix[vbegin][vend];
	return f;	
}
//��ʼ����ѡ������ 
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
//�����С�� 
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
//����TE���� 
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
//Prim�㷨 
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
//�洢�� 
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
//ȡ����С�� 
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
				path[j] = v;//����ǰ�� 
			}
		}
	}
}
//��ӡ·�� 
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
//Floyed�㷨 
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
//��������� 
void GetInDegree(Graph &G, int in[]) {
	for(int i=1; i<=G.VerNum; i++) {
		for(int j=1; j<=G.VerNum; j++) {
			if(G.AdjMatrix[j][i]) in[i]++;
		}
	}
}
//�������� 
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
//�ؼ�·�� 
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
//��ӡ�ؼ�·�� 
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
