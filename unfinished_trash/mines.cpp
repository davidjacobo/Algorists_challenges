#include <iostream>
#include <cstring>
#define MAX_N 52
#define MINE '*'
#define EMPTY '.'
#define START 'c'
#define BORDER '?'

using namespace std;

int add_x[] = {1, 1, 1, 0, 0, -1, -1, -1};
int add_y[] = {1, 0, -1, 1, -1, 1, 0, -1};
int visited[MAX_N][MAX_N];
char board[MAX_N][MAX_N];
int arr_out[MAX_N];
bool done;

void print_solution(int r,int c) {
  for(int i=1;i<=r;++i) {
    for(int j=1;j<=c;++j)
      cout<<board[i][j];
    cout<<endl;
  }
}

int dfs(int r,int c) {
	int counter = 1;
	visited[r][c] = true;

	bool can_expand = true;
	for(int k=0;k<8;++k) {
		int x = r + add_x[k];
		int y = c + add_y[k];

		if (board[x][y] == MINE) {
			can_expand = false;
			break;
		}
	}

	if (can_expand) {
		// Cool, lets expand to as many EMPTY spaces as possible.
		for(int k=0;k<8;++k) {
			int x = r + add_x[k];
			int y = c + add_y[k];

			if (board[x][y] == EMPTY && !visited[x][y])
				counter += dfs(x,y);
		}
	}
	
	return counter;
}

bool valid_solution(int r,int mines) {
	int c = arr_out[0];
	memset(board, EMPTY, sizeof board);
	for(int i=0;i<MAX_N;++i) board[i][0] = board[i][c+1] = BORDER;
	for(int j=0;j<MAX_N;++j) board[0][j] = board[r+1][j] = BORDER;

	int count_mines = 0;
	for(int i=1;i<=r;++i) count_mines += arr_out[i];
	if (count_mines != mines) return false;

	for(int i=1;i<=r;++i) {
		count_mines = arr_out[i];
		for(int j=1;j<=count_mines;++j)
			board[i][j] = MINE;
	}

	// In theory this board is a good candidate, has the correct amount of mines
	// and has a single mines component, as well as a single empty component.
	// We can assume the start is always at (r,c).

	// of course we dfs.
	memset(visited, false, sizeof visited);
	int empty = dfs(r,c);

	board[r][c] = START;
	return r*c - mines == empty;
}

void backtrack(int row, int r, int m, int total) {
	if (done) return;

	// We could prune branches that would never reach the amount of required mines
	if (m - total > (r - row + 1) * arr_out[row-1]) return;
 
  // This may be a solution, evaluate an mark as finished or just return.
	if (row > r) {
		if (valid_solution(r,m)) done = true;
		return;
	}

	for (int i = arr_out[row - 1]; i >= 0; --i) {
		arr_out[row] = i;
		backtrack(row + 1, r, m, total + i);
	}
}

void solve(int r,int c,int m) {
  // Cell 0 is not used but as reference of the max amount of mines we can put
	// in a row.
	arr_out[0] = c;
	done = false;

	backtrack(1, r, m, 0);
	if (done) {
    print_solution(r,c);
  } else {
    cout<<"Impossible"<<endl;
  }
}

int main() {
	int t, r, c, m;
	int counter = 1;
	cin>>t;
	while(t--) {
		cin>>r>>c>>m;
		cout<<"Case #"<<counter++<<":"<<endl;
		
		solve(r,c,m);
	}
	return 1;
}
