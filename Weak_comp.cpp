#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main()
{
    int N = 0, K = 0, v = 0, j = 0;
    cout << "Enter number of variables - 1" << endl;
    cin >> N;
    cout << "Enter max Lamda Size" << endl;
    cin >> K;
  

    vector<int> x;
    x.assign(N,0);
    x[0] = K;
    while(x[N - 1] != K + 1){
        cout << " { ";
        for (int i = 0; i < x.size(); i++){ 
            cout << " ";
            cout << x[i]; 
            
        }
        cout << "}"<< endl;
        v=x[N - 1];
        if(K == v){
            return 0;
        }
        x[N - 1] = 0;
        j = N - 2;
        while(0 == x[j]){
            j--;
        }
        x[j]--;
        x[j + 1] = 1 + v;
}

    return 0;

}
