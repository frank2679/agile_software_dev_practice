#include "foo.h"

#include <iostream>
int Foo::PrintFoo() {
    std::cout << __FUNCTION__ << std::endl;
    return 0;
}