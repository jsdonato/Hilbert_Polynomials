//
//  sat_ideals.hpp
//  HilbertScheme
//
//  Created by Joseph Donato on 3/21/20.
//  Copyright © 2020 Joseph Donato. All rights reserved.
//

#ifndef sat_ideals_hpp
#define sat_ideals_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class sat_ideals{
public:
    sat_ideals(int p, int r);
    
    sat_ideals();
    
    int p(int n, int m);
    
    vector<int> pre_comp(int rows);
    
    void input_N();
    
    void var_2();
    
private:
    int P;
    int R;
    int variables;
};

#endif /* sat_ideals_hpp */
