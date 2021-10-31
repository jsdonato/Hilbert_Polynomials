#ifndef term_hpp
#define term_hpp

#include <stdio.h>
class Term{
public:
    
    Term(double coefficent, int deg);
    
    double Coef() const;
    
    int Deg() const;
    
private:
    
    double coef;
    
    int degree;

};

struct term_deg_comp {
    bool operator() (const Term& t1, const Term& t2) {
        return t1.Deg() > t2.Deg();
    }
};

#endif /* term_hpp */
