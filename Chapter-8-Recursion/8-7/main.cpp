/*
Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents) and
pennies (1 cent), write code to calculate the number of ways of representing n cents.
*/
#include <iostream>

void calcCentCombo(int total, int q, int d, int n, int p);

int main(){
    calcCentCombo(139, 0, 0, 0, 0);
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
            //std::cout << total << std::endl;
            calcCentCombo(total - 25, q + 1, d, n, p );
        }

        if(total >= 10){
            //std::cout << total << std::endl;
            calcCentCombo(total - 10, q, d + 1, n, p);
        }

        if(total >= 5){
            //std::cout << total << std::endl;
            calcCentCombo(total - 5, q, d, n + 1, p);
        }

        if(total >= 1){
            //std::cout << total << std::endl;
            calcCentCombo(total - 1, q, d, n, p + 1);
        }
    }
}