#include "treasure_island.h"

int main(int args, const char *argv[])
{

    treasure_island obj;
    vector<vector<int>> in = {
            {2147483647,-1,0,2147483647},
            {2147483647,2147483647,2147483647,-1},
            {2147483647,-1,2147483647,-1},
            {0,-1,2147483647,2147483647} };

    obj.islandsAndTreasure(in);

    for(auto& i : in){
        for(auto& j : i) {
            cout << j << " ";

        }
        cout<<endl;
    }

    return 0;
};