#include"grpAdjLinkedList.h"
#include"createGrpAdjLinkedList.h"
char name[100];
int path[MaxVerNum];
int dis[MaxVerNum];
int diss[MaxVerNum][MaxVerNum];
int topo[MaxVerNum],vlt[MaxVerNum],vet[MaxVerNum];
int main() {
	int op,v0;
	bool flag = false;
	Graph G;
	do {
		cout<<"0--------------结束程序----------"<<endl;
		cout<<"1--------------构建图------------"<<endl;
		cout<<"2--------------输出dfs序和bfs序----------"<<endl;
		cout<<"3--------------求图的边数----------------"<<endl;
		cout<<"4--------------从V0出发深度优先遍历图G，并构造出相应的生成树---------"<<endl;
		cout<<"5--------------从V0出发广度优先遍历图G，并构造出相应的生成树---------"<<endl;
		cout<<"6--------------Prim算法---------"<<endl;
		cout<<"7--------------Kruskal算法------------"<<endl;
		cout<<"8--------------Dijkstra算法"<<endl;
		cout<<"9--------------Floyd算法"<<endl;
		cout<<"10--------------求拓扑序列"<<endl;
		cout<<"11--------------求AOE网的关键路径"<<endl;
		cout<<"Input: ";
		cin>>op;
		switch(op) {
		case 0:
		cout<<"<<--Exit-->>";
		break;
		case 1:
			cout<<"请输入图的文件:";
			scanf("%s",name);
			flag = CreateGraphFromFile(name,G);	
			if(!flag) cout<<"构建失败"<<endl;
			else cout<<"构建成功"<<endl;
			system("pause");
			system("cls");
			break;
			case 2:
				if(!flag) {
					cout<<"请构建图"<<endl;
					system("pause");
					system("cls");
					break; 
				}
				cout<<"dfs序: ";
				memset(visited,0,sizeof visited);
				for(int i=1;i<=G.VerNum; i++) {
					if(!visited[i]) dfs(G,i),cout<<endl;
						
				}
				cout<<endl;
				memset(visited,0,sizeof visited);
				cout<<"bfs序: ";
				for(int i=1; i<=G.VerNum; i++) {
					if(!visited[i]) bfs(G,i),cout<<endl;
				}
				cout<<endl;
				system("pause");
				system("cls");
				break;
				case 3:
					if(!flag) {
						cout<<"请构建图"<<endl;
						system("pause");
						system("cls");
						break; 
					}
					cout<<"边数："<<G.ArcNum<<endl;
					system("pause");
					system("cls");
					break;
					case 4:
						if(!flag) {
							cout<<"请构建图"<<endl;
							system("pause");
							system("cls");
							break; 
						}
						memset(visited,0,sizeof visited);
						cout<<"输入起始点:";
						cin>>v0;
						dfs(G,v0);
						system("pause");
						system("cls");
						break;
						case 5:
							if(!flag) {
								cout<<"请构建图"<<endl;
								system("pause");
								system("cls");
								break; 
							}
							memset(visited,0,sizeof visited);
							cout<<"输入起始点:";
							cin>>v0;
							bfs(G,v0);	
							system("pause");
							system("cls");
							break;
							case 6:
								if(!flag) {
									cout<<"请构建图"<<endl;
									system("pause");
									system("cls");
									break; 
								}
								memset(visited,0,sizeof visited);
								Prim(G,1);
								system("pause");
								system("cls");
								break;
								case 7:
									if(!flag) {
										cout<<"请构建图"<<endl;
										system("pause");
										system("cls");
										break; 
									}
									memset(visited,0,sizeof visited);
									Kruskal(G);
									system("pause");
									system("cls");
									break;
									case 8:
										if(!flag) {
											cout<<"请构建图"<<endl;
											system("pause");
											system("cls");
											break; 
										}
										cout<<"请输入指定顶点:";;
										cin>>v0;
										Djikstra(G,path,dis,v0);
										PrintDjiksta(G,path,dis,v0);
										system("pause");
										system("cls");
										break;
										case 9:
											if(!flag) {
												cout<<"请构建图"<<endl;
												system("pause");
												system("cls");
												break; 
											}
											for(int i=1; i<=G.VerNum; i++)
												for(int j=1; j<=G.VerNum; j++)
													diss[i][j] = INF;
											Floyed(G,diss);
											system("pause");
											system("cls");
											break;
											case 10:
												if(!flag) {
													cout<<"请构建图"<<endl;
													system("pause");
													system("cls");
													break; 
												}
												bool f; 
												f = toposort(G,topo);
												if(!f) cout<<"Failed"<<endl;
												else{
													cout<<"Succeed"<<endl;
													for(int i=0; i<G.VerNum; i++) cout<<G.VerList[topo[i]].data<<" ";
												}	
												system("pause");
												system("cls");
												break;
												case 11:
													if(!flag) {
														cout<<"请构建图"<<endl;
														system("pause");
														system("cls");
														break; 
													}
													f = toposort(G,topo);
													if(!f) cout<<"Failed"<<endl;
													else {
														KeyPath(G,vet,vlt,topo);
														PrintKeyPath(G,topo,vet,vlt);
														cout<<endl;	
													}
													system("pause");
													system("cls");
													break;
													default : cout<<"输入错误"<<endl;
															  system("pause");
															  system("cls");	
		}											
		
	}while(op);
	DestroyGraph(G);
	return 0;
}
