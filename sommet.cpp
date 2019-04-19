#include <iostream>
#include <queue>
#include<unordered_map>
#include<unordered_set>
#include "sommet.h"
#include "Coords.h"
#include "svgfile.h"


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
void Sommet::dessiner(Svgfile& svgout)
{
    svgout.addDisk(m_x,m_y,20);
    svgout.addText(m_x,m_y,m_id,"white");
}
void Sommet::dessinerKruskal(Svgfile& svgout)
{
    svgout.addDisk(m_x+500,m_y,20);
    svgout.addText(m_x+500,m_y,m_id,"white");
}

Sommet::~Sommet()
{
    //dtor
}

