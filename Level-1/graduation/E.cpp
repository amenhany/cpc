#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;
using std::vector;
typedef long long ll;


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n, battleTime;
    cin >> n >> battleTime;

    vector<ll> warriors(n), prefix(n);
    for (int i = 0; i < n; i++) {
        cin >> warriors[i];
        prefix[i] = warriors[i];
        if (i != 0) prefix[i] += prefix[i-1];
    }

    ll totalDamage = 0, counter = 0;
    while (battleTime--) {
        ll arrowDamage;
        cin >> arrowDamage;
        totalDamage += arrowDamage;

        // while (prefix[counter] - totalDamage <= 0) {
        //     if (counter == n - 1) {
        //         totalDamage = 0;
        //         counter = 0;
        //     }
        //     else counter++;
        // }

        int index = std::upper_bound(prefix.begin(), prefix.end(), totalDamage) - prefix.begin();
        if (totalDamage >= prefix[n-1]) {
            totalDamage = 0;
            index = 0;
        }

        cout << n - index << '\n';
    }
}