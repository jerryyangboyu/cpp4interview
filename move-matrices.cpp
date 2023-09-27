#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> solution(vector<vector<int>> numbers) {
    int n = numbers[0].size();
    map<int, vector<int>> m;
    vector<int> indices;
    for (int i = 0; i < n; i += 2) {
        vector<int> temp {numbers[0][i], numbers[0][i + 1], numbers[1][i], numbers[1][i + 1]};
        int result = 1;
        sort(temp.begin(), temp.end());
        for (auto n: temp) {
            if (n == result) {
                result++;
            } else {
                break;
            }
        }
        m[result].push_back(i);
        indices.push_back(result);
    }

    sort(indices.begin(), indices.end());

    // for (auto item: m) {
    //     cout << item.first << " ";
    //     copy(item.second.begin(), item.second.end(), ostream_iterator<int>(cout, " "));
    //     cout << endl;
    // }

    vector<vector<int>> res;
    res.push_back(vector<int>(n, 0));
    res.push_back(vector<int>(n, 0));

    int start = 0;
    for (int i = 0; i < indices.size(); ++i) {
        if (i > 0 && indices[i] == indices[i - 1]) {
            continue;
        }
        int index = indices[i];
        cout << "start index " << index << endl;
        for (int vectorStart: m[index]) {
            cout << "index: " << index << "vector start: " << vectorStart << endl;
            res[0][start*2] = numbers[0][vectorStart];
            res[0][start*2+1] = numbers[0][vectorStart + 1];
            res[1][start*2] = numbers[1][vectorStart];
            res[1][start*2 + 1] = numbers[1][vectorStart + 1];
            start++;
        }
    }

    /**
    [[1,4,12,11,3,1,1,2],
 [5,3,1,10,1,2,3,6]]
    **/

    return res;
}
