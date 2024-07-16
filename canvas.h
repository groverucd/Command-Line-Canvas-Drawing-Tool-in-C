#ifndef CANVAS_H
#define CANVAS_H

    // Define a structure for the Canvas
    typedef struct Canvas {
        int num_rows; // Number of rows in the canvas
        int num_cols; // Number of columns in the canvas
        char** table; // Pointer to a 2D array representing the canvas
    } Canvas;

    // Function declarations:

    // Prints available commands to the console
    void print_help();

    // Creates and initializes a new canvas based on the provided dimensions
    char** make_canvas(Canvas board);

    // Displays the current state of the canvas
    void display_canvas(Canvas board);

    // Reads a file name from user input
    char* getFileName();

    // Saves the current state of the canvas to a file
    void save(Canvas board);

    // Loads a canvas state from a file and replaces the current canvas
    void load(Canvas* board);

#endif /* CANVAS_H */
