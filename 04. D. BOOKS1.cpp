#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
int m,k;
long long *p,*c;
bool found = false;

void in(int a, int b, long long maxval){
	if(b<0)return;
	if(a<0){
		for(int i=0;i<k;i++){
			if(c[i]==0)return;
		}
		found = true;
		long long sum = 0;
		int j=0;
		for(int i=0;i<m;i++){
			if(sum+p[i]<=c[j]){
				cout<<p[i]<<" ";
				sum+=p[i];
			}
			else{
				cout<<"/ ";
				sum=0;
				j++;
				i--;
			}
		}cout<<endl;
		return;
	}
	if(found)return;
	if(c[b]+p[a]<=maxval){
		c[b]+=p[a];
		in(a-1,b,maxval);
		c[b]-=p[a];
	}
	in(a,b-1,maxval);
}

bool check(long long maxval){
	long long sum=0;
	int dem=0;
	for(int i=m-1; i>=0; i--){
		if(sum+p[i]<=maxval){
			sum+=p[i];
		}
		else{
			sum = p[i];
			if(p[i]>maxval)return false;
			dem++;
		}
	}
	if(dem>=k)return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin>>T;
	for(int t; t<T;t++){
		found = false;
		cin>>m>>k;
		p=new long long[m];
		c=new long long[k];
		long long MAX;
		for(int i=0; i<k; i++)c[i]=0;
		for(int i=0;i<m;i++){
			cin>>p[i];
			MAX+=p[i];
		}
		long long lo=0,hi=MAX;
		while(hi>lo){
			long long mi=(hi+lo)/2;
			if(check(mi)){
				hi=mi;
			}
			else{
				lo=mi+1;
			}
		}
		in(m-1,k-1,hi);
	}
	return 0;
}
