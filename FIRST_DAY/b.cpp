#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n, k;

struct sliding_window{
    deque<pair<int,int>> d;
    int l, r;

    sliding_window(){
        l = r = 0;
    }

    void push_back(int x){
        while(!d.empty() && d.back().first >= x) d.pop_back();
        d.emplace_back(x,r);
        ++r;
    }

    void pop_front(){
        if(d.front().second == l) d.pop_front();
        ++l;
    }

    int get_min(){
        return d.front().first;
    }
};

int main() {

    cin >> n >> k;
    sliding_window *w = new sliding_window();
    for (int i = 1; i <= n; ++i) {
        int value;
        cin >> value;
        if (i >= k) {
            w->push_back(value);
            cout << w->get_min()<<"\n";
            w->pop_front();
        } else {
            w->push_back(value);
        }
    }
    return 0;
}


