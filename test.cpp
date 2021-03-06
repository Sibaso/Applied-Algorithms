#include<iostream>
#include<vector>
using namespace std;
int N,M;
vector<int>*adj;

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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>M;
	adj = new vector<int>[N];
	for(int i=0;i<M;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	return 0;
}                                                                                                                                                        
