#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#define size 102

typedef char string[256];

//-----------------------------------------------------------------------------
//       InitializeCharMatrix
//       ---------------------
// General : Fills a sizexsize character matrix with a specified character.
//
// Parameters : 
//   cMatrix - The character matrix to fill (Out).
//   cFillChar - The character to fill the matrix with (In).
//
// Return Value : None.
//-----------------------------------------------------------------------------
void InitializeCharMatrix(char cMatrix[size][size], char cFillChar) {
    for (int nRow = 0; nRow < size; nRow++) {
        for (int nCol = 0; nCol < size; nCol++) {
            cMatrix[nRow][nCol] = cFillChar;
        }
    }
}

//-----------------------------------------------------------------------------
//       PrintMatrix
//       ------------
// General : Prints the given sizexsize character matrix.
//
// Parameters : 
//   cMatrix - The character matrix to print (In).
//
// Return Value : None.
//-----------------------------------------------------------------------------
void PrintMatrix(char cMatrix[size][size]) {
    for (int nRow = 0; nRow < size; nRow++) {
        for (int nCol = 0; nCol < size; nCol++) {
            printf("%c ", cMatrix[nRow][nCol]);
        }
        printf("\n");
    }
}

//-----------------------------------------------------------------------------
//       FillSafetyWall
//       ---------------
// General : Adds safety walls around the edges of the sizexsize board.
//
// Parameters : 
//   cBoard - The character board to modify (Out).
//
// Return Value : None.
//-----------------------------------------------------------------------------
void FillSafetyWall(char cBoard[size][size]) {
    for (int nIndex = 0; nIndex < size; nIndex++) {
        cBoard[nIndex][0] = '*';
        cBoard[0][nIndex] = '*';
        cBoard[nIndex][101] = '*';
        cBoard[101][nIndex] = '*';
    }
}

//-----------------------------------------------------------------------------
//       Walls
//       ------
// General : Allows the user to add walls to the board by specifying pairs 
//           of indexes.
//
// Parameters : 
//   cBoard - The character board to modify (Out).
//   pnCounter - Pointer to the wall counter (In/Out).
//
// Return Value : None.
//-----------------------------------------------------------------------------
void Walls(char cBoard[size][size], int* pnCounter) {
    int nRow, nCol;
    printf("Write me pairs of indexes. A wall will be created at each location obtained\n");
    printf("Enter row:\n");
    scanf("%d", &nRow);
    printf("Enter col:\n");
    scanf("%d", &nCol);
    while (nRow != 0 && nCol != 0) {
        cBoard[nRow][nCol] = '*';
        (*pnCounter)++;
        printf("Enter row:\n");
        scanf("%d", &nRow);
        printf("Enter col:\n");
        scanf("%d", &nCol);
    }
}

//-----------------------------------------------------------------------------
//       PutPointBack
//       -------------
// General : Restores a point on the board to '.'.
//
// Parameters : 
//   pnRow - Pointer to the row coordinate (In).
//   pnCol - Pointer to the column coordinate (In).
//   cBoard - The character board to modify (Out).
//
// Return Value : None.
//-----------------------------------------------------------------------------
void PutPointBack(int* pnRow, int* pnCol, char cBoard[size][size]) {
    cBoard[*pnRow][*pnCol] = '.';
}

//-----------------------------------------------------------------------------
//       B_Movement
//       -----------
// General : Moves the character 'B' on the board in a specified direction.
//
// Parameters : 
//   nDirection - The direction of movement (1: right, 2: left, 3: up, 4: down) (In).
//   pnRow - Pointer to the row coordinate of 'B' (In/Out).
//   pnCol - Pointer to the column coordinate of 'B' (In/Out).
//   cBoard - The character board to modify (Out).
//   pnPoints - Pointer to the points counter (In/Out).
//
// Return Value : None.
//-----------------------------------------------------------------------------
void B_Movement(int nDirection, int* pnRow, int* pnCol, char cBoard[size][size], int* pnPoints) {
    if (nDirection == 1 && cBoard[*pnRow][*pnCol + 1] != '*') {
        if (cBoard[*pnRow][*pnCol + 1] == '.') {
            (*pnPoints)--;
        }
        cBoard[*pnRow][*pnCol] = ' ';
        cBoard[*pnRow][++(*pnCol)] = 'B';
    }
    else if (nDirection == 2 && cBoard[*pnRow][*pnCol - 1] != '*') {
        if (cBoard[*pnRow][*pnCol - 1] == '.') {
            (*pnPoints)--;
        }
        cBoard[*pnRow][*pnCol] = ' ';
        cBoard[*pnRow][--(*pnCol)] = 'B';
    }
    else if (nDirection == 3 && cBoard[*pnRow - 1][*pnCol] != '*') {
        if (cBoard[*pnRow - 1][*pnCol] == '.') {
            (*pnPoints)--;
        }
        cBoard[*pnRow][*pnCol] = ' ';
        cBoard[--(*pnRow)][*pnCol] = 'B';
    }
    else if (nDirection == 4 && cBoard[*pnRow + 1][*pnCol] != '*') {
        if (cBoard[*pnRow + 1][*pnCol] == '.') {
            (*pnPoints)--;
        }
        cBoard[*pnRow][*pnCol] = ' ';
        cBoard[++(*pnRow)][*pnCol] = 'B';
    }
}
//-----------------------------------------------------------------------------
//       D_Movement
//       -----------
// General : Moves the character 'D' on the board towards 'B'.
//
// Parameters : 
//   pnBRow - Pointer to the row coordinate of 'B' (In).
//   pnBCol - Pointer to the column coordinate of 'B' (In).
//   pnDRow - Pointer to the row coordinate of 'D' (In/Out).
//   pnDCol - Pointer to the column coordinate of 'D' (In/Out).
//   cBoard - The character board to modify (Out).
//   pnFlag - Pointer to a flag indicating if 'D' should leave a '.' behind (In).
//
// Return Value : None.
//-----------------------------------------------------------------------------
void D_Movement(int* pnBRow, int* pnBCol, int* pnDRow, int* pnDCol, char cBoard[size][size], int* pnFlag) {
 
    int nColMove = 0;
    int nRowMove = 0;
    if ((*pnBRow - *pnDRow) > 0) {
        nRowMove = 1;
    }
    else if ((*pnBRow - *pnDRow) < 0) {
        nRowMove = -1;
    }

    if ((*pnBCol - *pnDCol) > 0) {
        nColMove = 1;
    }
    else if ((*pnBCol - *pnDCol) < 0) {
        nColMove = -1;
    }
    if (cBoard[*pnDRow+nRowMove][*pnDCol + nColMove] != '*')
    {
        if (*pnFlag) {
            cBoard[*pnDRow][*pnDCol] = '.';
        }
        else
        {
            cBoard[*pnDRow][*pnDCol] = ' ';
        }
        if (cBoard[*pnDRow + nRowMove][*pnDCol + nColMove] != '.')
        {
            *pnFlag = 0;
        }
        *pnDRow += nRowMove;
        *pnDCol += nColMove;
        cBoard[*pnDRow][*pnDCol] = 'D';
    }
}

//-----------------------------------------------------------------------------
//       HasBullyBeenCaught
//       -------------------
// General : Checks if 'B' and 'D' occupy the same position on the board.
//
// Parameters : 
//   pnBRow - Pointer to the row coordinate of 'B' (In).
//   pnBCol - Pointer to the column coordinate of 'B' (In).
//   pnDRow - Pointer to the row coordinate of 'D' (In).
//   pnDCol - Pointer to the column coordinate of 'D' (In).
//   cBoard - The character board (In).
//
// Return Value : 1 if 'B' has been caught by 'D', otherwise 0.
//-----------------------------------------------------------------------------
int HasBullyBeenCaught(int* pnBRow, int* pnBCol, int* pnDRow, int* pnDCol, char cBoard[size][size]) {
    if (cBoard[*pnBRow][*pnBCol] == cBoard[*pnDRow][*pnDCol]) {
        return 1;
    }
    return 0;
}

//-----------------------------------------------------------------------------
//       StartGame
//       ----------
// General : Initializes and starts the game of Bully and Dov, handles user input
//           for setting walls, and manages the movement of 'B' and 'D'.
//
// Parameters : None.
//
// Return Value : None.
//-----------------------------------------------------------------------------
void StartGame() {
    int nBRow, nBCol, nDRow, nDCol, nCounter = 0;
    char cBoard[size][size];
    InitializeCharMatrix(cBoard, '.');
    FillSafetyWall(cBoard);
    Walls(cBoard, &nCounter);

    int nPoints = (100 * 100) - nCounter;
    PrintMatrix(cBoard);

    printf("Enter starting position (row and col) for Bully:\n");
    scanf("%d", &nBRow);
    printf("Enter col:\n");
    scanf("%d", &nBCol);
    cBoard[nBRow][nBCol] = 'B';
    nPoints--;

    printf("Enter starting position (row and col) for the Dov:\n");
    scanf("%d", &nDRow);
    printf("Enter col:\n");
    scanf("%d", &nDCol);

    if (HasBullyBeenCaught(&nBRow, &nBCol, &nDRow, &nDCol, cBoard)) {
        printf("Bully lost\n");
        exit(1);
    }
    cBoard[nDRow][nDCol] = 'D';

    PrintMatrix(cBoard);
    int nFlag = 1;
    int nDirection;

    while (1) {
        printf("Enter direction for Bully (1: right, 2: left, 3: up, 4: down):\n");
        scanf("%d", &nDirection);

        B_Movement(nDirection, &nBRow, &nBCol, cBoard, &nPoints);
        if (nPoints == 0) {
            PrintMatrix(cBoard);
            printf("Bully won!\n");
            exit(1);
        }

        D_Movement(&nBRow, &nBCol, &nDRow, &nDCol, cBoard, &nFlag);

        if (HasBullyBeenCaught(&nBRow, &nBCol, &nDRow, &nDCol, cBoard)) {
            PrintMatrix(cBoard);
            printf("Bully lost\n");
            exit(1);
        }
        PrintMatrix(cBoard);
    }
}

//-----------------------------------------------------------------------------
//       Main
//       -----
// General : Entry point of the program, starts the game.
//
// Parameters : None.
//
// Return Value : 0.
//-----------------------------------------------------------------------------
int main() {
    StartGame();
    return 0;
}
