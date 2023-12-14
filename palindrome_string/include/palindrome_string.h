#include <iostream>

using namespace std;

class palindrome_string
{
public:
    palindrome_string(){};
    ~palindrome_string(){};

    void cleanData(string &s)
    {
        int run_l = s.size();
        for (int i = 0; i < run_l; i++)
        {
            if (isupper(s[i]) || islower(s[i]))
                s[i] = tolower(s[i]);
            else if (isdigit(s[i]))
            {
                // do nothing
            }
            else
            {
                s.erase(i, 1);
                --run_l;
                --i;
            }
        }
    };

    bool isPalindrome(string s)
    {
        bool res = true;
        cleanData(s);

        if (s.size() <= 1)
            return true;

        std::string::iterator start = s.begin();
        std::string::iterator end = s.end() - 1;

        while (!((start == end) || (end == start + 1)))
        {
            if (*start != *end)
                return false;
            ++start;
            --end;
        }
        if (end == start + 1)
        {
            if (*start != *end)
                return false;
            else
                return true;
        }
        return res;
    }
};