#include <iostream>
#include "Graphe.h"
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include "svgfile.h"
/*
void Graphe::AjouterArete(int u, int v, int w)//nb,Arete edge)
{
    //graphe.push_back(new Arete);
    graphe.push_back(make_pair(w, arete(u, v)));
}

    ///Svgfile svgout;

int Graphe::find_set(int i) /// trouver une portion de graphe
{
    // Si i est le predecesseur de lui meme
    if (i == pred[i])
        return i;
    else
        // Sinon si i n'est pas le predecesseur de lui meme
        // Alors i n'est pas la representation of his set,
        // On appelle recursivement Find sur son predecesseur
        return find_set(pred[i]);
}

void Graphe::union_set(int u, int v)    /// union des portions de graphe
{
    pred[u] = pred[v];
}

void Graphe::afficher()
{
    std::cout << "Arete |" << " Poids" << std::endl;
    for (int i = 0; i < arbre.size(); i++)
    { //                arete.sommet.depart               arete.sommet.arrivee               arete.poids
        std::cout << arbre[i].second.first << " - " << arbre[i].second.second << " : " << arbre[i].first << std::endl;
    }
}*/

    /// KRUSKAL   ||   MST = Minimum Spanning Tree (arbre couvrant de poids minimum)
    /// std::sort (pour trier dans l'ordre croissant les aretes)
    /// use the Union Find Algorithm pour verifier si les aretes vont former un cycle si on les ajoute dans l'actuel MST
    /// if yes discard it, else include it (union)

void kruskal(Graphe g);

int main()
{
    //Graphe g(6);
    Graphe g{"broadway.txt", "broadway_weights_0.txt"};
    //g.kruskal();
    g.afficher();
    return 0;
}

