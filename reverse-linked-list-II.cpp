#include "iostream"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static ListNode* reverseBetween(ListNode* head, int left, int right) {
        return nullptr;
    }
};

int main() {
    auto head = new ListNode(3);
    auto current = head;
    current->next = new ListNode(5);
    current = current->next;
    current->next = new ListNode(4);
    current = current->next;
    current->next = new ListNode(6);
    current = current->next;

    Solution::reverseBetween(head, 1, 2);

    cout << "test data: " << endl;
    while (head != nullptr) {
        cout << head->val << " ";
        auto prev = head;
        head = head->next;
        delete prev;
    }
    cout << endl;
    return 0;
}
