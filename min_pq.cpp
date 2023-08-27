#include <queue>
#include <iostream>

using namespace std;

int main() {
    // min pq
    // Caveat: push() function copy the object into vector
    // emplace() function copy the reference of object into vector
    priority_queue<int, vector<int>, greater<>> pq;
    pq.push(10);
    pq.push(8);
    pq.push(9);
    pq.push(2);
    pq.push(7);

    for (int i = 0; i < 5; ++i) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}