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
(\lambda-1)! to recover the number of maximal terms in our lambda partiton or, in
other words, the number of leading terms in our lambda partiton which are equivalent 
which is also equivalent to the lower bound of the size of our lambda partition.
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

```lambda_algo(Polynomial p, size_t N)``` will take in this specific lambda sequence 
and N. If N is greater than 2, then the function does nothing since no general 
count is developed yet for N greater than 2. 

For those interested in understanding where the counts for N=1 and N=2 come from, and their 
proofs, please refer to "The sum of the Betti numbers of smooth Hilbert Schemes" in the 
Journal of Algebraic Combinatorics. The paper can be found through the following link
https://link.springer.com/article/10.1007%2Fs10801-021-01055-5 

In the case that N=1, the algorithm counts the number of '1's in the lambda sequence,
say r (if it is not already specified by the user) and calculates the value of the
number of weak compositons of r into 2 (as per theorem).

In the case that N=2,  the algorithm again counts the number of ones in the lambda 
sequence ```r``` and the number of 2's in the lambda sequence ```p```.
Using the value p, the algorithm first finds "(p+2) choose 2" which is set to ```val1```
This corresponds to the choose function in the following formula which is the 
general count for N=2

![Image5](/images/SaturatedN2Count.png)

Now to find the value of the large sum, the algorithm takes the value or ```r```
and uses the ```pre_comp``` function that initializes a vector of size ```r```+1
and for the i'th element of the vector, finds the number of integer partitions of i.
(Note that there is a second function in this code, which is called within ```pre_comp```
and is a recursive function that does most of the work for finding the number of 
integer partitions for each i)

The code then finds each weak composition of ```r``` into 3. Each weak composition 
is represented as a vector of size 3. (This corresponds to the 3-tuple (kx_i, ky_i,kz_i))
in the photo above. Then, for this weak composition, the code looks at each element
of the vector, and finds the number of integer partitions of that value. This is done
by using the precomputed values mentioned earlier. This is done 3 times for each element 
in the weak composition vector. The values are mulitplied, this value is then
stored in ```sum``` and this is done for each weak composition.
```val1``` *```sum``` then represents the picture showed above. 

## Use and Examples
After building the code by running `bash build.sh` in the command line, the user runs the code by running `./hilbert -<option> input_file_name.txt`.
The following table describes the possible options and their uses.  Strictly one option is allowed.
| FLag | Use |
| :---: | :---: | 
| `-p`,`--polynomial` | User inputs a polynomial, N, and an upper bound to recover a lambda partition.  If its recovered, its count and smoothness is determined.|
| `-c`,`--count` | User inputs an N and a lambda partition to recover a count and determine its smoothness. |
| `-s`,`--smooth` | User inputs an N and a lambda partition to determine its smoothness. |

To input the mentioned parameters in the input file, the user must consider the following input format.  Lines beginnning with `#` will be ignored and interpreted as comments.  Outside of this, lines which are not to be ignored will be of the form `VAR_NAME : VAR_VALUE` where `VAR_NAME` can be any of the strings `POLYNOMIAL`, `N`, `UPPER_BOUND`, or `PARTITION`.  For `N` or `UPPER_BOUND`, a positive integer must take on `VAR_VALUE`.  On the other hand, for `PARTITION`, the string `VAR_VALUE` must take the form `l_0^n_0, l_1^n_1,...,l_k^n_k` where `l_i` is the positive integer value in the lambda partition and `n_i` is the number of occurences.  On the other hand, if `VAR_NAME` takes is equivalent to `POLYNOMIAL` then the associated `VAR_VALUE` must take on the form `c_0dn_0, c_1dn_1,...,c_kdn_k` where `c_idn_i` represents the polynomial term with coefficient `c_i` and non-negative integer degree `n_i` being added to the polynomial.  More specifically, the input `c_0dn_0, c_1dn_1,...,c_kdn_k` represents the polynomaial `c_0d^n_0 + c_1d^n_1 + ... + c_kd^n_k`.

### -p flag
For example, if the user wishes to recover a lambda partition from the following polynomial then they can run the command `./hilbert -p polynomial.in.txt`.

![Image3](/images/polynomial_ex_1.png)

Then in ```polynomial.in.txt``` we write 
```
# comment
POLYNOMIAL : 0.5d3, 2.5d2, -2d1, 7d0       
# comment
N:5
#comment
UPPER_BOUND     : 8
```
and in running the algorithm we get the following output
```
UPPER_BOUND ENTERED BY USER: 8
N ENTERED BY USER: 5
POLYNOMIAL ENTERED BY USER: 0.5d^3 + 0.5d^3 - 2.5d^2 + -2d
SUCCESS! Lambda partition: {4, 4, 4, 3, 3, 1, 1}
N is strictly greater than 2 or the largest element in the resulting lambda partition
is greater than 2.  Count will not be computed.
The resulting lambda partition is not smooth.
```
One can check on their own that this is indeed the correct lambda partition associated 
with the mentioned polynomial.  Now in the case in which n=2 and n=1 the algorithm
also outputs the number of saturated ideals associated with this ideal.  For example,
if the Hilbert Polynomial is the following

![Image4](/images/polynomial_ex_2.png)

Then once again ```polynomial.in.txt``` becomes
```
# comment
POLYNOMIAL : 3d1,2d0                
# comment
N:2
#comment
UPPER_BOUND     : 6
```
And we get the following output
```
UPPER_BOUND ENTERED BY USER: 6
N ENTERED BY USER: 2
POLYNOMIAL ENTERED BY USER: 3d + 2
SUCCESS! Lambda partition: {2, 2, 2, 1, 1}
For N=2, the number of saturated ideals for this particular lambda sequence is 90
The resulting lambda partition is smooth and satisfies condition 1.
```
### -c flag
If instead the user wants to input the lambda sequence `{2,2,2,2,1,1,1}` and recover its count and if its smooth then they can run the command `./hilbert -c partition.in.txt` where `partition.in.txt` contains
```
# comment
PARTITION : 2^4,1^3                 
# comment
N:2
#comment
```
and we get the following output

```
N ENTERED BY USER: 2
PARTITION ENTERED BY USER: 2 2 2 2 1 1 1 
For N=2, the number of saturated ideals for this particular lambda sequence is 330
The resulting lambda partition is smooth and satisfies condition 1.
```
### -s flag
If instead the user wants to input the lambda sequence `{5,5,5,5,5,2,2,2,2,1}` determine if its smooth then they can run the command `./hilbert -c partition.in.txt` where `partition.in.txt` contains
```
# comment
PARTITION : 5^5,2^4,1^1             
# comment
N:5
#comment
```
and we get the following output
```
N ENTERED BY USER: 5
PARTITION ENTERED BY USER: 5 5 5 5 5 2 2 2 2 1 
The resulting lambda partition is smooth and satisfies condition 5.
```
