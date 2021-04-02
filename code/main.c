//autEUR VANDECASTEELE Florian et TANGUY Gwendal
//mini ProjetN°1  de 1ER ANNEE DE SNIR 



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "edouard.h"
#include "phillipe.h"


#define TRUE 1
#define FALSE 0
#define SCOREMAX 343
int nb_player=0;
int score[6];


int main()
{
	srand( time( NULL ) );

	/* code */
	line();
    logo();
	line();
	
	nb_player=ask_nb_player();
	line_break(6);	
	printf("nombre de joueur = %d\n", nb_player);
	
	int dice[3]	;  
	

	while ( partie_finie(score)==FALSE )			//tant que le score d'un des joueur est est inferieur a 343 on continue
	{	
		
		
		for (int i_for_player = 0; i_for_player < nb_player && partie_finie(score)==FALSE; i_for_player++) 
		{
			line ();
			printf("\nappuyer sur entree\n");
			
			getchar();														// force les joueur a appuyer sur entree
			printf("\n\n\n");
			init_dice(dice);   												//initie 3 valeur aleatoire, les stock et les affiche

			test_chouette(dice,score,i_for_player);  						// verifie si c'est une chouette et ajoute score adequat
				
			test_souflette(dice, score, i_for_player, nb_player);			// verifie si c'est une souflette et ajoute score adequat

			test_culdechouette(dice, score,i_for_player);					// verifie si c'est un cul de chouette et ajoute score adequat

			test_suite(dice, score, i_for_player, nb_player);				// verifie si c'est une suite et ajoute score adequat

			test_velute( dice, score,i_for_player);    						// verifie si c'est une velute et ajoute score adequat
			
			test_score_negatif(score, i_for_player);   						// verifie si le score du joueur est negatif

			printf("\nscore joueur%d =%d \n",i_for_player+1 ,score[i_for_player]);//affiche  le score du joueur en cours  

			

			}
	}
line_break(2);
scoreboard(nb_player, score);


	return 0;
}