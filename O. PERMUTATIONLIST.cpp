#include<iostream>
using namespace std;
int n,k;
int*a;
bool*flag;
int c=0;
bool lock=false;

int gt(int i){
	if(i==0)return 1;
	return i*gt(i-1);
}

void duyet(int s){
	if(s>=n){
		c++;
		if(c==k){
			lock=true;
			for(int i=0;i<n;i++){
				cout<<a[i]<<" ";
			}
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(flag[i])continue;
		if(lock)return;
		a[s]=i;
		flag[i]=true;
		duyet(s+1);
		flag[i]=false;
	}
}

int main(){
	cin>>n>>k;
	a=new int[n];
	flag=new bool[n+1];
	for(int i=0;i<=n;i++)flag[i]=false;
	duyet(0);
	if(!lock)cout<<"-1";
	return 0;
}
