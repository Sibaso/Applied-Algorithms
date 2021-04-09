#include<iostream>
#include<string.h>
#include<map>
#include<vector>
using namespace std;
int W,H,N;
int*w,*h;
map<vector<int>,int> mem;


int duyet(int i,int x,int y){
	if(x < 0 || y < 0)return -99999;
	if(i<0)return 0;
	vector<int>v;
	v.push_back(i);
	v.push_back(x);
	v.push_back(y);
	if(mem[v]!=0)return mem[v]-1;
	int ans=0;
	int s=w[i]*h[i];
	ans=max(ans,s*(x/w[i])+duyet(i,x,y-h[i]));
	ans=max(ans,s*(y/h[i])+duyet(i,x-w[i],y));
	ans=max(ans,duyet(i-1,x,y));
	mem[v]=ans+1;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>W>>H;
	cin>>N;
	w=new int[N];
	h=new int[N];
	for(int i=0;i<N;i++){
		cin>>w[i]>>h[i];
	}
	cout<<W*H-duyet(N-1,W,H);
	return 0;
}
