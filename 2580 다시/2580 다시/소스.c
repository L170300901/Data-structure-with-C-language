#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int sdoku[9][9], zero;
bool stop;
vector<pair<int, int>> space;

bool Check(int y, int x, int num) {
	//horizon
	for (int i = 0; i < 9; i++)
		if (sdoku[y][i] == num) return false;

	//vertical
	for (int i = 0; i < 9; i++)
		if (sdoku[i][x] == num) return false;

	//square
	int dx = (x / 3) * 3;
	int dy = (y / 3) * 3;
	for (int i = dy; i < 3 + dy; i++)
		for (int j = dx; j < 3 + dx; j++)
			if (sdoku[i][j] == num) return false;

	return true;
}


void dfs(int depth) {
	if (stop) return;
	if (depth == zero) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				printf("%d ", sdoku[i][j]);
			printf("\n");
		}
		stop = true;
		return;
	}

	for (int i = 1; i <= 9; i++) {
		int y = space[depth].first;
		int x = space[depth].second;

		if (Check(y, x, i)) {
			sdoku[y][x] = i;
			dfs(depth + 1);
			sdoku[y][x] = 0;
		}
	}
}

int main()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			scanf("%d", &sdoku[i][j]);
			if (sdoku[i][j] == 0)
				space.push_back(make_pair(i, j));
		}
	zero = space.size();
	dfs(0);

	return 0;
}[출처] [백준 2580] 스도쿠 | 작성자 Zinc


