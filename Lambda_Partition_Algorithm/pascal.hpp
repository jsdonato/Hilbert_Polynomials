

#ifndef pascal_hpp
#define pascal_hpp

#include <stdio.h>
#include <vector>
using namespace std;
class Pascal{
public:
    
    Pascal();
    
    unsigned long long Binomial(int n, int k);
    
    unsigned long long factorial(size_t n);
    
private:
    
    vector<vector<unsigned long long>> p_triangle;
    
    vector<unsigned long long> fact;

};

#endif
