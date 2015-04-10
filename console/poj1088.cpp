//
//  poj1088.cpp
//  console
//
//  Created by yuanrui on 15-4-1.
//  Copyright (c) 2015年 KudoCC. All rights reserved.
//

#include <stdio.h>

#define N 101
#define NOTEXIST -1

int array[N][N] ;
int max[N][N] ;

int maxDyn(int i, int j) ;


int main1088(int argc, const char * argv[]) {
    int row = 0 ;
    int col = 0 ;
    scanf("%d%d", &row, &col) ;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            scanf("%d", &array[i][j]) ;
            max[i][j] = NOTEXIST ;
        }
    }
    
    int max = 0 ;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            int tmp = maxDyn(i, j) ;
            max = tmp > max ? tmp : max ;
        }
    }
    printf("%d\n", max) ;
    return 0;
}

// 上 下 左 右
int dd[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}} ;

int maxDyn(int row, int col)
{
    int iMax = 1 ;
    for (int i = 0; i < 4; ++i) {
        int iTmp = 1 ;
        int *a = dd[i] ;
        int tRow = row + a[0] ;
        int tCol = col + a[1] ;
        if (tRow >= 0 && tCol >= 0 && array[tRow][tCol] < array[row][col]) {
            if (max[tRow][tCol] != NOTEXIST) {
                iTmp = max[tRow][tCol]+1 ;
            } else {
                iTmp = maxDyn(tRow, tCol)+1 ;
            }
        }
        iMax = iMax < iTmp ? iTmp : iMax ;
    }
    max[row][col] = iMax ;
    return iMax ;
}
