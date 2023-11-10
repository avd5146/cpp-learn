#include "inheritance.h"

inheritance::inheritance()
{
    BaseClass obj;
    int out = obj.getter();
    cout<<out<<endl;
    out+=1;
    obj.setter(out);
    cout<<obj.getter()<<endl;
}

inheritance::~inheritance()
{
    
}