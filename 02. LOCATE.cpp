#include<iostream>
#include <vector>
using namespace std;
int c[2000][2000];
int main() {
	int T;
	cin >> T;
	for (int z = 0; z < T; z++) {
		int L, C;
		cin >> L >> C;
		vector<pair<int, int>> map1;
		vector<pair<int, int>> map2;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < C; j++) {
				int t;
				cin >> t;
				if (t == 1) {
					map1.push_back(make_pair(i, j));
				}
			}
		}
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < C; j++) {
				int t;
				cin >> t;
				if (t == 1) {
					map2.push_back(make_pair(i, j));
				}
			}
		}
		int N = 0;
		for (int i = 0; i < 2000; i++) {
			for (int j = 0; j < 2000; j++) {
				c[i][j] = 0;
			}
		}
		for (int i = 0; i < map1.size(); i++) {
			pair<int, int> t1 = map1.at(i);
			for (int j = 0; j < map2.size(); j++) {
				pair<int, int> t2 = map2.at(j);
				int I = t1.first - t2.first;
				int J = t1.second - t2.second;
				c[I + 1000][J + 1000]++;
			}
		}
		for (int i = 0; i < 2000; i++) {
			for (int j = 0; j < 2000; j++) {
				if (N < c[i][j])N = c[i][j];
			}
		}
		cout << N << endl;
	}
	
	return 0;
}
