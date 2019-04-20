#include <iostream>
#include "Graphe.h"
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include "svgfile.h"


int main()
{
    Svgfile svgout;
    Graphe g{"cubetown.txt", "cubetown_weights_0.txt"};
    g.kruskal(g);
    g.afficher(svgout);
    g.afficherKruskal(svgout);
    g.ConvertisseurBin(33);
    //g.bruteForce();
    g.bruteForceFacile();
    for(int i=0;i<g.ConvertisseurBin(33).size(); ++i)
    {
        std::cout << (g.ConvertisseurBin(33))[i] << " ";
    }
    return 0;
}
