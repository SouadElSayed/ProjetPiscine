#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED
#include <string>
#include <unordered_map>
#include "sommet.h"
#include "arete.h"
#include <iostream>
#include <vector>
#include <algorithm>

#define arete std::pair<int,int>


class Graphe
{
    private:
        std::vector <Arete*> edges ;    /// vecteur d'aretes
        std::vector<Sommet*> sommets ;/// vecteur de sommets
        std::vector<Arete*> ar_kruskal;
        int taille;
        //std::vector<std::pair<int,arete>> graphe; // graphe
        //std::vector<std::pair<int,arete>> arbre; // MST
        //int *pred;
        //int sommet; // nb de sommets
        /// Le réseau est constitué d'une collection de sommets
        //std::unordered_map<std::string,Sommet*> m_sommets;//stockée dans une map (clé=id du sommet, valeur= pointeur sur le sommet)

    public:
        Graphe(std::string fichier, std::string fichier_poids);
        void afficher(Svgfile& svgout) const;
        void afficherKruskal(Svgfile& svgout)const;
        //void AjouterArete(int u,int v,int w);//nb,Arete edge);
        //int find_set(int i);
        //void union_set(int u, int v);
        void kruskal(Graphe g);
        void triCout1();
        void triCout2();
        Graphe();
        //void insererArete(Arete* a);
        int tailleA() const ;
        //void afficher();
};



/*
class graphe
{
    public:
        ///constructeur qui charge le graphe en mémoire
        //format du fichier ordre/liste des sommets/taille/liste des arêtes
        graphe(std::string);
        ~graphe();
        void afficher() const;

    private:
        /// Le réseau est constitué d'une collection de sommets
        std::unordered_map<std::string,Sommet*> m_sommets;//stockée dans une map (clé=id du sommet, valeur= pointeur sur le sommet)
        /// Vecteur Aretes
        std::vector <Arete*> edges ;

};
*/

#endif // GRAPHE_H_INCLUDED
