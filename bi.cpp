#include <iostream>
#include <cmath>

using namespace std;

template<typename expressionType>
double bisection(double a, double b, const expressionType &expression, double errorBound);

int main(){

    auto expression = [](double x){ return ((x*x*x)-(3*x*x)-3.5); };

    cout << "Metoda bisekcji: " << bisection(5, 12, expression, 0.0005) << endl;

    return 0;
}

template<typename expressionType>
double bisection(double a, double b, const expressionType &expression, double errorBound) {
    double x = (a + b) / 2;
    double x_1; //xi-1 - root of previous iteration

    do{
        x_1 = x;   

        if(expression(a) * expression(b) > 0) {
            cout << "Podana funkcja jest nieokreślona!" << endl;
            return 0;
        }
        else if(expression(a) * expression(x) < 0){
            x = (a + x) / 2; 
            cout << "ax " << x << endl; 
        } else if(expression(b) * expression(x) < 0) {
            x = (b + x) / 2;
            cout << "bx " << x << endl;     
        }   
    } while((abs((x - x_1) / x) * 100) > errorBound || expression(x) != 0);

    return x;

}