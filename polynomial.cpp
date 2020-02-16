
#include <fstream>
#include "polynomial.hpp"
Polynomial::Polynomial(ifstream &in){
    size_t degree;
    in >> degree;
    
    size_t curr_degree;
    double curr_coeff;
    for (int i = 0; i <= degree; i++){
        in >> curr_degree >> curr_coeff;
        polynomial.emplace_back(curr_coeff, curr_degree);
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




//HARRYS IMPLEMENTATION
/*
#include <iostream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


// This is a class that enables the functionality of
// processing the polynomial p(d) to convert the polynomial
// into a vector that can be further analyzed by our
// program.
// The polynoimal entered should be in a specifc form.
// e.g. (32)d^(74)+(-24)d^(3)+(2)d^(2)+(8)q
class polynomial_p_d {
    
public:
    void converting();
    void print_the_polynomial();
private:
    void add_terms(string coefficient, string degree);
    int string_to_int(string s);
    vector<vector<int>> polynomial;
};

int main(int argc, const char * argv[]) {
    polynomial_p_d new_polynomial;
    new_polynomial.converting();
    new_polynomial.print_the_polynomial();
    return 0;
}

void polynomial_p_d::converting() {
    cout << "Please enter the polynomial:" << "\n";
    cout << "e.g.(32)d^(74)+(-24)d^(3)+(2)d^(2)+(8)q\n";
    char c;
    string coefficient = "0";
    string degree;
    while (cin >> c) {
        if (c == '(') {
            if (coefficient == "0") getline(cin, coefficient,')');
            else {
                getline(cin, degree, ')');
                add_terms(coefficient, degree);
                coefficient = "0";
                degree = "0";
            }
        }
        if (c == 'q') break;
    } // while
    if (coefficient != "0") add_terms(coefficient, "0");
}

void polynomial_p_d::add_terms(string coefficient, string degree) {
    int coefficient_int = string_to_int(coefficient);
    int degree_int = string_to_int(degree);
    cout << coefficient_int << " " << degree_int << ' ';
    polynomial.push_back({coefficient_int, degree_int});
}

int polynomial_p_d::string_to_int(string s) {
    int result = 0;
    if (s[0] == '-') {
        int n = 1;
        for (size_t i = s.length() - 1; i > 0; i--) {
            result += (s[i] - '0') * n;
            n *= 10;
        } // for
        return -1 * result;
    }
    else {
        int n = 1;
        for (int i = (int)s.length() - 1; i >= 0; i--) {
            result += (s[i] - '0') * n;
            n *= 10;
        } // for
        return result;
    }
}

void polynomial_p_d::print_the_polynomial() {
    for (auto& tuple : polynomial) {
        cout << "Coeficient: " << tuple[0] << " ";
        cout << "Degree: " << tuple[1] << "\n";
    }
}
*/
