#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;
int N,K;
int*c,*d;
int**dist;
vector<int> *adj;
struct edge { 
	int u, v; 
	int weight;
	edge(int _u, int _v, int _w) {
		u = _u; 
		v = _v; 
		weight = _w; 
	}
};
vector<edge> *vh;
int* dd;
void dijkstra(int start) { 
	dd[start] = 0; 
	priority_queue <pair <int , int>, 
					vector <pair <int , int > >, 
					greater <pair <int , int > > > pq; 
	pq.push(make_pair(dd[start], start));
	while (!pq.empty()) { 
		int u = pq.top().second; 
		pq.pop();
		for (int i = 0; i < vh[u].size(); i++) { 
			int v = vh[u][i].v; 
			int w = vh[u][i].weight;
			if (w + dd[u] < dd[v]) { 
				dd[v] = w + dd[u];
				pq.push(make_pair(dd[v], v)); 
			}
		}
	}
}

int main(){ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>K;
	c=new int[N];
	d=new int[N];
	dd=new int[N];
	dist=new int*[N];
	adj=new vector<int>[N];
	vh=new vector<edge>[N];
	for(int i=0;i<N;i++){
		cin>>c[i]>>d[i];
		dist[i]=new int[N];
		dd[i]=1e9;
		for(int j=0;j<N;j++){
			dist[i][j]=-1;
		}
	}
	for(int i=0;i<K;i++){
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int x=0;x<N;x++){
		queue<int> Q; 
		Q.push(x); 
		dist[x][x] = 0;
		while (!Q.empty()) { 
			int u = Q.front(); 
			Q.pop();
			for (int i = 0; i < adj[u].size(); i++) { 
				int v = adj[u][i]; 
				if (dist[x][v] == -1) { 
					Q.push(v); 
					dist[x][v] = 1 + dist[x][u]; 
				} 
			}
		}
	}
	for(int u=0;u<N;u++){
		for(int v=0;v<N;v++){
			if(dist[u][v]<=d[u]){
				//cout<<u<<"->"<<v<<" : "<<dist[u][v]<<endl;
				vh[u].push_back(edge(u,v,c[u]));
			}
		}
	}
	dijkstra(0);
	//for(int i =0;i<N;i++)cout<<dd[i]<<endl;
	cout<<dd[N-1];
}
