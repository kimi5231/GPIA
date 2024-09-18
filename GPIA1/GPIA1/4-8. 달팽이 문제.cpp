#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 100;
int board[MAX][MAX];
int N;

enum Dir
{
	RIGHT = 0,
	DOWN = 1,
	LEFT = 2,
	UP = 3
};

int dirX[] = { 1, 0, -1, 0 };
int dirY[] = { 0, 1, 0, -1 };

bool CanGo(int x, int y)
{
	if (x < 0 || x >= N)
		return false;
	if (y < 0 || y >= N)
		return false;
	if (board[y][x] != 0)
		return false;
	return true;
}

void SetBoard()
{
	int dir = RIGHT;
	int num = 1;
	int x = 0;
	int y = 0;

	while (true)
	{
		board[y][x] = num;

		if (num == N * N)
			return;

		int nextX = dirX[dir] + x;
		int nextY = dirY[dir] + y;

		/*switch (dir)
		{
		case RIGHT:
			nextX = x + 1;
			nextY = y;
			break;
		case DOWN:
			nextX = x;
			nextY = y + 1;
			break;
		case LEFT:
			nextX = x - 1;
			nextY = y;
			break;
		case UP:
			nextX = x;
			nextY = y - 1;
			break;
		}*/

		if (CanGo(nextX, nextY))
		{
			x = nextX;
			y = nextY;
			num++;
		}
		else
		{
			dir = (dir + 1) % 4;

			/*switch (dir)
			{
			case RIGHT:
				dir = DOWN;
				break;
			case DOWN:
				dir = LEFT;
				break;
			case LEFT:
				dir = UP;
				break;
			case UP:
				dir = RIGHT;
				break;
			}*/
		}
	}
}

void PrintBoard()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			cout << setfill('0') << setw(2) << board[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	cin >> N;

	SetBoard();

	PrintBoard();
}