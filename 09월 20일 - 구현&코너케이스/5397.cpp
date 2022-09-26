#include <iostream>
#include <list>

using namespace std;

int main() {
    int n;
    cin >> n;
    string log;
    list<char> key;
    list<char>::iterator iter;
    while (n--) {
        key.clear();
        iter = key.begin();
        cin >> log;
        for (int i = 0; i < log.length(); i++) {
            if (log[i] == '-' && iter != key.begin()) {
                iter = key.erase(--iter);
            } else if (log[i] == '<' && iter != key.begin()) {
                iter--;
            } else if (log[i] == '>' && iter != key.end()) {
                iter++;
            } else if (log[i] != '-' && log[i] != '<' && log[i] != '>') {
                key.insert(iter, log[i]);
            }
        }
        for (iter = key.begin(); iter != key.end(); iter++) {
            cout << *iter;
        }
        cout << "\n";
    }
    return 0;
}