#include "atlantic_pacific.h"

int main(int args, const char *argv[])
{
    atlantic_pacific obj;
    vector<vector<int>> in = {{{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}}};

    obj.pacificAtlantic(in);
}