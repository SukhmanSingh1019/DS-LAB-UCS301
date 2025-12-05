#include <bits/stdc++.h>
using namespace std;

int minIndex(queue<int> &q, int sortedIndex) {
    int minIndex = -1;
    int minValue = INT_MAX;
    int n = q.size();

    for (int i = 0; i < n; i++) {
        int current = q.front();
        q.pop();

        if (current <= minValue && i <= sortedIndex) {
            minIndex = i;
            minValue = current;
        }

        q.push(current);
    }
    return minIndex;
}

void insertMinToRear(queue<int> &q, int minIndex) {
    int minValue;
    int n = q.size();

    for (int i = 0; i < n; i++) {
        int current = q.front();
        q.pop();

        if (i != minIndex)
            q.push(current);
        else
            minValue = current;
    }
    q.push(minValue);
}

void sortQueue(queue<int> &q) {
    for (int i = 1; i <= q.size(); i++) {
        int min_index = minIndex(q, q.size() - i);
        insertMinToRear(q, min_index);
    }
}
