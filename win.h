#include <ncurses.h>
#define HIGHT 4
#define WIDTH 4
#define WINY 4
#define WINX 10
typedef struct _win_border_struct {
    chtype ls, rs, ts, bs, 
           tl, tr, bl, br;
}WIN_BORDER;

typedef struct _WIN_struct {

    int startx, starty;
    int height, width;
    WIN_BORDER border;
}WIN;

void init_win_params(WIN *p_win, int , int);
void print_win_params(WIN *p_win);
void create_box(WIN *win, bool flag);
