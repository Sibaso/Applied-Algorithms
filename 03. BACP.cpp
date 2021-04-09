#include<iostream>
#include<map>
using namespace std;
int n, m;
int* c;// tin chi mon i
map<int, int>before;//before[j]=i, truoc khi hoc j phai hoc i
int* b;//nhung mon co trong ki i
int* d;// tong tin chi hien tai trong ki i
int g=(1<<31)-1;//ham muc tieu

void duyet(int X,int s){
	if(s>n){
		int maxLoad = 0;
		for (int i = 1; i <= m; i++) {
			if (maxLoad < d[i])maxLoad = d[i];
		}
		if (g > maxLoad)g = maxLoad;
		return; 
	}
	if((1<<s&X))return;
	for(int i=1;i<=m;i++){
		bool ok = true;
		if (before[s] != 0) {
			ok = false;
			for (int j = 1; j < i; j++)
				if (1 << before[s] & b[j]) {
					ok = true;
					break;
				}
		}
		if (ok) {
			int t = b[i];
			d[i] += c[s];
			b[i] = b[i] | 1 << s;
			duyet(X | 1 << s, s + 1);
			d[i] -= c[s];
			b[i] = t;
		}
	}
}

int main() {
	cin >> n >> m;
	c = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int t;
			cin >> t;
			if (t == 1){
				if(i>j){
					int z=c[i];
					c[i]=c[j];
					c[j]=z;
					before[i]=j;
				}
				else before[j] = i;
			}
		}
	}
	b = new int[m+1];
	d = new int[m+1];
	for (int i = 1; i <= m; i++) {
		b[i] = 1;
		d[i] = 0;
	}
	
	duyet(0,1);
	
	cout<<g;
	return 0;
}
