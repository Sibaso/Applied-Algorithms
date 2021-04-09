#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int n, m;
int* c;//cac mon gv i co the day
int* d;// cac mon khong duoc day khi co mon i
int* a;//nhung mon hoc gv i day
int* b;//nhung mon ho gv i ko dc day
int* e;//so giao vien co the day duoc mon i
int* stt;// thu tu duyet
int g;


void duyet(int s) {
	if (s > n) {
		int maxLoad = 0;
		for (int i = 1; i <= m; i++) {
			int t = __builtin_popcount(a[i]);
			if (maxLoad < t)maxLoad = t;
		}
		if (g > maxLoad)g = maxLoad;
		return;
	}
	for (int i = 1; i <= m; i++) {
		if (1 << stt[s] & c[i] && (1 << stt[s] & b[i]) == 0) {
			int ta = a[i];
			int tb = b[i];
			a[i] = a[i] | 1 << stt[s];
			b[i] = b[i] | 1 << stt[s];
			b[i] = b[i] | d[stt[s]];
			duyet(s + 1);
			a[i] = ta;
			b[i] = tb;
		}
	}
}

bool ss(int i,int j){
	if(e[i]<e[j])return true;
	else return false;
}

int main() {
	cin >> m >> n;
	c = new int[m + 1];
	d=new int[n+1];
	g = n;
	e=new int[n+1];
	stt=new int[n+1];
	for(int i=1;i<=n;i++){
		d[i]=0;
		e[i]=0;
		stt[i]=i;
	}
	for (int i = 1; i <= m; i++) {
		int k;
		cin >> k;
		c[i] = 0;
		for (int j = 1; j <= k; j++) {
			int x;
			cin >> x;
			e[x]++;
			c[i] = c[i] | 1 << x;
		}
	}
	int k;
	cin >> k;
	for (int t = 0; t < k; t++) {
		int i, j;
		cin >> i >> j;
		d[i] = d[i] | 1 << j;
		d[j] = d[j] | 1 << i;
	}
	a = new int[m + 1];
	b = new int[m + 1];
	for (int i = 1; i <= m; i++) {
		a[i] = 0;
		b[i] = 0;
	}
	sort(stt+1,stt+n+1,ss);
	duyet(1);
	cout << g;
}
