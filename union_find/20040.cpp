#include<iostream>
using namespace std;

int parent[500050];
int n,m,a,b;

int find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	parent[y] = x;
}

int isUnion(int x, int y) { //집합인지 확인하는 것 안쓰임
	x = find(x);
	y = find(y);
	if (x == y) return true;
	return false;
}

int main() {
	cin >> n >> m;
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		if (find(a)==find(b)) {
			cout << i;
			return 0;
		}
		merge(a, b);
	}
	cout << 0;
}
