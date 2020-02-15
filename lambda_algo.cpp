

#include "lambda_algo.hpp"
#include <iostream>
using namespace std;

lambda_algo::lambda_algo(Polynomial &p){
    check_lambda(p);
    determine_upperbound();
}

lambda_algo::check_lambda(const Polynomial &p) {
    int degree = p[0].second;
    lower_bound = factorial(degree - 1);
}

lambda_algo::factorial(int n) {
    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

void lambda_algo::determine_upperbound(){
    int M = 0;
    cout << "INPUT UPPER BOUND FOR LAMBDA PARTITION: ";
    cout << '\n' << "(Note: It should be greater than " << lower_bound << " )" << '\n';
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

