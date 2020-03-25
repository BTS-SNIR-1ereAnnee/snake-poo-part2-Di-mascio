#include "Point.h"
#include "snake.h"
#include "Board.h"
#include <iostream>


using namespace std ;

snake::snake()
{
    for(int i = 0; i < longeur; i++)
    {
        serpent[i].setPoint(0,i);
    }
}


snake::snake(int x,int y)
{
    for(int i = 0; i < longeur; i++)
    {
        serpent[i].setPoint(x,i+y);
    }
}


void snake::affichSerpent()
{
    /**Parcours du tableau*/
    for(int i = 0; i < longeur; i++)
    {
        serpent[i].drawPoint(); /** utilisation de la méthode drawPoint*/
    }
}

void snake::move(int direction)
{
    for(int i = longeur; i > 0 ; i--)
    {
        serpent[i].erasePoint();
        serpent[i] = serpent[i-1];

    }

    if(direction == 1)
    {
        serpent[0].moveUp();
    }

    else if(direction == 2)
    {
        serpent[0].moveDown();
    }
    else if(direction == 3)
    {
        serpent[0].moveLeft();
    }
    else if(direction == 4)
    {
        serpent[0].moveRight();
    }

}

bool snake::checkColisionWithBoard()
{
    Board *b;
    b = Board::getInstance(); // on recup l'instance de board
    if (serpent[0].getX() == 0 || serpent[0].getX() == b->getXSize()-1) return TRUE;
    if (serpent[0].getY() == 0 || serpent[0].getY() == b->getYSize()-1) return TRUE;
    return FALSE;
}

bool snake::checkColisionWithSnake()
{
    for(int i = 1; i < longeur ; i++)
    {
        if(serpent[0]==serpent[i]) return TRUE;
    }
    return FALSE;
}