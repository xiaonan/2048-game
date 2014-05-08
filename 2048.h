#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define HIGHT 4
#define WIDTH 4
int SCORE;
static int flag = 0;
void dropZero(int arr[HIGHT][WIDTH]);
void merge(int arr[HIGHT][WIDTH]);
void echoArr(const int arr[HIGHT][WIDTH]);
void clockWise90(int arr[HIGHT][WIDTH]);
void antiClockWise90(int arr[HIGHT][WIDTH]);
void leftArrow(int arr[HIGHT][WIDTH]);
void upArrow(int arr[HIGHT][WIDTH]);
void rightArrow(int arr[HIGHT][WIDTH]);
void downArrow(int arr[HIGHT][WIDTH]);
int randNum(void);
void randArr(int arr[HIGHT][WIDTH]);
void initArr(int arr[HIGHT][WIDTH]);
