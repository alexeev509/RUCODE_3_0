#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
//Better try to make with recursion !!! handmade without next_permutation
int main() {
    int n, dist;
    cin >> n >> dist;
    vector<int> a(n);
    for(int i=0; i<n; ++i)
        a[i]=i+1;

    do {
        bool b=true;
        for(int i=1;i<n-1;++i)
            if(!(abs(a[i]-a[i-1])>=dist && abs(a[i]-a[i+1])>=dist))
                b=false;
        if(b){
            for(int i =0; i<n;++i)
                cout << a[i] << " ";
            cout<<"\n";
        }
    } while(next_permutation(a.begin(), a.end()));

    return 0;
}

