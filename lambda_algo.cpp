

#include "lambda_algo.hpp"
#include <iostream>
using namespace std;

lambda_algo::lambda_algo(Polynomial &p){
    determine_upperbound();
}

void lambda_algo::determine_upperbound(){
    int M = 0;
    cout << "INPUT UPPER BOUND FOR LAMBDA PARTITION: ";
    cin >> M;
    upper_bound = M;
}

void lambda_algo::initialize_evaluators(Polynomial &p){
    size_t n = p.degree();
    int M = upper_bound + 1;
    for (int i = 0; i <= n; i++){
        evaluators.push_back(M);
        M++;
    }
}

void lambda_algo::initialize_targets(Polynomial &p){
    size_t n = p.degree();
    int M = upper_bound + 1;
    for (int i = 0; i <= n; i++){
        targets.push_back(p.evaluate(M));
        M++;
    }
}

