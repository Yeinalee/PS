#include<iostream>
#include<vector>
#include<tuple>
#include<cmath>
#include<algorithm>
using namespace std;

int n, m, k;
vector<vector<int>> map;
vector<tuple<int, int, bool>> runner;
pair<int, int> entrance; //�ⱸ
pair<int, int> start;
int min_l;
int die = 0; //Ż���� ��� ��
int total = 0; //��ü �̵� �Ÿ�

 int move_runner() {
	int s = 0; //�̵��Ÿ�
	for (int i = 0; i < m; i++) {
		if (get<2>(runner[i]))
			continue;

		bool move = 0;
		//�Ʒ��ʿ� ��ġ
		if (get<0>(runner[i]) - entrance.first > 0) {
			//������̸�
			if (!map[get<0>(runner[i]) - 1][get<1>(runner[i])]) {
				get<0>(runner[i])--;
				move = 1;
			}
		}
		//���ʿ� ��ġ
		else if (get<0>(runner[i]) - entrance.first < 0) {
			if (!map[get<0>(runner[i]) + 1][get<1>(runner[i])]) {
				get<0>(runner[i])++;
				move = 1;
			}
		}
		//�����ʿ� ��ġ
		 if (!move && get<1>(runner[i]) - entrance.second > 0) {
			if (!map[get<0>(runner[i])][get<1>(runner[i])-1]) {
				get<1>(runner[i])--;
				move = 1;
			}
		}
		//���ʿ� ��ġ
		 else if (!move && get<1>(runner[i]) - entrance.second < 0) {
			if (!map[get<0>(runner[i])][get<1>(runner[i]) + 1]) {
				get<1>(runner[i])++;
				move = 1;
			}
		}

		if (move) s++;

		//�ⱸ ����
		if (get<0>(runner[i]) == entrance.first && get<1>(runner[i]) == entrance.second) {
			die++;
			get<2>(runner[i]) = 1;
		}
	}
	return s;
}

//���� ���� ���簢�� 90�� �ð� ���� ȸ��
 void rotate_map() {
	//���簢�� ũ�� ���ϱ�
	int s=0;
	int min_l, min_runner;
	while (s<n) {
		if (!get<2>(runner[s])) {
			 min_l = max(abs(get<0>(runner[s]) - entrance.first), abs(get<1>(runner[s]) - entrance.second));
			 min_runner = s;
			s++;
			break;
		}
		s++;
	}
	for (int i = s; i < m; i++)
	{
		if (get<2>(runner[i]))
			continue;

		if (abs(get<0>(runner[i]) - entrance.first) > abs(get<1>(runner[i]) - entrance.second)) {
			if (abs(get<0>(runner[i]) - entrance.first) < min_l) {
				min_l = abs(get<0>(runner[i]) - entrance.first);
				min_runner = i;
			}
			if (get<0>(runner[i]) == entrance.first) {
				//���ο�� �� ����
				if (get<0>(runner[min_runner]) - get<0>(runner[i]) > 0)
					min_runner = i;
				if (get<0>(runner[min_runner]) - get<0>(runner[i]) == 0) {
					//���ο�� �� ����
					if (get<1>(runner[min_runner]) - get<1>(runner[i]) > 0) {
						min_runner = i;
					}
				}
			}
		}
		else {
			if (abs(get<1>(runner[i]) - entrance.second) < min_l) {
				min_l = abs(get<1>(runner[i]) - entrance.second);
				min_runner = i;
			}

			if (get<0>(runner[i]) == entrance.first) {
				//���ο�� �� ����
				if (get<0>(runner[min_runner]) - get<0>(runner[i]) > 0)
					min_runner = i;
				if (get<0>(runner[min_runner]) - get<0>(runner[i]) == 0) {
					//���ο�� �� ����
					if (get<1>(runner[min_runner]) - get<1>(runner[i]) > 0) {
						min_runner = i;
					}
				}
			}
		}
	}
	//���� ��ǥ ���ϱ�
	pair<int, int> start;
	//�����ڰ� �Ʒ���
	if (get<0>(runner[min_runner]) - entrance.first > 0){
		if (get<0>(runner[min_runner]) - min_l >= 0) {
			start.first = get<0>(runner[min_runner]) - min_l;
		}
		else start.first = 0;
	}
	//�����ڰ� ����
	else {
		if (entrance.first - min_l >= 0) {
			start.first = entrance.first - min_l;
		}
		else start.first = 0;
	}

	//�����ڰ� �����ʿ�
	if (get<1>(runner[min_runner]) - entrance.second > 0) {
		if (get<1>(runner[min_runner]) - min_l >= 0) {
			start.second = get<1>(runner[min_runner])-min_l;
		}
		else start.second = 0;
	}
	else {
		if (entrance.second - min_l >= 0) {
			start.second = entrance.second- min_l;
		}
		else start.second = 0;
	}

	//90�� ȸ�� -> �� ȸ��
	vector<vector<int>> temp(min_l+1, vector<int>(min_l+1, 0));
	for (int i = 0; i < min_l + 1; i++) {
		for (int j = 0; j < min_l + 1; j++) {
			temp[i][j] = map[start.first + i][start.second + j];
			//������ ����
			if (temp[i][j] > 0)temp[i][j]--;
		}
	}
	for (int i = 0; i < min_l+1; i++) {
		for (int j = 0; j < min_l+1; j++) {
			map[start.first + j][start.second + (min_l - i)] = temp[i][j];
		}
	}

	//90�� ȸ�� -> �ⱸ
	pair<float, float> centroid = { start.first + float(min_l) / 2 , start.second + float(min_l) / 2 };
	if (entrance.first >= start.first && entrance.first <= start.first + min_l) {
		if (entrance.second >= start.second && entrance.second <= start.second + min_l) {
			int temp_ex = entrance.second;
			entrance.second = round(-entrance.first + centroid.first + centroid.second);
			entrance.first = round(temp_ex - centroid.second + centroid.first);

		}
	}
	//90�� ȸ�� -> ������
	for (int i = 0; i < m; i++) {
		if (get<2>(runner[i]))
			continue;
		if (get<0>(runner[i]) >= start.first && get<0>(runner[i]) <= start.first + min_l) {
			if (get<1>(runner[i]) >= start.second && get<1>(runner[i]) <= start.second + min_l) {
				int temp_ex = get<1>(runner[i]);
				get<1>(runner[i]) = round (-get<0>(runner[i]) + centroid.first + centroid.second);
				get<0>(runner[i]) = round(temp_ex - centroid.second + centroid.first);

			}
		}
	}
}

void get_min_len() {
	for (int min_len = 1; min_len <= n; min_len++) {
		//i, j���� min_len ũ���� ���簢��
		for (int i = 0; i < n-min_len; i++) {
			for (int j = 0; j < n-min_len; j++) {

				//�ⱸ ���� ���
				if (!(entrance.first >= i && entrance.first <= i + min_len && entrance.second >= j && entrance.second <= j + min_len)) {
					continue;
				}

				//������ Ȯ��
				for (int a = 0; a < m; a++) {
					if (get<2>(runner[a]))
						continue;

					if (get<0>(runner[a]) >= i && get<0>(runner[a]) <= i + min_len) {
						if (get<1>(runner[a]) >= j && get<1>(runner[a]) <= j + min_len) {
							start.first = i;
							start.second = j;
							min_l = min_len;
							return;
						}
					}
				}
			}
		}

	}
}

void rotate_map2() {
	get_min_len();

	//90�� ȸ�� -> �� ȸ��
	vector<vector<int>> temp(min_l + 1, vector<int>(min_l + 1, 0));
	for (int i = 0; i < min_l + 1; i++) {
		for (int j = 0; j < min_l + 1; j++) {
			temp[i][j] = map[start.first + i][start.second + j];
			//������ ����
			if (temp[i][j] > 0)temp[i][j]--;
		}
	}
	for (int i = 0; i < min_l + 1; i++) {
		for (int j = 0; j < min_l + 1; j++) {
			map[start.first + j][start.second + (min_l - i)] = temp[i][j];
		}
	}

	//90�� ȸ�� -> �ⱸ
	pair<float, float> centroid = { start.first + float(min_l) / 2 , start.second + float(min_l) / 2 };
	if (entrance.first >= start.first && entrance.first <= start.first + min_l) {
		if (entrance.second >= start.second && entrance.second <= start.second + min_l) {
			int temp_ex = entrance.second;
			entrance.second = round(-entrance.first + centroid.first + centroid.second);
			entrance.first = round(temp_ex - centroid.second + centroid.first);

		}
	}
	//90�� ȸ�� -> ������
	for (int i = 0; i < m; i++) {
		if (get<2>(runner[i]))
			continue;
		if (get<0>(runner[i]) >= start.first && get<0>(runner[i]) <= start.first + min_l) {
			if (get<1>(runner[i]) >= start.second && get<1>(runner[i]) <= start.second + min_l) {
				int temp_ex = get<1>(runner[i]);
				get<1>(runner[i]) = -get<0>(runner[i]) + centroid.first + centroid.second;
				get<0>(runner[i]) = temp_ex - centroid.second + centroid.first;
			}
		}
	}
}

void sol() {
	while (k--) {
		total+= move_runner();
		if (die == m)
			break;
		rotate_map2();
	}
	cout << total << '\n';
	cout << entrance.first+1 << " " << entrance.second+1 << '\n';
}
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	map.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		runner.push_back({ x - 1, y - 1, 0 });
	}

	cin >> x >> y;
	entrance = { x-1, y-1 };

	sol();

	return 0;
}