#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n, prev, temp = 1, dist = 1e5;
    long long int min = 1e9;
    cin >> n;
    deque<long long int> dq(n);

    for (int i = 0; i < n; i++) {
        cin >> dq[i];
        if (dq[i] == min) {
            prev = temp;
            temp = i+1;
            if (dist > (temp-prev) && temp != prev) dist = temp-prev;
        }

        if (dq[i] < min) {
            min = dq[i];
            temp = i+1;
            dist = 1e5;
        }
    }

    cout << dist;
}