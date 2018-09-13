#include <stdio.h>
#include <vector>
#include <string>

class Board
{
public:
    Board();
    void Display_Board();
    void Count_Walls();
private:
    int rows;
    int cols;
    std::vector<std::string> str;
};
