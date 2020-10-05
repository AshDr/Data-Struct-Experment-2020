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
		cout<<"0--------------��������----------"<<endl;
		cout<<"1--------------����ͼ------------"<<endl;
		cout<<"2--------------���dfs���bfs��----------"<<endl;
		cout<<"3--------------��ͼ�ı���----------------"<<endl;
		cout<<"4--------------��V0����������ȱ���ͼG�����������Ӧ��������---------"<<endl;
		cout<<"5--------------��V0����������ȱ���ͼG�����������Ӧ��������---------"<<endl;
		cout<<"6--------------Prim�㷨---------"<<endl;
		cout<<"7--------------Kruskal�㷨------------"<<endl;
		cout<<"8--------------Dijkstra�㷨"<<endl;
		cout<<"9--------------Floyd�㷨"<<endl;
		cout<<"10--------------����������"<<endl;
		cout<<"11--------------��AOE���Ĺؼ�·��"<<endl;
		cout<<"Input: ";
		cin>>op;
		switch(op) {
		case 0:
		cout<<"<<--Exit-->>";
		break;
		case 1:
			cout<<"������ͼ���ļ�:";
			scanf("%s",name);
			flag = CreateGraphFromFile(name,G);	
			if(!flag) cout<<"����ʧ��"<<endl;
			else cout<<"�����ɹ�"<<endl;
			system("pause");
			system("cls");
			break;
			case 2:
				if(!flag) {
					cout<<"�빹��ͼ"<<endl;
					system("pause");
					system("cls");
					break; 
				}
				cout<<"dfs��: ";
				memset(visited,0,sizeof visited);
				for(int i=1;i<=G.VerNum; i++) {
					if(!visited[i]) dfs(G,i),cout<<endl;
						
				}
				cout<<endl;
				memset(visited,0,sizeof visited);
				cout<<"bfs��: ";
				for(int i=1; i<=G.VerNum; i++) {
					if(!visited[i]) bfs(G,i),cout<<endl;
				}
				cout<<endl;
				system("pause");
				system("cls");
				break;
				case 3:
					if(!flag) {
						cout<<"�빹��ͼ"<<endl;
						system("pause");
						system("cls");
						break; 
					}
					cout<<"������"<<G.ArcNum<<endl;
					system("pause");
					system("cls");
					break;
					case 4:
						if(!flag) {
							cout<<"�빹��ͼ"<<endl;
							system("pause");
							system("cls");
							break; 
						}
						memset(visited,0,sizeof visited);
						cout<<"������ʼ��:";
						cin>>v0;
						dfs(G,v0);
						system("pause");
						system("cls");
						break;
						case 5:
							if(!flag) {
								cout<<"�빹��ͼ"<<endl;
								system("pause");
								system("cls");
								break; 
							}
							memset(visited,0,sizeof visited);
							cout<<"������ʼ��:";
							cin>>v0;
							bfs(G,v0);	
							system("pause");
							system("cls");
							break;
							case 6:
								if(!flag) {
									cout<<"�빹��ͼ"<<endl;
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
										cout<<"�빹��ͼ"<<endl;
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
											cout<<"�빹��ͼ"<<endl;
											system("pause");
											system("cls");
											break; 
										}
										cout<<"������ָ������:";;
										cin>>v0;
										Djikstra(G,path,dis,v0);
										PrintDjiksta(G,path,dis,v0);
										system("pause");
										system("cls");
										break;
										case 9:
											if(!flag) {
												cout<<"�빹��ͼ"<<endl;
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
													cout<<"�빹��ͼ"<<endl;
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
														cout<<"�빹��ͼ"<<endl;
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
													default : cout<<"�������"<<endl;
															  system("pause");
															  system("cls");	
		}											
		
	}while(op);
	DestroyGraph(G);
	return 0;
}
