#include <iostream>
#include <vector>
using namespace std;
char right(int d);
char left(int d);
void forward(int d, int& x, int& y, int n, int m, bool& miss, vector<vector<bool>>& map);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, x, y;
	char d;
	string act;
	cin >> n >> m;
	vector<vector<bool>>map(m+1, vector<bool>(n+1));
	while (cin >> x >> y>> d) {
		bool miss = false;
		cin >> act;
		for (char move:act) {
			switch (move) {
			case 'R':
				d = right(d);
				break;
			case 'L':
				d = left(d);
				break;
			case 'F':
				forward(d, x, y, n, m, miss, map);
				break;
			}
			if (miss) break;
		}
		cout << x << " " << y << " " << d << (miss ? " LOST\n" : "\n");
	}
	return 0;
}
char left(int d) {
	switch (d) {
	case 'N':
		d = 'W';
		break;
	case 'S':
		d = 'E';
		break;
	case 'E':
		d = 'N';
		break;
	case 'W':
		d = 'S';
		break;
	}
	return d;
}
char right(int d) {
	switch (d) {
	case 'N':
		d = 'E';
		break;
	case 'S':
		d = 'W';
		break;
	case 'E':
		d = 'S';
		break;
	case 'W':
		d = 'N';
		break;
	}
	return d;
}
void forward(int d, int& x, int& y, int n, int m, bool& miss, vector<vector<bool>>& map) {
	switch (d) {
	case 'N':
		if (y == m) {
			if (map[y][x]) break;
			else {
				map[y][x] = true;
				miss = true;
				break;
			}
		}
		else {
			y++;
			break;
		}
		break;
	case 'S':
		if (y == 0) {
			if (map[y][x]) break;
			else {
				map[y][x] = true;
				miss = true;
				break;
			}
		}
		else {
			y--;
			break;
		}
		break;
	case 'E':
		if (x == n) {
			if (map[y][x]) break;
			else {
				map[y][x] = true;
				miss = true;
				break;
			}
		}
		else {
			x++;
			break;
		}
		break;
	case 'W':
		if (x == 0) {
			if (map[y][x]) break;
			else {
				map[y][x] = true;
				miss = true;
				break;
			}
		}
		else {
			x--;
			break;
		}
		break;
	}
}
