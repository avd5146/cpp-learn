#include "base_class.h"

BaseClass::BaseClass()
{
    this->m_int = 2;
}

int BaseClass::getter()
{
    return this->m_int;
}

void BaseClass::setter(int& in)
{
    this->m_int = in;
}