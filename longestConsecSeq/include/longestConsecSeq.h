#include <iostream>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class longestConsecSeq
{
public:
    longestConsecSeq(){};
    ~longestConsecSeq(){};

    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return 1;

        set<int> s(nums.begin(), nums.end());
        // sort(s.begin(), s.end());

        int res = 0;
        int c = 1;
        bool first = true;

        for (auto i = s.begin(); i != s.end(); i++)
        {
            if (!first)
            {
                if ((*i - *prev(i)) == 1) // i-1 or i+1 does not work but i++ does!! iterator has advance, prev etc.
                {
                    ++c;
                }
                else
                {
                    res = max(res, c);
                    c = 1;
                }
            }
            else
            {
                first = false;
            }
        }
        res = max(res, c);
        return res;
    }
};