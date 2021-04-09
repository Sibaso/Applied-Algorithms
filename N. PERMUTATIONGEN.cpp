#include<iostream>
using namespace std;
int n,k;
int*a;
bool *flag;
bool lock=false;

void duyet(int s){
	if(s>=n){
		lock=true;
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(flag[i])continue;
		a[s]=i;
		flag[i]=true;
		duyet(s+1);
		flag[i]=false;
		if(lock)return;
	}
}

int main(){
	cin>>n;
	a=new int[n];
	flag=new bool[n+1];
	k=-1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		flag[a[i]]=true;
	}
	flag[a[n-1]]=false;
	for(int i=n-2;i>=0;i--){
		flag[a[i]]=false;
		if(a[i+1]>a[i]){
			k=i;
			break;
		}
	}
	if(k==-1)cout<<k;
	else {
		for(int i=a[k]+1;i<=n;i++){
			if(!flag[i]){
				a[k]=i;
				flag[i]=true;
				break;
			}
		}
		duyet(k+1);
	}
	return 0;
}
