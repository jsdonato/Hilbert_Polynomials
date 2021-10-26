#include "pascal.hpp"

Pascal::Pascal(){
    vector<unsigned long long>temp(60, 0);
    p_triangle.resize(60, temp);
        
    p_triangle[0][0] = 1;
    for (int i = 0; i < p_triangle.size(); i++){
        p_triangle[i][0] = 1;
        p_triangle[0][i] = 1;
    }
        
    for (int n = 1; n < p_triangle.size(); n++){
        for (int m = 1; m < p_triangle.size(); m++){
            p_triangle[n][m] = p_triangle[n][m - 1] + p_triangle[n - 1][m];
        }
    }
    
    fact.resize(18);
    fact[0] = 1;
    for (size_t i = 1; i < fact.size(); i++){
        fact[i] = i * fact[i - 1];
    }
    
}
    
unsigned long long Pascal::Binomial(int n, int k){
    return p_triangle[n - k][k];
}

unsigned long long Pascal::factorial(size_t n){
    return fact[n];
}

    
    
    

