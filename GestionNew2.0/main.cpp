//
//  main.cpp
//  GestionNew
//
//  Created by Kevin on 19/06/2018.
//  Copyright © 2018 Kevin. All rights reserved.
//

#include <iostream>
#include "include/core/Jeu.hpp"

using namespace std;

void purge(){
    system("clear");
}

int main(int argc, const char * argv[])
{
    cout << "Smart Pointers and Serialisation by MOKS\n";
    cout << "\n### Création du jeu ###"<<endl<<endl;
    
    // Création d'un pointeur intelligent
    shared_ptr<Jeu> myGame(make_shared<Jeu>());
    
    // Chargement du fichier de sauvegarde du jeu
    cout << "Chargement des données \n";
   
    /*
    std::ifstream ifile("Save");
    boost::archive::text_iarchive iTextArchive(ifile);
    iTextArchive >> myGame;     // désérialisation dans d
    */
    myGame->MenuLoop();

    // Sauvegarde du l'objet jeu dans un fichier
    std::ofstream ofile("Save");
    boost::archive::text_oarchive oTextArchive(ofile);
    oTextArchive << myGame;    // sérialisation de d
 
    cout <<endl;
    return 0;
}
