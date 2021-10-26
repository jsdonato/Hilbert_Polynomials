#include "polynomial.hpp"
Polynomial::Polynomial(vector<Term> poly){
    sort(poly.begin(), poly.end(), term_deg_comp());        

    uint32_t coeff_sum = 0;
    for (size_t i = 0; i < poly.size(); i++) {
        uint32_t curr_deg = poly[i].Deg();
	coeff_sum += poly[i].Coef();
	if (poly[i].Deg() != poly[i + 1].Deg() || i == poly.size() - 1) {
	    polynomial.emplace_back(coeff_sum, curr_deg);
	    coeff_sum = 0;
	}
    }
}

double Polynomial::evaluate(double d){
    double sum = 0;
    for (int i = 0; i < polynomial.size(); i++){
        sum += polynomial[i].Coef() * pow(d, polynomial[i].Deg());
    }
    return sum;
}

size_t Polynomial::degree(){
    return polynomial[0].Deg();
}

double Polynomial::first_coeff(){
    return polynomial[0].Coef();
}

ostream& operator<<(ostream& os, const Polynomial& poly) {
    for (int i = 0; i < poly.polynomial.size() - 1; i++) {
        if (poly.polynomial.Deg() == 1) {
	    os << poly.polynomial[i].Coef() << "d + ";
	}
	else {
	    os << poly.polynomial[i].Coef() << "d^" << poly.polynomial[i].Deg() << " + "; 
        }
    }
    if (poly.polynomial.Deg() == 1) {
        os << poly.polynomial[i].Coef();
    } 
    else if (poly.polynomial.Deg() == 1) {
        os << poly.polynomial[i].Coef() << "d";
    }
    else {
        os << poly.polynomial[poly.polynomial.size() - 1].Coef() << "d^" << poly.polynomial[poly.polynomial.size() - 1].Deg();  
    }
    return os;
}
