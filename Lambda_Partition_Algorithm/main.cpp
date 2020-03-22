#include <cmath>
#include <vector>
#include <utility>
#include <iostream>
#include <fstream>
#include "term.hpp"
#include "polynomial.hpp"
#include "pascal.hpp"
#include "lambda_algo.hpp"
#include "sat_ideals.hpp"
using namespace std;




int main(){
    int i;
    cout << "Press 1 to input a polynomial (in polynomial.in.txt)\n";
    cout << "Press 2 to input a lambda partiton\n";
    cin >> i;
    
    vector<unsigned long long> result;
    
    if (i == 1){
    
        ifstream in;
    
        in.open("polynomial.in.txt");
        Polynomial p(in);
    
        lambda_algo Algo(p);
    
        in.close();
        
        result = Algo.Result();
        
        if (result[0] <= 2){
            int p = 0;
            int r = 0;
            for (int j = 0; j < result.size(); j++){
                if (result[j] == 2){
                    p++;
                }
                else if (result[j] == 1){
                    r++;
                }
            }
            sat_ideals(p, r);
            
        }
    }
    
    else if (i == 2){
        sat_ideals();
    }
    return 0;
}

