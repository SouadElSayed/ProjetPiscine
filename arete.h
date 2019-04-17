#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED
#include "Coords.h"
#include "sommet.h"
#include <string>
#include <iostream>
#include <sstream>


class Arete
{
    private:
        int m_id ;
        Sommet* m_som1;
        Sommet* m_som2;
        std::vector<float> m_poids;

    public:
        Arete();
        Arete(int id, Sommet* som1, Sommet* som2, std::vector<float> poids);
        void afficherEdges() const;
        ~Arete();
};


#endif // ARETE_H_INCLUDED
