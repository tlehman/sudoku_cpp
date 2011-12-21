#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "grid.cpp"
#include "alphanum.cpp"
using namespace std;

int main()
{
    Grid sugrid;    // Instantiate the Grid
    char key;
    
    sugrid.init();  // Clear the Grid
    
    sugrid.print();
    
    do
    {
        key = getchar();
        fflush(stdin);
        if(islower(key))
        {
            key = toupper(key);
            sugrid.move(key);
            cin.clear();
        }
        else if(isnumber(key)) 
        {
            sugrid.put(key);
            sugrid.move(key);
            cin.clear();
        }
        else cin.clear();
    
    } while(key != 'Q');
    
    return 0;
}
