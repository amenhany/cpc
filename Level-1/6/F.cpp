#include <iostream>
#include <map>
#include <vector>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> v(n);
    std::map<int, int> mp;
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
        if (mp.find(v[i]) != mp.end()) mp[v[i]]++;
        else mp[v[i]] = 1;
    }

    if (!mp.empty()) {
        std::pair<int, int> prev = *mp.begin();
        auto it = mp.begin();
        int size = mp.size();
        for (int i = 0; i < size-1; i++) {
            it++;
            std::pair<int, int> curr = *it;
            if (prev.second > curr.second) {
                mp[curr.first] = prev.second;
                curr.second = prev.second;
            }
            mp.erase(prev.first);
            prev = curr;
        }
    }

    int sum = 0;
    for (auto &i : mp) sum += i.second;
    std::cout << sum << '\n';
}