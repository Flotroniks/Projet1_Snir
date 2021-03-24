#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "edouard.h"
#include "phillipe.h"

int nb_player=0;
int score[6];


int main()
{
	srand( time( NULL ) );
	/* code */
	line();
	//logo();
	//line();
	//rules();
	
	nb_player=ask_nb_player();
	line_break(6);	
	scoreboard(nb_player, *score);


	return 0;
}