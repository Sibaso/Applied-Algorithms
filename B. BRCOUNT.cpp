#include<iostream>
using namespace std;
string s;
int dem=0;
long long cach=0;
void duyet(int i){
	if(i>=s.size()){
		if(dem!=0)return;
		cach++;
		return;
	}
	if(dem<0)return;
	if(s[i]=='('){
		dem++;
		duyet(i+1);
		dem--;
	}
	else if(s[i]=='?'){
		dem++;
		duyet(i+1);
		dem-=2;
		duyet(i+1);
		dem++;
	}
	else if(s[i]==')'){
		dem--;
		duyet(i+1);
		dem++;
	}
}

int main(){
	cin>>s;
	
	duyet(0);
	cout<<cach;
	return 0;
}
