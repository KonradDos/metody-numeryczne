//Calculating value of given integral usign Simsone and Trapezoid rules.

#include <iostream>
#include <cmath>
#include <vector>

const double EulerConstant = std::exp(1.0);
    
double trapezoidRule(double a, double b, double m);
double trapezoidRuleErrorBound(double a, double b, double m);
double simpsonRule(double a, double b, double m);
int findN();

int main(){
    
    std::cout << "Trapezoid Rule: " << trapezoidRule(0, 1.0, 6.0) << std::endl;
    std::cout << "Trapezoid Rule Error Bound: " << trapezoidRuleErrorBound(0.0, 1.0, 6.0) << std::endl;
    std::cout << "Simpson Rule: " << simpsonRule(0.0, 1.0, 12.0) << std::endl;
    std::cout << "N: " << findN() << std::endl;

    return 0;
}

double trapezoidRule(double a, double b, double m) {
    double h = ( b - a ) / m;
    std::vector<double> functionValues;

    double resault = 0;

    for(double i = a; i <= b; i = i + h){
        functionValues.push_back(pow(EulerConstant, sin(i)) * sin(cos(i)));
    }

    for(int i = 1; i < functionValues.size()-1; i++){
        resault += functionValues.at(i);
    }

    return h * ((functionValues.front() + functionValues.back()) / 2 + resault);
}

double trapezoidRuleErrorBound(double a, double b, double m) {
    double maxA = (-1 * pow( EulerConstant, sin(a)))*(sin(a)+1)*cos(a-cos(a))*(-1 * pow(EulerConstant, sin(a)))*cos(a)*sin(a-cos(a));
    double maxB = (-1 * pow(EulerConstant, sin(b)))*(sin(b)+1)*cos(b-cos(b))*(-1 * pow(EulerConstant, sin(b)))*cos(b)*sin(b-cos(b)); 

    if( maxA > maxB ) return (((b - a) * (b - a) * (b - a)) / (12 * (m * m))) * maxA;
    else return (((b - a) * (b - a) * (b - a)) / (12 * (m * m))) * maxB;
}

double simpsonRule(double a, double b, double m) {
    double h = (b - a) / (2 * m);
    std::vector<double> functionValues;

    double resault = 0;

    for(double i = a; i <= b; i = i + h){
        functionValues.push_back(pow(EulerConstant, sin(i)) * sin(cos(i)));
    }

    for(int i = 1; i <= functionValues.size()-2; i++){
        if(i % 2 == 0) functionValues.at(i) = 4 * functionValues.at(i);
        else functionValues.at(i) = 2 * functionValues.at(i);
    }

    for(double i = 0; i <= functionValues.size()-1; i++){
        resault += functionValues.at(i);
    }

    return (h / 3.0) * (functionValues.at(0) + resault + functionValues.at(functionValues.size()-1));
}

int findN(){
    double error = 0;
    
    for(int i = 0; ; i++) {
        if(trapezoidRuleErrorBound(0, 1, i) < 0.0000005) return i;
    }
}