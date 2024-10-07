#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <queue>

using std::cin;
using std::cout;
using std::string;
typedef long long ll;



int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string correct, incorrect;
    cin >> correct >> incorrect;

    bool flag = false;
    std::queue<char> output;
    std::map<char, char> bindings;
    std::set<char> done;
    for (int i = 0; i < correct.length(); i++) {
        if (bindings.find(correct[i]) == bindings.end() && bindings.find(incorrect[i]) == bindings.end()) {
            if (correct[i] != incorrect[i]) {
                output.push(correct[i]);
                output.push(incorrect[i]);
            }
            bindings[correct[i]] = incorrect[i];
            bindings[incorrect[i]] = correct[i];
            done.insert(correct[i]);
            done.insert(incorrect[i]);
        }
        else if (bindings[correct[i]] != incorrect[i] || bindings[incorrect[i]] != correct[i]) flag = true;
    }

    if (flag) cout << -1 << '\n';
    else if (correct == incorrect) cout << 0 << '\n';   
    else {
        cout << output.size()/2 << '\n';
        while (!output.empty()) {
            cout << output.front() << ' ';
            output.pop();
            cout << output.front() << '\n';
            output.pop();
        }
    }
}