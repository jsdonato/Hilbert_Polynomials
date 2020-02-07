

#include "lambda_algo.hpp"

void lambda_algo::determine_upperbound(){
    int M = 0;
    //TODO: include functionality for determining upper bound.
    upper_bound = M;
}

void lambda_algo::initialize_evaluators(){
    size_t n = p.degree();
    int M = upper_bound;
    for (int i = 0; i <= n; i++){
        targets.push_back(M + 1);
        M++;
    }
}

void lambda_algo::initialize_targets(){
    size_t n = p.degree();
    int M = upper_bound;
    for (int i = 0; i <= n; i++){
        targets.push_back(p.evaluate(M + 1));
        M++;
    }
}

