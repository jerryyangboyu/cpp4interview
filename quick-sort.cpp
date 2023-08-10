#include <iostream>
#include <vector>

// Insertion Sort implementation
void insertion_sort(std::vector<int> &arr, int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Quick Sort implementation
void quick_sort(std::vector<int> &arr, int low, int high, int threshold) {
    if (low < high) {
        if (high - low + 1 <= threshold) {
            insertion_sort(arr, low, high);
            return;
        }

        int pivot = arr[(low + high) / 2];
        int i = low, j = high;

        while (i <= j) {
            while (arr[i] < pivot)
                i++;
            while (arr[j] > pivot)
                j--;

            if (i <= j) {
                std::swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        if (low < j)
            quick_sort(arr, low, j, threshold);
        if (i < high)
            quick_sort(arr, i, high, threshold);
    }
}

// Test the implementation
int main() {
    std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int threshold = 10;

    quick_sort(arr, 0, arr.size() - 1, threshold);

    for (int num: arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
