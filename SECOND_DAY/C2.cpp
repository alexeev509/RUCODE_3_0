#include <iostream>
#include <vector>

using namespace std;

int n;
int mod = 1000000000+7;

long long mod_mult(long long  a, long long  b){
    return (a%mod * b%mod) % mod;
}

int  mod_sum(int  a, int  b){
    return (a%mod + b%mod) % mod;
}

int main(){
    cin>>n;
    vector<int> a(n);
    vector<bool> used(n+1);
    vector<long long> fact (n+1);
    fact[0]=1;
    for(int i = 1;i<=n;++i){
        cin>>a[i-1];
        fact[i]=mod_mult(fact[i-1],i);
    }

    int  obj_index = 0;
    for(int i =0; i<n; ++i){
        used[a[i]]=true;
        for(int j = 1; j<a[i];++j){
            if(!used[j]){
                obj_index=mod_sum(obj_index,fact[n-i-1]);
            }
        }
    }
    cout<<mod_sum(obj_index,1);

    return 0;
}
