#include<iostream>
#include<map>
using namespace std;
int x[7];
int N;
int Q=0;
int f=-62;
int c[7]={100,10,2,-100,1000,100,10};
void duyet(int s,int flag){
	if(s>6){
		if(f==N){
			Q++;
		}
		return;
	}
	for(int i=1;i<=9;i++){
		if((1<<i&flag)==0){
			x[s]=i;
			int t=c[s]*x[s];
			f+=t;
			duyet(s+1,flag|1<<i);
			f-=t;
		}
	}
}
int main(){
	cin>>N;
	duyet(0,0);
	cout<<Q;
	return 0;
}
