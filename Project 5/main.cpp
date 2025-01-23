//Rahma Seid
//CSCI 3110
//Project 5: This program calculates Fibonacci numbers, sums up integers, finds the largest element in an array,
// and identifies and counts the number of connected objects (eagles) in a photograph grid using recursion.

#include <iostream>
#include <fstream>
#include "parameters.h"

using namespace std;

// Define a constant for the array size
const int MAX_SIZE = 50;

// Function Prototypes
int fibonacci(int n);
int sum(int n);
int largest(const int arr[], int size);
int findEagle(int grid[MAX_SIZE][MAX_SIZE], int rows, int cols, int x, int y);
void processPhotographs(const char* filename);

// Main Function
int main() {

    // Process Eagles from the data file
    processPhotographs("eagle.dat");

    return 0;
}

// Fibonacci Function (Recursive)
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Sum Function (Recursive)
int sum(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n + sum(n - 1);
    }
}

// Largest Function (Recursive)
int largest(const int arr[], int size) {
    if (size == 1) {
        return arr[0];
    }
    int max_of_rest = largest(arr, size - 1);
    return (arr[size - 1] > max_of_rest) ? arr[size - 1] : max_of_rest;
}

// Find Eagles Function (Recursive)
int findEagle(int grid[MAX_SIZE][MAX_SIZE], int rows, int cols, int x, int y) {
    // Base conditions to stop the recursion
    if (x < 0 || y < 0 || x >= rows || y >= cols || grid[x][y] == 0) {
        return 0;
    }

    // Count the current cell and set it to 0 (erasing the eagle)
    int count = 1;
    grid[x][y] = 0;

    // Recursively explore all 8 neighboring cells
    count += findEagle(grid, rows, cols, x - 1, y - 1);
    count += findEagle(grid, rows, cols, x - 1, y);
    count += findEagle(grid, rows, cols, x - 1, y + 1);
    count += findEagle(grid, rows, cols, x, y - 1);
    count += findEagle(grid, rows, cols, x, y + 1);
    count += findEagle(grid, rows, cols, x + 1, y - 1);
    count += findEagle(grid, rows, cols, x + 1, y);
    count += findEagle(grid, rows, cols, x + 1, y + 1);

    return count;
}

// Function to Process Photographs from File
struct Photograph {
    int grid[MAX_SIZE][MAX_SIZE];
    int rows;
    int cols;
};

void processPhotographs(const char* filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: could not open file " << filename << endl;
        return;
    }

    Photograph photos[MAX_SIZE];
    int num_photos = 0;
    while (file >> photos[num_photos].rows >> photos[num_photos].cols) {
        for (int i = 0; i < photos[num_photos].rows; ++i) {
            for (int j = 0; j < photos[num_photos].cols; ++j) {
                file >> photos[num_photos].grid[i][j];
            }
        }
        num_photos++;
    }
    file.close();

    for (int p = 0; p < num_photos; ++p) {
        Photograph photo = photos[p];
        for (int i = 0; i < photo.rows; ++i) {
            for (int j = 0; j < photo.cols; ++j) {
                cout << photo.grid[i][j] << " ";
            }
            cout << "\n";
        }

        int eagle_count = 0;
        for (int i = 0; i < photo.rows; ++i) {
            for (int j = 0; j < photo.cols; ++j) {
                if (photo.grid[i][j] != 0) {
                    int eagle_size = findEagle(photo.grid, photo.rows, photo.cols, i, j);
                    cout << "An eagle size " << eagle_size << " is found." << endl;
                    eagle_count++;
                }
            }
        }
        cout << "\n" << eagle_count << " eagle(s) found in the picture." << "\n" << endl;
    }
}













