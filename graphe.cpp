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
    return a1->getPoids().at(0) < a2->getPoids().at(0);     /// Mettre 1 a la place de 0 si on veut l'arbre couvrant en fct du cout 2
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

std::vector<bool> Graphe::ConvertisseurBin(int n)
{
    int t[20];
    int i=0;
    int ordre=edges.size()-1;       // ordre = nb d'aretes -1

    std::vector<bool> convert(edges.size(),0);
    do
    {
        t[i]=n%2;
        n=n/2;
        i++;
    }
    while(n!=0);

    for(int j=0;j<=i-1;j++)
        {
                convert[ordre]=t[j];
                ordre--;
        }
    return convert;
}

void Graphe::bruteForce() const
{
    std::bitset<12> nb_bits;
    std::vector<std::bitset<12>> domine ;       // pas optimales
    std::vector<std::bitset<25>> non_domine ;   // optimales
    for (int i=0; i<pow(2,taille); i++)
    {
        std::cout << "rania" << std::endl;
        nb_bits=i;
        if (nb_bits.count()==(sommets.size()-1))
        {
            std::cout << nb_bits << std::endl;
            domine.push_back(nb_bits);
            std::cout << "sol :" << std::endl;
            for(auto bit : domine)
                std::cout << bit;
            std::cout << std::endl;
        }
    }

    std::vector<Arete*> ccc ;
    std::vector<std::vector<Arete*>> compo_connexes;
    int a = pow(2,taille);
    int tab[a];
    for (int i=0; i<domine.size() ; i++)
    {
        for (int j=0; j<nb_bits.size(); j++)
        {
            if (domine[i].test(j)==1)
            {
                int cpt=0;
                for (auto ar : edges)
                {
                    if (cpt == tab[edges.size()-j-1])
                    {
                        ccc.push_back(ar);
                    }
                    cpt = cpt + 1;
                }
            }
        }
        compo_connexes.push_back(ccc);
        for (auto i: ccc)
        {
            std::cout << i << std::endl;
        }
        ccc.clear();

    }

}

void Graphe::bruteForceFacile(){
    int cpt=0;
    std::vector<bool> tmp(taille,false);
    for(int j=sommets.size()-1;j<taille;j++)
        {
        for(int i=0;i<j;i++){
            tmp[i]=true;
        }
        std::sort(tmp.begin(),tmp.end());
        do
        {
            cpt ++;
            for(auto bit :tmp)
            std::cout << bit;
            std::cout << cpt << std::endl;
        }
        while(std::next_permutation(tmp.begin(),tmp.end()));
    }
}





