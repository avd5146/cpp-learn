#include "threading.h"

int main(int args, const char *argv[])
{

    threading t;
    cout << "Hardware concurrency on this machine is: " << *((unsigned int *)(std::thread::hardware_concurrency)) << endl;
    // Important: thread initiation requires a pointer to the function and an object to the class that contains the function
    std::thread thread_a(&threading::a, t);
    std::thread thread_b(&threading::b, t);

    // This helps prevent an abort error at the end. Looks like this is essential to rejoin processes.
    thread_a.join();
    thread_b.join();
}