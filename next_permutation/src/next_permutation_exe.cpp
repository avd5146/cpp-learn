#include "next_permutation.h"
// #include "general.h"

int main(int args, const char *argv[])
{
    Solution obj;
    // vector<int> in = {1, 0, 0, 1};
    vector<int> in = {1, 2};
    obj.nextPermutation(in);
    obj.printV(in);
}