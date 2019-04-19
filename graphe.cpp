#include <fstream>
#include <iostream>
#include "Graphe.h"
#include "sommet.h"
#include "arete.h"
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include "svgfile.h"

Graphe::Graphe()
{

}

Graphe::Graphe(std::string fichier, std::string fichier_poids)
{

    std::ifstream ifs{fichier};
        if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + fichier );
    std::ifstream ifs2{fichier_poids};
    if (!ifs2)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + fichier_poids );

    int ordre;
    ifs >> ordre;
    std::cout << ordre << std::endl;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    int id;
    int x,y ;
    //lecture des sommets
    for (int i=0; i<ordre; ++i)
    {
        ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>x; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>y; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        sommets.push_back(new Sommet{id,x,y});
    }

    //int taille;
    int tmp;
    ifs >> taille;
    std::cout << taille << std::endl;
    ifs2 >> taille;
    ifs2 >> tmp;

    int indarr;

    float cout1;
    float cout2;

    int idsom1;
    int idsom2;

    std::vector<float> poids ;

    for (int i=0; i<taille; ++i)
    {
        ifs >> indarr;
        ifs >> idsom1;
        ifs >> idsom2;

        ifs2 >> indarr;
        ifs2 >> cout1;
        ifs2 >> cout2;

        poids.push_back(cout1);
        poids.push_back(cout2);

        edges.push_back(new Arete{indarr,sommets[idsom1], sommets[idsom2], poids});
        poids.clear();
    }

    //if ( ifs.fail() )
        //throw std::runtime_error("Probleme lecture taille du graphe");

    /*std::string id_voisin;
    //lecture des aretes
    for (int i=0; i<taille; ++i)
    {
        //lecture des ids des deux extrémités
        ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 1");
        ifs>>id_voisin; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 2");
        //ajouter chaque extrémité à la liste des voisins de l'autre (graphe non orienté)
        (m_sommets.find(id))->second->ajouterVoisin((m_sommets.find(id_voisin))->second);
        (m_sommets.find(id_voisin))->second->ajouterVoisin((m_sommets.find(id))->second);//remove si graphe orienté
    }*/

}

/*void Graphe::insererArete(Arete* a)
{
    ar_kruskal.push_back(a);
}*/

int Graphe::tailleA() const
{
    return edges.size();
}

void Graphe::afficher(Svgfile& svgout) const
{
   std::cout<<"graphe : " << std::endl << std::endl;
    std::cout<<"  ordre : "<< sommets.size() <<std::endl;
    std::cout<<"  sommets : " <<std::endl;

    for (auto i: sommets)
    {
        i->afficherData();
        i->dessiner(svgout);
    }

    for (auto i:edges)
         {
          i->afficherEdges(svgout);
         }
}

bool trierAretes(Arete* a1, Arete* a2)
{
    return a1->getPoids().at(0) < a2->getPoids().at(0);
}

void Graphe::kruskal(Graphe g)
{
    std::sort(this->edges.begin(), this->edges.end(), trierAretes);
    for (auto ar : edges)
    {
         ar->afficher();
    }
    //std::vector<Arete*> ar_kruskal;
    int connexe = g.tailleA();
    int tab[connexe];
    for (int i=0; i<connexe; i++)
    {
        tab[i]=i;
    }
    for (int i=0; i<connexe; i++)
    {
        Sommet* som1=edges[i]->getSom1();
        Sommet* som2=edges[i]->getSom2();
        if (tab[som1->getId()] != tab[som2->getId()])
        {
            ar_kruskal.push_back(edges[i]);
            for (int j=0; j<connexe; j++)
            {
                if (tab[j]==tab[som1->getId()])
                {
                    if (j!=som1->getId())
                    {
                        tab[j]=tab[som2->getId()];

                    }
                }
            }

                tab[som1->getId()]=tab[som2->getId()];

        }
    }

    std::cout << std::endl;

    for (auto b : ar_kruskal)
    {
        b->afficher();
    }



}



void Graphe::afficherKruskal(Svgfile& svgout) const
{
    for (auto i: sommets)
    {
        i->afficherData();
        i->dessinerKruskal(svgout);
    }

    //std::vector<Arete*> ar_kruskal;
    for (auto i: ar_kruskal)
         {
          i->afficherKruska(svgout);
         }
}




