#include<iostream>
using namespace std;
int n,m,M;
int *a;
int dem=0;

void duyet(int s,int f){
	if(s>=n)return;
	if(f>=m&&f<=M)dem++;
	duyet(s+1,f+a[s]);
	duyet(s+1,0);
}

int main(){
	cin>>n>>m>>M;
	a=new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	duyet(0,0);
	cout << dem << endl;
	return 0;
}
