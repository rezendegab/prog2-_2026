#include <iostream>
using namespace std;

void calcula_esfera(float R,float*area,float *volume);
int main(){
    float R,area,volume;
    cin>>R;
    calcula_esfera(R,&area,&volume);
    cout<<"Area: "<<area<<" "<<"volume: "<<volume<<endl;
    return 0;
}
void calcula_esfera(float R,float*area,float *volume){
    float p,duas,tres;
    p=3.14;
    duas = R*R;
    tres = R*R*R;
    *area = 4 *p*duas;
    *volume =(4.0/3.0)*p*tres;

}