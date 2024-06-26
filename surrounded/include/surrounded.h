#include <vector>

using namespace std;

class Solution {
public:

    int m = 0; int n = 0;
    
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == 'O')
                    dfs(board, i, j, visited);
            }
        }        
    }
    bool dfs(vector<vector<char>>& b, const int& i, const int& j,vector<vector<bool>>& visited)
    {
        // if starting from i,j, we can reach boundary without passing through an X, that means do not flip.
        
        if ( i <= 0 || j <= 0 || i >= m-1 || j >= n-1) // reached boundary or invalid
        {
            if (b[i][j] == 'X')
                return false;
            else
                return true;
        }
        if (b[i][j] == 'X') {
            visited[i][j] = true;
            return false;   
        }
        if (visited[i][j])
            return false;
        
        visited[i][j] = true;
        
        bool left = dfs(b,i,j-1,visited);
        bool up = dfs(b,i-1,j,visited);
        bool right = dfs(b,i,j+1,visited);
        bool down = dfs(b,i+1,j,visited);
    
        if (!(left || right || up || down))
            b[i][j] = 'X';
        return (left || right || up || down);
    }
};