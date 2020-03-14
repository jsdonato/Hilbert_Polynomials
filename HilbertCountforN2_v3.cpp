#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> pre_comp(int rows){//function that pre-computes the values of integer partitions of n for 0\leq<n\leqrows
    vector<int> vec;
    int partitionvalue=0;
    int check=0;
    int parMag=0;
    int size=0;
    int leave=0;
    int indicator=0;
    int VAR=0;
    int JAR=0;

    vec.assign(rows+1,0);
    vec[0]=1;

    for(int Q=1; rows+1>Q; Q++){
        
            parMag=Q;
            size=parMag;
                vector<int> z;
                z.assign(parMag,0);
                z[0] = size;
                while(z[parMag - 1] != size + 1 && leave==0){// this while loop and its contents make all weak compositions of 'size' into 'parMag'
                    indicator=0;
                    check=0;
                    while(indicator<parMag-1 && check==0){///this while loop ensures that the weak composition we are looking at actually is an integer partition
                        if(z[indicator]>=z[indicator+1]){
                            indicator=indicator+1;
                        }
                        else{
                            check=1;
                        }
                    }
                    if(check==0){
                        partitionvalue=partitionvalue+1;// if weak comp is also a partition, add one to the count
                    }
        
                    VAR=z[parMag - 1];//engine of the overall while loop that creates weak compositions
                    if(size == VAR){
                        leave=1;
                    }
                    if(leave==0){
                        z[parMag- 1] = 0;
                        JAR = parMag - 2;
                        while(0 == z[JAR]){
                            JAR--;
                        }
                    z[JAR]--;
                    z[JAR + 1] = 1 + VAR;
                    }

                } 
    
            leave=0;
            vec[Q]=partitionvalue;
            partitionvalue=0;

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
            prod=prod*data[N];	//use of function to create a more efficient count

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