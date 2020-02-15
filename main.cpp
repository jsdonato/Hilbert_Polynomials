#include <cmath>
#include <vector>
#include <utility>
#include <iostream>
#include <fstream>
#include "term.hpp"
#include "polynomial.hpp"
#include "pascal.hpp"
#include "lambda_algo.hpp"
using namespace std;


int main(){
    ifstream in;
    
    in.open("polynomial.in.txt");
    Polynomial p(in);
    
    lambda_algo Algo(p);
    
    in.close();
    return 0;
}

