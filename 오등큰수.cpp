// Pull Requests 1
// 202301604 박승준 pull requests
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n;

    vector<int> sequence(n);
    vector<int> F(n);
    vector<int> NGF(n, -1);
    vector<int> size(1000001, 0);

    stack<int> s;

    for(int i = 0; i < n; i++) {
        cin >> m;
        sequence[i] = m;
        size[m]++;
    }

    for(int i = 0; i < n; i++) {
        F[i] = size[sequence[i]];
    }

    for(int i = 0; i < n; i++) {
        while(!s.empty() && F[s.top()] < F[i]) {
            NGF[s.top()] = sequence[i];
            s.pop();
        }
        s.push(i);
    }

    for(int i = 0; i < NGF.size(); i++) {
        cout << NGF[i];
        if(i != NGF.size() - 1) {
            cout << "\n";
        }
    }   
    return 0;
}
