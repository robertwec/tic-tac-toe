#include "ncursesutils.h"

#include <ncurses.h>
#include <cmath>

NCursesUtils::NCursesUtils()
{

}

void NCursesUtils::rectangle(int x1, int x2, int y1, int y2)
{
    mvhline(y1, x1, 0, x2-x1);
    mvhline(y2, x1, 0, x2-x1);
    mvvline(y1, x1, 0, y2-y1);
    mvvline(y1, x2, 0, y2-y1);
    mvaddch(y1, x1, ACS_ULCORNER);
    mvaddch(y2, x1, ACS_LLCORNER);
    mvaddch(y1, x2, ACS_URCORNER);
    mvaddch(y2, x2, ACS_LRCORNER);
}

void NCursesUtils::circle(int x1, int x2, int y1, int y2)
{
    double half_x_length = std::abs((x2-x1)/2.0);
    double half_y_length = std::abs((y2-y1)/2.0);
    for (int deg = 0; deg < 360.0f; deg += 1.0f) {
        int x = x1 + half_x_length + half_x_length * cos(degree_to_radians(deg));
        int y = y1 + half_y_length + half_y_length * sin(degree_to_radians(deg));

        mvaddch(y,x,'O');
    }
}

void NCursesUtils::draw_x(int x1, int x2, int y1, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    for(int x = x1; x <= x2; x++) {
      int y = y1 + dy * (x - x1) / (double)dx;
      mvaddch(y,x,'X');
    }
    for(int x = x1; x <= x2; x++) {
      int y = y2 - dy * (x - x1) / (double)dx;
      mvaddch(y,x,'X');
    }
}

float NCursesUtils::degree_to_radians(float degree)
{
    return degree * (180.0f/M_PI);
}
