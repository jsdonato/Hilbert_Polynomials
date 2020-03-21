#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
	int p=0, r=0, val1=0, v = 0, j = 0, N = 0, K = 0, var = 0, jar = 0,c=0, test=0, ipv=0, prod=1, exit=0, sum=0;
cout << "Please enter the number of 2's, in your lambda partition" << endl;
cin >> p;
cout << "Please enter the number of 1's, in your lambda partition" << endl;
cin >> r;

val1=((p*p)+3*p+2)/2;

    vector<int> x;
    x.assign(3,0);
    x[0] = r;
    while(x[3 - 1] != r + 1){
        for (int i = 0; i < x.size(); i++){     

    		N=x[i];
   			K=N;
   			if(x[i]!=0){
    			vector<int> y;
    			y.assign(N,0);
    			y[0] = K;
    			while(y[N - 1] != K + 1 && exit==0){
    				c=0;
    				test=0;
    				while(c<N-1 && test==0){
    					if(y[c]>=y[c+1]){
    						c=c+1;
    					}
    					else{
    						test=1;
    					}
    				}
    				if(test==0){
        				ipv=ipv+1;
    				}
        
        			var=y[N - 1];
       				if(K == var){
       					prod=prod*ipv; 
            			exit=1;
        			}
        			if(exit==0){
        				y[N - 1] = 0;
        				jar = N - 2;
        				while(0 == y[jar]){
          	  				jar--;
       					}
        			y[jar]--;
        			y[jar + 1] = 1 + var;
        			}

				} 
			}
			else{
				prod=prod;
			}  
			exit=0;
			ipv=0;
        }
        sum=sum+prod;
        prod=1;
    






        v=x[3 - 1];
        if(r == v){
        	cout<<"Number of saturated ideals for this particular lambda sequence is ";
        	cout << val1*sum;
        	//cout << "here is val1, planes";
        	//cout << val1;
        	//cout<<endl;
        	//cout << "here is sum, rows";
        	//cout << sum;
        	//cout <<endl;
        	//cout << val1*sum;
        	//cout <<endl;
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