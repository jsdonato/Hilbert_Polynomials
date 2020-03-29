# Lambda Partition finder and Saturated Ideal counter algorithms.
This code base has two functionalities, the first being that given a polynomial 
p(d), the algorithm in this code base will return an associated lambda partiton 
if p(d) is indeed a Hilbert polynomial and the user provides a reasonable upperbound.  
In addition, if p(d) is indeed a hilbert polynomial then if n=1 or n=2 the code 
will also output the number of saturated ideals associated with p(d).  Now if the 
user only wishes to input a lambda partition and seek the number of saturated 
ideals associated with that partiton the user has that option as well.

## Algorithm
### Lambda partition finder
Before diving directly into how the algorithm functions we will first recall the
following theorem
![Image1](/images/M1927Theorem.png)

and the non-increasing sequence of lambda's from now on will be referred to as the "lambda partition".
From here we will then keep in mind that if x_0,x_1,...,x_n are n+1 distinct 
real numbers, then for arbitrary values y_0,y_1,...,y_n there is a unique polynomial 
p_n of degree at most n such that p_n(x_i)=y_i for all i in {0,1,...,n}.
From here, we now have a basis for algorithm which will use a brute force method
to find the lambda partiton mentioned in MacAulays theorem.  Now since a Hilbert
Polynomial is of the form mentioned in MacAulays we will note that the following 
binomial coefficient
![Image2](/images/binomial.png)

is a polynomial in d with degree \lambda-1 and with leading coefficient 1/((\lambda-1)!).
From here, if p(d) is indeed a Hilbert polynomial then we can multiply p(d) by 
(\lambda-1)! to recover the number of maximal terms in our lambda partiton or in
other words the number of leading terms in our lambda partiton which are equivalent.
From this, we now have the leading binomial terms in our sum mentioned in MacAulays
theorem and we can precompute the first couple sums of those evaluated at each 
x_0,x_1,...,x_n so that evaluating our guesses in the future is faster.  The values
of the first couple binomial sums evaluated at each x_0,x_1,...,x_n is stored in the 
vector called ```sum_of_first``` and is private member variable in the ```lambda_algo```
data structure.

Now going into further detail of the actual code, the member function in the ```lambda_algo```
data structure called ```zero_run()``` generates the vector ```sum_of_first``` which we mentioned
earlier and checks if simply the maximal terms of our lambda partiton is indeed the
correct lambda partition.  From there, if ```zero_run()``` does not find the lambda partiton
then we pass the task over to the ```first_run()``` member function of the ```lambda_algo```
data structure which checks the case in which we have the leading maximal terms of our lambda partiton 
and the final element in our lambda partiton is different from the leading maximal ones.
Finally, if ```first_run()``` is unable to determine the lambda partiton then we pass the 
final/general search attempt to the member function ``````




### Saturated Ideal Counter


## Use and Examples

