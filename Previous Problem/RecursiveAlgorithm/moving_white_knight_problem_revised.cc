#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> moves{
	{-2, 1},
	{-1, 2},
	{1, 2},
	{2, 1}
};

struct Position
{
	int x, y;
	Position(int _x = 0, int _y = 0)
		: x(_x), y(_y) {}
	Position operator+ (pair<int, int>& m)
	{
		return Position(x + m.first, y + m.second);
	}
};

bool valid(const Position& P, const pair<int, int>& m, int N)
{
	int x = P.x + m.first;
	int y = P.y + m.second;
	return 0 <= x && x < N && y < N;
}

int play_util(const vector<vector<char>>& board, Position K, vector<vector<int>>& dp)
{
	if (dp[K.x][K.y] != -1)
		return dp[K.x][K.y];
	int max_captures = 0;
	for (auto m : moves)
		if (valid(K, m, board.size()))
			max_captures = max(max_captures, play_util(board, K + m, dp));
	if (board[K.x][K.y] == 'P')
		max_captures += 1;
	dp[K.x][K.y] = max_captures;
	return dp[K.x][K.y];
}

int play(const vector<vector<char>>& board, Position K)
{
	vector<vector<int>> dp(board.size(), vector<int>(board.size(), -1));
	return play_util(board, K, dp);
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		Position K;
		vector<vector<char>> board(N, vector<char>(N));
		for (size_t i = 0; i < board.size(); ++i)
			for (size_t j = 0; j < board[i].size(); ++j)
			{
				cin >> board[i][j];
				if (board[i][j] == 'K')
					K = { (int)i, (int)j };
			}
		cout << play(board, K) << endl;
	}
}
