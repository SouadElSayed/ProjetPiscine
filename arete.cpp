#include <string>
#include <iostream>
#include <sstream>
#include "arete.h"
#include "Coords.h"
#include "Sommet.h"


Arete::Arete(int id, Sommet* som1, Sommet* som2, std::vector<float> poids)
{
    m_id = id ;
    m_som1 = som1 ;
    m_som2 = som2 ;
    m_poids = poids ;
}

void Arete::afficher() const
{
    std::cout << "Id : " << m_id << "    Poids : " << this->getPoids()[0] << std::endl ;
}

void Arete::afficherEdges(Svgfile& svg) const
{
    svg.addLine(m_som1->getX(),m_som1->getY(),m_som2->getX(),m_som2->getY(),"black");
}

void Arete::afficherKruska(Svgfile& svg) const
{
    svg.addLine(m_som1->getX()+500,m_som1->getY(),m_som2->getX()+500,m_som2->getY(),"black");
}

Arete::~Arete()
{

}
