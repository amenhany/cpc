#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::sort;
typedef long long ll;


vector<long long> luckyNums;

void solve(long long n) {
    if (n > 1e9) return;
    if (n > 0) luckyNums.push_back(n);

    solve(n*10 + 4);
    solve(n*10 + 7);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long n;
    cin >> n;
    solve(0);

    sort(luckyNums.begin(), luckyNums.end());
    // for (long long i = 0; i < luckyNums.size(); i++)
    //     if (luckyNums[i] == n) cout << i+1 << '\n';

    long long i = std::lower_bound(luckyNums.begin(), luckyNums.end(), n) - luckyNums.begin();
    cout << i+1 << '\n';
}