

#ifndef pascal_hpp
#define pascal_hpp

#include <stdio.h>
#include <vector>
using namespace std;
class Pascal{
public:
    
    Pascal(size_t size);
    
    unsigned long long Binomial(int n, int k);
    
private:
    
    vector<vector<unsigned long long>> p_triangle;
    
    unsigned long long factorial(size_t n)
    
    vector<unsigned long long> fact;

};

#endif
