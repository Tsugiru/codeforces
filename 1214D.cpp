#include <bits/stdc++.h>
using namespace std;

bool dfsv(vector<vector<char>> &grid, vector<vector<int>> &visited, int i, int j) {
    if(!visited[i][j]) {
        
    }
    else {
        return false;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> visited(n, vector<int>(m , 0));


    return 0;
}