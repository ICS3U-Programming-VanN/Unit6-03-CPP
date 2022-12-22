// Copyright (c) 2022 Van Nguyen All rights reserved.
//
// Created by: Van Nguyen
// Created on: December 15, 2022
// This program generates 10 random numbers from
// 0 - 100 and then finds and displays the lowest/min
// number of all of them


#include <array>
#include <iostream>
#include <random>


// Declared Constant at global scope (for function)
const int MAX_ARRAY_SIZE = 10;

// This function finds and returns the min value of an array
int FindMinValue(std::array<int, MAX_ARRAY_SIZE> randomIntegerList) {
    // Initialized Variable to 101 (impossible to generate)
    int listMinNumber = 101;

    // Goes through each index of the array to determine the lowest number
    for (int index : randomIntegerList) {
        // Checks if the index of the list is lower than
        // the placeholder value for the lowest number
        if (index < listMinNumber) {
            // Assigns the placeholder variable to the number
            // in the index of the array
            listMinNumber = index;
        }
    }

    // Returns the min number of the list to the array
    return listMinNumber;
}

int main() {
    // Declared Constants
    const int MIN_NUM = 0;
    const int MAX_NUM = 100;

    // Declared Array with size of 10
    std::array<int, MAX_ARRAY_SIZE> arrayOfIntegers;

    // Declared Variables
    int randomNumber, minNumber;

    // Generates 10 random numbers and adds them to an array
    // Displays what number and where it was added to (to console)
    for (int counter = 0; counter < MAX_ARRAY_SIZE; counter++) {
        // Generates a random number (from 0-100)
        std::random_device rseed;
        std::mt19937 rgen(rseed());
        std::uniform_int_distribution<int> idist(MIN_NUM, MAX_NUM);

        // Holds the random number (in variable)
        randomNumber = idist(rgen);

        // Adds the random number to the array
        arrayOfIntegers[counter] = randomNumber;

        // Displays what number and where it was added to in the array
        std::cout << arrayOfIntegers[counter]
                  << " added to the array at position " << counter << std::endl;
    }

    // Calls function to find the min  number in the array
    minNumber = FindMinValue(arrayOfIntegers);

    // Displays the lowest number in the array to the console
    std::cout << "\nThe min of the numbers: " << minNumber << std::endl;
}
