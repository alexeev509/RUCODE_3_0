#include "iostream"
#include "vector"

using namespace std;

int obj_index,n;
//Задача: определеить перестановку по номеру;
//Например:
//n=4 obj_index = 17
//Ответ: 3 4 1 2
int main(){
    cin>>n>>obj_index;
    //Because start from 0
    --obj_index;
    vector<int> a(n), used(n+1),fact(n+1);
    fact[0]=1;
    for(int i =1; i<=n; ++i){
        a[i-1]=i;
        fact[i]=fact[i-1]*i;
    }


    for(int i =0; i<n; ++i){
        for(int j=1; j<=n; ++j){
            if(!used[j]){
                if(obj_index<fact[n-i-1]){
                    a[i]=j;
                    break;
                } else{
                    obj_index-=fact[n-i-1];
                }
            }
        }
        used[a[i]]=true;
    }
    cout<<"\n";
    for(int i =0;i<n; ++i)
        cout<<a[i]<<" ";
    return 0;
}
