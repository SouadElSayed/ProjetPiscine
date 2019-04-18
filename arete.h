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
        float m_cout1;
        float m_cout2;
        //std::vector<float> m_poids;

    public:
        Arete();
        Arete(int id, Sommet* som1, Sommet* som2, float cout1, float cout2);//std::vector<float> poids);
        void afficherEdges(Svgfile &svg) const;
        void afficher() const;
        ~Arete();
        int getId() const {return m_id;};
        float getCout1() const {return m_cout1;};
        float getCout2() const {return m_cout2;};

};


#endif // ARETE_H_INCLUDED
