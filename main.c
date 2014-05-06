#include "2048.h"
#include "win.h"

void printWin(int arr[HIGHT][WIDTH]);

int main(void)
{   
  
    extern int flag;
    int i, j;
    int arr[HIGHT][WIDTH] = {0};
    int ch;

    initArr(arr);
    printWin(arr);

    /* Initialize the window parameters */
    mvprintw(0,0,"%s","Press F1 to exit");

    while((ch = getch()) != KEY_F(1))
    {

        switch(ch)
        {
            //case KEY_LEFT:
            case 'h':
            leftArrow(arr);
            printWin(arr);
            break;
            //case KEY_RIGHT:
            case 'l':
            rightArrow(arr);
            printWin(arr);
            break;
            //case KEY_UP:
            case 'k':
            upArrow(arr);
            printWin(arr);
            break;
            //case KEY_DOWN:
            case 'j':
            downArrow(arr);
            printWin(arr);
            break;
        }
    }
    endwin();/* End curses mode  */
    return 0;
}   


void printWin(int arr[HIGHT][WIDTH])
{
    WIN win[HIGHT][WIDTH];
    int i, j;
    initscr();/* Start curses mode */
    start_color();/* Start the color functionality */
    cbreak();/* Line buffering disabled, Pass on * everty thing to me */
    keypad(stdscr, TRUE);/* I need that nift                        y F1 */
    noecho();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    for(i = 0; i < HIGHT; i++)
    {
        for(j = 0; j < WIDTH; j++)
        {
            WIN *thewin = &win[i][j];
            init_win_params(&win[i][j], i, j);
            print_win_params(&win[i][j]);
            create_box(&win[i][j], TRUE);
            mvprintw(thewin->starty + WINY/2 , thewin->startx + WINX/2,"%d", arr[i][j]);
        }
    }
    refresh();
}
