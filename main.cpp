#include <iostream>
#include "Graphe.h"
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include "svgfile.h"


    /// KRUSKAL   ||   MST = Minimum Spanning Tree (arbre couvrant de poids minimum)
    /// std::sort (pour trier dans l'ordre croissant les aretes)
    /// use the Union Find Algorithm pour verifier si les aretes vont former un cycle si on les ajoute dans l'actuel MST
    /// if yes discard it, else include it (union)


//void kruskal(Graphe g);

int main()
{
    Svgfile svgout;
    Graphe g{"cubetown.txt", "cubetown_weights_0.txt"};
    g.kruskal(g);
    g.afficher(svgout);

    g.afficherKruskal(svgout);
    return 0;
}

