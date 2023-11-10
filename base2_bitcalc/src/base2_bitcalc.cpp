#include "base2_bitcalc.h"

base2_bitcalc::base2_bitcalc()
{

}

int base2_bitcalc::base2_calcbits(int& in)
{
    int ans = 0;
    while(in/2 > 0){
        ans+=1;
        in/=2;
    }
    return ans;

}

base2_bitcalc::~base2_bitcalc()
{

}