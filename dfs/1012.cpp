#include<iostream>
#include<algorithm>
#include<vector>

#define MAX 55

using namespace std;

vector<pair<int, int>> cabbage_pos; //배추위치저장

int visited[MAX][MAX]; //방문표시
int map[MAX][MAX];

int dx[4] = { 1,-1,0,0 }; //4방향
int dy[4] = { 0,0,1,-1 };

int answer;
int m, n, k;

void dfs(int x, int y) { //dfs
	visited[y][x] = 1; //방문표시

	for (int i = 0; i < 4; i++) { //4방향으로 돌면서
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (xx<0 || xx>=m || yy < 0 || yy >= n) {
			continue; //범위이탈
		}
		if (map[yy][xx] == 1 && visited[yy][xx] == 0) {
			dfs(xx, yy); //지도에있는데 방문안함>연결되어있음
		}
	}
}

int main() {
	int testcase;
	cin >> testcase;

	for (int t = 0; t < testcase; t++) {
		cin >> m >> n >> k;
		cabbage_pos.clear();
		answer = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j] = 0;
				visited[i][j] = 0;
			}
		}
		for (int i = 0; i < k; i++) {
			int x, y;

			cin >> x >> y;
			map[y][x] = 1;

			cabbage_pos.push_back({ x, y });
		}
		for (int i = 0; i < cabbage_pos.size(); i++) {
			if (visited[cabbage_pos[i].second][cabbage_pos[i].first]) {
				continue; //이미 가본장소
			}
			dfs(cabbage_pos[i].first, cabbage_pos[i].second);
			//dfs가 재귀호출되므로 한 뭉텅이가 끝날때까지 나오지 않음
			answer++; //뭉텅이 한개 표시
		}
		cout << answer << "\n";
	}
