// Q-> Coin Change Problem (Maximum Number of Ways) :
public class CoinChange {
	//this problem comes under unbounded knapsack problem, where we can use a single value multiple time.
	// I solved it using tabulation.
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int arr[] = {1,2,3};
		int n = arr.length;
		int sum = 5;
		//creating 2D array to store overlapping answer for each condition.
		int t[][] = new int[n+1][sum+1];
		
		for(int i=0; i<=n; i++) {
			for(int j=0; j<=sum; j++) {
				//if the length of the array is 0, then the answer will always be 0.
				if(i==0) {
					t[i][j] = 0;
				}
				// if the sum is 0, then 1.
				if(j==0) {
					t[i][j] = 1;
				}
			}
		}
		
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=sum; j++) {
				//if (i-1)th value is less than or equal to j where j is sum, then we can count it
				//then the answer will be t[i-1][j](prevoius row, same column) +t[i][j-arr[i-1]](same row, (j-(i-1)th value)th column).
				if(arr[i-1] <= j) {
					t[i][j] = t[i-1][j]+t[i][j-arr[i-1]];
				}
				// else we just have to initialize with t[i-1][j](prevoius row, same column).
				else {
					t[i][j] = t[i-1][j];
				}
			}
		}
		// At the end the answer will be in t[n][sum].
		System.out.print(t[n][sum]);
	}
	//TC : O(sum*n)
	//SC : O(sum*n)
}
