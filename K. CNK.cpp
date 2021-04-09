#include<iostream>
using namespace std;
long long n,k,m;
long long N,K,N_K;
long long result;

long long giai_thua(long long i){
	cout<<i<<endl;
	if(i==0)return 1;
	long long t=(i*giai_thua(i-1));
	cout<<t<<endl;
	if(i==n)N=t;
	if(i==k)K=t;
	if(i==(n-k))N_K=t;
	return t;
}

int main(){
	int T;
	cin>>T;
	for(int l=0;l<T;l++){
		cin>>n>>k>>m;
		N=K=N_K=1;
		giai_thua(n);
		cout<<endl;
		cout<<N<<endl;
		cout<<k<<endl;
		cout<<N_K<<endl;
		cout<<((N/(K*N_K))%m)<<"\n";
	}
	return 0;
}
