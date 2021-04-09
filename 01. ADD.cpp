#include<iostream>
#include <stack>
using namespace std;
int main() {
	string a, b, s;
	stack<char> c;
	int buffer = 0;
	cin >> a >> b;
	int i;
	for (i = 0;; i++) {
		if (i >= a.length()) {
			s = b;
			break;
		}
		if (i >= b.length()) {
			s = a;
			break;
		}
		int k = a[a.length() - 1 - i] - 48 + b[b.length() - 1 - i] - 48 + buffer;
		if (k > 9) {
			buffer = 1;
			k = k - 10;
		}
		else buffer = 0;
		k += 48;
		c.push(k);
	}
	for (i; i < s.length(); i++) {
		int k = s[s.length() - 1 - i] - 48 + buffer;
		if (k > 9) {
			buffer = 1;
			k = k - 10;
		}
		else buffer = 0;
		k += 48;
		c.push(k);
	}
	if (buffer)c.push('1');
	while (!c.empty()) {
		cout << c.top();
		c.pop();
	}
	cout << endl;
	return 0;
}
