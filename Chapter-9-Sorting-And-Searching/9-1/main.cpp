/*
You are given two sorted arrays, A and B, and A has a large enough buffer at the end
to hold B. Write a method to merge B into A in sorted order.
*/

#include <iostream>

void merge(int*, int, int*, int);

void display(int*, int);

int main(){
    int size_a = 5;
    int size_b = 3;

    int arr_a[8] = {1, 3, 5, 7, 9};
    int arr_b[3] = {2, 4, 6};

    display(arr_a, size_a);
    display(arr_b, size_b);

    merge(arr_a, size_a, arr_b, size_b);

    display(arr_a, (size_a + size_b));

}

void merge(int* arr_a, int size_a, int* arr_b, int size_b){
    
    int pos_a = 0;
    int pos_b = 0;
    int pos = 0;

    int new_size = size_a + size_b;

    int * new_arr = new int[new_size];

    while(pos < new_size){

        if(pos_a < size_a && pos_b < size_b){
            if(arr_a[pos_a] < arr_b[pos_b]){
                new_arr[pos] = arr_a[pos_a];
                pos_a++;
            }
            else{
                new_arr[pos] = arr_b[pos_b];
                pos_b++;
            }
        }
        else if(pos_a >= size_a){
            new_arr[pos] = arr_b[pos_b];
            pos_b++;
        }
        else{
            new_arr[pos] = arr_a[pos_a];
            pos_a++;
        }

        pos++;

    }

    // Copy combines array into array_a
    std::copy(new_arr, new_arr + new_size, arr_a);

}

void display(int* arr, int size){
    for(int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}