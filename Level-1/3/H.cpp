#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    int m, l, r;
    cin >> s >> m;
    int n = s.length();
    vector<int> prefix(n+1, 0);
    for (int i = 1; i < n; i++) {
        if (s[i-1] == s[i]) prefix[i] += prefix[i-1] + 1;
        else prefix[i] = prefix[i-1];
    }

    while (m--) {
        cin >> l >> r;
        cout << prefix[r-1] - prefix[l-1] << endl;
    }
}