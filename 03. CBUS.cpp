#include<iostream>
#include<map>
#include <algorithm>
using namespace std;
int n, k;
int ** c;
int minC;
int b = 0;
map<pair<int, int>, int>save;
bool *flag=new bool[n+1];

int duyet(unsigned int X, int p) {
	int i = __builtin_popcount(X);
	if (i == 2*n+1) return c[p][0];
	if (save[make_pair(X, p)] != 0) return save[make_pair(X, p)];
	int ans = 2e9;
	for (int s = 1; s <= 2*n; ++s)
		if ((X & (1 << s)) == 0 ) {
			if (s <= n) { 
				if (b + 1 > k) continue; 
				flag[s] = true; 
				b++; 
			}
			else { 
				if (flag[s - n] == false) continue; 
				b--; 
			}
			int t = c[p][s] + duyet(1 << s | X, s);
			if (ans > t)ans = t;
			if (s <= n) { 
				b--; 
				flag[s] = false; 
			} 
			else b++;
		}
	save[make_pair(X, p)] = ans;
	return ans;
}

int main() {
    cin >> n >> k;
	c = new int* [2*n+1];
	for (int i = 0; i <= 2*n; i++) {
		c[i] = new int[2*n+1];
		for (int j = 0; j <= 2*n; j++) {
			c[i][j] = 999999;
		}
	}
    for (int i = 0; i <= 2 * n; i++) {
		for (int j = 0; j <= 2 * n; j++) {
			cin >> c[i][j];
			if (minC > c[i][j])minC = c[i][j];
		}
	}
	for(int j=0;j<=n;j++){
		flag[j]=false;
	}
	cout << duyet(1, 0);
    return 0;
}
