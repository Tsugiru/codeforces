#include <bits/stdc++.h>

using namespace std;

// Returns true if there is a subset of set[] with sun equal to given sum
bool isSubsetSum(vector<int> set, int n, int sum) {
    bool subset[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        subset[i][0] = true;

    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j] ||
                               subset[i - 1][j - set[i - 1]];
        }
    }

    return subset[n][sum];
}

int main() {
    int n; cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];

    int sum = accumulate(v.begin(), v.end(), 0);
    if(sum & 1) {
        cout << "NO" << endl;
        return 0;
    }

    if(isSubsetSum(v, v.size(), sum/2)) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}