#include<iostream>
#include<vector>
using namespace std;
int n,m;
vector<int> *adj;
vector<int> order;
vector<int> *circles;
vector<bool> visited;
int ctr=0;

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
	order.push_back(u);
	visited[u]=true;
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if(v==p)continue;
		if(visited[v]){
			bool start = false;
			for(int j=0;j<order.size();j++){
				if(order[j]==v){
					start=true;
					ctr++;
					//cout<<endl;
				}
				if(start){
					circles[order[j]].push_back(ctr);
					//cout<<order[j]<<" ";
				}
				if(order[j]==u)break;
			}
		}
		else{
			find_circle(v,u);
		}
	}
}

bool in_circle(int u, int c){
	for(int i=0;i<circles[u].size();i++){
		if(circles[u][i]==c)return true;
	}
	return false;
}

bool ke(int u,int v){
	for(int i=0;i<adj[u].size();i++){
		if(adj[u][i]==v)return true;
	}
	return false;
}

bool check(int u,int v){
	if(circles[u].size()==0||circles[v].size()==0)return true;
	for(int i=0;i<circles[u].size();i++){
		for(int j=0;i<circles[v].size();j++){
			if(i==j)return false;
		}
	}
	return true;
}

int main(){
	cin>>n>>m;
	adj = new vector<int>[n];
	circles = new vector<int>[n];
	union_find uf = union_find(n);
	for(int i=0; i<m; i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int u=0;u<n;u++)visited.push_back(false);
	for(int u=0;u<n;u++){
		if(!visited[u])find_circle(u,-1);
	}
	int add=0;
	for(int i=0;i<ctr;i++){
		for(int j=i+1;j<=ctr;j++){
			int dem=0;
			for(int u=0;u<n;u++){
				if(in_circle(u,i)&&in_circle(u,j))dem++;
				if(dem>=2){
					add++;
					for(int u=0;u<n;u++){
						if(in_circle(u,i)||in_circle(u,j))circles[u].push_back(ctr+add);
					}
					break;
				}
			}
		}
	}
//	for(int u=0;u<n;u++){
//		if(circles[u].size()==0)continue;
//		for(int i=0;i<circles[u].size();i++)cout<<circles[u][i]<<" ";
//		cout<<endl;
//	}
	int ans=0;
	for(int u=0;u<n-1;u++){
		for(int v=u+1;v<n;v++){
			if(ke(u,v))continue;
			if(check(u,v)){
				ans++;
				//cout<<u<<" "<<v<<endl;
			}
		}
	}
	cout<<ans;
	return 0;
}
//6 8
//1 2
//2 3
//2 4
//2 6
//1 3
//4 5
//3 6
//5 6
