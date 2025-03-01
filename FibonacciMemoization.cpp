#include <iostream>
#include <vector>
using namespace std;

long long fibonacci(int n, vector<long long>& dp){
    if(n==1 || n==0){
        dp[n] = n;
        return n;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = fibonacci(n-1, dp) + fibonacci(n-2, dp);
    return dp[n];
};

int main(){
    int n;
    cout << "Enter No. of digits : ";
    cin >> n;
    vector<long long> dp(n+1, -1);
    fibonacci(n, dp);
    for(auto x : dp){
        cout << x << " ";
    }
}