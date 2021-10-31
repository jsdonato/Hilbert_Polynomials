#include "polynomial.hpp"

using namespace std;
Polynomial::Polynomial(vector<Term> poly){
    sort(poly.begin(), poly.end(), term_deg_comp());        

    double coeff_sum = 0;
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
    double coef = poly.polynomial[0].Coef();
    int deg = poly.polynomial[0].Deg();
    for (int i = 0; i < poly.polynomial.size() - 1; i++) {
        if (poly.polynomial[i+1].Coef() >= 0) {
	    if (deg == 1) os << coef << "d + ";
	    else os << coef << "d^" << deg << " + ";
	    coef = poly.polynomial[i+1].Coef();
	}
	else {
	    if (deg == 1) os << coef << "d - ";
	    else os << coef << "d^" << deg << " - ";
            coef = abs(poly.polynomial[i+1].Coef());
	}
        deg = poly.polynomial[i+1].Deg();
    } 
    if (deg == 0) {
        os << coef;
    } 
    else if (deg == 1) {
        os << coef << "d";
    }
    else {
        os << coef << "d^" << deg;  
    }
    return os;
}
