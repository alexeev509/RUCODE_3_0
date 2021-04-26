#include<iostream>
#include<set>
#include<vector>

using namespace std;

int n, s, t;
unsigned int m;
//https://official.contest.yandex.ru/rucode2021-spring/contest/25853/problems/I1/?success=50857096#7/2015_07_23/G4nsd8QuV9
const long long INF = 1e10;
vector<long long> dist;
vector<vector<pair<int, int>>> graph;

bool cmp1(int u, int v){
    return dist[u]<dist[v] || (dist[u]==dist[v] && u<v);
}
void deikstra() {
    dist[s] = 0;
    set<int,decltype(&cmp1)> st(cmp1);
    st.insert(s);
    while (!st.empty()) {
        int v = *st.begin();
        st.erase(st.begin());

        for (auto p:graph[v]) {
            int u=p.first;
            int w = p.second;

            if (dist[v] + w < dist[u]) {
                st.erase(u);
                dist[u] = dist[v] + w;
                st.insert(u);
            }

        }
    }
    if (dist[t] == INF)
        cout << -1;
    else
        cout << dist[t];
}


int main() {
    cin >> n >> m >> s >> t;
    --s;
    --t;
    dist.resize(n, INF);
    graph.resize(n,vector<pair<int,int>>());
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        --x, --y;
        graph[x].emplace_back(y,w);
        graph[y].emplace_back(x,w);
    }
    deikstra();

    return 0;
}
