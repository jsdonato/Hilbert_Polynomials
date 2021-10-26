#ifndef polynomial_hpp
#define polynomial_hpp

#include <stdio.h>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>
#include "term.hpp"
using namespace std;

class Polynomial{
public:
    
    Polynomial(vector<Term> poly);
    
    double evaluate(double d);
    
    size_t degree();
    
    double first_coeff();

    friend ostream& operator<<(ostream& os, const Polynomial& poly);
private:
    
    vector<Term> polynomial;

};

#endif 
