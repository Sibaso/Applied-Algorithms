#include<iostream>
#include<algorithm>
using namespace std;
int n;
int *s,*t,*I,*c;

int duyet(int i){
	int ans=-1;
	for(int j=0;j<i;j++){
		if(t[I[j]]<s[I[i]]){
			ans=max(ans,c[I[j]]+c[I[i]]);
		}
	}
	return ans;
}

bool ss(int i,int j){
	return c[i]>c[j];
}
int main(){ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	s=new int[n];
	t=new int[n];
	I=new int[n];
	c=new int[n];
	for(int i=0;i<n;i++){
		cin>>s[i]>>t[i];
		I[i]=i;
		c[i]=t[i]-s[i];
	}
	sort(I,I+n,ss);
	for(int i=0;i<n;i++){
		cout<<I[i]<<" "<<c[I[i]]<<endl;
	}
	return 0;
}
