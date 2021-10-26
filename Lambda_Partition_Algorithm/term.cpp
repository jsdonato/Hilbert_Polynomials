

#include "term.hpp"

Term::Term(double coefficent, int deg){
    coef = coefficent;
    degree = deg;
}
    
double Term::Coef(){
    return coef;
}
    
int Term::Deg(){
    return degree;
}
