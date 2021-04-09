#include<iostream>
using namespace std;
int n,L1,L2;
int*a;
int*mem;

int duyet(int i){
	if(i<0)return 0;
	if(mem[i]!=-1)return mem[i];
	int ans=a[i];
	for(int j=i-L2;j<i;j++){
		if(i-j>=L1){
			ans=max(ans,a[i]+duyet(j));
		}
		else{
			ans=max(ans,duyet(j));
		}
	}
	mem[i]=ans;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>L1>>L2;
	a=new int[n];
	mem=new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		mem[i]=-1;
	}
	cout<<duyet(n-1);
	return 0;
}
