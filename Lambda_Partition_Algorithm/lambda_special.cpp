#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){

	int N=0;// number of variables -1
	int constant =0; //constant term in a polynomial
	int linear =0; // coefficient of the linear term in a polynomial
	double check = 0; // this is the left hand side of the lambda criterion theorem for linear polynomials



	cout << " Please enter the value of N (Number of Variables - 1)" << endl;
	cin >> N;

	if(N==1){
		cout << "Please Enter the value of your constant of your polynomial" << endl;
		cout << "(There should be no terms of degree 1 or higher): This should also be an integer" << endl;//formatting 
		cin >> constant;
		if(constant > 0){//The constant here needs to be check, needs to be an integer otherwise no lambda
			cout << "This is a Hilbert Polynomial!" << endl;
			cout << "Lambda = {";// opening lambda
			for(int i=0; i<constant; i++){//prints out what the lambda looks like as per theorem
				cout << "1";
				if(i<constant-1){// formatting, making output look nice (no extra ,)
				cout << ", ";
				}

			}
			cout << "}"<< endl;// closing lambda 
		//
		// Joe, this is where i would suspect the counting algorithm would then be called for this case.
		//
		}
		if(constant <= 0){
			cout << "This is not a Hilbert Polynomial (No lambda exists)."<<endl;//test fails
			return 0;
		}
	}
	if(N==2){
		cout << "You have a first degree polynomial of the form p= Md-r"<< endl;// Aide for user to know what value to plug in for the constant term
		cout << "Please Enter the value of r (Should be an integer)" << endl;
		cout << "r = ";
		cin >> constant; // code needs to check that this value is an integer otherwise no lambda
		cout << "Please Enter the value of M (Should be an integer)" << endl;
		cout << "M = ";
		cin >> linear; // code needs to check that this is an integer, otherwise no lambda
		check = (0.5)*((linear*linear)-(3*linear));// lambda criterion as per theorem
		if(linear<0 || constant>check){
			cout << "This is not a Hilbert Polynomial (No lambda exists)"<<endl;// test fails, by theorem
			return 0;
		}
		if(linear==0 && constant ==0 ){
			cout << "This is not a Hilbert Polynomial (No lambda exists)"<<endl;// test fails, every term zero
			return 0;
		}
		if(constant<=check){//test passes
			cout << "This is a Hilbert Polynomial!" << endl;
			cout << "Lamda = { ";	//Lambda opens
			for(int i=0; i<linear; i++){//Prints out the '2's of the lambda sequence
				cout << "2 ";
				if(i<linear-1){//again, formatting to make output look nice
				cout << ", ";
				}
			}
			if(linear>0 && (check-constant)>0){// addtional formatting to make output look nice
				cout << ", ";

			}
			for(int j=0; j < (check-constant); j++){// Prints out the '1's of the lambda sequence
				cout <<"1 ";
				if(j<(check-constant)-1){//formating
				cout << ", ";
				}
			}
			cout << " }"<<endl;// lambda closes
		}
		//
		// Joe, this is where i would suspect the counting algorithm would then be called for this case.
		//

	}
	if(N>2){
		cout << "Lambda_algo.cpp";
		//
		// Joe, this is where the rest of the lambda algorithm would continue ( i think)
	}

	return 0;
}



/*bool is_integer(double num){ 
	return abs(floor(num) - num) < 0.0000000001;
}*/
