#include <iostream>
#include "display.h"
#include "input.h"
#include "logic.h"
#include <ncurses.h>

using namespace std;

int main(int argc, char *argv[])
{
    const char EXIT_KEY = 'q';

    Display display;
    Input input;
    Logic logic;

    display.render(logic);

    while(input.get_last_key() != EXIT_KEY) {
        input.process();
        logic.update(input.get_last_key());
        display.render(logic);
    }
    return 0;
}
