#include <iostream>
#include <cmath>
#include <set>


void solve() {
    int n;
    std::cin >> n;
    std::set<long long> st;

    for (int i = 0; i < n; i++) {
        long long num;
        std::cin >> num;
        st.insert(num);
    }

    auto startIT = st.begin();
    auto endIT = st.end();
    endIT--;
    bool flag = false;
    long long ans = *startIT * *endIT;

    std::set<int> divisors;
    for (int i = 2; i <= sqrt(ans); i++) {
        if (ans%i == 0) {
            divisors.insert(i);
            if (ans/i != i) divisors.insert(ans/i);
        }
    }

    for (auto &i : divisors)
        if (!st.count(i) && i != ans) flag = true;  
    
    for (auto &i : st)
        if (ans%i) flag = true;

    if (flag) ans = -1;

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int t;
    std::cin >> t;

    while (t--) solve();
}