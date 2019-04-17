#include <string>
#include <iostream>
#include <sstream>
#include "arete.h"
#include "Coords.h"
#include "Sommet.h"


Arete::Arete(int id, Sommet* som1, Sommet* som2,std::vector<float> poids)
{
    m_id = id;
    m_som1 = som1;
    m_som2 = som2;
    m_poids = poids;
}
void Arete::afficherEdges() const
{
    std::cout<<"    "<<m_id;
    std::cout<<" : Sommet de depart -> Sommet d'arrivee : "<< m_som1->getId()<<" -> "<< m_som2->getId();
    std::cout << "  | Cout1,Cout2 :";

    for (int i=0; i<m_poids.size(); ++i)
    {
        std::cout<<" "<<m_poids[i];
    }
    std::cout << std::endl;
}
Arete::~Arete()
{

}
