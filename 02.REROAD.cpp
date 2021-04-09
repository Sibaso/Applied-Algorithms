#include<iostream>
using namespace std;
int main() {
	int N,Q;
	int* t;
	int* c;
	cin >> N;
	t = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> t[i];
	}
	cin >> Q;
	int count = 1;
	for (int j = 1; j < N; j++) {
		if (t[j] != t[j - 1])count++;
	}
	for (int i = 0; i < Q; i++) {
		int k;
		cin >> k;
		k--;
		int temp = t[k];
		cin >> t[k];
		if (k == 0) {
			if (temp == t[k + 1]) {
				if (t[k] != t[k + 1])count++;
			}
			else if (temp != t[k + 1]) {
				if (t[k] == t[k + 1])count--;
			}
		}
		else if (k == N - 1) {
			if (temp == t[k - 1]) {
				if (t[k] != t[k - 1])count++;
			}
			else if (temp != t[k - 1]) {
				if (t[k] == t[k - 1])count--;
			}
		}
		else {
			if (t[k - 1] == t[k + 1]) {
				if (temp == t[k - 1]) {
					if (t[k] != t[k - 1])count += 2;
				}
				else {
					if (t[k] == t[k - 1])count -= 2;
				}
			}
			else {
				if (temp != t[k - 1] && temp != t[k + 1]) {
					if (t[k] == t[k - 1])count--;
					if (t[k] == t[k + 1])count--;
				}
				else {
					if (t[k] != t[k - 1] && t[k] != t[k + 1])count++;
				}
			}
		}
		cout << count << endl;
	}
}
