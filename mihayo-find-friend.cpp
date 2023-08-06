#include <iostream>
#include <string>
#include <vector>

using namespace std;

int find_friendship(int word_number) {
    int capacity = 0;
    vector<string> expect_words;
    string word;

    // read expect words
    for (int j = 0; j < word_number; ++j) {
        cin >> word;
        expect_words.push_back(word);
    }

    // read actual words
    for (int j = 0; j < word_number; ++j) {
        cin >> word;
        if (word != expect_words[j]) {
            capacity -= 1;
            if (capacity < 0) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return 0;
            }
        } else {
            capacity += 1;
        }
    }

    return 1;
}

int main() {
    int round_number, word_number, friendship_count = 0;
    cin >> round_number;
    for (int i = 0; i < round_number; ++i) {
        cin >> word_number;
        friendship_count += find_friendship(word_number);
    }
    cout << friendship_count;
}
