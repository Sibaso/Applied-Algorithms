#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int N;
	int *t;
	cin>>N;
	t=new int[N];
	for(int i=0;i<N;i++){
		cin>>t[i];
	}
	sort(t,t+N);
	long long max_day=0;
	int cur_day = 0;
	for(int i=N-1;i>=0;i--){
		cur_day++;
		if(max_day<cur_day+t[i]){
			max_day=cur_day+t[i];
		}
	}
	cout<<max_day+1;
	return 0;
}
