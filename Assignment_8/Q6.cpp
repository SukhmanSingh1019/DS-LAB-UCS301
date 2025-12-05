#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> heap;
public:
    PriorityQueue() {
        heap.push_back(-1); 
    }
    void heapifyDown(int i) {
        int n = heap.size() - 1;

        while (true) {
            int left = 2 * i;
            int right = 2 * i + 1;
            int largest = i;

            if (left <= n && heap[left] > heap[largest])
                largest = left;

            if (right <= n && heap[right] > heap[largest])
                largest = right;

            if (largest != i) {
                swap(heap[i], heap[largest]);
                i = largest;  
            } else break;
        }
    }

    void heapifyUp(int i) {
        while (i > 1) {
            int parent = i / 2;

            if (heap[i] > heap[parent]) {
                swap(heap[i], heap[parent]);
                i = parent;
            } else break;
        }
    }
   
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int top() {
        if (heap.size() <= 1)
           return -1;
        return heap[1];
    }

    void pop() {
        if (heap.size() <= 1) {
            cout << "Priority Queue empty\n";
            return;
        }

        heap[1] = heap.back();
        heap.pop_back();
        heapifyDown(1);
    }

    bool empty() {
        return heap.size() <= 1;
    }

    int size() {
        return heap.size() - 1;
    }
};

int main() {
    PriorityQueue pq;

    pq.push(50);
    pq.push(30);
    pq.push(40);
    pq.push(10);
    pq.push(60);

    cout << "Top: " << pq.top() << endl;

    pq.pop();
    cout << "Top after pop: " << pq.top() << endl;

}

