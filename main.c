// main.c
// Text-based paint program in C.
// Allows users to create and manipulate a canvas with various commands.
// This program simulates a text based version of paint.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "canvas.h"
#include "commands.h"

// Entry point of the program
int main(int argc, char** argv) {
    Canvas board; // Declare a Canvas struct to hold the drawing board
    bool validRowCount = false; // Flag to check if row count is valid
    bool defaultBoard = true; // Flag to indicate if default board size is used

    // Set default board size
    board.num_rows = 10, board.num_cols = 10;

    // Handle command line arguments for custom board size
    if (argc == 3) {
        // Check if first argument (number of rows) is a valid integer
        if (atoi(argv[1]) != 0) {
            // Check if the number of rows is positive
            if (atoi(argv[1]) > 0) {
                board.num_rows = atoi(argv[1]); // Set custom number of rows
                validRowCount = true;
            }
            else {
                printf("The number of rows is less than 1.\n");
            }
        }
        else {
            printf("The number of rows is not an integer.\n");
        }

        // Check if second argument (number of columns) is valid
        if (validRowCount) {
            if (atoi(argv[2]) != 0) {
                // Check if the number of columns is positive
                if (atoi(argv[2]) > 0) {
                    board.num_cols = atoi(argv[2]); // Set custom number of columns
                    defaultBoard = false;
                }
                else {
                    printf("The number of columns is less than 1.\n");
                    board.num_rows = 10; // Reset to default rows
                }
            }
            else {
                printf("The number of columns is not an integer.\n");
                board.num_rows = 10; // Reset to default rows
            }
        }
    }
    else if (argc != 1) {
        // Handle incorrect number of command line arguments
        printf("Wrong number of command line arguments entered.\n");
        printf("Usage: ./paint.out [num_rows num_cols]\n");
    }

    // Notify user about default board creation
    if (defaultBoard && argc != 1) {
        printf("Making default board of 10 X 10.\n");
    }

    // Create and display the canvas
    board.table = make_canvas(board);
    display_canvas(board);

    // Main command loop
    char command = '\0';
    do {
        printf("Enter your command: ");
        // Read commands from the user
        do {
            scanf("%c", &command);
        } while (!isalpha(command)); // Ensure command is a letter

        // Process commands
        if (command == 'h') {
            print_help();
        }
        else if (command == 'w') {
            write(&board);
        }
        else if (command == 'e') {
            erase(&board);
        }
        else if (command == 'r') {
            resize(&board);
        }
        else if (command == 'a') {
            add(&board);
        }
        else if (command == 'd') {
            _delete(&board);
        }
        else if (command == 's') {
            save(board);
        }
        else if (command == 'l') {
            load(&board);
        }
        else if (command != 'q') {
            // Handle unrecognized commands
            printf("Unrecognized command. Type h for help.\n");
        }

        // Display the canvas unless quitting
        if (command != 'q') {
            display_canvas(board);
        }

        fflush(stdin); // Clear input buffer
    }
    while (command != 'q'); // Exit loop if command is 'q'

    // Clean up and exit
    free(board.table);

    return 0;
}


