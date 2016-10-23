#ifndef NCURSESUTILS_H
#define NCURSESUTILS_H


class NCursesUtils
{
public:
    NCursesUtils();
    void rectangle(int x1, int x2, int y1, int y2);
    void circle(int x1, int x2, int y1, int y2);
    void draw_x(int x1, int x2, int y1, int y2);
private:
    float degree_to_radians(float degree);
};

#endif // NCURSESUTILS_H
