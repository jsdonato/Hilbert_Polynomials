

#ifndef lambda_algo_hpp
#define lambda_algo_hpp

#include <stdio.h>
#include <vector>
#include "polynomial.hpp"
using namespace std;

class lambda_algo{
public:
    lambda_algo(Polynomial &p);
    
    void determine_upperbound();
    
    void initialize_evaluators(Polynomial &p);
    
    void initialize_targets(Polynomial &p);
private:
    vector<int> targets;
    vector<int> evaluators;
    void check_lambda(const Polynomial &p);
    int factorial(int n)
    int upper_bound;
    int lower_bound;
};

#endif /* lambda_algo_hpp */
