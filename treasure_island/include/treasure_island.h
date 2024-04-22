#include <iostream>
#include <vector>

using namespace std;

class treasure_island
{
public:
    treasure_island(){};
    ~treasure_island(){};

    int R,C = 0;

    void checkTreasure(vector<vector<int>>& grid, bool t, int r, int c, int cd)
    {
        if (t && grid[r][c] > 0)
            grid[r][c] = min(cd, grid[r][c]);

        return;
    }

    void dfs(vector<vector<int>>& grid, int r, int c, int& current_distance, bool& treasure, vector<vector<bool>>& visited)
    {
        if (r >= R || c >= C || r < 0 || c < 0)
            return;
        if (visited[r][c])
            return;
        if (treasure){
            // grid[r][c] = min(current_distance, grid[r][c]);
            return;
        }
        if (grid[r][c] == 0)
        {
            treasure = true;
            return;
        }

        visited[r][c] = true;
        ++current_distance;
        
        int d1 = 0;
        int d2 = 0;
        int d3 = 0;
        int d4 = 0;
        bool t1 = false;
        bool t2 = false;
        bool t3 = false;
        bool t4 = false;       
        
        dfs(grid, r, c-1, d1, t1, visited);
        dfs(grid, r-1, c, d2, t2, visited);
        dfs(grid, r, c+1, d3, t3, visited);
        dfs(grid, r+1, c, d4, t4, visited);

        treasure = (t1 || t2 || t3 || t4);
        current_distance += min(d1,min(d2,min(d3,d4)));
        return;
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        R = grid.size();
        C = grid.size();

        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                vector<vector<bool>> visited(R, vector<bool>(C, false));
                bool treasure = false;
                int d = 0;
                dfs(grid, i, j, d, treasure, visited);
                checkTreasure(grid, treasure, i, j, d);
            }
        }
    }
};
