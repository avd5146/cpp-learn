#include "roman2string.h"
#include <string>
#include <unordered_map>

roman2string::roman2string(const int &num) : num_(num)
{

    unordered_map<int, string> r2s_map = {
        {1, "I"},
        {2, "II"},
        {3, "III"},
        {4, "IV"},
    };
    // extract the digits
    uint8_t factor = 10;
    uint8_t n = 0;
    string out = "";

    while (int(num / pow(factor, n)) > 0)
    {

        int temp = num % (int(pow(factor, n + 1)));
        cout << std::to_string(temp) << endl;

        // compare the temp in ranges
        string t_str = "";

        // add the roman to string
        out = t_str + out;
        n++;
    }
}

roman2string::~roman2string() {}