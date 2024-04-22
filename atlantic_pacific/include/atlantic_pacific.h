#include <iostream>
#include <vector>

using namespace std;

class atlantic_pacific
{
public:
    atlantic_pacific(){};
    ~atlantic_pacific(){};

private:
    int R = 0;
    int C = 0;

    void printV(vector<bool> in){
        for (const auto& i : in) {
            cout<<i<<" ";
        }
        cout<<endl;
    };

    pair<bool,bool> search(int r, int c, int val, const vector<vector<int>>& m, vector<vector<bool>>& visited) {
        // cout<<r<<" "<<c<<endl;
        bool pacific = false;
        bool atlantic = false;
        if (r < 0 || c < 0)
            pacific = true;
        if (r == R || c == C)
            atlantic = true;
        if (atlantic || pacific) 
            return {pacific,atlantic}; 
        
        if (m[r][c] <= val && !visited[r][c])
        {
            visited[r][c] = true;
            
            pair<bool,bool> temp = (search(r,c-1,m[r][c], m,visited));
            pacific = temp.first;
            atlantic = temp.second;
            
            temp = (search(r-1,c,m[r][c], m,visited));
            if (!pacific) 
                pacific = temp.first;
            if(!atlantic)
                    atlantic = temp.second;
            
            
            temp = (search(r,c+1,m[r][c], m,visited));
            if (!atlantic)
                atlantic = temp.second;
            if(!pacific)
                pacific = temp.first;
            temp = (search(r+1,c,m[r][c], m,visited));
            if (!atlantic)
                atlantic = temp.second;
            if(!pacific)
                pacific = temp.first;
        }
        return {pacific,atlantic};
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;

        R = heights.size();
        C = heights[0].size();
        
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                cout<<"i: "<<i<<" "<<"j: "<<j<<endl;
                vector<vector<bool>> visited(R, vector<bool>(C, false)); // missing piece
                pair<bool,bool> reaching = search(i,j,heights[i][j],heights, visited);
                
                if(reaching.first && reaching.second)
                    res.push_back({i,j});
            }
        }
        for(auto i : res) {
            for (auto ii : i) {
                cout<<ii<<",";
            }
            cout<<endl;
        }
        return res;
    }
};