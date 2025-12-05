#include <bits/stdc++.h>
using namespace std;

int sol(vector<int>& students, vector<int>& sandwiches) {
    int count0 = 0, count1 = 0;
    for (int s : students) (s == 0 ? count0++ : count1++);

    for (int s : sandwiches) {
        if (s == 0) {
            if (count0 == 0) return count1;
            count0--;
        } else {
            if (count1 == 0) return count0;
            count1--;
        }
    }
    return 0;
}


