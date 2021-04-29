#include "iostream"
#include "vector"
#include "algorithm"
#include "set"

using namespace std;


int n;

struct Line_X {
    Line_X(long long id, long long x, long long y_1, long long y_2, bool closed) :
            id(id), x(x), y_1(y_1), y_2(y_2), closed(closed) {}

private:
    long long id;
    long long x;
    long long y_1;
    long long y_2;
    bool closed;
public:
    long long getId() { return id; }

    long long getX() { return x; }

    long long getY_1() { return y_1; }

    long long getY_2() { return y_2; }

    bool getClosed() { return closed; }
};

bool cmpByX(Line_X l1, Line_X l2) {
    return l1.getX() < l2.getX() || (l1.getX() == l2.getX() && l1.getId() < l2.getId());
}

struct YLine {
    YLine(long long y_1, long long y_2, long long id) : y_1(y_1), y_2(y_2), id(id) {}

private:
    long long y_1;
    long long y_2;
    long long id;
public:
    long long getId() const { return id; }

    long long getY_1() const { return y_1; }

    long long getY_2() const { return y_2; }
};

bool cmpByY(YLine l1, YLine l2) {
    return l1.getY_1() > l2.getY_1();
}

//bool cmpExample(int u, int v){
//    return u>v;
//}
int main() {
//    set<int,decltype(&cmpExample)> u(cmpExample);
//    u.insert(10);
//    u.insert(20);
//    u.insert(30);
//    u.insert(40);
//    u.insert(50);
//    auto it = u.lower_bound(35);
//    cout<<*it;
    cin >> n;
    set<Line_X, decltype(&cmpByX)> st(cmpByX);
    set<YLine, decltype(&cmpByY)> y_1_2(cmpByY);
    for (int i = 0; i < n; ++i) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1>x2){
            long long temp =x1;
            x1=x2;
            x2=temp;
            temp=y1;
            y1=y2;
            y2=temp;
        }
        if(y1>y2){
            long long temp =y1;
            y1=y2;
            y2=temp;
        }
        st.insert(Line_X(i, x1, y1, y2, false));
        st.insert(Line_X(i, x2, y1, y2, true));
    }

//    for (auto q:st) {
//        cout << "id: " << q.getId() << " x = " << q.getX() << " y_1 = " << q.getY_1() << " y_2 = " << q.getY_2()
//             << " Closed ? - " << q.getClosed() << "\n";
//    }
    long long count=0;
    for (auto q:st) {
        if (y_1_2.empty()) {
            y_1_2.insert(YLine(q.getY_1(), q.getY_2(), q.getId()));
        } else {
            YLine temp = YLine(q.getY_1(), q.getY_2(), q.getId());
            auto it = y_1_2.lower_bound(temp);
//            cout << (*it).getId()<<" "<<(*it).getY_1()<<" "<<(*it).getY_2()<<"\n";
          
            //Если верхняя координата ближайшего в сете прямоугольника меньше верхней координаты текущего
            //прямоугольника - то добавляем его в сет (тк они не пересекаются)
          //ЗАМЕЧАНИЕ: it==y_1_2.end() тоже может быть
            if(it==y_1_2.end() ||(*it).getY_2()<temp.getY_2()){
                y_1_2.insert(temp);
            }
                //Если id совпадают = значит это закрытие данного прямоугольника => значит он внешний.
            else if((*it).getId()==temp.getId()){
                ++count;
                y_1_2.erase(it);
            }
            //Если меньше = ничего не делаем
            //Равны быть не могут - тк прямоугольники не перескаются =)
        }
    }
    cout<<count;
    return 0;
}


//ТЕСТЫ! :-)
//4 4 5 5
//4 6 5 7

//2
//4 6 5 7
//4 4 5 5


//ОДИН ВНУТРИ ДРУГОГО:
//2
//4 6 5 7
//3 5 6 8

//ОДИН ВНУТРИ ДРУГОГО:
//2
//3 5 6 8
//4 6 5 7


