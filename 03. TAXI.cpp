#include<iostream>
#include<map>
using namespace std;
int n;
int** c;
int minC;
map<pair<int, int>, int>save;

int duyet(unsigned int X, int p) {
	int i = __builtin_popcount(X);
	if (i == n+1) return c[p][p+n]+c[p+n][0];
	if (save[make_pair(X, p)] != 0) return save[make_pair(X, p)];
	int ans = 2e9;
	for (int s = 1; s <= n; ++s)
		if ((X & (1 << s)) == 0) {
			int t = c[p][p+n]+c[p+n][s] + duyet(1 << s | X, s);
			if (ans > t)ans = t;
		}
	save[make_pair(X, p)] = ans;
	return ans;
}

int main(){
	cin >> n;
	c = new int* [2 * n + 1];
	for (int i = 0; i <= 2 * n; i++) {
		c[i] = new int[2 * n + 1];
		for (int j = 0; j <= 2 * n; j++) {
			c[i][j] = 999999;
		}
	}
	for (int i = 0; i <= 2 * n; i++) {
		for (int j = 0; j <= 2 * n; j++) {
			cin >> c[i][j];
		}
	}
	cout << duyet(1, 0);
	return 0;
}
