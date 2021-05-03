#include "iostream"
#include "string"

using namespace std;

int n;

void generate(int pos, int balance,string ans) {
    if(pos==n){
        cout<<ans<<"\n";
        return;
    }
    if (balance + 1 <= n - pos-1) {
        ans.push_back('(');
        generate(pos+1, balance+1,ans);
        ans.pop_back();
    }
    if (balance>0){
        ans.push_back(')');
        generate(pos+1,balance-1,ans);
        ans.pop_back();
    }
}
int main() {
    cin >> n;
    n*=2;
    generate(0,0,"");
    return 0;
}
