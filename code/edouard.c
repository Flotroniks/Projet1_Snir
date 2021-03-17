#include <stdio.h>
#include <stdlib.h>
#include <time.h>




int testf()
{
	
	printf("test 123456789\n");

}
int logo()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("		   _____      _       _        _              _                      _   _ \n");
	printf("		  / ____|    | |     | |      | |            | |                    | | | |\n");
	printf("		 | |    _   _| |   __| | ___  | | __ _    ___| |__   ___  _   _  ___| |_| |_ ___\n");
	printf("		 | |   | | | | |  / _` |/ _ \\ | |/ _` |  / __| '_ \\ / _ \\| | | |/ _ \\ __| __/ _ \\\n");
	printf("		 | |___| |_| | | | (_| |  __/ | | (_| | | (__| | | | (_) | |_| |  __/ |_| ||  __/\n");
	printf("		  \\_____\\__,_|_|  \\__,_|\\___| |_|\\__,_|  \\___|_| |_|\\___/ \\__,_|\\___|\\__|\\__\\___|\n");
	printf("\n");
	printf("\n");
	printf("\n");
}



int alea_dice()  //nombre aleatoire entre 1 et 6
{
	
	int nb = rand()%6+1;
	return nb;
}


int nb_player() // nombre de joueur
{
	
}