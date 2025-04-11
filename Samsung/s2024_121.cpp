#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int R, C, K;
vector < vector<pair<int, bool>>> map;
vector<int> dx = { -1, 1, 0, 0, 0 };
vector<int> dy = { 0, 0, 0, 1, -1 };
vector<int> dx_d = { -1, 0, 1, 0 };
vector<int> dy_d = { 0, 1, 0, -1 };

bool can_go(int x, int y, int num) {
	for (int i = 0; i < 5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx > R || ny > C || ny < 1)
			return false;

		if (nx > 0) {
			if (map[nx][ny].first != 0 && map[nx][ny].first != num)
				return false;
		}
	}
	return true;
}

void erase_map(int nx, int ny) {
	for (int i = 0; i < 5; i++) {
		if (nx + dx[i] >= 0 && nx + dx[i] <= R && ny + dy[i] >= 0 && ny + dy[i] <= C) {
			map[nx + dx[i]][ny + dy[i]].first = 0;
			map[nx + dx[i]][ny + dy[i]].second = 0;
		}
	}
}

void go_to(int nx, int ny, int num, int di) {
	for (int i = 0; i < 5; i++) {
		map[nx + dx[i]][ny + dy[i]].first = num;
	}
	map[nx + dx_d[di]][ny + dy_d[di]].second = true;
}

int go_south_max(int x, int y, int num) {
	vector<vector<bool>> visited(R + 1, vector<bool>(C + 1, 0));
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = 1;
	int max_r = x;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx_d[i];
			int ny = cy + dy_d[i];

			if (nx <= 0 || nx > R || ny <= 0 || ny > C) {
				continue;
			}

			//우주선 아닌 경우
			if (map[nx][ny].first == 0)
				continue;

			//다른 우주선
			if (map[cx][cy].first != map[nx][ny].first) {
				if (!map[cx][cy].second) //출구 아니면
					continue;
			}

			if (!visited[nx][ny]) {
				q.push({ nx, ny });
				visited[nx][ny] = 1;
				if (max_r < nx)
					max_r = nx;
			}

			if (max_r == R)
				return R;
		}
	}
	return max_r;
}

//c열로 출구가 d방향인 정령 등장
int move_on(int num, int c, int d) {
	bool is_move = true;
	int nx = -1;
	int ny = c;
	while (is_move) {
		is_move = false;

		//남쪽으로 이동
		if(!is_move && can_go(nx+1, ny, num)){
			nx++;
			is_move = true;
		}

		//서쪽으로 이동
		if(!is_move && can_go(nx+1, ny-1, num) && can_go(nx, ny-1, num)){
			nx++;
			ny--;
			if (d > 0) d--;
			else d = 3;
			is_move = true;
		}

		//동쪽으로 이동
		if (!is_move && can_go(nx + 1, ny + 1, num) && can_go(nx, ny+1, num)) {
			nx++;
			ny++;
			if (d < 3) d++;
			else d = 0;
			is_move = true;
		}
	}
	//밖으로 나갔는지 확인 -> 초기화
	for (int i = 0; i < 5; i++) {
		if (nx + dx[i] <= 0 || nx + dx[i] > R || ny + dy[i] <= 0 || ny + dy[i] > C) {
			//맵 초기화
			map.clear();
			map.assign(R + 1, vector<pair<int, bool>>(C + 1, { 0, 0 }));
			return 0;
		}
	}

	if (can_go(nx, ny, num))
		go_to(nx, ny, num, d);

	//최대한 남쪽으로 이동
	return go_south_max(nx, ny, num);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> R >> C >> K;
	map.assign(R+1, vector<pair<int, bool>>(C+1, { 0, 0 }));

	int c, d, ans=0;
	for (int i = 0; i < K; i++) {
		cin >> c >> d;
		ans += move_on(i + 1, c, d);
	}
	cout << ans << "\n";
	return 0;
}