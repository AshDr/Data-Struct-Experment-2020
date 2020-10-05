//************************************************************//
//*    ͼ���ڽ������ʾ��ͷ�ļ����ļ�����GraphAdjLinkList.h  *//
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

typedef char elementType;  //����ͼ�ж������������
typedef int eInfoType;     //�������й��ڱߵ���Ϣ���������ͣ����磬��Ȩͼ�п��Ա�ʾ�ߵ�Ȩֵ  
typedef int cellType;      //�����ڽӾ�����Ԫ�ص���������
                           //����Ȩͼ��1-���ڣ��бߣ���0-�����ڣ��ޱߣ�
                           //����Ȩͼ��Ϊ�ߵ�Ȩֵ���ر��������
typedef enum{UDG, UDN, DG, DN} GraphKind;  //ö��ͼ������--����ͼ��������������ͼ��������

typedef struct eNode       //��������ṹ
{
	int adjVer;            //�ڽӶ����ַ���˴�Ϊ�����ڶ��������ţ���1��ʼ
	eInfoType eInfo;       //�������б�ʾ�ߵ������Ϣ��������Ȩֵ
	struct eNode* next;    //ָ��������е���һ�����
}EdgeNode;                 //������������

typedef struct vNode       //�������Ԫ�ؽṹ
{
	elementType data;      //���ͼ�ж��������
	EdgeNode* firstEdge;   //ָ��˶�������ĵ�һ���ߵ�ָ�룬���������ͷָ��
}VerNode;

typedef struct GraphAdjLinkList
{
	VerNode VerList[MaxVerNum+1];  //��Ŷ����˳�������0��Ԫ����
	int VerNum;                    //������
	int ArcNum;                    //�����ߣ���
	GraphKind gKind;               //ͼ������:0-����ͼ��1-��������2-����ͼ��3-������
}Graph;                            //ͼ��������
typedef struct minEdgeType {
	int v;
	eInfoType eWeight;
}MinEdgeType;
typedef struct edgetype {
	int vbegin;
	int vend;
	eInfoType eWeight;
}EdgeType;
using namespace std;
bool visited[MaxVerNum+1];  //ȫ�����飬��Ƕ����Ƿ��Ѿ������ʡ�0--δ���ʣ�1--�ѷ��ʡ�����0��Ԫ����

//******************* ����ͼ�ж���ĺ���*********************//
//* �������ܣ���ӡͼ�ж���Ԫ�أ������Ϊ�Ѿ�����            *//
//* ��ڲ���  Graph G�������ʵ�ͼ��int verID Ŀ�궥����   *//
//* ���ڲ�������                                            *//
//* �� �� ֵ����                                            *//
//* �� �� ����visit(Graph &G, int verID)                    *//
//***********************************************************//
void visit(Graph &G, int verID)
{         //�����Ŵ�1��ʼ������0��Ԫ����
	cout<<G.VerList[verID].data<<"\t";
	visited[verID]=true;
}

//*******************  ͼ�в���Ŀ�궥�� *********************//
//* �������ܣ���������Ԫ�أ���ͼ�в��Ҵ˶���Ԫ�صı��      *//
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
		if( G.VerList[i].data==v )
			return i;
	}
	return -1;
}

//��������v�ĵ�һ���ڽӶ���
int firstAdj(Graph &G, int v)
{
	EdgeNode *p;
	p=G.VerList[v].firstEdge;
	if(p)
		return p->adjVer;
	else
		return 0;
}

//��������vλ���ڽӵ�w֮�����һ���ڽӵ�
int nextAdj(Graph &G, int v, int w)
{
	EdgeNode *p;
	p=G.VerList[v].firstEdge;         //ȡ����v�ı�����ͷָ��
	while(p->next)
	{
		if(p->adjVer==w)
			return p->next->adjVer;  //����w֮����һ���ڽӵ���
		p=p->next;	
	}
	return 0;                        //δ�ҵ���һ���ڽӵ㣬����0

}


//******************** ��ӡͼ�������Ϣ *********************//
//* �������ܣ���ӡͼ�������Ϣ                              *//
//* ��ڲ���  Graph G������ӡ��ͼ                           *//
//* ���ڲ�������                                            *//
//* �� �� ֵ����                                            *//
//* �� �� ����printGraph(Graph &G)                          *//
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
	cout<<"���\t����\t������"<<endl;
    EdgeNode* p;    
	for(i=1;i<=G.VerNum;i++)
	{
		cout<<i<<"\t"<<G.VerList[i].data<<"\t";
		p=G.VerList[i].firstEdge;
		while(p!=NULL)
		{
			cout<<p->adjVer<<"\t";
			p=p->next;
		}
		cout<<endl;
	}
	cout<<endl;
	//��ӡ�ڽӾ���
	cout<<"�ڽӾ���"<<endl;
	for(i=1;i<=G.VerNum;i++)
	{   
		cout<<"\t";
		p=G.VerList[i].firstEdge;
		j=1;
		while(p!=NULL || j<=G.VerNum)
		{
			if((j<=G.VerNum) && (p!=NULL) && j==p->adjVer)  //�б�
			{
				cout<<p->eInfo<<"\t";
				j++;
				p=p->next;
			}
			else   //�ޱ�
			{
				if(G.gKind==UDN || G.gKind==DN)
					cout<<"INF"<<"\t";  //�����ޱ�ʱ��ӡȨֵΪ������á�INF����ʾ
				else
					cout<<"0"<<"\t";    //ͼ���ޱ�ʱ��0��ʾ
				j++;			
			}
			
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
bool HasEdge(Graph &G,int vbegin, int vend, eInfoType &eWeight) {
	EdgeNode *p;
	int f = false;
	eWeight = INF;
	p = G.VerList[vbegin].firstEdge;
	while(p) {
		if(p->adjVer==vend) {
			f=true;
			eWeight = p->eInfo;
			break;
		}
		p = p->next;
	}
	return f;	
}
//��ʼ����ѡ������ 
void InitialTE(Graph G,MinEdgeType TE[], int vid) {
	eInfoType eWeight;
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
	eInfoType eMin = INF;
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
	eInfoType eWeight;
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
	for(int i=2; i<=G.VerNum; i++) cout<<G.VerList[TE[i].v].data<<"->"<<G.VerList[i].data<<"="<<TE[i].eWeight<<endl;
}
//�洢�� 
void GetEdges(Graph &G,EdgeType edges[]) {
	int k = 1;
	EdgeNode *p;
	for(int i=1; i<=G.VerNum; i++) {
		p = G.VerList[i].firstEdge;
		while(p) {
			edges[k].vbegin = i;
			edges[k].vend = p->adjVer;
			edges[k].eWeight = p->eInfo;
			p = p->next;
			k++;
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
	EdgeNode *p;
	p = G.VerList[vid].firstEdge;
	for(int i=1; i<=G.VerNum; i++) dis[i] = INF;
	while(p) {
		int v = p->adjVer;
		dis[v] = p->eInfo;
		p = p->next;
	}
	for(int i=1; i<=G.VerNum; i++) {
		solved[i] = 0;
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
		p = G.VerList[v].firstEdge;
		while(p) {
			int t = p->adjVer;
			if(!solved[t] && mindis+(p->eInfo)<dis[t]) 
				dis[t] = mindis+(p->eInfo),path[t] = v;
			p = p->next;
		}
	}
}
//��ӡ·�� 
void PrintDjiksta(Graph &G,int path[],int dis[],int vid) {
	int spath[MaxVerNum];
	int vpre;
	int top = 0;
	for(int i=1; i<=G.VerNum; i++) {
		cout<<G.VerList[vid].data<<"to"<<G.VerList[i].data<<":"<<endl;
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
					cout<<G.VerList[spath[j]].data<<" ";
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
	EdgeNode *p;
	for(int i=1; i<=G.VerNum; i++) {
		p = G.VerList[i].firstEdge;
		while(p) {
			int j = p->adjVer;
			dis[i][j] = p->eInfo;
			p = p->next;
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
			cout<<G.VerList[i].data<<"->"<<G.VerList[j].data<<"="<<dis[i][j]<<endl;
		}
	}
}
//��������� 
void GetInDegree(Graph &G, int in[]) {
	EdgeNode *p;
	for(int i=1; i<=G.VerNum; i++) {
		p = G.VerList[i].firstEdge;
		while(p) {
			int j =p->adjVer;
			in[j]++;
			p = p->next;
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
	EdgeNode *p;
	while(!s.empty()) {
		v = s.top();
		s.pop();
		topo[vcount] = v;
		vcount++;
		p = G.VerList[v].firstEdge;
		while(p) {
			int j = p->adjVer;
			in[j]--;
			if(in[j]==0) s.push(j);
			p = p->next;
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
	EdgeNode *p;
	for(int i=1; i<=G.VerNum; i++) {
		vpre = topo[i-1];
		p = G.VerList[vpre].firstEdge;
		while(p) {
			int j = p->adjVer;
			if(vet[j]<vet[vpre]+p->eInfo) vet[j] = vet[vpre]+p->eInfo;
			p = p->next;
		}
	}
	for(int i=1; i<=G.VerNum; i++) vlt[i] = vet[G.VerNum];
	for(int i=G.VerNum; i>=1; i--) {
		vsuf = topo[i-1];
		for(int j=1; j<=G.VerNum; j++) {
			p = G.VerList[j].firstEdge;
			while(p) {
				int v = p->adjVer;
				if(v==vsuf) {
					if(vlt[v]>vlt[vsuf]-p->eInfo) vlt[j] = vlt[vsuf]-p->eInfo; 
				}
				p = p->next;
			}
		}
	}
	
}
//��ӡ�ؼ�·�� 
void PrintKeyPath(Graph &G,int topo[],int vet[],int vlt[]) {
	cout<<"KeyPath: ";
	int v = topo[0];
	cout<<G.VerList[v].data<<" ";
	int w;
	while(v) {
		w = firstAdj(G,v);
		while(w) {
			if(vet[w]==vlt[w]) {
				cout<<G.VerList[w].data<<" ";
				break;
			}
			else w = nextAdj(G,v,w);
		}
		v = w;
	}
}
