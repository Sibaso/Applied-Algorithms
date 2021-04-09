#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
long long n, k;
long long* x;
long long* m;
long long pg=0, ng=0;
 
bool ne_ss(int a,int b) {
	if (x[a] < x[b])return true;
	return false;
}
 
bool po_ss(int a, int b) {
	if (x[a] > x[b])return true;
	return false;
}
 
int main() {
	cin >> n >> k;
	x = new long long[n];
    m = new long long[n];
	vector<int>ne;
	vector<int>po;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> m[i];
		if (x[i] < 0)ne.push_back(i);
		else po.push_back(i);
	}
	sort(ne.begin(), ne.end(),ne_ss);
	sort(po.begin(), po.end(),po_ss);
 
	for (int i = 0; i < ne.size();i++) {
		long long t = abs(x[ne[i]]);
		if (m[ne[i]] >= k) {
			long long a = m[ne[i]] / k;
			m[ne[i]] = m[ne[i]] % k;
			ng += 2 * t * a;
		}
		if (m[ne[i]] == 0)continue;
		ng += 2 * t;
		long long d = k;
		while (i < ne.size() && d >= m[ne[i]] && m[ne[i]] != 0) {
			d -= m[ne[i]];
			m[ne[i]] = 0;
			i++;
		}
		if (i < ne.size()) {
			m[ne[i]] -= d;
			i--;
		}
	}
	for (int i = 0; i < po.size(); i ++ ) {
		if (m[po[i]] >= k) {
			long long a = m[po[i]] / k;
			m[po[i]] = m[po[i]] % k;
			ng += 2 * x[po[i]] * a;
		}
		if (m[po[i]] == 0)continue;
		pg += 2 * x[po[i]];
		long long d = k;
		while (i < po.size() && d >= m[po[i]] && m[po[i]]!=0) {
			d -= m[po[i]];
			m[po[i]] = 0;
			i++;
		}
		if (i < po.size()) {
			m[po[i]] -= d;
			i--;
		}
	}
	cout << pg + ng << endl;
	return 0;
}
