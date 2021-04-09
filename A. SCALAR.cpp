#include<iostream>
using namespace std;
int n;
int *x,*y,*z;
bool *flag;
long long ans=1e9;
long long f=0;
int miny;
int minx;
long long temp;

void duyet(int s){
	if(s>=n){
		if(ans>f)ans=f;
		return;
	}
	for(int i=0;i<n;i++){
		if(!flag[i]){
			z[s]=y[i];
			flag[i]=true;
			long long t=z[s]*x[s];
			f+=t;
			if(f+temp*(n-s-1))duyet(s+1);
			f-=t;
			flag[i]=false;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		x=new int[n];
		y=new int[n];
		z=new int[n];
		flag=new bool[n];
		minx=1e5;
		for(int j=0;j<n;j++){
			flag[j]=false;
			cin>>x[j];
			if(minx>x[j])minx=x[j];
		}
		//miny=10e5;
		for(int j=0;j<n;j++){
			cin>>y[j];
			if(miny>y[j])miny=y[j];
		}
		temp=minx*miny;
		f=0;
		ans=1e9;
		duyet(0);
		cout<<"Case #"<<i<<": "<<ans<<"\n";
	}
	return 0;
}
