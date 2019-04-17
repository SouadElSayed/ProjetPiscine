#include <iostream>
#include <queue>
#include<unordered_map>
#include<unordered_set>
#include "sommet.h"
#include "Coords.h"


Sommet::Sommet(int id,int x,int y)
{
    m_id = id ;
    m_x = x ;
    m_y = y ;
}

void Sommet::afficherData() const
{
    std::cout<<"    "<<m_id<<" : "<<"(x,y)=("<<m_x<<","<<m_y<<")"<<std::endl;
}


Sommet::~Sommet()
{
    //dtor
}

