#include<iostream>
#include<map>
#include<stack>
#include <string>
using namespace std;
int main() {
	int t;
	cin >> t;
	map<char, char>m;
	stack<char>s;
	m[')'] = '(';
	m[']'] = '[';
	m['}'] = '{';
	for (int i = 0; i < t; i++) {
		string str;
		cin >> str;
		int correct = 1;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '(' || str[j] == '{' || str[j] == '[') {
				s.push(str[j]);
			}
			else {
				if (s.empty()) {
					correct = 0;
					break;
				}
				if(m[str[j]]==s.top())s.pop();
				else {
					correct = 0;
					break;
				}
			}
		}
		cout << correct << endl;
	}
	return 0;
}
