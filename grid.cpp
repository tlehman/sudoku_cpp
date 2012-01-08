/** Author: Tobi Lehman
   Created: January 2008
Dusted off: January 2012

    A Grid object represents a 9x9 sudoku grid, it has 9x9=81 cells, and a cursor, 
    which represents the current position in the grid.
    
 */
#include <iostream>
using namespace std;

class Grid
{
    private:
        int grid[9][9]; // Grid is a 81-celled matrix representing the sudoku workspace
        int cursor[2];  // Cursor is a set of ordered pairs representing the current location
    public:
        void print();           
        void init();
        int put(int v);
        void move(char direction);

        // sudoku game logic
        bool check_vert(int v);     // determines whether 
        bool check_horiz(int v);
        bool check_block(int v);
};

void Grid::print()
{
    system("sh -c clear");
    for(int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            if(grid[j][i] == 0)
            {
                if(cursor[0] == i && cursor[1] == j) cout << "-";
                else cout << "[";
                cout << " ";
                if(cursor[0] == i && cursor[1] == j) cout << "-";
                else cout << "]";
            }
            else
            {
                if(cursor[0] == i && cursor[1] == j) cout << "-";
                else cout << "[";
                cout << grid[j][i];
                if(cursor[0] == i && cursor[1] == j) cout << "-";
                else cout << "]";
            }
            
            if((j+1) % 3 == 0) cout << "  ";    // Separates the Columns into Groups of Three
            if(j == 8) cout << endl;            // Once j (horizontal iterator) is 9, newline
            if(j == 8 && (i+1) % 3 == 0) cout << endl; // Separates the Rows into Groups of Three
        }
    }
}

void Grid::init()
{
    for(int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            grid[j][i] = 0;     // Zero out the playing field, eliminate possible garbage
        }
    }
    cursor[0] = 0;             // Grid's Y coordinate
    cursor[1] = 0;             // Grid's X coordinate
}

void Grid::move(char direction)
{
    switch(direction)
    {
        case 'K':   // Move Cursor Up
            if(cursor[0] > 0)
            {
                --cursor[0];   // Decrement the Y Value (Move UP)
                print();
            }
            break;
        case 'J':   // Move Cursor Down
            if(cursor[0] < 8)
            {
                ++cursor[0];    // Increment the Y Value (Move DOWN)
                print();
            }
            break;
        case 'H':   // Move Cursor Left
            if(cursor[1] > 0)
            {
                --cursor[1];    // Decrement the X Value (Move LEFT)
                print();
            }
            break;
        case 'L':   // Move Cursor Right
            if(cursor[1] < 8)
            {
                ++cursor[1];    // Increment the X Value (Move RIGHT)
                print();
            }
            break;
        default:
            print();
            break;
        
    }
}

int Grid::put(int v)
{
    // ASCII offset
    if(v > 0) v -= 48;
    int o = grid[cursor[1]][cursor[0]];
    grid[cursor[1]][cursor[0]] = v;
    
    if(check_vert(v) || check_horiz(v) || check_block(v))
    {
        grid[cursor[1]][cursor[0]] = o; 
    	print();
    }
    else
    {
        print();
    }
    return 0;
}

/* check_vert returns true the value v doesn't appear in the vertical line 
   on which cursor resides */
bool Grid::check_vert(int v)
{
    bool r = false;
    int w = 0;
    for(int i = 0; i <= 8; ++i)
    {
	    if(grid[cursor[1]][i] == v) 
            ++w;
    }
    if(w > 1) r = true;
    else r = false;
    return r;
}

/* check_horiz returns true if the value v doesn't appear in the horizontal line 
   on which cursor resides */
bool Grid::check_horiz(int v)
{
    bool r = false;
    int w = 0;
    for(int i = 0; i <= 8; ++i)
    {
	if(grid[i][cursor[0]] == v) ++w;
    }
    if(w > 1) r = true;
    else r = false;
    return r;
}

/* check_block returns true if the value v can be set at the position specified in 
   cursor and then sets the value, it returns false if it is not a valid play */
bool Grid::check_block(int v)
{
    bool r = false;
    int w = 0;
    if(cursor[0] >= 0 && cursor[0] <= 2)        // Sections A,B,C
    {
        if(cursor[1] >= 0 && cursor[1] <= 2)      // A
        {
            for(int i = 0; i <= 2; ++i)
            {
                for(int j = 0; j <= 2; ++j)
                {
                    if(grid[j][i] == v) ++w;
                }
            }
        }
        else if(cursor[1] >= 3 && cursor[1] <= 5) // B
        {
            for(int i = 0; i <= 2; ++i)
            {
                for(int j = 3; j <= 5; ++j)
                {
                    if(grid[j][i] == v) ++w;
                }
            }            
        }
        else if(cursor[1] >= 6 && cursor[1] <= 8) // C
        {
            for(int i = 0; i <= 2; ++i)
            {
                for(int j = 6; j <= 8; ++j)
                {
                    if(grid[j][i] == v) ++w;
                }
            }
        }
    }
    else if(cursor[0] >= 3 && cursor[0] <= 5)   // Sections D,E,F
    {
        if(cursor[1] >= 0 && cursor[1] <= 2)      // D
        {
            for(int i = 3; i <= 5; ++i)
            {
                for(int j = 0; j <= 2; ++j)
                {
                    if(grid[j][i] == v) ++w;
                }
            }
        }
        else if(cursor[1] >= 3 && cursor[1] <= 5) // E
        {
            for(int i = 3; i <= 5; ++i)
            {
                for(int j = 3; j <= 5; ++j)
                {
                    if(grid[j][i] == v) ++w;
                }
            }            
        }
        else if(cursor[1] >= 6 && cursor[1] <= 8) // F
        {
            for(int i = 3; i <= 5; ++i)
            {
                for(int j = 6; j <= 8; ++j)
                {
                    if(grid[j][i] == v) ++w;
                }
            }
        }
    }
    else if(cursor[0] >= 6 && cursor[0] <= 8)   // Sections G,H,I
    {
        if(cursor[1] >= 0 && cursor[1] <= 2)      // G
        {
            for(int i = 6; i <= 8; ++i)
            {
                for(int j = 0; j <= 2; ++j)
                {
                    if(grid[j][i] == v) ++w;
                }
            }
        }
        else if(cursor[1] >= 3 && cursor[1] <= 5) // H
        {
            for(int i = 6; i <= 8; ++i)
            {
                for(int j = 3; j <= 5; ++j)
                {
                    if(grid[j][i] == v) ++w;
                }
            }            
        }
        else if(cursor[1] >= 6 && cursor[1] <= 8) // I
        {
            for(int i = 6; i <= 8; ++i)
            {
                for(int j = 6; j <= 8; ++j)
                {
                    if(grid[j][i] == v) ++w;
                }
            }
        }
    }
    if(w > 1) r = true;
    else r = false;
    return r;
}
