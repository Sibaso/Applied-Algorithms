#include<iostream>
#include <algorithm>
#include <map>
using namespace std;
int m, n;
int minC = 999999;
int** c;
map<pair<int, int>, int>save;

int duyet(unsigned int X, int p) {
	int i = __builtin_popcount(X);
	if (i == n) return c[p][0];
	if (save[make_pair(X, p)] != 0) return save[make_pair(X, p)];
	int ans = 2e9;
	for (int s = 0; s < n; ++s)
		if ((X >> s & 1) == 0 && c[p][s] + minC * (n - i) < ans) {
			int t = c[p][s] + duyet(1 << s | X, s);
			if (ans > t)ans = t;
		}
	save[make_pair(X, p)] = ans;
	return ans;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	c = new int* [n];
	for (int i = 0; i < n; i++) {
		c[i] = new int[n];
		for (int j = 0; j < n; j++) {
			//c[i][j] = 999999;
			cin>>c[i][j];
			if(i!=j){
                minC = min(c[i][j],minC);
			}
		}
	}
	cout << duyet(1, 0);
	return 0;
}
