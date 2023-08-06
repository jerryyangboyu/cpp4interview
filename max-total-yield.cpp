#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

class Solution {
public:
    /**
2 3 1 8 -> 14
1 2 0 6 -> 9
8 4 2 14 -> 28
3 1 4 4 -> 12

     */
    static int calculateMaxTotalYie(vector<vector<int>> cropField) {
        // find max row
        int maxRow = std::numeric_limits<int>::min();
        int maxRowIndex = -1;
        for (int i = 0; i < cropField.size(); ++i) {
            int rowSum = accumulate(begin(cropField[i]), end(cropField[i]), 0);
            if (rowSum > maxRow) {
                maxRow = rowSum;
                maxRowIndex = i;
            }
        }
//        cout << "max row index: " << maxRowIndex << endl;

        // find max col
        int maxCol = std::numeric_limits<int>::min();
        int maxColIndex = -1;
        for (int i = 0; i < cropField[0].size(); ++i) {
            int colSum = 0;
            for (int j = 0; j < cropField.size(); ++j) {
                colSum += cropField[j][i];
            }
            if (colSum > maxCol) {
                maxCol = colSum;
                maxColIndex = i;
            }
        }
//        cout << "max col index: " << maxRowIndex << endl;
        // iterate the matrix again, satisfy condition either the rowIndex = maxRowIndex or colIndex = maxColIndex
        // then doubled the value and added to the sum, otherwise just add the value to the sum
        int sum = 0;
        for (int i = 0; i < cropField.size(); ++i) {
            for (int j = 0; j < cropField[0].size(); ++j) {
                int n = cropField[i][j];
                if (i == maxRowIndex || j == maxColIndex)
                    n *= 2;
                sum += n;
//                cout << n << " ";
            }
//            cout << endl;
        }
        return sum;
    }
};

int main() {
    int res;

    int cropField_rows = 0;
    int cropField_cols = 0;
    cin >> cropField_rows >> cropField_cols;
    vector< vector < int > > cropField(cropField_rows);
    for(int cropField_i=0; cropField_i<cropField_rows; cropField_i++) {
        for(int cropField_j=0; cropField_j<cropField_cols; cropField_j++) {
            int cropField_tmp;
            cin >> cropField_tmp;
            cropField[cropField_i].push_back(cropField_tmp);
        }
    }
    res = Solution::calculateMaxTotalYie(cropField);
    cout << res << endl;

    return 0;
}
