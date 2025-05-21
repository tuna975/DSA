class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> a;

        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    a.push_back({i, j});
                }
            }
        }

        for (auto [row, col] : a) {
            rowz(matrix[row], n);
            colz(matrix, m, col);
        }
    }

    void rowz(vector<int>& row, int n) {
        for (int i = 0; i < n; ++i) {
            row[i] = 0;
        }
    }

    void colz(vector<vector<int>>& matrix, int m, int idx) {
        for (int i = 0; i < m; ++i) {
            matrix[i][idx] = 0;
        }
    }
};