#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAX_N = 3000 + 10, MOD = 1e9 + 7;
ll n, k, dp[MAX_N][MAX_N], fac[MAX_N * MAX_N], en[MAX_N * MAX_N], r,pwmakh, makh = 1;
ll pw(int x,int y){
	if(!y) return 1ll;
	ll t = pw(x, y / 2);
	t = 1ll * t * t % MOD;
	if(y & 1) t = 1ll * t * x % MOD;
	return t;
}
int32_t main(){
    cin>>n>>k;
    if(k == 1){
        cout<<1;
    }
    else{
        fac[0] = 1;
        for(int i = 1; i <= n * k; i++){
            fac[i] = fac[i - 1] * i;
            fac[i] %= MOD;
        }
        for(int i = 1; i <= k - 2; i++){
            makh *= i;
            makh %= MOD;
        }
        pwmakh = pw(makh, MOD - 2);
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if(j > 0){
                    if(en[i * k + j * (k - 1) - 1] == 0){
                        r = fac[i * k + j * (k - 1) - 1] * pwmakh % MOD * pw(fac[i * k + j * (k - 1) - 1 - (k - 2)], MOD - 2) % MOD;
                        en[i * k + j * (k - 1) - 1] = r;
                    }
                    else{
                        r = en[i * k + j * (k - 1) - 1];
                    }
                }
                if(i > 0 && j > 0){
                    dp[i][j] = dp[i - 1][j + 1] + (dp[i][j - 1] * r) % MOD;
                }
                else if(i == 0 && j > 0){
                    dp[i][j] = dp[i][j - 1] * r;
                }
                else if(i > 0 && j == 0){
                    dp[i][j] = dp[i - 1][j + 1];
                }
                else{
                    dp[i][j] = 1;
                }
                dp[i][j] %= MOD;
            }
        }
        /*for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                cout<<dp[i][j]<<"  ";
            }
            cout<<endl;
        }*/
        ll ans = 1ll * dp[n][0] * fac[n] % MOD;
        cout<<ans;
    }
}
