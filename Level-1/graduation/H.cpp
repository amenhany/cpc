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

    int n;
    cin >> n;

    vector<int> transaction(n);
    for (int i = 0; i < n; i++) cin >> transaction[i];

    std::sort(transaction.begin(), transaction.end());

    int q;
    cin >> q;

    while (q--) {
        int max;
        cin >> max;

        if (max < transaction[n-1]) {
            cout << "Impossible" << '\n';
            continue;
        }

        int batches = 0, sum = 0;
        //optimize with upper bound if necessary
        for (int i = 0; i < n; i++) {
            sum += transaction[n-i-1];
            if (i != n-1 && sum + transaction[i+1] < max) continue;
            batches++;
            sum = 0;
        }

        cout << batches << '\n';
    }
}