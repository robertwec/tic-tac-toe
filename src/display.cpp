#include "display.h"
#include <ncurses.h>

Display::Display()
{
    initscr(); // Initialize the window
    noecho(); // Don't echo any keypresses
    curs_set(FALSE); // Don't display a cursor
    use_default_colors();
}

void Display::render(const Logic &logic)
{
    set_dimensions();
    set_array_of_field_dimensions(logic.get_board_size());
    draw(logic);

}

Display::~Display()
{
    endwin();
}

void Display::set_dimensions()
{
    getmaxyx(stdscr, number_of_rows, number_of_columns);
    if(number_of_rows <= number_of_columns) {
        start_y = 0;
        end_y = number_of_rows;
        start_x = (number_of_columns - number_of_rows)/4;
        end_x = start_x + number_of_rows + (number_of_columns - number_of_rows)/2;
    } else {
        start_y = (number_of_rows - number_of_columns)/4;
        end_y = start_y + number_of_columns + (number_of_rows - number_of_columns)/2;
        start_x = 0;
        end_x = number_of_columns;
    }

}

void Display::set_array_of_field_dimensions(const int board_size)
{
    boardFields = std::vector< std::vector<FieldCoordinates> > (
                board_size, std::vector<FieldCoordinates>(board_size, {0, 0, 0, 0}));

    for(int x = 0; x < board_size; x++) {
        for(int y = 0; y < board_size; y++) {
            boardFields[x][y].x_start = start_x + x*((end_x-start_x)/board_size);
            boardFields[x][y].x_end = start_x + (x+1)*((end_x-start_x)/board_size);
            boardFields[x][y].y_start = start_y + y*((end_y-start_y)/board_size);
            boardFields[x][y].y_end = start_y + (y+1)*((end_y-start_y)/board_size);
        }
    }
}

void Display::draw(const Logic &logic)
{
    clear();
    std::vector<std::vector<BoardField> > board = logic.getBoard();
    for(int x = 0; x < logic.get_board_size(); x++) {
        for(int y = 0; y < logic.get_board_size(); y++) {
            if(board[x][y] == BoardField::O) {
                ncurses_utils.circle(boardFields[x][y].x_start+1, boardFields[x][y].x_end-1, boardFields[x][y].y_start+1, boardFields[x][y].y_end-1);
            } else if(board[x][y] == BoardField::X) {
                ncurses_utils.draw_x(boardFields[x][y].x_start+1, boardFields[x][y].x_end-1, boardFields[x][y].y_start+1, boardFields[x][y].y_end-1);
            }

            ncurses_utils.rectangle(boardFields[x][y].x_start, boardFields[x][y].x_end, boardFields[x][y].y_start, boardFields[x][y].y_end);
        }
    }
    start_color();
    init_pair(1, COLOR_RED, -1);
    attron(COLOR_PAIR(1));
    int x = logic.getSelected_field().x;
    int y = logic.getSelected_field().y;
    ncurses_utils.rectangle(boardFields[x][y].x_start, boardFields[x][y].x_end, boardFields[x][y].y_start, boardFields[x][y].y_end);
    attroff(COLOR_PAIR(1));
    refresh();
}
