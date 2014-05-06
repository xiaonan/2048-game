/**
 * @file caculate.c
 * @Synopsis  2048 titles
 * @author chenxiaonan
 * @version 1.0
 * @date 2014-05-05
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define HIGHT 4
#define WIDTH 4
static int SCORE = 0;
static int flag = 0;
void changeArr(int arr[HIGHT][WIDTH], char);
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

int main(void)
{   
    extern int flag;
    int i, j;
    int arr[HIGHT][WIDTH] = {0};
    initArr(arr);
    echoArr(arr);
    do {
        char  arrow;
        arrow = getchar();
        changeArr(arr, arrow);
        //printf("SCORE: %d\n", SCORE);
    } while(1);
    return 0;
}   


/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  合并数组
 *
 * @Param arr[HIGHT][WIDTH]
 */
/* ----------------------------------------------------------------------------*/
void mergeArr(int arr[HIGHT][WIDTH])
{
    int temp[HIGHT][WIDTH];
    int i,j;
    flag = 0;
    for(int i = 0; i< HIGHT; i++)
    {
        for(int j = 0; j < HIGHT; j++)
        {
            temp[i][j] = arr[i][j];
        }
    }
    dropZero(arr);
    merge(arr);
    dropZero(arr);


    for(int i = 0; i< HIGHT; i++)
    {
        for(int j = 0; j < HIGHT; j++)
        {
            if(temp[i][j] != arr[i][j])
            {
                flag = 1;
                return;
            }
        }
    }
}

/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  向左合并
 *
 * @Param arr[HIGHT][WIDTH]
 * @Param HIGHT
 * @Param WIDTH
 */
/* ----------------------------------------------------------------------------*/
void leftArrow(int arr[HIGHT][WIDTH])
{
    mergeArr(arr);
    randArr(arr);
}

void upArrow(int arr[HIGHT][WIDTH])
{
    antiClockWise90(arr);
    mergeArr(arr);
    randArr(arr);
    clockWise90(arr);
}

void rightArrow(int arr[HIGHT][WIDTH])
{
    antiClockWise90(arr);
    antiClockWise90(arr);
    mergeArr(arr);
    randArr(arr);
    clockWise90(arr);
    clockWise90(arr);
}

void downArrow(int arr[HIGHT][WIDTH])
{
    clockWise90(arr);
    mergeArr(arr);
    randArr(arr);
    antiClockWise90(arr);
}




void changeArr(int arr[HIGHT][WIDTH], char arrow) 
{
    switch(arrow){
        case 'j':
            downArrow(arr);
            puts("----------down arrow---------------");
            echoArr(arr);
            puts("-----------------------------------");
            break;
        case 'k':
            upArrow(arr);
            puts("----------up arrow---------------");
            echoArr(arr);
            puts("-----------------------------------");
            break;
        case 'h':
            leftArrow(arr);
            puts("----------left arrow---------------");
            echoArr(arr);
            puts("-----------------------------------");
            break;
        case 'l':
            rightArrow(arr);
            puts("----------right arrow---------------");
            echoArr(arr);
            puts("-----------------------------------");
            break;
    }

}

void dropZero(int arr[HIGHT][WIDTH])
{
    int i, j;
    for(i = 0; i< HIGHT; i++)
    {
        int temp[WIDTH] = {0};
        int k = 0;
        for( j = 0; j < WIDTH; j++)
        {
            if(arr[i][j] != 0) {
                temp[k++] = arr[i][j];
            }
        }
        for(j = 0; j < WIDTH; j++)
        {
            arr[i][j] = temp[j];
        }
    }
}

void merge(int arr[HIGHT][WIDTH]) 
{
    int i, j;
    for(i = 0; i < HIGHT; i++)
    {
        for(j = 0; j < WIDTH - 1; j++)
        {
            if(arr[i][j] == arr[i][j+1])
            {
                arr[i][j] = 2*arr[i][j];
                SCORE += arr[i][j];
                arr[i][j + 1] = 0;
            }
        }
    }
}


/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  输出数组
 *
 * @Param arr[HIGHT][WIDTH]
 * @Param HIGHT
 * @Param WIDTH
 */
/* ----------------------------------------------------------------------------*/
void echoArr(const int arr[HIGHT][WIDTH])
{
    int i, j, k = 0;
    for(i = 0; i < HIGHT; i++)
    {
        for(j = 0; j < WIDTH; j++)
        {
            printf("%10d",arr[i][j]);
            k++;
            if(k%4 == 0) {
                printf("\n");
            }
        }
    }
    printf("\n");
}


/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  顺时针旋转数组
 *
 * @Param arr[HIGHT][WIDTH]
 * @Param HIGHT
 * @Param WIDTH
 */
/* ----------------------------------------------------------------------------*/
void clockWise90(int arr[HIGHT][WIDTH])
{
    int temp[HIGHT][WIDTH] = {0};
    int i, j;

    for( int i = 0; i < HIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            temp[i][j] = arr[HIGHT - 1 - j][i];
        }
    }
    for( int i = 0; i < HIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            arr[i][j] = temp[i][j];
        }
    }
}

/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  逆时针旋转数组
 *
 * @Param arr[HIGHT][WIDTH]
 * @Param HIGHT
 * @Param WIDTH
 */
/* ----------------------------------------------------------------------------*/
void antiClockWise90(int arr[HIGHT][WIDTH])
{
    int temp[HIGHT][WIDTH] = {0};
    int i, j;

    for( int i = 0; i < HIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            temp[i][j] = arr[j][WIDTH - 1 - i];
        }
    }
    for( int i = 0; i < HIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            arr[i][j] = temp[i][j];
        }
    }
}

int randNum(void)
{
    srand((unsigned int)time(0));
    if(rand() % 20 == 0) {
        return 4;
    }
    return 2;
}

void randArr(int arr[HIGHT][WIDTH]){

    int i, j;
    int zeroNum = 0;
    int luckyNum;
    int indexNum = 0;
    if(flag == 0) {
        return;
    }
    for(i = 0; i < HIGHT; i++)
    {
        for(j = 0; j < WIDTH; j++)
        {
            if(arr[i][j] == 0)
                zeroNum++;
        }
    }   
    if(zeroNum == 0) 
    {
        puts("Sorry you are die");
        exit(0);
    }
    srand((unsigned int)time(0));
    luckyNum = rand() % zeroNum;
    for(i = 0; i < HIGHT; i++)
    {
        for(j = 0; j < WIDTH; j++)
        {
            if(arr[i][j] == 0)
            {
                if(luckyNum == indexNum) {
                    arr[i][j] = randNum();
                    return;
                }
                indexNum++;
            }
        }
    }

}

void initArr(int arr[HIGHT][WIDTH])
{
    int i, j;
    int luckyNum1, luckyNum2;
    int indexNum = 0;
    srand((unsigned int)time(0));
    luckyNum1 = rand() % HIGHT*WIDTH;
    srand((unsigned int)time(0));
    do{
        luckyNum2 = rand() % HIGHT*WIDTH;
    } while(luckyNum1 == luckyNum2);
    for(i = 0; i < HIGHT; i++)
    {
        for(j = 0; j < WIDTH; j++)
        {
            if(arr[i][j] == 0)
            {
                if(luckyNum1 == indexNum) {
                    arr[i][j] = randNum();
                }
                if(luckyNum2 == indexNum) {
                    arr[i][j] = randNum();
                }
                indexNum++;
            }
        }
    }

}
