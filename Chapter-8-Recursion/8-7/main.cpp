/*
Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents) and
pennies (1 cent), write code to calculate the number of ways of representing n cents.
*/
#include <iostream>

void calcCentCombo(int total, int q, int d, int n, int p);

int main(){
    calcCentCombo(16, 0, 0, 0, 0);
}


void calcCentCombo(int total, int q, int d, int n, int p){
    if(total == 0){
        std::cout << "Q" << q << " | "
                  << "D" << d << " | "
                  << "N" << n << " | "
                  << "P" << p << std::endl;
    }
    else{
        if(total >= 25){
            calcCentCombo(total - 25, q + 1, d, n, p);
        }

        if(total >= 10){
            calcCentCombo(total - 10, q, d + 1, n, p);
        }

        if(total >= 5){
            calcCentCombo(total - 5, q, d, n + 1, p);
        }

        if(total >= 1){
            calcCentCombo(total - 1, q, d, n, p + 1);
        }
    }
}