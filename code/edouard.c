#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LARGEURMAX 156
#define SCOREMAX 343
#define TRUE 1

int square(int nb)
{
	int resultat;
	resultat=nb*nb;
	return resultat;	
}
int suite()
{
	char yes='O';
	char NO='N';
	char test;

	printf("\nquels joueur a tapé sur la table en criant \"Grelotte ça piquote ! \" en dernier\n ");
	printf("Il y a-t-il un égalité  O/N\n ");
	scanf("%c",&test);
	if(test== yes)
	{
		printf(" pas cool le boeuf");
	}

}

int velute(int d1, int d2, int d3)
{
	int nb;

	if (d1+d2==d3)
	{
		nb =2*square(d3);
		return nb;
	}
	else
	{
		if (d3+d2==d1)
		{	
			nb =2*square(d1);
			return nb;
		}
		
		else
		{
			if (d3+d1==d2)
			{
				nb =2*square(d2);
				return nb;
			}	
		}
	}
	
}


int chouette(int d1, int d2, int d3)
{
	int nb;
	if (d1==d2)
	{
		nb=d1;
	}
	else
	{
		if (d2==d3)
		{
			nb=d2;
		}
		else
		{
			if (d3==d1)
			{
				nb=d1;
			}
			
		}
		
	}
	
	int squarenb;
	squarenb=nb*nb;	
	return squarenb;
}

int partie_finie(int score[])
{
	return !(score[0]<SCOREMAX && score[1]<SCOREMAX && score[2]<SCOREMAX && score[3]<SCOREMAX && score[4]<SCOREMAX && score[5]<SCOREMAX);
	
}

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


void test_velute(int dice[],int score[],int player)
{
	if (dice[0]+dice[1]==dice[2] || dice[2]+dice[1]==dice[0] || dice[2]+dice[0]==dice[1] )
	{
		printf("c'est une Velute \n");
		score[player]+=velute(dice[0], dice[1],dice[2]);
		
	}
}

void test_suite(int dice[])
{
	if (sequence_test(dice[0], dice[1],dice[2])== TRUE)
	{
		printf("c'est une suite \n");

	}
}

void test_culdechouette(int dice[])
{
	if (dice[0] == dice[1] )
	{
		if (dice[0] == dice[2])
		{
			
				printf("c'est un cul de chouette\n"); // X10 le score
			
		}
	}
}

void test_souflette(int dice[])
{
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
}

void test_chouette(int dice[],int score[],int player)
{
		if (dice[0] == dice[1] || dice[1] == dice[2] || dice[2] == dice[0] )
	{
	printf("c'est une chouette\n");
		score[player]+=chouette(dice[0],  dice[1], dice[1]);
		
		
	}
}

void init_dice(int dice[])
{
	
	for ( int i = 0; i < 3; ++i)
	{
		
		dice[i] = rand()%6+1;
										/// lancement des dés
		printf("Dé %d = %d \n", i+1, dice[i]);

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