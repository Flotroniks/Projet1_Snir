#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "edouard.h"
#include "phillipe.h"


#define TRUE 1
int nb_player=0;
int score[6];


int main()
{
	srand( time( NULL ) );
	/* code */
	//line();
	//logo();
	//line();

	
	//nb_player=ask_nb_player();
	//line_break(6);	


	int dice[3]	;
	
	for ( int i = 0; i < 3; ++i)
	{
		dice[i] = rand()%6+1;
										/// lancement des dés
		printf("Dé %d = %d \n", i+1, dice[i]);

	}


	if (dice[0] == dice[1] || dice[1] == dice[2] || dice[2] == dice[0] )
	{
		printf("c'est une chouette\n");
	}
	


	if (dice[0] == 4 || dice[1] == 4 || dice[2] == 4 )
	{
		if (dice[0] == 2 || dice[1] == 2 || dice[2] == 2 )
		{
			if (dice[0] == 1 || dice[1] == 1 || dice[2] == 1 )
			{
				
				printf("c'est une Souflette\n");
			}
		}
	}

	if (dice[0] == dice[1] )
	{
		if (dice[0] == dice[2])
		{
			
				
				printf("c'est un cul de chouette\n"); // X10 le score
			
		}
	}
	if (sequence_test(dice[0], dice[1],dice[2])== TRUE)
	{
		printf("c'est une suite \n");
	}

	if (dice[0]+dice[1]==dice[2] || dice[2]+dice[1]==dice[0] || dice[2]+dice[0]==dice[1] )
	{
		printf("c'est une Velute \n");
	}







//	scoreboard(nb_player, *score);


	return 0;
}