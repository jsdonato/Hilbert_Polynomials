#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main()
{
    int N = 0, K = 0, v = 0, j = 0;// Most variables defined in code, besides j, which acts as a placeholder.
    cout << "Enter number of variables - 1" << endl;// In the problem, this is the value of N, thus we use the variable N
    cin >> N;
    cout << "Enter max Lamda Size" << endl;
    cin >> K; // The largest size of lambda we want to check for, this is the user inputed upper bound
  

    vector<int> x;
    x.assign(N,0);// Vector has N elements all of which are initialized to 0.
    x[0] = K;// let the first element be K
    while(x[N - 1] != K + 1){// This while never loop never breaks, the program ends within the while loop (check line 27 and 28), it used only to continue the weak composition algorithm
        cout << "{";
        for (int i = 0; i < x.size(); i++){ // For loop: Prints out the current vector, which represents some weak composition
            cout << " ";
            cout << x[i];
            
        }

        cout << "}"<< endl;
        v=x[N - 1];//This is the last element in the vector, call it v

        if(K == v){// If the last element in the vector is K,then we have exhausted all weak composition possibilities
            return 0;
        }

        x[N - 1] = 0; // Initialize last element in vector back to 0, (v still remembers what the last element was)
        j = N - 2;

        while(0 == x[j]){// starts to check from the second to last element in the vector
            j--;//This while loop looks for the first nonzero element in the vector from the end to the front
        }

        x[j]--;// First nonzero-value is found, take away 1
        x[j + 1] = 1 + v;//move over that value one element to the right of element j in the vector, then add v (previous weak compositions last value)
}

    return 0;

}
