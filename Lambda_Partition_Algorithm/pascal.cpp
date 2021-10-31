#include "pascal.hpp"

Pascal::Pascal(){ 
    p_triangle.resize(68);
    for (int i = 0; i < p_triangle.size(); i++) {
        p_triangle[i].resize(i + 1);
    }
        
    p_triangle[0][0] = 1;
    for (int i = 0; i < p_triangle.size(); i++){
        p_triangle[i][0] = 1;
        p_triangle[i][i] = 1;
    }
        
    for (int n = 1; n < p_triangle.size(); n++){
        for (int m = 1; m < p_triangle[n].size() - 1; m++){
            p_triangle[n][m] = p_triangle[n - 1][m - 1] + p_triangle[n - 1][m];
        }
    }
    
    fact.resize(21);
    fact[0] = 1;
    for (size_t i = 1; i < fact.size(); i++){
        fact[i] = i * fact[i - 1];
    }
    
}
    
uint64_t Pascal::Binomial(int n, int k){
    return p_triangle[n][k];
}

uint64_t Pascal::factorial(size_t n){
    return fact[n];
}

    
    
    

