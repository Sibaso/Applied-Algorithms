#include<iostream>
#include<algorithm>
using namespace std;
int N,M;
int *pa;//phuong an
int *rb;//rang buoc
int*stt;
int dem=0;

bool check(int row,int col){
	if(rb[row]&1<<col)return false;
	for(int i=1;i<=N;i++){
		if(pa[i]==0)continue;
		if(pa[i]==col)return false;
		if(i-pa[i]==row-col)return false;
		if(i+pa[i]==row+col)return false;
	}
	return true;
}

void duyet(int i){
	if(i>N){
		dem++;
		return;
	}
	for(int j=1;j<=N;j++){
		if(check(stt[i],j)){
			pa[stt[i]]=j;
			duyet(i+1);
			pa[stt[i]]=0;
		}
	}
}

bool ss(int i,int j){
	return __builtin_popcount(rb[i])>__builtin_popcount(rb[j]);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(true){
		cin>>N>>M;
		if(N==0&&M==0)break;
		pa=new int[N+1];
		rb=new int[N+1];
		stt=new int[N+1];
		for(int i=1;i<=N;i++){
			pa[i]=0;
			rb[i]=0;
			stt[i]=i;
		}
		for(int i=0;i<M;i++){
			int row,col;
			cin>>row>>col;
			rb[row]=rb[row]|1<<col;
		}
		sort(stt+1,stt+N+1,ss);
		dem=0;
		duyet(1);
		cout<<dem<<"\n";
	}
	return 0;
}
