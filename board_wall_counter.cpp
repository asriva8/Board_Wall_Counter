#include <iostream>
#include <stdio.h>
#include <vector>
#include "board_wall_counter.h"

Board::Board()
{

    std::cout<<"Enter the number of rows in the board\n";
    std::cin>>rows;
    while(rows<1)
    {
        std::cout<<"number of rows must be >= 1\n";
        std::cout<<"Enter the number of rows in the board\n";
        std::cin>>rows;
    }
    std::cout<<"Enter the number of columns in the board\n";
    std::cin>>cols;
    while(cols<1)
    {
        std::cout<<"number of cols must be >= 1\n";
        std::cout<<"Enter the number of cols in the board\n";
        std::cin>>cols;
    }
    std::string strng;
    getline(std::cin,strng); // This is done to remove a "\n" after getting input in n.
    for (int i=1; i<=rows; i++)
    {
        std::cout<<"input string "<<i<<"\n";
        getline(std::cin,strng);
        while(strng.size()!=cols)
        {
            std::cout<<"String size must be equal to "<<cols<<"\n";
            std::cout<<"input string "<<i<<"\n";
            getline(std::cin,strng);
        }
        str.push_back(strng);
    }

}


void Board::Display_Board()
{
    std::cout<<"the size of the board is "<<str.size()<<"\n";
    for(int i=0; i <str.size(); i++)
    {
        std::cout<<str[i]<<std::endl;

    }
}

void Board::Count_Walls()
{
    std::vector<int> coordinate;  //Stores x,y coordinate location
    std::vector<std::vector<int> > container;
    std::vector<std::vector<int> > new_board;
    std::vector<int> dummy;       // New board is filled with a dummy variable which has a value equal to -1.
    for (int i=0; i<cols; i++)
    {dummy.push_back(-1);}
    for (int i =0; i<rows; i++)
    {
        new_board.push_back(dummy);
    }
    int count = 0;
    for (int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(new_board[i][j]==-1)
            {
                if(str[i][j]=='x')
                {
                    coordinate.push_back(i);
                    coordinate.push_back(j);
                    container.push_back(coordinate);
                    coordinate.clear();
                    count++;
                    new_board[i][j]=count;
                }
                else
                {
                    new_board[i][j]=0;
                }
            }
            while (!container.empty())
            {
                int x = container.back()[0];
                int y = container.back()[1];
                container.pop_back();
                if(y>0) //check left
                {
                    if(new_board[x][y-1]==-1)
                    {
                        if(str[x][y-1]=='x')
                        {
                            coordinate.push_back(x);
                            coordinate.push_back(y-1);
                            container.push_back(coordinate);
                            coordinate.clear();
                            new_board[x][y-1]=count;
                        }
                        else
                        {
                            new_board[x][y-1]=0;
                        }

                    }

                }
                if (y<cols-1)  // check right
                {
                    if(new_board[x][y+1]==-1)
                    {
                        if(str[x][y+1]=='x')
                        {
                            coordinate.push_back(x);
                            coordinate.push_back(y+1);
                            container.push_back(coordinate);
                            coordinate.clear();
                            new_board[x][y+1]=count;
                        }
                        else
                        {
                            new_board[x][y+1]=0;
                        }
                    }

                }
                if (x>0)  //check up
                {
                    if(new_board[x-1][y]==-1)
                    {
                        if(str[x][y-1]=='x')
                        {
                            coordinate.push_back(x-1);
                            coordinate.push_back(y);
                            container.push_back(coordinate);
                            coordinate.clear();
                            new_board[x-1][y]=count;
                        }
                        else
                        {
                            new_board[x-1][y]=0;
                        }
                    }

                }
                if (x<rows-1)   //check down
                {
                    if(new_board[x+1][y]==-1)
                    {
                        if(str[x+1][y]=='x')
                        {
                            coordinate.push_back(x+1);
                            coordinate.push_back(y);
                            container.push_back(coordinate);
                            coordinate.clear();
                            new_board[x+1][y]=count;
                        }
                        else
                        {
                            new_board[x+1][y]=0;
                        }
                    }

                }

            }
        }
    }

    std::cout<<"Number of walls in the given board is: "<<count<<"\nThe board showing number of walls is below\n";
    for(int i=0; i <new_board.size(); i++)
    {
        for(int j=0; j<new_board[i].size(); j++)
        {
            std::cout<<new_board[i][j];
        }
        std::cout<<std::endl;

    }

}
