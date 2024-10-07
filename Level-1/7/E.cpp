#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;
using std::vector;
typedef long long ll;


int binary_search_closest(vector<ll> &, int, ll);

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int totalDormitories, totalLetters;
    cin >> totalDormitories >> totalLetters;

    vector<ll> dormitories(totalDormitories);
    cin >> dormitories[0];
    for (int i = 1; i < totalDormitories; i++) {
        cin >> dormitories[i];
        dormitories[i] += dormitories[i-1];
    }

    while (totalLetters--) {
        ll letter;
        cin >> letter;
        
        int dormitoryNumber = binary_search_closest(dormitories, totalDormitories, letter) + 1;
        ll roomNumber = letter;
        if (dormitoryNumber > 1) roomNumber -= dormitories[dormitoryNumber-2];

        cout << dormitoryNumber << ' ' << roomNumber << '\n';
    }
}

int binary_search_closest(vector<ll> &a, int n, ll target) {

    int st = 0, ed = n-1, md, ans;
    while (st <= ed) {
        md = (st + ed)/2;
        if (a[md] == target) return md;
        else if (a[md] < target) st = md + 1;
        else {
            ans = md;
            ed = md - 1;
        }
    }

    return ans;
}