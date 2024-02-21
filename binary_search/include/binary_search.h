#include <iostream>
#include <vector>

using namespace std;

class binary_search
{
public:
    binary_search(){};
    ~binary_search(){};

    int search(vector<int> &nums, int target)
    {

        if (target > nums.back() || target < nums.front())
            return -1;

        int right = (int)nums.size() - 1;
        int left = 0;

        while (1)
        {
            int p = ceil((left + right) / 2);
            if (nums[p] == target)
                return p;
            else if (nums[p] < target)
                left = p;
            else
                right = p;

            if (left >= right || left + 1 == right)
                break;
        }
        if (target == nums[left])
            return left;
        if (target == nums[right])
            return right;
        return -1;
    }
};