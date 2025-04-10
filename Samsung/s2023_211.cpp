#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
int l, n, q;
struct person {
	int r, c, h, w, k;
};
vector<vector<int>> map;
vector<vector<int>> warrior;
vector<person> info;
vector<int> get_answer;
vector<int> dx = { -1, 0, 1, 0 };
vector<int> dy = { 0, 1, 0, -1 };

void get_penalty(int t) {
	int p = 0;
	for (int a = 0; a < info[t].h; a++) {
		for (int b = 0; b < info[t].w; b++) {
			if (map[info[t].r + a][info[t].c + b] == 1) {
				p++;
			}
		}
	}
	info[t].k -= p;
	return;
}


//i번 병사를 d 방향으로 이동
void move_s(int i, int d) {
	//정보 갱신
	info[i].r += dx[d];
	info[i].c += dy[d];

	for (int a = 0; a < info[i].h; a++) {
		for (int b = 0; b < info[i].w; b++) {
			warrior[info[i].r + a][info[i].c + b] = i;
		}
	}
	return;
}

void move_warrior(int i, int d) {
	vector<bool> is_move(n + 1, 0);
	queue<int> q;

	//죽은 경우
	if (info[i].k <= 0)
		return;

	//움직여야 하는 기사 확인
	q.push(i);
	is_move[i] = 1;
	while (!q.empty()) {
		int cn = q.front();
		q.pop();

		for (int a = 0; a < info[cn].h; a++) {
			for (int b = 0; b < info[cn].w; b++) {
				int nr = info[cn].r + a + dx[d];
				int nc = info[cn].c + b + dy[d];

				//밖으로 나갈 수 없음
				if (nr < 1 || nr > l || nc< 1 || nc > l)
					return;

				//벽을 만났을 경우
				if (map[nr][nc] == 2)
					return;
				
				int nx = warrior[nr][nc];
				if (nx != 0 && !is_move[nx] && info[nx].k >0) {
					is_move[nx] = 1;
					q.push(nx);
				}
			}
		}
	}

	for (int a = 0; a < l + 1; a++){
		for (int b = 0; b < l + 1; b++) {
			warrior[a][b] = 0;
		}
	}
	for (int a = 1; a < n + 1; a++) {
		//움직여줘야 하는 병사들
		if (is_move[a]) {
			move_s(a, d);
			if (a != i) {
				get_penalty(a); //a 번 병사의 패널티
			} 
		}
		else if(info[a].k > 0) {
			for (int m = 0; m < info[a].h; m++) {
				for (int n = 0; n < info[a].w; n++) {
					warrior[info[a].r + m][info[a].c + n] = a;
				}
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> l >> n >> q;
	map.assign(l+1, vector<int>(l+1, 0));
	warrior.assign(l+1, vector<int>(l+1, 0));

	for (int i = 1; i < l+1; i++) {
		for (int j = 1; j < l+1; j++) {
			cin >> map[i][j];
		}
	}

	int r, c, w, h, k;
	info.push_back({ -1,-1,-1,-1,-1 }); // 더미 데이터
	get_answer.push_back(-1);
	for (int i = 1; i < n+1; i++) {
		cin >> r >> c >> h >> w >> k;
		for (int a = 0; a < h; a++) {
			for (int b = 0; b < w; b++) {
				warrior[r + a][c + b] = i;
			}
		}
		info.push_back({ r, c, h, w, k });
		get_answer.push_back(k);
	}

	for (int i = 0; i < q; i++) {
		cin >> r >> c; //r번 기사를 c방향으로 이동
		move_warrior(r, c);
	}

	int ans=0;
	for (int i = 1; i < n + 1; i++) {
		if(info[i].k > 0)
			ans += get_answer[i] - info[i].k;
	}
	cout << ans << '\n';
	return 0;
}