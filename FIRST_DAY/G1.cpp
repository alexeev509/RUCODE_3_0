#include "iostream"
#include "set"
#include "algorithm"
#include "vector"

using namespace std;

long n, m;
vector<long> indexes_add;
vector<long> len_add;

bool comp1(pair<long,long> p1, pair<long,long> p2){
    return p1.first>p2.first || (p1.first==p2.first && p1.second<p2.second);
}

//По возрастанию номеров
bool comp2(pair<long,long> p1, pair<long,long> p2){
    return p1.first<p2.first;
}

int main() {
    cin >> n >> m;
    //Этот сет сортирует по длине свободные отрезки;
    set<pair<long, long>, decltype(&comp1)> st_1_len_index(comp1);
    //Этот сет сортирует по левой границе свободные отрезки;
    set<pair<long, long>, decltype(&comp2)> st_2_index_len(comp2);

    st_1_len_index.emplace(n, 1);
    st_2_index_len.emplace(1, n);
    for (long i = 0; i < m; ++i) {
        long x;
        cin >> x;
        //Allocate:
        if (x > 0) {
            auto it = st_1_len_index.begin();
            //Если нашли свободный отрезок
            if (it != st_1_len_index.end() && it->first >= x) {
                //
                pair<long, long> p = (*it);
                //Удаляем  этот свободный отрезок из сета st
                st_1_len_index.erase(it);
                //Аналогично удаляем из второго сета
                auto it_2 = st_2_index_len.lower_bound({p.second, p.first});
                st_2_index_len.erase(it_2);
                //Если длина не равна x (меньше x) - значит нам нужно вернуть в сет этот отрезок с незанятой памятью
                if (p.first != x) {
                    //Длина отрезка станет меньше на x
                    //Левая граница сдвинется на x вправо
                    st_1_len_index.emplace(p.first - x, p.second + x);
                    st_2_index_len.emplace(p.second + x, p.first - x);
                }
                cout << p.second << "\n";
                indexes_add.push_back(p.second);
                len_add.push_back(x);
            } else {
                //Запрос на выделение памяти был отклонен
                indexes_add.push_back(-1);
                len_add.push_back(-1);
                cout << -1 << "\n";
            }
        }
            //Free:
        else {
            //Если запрос на выделение памяти прошел ранее успешно
            x = x * (-1) - 1;
            //Если запрос не был отклоненен:
            if (x < indexes_add.size() && indexes_add[x] > 0) {

                //Добавляем текущий отрезок
                pair<long, long> ans = {len_add[x], indexes_add[x]};
                st_2_index_len.emplace(ans.second, ans.first);
                st_1_len_index.emplace(ans.first, ans.second);
                //Ищем его итератор справа и слева
                auto it_2 = st_2_index_len.lower_bound({indexes_add[x], 0});
                auto right = next(it_2);
                auto left = prev(it_2);
                //Проверяем слева - свободна ли память
                if(left!=st_2_index_len.end() && left->first+left->second==it_2->first){
                    //Удаляем зеркальные элементы из первого сета;
                    st_1_len_index.erase({it_2->second,it_2->first});
                    st_1_len_index.erase({left->second,left->first});
                    //Меняем ans;
                    ans.first = left->second + it_2->second;
                    ans.second = left->first;
                    //Удаляем элементы из втого сета
                    st_2_index_len.erase(left);
                    st_2_index_len.erase(it_2);
                    //Добавляем финальный ответ в оба сета
                    st_2_index_len.emplace(ans.second,ans.first);
                    st_1_len_index.emplace(ans.first, ans.second);
                }
                //Теперь проверяем аналогично справа:
                it_2 = st_2_index_len.lower_bound({ans.second, ans.first});
                if(right!=st_2_index_len.end() && it_2->first+it_2->second==right->first){
                    //Удаляем зеркальные элементы из первого сета;
                    st_1_len_index.erase({it_2->second,it_2->first});
                    st_1_len_index.erase({right->second,right->first});
                    //Меняем ans;
                    ans.first = right->second + it_2->second;
                    //Удаляем элементы из втого сета
                    st_2_index_len.erase(right);
                    st_2_index_len.erase(it_2);
                    //Добавляем финальный ответ в оба сета
                    st_2_index_len.emplace(ans.second,ans.first);
                    st_1_len_index.emplace(ans.first, ans.second);
                }

            }
            indexes_add.push_back(-1);
            len_add.push_back(-1);
        }
    }

    return 0;
}
