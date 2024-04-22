#include "CircularBuffer_doublyLL.h"
#include <algorithm>


int main(int args, const char *argv[])
{
    int n = 5;
    CircularBuffer<double> obj(n,5);

    for(int i = 0; i < 22; i++) {
        obj.push_back(i+1);
        if ((i+1)%n == 0) {
            for(int j = 0; j < n; j++) {
                cout<<obj[j]<<endl;
            }
            cout<<"-----------"<<endl;
        }
    }
    for(int j = 0; j < n; j++) {
        cout<<obj[j]<<endl;
    }
    cout<<"-----------"<<endl;

    // Would require implemeting iterator class
    // cout<<std::accumulate(obj.begin(), obj.end(), 0);

    return 0;
}