#ifndef DISPLAY_H
#define DISPLAY_H

#include "logic.h"
#include "ncursesutils.h"

class Display
{
public:
    Display();
    void render(const Logic &logic);
    ~Display();


private:
    NCursesUtils ncurses_utils;

    int number_of_rows;
    int number_of_columns;
    int start_x, end_x;
    int start_y, end_y;


    struct FieldCoordinates{
        int x_start;
        int x_end;
        int y_start;
        int y_end;
    };

    std::vector< std::vector<FieldCoordinates> > boardFields;

    void set_dimensions();
    void set_array_of_field_dimensions(const int board_size);
    void draw(const Logic &logic);
};

#endif // DISPLAY_H
