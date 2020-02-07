

#ifndef lambda_algo_hpp
#define lambda_algo_hpp

#include <stdio.h>
#include <vector>
#include "polynomial.hpp"
using namespace std;

class lambda_algo{
public:
    lambda_algo(Polynomial poly);
    
    void determine_upperbound();
    
    void initialize_evaluators();
    
    void initialize_targets();
private:
    Polynomial p;
    vector<int> targets;
    vector<int> evaluators;
    int upper_bound;
   
};

#endif /* lambda_algo_hpp */
