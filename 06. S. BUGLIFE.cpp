#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int N,M;
vector<int> *adj;
int*color;
bool bipartite = true;

void toMau(int u){
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(color[v]==-1){
			color[v]= !color[u];
			toMau(v);
		}
		else if(color[v]==color[u]){
			bipartite = false;
		}
	}
}

int main(){
	int T;
	cin>>T;
	for(int t=0;t<T;t++){
		bipartite = true;
		cin>>N>>M;
		adj = new vector<int>[N];
		color = new int[N];
		for(int u=0;u<N;u++)color[u]=-1;
		for(int i=0;i<M;i++){
			int u,v;
			cin>>u>>v;
			u--;v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for(int u=0;u<N;u++){
			if(color[u]==-1){
				color[u]=0;
				toMau(u);
			}
		}
		if(!bipartite){
			cout<<"Scenario #"<<t+1<<":\nSuspicious bugs found!\n";
		}
		else{
			cout<<"Scenario #"<<t+1<<":\nNo suspicious bugs found!\n";
		}
	}
	return 0;
}
