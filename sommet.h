#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "Coords.h"
#include "sommet.h"
#include "svgfile.h"
class Sommet
{
    private:
        /// Données spécifiques du sommet
        int m_id; // Identifiant
        int m_x;
        int m_y; // Coordonnees de la position du sommet

    public:
        ///constructeur qui reçoit en params les données du sommet
        Sommet(int id,int x,int y);
        void afficherData() const;
        void dessiner(Svgfile& svgout);
        void dessinerKruskal(Svgfile& svgout);
        int getId() const {return m_id;};
        int getX() const {return m_x;};
        int getY() const {return m_y;};

        ~Sommet();

};


#endif // SOMMET_H_INCLUDED
