#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
	//line();
	//logo();
	//line();
	
	nb_player=ask_nb_player();
	//line_break(6);	
	printf("nombre de joueur = %d\n", nb_player);
	
	int dice[3]	;
	

	while ( partie_finie(score)==FALSE )
	{	
		
		//score[0]=45454;
		for (int i_for_player = 0; i_for_player < nb_player && partie_finie(score)==FALSE; i_for_player++)
		{

			//char next='t';
			printf("appuyer sur enter\n");
			//scanf("%s",&next);
			getchar();

			init_dice(dice);

			test_chouette(dice,score,i_for_player);
				
			test_souflette(dice);

			test_culdechouette(dice);

			test_suite(dice);

			test_velute( dice, score,i_for_player);

			printf("\nscore joueur%d =%d \n",i_for_player+1 ,score[i_for_player]);

			}
	}

//	scoreboard(nb_player, *score);


	return 0;
}