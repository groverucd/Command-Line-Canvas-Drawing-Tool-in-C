#ifndef COMMANDS_H
#define COMMANDS_H

#include "canvas.h"

    // Validates the format and type of command arguments.
    int validateArguments(char* format, ...);

    // Draws a vertical line on the canvas.
    void vertical_draw(Canvas* board, int col, int row_start, int row_end);

    // Draws a horizontal line on the canvas.
    void horizontal_draw(Canvas* board, int col_start, int col_end, int row);

    // Draws an upward diagonal line on the canvas.
    void up_diagonal_draw(Canvas* board, int col_start, int row_start, int col_end, int row_end);

    // Draws a downward diagonal line on the canvas.
    void down_diagonal_draw(Canvas* board, int col_start, int row_start, int col_end, int row_end);

    // Interprets user input to draw lines on the canvas.
    void write(Canvas* board);

    // Erases a specific point on the canvas.
    void erase(Canvas* board);

    // Adds a row or column to the canvas.
    void add(Canvas* board);

    // Deletes a row or column from the canvas.
    void _delete(Canvas* board);

    // Resizes the canvas to new dimensions.
    void resize(Canvas* board);

#endif /* COMMANDS_H */
