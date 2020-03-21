

#ifndef term_hpp
#define term_hpp

#include <stdio.h>
class Term{
public:
    
    Term(double coefficent, int deg);
    
    double Coef();
    
    int Deg();
    
private:
    
    double coef;
    
    int degree;

};
#endif /* term_hpp */
