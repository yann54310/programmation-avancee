#include "Generation.hpp"

float** G ; //G est le tableau représentant le graphe pondéré
FILE * pFile; int taille = 5;
pFile=fopen( "room.txt" , "r");
if (pFile==NULL) perror ("Error opening file");
else {
    fprintf(pFile, "%d\n" , taille );
    for(int i=0; i<taille ; i++) {
        for(int j=0; j<taille ; j++)
            fprintf(pFile, "%f " , G[i][j]);
            fprintf(pfile, "\n");
        }
    fclose (pFile);
}


Room Generation::generateRoom(int lvl)
{
    

    if(lvl==0){

    }
    if(lvl%10==0){

    }
    if(lvl%5==0){

    }

    
}
Room Generation::generateEnemies(int number)
{

}

void Generation::clearRoom(Room salle)
{

}