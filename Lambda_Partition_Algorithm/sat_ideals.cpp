//
//  sat_ideals.cpp
//  HilbertScheme
//
//  Created by Joseph Donato on 3/21/20.
//  Copyright © 2020 Joseph Donato. All rights reserved.
//

#include "sat_ideals.hpp"
#include <vector>
#include <iostream>

sat_ideals::sat_ideals(int p, int r, int N){
    P = p;
    R = r;
    variables = N;
    if (variables == 1){
        cout << "For N=1, the number of saturated ideals for this particular lambda sequence is ";
        cout << R + 1;
        cout << endl;
    }
    
    else if (variables == 2){
        var_2();
    }
}

int sat_ideals::p (int n, int m){
    
    if (n == m)
        return 1 + p(n, m - 1);
    if (m == 0 || n < 0)
        return 0;
    if (n == 0 || m == 1)
        return 1;
    
    return p(n, m - 1) + p(n - m, m);
    
}

vector<int> sat_ideals::pre_comp(int rows){//function that pre-computes the values of integer partitions of n for 0\leq<n\leqrows
    vector<int> vec(rows + 1, 0);
    vec[0] = 1;
    for (int i = 1; i <= rows; i++){
        vec[i] = p(i,i);
    }
    return vec;
}

void sat_ideals::var_2(){
    int N = 0;
    int val1 = 0;
    int sum = 0;
    int prod = 1;
    int j = 0;
    int v = 0;
    
    vector<int> data = pre_comp(R);
    val1=((P*P)+3*P+2)/2;
    
    
    vector<int> x;
    x.assign(3,0);
    x[0] = R;
    
    while(x[3 - 1] != R + 1){//weak compositions of rows into 3 directions created
        
        for (int i = 0; i < x.size(); i++){//integer partition product of values in each weak comp
            
            N=x[i];
            prod=prod*data[N];    //use of function to create a more efficient count
            
        }
        sum=sum+prod;
        prod=1;
        
        v=x[3 - 1];
        if(R == v){
            cout << "For N=2, the number of saturated ideals for this particular lambda sequence is ";
            cout << val1*sum;
            cout << endl;
            return;
        }
        x[3 - 1] = 0;
        j = 3 - 2;
        while(0 == x[j]){
            j--;
        }
        x[j]--;
        x[j + 1] = 1 + v;
    }
}

