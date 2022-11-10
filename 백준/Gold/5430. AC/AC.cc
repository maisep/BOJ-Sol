#include <iostream>
#include <deque>
#include <string>

#define endl '\n'
#define INF 123456789

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    string p;
    int n;
    string arr;
    deque<int> dq;
    bool is_forward = true;
    bool is_error = false;
    for (int t = 0; t < T; t++) {
        cin >> p >> n >> arr;

        string tmp = "";
        if (n > 0) {
            for (int i = 1; i < arr.length() - 1; i++) {
                if (arr[i] == ',') {
                    dq.push_back(stoi(tmp));
                    tmp = "";
                }
                else {
                    tmp += arr[i];
                }
            }
            dq.push_back(stoi(tmp));
        }

        is_forward = true;
        is_error = false;
        for (int i = 0; i < p.length(); i++) {
            if (p[i] == 'R') {
                is_forward = !is_forward;
            }
            else {
                if (n == 0) {
                    is_error = true;
                    break;
                }
                else {
                    if (is_forward) {
                        dq.pop_front();
                        n--;
                    }
                    else {
                        dq.pop_back();
                        n--;
                    }
                }
            }
        }

        string print_buff = "";
        if (!is_error) {
            print_buff += "[";
            while (!dq.empty()) {
                if (is_forward) {
                    print_buff += to_string(dq.front());
                    dq.pop_front();
                }
                else {
                    print_buff += to_string(dq.back());
                    dq.pop_back();
                }
                print_buff += ",";
            }

            if (print_buff[print_buff.length() - 1] == ',')
                print_buff[print_buff.length() - 1] = ']';
            else
                print_buff += "]";
        }
        else {
            print_buff = "error";
        }
        cout << print_buff << endl;
    }

    return 0;
}