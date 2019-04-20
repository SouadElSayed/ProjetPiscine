#include <iostream>
#include "Graphe.h"
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include "svgfile.h"

/**
 * \file          main.cpp
 * \author    Groupe 11
 * \date       20/04/19
 * \brief       Définit les modèles de voiture et leur particularités.
 *
 * \details    La classe /b main sert à appeler l'ensemble des fonctions utiles
 *                  afin de faire tourner notre algorithme + menu
 */

void Menu()
{
    int choixA=0;
    int choixB=0;
    do{

    std::system("cls");
    std::cout<<"Bonjour"<<std::endl
             <<"Bienvenue dans notre projet informatique\n" <<std::endl
             <<"Les bicyclettes de Triville" <<std::endl
             <<"Que souhaitez-vous faire?" <<std::endl
             <<"  [1] -  Lancer une topologie aléatoire" <<std::endl
             <<"  [2] -  Charger une topologie à partir du dossier source" <<std::endl
             <<"  [3] -  Quitter" <<std::endl;
    std::cin >> choixA;
    std::system("cls");
    while(choixA != 1 && choixA != 2 && choixA != 3 )
    {
        std::cout<<"Que souhaitez-vous faire?" <<std::endl
                 <<"  [1] -  Lancer une topologie aléatoire" <<std::endl
                 <<"  [2] -  Charger une topologie à partir du dossier source" <<std::endl
                 <<"  [3] -  Quitter" <<std::endl;
        std::cin >> choixA;
        std::system("cls");
    }

    if( choixA == 1)
    {


    }

    else if(choixA == 2)
    {
        std::cout<<" Fonctionnalitee en developpement!" <<std::endl
                 <<" Appuyez sur une touche pour revenir au menu" << std::endl;
        std::system("pause");
    }

    if ( choixB == 1)
    {

    }

    while(choixB !=3);
    }

    else
    {
        std::cout<<" Au revoir!" <<std::endl;
    }

    }while(choixA!=3);
}

*/

int main()
{
    Svgfile svgout;
    std::cout<<"Entrez le nom du fichier"<<std::endl;
    std::string ville;
    std::string poids;
    std::cin>>ville;
    std::cout<<"Entrez le nom du fichier poids"<<std::endl;
    std::cin>>poids;
    Graphe g{ville, poids};
    g.kruskal(g);
    g.afficher(svgout);
    g.afficherKruskal(svgout);
    g.bruteForceFacile();

    return 0;
}
