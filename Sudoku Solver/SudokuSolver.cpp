#include <iostream>
#include <vector>

using namespace std;


void printSudoku(int arr[9][9]) //Prints the sudoku.
{
    cout << "-------------------------" << endl;

    for (int r= 0; r<9; r++){ //Prints the sudoku
        for (int c = 0; c<9; c++){ 
            cout << arr[r][c] << " "; //Prints the number
    
        }
    cout << endl; 
    }

    cout << "-------------------------" << endl;

}

bool canPlace(int arr[9][9], int row, int col,int n) //Checks if the number can be placed in the sudoku
{
    if(arr[row][col]!= 0) return false; //If the number is not 0, it cannot be placed
    bool status = true; //Status is true
    int gridX = (col / 3) * 3; //Finds the X grid
    int gridY = (row / 3) *3; //Finds the Y grid
    for(int i=0;i<9;i++) //Checks the row
    {
        if(arr[row][i]== n) {status = false; break;} //If the number is in the row, it cannot be placed
        if(arr[i][col]== n) {status = false; break;} //If the number is in the column, it cannot be placed
        if(arr[gridY + i / 3][gridX + i % 3]== n) {status = false; break;} //If the number is in the grid, it cannot be placed

        return false; //If the number is in the row, column, or grid, it cannot be placed
    }
}

vector<int> findPlaceable(int arr[9][9], int row, int col) //Finds the placeable numbers
{
    vector<int> cps = {}; //Creates a vector
    for (int i = 1; i <= 9; i++) // Checks numers 1-9
    {
        if(canPlace(arr,row,col,i)) //If the number can be placed, it is added to the vector
            cps.push_back(i); //Adds the number to the vector
    }
    return cps;
}

void copyArray(int arr[9][9], int arrCopy[9][9])
{
    for(int y= 0; y<9;y++)
        for(int x= 0; x<9;x++)
            arrCopy[y][x] = arr[y][x];
}

bool solveSudoku(int arr[9][9], int row, int col)
{
    if(row > 8 ) return true;

    vector<int> placeables = findPlaceable(arr,row,col);

    if (placeables.size() == 0) return false;

    bool status = false;

    for(int i = 0; i < placeables.size(); i++)
    {
        int n = placeables[i];
    }


    return status;
}



int main()
{
    int board[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    

printSudoku(board);


    return 0;
}