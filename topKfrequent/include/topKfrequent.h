#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

class topKfrequent
{
public:
    // static is important here..but why??
    static bool compare(std::pair<int, int> p1, std::pair<int, int> p2)
    {
        return p1.second > p2.second;
    };

    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        std::unordered_map<int, int> m;
        std::vector<int> res;
        // res.resize(k);

        for (auto &n : nums)
        {
            m[n]++;
        }

        vector<pair<int, int>> v;
        for (auto &elem : m)
        {
            v.push_back({elem.first, elem.second});
        }

        sort(v.begin(), v.end(), compare); // doesnt work with map directly..dont know why
        int c = 0;
        for (auto &elem : v)
        {
            res.push_back(elem.first);
            ++c;
            if (c >= k)
                return res;
        }
        return res;
    }
};