/**
 * @file main.c
 * @Synopsis  2048游戏
 * @author chenxiaonan
 * @version 1.0
 * @date 2014-05-06
 */

#include <stdlib.h> 
#include <string.h> 
#include "2048.h"
#include "win.h"
#include <math.h> 

//extern int SCORE;

void printWin(int arr[HIGHT][WIDTH]);

int main(void)
{   
  
    extern int flag;
    int i, j;
    int arr[HIGHT][WIDTH] = {0};
    int ch;

    initArr(arr);

    initscr();/* Start curses mode */
    cbreak();/* Line buffering disabled, Pass on * everty thing to me */
    keypad(stdscr, TRUE);/* I need that nift                        y F1 */
    noecho();
    start_color();/* Start the color functionality */

    printWin(arr);

    /* Initialize the window parameters */
    mvprintw(0,0,"%s","Press F1 to exit");
    while((ch = getch()) != KEY_F(1))
    {
        switch(ch)
        {
            case KEY_LEFT:
            case 'h':
            leftArrow(arr);
            printWin(arr);
            break;
            case KEY_RIGHT:
            case 'l':
            rightArrow(arr);
            printWin(arr);
            break;
            case KEY_UP:
            case 'k':
            upArrow(arr);
            printWin(arr);
            break;
            case KEY_DOWN:
            case 'j':
            downArrow(arr);
            printWin(arr);
            break;
        }
    }
    endwin();
    return 0;
}   


void printWin(int arr[HIGHT][WIDTH])
{
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);

    init_pair(8, COLOR_WHITE, COLOR_YELLOW);

    WIN win[HIGHT][WIDTH];
    int i, j;
    for(i = 0; i < HIGHT; i++)
    {
        for(j = 0; j < WIDTH; j++)
        {
            int offset;
            WIN *thewin = &win[i][j];
            init_win_params(&win[i][j], j-3, i-3);
            print_win_params(&win[i][j]);
            attron(COLOR_PAIR(7));
            create_box(&win[i][j], TRUE);
            attroff(COLOR_PAIR(7));
            mvprintw(thewin->starty + WINY/2 , thewin->startx + WINX/2-4,"%s", "         ");
            if(arr[i][j] == 0){
                attron(COLOR_PAIR(1));
                offset = 0;
            } else {
                attron(COLOR_PAIR((int)log2((double)arr[i][j])%7 + 1));
                offset = (int)(log10((double)arr[i][j])/2);
            }
            mvprintw(thewin->starty + WINY/2 , thewin->startx + WINX/2-offset,"%d", arr[i][j]);
            if(arr[i][j] == 0){
                attroff(COLOR_PAIR(1));
            } else {
                attroff(COLOR_PAIR((int)log2((double)arr[i][j])%7 + 1));
            }
            move(0,0);
//            mvprintw(10,10,"%s%d","Your Score: ", SCORE);
        }
    }
    refresh();
}

