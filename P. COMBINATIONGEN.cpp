#include<iostream>
using namespace std;
int n,m;
int*a;

void duyet(int s,int last){
	if(s>=m){	
		for(int i=0;i<m;i++)cout<<a[i]<<" ";
		cout<<endl;
		return;
	}
	for(int i=last+1;i<=n-m+s+1;i++){
		a[s]=i;
		duyet(s+1,i);
	}
}

int main(){
	cin>>n>>m;
	a=new int[m];
	duyet(0,0);
	return 0;
}
