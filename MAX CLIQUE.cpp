#include<iostream>
#include<vector>
using namespace std;
int N,M;
vector<int>*adj;
vector<int>color;
vector<bool>visited;
int ctr = 0;
int num_nodes = 0;

struct union_find { 
	vector <int> parent; 
	union_find(int n) { 
		parent = vector <int>(n); 
		for (int i = 0; i < n; i++) { 
			parent[i] = i;
		}
	}
	int find(int x) { 
		if (parent[x] == x) { 
			return x;
		} else {
			parent[x] = find(parent[x]); 
			return parent[x];
		} 
	}
	void unite(int x, int y) { 
		parent[find(x)] = find(y);
	}	
	void collections(){
		for(int i=0; i<parent.size(); i++){
			cout<<parent[i]<<" ";
		}cout<<endl;
	}	
};

bool ss(int u, int v){
	return(adj[u].size()>adj[v].size());
}

void duyet(int u){
	int dem=0;
	visited[u]=true;
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if(color[v]==ctr)dem++;
	}
	if(dem==num_nodes){
		color[u]=ctr;
		num_nodes++;
	}
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if(!visited[v]){
			duyet(v);
		}
	}
}

int main(){
	cin>>N>>M;
	adj = new vector<int>[N];
	color = vector<int>(N,-1);
	for(int i=0;i<M;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int best=0;
	for(int i=0;i<N;i++){
		ctr++;
		num_nodes=0;
		visited = vector<bool>(N,false);
		duyet(i);
		if(num_nodes>best)best=num_nodes;
//		for(int u=0;u<N;u++){
//			if(color[u]==ctr)cout<<u<<" ";
//		}cout<<endl;
	}
	cout<<best;
	return 0;
}
