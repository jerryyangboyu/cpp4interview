#include <iostream>

template <typename T>
class SimpleSmartPointer {
public:
    // Constructor
    explicit SimpleSmartPointer(T* ptr = nullptr) : ptr_(ptr), ref_count_(nullptr) {
        if (ptr_) {
            ref_count_ = new size_t(1);
        }
    }

    // Copy constructor
    SimpleSmartPointer(const SimpleSmartPointer& other) : ptr_(other.ptr_), ref_count_(other.ref_count_) {
        if (ref_count_) {
            ++(*ref_count_);
        }
    }

    // Assignment operator
    SimpleSmartPointer& operator=(const SimpleSmartPointer& other) {
        if (this != &other) {
            // Release current resource
            release();

            // Copy resource and reference count
            ptr_ = other.ptr_;
            ref_count_ = other.ref_count_;

            if (ref_count_) {
                ++(*ref_count_);
            }
        }
        return *this;
    }

    explicit operator bool() const {
        return ptr_ != nullptr;
    }

    // Destructor
    ~SimpleSmartPointer() {
        release();
    }

    // Dereference operator
    T& operator*() const {
        return *ptr_;
    }

    // Arrow operator
    T* operator->() const {
        return ptr_;
    }

private:
    T* ptr_;
    size_t* ref_count_;

    // Helper function to release the resource and decrement the reference count
    void release() {
        if (ref_count_) {
            --(*ref_count_);
            if (*ref_count_ == 0) {
                delete ptr_;
                delete ref_count_;
                ptr_ = nullptr;
                ref_count_ = nullptr;
            }
        }
    }
};


int main() {
    SimpleSmartPointer<int> smartPtr1(new int(42));
    SimpleSmartPointer<int> smartPtr2;

    if (smartPtr1) {
        std::cout << "smartPtr1 is not null. Value: " << *smartPtr1 << std::endl;
    } else {
        std::cout << "smartPtr1 is null." << std::endl;
    }

    if (smartPtr2) {
        std::cout << "smartPtr2 is not null. Value: " << *smartPtr2 << std::endl;
    } else {
        std::cout << "smartPtr2 is null." << std::endl;
    }

    return 0;
}
