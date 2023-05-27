#include <iostream>
#include "Gameplay.h"

int Gameplay::gameplay(int** map_matrix, int** key_matrix, int current_y, int current_x, int map_size_y, int map_size_x, int key_size, FILE *output_file){

    // CHECKING CURRENT POSITION IF IT IS OUT OF MAP MATRIX
    if (current_y < 0 || current_x < 0 || current_y >= map_size_y ||current_x >=map_size_x) {
        return 0;
    }

    // RESULT OF MULTIPLICATION OF KEY MATRIX AND MAP SUB-MATRIX
    int result = 0;
    for (int y = 0; y < key_size; y++) {
        for (int x = 0; x < key_size; x++) {
            result += key_matrix[y][x] * map_matrix[current_y - key_size/2 + y][current_x - key_size/2 + x];
        }
    }

    // WRITING OUTPUT
    fprintf(output_file,"%d,%d;%d",current_y, current_x, result);

    // FINDING ROTATION
    int rotation = 0;
    if (result >= 0){
        rotation += result % 5;
    } else {
        rotation += result % 5 + 5;
    }

    // FINDING TREASURE
    if (rotation == 0){
        return 1;
    }

    // GOING UP
    if (rotation == 1){
        fprintf(output_file,"\n");
        if (gameplay(map_matrix, key_matrix, current_y - key_size, current_x, map_size_y, map_size_x, key_size, output_file) == 1){
            return 1;
        }
        else if (gameplay(map_matrix, key_matrix, current_y + key_size, current_x, map_size_y, map_size_x, key_size, output_file) == 1){
            return 1;
        }
    }

    // GOING DOWN
    if (rotation == 2){
        fprintf(output_file,"\n");
        if (gameplay(map_matrix, key_matrix, current_y + key_size, current_x, map_size_y, map_size_x, key_size, output_file) == 1){
            return 1;
        }
        else if (gameplay(map_matrix, key_matrix, current_y - key_size, current_x, map_size_y, map_size_x, key_size, output_file) == 1){
            return 1;
        }
    }

    // GOING RIGHT
    if (rotation == 3){
        fprintf(output_file,"\n");
        if (gameplay(map_matrix, key_matrix, current_y, current_x + key_size, map_size_y, map_size_x, key_size, output_file) == 1){
            return 1;
        }
        else if (gameplay(map_matrix, key_matrix, current_y, current_x - key_size, map_size_y, map_size_x, key_size, output_file) == 1){
            return 1;
        }
    }

    // GOING LEFT
    if (rotation == 4){
        fprintf(output_file,"\n");
        if (gameplay(map_matrix, key_matrix, current_y, current_x - key_size, map_size_y, map_size_x, key_size, output_file) == 1){
            return 1;
        }
        else if (gameplay(map_matrix, key_matrix, current_y, current_x + key_size, map_size_y, map_size_x, key_size, output_file) == 1){
            return 1;
        }
    }

    return 0;
}