#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LARGEURMAX 156
#define TRUE 1







int sequence_test(int d1,int d2,int d3)
{
	if (d3-d2== TRUE)
	{
		if (d2-d1== TRUE)
		{
			return TRUE;
		}
	}
	if (d2-d1== TRUE)
	{
		if (d1-d3== TRUE)
		{
			/* code */
			return TRUE;
		}
	}
	
	if (d1-d3== TRUE)
	{
		if (d3-d2== TRUE)
		{
			/* code */
			return TRUE;
		}
	}
	
	if (d2-d3== TRUE)
	{
		if (d3-d1== TRUE)
		{
			/* code */
			return TRUE;
		}
	}	
	
	if (d3-d1== TRUE)
	{
		if (d1-d2== TRUE)
		{
			/* code */
			return TRUE;
		}
	}

	if (d1-d2== TRUE)
	{
		if (d2-d3== TRUE)
		{
			/* code */
			return TRUE;
		}
	}
}








int ask_nb_player() // nombre de joueur
{
	int nb;
	printf("Combien de joueur dans cette partie?\n");
	scanf("%d", &nb);
	if (nb<2 || nb>6)
	{
		printf("veilllez saisir un nombre entre 2 et 6\n");
		ask_nb_player();
	}
	
 

 return nb;
	
}




int scoreboard (int nbplr, int show_score)
{
	int size_column = LARGEURMAX/nbplr;
	//printf("%d",size_column);
	int i;
	for (i = 0; i < nbplr; i++)
	{  	printf("	joueur %d	", i+1);
		for (int j = 0; j < size_column; j++)
		{
			
			if (j==size_column-1 )
			{
				if (i<nbplr-1)
				{
					printf("|");
				}
			}
			
		}
		
	}
	printf("\n");
	for (i = 0; i < nbplr; i++)

	{	
		for (int j = 0; j < size_column; j++)
		{
			
			
				
					printf("=");
				
				
				

			
			
		}
		
	}
	
	printf("\n");

	for (int k = 0; k < nbplr; k++)
	{
		printf("	   666		");
		for (int l = 0; l < size_column; l++)
		{
			
			if (l==size_column-1 )
			{
				if (k<nbplr-1)
				{
					printf("|");
				}
				
				

			}
		}
	}
	
	

	printf("\n");
}






int line_break(int linejump)
{
	for (int i = 0; i < linejump; i++)
	{
		printf("\n");
	}
	
}


int line ()
{
	int i;
	for (i = 0; i < LARGEURMAX; i++)
	{
		printf("=");
	}
	printf("\n");
	printf("%d",i);


}





















int logo()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("			   _____      _       _        _              _                      _   _ \n");
	printf("			  / ____|    | |     | |      | |            | |                    | | | |\n");
	printf("			 | |    _   _| |   __| | ___  | | __ _    ___| |__   ___  _   _  ___| |_| |_ ___\n");
	printf("			 | |   | | | | |  / _` |/ _ \\ | |/ _` |  / __| '_ \\ / _ \\| | | |/ _ \\ __| __/ _ \\\n");
	printf("			 | |___| |_| | | | (_| |  __/ | | (_| | | (__| | | | (_) | |_| |  __/ |_| ||  __/\n");
	printf("			  \\_____\\__,_|_|  \\__,_|\\___| |_|\\__,_|  \\___|_| |_|\\___/ \\__,_|\\___|\\__|\\__\\___|\n");
	printf("\n");
	printf("\n");
	printf("\n");
}