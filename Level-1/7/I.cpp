#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::string;
using std::vector;
typedef long long ll;


bool enough(int v, int n, int k) {
    int ans = v, counter = 1;
    while (true) {
        int increase = v/pow(k, counter);
        if (increase == 0) break;
        ans += v/pow(k, counter);
        counter++;
    }

    return ans >= n;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int st = 0, ed = n-1, md, v = n;
    while (st <= ed) {
        md = (st + ed)/2;
        if (enough(md, n, k)) {
            v = md;
            ed = md - 1;
        } else st = md + 1;
    }

    cout << v << '\n';
}
