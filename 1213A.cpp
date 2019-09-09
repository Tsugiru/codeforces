#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; std::cin >> n;
    int evens = 0, odds = 0;
    for(int i = 0, k = 0; i < n; i++) {
        std::cin >> k;
        odds += (k % 2 == 0);
        evens += (k % 2 == 1);
    }
    std::cout << std::min(odds, evens) << std::endl;
}