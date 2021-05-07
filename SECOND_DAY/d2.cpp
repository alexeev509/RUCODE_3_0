#include "iostream"
#include "vector"

using namespace std;
vector<vector<long>> v;
string sequence;
//https://e-maxx.ru/algo/bracket_sequences
//https://neerc.ifmo.ru/wiki/index.php?title=%D0%9F%D1%80%D0%B0%D0%B2%D0%B8%D0%BB%D1%8C%D0%BD%D1%8B%D0%B5_%D1%81%D0%BA%D0%BE%D0%B1%D0%BE%D1%87%D0%BD%D1%8B%D0%B5_%D0%BF%D0%BE%D1%81%D0%BB%D0%B5%D0%B4%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D0%BE%D1%81%D1%82%D0%B8
long const MODULE = 1e9+7;

void findIndex(){
    v[0][0]=1;
    for(int i =1; i<=sequence.size();++i){
        v[i][0]=v[i-1][1];
        for(int j =1;j<=sequence.size(); ++j){
            v[i][j]=(v[i-1][j-1]%MODULE+v[i-1][j+1]%MODULE)%MODULE;
        }
    }
//    for(int i = 0;i<=sequence.size();++i){
//        for(int j =0;j<=sequence.size(); ++j){
//            cout<<v[i][j]<<" ";
//        }
//        cout<<"\n";
//    }
}
void restoreAnswer(){
    int depth=0;
    long answer=1;
    for(int i =0; i<sequence.size();++i){
        if(sequence[i]=='(')
            ++depth;
        else{
            answer=(answer%MODULE + v[sequence.size()-i-1][depth+1]%MODULE)%MODULE;
            --depth;
        }
    }
    cout<<answer;
}

int main(){
    cin>>sequence;
    v.resize(sequence.size()+2,vector<long>(sequence.size()+2));
    findIndex();
    restoreAnswer();
    return 0;
}

//(()())()
//1 0 0 0 0 0 0 0 0
//0 1 0 0 0 0 0 0 0
//1 0 1 0 0 0 0 0 0
//0 2 0 1 0 0 0 0 0
//2 0 3 0 1 0 0 0 0
//0 5 0 4 0 1 0 0 0
//5 0 9 0 5 0 1 0 0
//0 14 0 14 0 6 0 1 0
//14 0 28 0 20 0 7 0 1

//n=8;
//4+


//(()())()

//(((())))  1
//((()()))  2
//((())())  3
//((()))()  4
//(()(()))  5
//(()()())  6
//(()())()  7

//Идея такая: закрывающиеся скобки - пропускаем
//Если скобка отркывается - предположим - что она наооборот закрыта - тогда сколько вариантов поставить после нее скобки - чтобы баланс был равен 0?
//(()())()
//Предположим третья закрывается:((( - тогда 4 варианта поставить скобки после неё (1,2,3,4)
//Предположим 5-ая скобка закрывается: (()(( - тогда остается 1 вариант
//и тд

