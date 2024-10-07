#include <iostream>
#include <deque>
#include <string>


void solve() {
    std::string s;
    std::cin >> s;

    std::deque<std::pair<char, int>> lowercase;
    std::deque<std::pair<char, int>> uppercase;
    for (int i = 0; i < s.length(); i++) {
        if (std::islower(s[i]) && s[i] != 'b') lowercase.push_back({s[i], i});
        else if (std::isupper(s[i]) && s[i] != 'B') uppercase.push_back({s[i], i});
        else if (!lowercase.empty() && s[i] == 'b') lowercase.pop_back();
        else if (!uppercase.empty() && s[i] == 'B') uppercase.pop_back();
    }

    std::string ans = "";
    for (int i = 0; i < s.length(); i++) {
        if (!lowercase.empty() && lowercase.front().second == i) {
            ans += lowercase.front().first;
            lowercase.pop_front();
        }
        else if (!uppercase.empty() && uppercase.front().second == i) {
            ans += uppercase.front().first;
            uppercase.pop_front();
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}