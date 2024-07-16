#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "canvas.h"
#include "commands.h"

// Function to print available commands to the console
void print_help() {
    
    //prints all commands the program takes
    
    printf("Commands:\n");
    printf("Help: h\n");
    printf("Quit: q\n");
    printf("Draw line: w row_start col_start row_end col_end\n");
    printf("Resize: r num_rows num_cols\n");
    printf("Add row or column: a [r | c] pos\n");
    printf("Delete row or column: d [r | c] pos\n");
    printf("Erase: e row col\n");
    printf("Save: s file_name\n");
    printf("Load: l file_name\n");
}
// Function to create and initialize a new canvas

char** make_canvas(Canvas board) {
    
    //creates an empty matrix with dimensions inside struct
  
    char** canvas;
    canvas = (char**)malloc(board.num_rows * sizeof(char*));
    for (int i = 0; i < board.num_rows; ++i) {
        canvas[i] = (char*)malloc(board.num_cols * sizeof(char));
    }
    for (int i = 0; i < board.num_rows; ++i) {
        for (int j = 0; j < board.num_cols; ++j) {
            canvas[i][j] = '*';
        }
    }
    return canvas;
}

void display_canvas(Canvas board) {
    /**
    prints the current canvas to the screen
    @board: a struct holding the canvas contents
    @returns: nothing
    */
    int row_num = board.num_rows - 1;

    for (int i = row_num; i >= 0; --i, --row_num) {
        printf("%d ", row_num);
        for (int j = 0; j < board.num_cols; ++j) {
            printf("%c ", board.table[i][j]);
        }
        printf("\n");
    }

    printf("  ");
    for (int i = 0; i < board.num_cols; ++i) {
        printf("%d ", i);
    }
    printf("\n");
}

char* getFileName() {
    
    //reads file name from command argument
    
    char ch = '?';
    int CUR_MAX = 20;
    char* buffer = (char*)malloc(sizeof(char) * CUR_MAX);
    int length = 0;

    while (ch != '\n') {
        if (length == CUR_MAX) {
            CUR_MAX *= 2;
            buffer = realloc(buffer, CUR_MAX);
        }
        ch = getc(stdin);
        if (!isspace(ch)) {
            buffer[length] = ch;
            length++;
        }
    }

    return buffer;
}

void save(Canvas board) {
    
    // saves the current canvas to a text file
    
    FILE* fp;
    char* file_name = getFileName();
    fp = fopen(file_name, "w");
    if (fp == NULL) {
        printf("Improper save command or file could not be created.\n");
        return;
    }

    fprintf(fp, "%d %d", board.num_rows, board.num_cols);
    fprintf(fp, "\n");
    for (int row = 0; row < board.num_rows; ++row) {
        for (int col = 0; col < board.num_cols; ++col) {
            fprintf(fp, "%c", board.table[row][col]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void load(Canvas* board) {
    
    // replaces the current canvas with one loaded from a text file
  
    FILE* fp;
    char* file_name = getFileName();
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Improper load command or file could not be opened.\n");
        return;
    }
  // Free the existing canvas and create a new one based on file data
  
    free(board->table);
    fscanf(fp, "%d %d", &board->num_rows, &board->num_cols);
    board->table = make_canvas(*board);

    for (int row = 0; row < board->num_rows; ++row) {
        for (int col = 0; col < board->num_cols; ++col) {
            fscanf(fp, "%c ", &board->table[row][col]);
            if (board->table[row][col] == '\n') {
                col--;
            }
        }
    }
    fclose(fp);
}

