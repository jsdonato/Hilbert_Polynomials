

#ifndef polynomial_hpp
#define polynomial_hpp

#include <stdio.h>
#include <utility>
#include <vector>
#include <cmath>
#include "term.hpp"
using namespace std;

class Polynomial{
public:
    
    Polynomial(vector<pair<double, int>> poly);
    
    double evaluate(double d);
    
    size_t degree();

private:
    
    vector<Term> polynomial;

};

#endif 
