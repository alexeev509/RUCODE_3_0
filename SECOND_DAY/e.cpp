#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;
int n;
int x[50];
//https://site.ada.edu.az/~medv/acm/Docs%20e-olimp/Volume%2024/2390.htm

void Partitions(int pos, int max, int number){
    int i;
    if(!number){
        for(int i=0; i<pos;++i){
            cout<<x[i]<<" ";
        }
        cout<<"\n";
    }
    for(int i=1;i<=min(max,number);++i){
        x[pos]=i;
        Partitions(pos+1,i,number-i);
    }
}

int main(){
    cin>>n;
    Partitions(0,n,n);
    return 0;
}
