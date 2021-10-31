

#ifndef lambda_algo_hpp
#define lambda_algo_hpp

#include <stdio.h>
#include <vector>
#include "polynomial.hpp"
#include "pascal.hpp"
using namespace std;

class lambda_algo{
public:
    lambda_algo(Polynomial &p, size_t UPPER_BOUND);
    
    void check_lambda(Polynomial &p);
    
    void determine_upperbound();
    
    void initialize_evaluators(Polynomial &p);
    
    void initialize_targets(Polynomial &p);
    
    void zero_run();
    
    void first_run();
    
    uint32_t accumulate(vector<int> &x, int d);
    
    void use(vector<int> &x);
    
    void weak_comp(int N, int K);
    
    void run();
    
    vector<uint32_t> Result();
private:
    Pascal t;
    
    vector<double> targets;
    vector<int> evaluators;
    vector<uint32_t> sum_of_first;
    
    vector<uint32_t> result;
   
    int upper_bound;
    unsigned long long lower_bound;
    size_t poly_degree;
    
    bool success;
};

#endif /* lambda_algo_hpp */
