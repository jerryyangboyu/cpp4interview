#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
private:
    vector<int> heap;

    // Helper functions to maintain the min-heap property
    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[parentIndex] > heap[index]) {
                swap(heap[parentIndex], heap[index]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int n = heap.size();
        while (index < n) {
            int leftChildIndex = 2 * index + 1;
            int rightChildIndex = 2 * index + 2;
            int smallest = index;

            if (leftChildIndex < n && heap[leftChildIndex] < heap[smallest]) {
                smallest = leftChildIndex;
            }

            if (rightChildIndex < n && heap[rightChildIndex] < heap[smallest]) {
                smallest = rightChildIndex;
            }

            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
        if (heap.empty()) {
            cerr << "Heap is empty!" << endl;
            return -1; // Assuming -1 is not a valid element in the heap
        }

        int minElement = heap[0];
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapifyDown(0);
        return minElement;
    }

    int getMin() {
        if (heap.empty()) {
            cerr << "Heap is empty!" << endl;
            return -1; // Assuming -1 is not a valid element in the heap
        }
        return heap[0];
    }

    bool isEmpty() {
        return heap.empty();
    }
};

int main() {
    MinHeap minHeap;
    minHeap.insert(5);
    minHeap.insert(10);
    minHeap.insert(3);
    minHeap.insert(7);
    minHeap.insert(2);

    cout << "Minimum element: " << minHeap.getMin() << endl;

    while (!minHeap.isEmpty()) {
        cout << minHeap.extractMin() << " ";
    }
    cout << endl;

    return 0;
}
