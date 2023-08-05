#include <array>
#include <stdexcept>
#include <memory>
#include <cassert>

template<typename T>
class ListNode {
public:
    T val;
    std::unique_ptr<ListNode> next;

    explicit ListNode(T val, ListNode *next) : val(val), next(next) {}
};


template<typename T>
class LinkedList {
private:
    std::unique_ptr<ListNode<T>> _startNode = nullptr;
    std::size_t _size = 0;

public:
    LinkedList() = default;

    LinkedList(const LinkedList &) = delete;

    LinkedList &operator=(const LinkedList &) = delete;

    [[maybe_unused]] [[nodiscard]] std::size_t size() const {
        return _size;
    }

    [[nodiscard]] ListNode<T> *getHeadNode() const {
        return _startNode.get();
    }

    [[maybe_unused]] T at(std::size_t index) {
        if (index >= _size) {
            throw std::out_of_range("Index Out of Range");
        }

        auto current = _startNode.get();
        for (std::size_t i = 0; i < index; ++i) {
            current = current->next.get();
        }
        return current->val;
    }

    void add(T val) {
        auto newNode = std::make_unique<ListNode<T>>(val, nullptr);
        this->_size += 1;

        if (_startNode == nullptr) {
            this->_startNode = std::move(newNode);
            return;
        }

        auto node = _startNode.get();
        while (node->next != nullptr) {
            node = node->next.get();
        }
        node->next = std::move(newNode);
    }

    template<class... Arg>
    [[maybe_unused]] static std::unique_ptr<LinkedList<T>> of([[maybe_unused]] Arg... args) {
        std::array<T, sizeof...(args)> argList{args...};
        auto resultList = std::make_unique<LinkedList<T>>();

        for (const auto &arg: argList) {
            resultList->add(arg);
        }

        return resultList;
    }

    ~LinkedList() = default;
};

template<typename T>
std::unique_ptr<ListNode<T>> addTwoNumbers(LinkedList<T> &lst1, LinkedList<T> &lst2, const T threshold = 10) {
    ListNode<T> *head = lst1.getHeadNode();
    int carry = 0;
    ListNode<T> *lst1Ptr = head;
    ListNode<T> *lst2Ptr = lst2.getHeadNode();

    while (lst1Ptr != nullptr || lst2Ptr != nullptr) {
        T sum = carry;
        if (lst2Ptr != nullptr) {
            sum += lst2Ptr->val;
            if (lst1Ptr == nullptr) {
                lst1Ptr = lst2Ptr;
                head = lst1Ptr;
                lst2Ptr = nullptr;
            } else {
                lst2Ptr = lst2Ptr->next.get();
            }
        }
        // if both or only lst1
        sum += lst1Ptr->val;
        lst1Ptr->val = sum % threshold;
        carry = sum >= threshold ? 1 : 0;
        if (lst1Ptr->next == nullptr && lst2Ptr == nullptr && carry == 1) {
            lst1Ptr->next = std::make_unique<ListNode<T>>(1, nullptr);
            return std::unique_ptr<ListNode<T>>(head);
        }
        if (lst1Ptr->next == nullptr && lst2Ptr != nullptr) {
            // Release the ownership of lst2Ptr and assign it to lst1Ptr->next
            lst1Ptr->next.reset(lst2Ptr);
            lst2Ptr = nullptr;
        }
        lst1Ptr = lst1Ptr->next.get();
    }
    return std::unique_ptr<ListNode<T>>(head);
}


int main() {
    // test empty
    LinkedList<int> lst1;
    LinkedList<int> lst2;

    auto pNode = addTwoNumbers(lst1, lst2);

    assert(pNode == nullptr);
}
