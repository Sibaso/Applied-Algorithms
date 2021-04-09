#include<iostream>
#include<string.h>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int n;
long long *x,*y,*z;
map<pair<long long,long long>,long long> mem;

long long duyet(long long X,long long Y){
	pair<long long,long long>p=make_pair(X,Y);
	if(mem[p]!=0)return mem[p]-1;
	long long ans=0;
	for(int i=0;i<n;i++){
		if(y[i]<X&&z[i]<Y)ans=max(ans,x[i]+duyet(y[i],z[i]));
		if(z[i]<X&&y[i]<Y)ans=max(ans,x[i]+duyet(z[i],y[i]));
		if(y[i]<X&&x[i]<Y)ans=max(ans,z[i]+duyet(y[i],x[i]));
		if(x[i]<X&&y[i]<Y)ans=max(ans,z[i]+duyet(x[i],y[i]));
		if(x[i]<X&&z[i]<Y)ans=max(ans,y[i]+duyet(x[i],z[i]));
		if(z[i]<X&&x[i]<Y)ans=max(ans,y[i]+duyet(z[i],x[i]));
	}
	mem[p]=ans+1;
	return ans;
}


int main(){
	int t=0;
	while(true){
		mem.clear();
		cin>>n;
		if(n==0)break;
		t++;
		x=new long long[n];
		y=new long long[n];
		z=new long long[n];
		for(int i=0;i<n;i++){
			cin>>x[i]>>y[i]>>z[i];
		}
		
		long long ans=0;
		for(int i=0;i<n;i++){
			ans=max(ans,x[i]+duyet(y[i],z[i]));
			ans=max(ans,x[i]+duyet(z[i],y[i]));
			ans=max(ans,z[i]+duyet(y[i],x[i]));
			ans=max(ans,z[i]+duyet(x[i],y[i]));
			ans=max(ans,y[i]+duyet(x[i],z[i]));
			ans=max(ans,y[i]+duyet(z[i],x[i]));
		}
		cout<<"Case "<<t<<": maximum height = "<<ans<<endl;
	}
	return 0;
}
