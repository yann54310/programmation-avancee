#include "Generation.hpp"

Generation Generation::generateRoom(int lvl)
{
    std::ifstream monFlux("assets/room.txt");

    char a;
    int taille,nbsalle,valeur;
    //146 taille d'une salle plus la ligne de séparation

    //on récupére la taille du fichier 
    monFlux.seekg(0, std::ios::end);  
    taille = monFlux.tellg();
    monFlux.seekg(0, std::ios::beg); 

    //On vérifie la taille du fichier et on calcul le nombre de salle
    if(taille%146!=0){
        std::cout << "ERREUR: Le fichier n'est pas de la bonne taille." << std::endl;
    }
    else{
        nbsalle = taille/146;
    }

    /* fonction aléatoir
        valeur = rand()%6 +1 pour valeur [1,6]
    */
    /*
    if(monFlux)  //On teste si tout est OK
    {
        if(lvl==0){
            while(a!='x'){

            }
            room[][];
        }
        else{
            if(lvl%10==0){

            }
            else{
                if(lvl%5==0){

                }
                else{

                }
            }
            
        }
        
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
    */
}
Generation Generation::generateEnemies(int number)
{

}

void Generation::clearRoom(Generation salle)
{

}