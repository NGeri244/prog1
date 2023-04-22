#include <iostream>
#include <cstring>
#define HEIGHT 10
#define WIDTH 10

using namespace std;
    char matrix[WIDTH+1][HEIGHT+1];
void clearTable() {
   memset(matrix, '.', sizeof(matrix));

}


void printTable() {
    // filling up the matrix

    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            if (i == 0 && j > 0) {
                matrix[i][j] = 'A' + j - 1;
            }
            else if (j == 0 && i > 0) {
                matrix[i][j] = '0' + i;
            }
            else if (i == 0 && j == 0) {
                matrix[i][j] = ' ';
            }
        }
    }

    // printing out the matrix
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}
void init(string ships) {

    for (int i = 0; i < ships.length(); i+=2) 
    {
        if (ships[i+1] == '1' && ships[i+2]== '0')
        {
            int oszlop = ships[i] - 'A' + 1;
            int sor = 10;
            matrix[sor][oszlop] = 'X';
            i++;
        }
        else {
            int oszlop = ships[i] - 'A' + 1;
            int sor = ships[i + 1] - '0';
            matrix[sor][oszlop] = 'X';
        }
    }

}

bool are_ships_destroyed(string bombs_pos) {
    for (int i = 0; i < bombs_pos.length(); i += 2)
    {
        if (bombs_pos[i + 1] == '1' && bombs_pos[i + 2] == '0')
        {
            int oszlop = bombs_pos[i] - 'A' + 1;
            int sor = 10;
            i++;
            if (matrix[sor][oszlop] == 'X')
            {
                matrix[sor][oszlop] = '*';
            }
        }
        else {
            int oszlop = bombs_pos[i] - 'A' + 1;
            int sor = bombs_pos[i + 1] - '0';
            matrix[sor][oszlop] = 'X';
            if (matrix[sor][oszlop] == 'X')
            {
                matrix[sor][oszlop] = '*';
            }
        }
    }
 
    for (int  i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j <HEIGHT; j++)
        {
            if (matrix[i][j] == 'X')
            {
                return false;
            }
        }
    }
    return true;
}
int main() {
    clearTable();
    init("A3A5A4C10B10A10F1E1");
    bool alld = are_ships_destroyed("B6B10E10C5");
    if (alld)
    {
        cout << "There are no remaining ships!"<<endl ;
    }
    else {
        cout << "Ships still up!" <<endl;
    }
    cout << endl;
    printTable();

   
    
}
