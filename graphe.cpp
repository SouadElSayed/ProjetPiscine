#include <fstream>
#include <iostream>
#include "Graphe.h"
#include "sommet.h"
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include "svgfile.h"


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
    std::vector<float> poids;

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


void Graphe::afficher() const
{
    std::cout<<"graphe : " << std::endl << std::endl;
    std::cout<<"  ordre : "<< sommets.size() <<std::endl;
    std::cout<<"  sommets : " <<std::endl;


    for (auto i: sommets)
    {
        i->afficherData();
    }
    for (auto i: edges)
    {
        i->afficherEdges();
    }
}
/*
void Graphe::kruskal()
{
    int i, uRep, vRep;
    std::sort(g.begin(), g.end()); // on trie le graphe dans l'ordre croissant
    for (i=0; i<graphe.size(); i++)
    {
        uRep = find_set(graphe[i].second.first);
        vRep = find_set(graphe[i].second.second);
        if (uRep != vRep)
        {
            arbre.push_back(graphe[i]); // on l'ajoute a l'arbre deja existant
            union_set(uRep, vRep);      // on unit les 2 portions
        }
    }
}*/
