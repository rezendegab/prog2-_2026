#include <iostream>
using namespace std;
// struct para horas minutos e segundos
struct Data{
    int hora;
    int min;
    int seg;
};

int main(){
    Data t1,t2;
    char c;
    cin>> t1.hora>>c>>t1.min>>c>>t1.seg;
    cin>>t2.hora>>c>>t2.min>>c>>t2.seg;

    if(t1.hora<t2.hora||(t1.hora == t2.hora && t1.min<t2.min ||(t1.hora == t2.hora && t1.min == t2.min && t1.seg <t2.seg))){
        cout<<"atividade 1 tem:"<<" "<<t1.hora<<":"<<t1.min<<":"<<t1.seg<<" "<<"Logo começa primeiro"<<endl;
    }else
        cout<<"atividade 2 tem"<<" "<<t2.hora<<":"<<t2.min<<":"<<t2.seg<<" "<<"logo começa primeiro"<<endl;

    return 0;
}

