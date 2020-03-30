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
    int p=0, r=0, val1=0, v = 0, j = 0, N = 0, prod=1, sum=0, variables;
    vector<int> data;
    cout << "Please enter youre value of N. (Number of variables -1)"<<endl;
    cin >> variables;// Value of N
    while(variables!= 1 && variables !=2){// this just checks that the value of N is 1 or 2, since we dont have a count for N>3
        cout<< "Please enter either a value of 1 or 2"<<endl;
        cin>> variables;
    }
    if(variables ==1){//This is the part of the program that performs the N=1 count
        cout << "Please enter the number of 1's in your lambda partition" << endl;
        cin >> r; // This corresponds to the number of 1's in the lambda parittion
        cout << "For N=1, the number of saturated ideals for this particular lambda sequence is ";
        cout << r+1;//weak composition of r into 2 is always r+1
        cout <<endl;
    }
    if(variables ==2){//This is the part of the program that performs the N=2 count

    
        cout << "Please enter the number of 2's, in your lambda partition" << endl;
        cin >> p; // Number of 'planes'- number of twos in the lambda parition
        cout << "Please enter the number of 1's, in your lambda partition" << endl;
        cin >> r;
        data=pre_comp(r);
        val1=((p*p)+3*p+2)/2;// This value is used at the very end of the program. Val1 counts the number of weak compositions of planes into 3 directions. The first product term of the N=2 count
    
    
        vector<int> x;
        x.assign(3,0);//this is the vector that will be used for the weak composition algorithm below
        x[0] = r;// First weak composition is (r,0,0) where recall, r is the numberof 1's in the lambda partition
    
        while(x[3 - 1] != r + 1){//This entire while loop finds all weak compositions of rows into 3 boxes
        
            for (int i = 0; i < x.size(); i++){//In each weak composition we take the i'th value in the composition and find the how many integer partitions there are of that number
            
                N=x[i];// 
                prod=prod*data[N];    //We find the product of all these integer parition values. Recall 'data' is a vector whos i'th value tells us the number of integer partitions of i
            
            }
            sum=sum+prod;// We sum up the products of all integer partition values for each weak composition
            prod=1;// reinitializes prod to 1 so that line 65 works properly
        
            v=x[3 - 1];// v is the last value in the weak composition (#,#,v)
            if(r == v){// if (0,0,r) we have gone through all possible weak compositons of r into 3, the following outputs the final count.
                cout<<"For N=2, the number of saturated ideals for this particular lambda sequence is ";
                cout << val1*sum;// recall what val1 is from line 53
                cout << endl;
                return 0;
            }
            x[3 - 1] = 0;// The rest of the lines below is the weak composition algorithm.
            j = 3 - 2;
            while(0 == x[j]){
                j--;
            }
            x[j]--;
            x[j + 1] = 1 + v;
        }
    }
    
}
