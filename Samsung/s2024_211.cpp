#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M, F;
struct s {
	int r, c, d, v;
	bool can_spread;
};
vector<s> strange;
vector<vector<int>> space;
vector<vector<int>> wall;
pair<int, int> exit_;
pair<int, int> wall_start;
pair<int, int> wall_end;
pair<int, int> machine;
pair<int, int> to_go_space;
pair<int, int> to_go_wall;
vector<int> dx = { -1, 1, 0, 0 };
vector<int> dy = { 0, 0, 1, -1 };

//������ ���� ���� �ϴ°�
bool where_to_go_space() {
	for(int cx = wall_start.first; cx <= wall_end.first; cx++){
		for (int cy = wall_start.second; cy <= wall_end.second; cy++) {
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];

				if (nx < 1 || nx > N || ny < 1 || ny > N)
					continue;

				if (space[nx][ny] == 0) {
					to_go_space = { nx, ny };
					return true;
				}
			}
		}
	}
	return false;
}

bool where_to_go_wall() {
	int dx = to_go_space.first - wall_start.first;
	int dy = to_go_space.second - wall_start.second;
	//����
	if (wall_start.first > to_go_space.first) {
		to_go_wall = { M, 4 * M - dy };
		return true;
	}

	//����
	if (wall_end.first < to_go_space.first) {
		to_go_wall = { M,  M + 1 + dy };
		return true;
	}

	//����
	if (wall_start.second > to_go_space.second) {
		to_go_wall = { M, dx + 1 };
		return true;
	}

	//����
	else if (wall_end.second < to_go_space.second) {
		to_go_wall = {M, 2 * M + (M-dx) };
		return true;
	}
	return false;
}

//�������� �ִ� �Ÿ� ���ϱ�
int move_wall(){
	//Ż�� �Ұ�
	if (!where_to_go_space())
		return -1;
	if (!where_to_go_wall())
		return -1;

	//cout << to_go_space.first << ' ' << to_go_space.second << "\n";
	//cout << to_go_wall.first << ' ' << to_go_wall.second << "\n";

	queue<pair<int, int>> q;
	q.push(machine);
	wall[machine.first][machine.second] = 1;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx > M + 1 || ny < 0 || ny > 5 * M + 1)
				continue;

			if (nx >= M + 1 && ny >= 0 && ny <= 4 * M)
				continue;

			if (nx == 0) {
				nx++;
				//���� -> ��
				if (ny >= 2 * M + 1 && ny <= 3 * M) {
					nx = ny - 2 * M;
					ny = 5 * M;
				}

				//���� -> ��
				else if (ny >= M + 1 && ny <= 2 * M) {
					nx = M;
					ny += 3 * M;
				}

				//���� -> ��
				else if (ny >= 1 && ny < M) {
					nx = ny;
					ny = 4 * M + 1;
				}

				//���� -> ��
				else if (ny >= 3 * M + 1 && ny < 4 * M) {
					nx = 1;
					ny = 8 * M + 1 - ny;
				}

				//�� -> ��
				else if (ny >= 4 * M + 1 && ny <= 5 * M) {
					ny = 8 * M + 1 - ny;
					nx = 1;
				}
			}

			//�� -> ��
			else if (ny == 4 * M + 1 && i == 2) {
				ny = 1;
			}

			//�� -> ��
			else if (ny ==  0 && i==3) {
				ny = 4 * M;
			}

			//�� -> ��
			else if (ny == 5*M+1) {
				ny = 3 * M - nx + 1;
				nx = 1;
			}

			//�� -> ��
			else if (nx == M + 1) {
				nx = 1;
				ny -= 3 * M;
			}

			//��->��
			else if (ny == 4 * M && i == 3) {
				ny = nx;
				nx = 1;
			}

			//������ ����
			if (nx == to_go_wall.first && ny == to_go_wall.second) {
				return wall[cx][cy];
			}

			if (wall[nx][ny] == 0 ) {
				wall[nx][ny] = wall[cx][cy] + 1;
				q.push({ nx, ny });
			}
		}
	}
	return -1;

}

//�̻� ���� ��Ʈ����
void spread(int turn) {
	vector<int> dxs = { 0, 0, 1, -1 };
	vector<int> dys = { 1, -1, 0, 0 };
	for (int i = 0; i < F; i++) {
		if (!strange[i].can_spread)
			continue;

		if (turn % strange[i].v == 0) {
			strange[i].r += dxs[strange[i].d];
			strange[i].c += dys[strange[i].d];

			if (strange[i].r < 1 || strange[i].r > N || strange[i].c < 1 || strange[i].c > N || space[strange[i].r][strange[i].c] == -1) {
				strange[i].can_spread = 0;
				continue;
			}

			space[strange[i].r][strange[i].c] = -2;
		}
	}
}

//���������� �ִ� �Ÿ� ���ϱ�
int move_space(int num) { 
	queue<pair<int, int>> q;
	q.push(to_go_space);
	space[to_go_space.first][to_go_space.second] = num;

	while (!q.empty()) {
		int size_q = q.size();
		spread(num++);
		while (size_q--) {
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];

				if (nx < 1 || nx > N || ny <1 || ny>N)
					continue;

				if (nx == exit_.first && ny == exit_.second) {
					return space[cx][cy] + 1;
				}

				if (space[nx][ny] == 0 && space[cx][cy] == num-1) {
					q.push({ nx, ny });
					space[nx][ny] = space[cx][cy] + 1;
				}

			}
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M >> F;
	space.assign(N + 1, vector<int>(N + 1, 0));
	wall.assign(M + 2, vector<int>(5 * M + 2, 0));
	
	int x;
	bool start = true;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> x;
			//Ż�ⱸ
			if (x == 4) {
				exit_ = { i,j };
				space[i][j] = 0;
			}

			//�ð��� ��
			else if (x == 3) {
				if (start) {
					wall_start = { i,j };
					start = 0;
				}
				else
					wall_end = { i, j };
				space[i][j] = -1;
			}

			//��ֹ�
			else if(x == 1)
				space[i][j] = -1;
		}
	}
	
	//����
	for (int i = 1; i <= M; i++) {
		for (int j = 2 * M + 1; j <= 3 * M; j++) {
			cin >> x;
			if (x == 1)
				wall[i][j] = -1;
		}
	}

	//����
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> x;
			if (x == 1)
				wall[i][j] = -1;
		}
	}
	
	//����
	for (int i = 1; i <= M; i++) {
		for (int j = M + 1; j <= 2 * M; j++) {
			cin >> x;
			if (x == 1)
				wall[i][j] = -1;
		}
	}

	//����
	for (int i = 1; i <= M; i++) {
		for (int j = 3 * M + 1; j <= 4 * M; j++) {
			cin >> x;
			if (x == 1)
				wall[i][j] = -1;
		}
	}

	//����
	for (int i = 1; i <= M; i++) {
		for (int j = 4 * M + 1; j <= 5 * M; j++) {
			cin >> x;
			if (x == 1)
				wall[i][j] = -1;
			if (x == 2){
				machine = { i, j };
			}
		}
	}

	int a, b, c;
	for (int i = 0; i < F; i++) {
		cin >> a >> b >> c >> x;
		strange.push_back({ a+1, b+1, c, x, 1 });
		space[a + 1][b + 1] = -2;
	}

	/*cout << machine.first << ' ' << machine.second << "\n";*/
	int A = move_wall();
	if (A <= 0) {
		cout << -1 << "\n";
		return 0;
	}

	//for (int i = 1; i <= M; i++) {
	//	for (int j = 1; j <= 5 * M; j++) {
	//		cout << wall[i][j] << " ";
	//	}
	//	cout << '\n';
	//}

	for (int i = 1; i <= A; i++)
		spread(i);

	int B = move_space(A+1);
	if (B <= 0) {
		cout << -1 << "\n";
		return 0;
	}

	//for (int i = 1; i <= N; i++) {
	//	for (int j = 1; j <= N; j++) {
	//		cout << space[i][j] <<" ";
	//	}
	//	cout << '\n';
	//}

	cout << B << "\n";
	return 0;
}