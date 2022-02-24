#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdlib.h>
#include <stdio.h>

#define SLIDE_LEFT 1
#define SLIDE_RIGHT 0
void move_zeros_to_right(int *line, int size);

int slide_line(int *line, size_t size, int direction);
#endif
