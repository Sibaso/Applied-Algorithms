#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
int N,M;
int*a;
int*c;
long long Q=0;
long long p = (long long)(1e9+7);
int save[100][501];
void duyet(int s, int total){
	if(total<0)return;
	if(s>=N){
		if(total==0){
			Q++;
		}
		return;
	}
	c[s]+=a[s];
	duyet(s+1, total-a[s]);
	duyet(s, total-a[s]);
	c[s]-=a[s];
}

long long qhd(int n, int m){
	if(m==0)return 0;
	if(n==0){
		if(m%a[n]==0)return 1;
		else return 0;
	}
	if(save[n][m]!=-1)return save[n][m];
	long long ans=0;
	for(int k=1;k<=m/a[n];k++){
		ans+=qhd(n-1,m-a[n]*k);
	}
	ans = ans%p;
	save[n][m]=ans;
	return ans;
}

int main(){
	memset(save,-1,sizeof(save));
	cin>>N>>M;
	a=new int[N];
	//c=new int[N];
	for(int i=0;i<N;i++){
		cin>>a[i];
		//c[i]=0;
	}
	//duyet(0,M);
	cout<<qhd(N-1,M);
	return 0;
}
