/*
Write a method that returns all subsets of a set.
*/

#include <iostream>
#include <vector>

void findAllSubsets(std::vector<int>&, std::vector< std::vector<int> >&, int);

void display(std::vector< std::vector<int> >&);

int main(){
    std::vector<int> set;
    set.push_back(1);
    set.push_back(2);
    set.push_back(3);
    set.push_back(4);
    set.push_back(5);

    std::vector< std::vector<int> > all_subsets;

    findAllSubsets(set, all_subsets, 0);

    display(all_subsets);
}

void findAllSubsets(std::vector<int>& set, std::vector< std::vector<int> >& all_subsets, int pos){

    if(pos < set.size()){
        if(pos == 0){
            std::vector<int>* empty = new std::vector<int>;
            std::vector<int>* first_set = new std::vector<int>;

            first_set->push_back(set[0]);

            all_subsets.push_back(*empty);
            all_subsets.push_back(*first_set);

            findAllSubsets(set, all_subsets, ++pos);

        }
        else{
            for(int i = 0; i < all_subsets.size(); i++){
                std::vector<int>* new_set = new std::vector<int>;

                for(int j = 0; j < all_subsets[i].size(); j++){
                    new_set->push_back(all_subsets[i][j]);
                }

                new_set->push_back(set[pos]);

                for(int k = 0; k < new_set->size(); k++){
                    std::cout << (*new_set)[k] << " ";
                }
                std::cout << std::endl;
                //all_subsets.push_back(*new_set);
            }
            

            //findAllSubsets(set, all_subsets, ++pos);
            
        }
    }
}

void display(std::vector< std::vector<int> >& all_subsets){
    for(int i = 0; i < all_subsets.size(); i++){

        std::cout << "All_Subset[" << i << "]: { ";

        for(int j = 0; j < all_subsets[i].size(); j++){
            std::cout << all_subsets[i][j] << " ";
        }

        std::cout << "} " << std::endl;
    }
}
