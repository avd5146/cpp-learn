#include "app_test.h"
#include "1_primitive_types.h"
#include "general.h"

int main(int args, const char *argv[])
{
    app_test obj;
    vector<int> v(5);
    Utils::printV(v);
    
    cout<<"App 1 done."<<endl;
    return 0;
}