#include "iostream"
#include "set"

using namespace std;

int main(){
    set<int> st;
    for(int i=1;i<2000001; ++i){
        st.insert(i);
    }
    int n;
    cin>>n;
    for(int i=0; i<n; ++i){
        int x;
        cin>>x;
        if(x>0){
            auto it = st.lower_bound(x);
            cout<<*it<<"\n";
            st.erase(it);
        } else{
            st.insert(x*(-1));
        }
    }
    return 0;
}

