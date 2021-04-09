#include<iostream>
using namespace std;
int n,m,k;
int*a;
bool lock=false;
int c=0;

void duyet(int s,int last){
	if(s>=m){
		c++;
		if(c==k){
			lock=true;
			for(int i=0;i<m;i++)cout<<a[i]<<" ";
			cout<<endl;
		}
		return;
	}
	for(int i=last+1;i<=n-m+s+1;i++){
		a[s]=i;
		duyet(s+1,i);
		if(lock)return;
	}
}

int main(){
	cin>>n>>m>>k;
	a=new int[m];
	duyet(0,0);
	if(!lock)cout<<"-1";
	return 0;
}
