#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,k;

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

struct edge{
	int u;
	int v;
	int weight;
	edge(int _u, int _v, int _weight){
		u = _u; 
		v = _v; 
		weight = _weight;
	}
};

vector<edge> edges;

bool cmp_edges(edge a, edge b){
	return a.weight < b.weight;
}

int main(){
	cin>>n>>m>>k;
	union_find uf = union_find(n);
	for(int i=0; i<m; i++){
		int u,v,w;
		cin>>u>>v>>w;
		u--;v--;
		edges.push_back(edge(u,v,w));
	}
	sort(edges.begin(),edges.end(),cmp_edges);
	int sum=0;
	int wei=0;
	for(int i=0; i<edges.size(); i++){
		int u = edges[i].u;
		int v = edges[i].v;
		if(uf.find(u)!=uf.find(v)){
			uf.unite(u,v);
			wei+=edges[i].weight;
			sum+=1;
		}
		if(sum==k)break;
	}
	if(sum==k)cout<<wei;
	else cout<<"-1";
	return 0;
}
