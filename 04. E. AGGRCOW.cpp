#include<iostream>
#include<algorithm>
using namespace std;
int N,C;
long long *x;

bool p(long long  m){
	int dem=1;
	long long pre=x[0];
	for(int i=1;i<N;i++){
		if(x[i]-pre>=m){
			dem++;
			pre=x[i];
		}
	}
	if(dem<C)return true;
	return false;
}

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>N>>C;
		x=new long long[N];
		for(int j=0;j<N;j++)cin>>x[j];
		sort(x,x+N);
		long long pre=x[0]; 
		long long hi=x[N-1]-x[0],lo=1e9;
		for(int j=1;j<N;j++){
			lo=min(lo,x[j]-pre);
			pre=x[j];
		}
		while(hi>lo){
			long long m=(hi+lo)/2;
			if(p(m))hi=m;
			else lo=m+1;
			//cout<<lo<<" "<<m<<" "<<hi<<endl;
		}
		cout<<lo-1<<endl;
	}
	return 0;
}
