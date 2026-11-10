#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    vector<int> coins = {1, 3, 4};
    int amount = 6;

    //making the table
    vector<int> dp(amount + 1, amount + 1);

    dp[0] = 0;

    for(int i = 1; i <= amount; i++)
    {
        for(int j = 0; j < coins.size(); j++)
        {
            if(coins[j] <= i)
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    cout << "Minimum coins = " << dp[amount] << endl;

    return 0;
}
