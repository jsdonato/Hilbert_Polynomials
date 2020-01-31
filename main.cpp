#include <cmath>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

class Term{
public:
    Term(double coefficent, int deg){
        coef = coefficent;
        degree = deg;
    }
    
    double Coef(){
        return coef;
    }
    
    int Deg(){
        return degree;
    }
    
private:
    double coef;
    int degree;
};

class Polynomial{
public:
    Polynomial(vector<pair<double, int>> poly){
        for (int i = 0; i < poly.size(); i++){
            polynomial.emplace_back(poly[i].first, poly[i].second);
        }
    }
    
    double evaluate(double d){
        double sum = 0;
        for (int i = 0; i < polynomial.size(); i++){
            sum += polynomial[i].Coef() * pow(d, polynomial[i].Deg());
        }
        return sum;
    }
private:
    vector<Term> polynomial;
};

class Pascal{
public:
    Pascal(size_t size){
        vector<unsigned long long>temp(size, 0);
        p_triangle.resize(size, temp);
        
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
    }
    
    unsigned long long Binomial(int n, int k){
        return p_triangle[n - k][k];
    }
    
    

private:
    vector<vector<unsigned long long>> p_triangle;
};



int main(){
    
    
    return 0;
}

