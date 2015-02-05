/*
Given an integer, print the next smallest and next largest number that have the same 
number of 1 bits in their binary representation.
*/

#include <iostream>

int findNextSameBits(int, bool);

int main(){
    int test_num = 18;
    bool large_or_small = false;

    if(large_or_small)
        std::cout << "Next largest ";
    else
        std::cout << "Next smallest ";

    std::cout << "value of int " << test_num << " is: " 
             << findNextSameBits(test_num, large_or_small) << std::endl;
}

int findNextSameBits(int orig, bool large_or_small){
    int orig_one_bits = 0;

    int large_one_bits = 0;
    bool match_found = false;

    // Find total # of 1 bits
    for(int i = 31; i >= 0; i--){
        if(((orig >> i) & 1))
            orig_one_bits++;
    }

    // Keep increasing until you find matching 1 bits
    while(!match_found){

        if(large_or_small)
            orig++;
        else
            orig--;
        
        large_one_bits = 0;

        for(int i = 31; i >= 0; i--){
            if(((orig >> i) & 1))
                large_one_bits++;
        }

        if(large_one_bits == orig_one_bits)
            match_found = true;
    }

    return orig;
}