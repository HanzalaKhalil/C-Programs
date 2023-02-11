#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char BOARD[8][8][2][4] = {
    {{{"♜"}, {""}},
     {{"♞"}, {""}},
     {{"♝"}, {""}},
     {{"♛"}, {""}},
     {{"♚"}, {""}},
     {{"♝"}, {""}},
     {{"♞"}, {""}},
     {{"♜"}, {""}}},
    {{{"♟"}, {""}},
     {{"♟"}, {""}},
     {{"♟"}, {""}},
     {{"♟"}, {""}},
     {{"♟"}, {""}},
     {{"♟"}, {""}},
     {{"♟"}, {""}},
     {{"♟"}, {""}}},
    {{{" "}, {""}},
     {{" "}, {""}},
     {{" "}, {""}},
     {{" "}, {""}},
     {{" "}, {""}},
     {{" "}, {""}},
     {{" "}, {""}},
     {{" "}, {""}}},
    {{{" "}, {""}},
     {{" "}, {""}},
     {{" "}, {""}},
     {{" "}, {""}},
     {{" "}, {""}},
     {{" "}, {""}},
     {{" "}, {""}},
     {{" "}, {""}}},
    {{{" "}, {""}},
     {{" "}, {""}},
     {{" "}, {""}},
     {{" "}, {""}},
     {{" "}, {""}},
     {{" "}, {""}},
     {{" "}, {""}},
     {{" "}, {""}}},
    {{{" "}, {""}},
     {{" "}, {""}},
     {{" "}, {""}},
     {{" "}, {""}},
     {{" "}, {""}},
     {{" "}, {""}},
     {{" "}, {""}},
     {{" "}, {""}}},
    {{{"♙"}, {""}},
     {{"♙"}, {""}},
     {{"♙"}, {""}},
     {{"♙"}, {""}},
     {{"♙"}, {""}},
     {{"♙"}, {""}},
     {{"♙"}, {""}},
     {{"♙"}, {""}}},
    {{{"♖"}, {""}},
     {{"♘"}, {""}},
     {{"♗"}, {""}},
     {{"♕"}, {""}},
     {{"♔"}, {""}},
     {{"♗"}, {""}},
     {{"♘"}, {""}},
     {{"♖"}, {""}}}};
const int BOARD_INFO[8][8][3] = {
    {{1, 1, 2},
     {1, 1, 3},
     {1, 1, 4},
     {1, 1, 6},
     {1, 1, 5},
     {1, 1, 4},
     {1, 1, 3},
     {1, 1, 2}},
    {{1, 1, 1},
     {1, 1, 1},
     {1, 1, 1},
     {1, 1, 1},
     {1, 1, 1},
     {1, 1, 1},
     {1, 1, 1},
     {1, 1, 1}},
    {{0, 0, 0},
     {0, 0, 0},
     {0, 0, 0},
     {0, 0, 0},
     {0, 0, 0},
     {0, 0, 0},
     {0, 0, 0},
     {0, 0, 0}},
    {{0, 0, 0},
     {0, 0, 0},
     {0, 0, 0},
     {0, 0, 0},
     {0, 0, 0},
     {0, 0, 0},
     {0, 0, 0},
     {0, 0, 0}},
    {{0, 0, 0},
     {0, 0, 0},
     {0, 0, 0},
     {0, 0, 0},
     {0, 0, 0},
     {0, 0, 0},
     {0, 0, 0}},
    {{0, 0, 0},
     {0, 0, 0},
     {0, 0, 0},
     {0, 0, 0},
     {0, 0, 0},
     {0, 0, 0},
     {0, 0, 0},
     {0, 0, 0}},
    {{1, 2, 1},
     {1, 2, 1},
     {1, 2, 1},
     {1, 2, 1},
     {1, 2, 1},
     {1, 2, 1},
     {1, 2, 1},
     {1, 2, 1}},
    {{1, 2, 2},
     {1, 2, 3},
     {1, 2, 4},
     {1, 2, 6},
     {1, 2, 5},
     {1, 2, 4},
     {1, 2, 3},
     {1, 2, 2}}};

//  *******  **    *   *****   *******  ******   *     *  ******  *******  *******   *****   **    *   *****
//     *     * *   *  *           *     *     *  *     * *           *        *     *     *  * *   *  *
//     *     *  *  *   *****      *     ******   *     * *           *        *     *     *  *  *  *   *****
//     *     *   * *        *     *     *  *     *     * *           *        *     *     *  *   * *        *
//  *******  *    **   *****      *     *     *   *****   ******     *     *******   *****   *    **   *****

char board[8][8][2][4];
int board_info[8][8][3];

void main()
{
    int choice = 0;

    printf("\n1.New Game");
    printf("\n2.Load Game");
    printf("\n3.Save Game");
    printf("\n4.Exit");

Choice:

    printf("\n\tEnter Choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("clear");
        break;
    case 2:
        printf("Load");
        break;
    case 3:
        printf("Save");
        break;
    case 4:
        system("clear");
        printf("\n\n\tThank You!!!!!");
        break;
    default:
        goto Choice;
        break;
    }

    char board[8][8][2][4], col[2] = {'X', 'X'}, temp;
    int row[2] = {0, 0}, col_i[2] = {8, 8}, row_i[2] = {8, 8}, j;
Main:
    scanf("%c%c%d%c%c%d", &temp, &col[0], &row[0], &col[1], &col[1], &row[1]);
    printf("%c 1\n%d 2 \n%c 3 \n%d 4\n", col[0], row[0], col[1], row[1]);

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                strcpy(board[i][j][k], BOARD[i][j][k]);
            }
            for (int k = 0; k < 3; k++)
            {
                board_info[i][j][k] = BOARD_INFO[i][j][k];
            }
        }
    }

    // GIVING COLUMN INDEX

    for (int i = 0; i < 2; i++)
    {
        int letter[2] = {65, 97};
        for (int j = 0; j < 8; j++)
        {
            if (col[i] == letter[0] || col[i] == letter[1])
            {
                col_i[i] = j;
                break;
            }
            else if (j == 7)
            {
                printf("ERROR : INVALID COLUMN\n");
                goto Main;
            }
            letter[0]++;
            letter[1]++;
        }
    }

    // GIVING ROW INDEX

    for (int i = 0; i < 2; i++)
    {
        if (row[i] < 1 || row[i] > 8)
        {
            printf("ERROR : INVALID ROW\n");
            goto Main;
        }
        else
        {
            row_i[i] = row[i] - 1;
        }
    }

    printf("%d 1\n%d 2 \n%d 3 \n%d 4\n", col_i[0], row_i[0], col_i[1], row_i[1]);

    goto Main;

    // if (row_i[1] == row_i[0] || col_i[1] == col_i[0])
    // {
    //     printf("ERROR : INVALID MOVE\n");
    //     Chess_Board();
    // }
    // else if (row_i[1] > row_i[0])
    // {

    //     j = 1;
    //     for (int i = col_i[0]; i < col_i[1]; i++)
    //     {
    //         if (row_i[1] == row_i[0] + j && col_i[1] == col_i[0] + j)
    //         {
    //             if (board_info[row_i[1]][col_i[1]][1] == 2)
    //             {
    //                 Move();
    //             }
    //             else
    //             {
    //                 Move();
    //             }
    //         }
    //         else if (board_info[row_i[0] + j][col_i[0] + j][0] == 1)
    //         {
    //             printf("ERROR : INVALID MOVE\n");
    //             Chess_Board();
    //         }
    //         else if (i == col_i[1] - 1)
    //         {
    //             printf("ERROR : INVALID MOVE\n");
    //             Chess_Board();
    //         }
    //     }
    //     for (int i = col_i[0]; i > col_i[1]; i--)
    //     {
    //         if (row_i[1] == row_i[0] + j && col_i[1] == col_i[0] - j)
    //         {
    //             if (board_info[row_i[1]][col_i[1]][1] == 2)
    //             {
    //                 Move();
    //             }
    //             else
    //             {
    //                 Move();
    //             }
    //         }
    //         else if (board_info[row_i[0] + j][col_i[0] - j][0] == 1)
    //         {
    //             printf("ERROR : INVALID MOVE\n");
    //             Chess_Board();
    //         }
    //         else if (i == col_i[1] + 1)
    //         {
    //             printf("ERROR : INVALID MOVE\n");
    //             Chess_Board();
    //         }
    //     }
    // }
    // else if (row_i[1] < row_i[0])
    // {
    //     j = 1;
    //     for (int i = col_i[0]; i < col_i[1]; i++)
    //     {
    //         if (row_i[1] == row_i[0] - j && col_i[1] == col_i[0] + j)
    //         {
    //             if (board_info[row_i[1]][col_i[1]][1] == 2)
    //             {
    //                 Move();
    //             }
    //             else
    //             {
    //                 Move();
    //             }
    //         }
    //         else if (board_info[row_i[0] - j][col_i[0] + j][0] == 1)
    //         {
    //             printf("ERROR : INVALID MOVE\n");
    //             Chess_Board();
    //         }
    //         else if (i == col_i[1] - 1)
    //         {
    //             printf("ERROR : INVALID MOVE\n");
    //             Chess_Board();
    //         }
    //     }
    //     for (int i = col_i[0]; i > col_i[1]; i--)
    //     {
    //         if (row_i[1] == row_i[0] - j && col_i[1] == col_i[0] - j)
    //         {
    //             if (board_info[row_i[1]][col_i[1]][1] == 2)
    //             {
    //                 Move();
    //             }
    //             else
    //             {
    //                 Move();
    //             }
    //         }
    //         else if (board_info[row_i[0] - j][col_i[0] - j][0] == 1)
    //         {
    //             printf("ERROR : INVALID MOVE\n");
    //             Chess_Board();
    //         }
    //         else if (i == col_i[1] + 1)
    //         {
    //             printf("ERROR : INVALID MOVE\n");
    //             Chess_Board();
    //         }
    //     }
    // }

    //   printf("       A       B       C       D       E       F       G       H    \n    ------- ------- ------- ------- ------- ------- ------- ------- \n   |       |       |       |       |       |       |       |       |\n 8 |   %s   |   %s   |   %s   |   %s   |   %s   |   %s   |   %s   |   %s   | 8\n   |       |       |       |       |       |       |       |       |\n    ------- ------- ------- ------- ------- ------- ------- ------- \n   |       |       |       |       |       |       |       |       |\n 7 |   %s   |   %s   |   %s   |   %s   |   %s   |   %s   |   %s   |   %s   | 7\n   |       |       |       |       |       |       |       |       |\n    ------- ------- ------- ------- ------- ------- ------- ------- \n   |       |       |       |       |       |       |       |       |\n 6 |   %s   |   %s   |   %s   |   %s   |   %s   |   %s   |   %s   |   %s   | 6\n   |       |       |       |       |       |       |       |       |\n    ------- ------- ------- ------- ------- ------- ------- ------- \n   |       |       |       |       |       |       |       |       |\n 5 |   %s   |   %s   |   %s   |   %s   |   %s   |   %s   |   %s   |   %s   | 5\n   |       |       |       |       |       |       |       |       |\n    ------- ------- ------- ------- ------- ------- ------- ------- \n   |       |       |       |       |       |       |       |       |\n 4 |   %s   |   %s   |   %s   |   %s   |   %s   |   %s   |   %s   |   %s   | 4\n   |       |       |       |       |       |       |       |       |\n    ------- ------- ------- ------- ------- ------- ------- ------- \n   |       |       |       |       |       |       |       |       |\n 3 |   %s   |   %s   |   %s   |   %s   |   %s   |   %s   |   %s   |   %s   | 3\n   |       |       |       |       |       |       |       |       |\n    ------- ------- ------- ------- ------- ------- ------- ------- \n   |       |       |       |       |       |       |       |       |\n 2 |   %s   |   %s   |   %s   |   %s   |   %s   |   %s   |   %s   |   %s   | 2\n   |       |       |       |       |       |       |       |       |\n    ------- ------- ------- ------- ------- ------- ------- ------- \n   |       |       |       |       |       |       |       |       |\n 1 |   %s   |   %s   |   %s   |   %s   |   %s   |   %s   |   %s   |   %s   | 1\n   |       |       |       |       |       |       |       |       |\n    ------- ------- ------- ------- ------- ------- ------- ------- \n       A       B       C       D       E       F       G       H    \n", board[7][0][0], board[7][1][0], board[7][2][0], board[7][3][0], board[7][4][0], board[7][5][0], board[7][6][0], board[7][7][0], board[6][0][0], board[6][1][0], board[6][2][0], board[6][3][0], board[6][4][0], board[6][5][0], board[6][6][0], board[6][7][0], board[5][0][0], board[5][1][0], board[5][2][0], board[5][3][0], board[5][4][0], board[5][5][0], board[5][6][0], board[5][7][0], board[4][0][0], board[4][1][0], board[4][2][0], board[4][3][0], board[4][4][0], board[4][5][0], board[4][6][0], board[4][7][0], board[3][0][0], board[3][1][0], board[3][2][0], board[3][3][0], board[3][4][0], board[3][5][0], board[3][6][0], board[3][7][0], board[2][0][0], board[2][1][0], board[2][2][0], board[2][3][0], board[2][4][0], board[2][5][0], board[2][6][0], board[2][7][0], board[1][0][0], board[1][1][0], board[1][2][0], board[1][3][0], board[1][4][0], board[1][5][0], board[1][6][0], board[1][7][0], board[0][0][0], board[0][1][0], board[0][2][0], board[0][3][0], board[0][4][0], board[0][5][0], board[0][6][0], board[0][7][0]);

    // //     for (int i = 0; i < 8; i++)
    // //     {
    // //         for (int j = 0; j < 8; j++)
    // //         {
    // //             for (int k = 0; k < 3; k++)
    // //             {
    // //                 printf("%d",board_info[i][j][k]);
    // //             }
    // //             printf("\n");
    // //         }

    // //     }
}
