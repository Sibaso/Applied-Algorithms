#include<iostream>
using namespace std;
int N,T,D;
int*t,*a,**mem;

int duyet(int i,int k){
	if(k<t[i])return -99999;
	if(i<0)return 0;
	if(mem[i][k]!=-1)return mem[i][k];
	int ans=a[i];
	for(int j=i-D;j<i;j++){
		ans=max(ans,a[i]+duyet(j,k-t[i]));
	}
	mem[i][k]=ans;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>T>>D;
	a=new int[N];
	t=new int[N];
	mem=new int*[N];
	for(int i=0;i<N;i++){
		cin>>a[i];
		mem[i]=new int[T+1];
		for(int j=0;j<=T;j++)mem[i][j]=-1;
	}
	for(int i=0;i<N;i++){
		cin>>t[i];
	}
	int ans=-1;
	for(int i=0;i<N;i++){
		ans=max(ans,duyet(i,T));
	}
	cout<<ans;
	return 0;
}
