#include <iostream>
#include <sstream>
#include <fstream>
#include "Gameplay.h"
using namespace std;

int main(int argc, char **argv) {

    // GETTING MAP MATRIX SIZES
    stringstream size(argv[1]);
    string sizes_str;
    string sizes_array[2];
    int s = 0;
    while (getline(size, sizes_str, 'x')) {
        stringstream ss_s(sizes_str);
        ss_s >> sizes_array[s];
        s++;
    }
    int size_y;
    int size_x;
    (stringstream)sizes_array[0] >> size_y;
    (stringstream) sizes_array[1] >> size_x;

    // GETTING KEY MATRIX SIZE
    int key_size;
    (stringstream) argv[2] >> key_size;

    // CREATING MAP MATRIX 2D ARRAY
    int **map_arr;
    map_arr = new int *[size_y];
    for (int j = 0; j < size_y; j++) {
        map_arr[j] = new int[size_x];
    }
    ifstream map_file(argv[3]);
    if (map_file.is_open()) {
        for (int j = 0; j < size_y; j++) {
            for (int i = 0; i < size_x; i++) {
                map_file >> map_arr[j][i];
            }
        } map_file.close();
    } else cout << "\nMap matrix file could not be opened.\n";

    // CREATING KEY MATRIX ARRAY
    int **key_arr;
    key_arr = new int *[key_size];
    for (int j = 0; j < key_size; j++) {
        key_arr[j] = new int[key_size];
    }
    ifstream key_file(argv[4]);
    if (key_file.is_open()){
        for (int j = 0; j < key_size; j++) {
            for (int i = 0; i < key_size; i++) {
                key_file >> key_arr[j][i];
            }
        } map_file.close();
    } else cout << "\nKey matrix file could not be opened.\n";

    // OPENING OUTPUT FILE
    FILE  *output_file = fopen(argv[5], "w");

    // RECURSIVE FUNCTION THAT PLAYS THE GAME
    Gameplay::gameplay(map_arr,key_arr,key_size/2,key_size/2,size_y,size_x,key_size, output_file);

    // DELETING ARRAYS
    for (int i = 0; i < size_y; i++) { delete[] map_arr[i]; } delete[] map_arr;
    for (int i = 0; i < key_size; i++) { delete[] key_arr[i]; } delete[] key_arr;
    return 0;
}