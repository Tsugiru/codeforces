#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <chrono>
#include <random>
#include <string>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>
#include <unordered_set>
#include <unordered_map>


using namespace std;

auto changeToPalindrome(const string &s) {
    auto res = make_pair(s, 0);
    auto &[newPal, changes] = res;
    for(int i = 0, j = newPal.size() - 1; i != j; i++, j--) {
        changes += newPal[i] != newPal[j];
        newPal[i] = newPal[j] = min(newPal[i], newPal[j]);
    }
    return res;
}

bool trialOfValor(vector<vector<int>> &d) {
    if(d.empty()) {
        return false;
    }

    int n = d.size(), m = d[0].size();
    vector<vector<int>> visited(n, vector<int>(m));
    queue<pair<int, int>> q, doors;
    q.emplace(0, 0);
    visited[0][0] = 1;
    bool hasKey = false;

    const vector<pair<int, int>> deltas { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if(d[x][y] == 4) {
            return true;
        }

        if(d[x][y] == 3) {
            hasKey = true;
            while(!doors.empty()) {
                q.push(doors.front());
                doors.pop();
            }
        }

        for(const auto& [dx, dy] : deltas) {
            int xx = x + dx, yy = y + dy;
            if(xx >= 0 && xx < n && yy >= 0 && yy < m && d[xx][yy] != 1 && !visited[xx][yy]) {
                visited[xx][yy] = 1;
                if(d[xx][yy] == 2 && !hasKey) {
                    doors.emplace(xx, yy);
                }
                else {
                    q.emplace(xx, yy);
                }
            }
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> v1 {{0, 2, 2, 3}, 
                        {1, 0, 1, 1},
                        {1, 0, 1, 4}};
    vector<vector<int>> v2 {{}};
    cout << trialOfValor(v2) << endl;
}
