#include<iostream>
using namespace std;
int N,K;
int*c,*a,**mem;

int duyet(int i,int k){
	if(k<0)return -99999;
	if(i==0)return c[i];
	if(mem[i][k]!=-1)return mem[i][k];
	int ans=-99999;
	for(int j=0;j<i;j++){
		if(a[j]+j>=i){
			ans=max(ans,c[i]+duyet(j,k-1));
		}
	}
	mem[i][k]=ans;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>K;
	c=new int[N];
	a=new int[N];
	mem=new int*[N];
	for(int i=0;i<N;i++)cin>>c[i];
	for(int i=0;i<N;i++){
		cin>>a[i];
		mem[i]=new int[K+1];
		for(int j=0;j<K+1;j++)mem[i][j]=-1;
	}
	int ans=duyet(N-1,K);
	if(ans<0)ans=-1;
	cout<<ans;
	return 0;
}
