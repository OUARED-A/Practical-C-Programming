#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define n 5

typedef struct maillon {
  int t[n] ;
  int tete,queue ;

}file ;



void creer_file(file *f){

  f->tete=-1 ;
  f->queue=0 ;


}
bool file_pleine(file f){
   return (f.queue==-1);
}
bool file_vide(file f){
   return (f.tete==-1);
}
void enfiler(file *f,int e){
   if(!file_pleine(*f)){
   if(f->tete==-1) f->tete=0 ;
   f->t[f->queue]=e ;
   f->queue = (f->queue+1)%n ;
   if(f->queue==f->tete) f->queue=-1 ;

   } else printf(" \n\n    ERROR LA FILE EST PLEINE !!!!!!!!!!!!\n\n");
}
void defiler(file *f){
  if(!file_vide(*f)){
    if(f->queue==-1) f->queue =f->tete ;
    f->tete = (f->tete+1)%n ;
    if(f->tete == f->queue ) { f->tete=-1 ; f->queue =0 ;}
  } else printf(" \n\n    ERROR LA FILE EST VIDE !!!!!!!!!!!!\n\n");
}


void afficher(file f){
  if(!file_vide(f)){
  printf("\n\n              ");

  int i,j ;
  i = f.tete ;
  j = f.queue ;
  if(i<j)
    while(i<=j-1){
        printf(" %d | ",f.t[i]);
        i++ ;
    }
  else
        if(i>j){
            if(j==-1) do{
                         printf(" %d | ",f.t[i]);
                         i= (i+1 )% n ;
                        }while( i != f.tete);

            else  while((i%n) != j){
                printf(" %d | ",f.t[i]);
                i = (i+1) %n ;
            }
        }
  } else printf(" \n\n    ERROR LA FILE EST VIDE !!!!!!!!!!!!\n\n");


}

int menu (){

    printf ( "\n \n \n \n") ;
    printf ("                       1- CREER FILE  \n\n");
    printf ("                       2- ENFILER \n\n") ;
    printf ("                       3- DEFILER \n\n" );
    printf ("                       4- TEST PLEINE\n\n") ;
    printf ("                       5- TEST VIDE \n\n" );
    printf ("                       6- AFFICHER \n\n" );
    printf ("                       7- QUITTER \n\n" );
    printf ( "\n \n \n \n" );
    printf ("      Entrer le choix que vous voulez effectuer : ");

     int choix ;
     scanf("%d",&choix);
     system("cls");

     return choix ;
}



int main()
{
    int d,val,i,choix;
    file f ;
    creer_file(&f);
   d : choix = menu() ;
    switch (choix){
    case 1 :  creer_file(&f);
              printf(" Entrer le nombre des  element que voulez empiler :  ") ;
              scanf("%d",&d);
              for(i=1;i<=d;i++) {
                printf(" Entrer la %d  valeur :  ",i) ;
                scanf("%d",&val);
                enfiler(&f,val);
              }
              printf("\n\n\n") ;
                system("PAUSE");
    break ;
    case 2 : printf(" Entrer la   valeur :  ") ;
             scanf("%d",&val);
             enfiler(&f,val) ;
             printf("\n\n\n") ;
                system("PAUSE");
                break ;
    case 3 :
             defiler(&f);
             printf("\n\n\n") ;
                system("PAUSE");
    break ;
    case 4 :  if(file_pleine(f)==true) printf(" \n\n   LA PILE EST PLEINE !!!!! \n\n") ;
              else printf(" \n\n    LA PILE N EST PAS PLEINE !!!!! \n\n") ;
              printf("\n\n\n") ;
                system("PAUSE");
              break ;
    case 5 : if(file_vide(f)==true) printf(" \n\n LA PILE EST VIDE !!!!! \n\n ") ;
              else printf(" \n\n   LA PILE N EST PAS VIDE !!!!! \n\n") ;
              printf("\n\n\n") ;
                system("PAUSE");
              break ;
    case 6 : afficher(f);
       printf("\n\n\n") ;
                system("PAUSE");
              break ;

    }

     if (choix>=7) goto e ; else system("cls");
   goto d ;
    e : return 0;

    return 0;
}
