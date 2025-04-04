/*Author: MIDN Ronny Saini
 *Filename: part4.cpp
 *Sierpinski Carpet
 */

#include <iostream>
using namespace std;

void repeat(char s, int count) {
    if (count == 0) {
        return;
    } else {
        cout << s;
        repeat(s, count - 1);
    }
}

void triangle_row(int width, int row_index, int height) {
    // Base case: when width is 1, print a triangle character
    if (width == 1) {
        cout << "\u25b2"; // Triangle character ▲
    } else {
        int segment_width = width / 2;
        int segment_height = (height + 1) / 2;

        if (row_index < segment_height) {
            repeat(' ', segment_width);
            triangle_row(segment_width, row_index, segment_height);
            repeat(' ', segment_width);
        } else {
            triangle_row(segment_width, row_index - segment_height, segment_height);
            repeat('.', width - 2);
            triangle_row(segment_width, row_index - segment_height, segment_height);
        }
    }
}

int main() {
    int height;
    cout << "Enter height of the Sierpinski triangle: ";
    cin >> height;

    int width = 2 * height - 1;

    for (int row = 0; row < width; row++) {
        triangle_row(width, row, height);
        cout << endl;
    }

    return 0;
}
