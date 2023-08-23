//#include <queue>
//#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> A {9, 4, 2, 10, 7, 8, 8, 1, 9};
    sort(A.begin(), A.end());

    for (auto i : A) {
        cout << i << endl;
    }
//    priority_queue<int, vector<int>, greater<>> pq;
//
//    for (int i = 0; i < 10; ++i) {
//        pq.push(rand() % 10);
//    }
//
//    for (int i = 0; i < 10; ++i) {
//        cout << pq.top() << endl;
//        pq.pop();
//    }

    return 0;

//    make_heap(A);
//    int smallest = A[0];
//    int result = 1;
//    pop_heap(A);
//    while (result >= smallest) {
//        result += 1;
//        smallest = A[0];
//        pop_heap(A);
//    }
//    return result;
}
