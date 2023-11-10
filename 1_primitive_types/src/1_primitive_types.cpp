#include "1_primitive_types.h"

primitive_types::primitive_types ()
{
    // int a = 2;
    // int b = a>>1;
    // cout<<"right shift 2 by 1 bit : "<<b<<endl;
    // a=a<<1;
    // cout<<"left shift 2 by 1 bit : "<<a<<endl;
    // a=a<<1;
    // cout<<"left shift 2 by 2 bits : "<<a<<endl;
    // int c = 126;
    // c=c>>1;
    // cout<<"right shift 126 by 1 bit : "<<c<<endl;
    // c=c<<2;
    // cout<<"left shift 126 by 1 bit : "<<c<<endl;

    int a = 3;
    a>>=1;
    cout<<"right shift 3 by 1 bit : "<<a<<endl;
    a>>=1;
    cout<<"right shift 3 by 2 bit : "<<a<<endl;
    a>>=1;
    cout<<"right shift 3 by 3 bit : "<<a<<endl;
    a>>=1;
    cout<<"right shift 3 by 4 bit : "<<a<<endl;

    uint8_t b = 1U;
    b = ~b;
    cout<<"1 ~ = "<<unsigned(b)<<endl;

}

primitive_types::~primitive_types ()
{
    
}