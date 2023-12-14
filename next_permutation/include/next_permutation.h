#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include <algorithm>
class Solution
{
public:
    template <class T>
    void printV(const vector<T> &in)
    {
        for (auto iter : in)
        {
            cout << iter << endl;
        }
    }
    void nextPermutation(vector<int> &nums)
    {

        // largest check
        bool check = true;
        for (uint8_t i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] >= nums[i + 1])
            {
                // check passed
            }
            else
            {
                check = false;
            }
        }
        if (check)
        {
            // send out sorted nums
            reverse(nums.begin(), nums.end());
            return;
        }

        vector<int>::iterator c = nums.end();
        while (c > nums.begin())
        {
            if (*c > *(c - 1))
            {
                std::iter_swap(c, c - 1);
                if (c < nums.end())
                {
                    sort(c, nums.end());
                }
                return;
            }
            else
            {
                c = c - 1;
            }
        }
    }
};