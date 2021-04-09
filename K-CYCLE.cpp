#include<iostream>
#include<vector>
#include<map>
using namespace std;
int N,M,K;
vector<int>*adj;
vector<int> order;
vector<int> *circles;
vector<bool> visited;
vector<bool> tham;
map<int,int> save;
int ctr=0;
int Q;

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

void find_circle(int u, int p){
	tham[u]=true;
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if(v==p)continue;
		if(visited[v]){
			bool start = false;
			int dem=0;
			for(int j=0;j<order.size();j++){
				if(order[j]==v){
					start=true;
					ctr++;
				}
				if(start){
					circles[order[j]].push_back(ctr);
					cout<<order[j]<<" ";
					dem++;
				}
			}
			cout<<endl;
			if(dem==K){
				Q++;
			}
		}
		else{
			visited[v]=true;
			order.push_back(v);
			find_circle(v,u);
			order.pop_back();
			visited[v]=false;
		}
	}
}

void duyet(int u, int p, int q, int X){
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if(v==p)continue;
		if(v==q){
			if(save[X]==0){
				save[X]=1;
				if(order.size()==K)Q++;
				for(int j=0;j<order.size();j++){
					cout<<order[j]<<" ";
				}
				cout<<endl;
			}
		}
		if(!visited[v]){
			visited[v]=true;
			order.push_back(v);
			duyet(v,u,q,X|1<<v);
			visited[v]=false;
			order.pop_back();
		}
	}
}

int main(){
	cin>>N>>M>>K;
	adj = new vector<int>[N];
	circles = new vector<int>[N];
	visited = vector<bool>(N,false);
	tham = vector<bool>(N,false);
	for(int i=0;i<M;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
//	for(int u=0;u<N;u++){
//		if(tham[u])continue;
//		visited[u]=true;
//		order.push_back(u);
//		find_circle(u,-1);
//		order.pop_back();
//		visited[u]=false;
//	}
	for(int u=0;u<N;u++){
		visited[u]=true;
		order.push_back(u);
		duyet(u,-1,u,0|1<<u);
		order.pop_back();
		visited[u]=false;
	}
	cout<<Q;
	return 0;
}
