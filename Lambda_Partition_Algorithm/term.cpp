

#include "term.hpp"

Term::Term(double coefficent, int deg){
    coef = coefficent;
    degree = deg;
}
    
double Term::Coef() const {
    return coef;
}
    
int Term::Deg() const {
    return degree;
}
