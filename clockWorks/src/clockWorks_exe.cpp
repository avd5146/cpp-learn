#include "clockWorks.h"

int main(int args, const char *argv[])
{
    clockWorks test;
    //constexpr uint16_t lim{numeric_limits<uint16_t>max()};
    for (uint16_t i = 0; i < 10000U; i++){
        test.startClock();
        //cout<<".";
        test.endClock();
    };
    
    cout<<"Total elapsed time: " << double(*test.getTotalTime()) << "seconds" << endl;
    cout<<"cycle count: " << unsigned(*test.getCycleCount()) << endl;
    cout<<"Average time: " << test.getAverageTime() << "seconds" << endl;
}