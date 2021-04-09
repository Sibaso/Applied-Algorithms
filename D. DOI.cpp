#include<iostream>
using namespace std;
int n;
int *a;

void duyet(int s){
	
}

int main(){
	cin>>n;
	a=new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int tt=0;
	int d1=0,d2=0;
	int t1=0,t2=0;
	int dem=0;
	int bestD=0,bestT=0;
	for(int i=1;i<n;i++){
		if(a[i]<a[i-1]){
			if(tt==1){
				d1=dem;
				t2=dem;
				if(t1!=0){
					int temp=min(t1,t2);
					if(bestT<temp)bestT=temp;
				}
				t1=0;
				tt=-1;
				dem=1;
			}
			else if(tt==-1){
				dem++;
			}
			else{
				tt=-1;
				dem=1;
			}
		}
		else if(a[i]>a[i-1]){
			if(tt==-1){
				t1=dem;
				d2=dem;
				if(d1!=0){
					int temp=min(d1,d2);
					if(bestD<temp)bestD=temp;
				}
				d1=0;
				tt=1;
				dem=1;
			}
			else if(tt==1){
				dem++;
			}
			else{
				tt=1;
				dem=1;
			}
		}
		else{
			if(tt==1){
				d1=0;
				t2=dem;
				if(t1!=0){
					int temp=min(t1,t2);
					if(bestT<temp)bestT=temp;
				}
				dem=0;
				tt=0;
			}
			else if(tt==-1){
				d2=dem;
				t1=0;
				dem=0;
				if(d1!=0){
					int temp=min(d1,d2);
					if(bestD<temp)bestD=temp;
				}
				tt=0;
			}
		}
	}
	if(tt=1&&d1!=0){
		int temp=min(d1,dem);
		if(bestD<temp)bestD=temp;
	}else if(tt=-1&&t1!=0){
		int temp=min(t1,dem);
		if(bestT<temp)bestT=temp;
	}
	cout<<bestD<<" "<<bestT;
	return 0;
}
