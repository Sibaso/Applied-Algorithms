#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int f, s, g, u, d;
vector<int> *adj;
int main(){
	cin>>f>>s>>g>>u>>d;
	s--;g--;
	adj = new vector<int>[f];
	for(int i=0; i<f; i++){
		if(i+u<f)adj[i].push_back(i+u);
		if(i-d>=0)adj[i].push_back(i-d);
	}
//	for(int i=0;i<f;i++){
//		cout<<i<<": ";
//		for(int j=0;j<adj[i].size();j++){
//			cout<<adj[i][j]<<" ";
//		}cout<<endl;
//	}
	vector <int> dist(f, -1);
	queue<int> Q; 
	Q.push(s); 
	dist[s] = 0;
	while (!Q.empty()) { 
		int u = Q.front(); 
		Q.pop();
		for (int i = 0; i < adj[u].size(); i++) { 
			int v = adj[u][i];
			if (dist[v] == -1) { 
				Q.push(v); 
				dist[v] = 1 + dist[u]; 
			}
		}
	}
	if(dist[g]!=-1)cout<<dist[g];
	else cout<<"use the stairs";
	return 0;
}
