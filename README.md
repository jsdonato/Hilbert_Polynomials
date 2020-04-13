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
final/general search attempt to the member functions ```weak_comp()```, ```accumulate```, and
```use()``` which use a weak compositon to generate the remaining possible lambda partitons 
with size up to an upperbound which the user specifies and if it finds a valid lambda 
partiton then it outputs it and if it doesn't then the algorithm terminates.

### Saturated Ideal Counter

For the cases where N=1 or N=2, our code will determine the number of saturated 
monomial ideals for some given Hilbert Polynomial. This is done by directly using 
the lambda sequence of the Hilbert Polynomial. This, of course, can be determined
by the algortihm explained above or inputed by the user. 

```Hilbert_Count_General_Documented``` will take in this specific lambda sequence 
and will N. If N is greater than 2, then the function does nothing since no general 
count is developed yet for N greater than 2. 

In the case that N=1, the algorithm counts the number of '1's in the lambda sequence,
say r (if it is not already specified by the user) and calculates the value of the
number of weak compositons of r into 2 (as per theorem).

In the case that N=2,  the algorithm again counts the number of ones in the lambda 
sequence (r) and the number of 2's in the lambda sequence (p).
Using the value p, the algorithm first finds "(p+2) choose 2"


## Use and Examples
### Lambda partition finder
If the user wishes to find a lambda partiton associated with p(d) if there is one
then the user inputs the polynomial into ```polynomial.in.txt```.  For example, if the user wishes
to input the polynomial

![Image3](/images/polynomial_ex_1.png)

then in ```polynomial.in.txt``` we write 
```
3
3 0.5
2 -2.5
1 -2
0 7
```
and in running the algorithm we get the following output
```
Press 1 to input a polynomial (in polynomial.in.txt)
Press 2 to input a lambda partiton
1
INPUT UPPER BOUND FOR LAMBDA PARTITION: 
(Note: It should be greater than 3 )
8
SUCCESS! Lambda partition: {4, 4, 4, 3, 3, 1, 1}
```
One can check on their own that this is indeed the correct lambda partition associated 
with the mentioned polynomial.  Now in the case in which n=2 and n=1 the algorithm
also outputs the number of saturated ideals associated with this ideal.  For example,
if the Hilbert Polynomial is the following

![Image4](/images/polynomial_ex_2.png)

Then once again ```polynomial.in.txt``` becomes
```
1
1 3
0 2
```
And we get the following output
```
Press 1 to input a polynomial (in polynomial.in.txt)
Press 2 to input a lambda partiton
1
INPUT UPPER BOUND FOR LAMBDA PARTITION: 
(Note: It should be greater than 3 )
6
SUCCESS! Lambda partition: {2, 2, 2, 1, 1}
Please enter your value of N. (Number of variables -1)
2
For N=2, the number of saturated ideals for this particular lambda sequence is 90
```


