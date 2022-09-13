#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string name, state;
    set<string> log;
    cin >> n;
    while (n--) {
        cin >> name >> state;
        if (state == "enter") {
            log.insert(name);
        } else {
            log.erase(name);
        }
    }

    for (auto iter = log.rbegin(); iter != log.rend(); iter++) {
        //역순출력
        cout << *iter << "\n";
    }
    return 0;
}