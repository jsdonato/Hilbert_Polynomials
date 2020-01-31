#include <cmath>
#include <vector>
#include <utility>
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
    
};
