#include "bits/stdc++.h"
#include <ranges> // only in C++20

using namespace std;

// Define a concept for types that are instantiations of std::vector
template<typename T>
concept VectorOf = requires {
    typename T::value_type;
    requires std::same_as<T, std::vector<typename T::value_type>>;
    requires std::forward_iterator<decltype(std::declval<T>().begin())>;
    requires std::forward_iterator<decltype(std::declval<T>().end())>;
};

// Base case: If Tp is not a vector type, wrap it in a vector
template<typename Tp>
std::vector<Tp> flatten(Tp base) requires (!VectorOf<Tp>) {
    return {base};
}

// Recursive case: If the input is a vector, flatten its elements
template<VectorOf Container>
auto flatten(const Container &nested) {
    using InnerType = typename Container::value_type;
    return std::accumulate(
            nested.begin(), nested.end(), std::vector<InnerType>(),
            [](auto acc, const auto &curr) {
                auto flattened = flatten(curr);
                acc.insert(acc.end(), flattened.begin(), flattened.end());
                return acc;
            }
    );
}

int main() {
    // flat 2 dimensional vector
    vector<vector<int>> nested_lst = {{1, 2, 3},
                                      {4, 5},
                                      {6, 7, 8, 9}};
    // C++20 style
    auto joined_view = nested_lst | std::views::join;
    std::copy(joined_view.begin(), joined_view.end(), std::ostream_iterator<int>(std::cout, " "));
    cout << endl;

    // before C++ 20
    std::vector<int> flattened_lst = std::accumulate(
            nested_lst.begin(), nested_lst.end(), std::vector<int>(),
            [](auto acc, const auto &curr) {
                acc.insert(acc.end(), curr.begin(), curr.end());
                return acc;
            }
    );
    std::copy(flattened_lst.begin(), flattened_lst.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;

    auto pl = std::accumulate(nested_lst.begin(), nested_lst.end(), vector<int>(),
                         [](auto acc, auto &curr) {
                             acc.insert(acc.end(), curr.begin(), curr.end());
                         });
    copy(pl.begin(), pl.end(), ostream_iterator<int>(cout, " "));



    cout << "using single accumulate: ";
    copy(flattened_lst.begin(), flattened_lst.end(), ostream_iterator<int>(cout, " "));
    auto flattened_lst_recur = flatten(nested_lst);
    cout << endl << "using recursive accumulate: ";
    copy(flattened_lst_recur.begin(), flattened_lst_recur.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}
