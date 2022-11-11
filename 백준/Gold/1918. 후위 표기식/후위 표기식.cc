#include <iostream>
#include <stack>
#include <string>

#define endl '\n'

using namespace std;

int priority(char o) {
    if (o == '(' || o == ')') {
        return 0;
    }
    else if (o == '*' || o == '/') {
        return 1;
    }
    else {
        return 2;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    stack<char> s;

    string e;
    cin >> e;

    string answer;
    for (int i = 0; i < e.size(); i++) {
        if (isalpha(e[i])) {
            answer += e[i];
        }
        else {
            if (s.empty()) {
                s.push(e[i]);
            }
            else {
                if (e[i] == '(') {
                    s.push(e[i]);
                }
                else if (e[i] == ')') {
                    while (s.top() != '(') {
                        answer += s.top();
                        s.pop();
                    }
                    s.pop(); // '(' 와 ')'는 식에 포함 안시킴.
                }
                else if (priority(e[i]) >= priority(s.top()) && s.top() != '(') {
                    while (!s.empty() && (priority(e[i]) >= priority(s.top())) && s.top() != '(') {
                        answer += s.top();
                        s.pop();
                    }
                    s.push(e[i]);
                }
                else {
                    s.push(e[i]);
                }
            }
        }
    }
    while (!s.empty()) {
        answer += s.top();
        s.pop();
    }

    cout << answer << endl;

    return 0;
}

