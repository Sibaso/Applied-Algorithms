#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
using namespace std;
int N;
int *a;
struct edge { 
	int u, v; 
	int weight;
	edge(int _u, int _v, int _w) {
		u = _u; 
		v = _v; 
		weight = _w; 
	}
};
vector<edge>e;
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
		for (int i = 0; i < e[u].size(); i++) { 
			int v = e[u][i].v; 
			int w = e[u][i].weight;
			if (w + dd[u] < dd[v]) { 
				dd[v] = w + dd[u];
				pq.push(make_pair(dd[v], v)); 
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	a=new  int[N];
	dd=new int[N];
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	for(int i=0;i<N;i++){
		dd[i]=999999;
		for(int j=0;j<N;j++){
			if(abs(a[i]-a[j])<=10){
				e.push_back(edge(i,j,1));
			}
			else if(abs(a[i]-a[j])<=20){
				e.push_back(edge(i,j,5));
			}
			else{
				e.push_back(edge(i,j,10));
			}
		}
	}
	dijkstra(0);
	cout<<dd[N-1];
	return 0;
}
