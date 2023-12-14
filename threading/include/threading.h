#include <iostream>
#include <thread>
// #include <pthread.h> // for linux

using namespace std;

class threading
{
public:
    threading(){};
    ~threading(){};

    void a()
    {
        for (int i = 0; i <= 10000; i++)
        {
            if (i % 10 == 0)
                cout << endl
                     << "Inside a() @ " << i << endl;
        }
    };
    void b()
    {
        for (int i = 0; i <= 10000; i++)
        {
            if (i % 10 == 0)
                cout << endl
                     << "Inside b() @ " << i << endl;
        }
    };
};