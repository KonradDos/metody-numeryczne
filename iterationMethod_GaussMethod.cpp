#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void Gauss(vector< vector<double>> &tab);
void iteration(vector< vector<double>> & tab);

int main(){
 
    vector< vector<double> > InitialValues;
    
    InitialValues = {
        {3, -2, 0, -7},
        {1, 4, -3, 0},
        {2, -3, 1, 9}    
    };

    Gauss(InitialValues);
    cout << endl;
    iteration(InitialValues);
}

void iteration(vector< vector<double>>  &tab) {
    
    double A[3][4];
    vector<double> B;

    double tmp;
    double error;
    double arrayNorm = 0;

    double X = 0;
    double Y = 0;
    double Z = 0;

    double X_n1 = 0;
    double Y_n1 = 0;
    double Z_n1 = 0;

    double U_i = 0;

    //tworzenie B i A według instrukcji. 
    for(int i = 0; i < tab.size(); i++) {
        for(int j = 0; j <= tab.size(); j++) {
            if(j == 3) {
                B.push_back(tab[i][3]/tab[i][i]);
            }

            else if(i == j) {
                A[i][j] = 0;

            } else if(j < 3){
                A[i][j] = (-tab[i][j])/tab[i][i];
            }
        }
    }

    //pozbycie sie zer z tablicy
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(j == 2) {
                A[i][j] = B.at(i);
            }
            else if(A[i][j] == 0) {
                tmp = A[i][j];
                A[i][j] = A[i][j+1];
                A[i][j+1] = tmp;
             }
         }
    }

    do{
        X = A[0][0]*Y + A[0][1]*Z + B.at(0);
        Y = A[1][0]*X + A[1][1]*Z + B.at(1);
        Z = A[2][0]*X + A[2][1]*Y + B.at(2);

        U_i = abs(X - X_n1) + abs(Y - Y_n1) + abs(Z - Z_n1);
        error = (0.375/(1-0.375)) * U_i;

        // cout << "|x: " << X << ", y: " << Y << ", z: " << Z << endl;

        X_n1 = X;
        Y_n1 = Y;
        Z_n1 = Z;

    }while(error > 0.0000005);

    cout << "x: " << X << ", y: " << Y << ", z: " << Z << endl;
}

void Gauss(vector< vector<double>> &tab) {
    
    //print table
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++){
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }

    //calculations

    double tmp = tab[0][0]; 
    double tmp2 = tab[1][0];

//1

    for(int i = 0; i <= 3; i++) {
        tab[0][i] = tab[0][i] / tmp;
    }

//2    
    for(int i = 0; i <= 3; i++) {
        tab[0][i] = tab[0][i] * tab[1][0];
    }

//3
    for(int i = 0; i <= 3; i++) {
        tab[1][i] = tab[1][i] - tab[0][i];
    }

//4
    for(int i = 0; i <= 3; i++) {
        tab[0][i] = tab[0][i] * 1/tmp2;
    }

//5

    for(int i = 0; i <= 3; i++) {
        tab[0][i] = tab[0][i] * tab[2][0];
    }
//6

    for(int i = 0; i <= 3; i++) {
        tab[2][i] = tab[2][i] - tab[0][i];
    }

//7

    double tmp3 = tab[1][1];
    for(int i = 0; i <= 3; i++) {
        tab[1][i] = tab[1][i] / tmp3;
    }
//8

    for(int i = 0; i <= 3; i++) {
        tab[1][i] = tab[1][i] * tab[2][1];
    }

//9

    for(int i = 0; i <= 3; i++) {
        tab[2][i] = tab[2][i] - tab[1][i];
    }

    double z = tab[2][3]/tab[2][2];
    double y = (tab[1][3]-(tab[1][2]*z)) * 1/tab[1][1];
    double x = (tab[0][3]-(tab[0][2]*z)-(tab[0][1]*y)) * 1/tab[0][0];

    cout << "\n" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
}