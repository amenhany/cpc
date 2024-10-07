#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using std::cin;
using std::cout;
using std::string;
using std::vector;
typedef long long ll;


// unused by me
bool check(int participants, std::map<int, int> mp, int days) {
    int people = 0;
    if (days != 0) for (auto &i : mp) people += i.second/days;
    if (people < participants) return false;
    else return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int participants, foodPackages;
    cin >> participants >> foodPackages;

    std::map<int, int> foodTypes;
    for (int i = 0; i < foodPackages; i++) {
        int foodType;
        cin >> foodType;
        foodTypes[foodType]++;
    }

    int days = 1;
    while (true) {
        int people = 0;
        for (auto &i : foodTypes) people += i.second/days;
        if (people < participants) {
            days--;
            break;
        }
        days++;
    }

    // binary search from the lecture that gives the wrong answer

    // int st = 0, end = 100, md, days = 0;
    // while (st < end) {
    //     md = (st + end)/2;
    //     if (check(participants, foodTypes, md)) {
    //         days = md;
    //         st = md + 1;
    //     }
    //     else end = md;
    // }

    cout << days << '\n';
}