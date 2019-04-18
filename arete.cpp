#include <string>
#include <iostream>
#include <sstream>
#include "arete.h"
#include "Coords.h"
#include "Sommet.h"


Arete::Arete(int id, Sommet* som1, Sommet* som2,float cout1, float cout2)//std::vector<float> poids)
{
    m_id = id;
    m_som1 = som1;
    m_som2 = som2;
    //m_poids = poids;
    m_cout1 = cout1;
    m_cout2 = cout2;
}

void Arete::afficher() const
{
    std::cout << "Id : " << m_id << "    Cout1 : " << m_cout1 << "   Cout 2 : " << m_cout2 << std::endl;
}


void Arete::afficherEdges(Svgfile& svg) const
{
    /*std::cout<<"    "<<m_id;
    std::cout<<"    "<< m_som1->getId()<<"  "<< m_som2->getId();

    for (int i=0; i<m_poids.size(); ++i)
    {
        std::cout<<"  "<<m_poids[i];
    }
    std::cout << std::endl;*/
    svg.addLine(m_som1->getX(),m_som1->getY(),m_som2->getX(),m_som2->getY(),"black");

}



Arete::~Arete()
{

}
