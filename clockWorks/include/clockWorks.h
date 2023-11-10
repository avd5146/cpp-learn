#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

class clockWorks
{

public:
    clockWorks(){};
    ~clockWorks(){};

    inline void startClock()
    {
        m_start_time = high_resolution_clock::now();
        m_cycle_count+=uint64_t(1);
    };
    inline void endClock()
    {
        m_end_time = high_resolution_clock::now();
        if(m_cycle_count > 0)
            m_total_time += calcDuration();
    };
    inline const double getAverageTime() {
        return m_cycle_count > 0 ? (m_total_time/double(m_cycle_count)) : double(0.0) ;
    };
    inline const uint64_t* getCycleCount() {return &m_cycle_count;};
    inline const double* getTotalTime() { return &m_total_time;}
    
private:
    inline double calcDuration()
    {
        return (duration_cast<duration<double>>(m_end_time - m_start_time)).count();
    };
    uint64_t m_cycle_count = 0; // TODO: consider overflow
    high_resolution_clock::time_point m_start_time{};
    high_resolution_clock::time_point m_end_time{};
    double m_total_time = 0.0;
};