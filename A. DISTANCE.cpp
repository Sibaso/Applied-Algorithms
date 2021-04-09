#include<iostream>
#include<vector>
using namespace std;
int n,m;
int **c;
int *x;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	c=new int*[n];
	for(int i=0;i<n;i++){
		c[i]=new int[n];
		for(int j=0;j<n;j++){
			cin>>c[i][j];
		}
	}
	cin>>m;
	x=new int[m];
	for(int i=0;i<m;i++){
		cin>>x[i];
		x[i]--;
	}
	int start=x[0];
	int dis=0;
	for(int i=1;i<m;i++){
		int end=x[i];
		dis+=c[start][end];
		start=x[i];
	}
	cout<<dis;
	return 0;
}
