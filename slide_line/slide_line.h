#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

/**
 * @brief Slides and merges an array of integers to the left or right.
 *
 * @param line The array of integers to be slided and merged.
 * @param size The number of elements in the array.
 * @param direction The direction of the slide and merge operation. Can be SLIDE_LEFT or SLIDE_RIGHT.
 *
 * @return 1 upon success, 0 upon failure.
 */
int slide_line(int *line, size_t size, int direction);

#endif
