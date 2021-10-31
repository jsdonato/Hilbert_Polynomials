

#ifndef pascal_hpp
#define pascal_hpp

#include <stdio.h>
#include <vector>
using namespace std;
class Pascal{
public:
    
    Pascal();
    
    uint64_t Binomial(int n, int k);
    
    uint64_t factorial(size_t n);
    
private:
    
    vector<vector<uint64_t>> p_triangle;
    
    vector<uint64_t> fact;

};

#endif
