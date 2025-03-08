// https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/

#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX-1  //like for comparision in max function, we take the value zero // same way for comparing with min, we took value INT_MAX
//why INT_MAX-1 ????...see code..later we did +1..now numbers in computers are cyclic....so INT_MAX+1 will give a -ive value...thus we did (INT_MAX-1) initially

int getMinNumberOfCoins(int coins[], int n, int sum) {
	int t[n + 1][sum + 1];
	// initialization
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (j == 0)
				t[i][j] = 0;
			if (i == 0)
				t[i][j] = INF;
			if (i == 1) {                          //here we Initialize 2 rows! see video no. 17 and 18
				if (j % coins[i - 1] == 0)
					t[i][j] = j / coins[i - 1];
				else
					t[i][j] = INF;
			}
		}
	}

	t[0][0] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= sum; j++)
			if (coins[i - 1] <= j)
				t[i][j] = min(t[i - 1][j], 1 + t[i][j - coins[i - 1]]);  //here we take min...not max  // also here we did 1+t[][] because we are adding 1 coin
			else
				t[i][j] = t[i - 1][j];

	return t[n][sum];
}

signed main() {
	int n; cin >> n;
	int coins[n];
	for (int i = 0; i < n; i++)
		cin >> coins[i];
	int sum; cin >> sum;

	cout << getMinNumberOfCoins(coins, n, sum) << endl;
	return 0;
}
