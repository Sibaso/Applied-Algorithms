#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,K;
int *l,*r;
int *stt;
int best=0;
vector<bool> flag;
vector<bool> selected;

void duyet(int t){
	if(t>=K-2){
		int dem=0;
		for(int i=0;i<N;i++){
			if(flag[i])dem++;
		}
		if(best<dem)best=dem;
		return;
	}
	for(int i=0;i<K;i++){
		if(selected[i])continue;
		selected[i]=true;
		for(int j=l[i];j<=r[i];j++){
			flag[j]=true;
		}
		duyet(t+1);
		selected[i]=false;
		for(int j=l[i];j<=r[i];j++){
			flag[j]=false;
		}
	}
}

bool ss(int i,int j){
	return l[i]<l[j];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>K;
	l=new int[K];
	r=new int[K];
	flag=vector<bool>(N,false);
	selected=vector<bool>(K,false);
	for(int i=0;i<K;i++){
		cin>>l[i]>>r[i];
		l[i]--;
		r[i]--;
	}
	duyet(0);
	cout<<best;
	return 0;
}
