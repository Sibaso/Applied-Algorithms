#include<iostream>
#include<vector>
using namespace std;
int N;
int a[6]={1,5,10,50,100,500};

int thamLam(int n){
	int ans=0;
	for(int i=5;i>=0;i--){
		ans+=n/a[i];
		n%=a[i];
	}
	return ans;
}

int main(){
	cin>>N;
	cout<<thamLam(1000-N)<<endl;
	return 0;
}
