//autEUR VANDECASTEELE Florian et TANGUY Gwendal
//mini ProjetN°1  de 1ER ANNEE DE SNIR 

#include <stdio.h>




int testf();
int line ();

int ask_nb_player(); // demande le nombre de joueur
int logo();//logo
int line_break(int);
int sequence_test(int,int,int);
int scoreboard(int,int score[]);
int launch_dice(int);
int chouette(int, int ,int);
int velute(int d1, int d2, int d3);
int suite();
void init_dice(int[]);
void test_chouette(int [],int [],int );
void test_souflette(int dice[],int score[],int player,int nbplayer);
void test_culdechouette(int dice[],int score[],int player);
void test_suite(int dice[],int score[],int player,int nbplayer);
void test_velute(int dice[],int score[],int player);
int partie_finie(int score[]);
int test_score_negatif(int score[], int i_for_player);