#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<iterator>
using namespace std;
int n,k,q;
int *d;//so goi hang yeu cau cua client
int *a;// dung tich dang chua trong xe
int **c;// distance
int r=10000;
set<int>* v;//danh sach duong di
set<set<set<int> > > se;//check phuong an trung nhau
map<pair<set<int>,int>, int> save;//luu cac gia tri da tinh;
map<int,int> m;//luu cac gia tri da tinh

int TSP(set<int> v, int p) {
	if (v.size()==0) return c[p][0];
	if (save[make_pair(v,p)] != 0) return save[make_pair(v,p)];
	int ans = 2e9;
	for(set<int>::iterator s = v.begin(); s != v.end(); s++){
		set<int>z=v;
		z.erase(*s);
		int t = c[p][*s] + TSP(z,*s);
		if (ans > t)ans = t;
	}
	save[make_pair(v,p)] = ans;
	return ans;
}

void phan_tap(int s,int X,int last){
	if(s>=k){
		if(__builtin_popcount(X)==n){
			set<set<int> >t;
			for(int i=0;i<k;i++){
				t.insert(v[i]);
			}
			if(se.find(t)==se.end()){
				se.insert(t);
				int y=0;
				for(int i=0;i<k;i++){
					y+=TSP(v[i],0);
				}
				if(r>y)r=y;
			}
		}
		return;
	}
	for(int i=last+1;i<=n;i++){
		if((1<<i&X)==0 && a[s]+d[i]<=q){
			a[s]+=d[i];
			v[s].insert(i);
			phan_tap(s+1,X|1<<i,0);
			phan_tap(s,X|1<<i,i);
			v[s].erase(i);
			a[s]-=d[i];
		}
	}
}


int main(){
	cin>>n>>k>>q;
	d=new int[n+1];
	c=new int*[n+1];
	a=new int[k];
	v=new set<int>[k];
	for(int i=1;i<=n;i++){
		cin>>d[i];
	}
	for(int i=0;i<=n;i++){
		c[i]=new int[n+1];
		for(int j=0;j<=n;j++){
			cin>>c[i][j];
		}
	}
	for(int i=0;i<k;i++){
		a[i]=0;
	}
	phan_tap(0,0,0);
	cout<<r;
	return 0;
}
