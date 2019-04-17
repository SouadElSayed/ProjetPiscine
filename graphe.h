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
        std::vector<Sommet*> sommets ;  /// vecteur de sommets

    public:
        Graphe(std::string fichier, std::string fichier_poids);
        void afficher() const;
        //void AjouterArete(int u,int v,int w);
        //int find_set(int i);
        //void union_set(int u, int v);
        void kruskal();
};

#endif // GRAPHE_H_INCLUDED
