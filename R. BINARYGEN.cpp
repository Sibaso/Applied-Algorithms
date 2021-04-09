#include<iostream>
#include<string.h>
using namespace std;
int n;
string s;
int *a;

void duyet(int s){
	if(s>=n){
		for(int j=0;j<n;j++)cout<<a[j]<<" ";
		cout<<"\n";
		return;
	}
	a[s]=0;
	duyet(s+1);
	a[s]=1;
	duyet(s+1);	
}

int main(){
	cin>>n;
	a= new int[n];
	cin>>s;
	bool check=true;
	for(int i=n-1;i>=0;i--){
		if(s[i]=='0'){
			check=false;
			break;
		}
	}
	if(check){
		cout<<"-1";
		return 0;
	}
	for(int i=n-1;i>=0;i--){
		if(s[i]=='1'){
			s[i]='0';
		}
		else{
			s[i]='1';
			break;
		}
	}
	cout<<s;
	return 0;
}
