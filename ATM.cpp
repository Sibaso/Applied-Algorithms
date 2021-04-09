#include<iostream>
#include<string.h>
#include<map>
#include<vector>
#include<math.h>
using namespace std;
long long w,c,n,s;
int a[]={1000,2000,3000,5000};
long long duyet(int k,long long h){
	if(k==0||h==0)return 0;
	long long ans=0;
	for(int i=c;i>=0;i--){
		for(int j=3;j>=0;j--){
			ans=min	
		}
	}
}
int main(){
	int T;
	cin>>T;
	for(int t=0;t<T;t++){
		cin>>w>>c;
		n=0;
		long long W=w;
		for(int i=c;i>=0;i--){
			for(int j=3;j>=0;j--){
				int temp=W/(a[j]*pow(10,i));
				n+=temp;
				W%=(int)(a[j]*pow(10,i));
			}
		}
		s=0;
		//duyet(0,0);
		cout<<n<<" "<<s<<endl;
	}
	return 0;
}
