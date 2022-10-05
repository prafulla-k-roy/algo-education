// Java program to implement Euclid's Algorithm

import java.lang.*;
import java.util.*;

class Euclid {
	// Recursive implementation of Euclid's Algorithm to calculate GCD
	// Euclid’s algorithm is based on the following property: 
	// If p>q then the gcd of p and q is the same as the gcd of p%q and q. p%q is the remainder of p
	// 
	public static int gcd(int a, int b) {
		if (a == 0)
			return b;

		return gcd(b % a, a);
	}

	// Driver code
	public static void main(String[] args)
	{
		int a, b, g;
		Scanner sc = new Scanner(System.in);
		
		a = sc.nextInt();
		b = sc.nextInt();
		
		g = gcd(a, b);
		
		System.out.println("GCD (" + a + ", " + b + ") = " + g);
	}
}
