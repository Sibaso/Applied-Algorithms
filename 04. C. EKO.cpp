#include<iostream>
#include<algorithm>
using namespace std;
long long N,M;
long long *a;


bool p(long long i,long long begin){
	long long ans=0;
	for(long long j=begin;j<N;j++)ans+=a[j]-i;
	return ans<M;
}

long long find(long long i, long long begin,long long end){
	long long lo=begin,hi=end;
	while(lo<hi){
		long long m=(lo+hi)/2;
		if(a[m]>i)hi=m;
		else lo=m+1;
	}
	return hi;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>M;
	a=new long long[N];
	for(long long i=0;i<N;i++){
		cin>>a[i];
	}
	sort(a,a+N);
	long long lo=0,hi=a[N-1];
	long long begin=0,end=N-1;
	while(lo<hi){
		long long m=(lo+hi)/2;
		long long t=find(m,begin,end);
		if(p(m,t)){
			end=t;
			hi=m;
		}
		else {
			begin=t;
			lo=m+1;
		}
	}
	cout<<(hi-1);
	return 0;
}
