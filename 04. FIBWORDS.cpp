#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
string p;

bool check(string s,string p,long long start){
	for(long long i=0;i<p.length();i++){
		if(s[i+start]!=p[i])return false;
	}
	return true;
}

string fn="1",fn_1="0";
long long cn=0,cn_1=0;
bool lock=false;
long long cax=0,cbx=0;
int k=0;

void solve(int n){
	if(n==0||n==1)return;
	solve(n-1);
	long long cn_2=cn_1;
	cn_1=cn;
	cn=cn_1+cn_2;
	if(!lock){
		string fn_2=fn_1;
		fn_1=fn;
		fn=fn_1+fn_2;
		if(fn.length()<p.length())return;
		if(fn_2.length()<p.length()){
			if(fn_1.length()<p.length()){
				for(long long i=0;i<fn.length()-p.length()+1;i++){
					if(check(fn,p,i))cn++;
				}
				return;
			}
			else{
				for(long long i=fn_1.length()-p.length()+1;i<fn.length()-p.length()+1;i++){
					if(check(fn,p,i))cn++;
				}
				return;
			}
		}
		else{
			lock=true;
			k=n;
			string a,b,x;
			x=fn_1.substr(0,p.length()-1);
			a=fn_1.substr(fn_1.length()+1-p.length());
			b=fn_2.substr(fn_2.length()+1-p.length());
			string ax=a+x,bx=b+x;
			for(long long i=0;i<ax.size();i++){
				if(check(ax,p,i))cax++;
				if(check(bx,p,i))cbx++;
			}
		}
	}
	if((n-k)%2==0){
		cn+=cax;
	}
	else{
		cn+=cbx;
	}
}

int main(){
	for (int i = 1, n; scanf("%d", &n) != EOF; i++) {
		fn="1";fn_1="0";
		cn=0;cn_1=0;
		lock=false;
		cax=0;cbx=0;
		k=0;
        cin >> p;
        if(p[0]=='0'&&p.length()==1)cn_1 = 1;
        if(p[0]=='1'&&p.length()==1)cn = 1;
        solve(n);
        cout << "Case " << i << ": " << cn << endl;
    }
	return 0;
}
