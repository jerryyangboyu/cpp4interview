#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

struct CompareNodes {
    bool operator()(const ListNode *a, const ListNode *b) {
        return a->val > b->val;
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<ListNode *, vector<ListNode *>, CompareNodes> pq;

    // Push the first node from each list into the priority queue
    for (ListNode *head: lists) {
        if (head) {
            pq.push(head);
        }
    }

    // Initialize the dummy head of the merged list
    ListNode *mergedHead = new ListNode(-1);
    ListNode *current = mergedHead;

    // Merge the lists using the priority queue
    while (!pq.empty()) {
        // Pop the node with the smallest value from the priority queue
        ListNode *node = pq.top();
        pq.pop();

        // Append this node to the merged list
        current->next = node;
        current = current->next;

        // Push the next node from the same list into the priority queue (if available)
        if (node->next) {
            pq.push(node->next);
        }
    }

    return mergedHead->next;
}

// Helper function to convert a vector to a linked list
ListNode *vectorToLinkedList(const vector<int> &vec) {
    ListNode *head = nullptr;
    ListNode *current = nullptr;
    for (int val: vec) {
        if (!head) {
            head = new ListNode(val);
            current = head;
        } else {
            current->next = new ListNode(val);
            current = current->next;
        }
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode *head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    vector<vector<int>> lists = {{1, 4, 5},
                                 {1, 3, 4},
                                 {2, 6}};
    vector<ListNode *> linkedLists;

    linkedLists.reserve(lists.size());
    for (const auto &list: lists) {
        linkedLists.push_back(vectorToLinkedList(list));
    }

    ListNode *mergedList = mergeKLists(linkedLists);

    printLinkedList(mergedList);

    // Don't forget to free the memory
    while (mergedList) {
        ListNode *temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}
