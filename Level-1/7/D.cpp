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
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int n;
    cin >> n;

    vector<int> measurements(n);
    for (int i = 0; i < n; i++) cin >> measurements[i];
    std::sort(measurements.begin(), measurements.end());

    int min = n;
    
    for (int i = 0; i < n; i++) {
        int ans = std::upper_bound(measurements.begin(), measurements.end(), measurements[i]*2)
                    - measurements.begin();
        ans = n - (ans - i);
        min = std::min(min, ans);
    }

    cout << min << '\n';
}