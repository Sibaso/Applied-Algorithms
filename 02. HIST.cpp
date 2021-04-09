#include<iostream>
#include <queue>
using namespace std;
 
long long n;
long long* a;
 
int left(int i) {
	int j;
	for (j = i; j >= 0; j--) {
		if (a[j] < a[i])return j+1;
	}
	return 0;
}
 
int right(int i) {
	int j;
	for (j = i; j <n; j++) {
		if (a[j] < a[i])return j-1;
	}
	return n-1;
}
 
int main() {
	queue<long long> Q;
	while (1) {
		cin >> n;
		if (n == 0)break;
		Q.push(n);
		for (int i = 0; i < n; i++) {
			long long t;
			cin >> t;
			Q.push(t);
		}
	}
	while (!Q.empty()) {
		n = Q.front();
		Q.pop();
		a = new long long[n];
		long long max=0;
		for (int i = 0; i < n; i++) {
			a[i] = Q.front();
			Q.pop();
		}
		for (int i = 0; i < n; i++) {
			long long t = (right(i) - left(i) + 1) * a[i];
			if (max < t)max = t;
		}
		cout << max << endl;
	}
	return 0;
}
