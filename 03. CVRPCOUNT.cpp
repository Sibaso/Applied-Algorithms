#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int n,k,q;
int *d;
int *x;// nhung goi hang trong xe
int *c;// dung tich dang chua trong xe
long long r=0;
set<set<int> >se;

int giai_thua(int n){
	if(n==1)return 1;
	if(n==0)return 1;
	return n*giai_thua(n-1);
}

void phan_tap(int s,int X,int last){
	if(s>=k){
		if(__builtin_popcount(X)==n){
			int z=1;
			set<int>t;
			for(int i=0;i<k;i++){
				t.insert(x[i]);
			}
			if(se.find(t)==se.end()){
				se.insert(t);
				for(int i=0;i<k;i++)
					z*=giai_thua(__builtin_popcount(x[i]));
				r+=z;
			}
		}
		return;
	}
	for(int i=last+1;i<=n;i++){
		if((1<<i&X)==0 && c[s]+d[i]<=q){
			int t=x[s];
			x[s]=x[s]|1<<i;
			c[s]+=d[i];
			phan_tap(s+1,X|1<<i,0);
			phan_tap(s,X|1<<i,i);
			x[s]=t;
			c[s]-=d[i];
		}
	}
}


int main(){
	cin>>n>>k>>q;
	d=new int[n+1];
	x=new int[k];
	c=new int[k];
	d[0]=0;
	for(int i=1;i<=n;i++){
		cin>>d[i];
	}
	for(int i=0;i<k;i++){
		x[i]=0;
		c[i]=0;
	}
	phan_tap(0,0,0);
	cout<<r%1000000007;
	return 0;
}
