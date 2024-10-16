#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using std::cin;
using std::cout;
using std::string;
using std::vector;
typedef long long ll;


ll factorial(ll n) {
    ll result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll a, b;
    cin >> a >>b;

    cout << factorial(std::min(a, b));
}