
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
  
        auto getPos = [&](int num) {
            int r = n - 1 - (num - 1) / n;
            int c = (num - 1) % n;
            if ((n - r) % 2 == 0) c = n - 1 - c;
            return make_pair(r, c);
        };
    
        vector<bool> visited(n * n + 1, false); 
        queue<pair<int, int>> q; 
        q.push({1, 0}); 
        visited[1] = true;

        while (!q.empty()) {
            auto [curr, moves] = q.front(); q.pop();
            for (int dice = 1; dice <= 6; dice++) {
                int next = curr + dice;
                if (next > n * n) continue;

                auto [r, c] = getPos(next);
                if (board[r][c] != -1) next = board[r][c];
     

                if (next == n * n) return moves + 1;
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }
        return -1;
    }
};