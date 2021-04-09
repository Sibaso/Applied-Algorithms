#include<iostream>
#include <queue>
using namespace std;
queue<pair<int,int>>q;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	bool** visited = new bool*[a + 1];
	int** d = new int* [a + 1];
	for (int i = 0; i < a + 1; i++) {
		visited[i] = new bool[b + 1];
		d[i] = new int[b + 1];
		for (int j = 0; j < b + 1; j++) {
			visited[i][j] = false;
		}
	}
	q.push(make_pair(0, 0));
	d[0][0] = 0;
	while (!q.empty()) {
		pair<int, int> t = q.front();
		q.pop();
		visited[t.first][t.second] = true;
		if (!visited[0][t.second]) {
			q.push(make_pair(0, t.second));
			d[0][t.second] = d[t.first][t.second] + 1;
		}
		if (!visited[a][t.second]) {
			q.push(make_pair(a, t.second));
			d[a][t.second] = d[t.first][t.second] + 1;
		}
		if (!visited[t.first][0]) {
			q.push(make_pair(t.first, 0));
			d[t.first][0] = d[t.first][t.second] + 1;
			q.push(make_pair(t.first, b));
		}
		if (!visited[t.first][b]) {
			q.push(make_pair(t.first, b));
			d[t.first][b] = d[t.first][t.second] + 1;
		}
		
		int i = t.first - min(t.first, b - t.second);
		int j = t.second + min(t.first, b - t.second);
		if (!visited[i][j]) {
			q.push(make_pair(i, j));
			d[i][j] = d[t.first][t.second] + 1;
			if (i == c || j == c) {
				cout << d[i][j];
				break;
			}
		}
		
		i = t.first + min(a - t.first, t.second);
		j = t.second - min(a - t.first, t.second);
		if (!visited[i][j]) {
			q.push(make_pair(i, j));
			d[0][i, j] = d[t.first][t.second] + 1;
			if (i == c || j == c) {
				cout << d[i][j];
				break;
			}
		}
	}
}
