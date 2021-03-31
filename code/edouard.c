#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "edouard.h"

#define LARGEURMAX 156
#define SCOREMAX 343
#define TRUE 1
#define FALSE 0

void init_dice(int dice[]) //fini
{
	
	for ( int i = 0; i < 3; ++i)
	{
		
		dice[i] = rand()%6+1;
										/// lancement des dés
		printf("Dé  %d = %d \n", i+1, dice[i]);

	}
}

int square(int nb) //fini
{
	int resultat;
	resultat=nb*nb;
	return resultat;	
}


int velute(int d1, int d2, int d3) //fini
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


int chouette(int d1, int d2, int d3) //fini
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
			
	return square(nb);
}

int partie_finie(int score[])
{
	return !(score[0]<SCOREMAX && score[1]<SCOREMAX && score[2]<SCOREMAX && score[3]<SCOREMAX && score[4]<SCOREMAX && score[5]<SCOREMAX);
	
}

int sequence_test(int d1,int d2,int d3) //finie
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

void test_suite(int dice[],int score[],int player,int nbplayer)  //fini
{
	int test_nbplayer_suite;
	if (sequence_test(dice[0], dice[1],dice[2])== TRUE)
	{
		printf("c'est une suite \n");
		char yes='O';
		char NO='N';
		char test;

		printf("\nquels joueur a tapé sur la table en criant \"Grelotte ça piquote ! \" en dernier ?\n ");
		printf("Il y a-t-il une égalité ? O/N\n ");
		scanf("%c",&test);
		if(test== yes)
		{
			int play_again=FALSE;
			do 
			{
				printf("\nquels joueur à criée \"Sans fin est la moisissure des bières bretonnes! \" en dernier\n ");
				
				scanf("%d",&test_nbplayer_suite);

				if (test_nbplayer_suite<=nbplayer && test_nbplayer_suite>0 )
				{
					play_again=TRUE;
					score[test_nbplayer_suite]-=10;
				}
				
			}while(play_again==FALSE);
			
			
			
		}
		else
		{
			scanf("%d",&test_nbplayer_suite);
			score[test_nbplayer_suite]-=10;					
		}
		
		//score[player]+=velute(dice[0], dice[1],dice[2]);
	}
}


void test_velute(int dice[],int score[],int player)//fini
{
	if (dice[0]+dice[1]==dice[2] || dice[2]+dice[1]==dice[0] || dice[2]+dice[0]==dice[1] )
	{
		printf("c'est une Velute \n");
		score[player]+=velute(dice[0], dice[1],dice[2]);
		
	}
}



void test_culdechouette(int dice[],int score[],int player) //fini
{
	if (dice[0] == dice[1] )
	{
		if (dice[0] == dice[2])
		{
			
				printf("c'est un cul de chouette\n"); 

				score[player]+=40+10*dice[0]; // X10 le score +40
			
		}
	}
}

void test_souflette(int dice[],int score[],int player,int nbplayer) //fini
{
	int test_4=FALSE;
	int test_2=FALSE;	
	int test_1=FALSE;
	int souflette=TRUE;
	int Chosen_player;
	if (dice[0] == 4 || dice[1] == 4 || dice[2] == 4 )
	{
		if (dice[0] == 2 || dice[1] == 2 || dice[2] == 2 )
		{
			if (dice[0] == 1 || dice[1] == 1 || dice[2] == 1 )
			{
				
				printf("c'est une Souflette\n");
				printf("Designez un joueur autre que vous en disant:'En garde ma mignone'\n");
				scanf("%d",&Chosen_player);
				if (Chosen_player<nbplayer && Chosen_player!=player )
				{
					
					for (int i = 0; i < 3; i++)
					{
						init_dice(dice);
						printf("\n\n");
						for (int j = 0; j < 3; j++)
						{
							
							if (dice[j]==4)
							{
								test_4=TRUE;
							}
							if (dice[j]==2)
							{
								test_2=TRUE;
							}
							
							if (dice[j]==1)
							{
								test_1=TRUE;
							}
						}
						if (test_1 && test_2 && test_4)
						{
							printf("Souflette reussi \nessai=%d\n",i+1);
							if (i==0)
							{
								score[player]-=50;
								score[Chosen_player]+=50;
							}
							if (i==1)
							{
								score[player]-=40;
								score[Chosen_player]+=40;
							}
							if (i==2)
							{
								score[player]-=30;
								score[Chosen_player]+=30;
							}
							break;       //condition remplie donc on quitte la boucle
						}
						
						
					}
					if ((test_1 && test_2 && test_4)==FALSE)
					{
						score[player]+=30;
						score[Chosen_player]-=30;
					}
					printf("score joueur %d = %d",player,score[Chosen_player]);
					






					
				}
				

			}
		}
	}
}

void test_chouette(int dice[],int score[],int player)//fini
{
		if (dice[0] == dice[1] || dice[1] == dice[2] || dice[2] == dice[0] )
	{
	printf("c'est une chouette\n");
		score[player]+=chouette(dice[0], dice[1], dice[1]);
		
		
	}
}


int ask_nb_player() // nombre de joueur   //fini
{
	int nb=0;
	do
	{
		printf("Combien de joueur dans cette partie?\n");
		scanf("%d", &nb);
	} while (nb<2 || nb>6);
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