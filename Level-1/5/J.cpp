#include <iostream>
#include <vector>
#include <algorithm>
 
typedef long long ll;
 
int main() {
    int t, nOfMonsters, genosPower;
    std::cin >> t;
    while (t--) {
        std::cin >> nOfMonsters >> genosPower;
        std::vector<std::pair<ll, ll>> monsters(nOfMonsters);
        for (int i = 0; i < nOfMonsters; i++) std::cin >> monsters[i].second;
        for (int i = 0; i < nOfMonsters; i++) std::cin >> monsters[i].first;
        std::sort(monsters.begin(), monsters.end());

        int damage = genosPower;
        for (int i = 0; i < nOfMonsters; i++) {
            if (monsters[i].second > damage) {
                genosPower -= monsters[i].first;
                damage += genosPower;
                i--;
            }
        }       
 
        if (genosPower > 0) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
}