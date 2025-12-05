#include <bits/stdc++.h>
using namespace std;

bool sol(vector<int> arr) {
    int n = arr.size();
    queue<int> q;
    for (int x : arr) q.push(x);
    stack<int> st;
    int need = 1;
    while (!q.empty() || !st.empty()) {
        if (!q.empty() && q.front() == need) {
            q.pop();
            need++;
        } else if (!st.empty() && st.top() == need) {
            st.pop();
            need++;
        } else if (!q.empty()) {
            st.push(q.front());
            q.pop();
        } else {
            return false;
        }
    }
    return (need == n+1);
}

