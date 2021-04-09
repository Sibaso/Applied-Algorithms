#include<iostream>
using namespace std;
int n, b;
int* a, * c;
int best=0;
int maxAVW=0;
void duyet(int i, int sum, int val) {
	if (i >= n) {
		if (val > best)best = val;
		return;
	}
	duyet(i + 1, sum, val);
	if (sum + a[i] <= b && val + c[i] + maxAVW*(b - sum - a[i])>best)
		duyet(i + 1, sum + a[i], val + c[i]);
}
int main() {
	cin >> n>> b;
	a = new int[n];
	c = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> c[i];
		if (maxAVW < (c[i] / a[i]))maxAVW = c[i] / a[i];
	}
	duyet(0, 0, 0);
	cout << best;
	return 0;
}
