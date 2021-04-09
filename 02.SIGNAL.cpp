#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int> v;
	int n, b;
	int* a;
	cin >> n >> b;
	a = new int[n];
	cin >> a[0];
	v.push_back(a[0]);
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		int l = v.size();
		for (int j = 0; j < l; j++) {
			if (v[j] < a[i]) {
				v.insert(v.begin() + j, a[i]);
				break;
			}
		}
		if (l == v.size())v.push_back(a[i]);
	}
	int c = 0;
	if (a[0] == v[0])c++;
	int maxLeft = 0, maxRight = v[c];
	int g = maxLeft - a[0] + maxRight - a[0];
	bool is2 = false;
	for (int i = 1; i < n; i++) {
		if (a[i-1] > maxLeft)maxLeft = a[i-1];
		if (a[i] == maxRight)maxRight = v[++c];
		int tl = maxLeft - a[i];
		int tr = maxRight - a[i];
		if (tl >= b && tr >= b) {
			is2 = true;
			int tg = tl + tr;
			if (g < tg)g = tg;
		}
	}
	if (is2)cout << g << endl;
	else cout << -1 << endl;
}
