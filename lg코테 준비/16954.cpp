#include <iostream>
#include <queue>
using namespace std;

//상하좌우, 대각선, 제자리
int dx[9] = {1,-1,0,0,1,1,-1,-1,0};
int dy[9] = {0,0,1,-1,-1,1,-1,1,0};

char map[8][8];
bool visit[8][8][20];

struct group
{
	int row;
	int col;
	int count; // count에 따라 캐릭터가 이동하고 벽이 내려옴
};

void bfs()
{
	queue<group> q;
	q.push({7,0,0});
	visit[7][0][0] = true;
	while (!q.empty())
	{
		int nowX = q.front().row;
		int nowY = q.front().col;
		int nowCount = q.front().count;
		q.pop();
		for (int i = 0; i < 9; i++)
		{
			int nextX = nowX + dx[i];
			int nextY = nowY + dy[i];
			if (nextX == 0 && nextY == 7)//다음 칸이 목표 칸이면
			{
				cout << 1;
				return;
			}
			if (visit[nextX][nextY][nowCount + 1])
				continue;
			//범위 벗어나면 스킵
			if (nextX < 0 || nextX >= 8 || nextY < 0 || nextY >= 8)
				continue;
			//가려는 칸이 벽이라면 스킵
			if (map[nextX - nowCount][nextY] == '#' && nextX - nowCount >= 0)
				continue;
			//이동한다음 벽을 마주친다면
			if (map[nextX - nowCount - 1][nextY] == '#' && nextX - nowCount - 1 >= 0)
				continue;
			//위 조건들에 해당 안된다면
			visit[nextX][nextY][nowCount + 1] = true;
			q.push({ nextX, nextY, nowCount + 1 });
		}
	}
	cout << 0;
}

int main()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> map[i][j];
		}
	}

	bfs();
}