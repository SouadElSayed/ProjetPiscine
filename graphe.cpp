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

    int taille;
    int tmp;
    ifs >> taille;
    ifs2 >> taille;
    ifs2 >> tmp;

    int indarr;

    float cout1;
    float cout2;

    int idsom1;
    int idsom2;
    //std::vector<float> poids;

    for (int i=0; i<taille; ++i)
    {
        ifs >> indarr;
        ifs >> idsom1;
        ifs >> idsom2;

        ifs2 >> indarr;
        ifs2 >> cout1;
        ifs2 >> cout2;
        //poids.push_back(cout1);
        //poids.push_back(cout2);
        edges.push_back(new Arete{indarr,sommets[idsom1], sommets[idsom2], cout1, cout2});
        //cout1.clear();
        //cout2.clear();
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


void Graphe::afficher(Svgfile& svgout) const
{
   std::cout<<"graphe : " << std::endl << std::endl;
    std::cout<<"  ordre : "<< sommets.size() <<std::endl;
    std::cout<<"  sommet : " <<std::endl;

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

struct ordreCout1
{
    inline bool operator() (const Arete* cout1, const Arete* cout2)
    {
        return (cout1->getCout1()< cout2->getCout1());
    }
};

struct ordreCout2
{
    inline bool operator() (const Arete* c1, const Arete* c2)
    {
        return (c1->getCout2()< c2->getCout2());
    }
};

void Graphe::triCout1()
{
    std::sort(edges.begin(),edges.end(),ordreCout1());
}

void Graphe::triCout2()
{
    std::sort(edges.begin(),edges.end(), ordreCout2());
}


void Graphe::kruskal()
{
    Graphe g;
    g.triCout1();
    g.triCout2();
    for (auto ar : edges)
    {
         ar->afficher();
    }
}
