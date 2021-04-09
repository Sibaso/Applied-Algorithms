#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int w = a[0];
	int temp = a[0];
	for (int i = 1; i < n; i++) {
		temp += a[i];
		if (temp < a[i])temp = a[i];
		if (w < temp)w = temp;
	}
	cout << w << endl;
	return 0;
}
