//
// Created by Nick on 2018/11/5.
//
#include <vector>
#include <iostream>

using namespace std;

int cut_rod(vector<int> p, int n) {
    if (n == 0) {
        return 0;
    }
    int q = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        q = max(q, p[i] + cut_rod(p, n - i));
    }
    return q;
}

int memoized_cut_rod_aux(vector<int> p, int n, vector<int> &r) {
    if (r[n] >= 0)
        return r[n];
    if (n == 0)
        return 0;

    int q = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        q = max(q, p[i] + memoized_cut_rod_aux(p, n - i, r));
    }
    r[n] = q;
    return q;
}

int memoized_cut_rod(vector<int> p, int n) {
    vector<int> r(n + 1, INT_MIN);
    return memoized_cut_rod_aux(p, n, r);
}

int bottom_up_cut_rod(vector<int> p, int n) {
    vector<int> r(n + 1, INT_MIN);
    r[0] = 0;

    for (int j = 1; j <= n; ++j) {
        int q = INT_MIN;
        for (int i = 1; i <= j; ++i) {
            q = max(q, p[i] + r[j - i]);
        }
        r[j] = q;
    }
    return r[n];

}

vector<int> extended_bottom_up_cut_rod(vector<int> p, int n, vector<int> &s) {
    vector<int> r(n + 1, INT_MIN);

    r[0] = 0;

    for (int j = 1; j <= n; ++j) {
        int q = INT_MIN;
        for (int i = 1; i <= j; ++i) {
            if (p[i] + r[j - i] > q) {
                q = p[i] + r[j - i];
                s[j] = i;
            }
        }
        r[j] = q;
    }

    return r;
}

void print_cut_rod_solution(vector<int> p, int n, vector<int> &s) {
    vector<int> r = extended_bottom_up_cut_rod(p, n, s);
    cout << r[n] << endl;
    cout << "----------" << endl;
    while (n) {
        cout << s[n] << " ";
        n -= s[n];
    }
}

int main() {
    int n = 7;
    vector<int> p = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    vector<int> s(n + 1, 0);
    print_cut_rod_solution(p, n, s);
}

