// Sudoku Solver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

class Solver
{
public:
    // member variable that holds the board
    int board[9][9] = {
        {7, 2, 3, 0, 0, 0, 1, 5, 9},
        {6, 0, 0, 3, 0, 2, 0, 0, 8},
        {8, 0, 0, 0, 1, 0, 0, 0, 2},
        {0, 7, 0, 6, 5, 4, 0, 2, 0},
        {0, 0, 4, 2, 0, 7, 3, 0, 0},
        {0, 5, 0, 9, 3, 1, 0, 4, 0},
        {5, 0, 0, 0, 7, 0, 0, 0, 3},
        {4, 0, 0, 1, 0, 3, 0, 0, 6},
        {9, 3, 2, 0, 0, 0, 7, 1, 4}
    };

public:
    // Solves for a grid square
    void solveGridSquare(int row, int column)
    {
        // If the grid square is already populated then we don't need to solve for it.
        if (board[row][column] != 0)
        {
            return;
        }

        // Notes is all of the possibilities for that square
        vector<int> notes = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        // inRow, column, and box are all the numbers in those items
        vector<int> inRow = getRow(row);
        vector<int> inColumn = getColumn(column);
        vector<int> inBox = getBox(row, column);
        vector<int>::iterator it;

        // removing anything from the notes that's in the row
        for (int i = 0; i < notes.size(); i++)
        {
            it = notes.end();
            for (int x = 0; x < inRow.size(); x++)
            {
                if (notes[i] == inRow[x])
                {
                    it = notes.begin() + i;
                }
            }

            if (it != notes.end())
            {
                notes.erase(it);
                i -= 1;
            }
        }


        // removing anything from the notes that's in the column
        for (int i = 0; i < notes.size(); i++)
        {
            it = notes.end();
            for (int x = 0; x < inColumn.size(); x++)
            {
                if (notes[i] == inColumn[x])
                {
                    it = notes.begin() + i;
                }
            }

            if (it != notes.end())
            {
                notes.erase(it);
                i -= 1;
            }
        }


        // removing anything from the notes that's in the box
        for (int i = 0; i < notes.size(); i++)
        {
            it = notes.end();
            for (int x = 0; x < inBox.size(); x++)
            {
                if (notes[i] == inBox[x])
                {
                    it = notes.begin() + i;
                }
            }

            if (it != notes.end())
            {
                notes.erase(it);
                i -= 1;
            }
        }
        
        // If there is only one possibility then we know that's the answer.
        if (notes.size() == 1)
        {
            updateSquare(row, column, notes[0]);
        }
       
    }

    // Getting all the current numbers in the row
    vector<int> getRow(int rowNum)
    {
        vector<int> row;
        for (int i = 0; i < 9; i++)
        {
            if (board[rowNum][i] != 0) 
            {
                row.push_back(board[rowNum][i]);
            }
        }

        return row;
    }

    // getting all the current numbers in the column
    vector<int> getColumn(int columnNum)
    {
        vector<int> column;
        for (int i = 0; i < 9; i++)
        {
            if (board[i][columnNum] != 0)
            {
                column.push_back(board[i][columnNum]);
            }
        }

        return column;
    }

    // getting all the current numbers in the box
    vector<int> getBox(int rowNum, int columnNum)
    {
        vector<int> box;
        int rowLow = 0;
        int rowHigh = 0;
        int columnLow = 0;
        int columnHigh = 0;

        // determining which box based on the row and column number
        if (rowNum < 3)
        {
            rowLow = 0;
            rowHigh = 3;
        }
        else if (rowNum >= 3 && rowNum < 6)
        {
            rowLow = 3;
            rowHigh = 6;
        }
        else
        {
            rowLow = 6;
            rowHigh = 9;
        }

        if (columnNum < 3)
        {
            columnLow = 0;
            columnHigh = 3;
        }
        else if (columnNum >= 3 && columnNum < 6)
        {
            columnLow = 3;
            columnHigh = 6;
        }
        else
        {
            columnLow = 6;
            columnHigh = 9;
        }

        // putting the items in the vector that are in that box
        for (int row = rowLow; row < rowHigh; row++)
        {
            for (int column = columnLow; column < columnHigh; column++)
            {
                if (board[row][column] != 0)
                {
                    box.push_back(board[row][column]);
                }
            }
        }

        return box;
    }

    // Reassigns the correct number to the grid sqare
    void updateSquare(int rowNum, int columnNum, int answer)
    {
        board[rowNum][columnNum] = answer;
        // cout << "updated row : " << rowNum << " column : " << columnNum << " with number : " << answer << endl;
    }
    
    // displays the board
    void displayBoard()
    {
        for (int row = 0; row < 9; row++)
        {
            for (int column = 0; column < 9; column++)
            {
                string display;
                if (board[row][column] == 0)
                {
                    display = " ";

                }
                else
                {
                    display = to_string(board[row][column]);

                }

                if (column == 2 or column == 5)
                {
                    cout << display << "   |   ";
                }
                else
                {
                    cout << display << "   ";
                }
            }
            if (row == 2 or row == 5)
            {
                cout << endl;
                cout << "------------+---------------+------------";
            }
            cout << endl << endl;
        }
    }
   
    // determines if the puzzle has been solved
    bool solved()
    {
        for (int row = 0; row < 9; row++)
        {
            for (int column = 0; column < 9; column++)
            {
                // if there are any 0's at all then the puzzle isn't solved
                if (board[row][column] == 0)
                {
                    return false;
                }
            }
        }
        return true;
    }
};




int main()
{
    Solver solver;
    
    solver.displayBoard();

    // While the puzzle isn't solved it will continue to loop through every unsolved grid square and follow the same process
    while (solver.solved() == false)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int column = 0; column < 9; column++)
            {
                solver.solveGridSquare(row, column);
            }
        }
    }

    // Prints a message and the solved board when it is solved.
    cout << "solved board!" << endl;
    solver.displayBoard();

}