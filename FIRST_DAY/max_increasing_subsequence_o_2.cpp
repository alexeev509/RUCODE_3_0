#include "iostream"
#include "vector"
#include "map"

using namespace std;
int n;
vector<int> sequence;
const int INF =1000000;
vector<int> pos;
vector<int> id;
vector<int> d;

void restore_answer(){
    int max_last_element_index=-1;
    for(int i=1; i<=n; ++i){
        if(d[i]!=INF)
            max_last_element_index=i;
        else
            break;
    }
    vector<int> answer;
    int p=id[max_last_element_index];
    while (p!=-1){
        answer.push_back(sequence[p]);
        p=pos[p];
    }
    cout<<"\nОтвет (элементы максимальной возрастающей подпоследовательности:\n";
    for(int i=answer.size()-1;i>=0;--i)
        cout<<answer[i]<<" ";
}

void find_max_subsequence(){
    d.resize(n+1,INF);
    id.resize(n+1);
    pos.resize(n + 1);
    d[0]=-INF;
    id[0] = -1;
    for(int i =0; i<n;++i){
        for(int j =1; j<=n;++j){
            if(d[j-1]<sequence[i] && sequence[i]<d[j]){
                d[j]=sequence[i];
                id[j]=i;
                pos[i]=id[j - 1];
            }
        }
    }
    cout<<"\nМассив d, который содержит в позиции i элемент на который заканчивается НВП длиной i:\n";
    for(int i=1; i<=n; ++i){
        cout<<d[i]<<" ";
    }
    cout<<"\nМассив индексов (для восстановления ответа):\n";
    for(int i=1; i<=n; ++i){
        cout<<id[i]<<" ";
    }
    cout<<"\nМассив предков (для восстановления ответа):\n";
    for(int i=0; i<n; ++i){
        cout << pos[i] << " ";
    }

    restore_answer();
}



int main(){
    setlocale(LC_ALL, "Russian");
    cin>>n;
    for(int i =0; i<n; ++i){
        int x;
        cin>>x;
        sequence.push_back(x);
    }
    find_max_subsequence();
    return 0;
}
//TEST:
//4
//3 6 7 12
//-1000000 3 6 7


//7
//3 2 9 10 3 4 5



//5
//3 2 9 10 3
