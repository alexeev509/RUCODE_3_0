#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;
vector<int> sequence;
vector<int> d;
vector<int> id;
vector<int> parent_id;
int n;
const int INF=2147483647;

void restore_answer(){
    int min_index=-1;
    for(int i =1; i<d.size();++i){
        if(d[i]==-INF)
            break;
        else
            min_index=id[i];
    }
    vector<int> answer;
    int pos = min_index;
    while (pos!=-1){
        answer.push_back(pos+1);
        pos=parent_id[pos];
    }
    cout<<answer.size()<<"\n";
    for(int i=answer.size()-1;i>=0; --i){
        cout<<answer[i]<<" ";
    }
}
void max_subsequence(){
    d.resize(n+1,-INF);
    id.resize(n+1);
    parent_id.resize(n);
    d[0]=INF;
    id[0]=-1;
    for(int i=0; i<n; ++i){
        auto it = std::upper_bound(d.begin(), d.end(), sequence[i], greater<int>());
        int j = it - d.begin();
        if(d[j-1]>=sequence[i] && sequence[i]>=d[j]){
            d[j] = sequence[i];
            id[j]=i;
            parent_id[i]=id[j-1];

        }
    }
    restore_answer();
}

int main(){
    cin>>n;
    for( int i=1;i<=n; ++i){
        int x;
        cin>>x;
        sequence.push_back(x);
    }
    max_subsequence();
    return 0;
}
