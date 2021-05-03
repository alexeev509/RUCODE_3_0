#include "iostream"
#include "string"

using namespace std;
//https://silvertests.ru/GuideView.aspx?id=29833
int n;

void generate(int pos, int balance,string ans) {
    //Если позиция равна n значит все ок;
    if(pos==n){
        cout<<ans<<"\n";
        return;
    }
    //Ключевая идея в поддержке баланса;
    //Если баланс позволяет добавить открывающуюся скобку - добавляем ее
    if (balance + 1 <= n - pos-1) {
        ans.push_back('(');
        generate(pos+1, balance+1,ans);
        //Главное - не забыть убрать скобку которую добавили - ведь далее на ее место может встать противоположная скобка
        //Я на этом спотыкался :((
        ans.pop_back();
    }
    //Если баланс больше нуля - значит можно добавить закрывающуюся скобку;
    if (balance>0){
        ans.push_back(')');
        generate(pos+1,balance-1,ans);
        ans.pop_back();
    }
}
int main() {
    cin >> n;
    n*=2;
    generate(0,0,"");
    return 0;
}
