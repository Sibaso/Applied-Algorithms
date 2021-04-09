#include<iostream>
#include<algorithm>
using namespace std;
int n,i;
long long k;
int dem_0=0;
long long dem_xau=0;
bool lock=false;
int *a;

void duyet(int s){
	if(s>=n){
		dem_xau++;
		if(dem_xau==k){
			lock=true;
			for(int j=0;j<n;j++)cout<<a[j]<<" ";
			cout<<"\n";
		}
		return;
	}
	if(dem_0+1<i){
		a[s]=0;
		dem_0++;
		duyet(s+1);
		dem_0--;
		if(lock)return;
	}
	a[s]=1;
	int t=dem_0;
	dem_0=0;
	duyet(s+1);	
	dem_0=t;
}

int main(){
	cin>>n>>k>>i;
	a= new int[n];
	duyet(0);
	if(!lock)cout<<"-1";
	return 0;
}
