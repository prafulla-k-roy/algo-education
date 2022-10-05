
//Example from wikipedia
/*
For illustration, the Euclidean algorithm can be used to find the greatest common divisor of a = 1071 and b = 462. To begin, multiples of 462 are subtracted from 1071 until the remainder is less than 462. Two such multiples can be subtracted (q0 = 2), leaving a remainder of 147:

1071 = 2 × 462 + 147.
Then multiples of 147 are subtracted from 462 until the remainder is less than 147. Three multiples can be subtracted (q1 = 3), leaving a remainder of 21:

462 = 3 × 147 + 21.
Then multiples of 21 are subtracted from 147 until the remainder is less than 21. Seven multiples can be subtracted (q2 = 7), leaving no remainder:

147 = 7 × 21 + 0.
Since the last remainder is zero, the algorithm ends with 21 as the greatest common divisor of 1071 and 462.
*/

#include <iostream>
using namespace std;

void calculate_gcd(int a, int b) {

    if (b == 0) {
        cout << "GCD of both numbers is : " << a;
    }
    else {
        //Using recursion to calculate gcd
        //In recursion b is passed to a and a % b is paased to b
        calculate_gcd(b, a % b);
    }
}

int main()
{
    int a, b;

    //Taking input of a and b values.
    cout << "Enter two numbers to calculate GCD : \n";
    cin >> a >> b;

    //calling calculate gcd function.
    calculate_gcd(a, b);
}
