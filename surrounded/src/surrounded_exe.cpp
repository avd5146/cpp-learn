#include "surrounded.h"

int main() {
    Solution s;

    vector<vector<char>> in = 
    {{'O','O','O','O','X','X'},
    {'O','O','O','O','O','O'},
    {'O','X','O','X','O','O'},
    {'O','X','O','O','X','O'},
    {'O','X','O','X','O','O'},
    {'O','X','O','O','O','O'}};
    
    s.solve(in);
    return 0;
}