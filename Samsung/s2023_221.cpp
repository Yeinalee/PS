#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int N, M, P, C, D;
pair<int, int> rudol;
struct santa {
	int x, y, state, score;
};
int die = 0;
vector<santa> s;
vector<vector<int>> map;
//루돌프 이동
vector<int> dxr = { -1, -1, -1, 0, 0, 1, 1, 1 };
vector<int> dyr = { -1, 0, 1, -1, 1, -1, 0, 1 };
//산타 이동
vector<int> dxs = { -1, 0, 1, 0 };
vector<int> dys = { 0, 1, 0, -1 };

//거리 구하기
int get_len(int x1, int y1, int x2, int y2) {
	return pow((x1 - x2), 2) + pow((y1 - y2), 2);
}

//루돌프가 이동해서 충돌
void rudol_crash(int d) {
	bool is_first = true;
	int cx = rudol.first;
	int cy = rudol.second;
	int num_san = map[cx][cy]; //해당 위치에 있던 산타
	map[cx][cy] = -1; //갱신된 루돌프 위치
	
	//산타가 있다면
	while (num_san > 0) {
		int nx, ny;
		int n_san = num_san;
		if (is_first) {
			//c만큼 일려남
			nx = s[num_san].x + C * dxr[d];
			ny = s[num_san].y + C * dyr[d];
			s[num_san].state = 2;// 충돌한 산타 기절
			//점수 추가
			s[n_san].score += C;
			is_first = false;
		}
		else {
			//1만큼 일려남
			nx = s[num_san].x + dxr[d];
			ny = s[num_san].y + dyr[d];
		}

		//밖으로 밀려남
		if (nx > N || nx <= 0 || ny > N || ny <= 0) {
			if (map[s[n_san].x][s[n_san].y] == n_san)
				 map[s[n_san].x][s[n_san].y] = 0; //빈 자리로
			s[n_san].state = 3;
			die++;
			return;
		}
		
		//다른 산타가 있다면
		if (map[nx][ny] > 0) {
			num_san = map[nx][ny];
		}
		else
			num_san = 0;

		if(map[s[n_san].x][s[n_san].y] == n_san){
			map[s[n_san].x][s[n_san].y] = 0; //빈 자리로
		}
		s[n_san].x = nx;
		s[n_san].y = ny;
		map[nx][ny] = n_san;
	}
	return;
}

//루돌프 이동
void move_rudol(){
	int min_s = pow(N, 2)+1;
	int min_sn = 0;
	//각 산타와의 거리 계산
	for (int j = 1; j <= P; j++) {
		if (s[j].state >= 3) //죽은 산타 패스
			continue;

		int nl = get_len(rudol.first, rudol.second, s[j].x, s[j].y);
		bool change = false;

		if (min_s > nl){
			change = true;
		}

		//거리가 같다면
		else if (min_s == nl) {
			//행이 더 크다면
			if (s[min_sn].x < s[j].x) {
				change = true;
			}

			//행이 같고 열이 더 크다면
			else if (s[min_sn].x == s[j].x && s[min_sn].y < s[j].y) {
				change = true;
			}
		}
		if (change) {
			min_s = nl;
			min_sn = j;
		}
	}

	int min_d = -1;
	//산타가 위쪽
	if (rudol.first > s[min_sn].x) {
		if (rudol.second > s[min_sn].y) min_d = 0;		//위왼
		else if (rudol.second == s[min_sn].y) min_d = 1;//위중
		else min_d = 2; //위오
	}
	//같은 행
	else if(rudol.first == s[min_sn].x){		
		if (rudol.second > s[min_sn].y) min_d = 3;		//왼
		else min_d = 4; //오
	}
	//산타가 아래
	else if (rudol.first < s[min_sn].x) {
		if (rudol.second > s[min_sn].y) min_d = 5;		//위왼
		else if (rudol.second == s[min_sn].y) min_d = 6;//위중
		else min_d = 7; //위오
	}

	//루돌프 이동
	map[rudol.first][rudol.second] = 0;
	rudol.first += dxr[min_d];
	rudol.second += dyr[min_d];

	//충돌
	if(map[rudol.first][rudol.second]>0)
		rudol_crash(min_d);
	else {
		map[rudol.first][rudol.second] = -1;
	}

	return;
}

//산타가 이동해서 충돌
void santa_crach(int num_san, int d) {
	bool is_first = true;
	int cx = s[num_san].x; //이동 전 충돌 산타의 위치
	int cy = s[num_san].y;

	//다른 산타가 있었다면
	while (num_san > 0) {
		int nx, ny;
		int n_san = num_san;
		if (is_first) {
			//d만큼 일려남
			nx = s[num_san].x + (1- D) * dxs[d];
			ny = s[num_san].y + (1- D) * dys[d];
			s[num_san].score += D;
			s[num_san].state = 2;// 충돌한 산타 기절
			is_first = false;
		}
		else {
			//1만큼 일려남
			nx = s[num_san].x - dxs[d];
			ny = s[num_san].y - dys[d];
		}

		//밖으로 밀려남
		if (nx > N || nx <= 0 || ny > N || ny <= 0) {
			if (map[s[n_san].x][s[n_san].y] == n_san)
				map[s[n_san].x][s[n_san].y] = 0; //빈 자리로
			s[n_san].state = 3;
			die++;
			return;
		}

		//다른 산타가 있다면
		if (map[nx][ny] > 0 && map[nx][ny] != n_san) {
			num_san = map[nx][ny];
		}
		else
			num_san = 0;

		if (map[s[n_san].x][s[n_san].y] == n_san) {
			map[s[n_san].x][s[n_san].y] = 0; //빈 자리로
		}
		s[n_san].x = nx;
		s[n_san].y = ny;
		map[nx][ny] = n_san;
	}
	return;
}

//산타 이동
void move_santa(){
	for (int i = 1; i < P + 1; i++) {
		if (s[i].state >= 1) //기절 or죽음
			continue;

		int min_len = get_len(rudol.first, rudol.second, s[i].x, s[i].y);
		int min_d = -1;
		for (int j = 0; j < 4; j++) {
			int nx = s[i].x + dxs[j];
			int ny = s[i].y + dys[j];

			//밖으로
			if (nx <= 0 || nx > N || ny <= 0 || ny > N)
				continue;

			//다른 산타 존재
			if (map[nx][ny] > 0)
				continue;

			int n_len = get_len(rudol.first, rudol.second, nx, ny);
			if (min_len > n_len) {
				min_len = n_len;
				min_d = j;
			}
		}

		//이동X
		if (min_d < 0)
			continue;

		int kx = s[i].x + dxs[min_d];
		int ky = s[i].y + dys[min_d];
		//루돌프가 있다면 -> 충돌
		if (map[kx][ky] == -1) {
			santa_crach(i, min_d);
		}
		//빈 공간이면
		else if (map[kx][ky] == 0) {
			if (map[s[i].x][s[i].y] == i)
				map[s[i].x][s[i].y] = 0;
			s[i].x = kx;
			s[i].y = ky;
			map[s[i].x][s[i].y] = i;
		}
		else cout << "error in move_santa" << i << '\n';
	}
	return;
}

void after_care(){
	for (int i = 1; i <= P; i++) {
		if (s[i].state < 3) {
			s[i].score++;
			if (s[i].state > 0)
				s[i].state--;
		}
	}
}


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M >> P >> C >> D;
	map.assign(N + 1, vector<int>(N + 1, 0));
	s.assign(P + 1, santa{-1, -1, -1, -1});
	int r, c;

	cin >> r >> c;
	rudol = { r,c };
	map[r][c] = -1;

	int x;
	for (int i = 1; i < P+1; i++) {
		cin >> x >> r >> c;
		s[x] = { r, c, 0, 0 };
		map[r][c] = x;
	}

	//m번 턴 실행
	for (int i = 0; i < M && die < P; i++) {
		move_rudol();
		move_santa();
		after_care();
	}

	//점수 출력
	for (int i = 1; i < P + 1; i++) {
		cout << s[i].score << " ";
	}

	return 0;
}