#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;

void compress(vector<pair<long, long>> &v) {
    vector<int> ys;
    for (size_t i = 0; i < v.size(); ++i) {
        ys.push_back(v[i].first);
        ys.push_back(v[i].second);
    }
    sort(ys.begin(), ys.end());
    ys.resize(unique(ys.begin(), ys.end()) - ys.begin());

    for(size_t i =0; i<v.size();++i){
        v[i].first = lower_bound(ys.begin(),ys.end(),v[i].first)-ys.begin();
        v[i].second = lower_bound(ys.begin(),ys.end(),v[i].second)-ys.begin();
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }

}

int main() {
    cin >> n;
    vector<pair<long, long>> v;
    for(int i =0; i<n;++i){
        int y_s,y_e;
        cin>>y_s>>y_e;
        v.emplace_back(y_s,y_e);
    }
    compress(v);
    return 0;
}
