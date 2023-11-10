#include "base2_bitcalc.h"

int main(int args, const char *argv[])
{
    int input = 120;
    cout<<"Input: "<<input<<endl;

    base2_bitcalc obj;
    int out = obj.base2_calcbits(input);
    
    cout<<"Input after running the program: "<<input<<endl;
    cout<<"Output: "<<out<<endl;
}