#include <iostream>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int n;
    long long num = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        num += 6*i;
    }
    cout << num << endl;
}