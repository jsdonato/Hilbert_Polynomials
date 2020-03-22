

#include "lambda_algo.hpp"
#include <iostream>
#include <cmath>
using namespace std;

lambda_algo::lambda_algo(Polynomial &p){
    success = false;
    
    check_lambda(p);
    determine_upperbound();
    
    initialize_evaluators(p);
    initialize_targets(p);
    
    zero_run();
    if (success == true){
        cout << "SUCCESS! Lambda partition: {";
        /*for (int i = 0; i < lower_bound - 1; i++){
            cout << poly_degree + 1 << ", ";
        }
        cout << poly_degree + 1 << "}\n";*/
        for (int i = 0; i < lower_bound; i++){
            result.push_back(poly_degree + 1);
        }
        
        for (int i = 0; i < result.size() - 1; i++){
            cout << result[i] << ", ";
        }
        
        cout << result[result.size() - 1] << "}\n";
        
    }
    if (success == false){
        first_run();
        if (success == false){
            run();
        }
    }
}

void lambda_algo::check_lambda(Polynomial &p) {
    poly_degree = p.degree();
    lower_bound = ceil((double)t.factorial(poly_degree) * p.first_coeff());
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

void lambda_algo::zero_run(){
    int lambda_max = (int)poly_degree + 1;
    
    for (int i = 0; i < targets.size(); i++){
        unsigned long long sum = 0;
        for (int j = 1; j <= lower_bound; j++){
            sum += t.Binomial(evaluators[i] + lambda_max - j, lambda_max - 1);
        }
        sum_of_first.push_back(sum);
    }
    
    for (size_t i = 0; i < sum_of_first.size(); i++){
        if (abs(sum_of_first[i] - targets[i]) > .0000000001){
            success = false;
            return;
        }
    }
    
    
    success = true;
}

void lambda_algo::first_run(){
    for (int lambda = (int)poly_degree; lambda > 0; lambda--){
        for (int i = 0; i < targets.size(); i++){
            unsigned long long sum = 0;
            sum = sum_of_first[i] + t.Binomial(evaluators[i] + lambda - ((int)lower_bound + 1), lambda - 1);
            if (abs(sum - targets[i]) > .0000000001){
                break;
            }
            else if (i == targets.size() - 1 && abs(sum - targets[i]) < .0000000001){
                cout << "SUCCESS! Lambda partition: {";
                /*for (int i = 0; i < lower_bound; i++){
                    cout << poly_degree + 1 << ", ";
                }
                cout << lambda << "}\n";*/
                for (int i = 0; i < lower_bound; i++){
                    result.push_back(poly_degree + 1);
                }
                result.push_back(lambda);
                
                for (int i = 0; i < result.size() - 1; i++){
                    cout << result[i] << ", ";
                }
                
                cout << result[result.size() - 1] << "}\n";
                
                success = true;
                return;
            }
        }
    }
    success = false;
}


unsigned long long lambda_algo::accumulate(vector<int> &x, int d){
    unsigned long long sum = 0;
    int k = 1;
    for (int i = 0; i < x.size(); i++){
        for (int j = 0; j < x[i]; j++){
            sum += t.Binomial(d + ((int)poly_degree - i) - k - (int)lower_bound, ((int)poly_degree - i) - 1);
            k++;
        }
    }
    return sum;
}

void lambda_algo::use(vector<int> &x){
    for (int i = 0; i < targets.size(); i++){
        unsigned long long num = sum_of_first[i] + accumulate(x, evaluators[i]);
        
        if (abs(num - targets[i]) > .0000000001){
            return;
        }
        
        else if (i == targets.size() - 1 && abs(num - targets[i]) < .0000000001){
            
            cout << "SUCCESS! Lambda partition: {";
            for (int i = 0; i < lower_bound; i++){
                result.push_back(poly_degree + 1);
            }
            
            for (int i = 0; i < x.size(); i++){
                for (int j = 0; j < x[i]; j++){
                    result.push_back(poly_degree - i);
                }
            }
            for (int i = 0; i < result.size() - 1; i++){
                cout << result[i] << ", ";
            }
                
            cout << result[result.size() - 1] << "}\n";
            
            success = true;
            return;
        }
    }
}

void lambda_algo::weak_comp(int N, int K){
    int v = 0;
    int j = 0;
    
    vector<int> x(N, 0);
    x[0] = K;
    while(x[N - 1] != K + 1){
        
        use(x);
        
        if (success == true){
            return;
        }
        
        v = x[N - 1];
        if(K == v){
            return;
        }
        x[N - 1] = 0;
        j = N - 2;
        while(0 == x[j]){
            j--;
        }
        x[j]--;
        x[j + 1] = 1 + v;

    }
}

void lambda_algo::run(){
    for (int i = 2; i < upper_bound - lower_bound; i++){
        weak_comp((int)poly_degree, i);
        if (success == true){
            return;
        }
    }
}

vector<unsigned long long> lambda_algo::Result(){
    return result;
}





