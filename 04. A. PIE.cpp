#include<iostream>
#include<cmath>
#include<algorithm>
#define M_PI   3.14159265358979323846264338327950288
using namespace std;
int N,F;
float *r;

bool p(double i){
	int c=0;
	for(int j=0;j<N;j++){
		c+=int(r[j]/i);
	}
	if(c>=F+1)return true;
	else return false;
}

int main(){
	int t;
	cin>>t;
	for(int z=0;z<t;z++){
		cin>>N>>F;
		r=new float[N];
		for(int i=0;i<N;i++){
			cin>>r[i];
			r[i]=M_PI*r[i]*r[i];
		}
		sort(r,r+N);
		double lo=0,hi=r[N-1];
		while(hi-lo>1e-6){
			double m=(hi+lo)/2.0;
			if(p(m))lo=m;
			else hi=m;
		}
		printf("%f\n",lo);	
	}
	return 0;
}
