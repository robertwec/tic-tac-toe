#include "input.h"
#include <ncurses.h>

Input::Input()
{
    keypad( stdscr, TRUE );
}

void Input::process()
{
    last_key = getch();
}

int Input::get_last_key()
{
    return last_key;
}
