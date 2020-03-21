#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int p (int n, int m)
{
    if (n == m)
        return 1 + p(n, m - 1);
    if (m == 0 || n < 0)
        return 0;
    if (n == 0 || m == 1)
        return 1;
    
    return p(n, m - 1) + p(n - m, m);
    
}

vector<int> pre_comp(int rows){//function that pre-computes the values of integer partitions of n for 0\leq<n\leqrows
    vector<int> vec(rows + 1, 0);
    vec[0] = 1;
    for (int i = 1; i <= rows; i++){
        vec[i] = p(i,i);
    }
    return vec;
}

int main()
{
    int p=0, r=0, val1=0, v = 0, j = 0, N = 0, prod=1, sum=0;
    vector<int> data;
    cout << "Please enter the number of 2's, in your lambda partition" << endl;
    cin >> p;
    cout << "Please enter the number of 1's, in your lambda partition" << endl;
    cin >> r;
    data=pre_comp(r);
    val1=((p*p)+3*p+2)/2;
    
    
    vector<int> x;
    x.assign(3,0);
    x[0] = r;
    
    while(x[3 - 1] != r + 1){//weak compositions of rows into 3 directions created
        
        for (int i = 0; i < x.size(); i++){//integer partition product of values in each weak comp
            
            N=x[i];
            prod=prod*data[N];    //use of function to create a more efficient count
            
        }
        sum=sum+prod;
        prod=1;
        
        v=x[3 - 1];
        if(r == v){
            cout<<"Number of saturated ideals for this particular lambda sequence is ";
            cout << val1*sum;
            return 0;
        }
        x[3 - 1] = 0;
        j = 3 - 2;
        while(0 == x[j]){
            j--;
        }
        x[j]--;
        x[j + 1] = 1 + v;
    }
    
}