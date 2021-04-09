#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string S;
int k;
char*ans;

bool ss(int i, int j){
	return S[i]>S[j];
}

//void duyet(int s,int cur){
//	if(s>=k){
//		for(int i=0;i<k;i++){
//			if(best_ans[i]<ans[i]){
//				for(int j=0;j<k;j++){
//					best_ans[i]=ans[i];
//				}
//				return;
//			}
//		}
//		return;
//	}
//	for(int i=cur;i<S.size();i++){
//		//cout<<S[i]<<endl;
//		ans[s]=S[i];
//		duyet(s+1,i+1);
//	}
//}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>S;
	cin>>k;
	ans=new char[k];
	int stt[S.size()];
	for(int i=0;i<S.size();i++){
		stt[i]=i;
	}
	sort(stt,stt+S.size(),ss);
	int cur=-1;
	int len =S.size();
	for(int j=0;j<k;j++){
		for(int i=0;i<len;i++){
			if(stt[i]>cur&&(len-stt[i])>(k-j-1)){
				ans[j]=S[stt[i]];
				cur=stt[i];
				break;
			}
		}
	}
		
	for(int i=0;i<k;i++)cout<<ans[i];
	return 0;
}
