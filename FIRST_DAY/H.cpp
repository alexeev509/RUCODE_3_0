#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;
int n;
int main(){
    cin>>n;
    vector<int> a;
    vector<int> index;
    vector<int> pages;
    for(int i=0; i<n; ++i){
        int x;
        cin>>x;
        pages.push_back(x);
        index.push_back(i);
    }
    for(int i=0; i<n-1; ++i){
        int x;
        cin>>x;
        a.push_back(x);
    }
    int counter=0;
    do{
        bool can=true;
        for(int i=0; i<n-1; ++i){
            if(pages[index[i]]+pages[index[i+1]]>a[i]){
                can=false;
                break;
            }
        }
        if(can)
            ++counter;

    }while (next_permutation(index.begin(),index.end()));
    cout<<counter;
    return 0;
}

