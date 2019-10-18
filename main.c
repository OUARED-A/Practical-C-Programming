#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "Fonction_TP2.h"
#define godown 35

int main()
{
    int menu1, u, v, cpt= 0, n=0, i;
    struct noeud_1 *r1= NULL;
    struct noeud_2 *r2= NULL;
    struct maillon *tete= NULL;
    struct maillon *r;
    struct noeud_1 *p;
    struct noeud_1 *tab2[1000];
    char rep[3];
    long initx,inity;


    /**< Le corps du programme principale */
    system("color 0f");
    entree();
    printf("\n\n\n\n\n\n\n\n\t\t");

     menu:
        system("color 0f");
        system("cls");

       do
        {
        Color(12, 0);
        printf("\n");
        printf("\t\t\t\t\t\t                         **************************\n");
        printf("\t\t\t\t\t\t                         *");
        printf("    MENU PRINCIPAL:     * \n");
        printf("\t\t\t\t\t\t                         **************************\n");
        Color(15, 0);
        printf("\n\n\t\t---->Vous choisissez l'une des operations suivantes: \n\n\n");
        Color(10, 0);
        printf("\n\t\t\t\t-Utilisez les touches Haut-Bas du clavier pour selectionner  votre choix.\n\n\n");
        Color(0, 15);
        menu1= menu(4,"\t\t01.----->Partie 01- Creation et affichage des combinaisons des ABR.","\t\t02.----->Partie 02- Creation et affichage des reservations.","\t\t03.----->Contactez-nous.","\t\t04.----->Quitter le programme.");

        switch (menu1)
        {
        case 1:
            do
            {
            partie1:
            system("cls");
            system("color 0f");
            printf("\n");
            Color(15, 0);
            printf("\n\n\t\t---->Vous choisissez l'une des operations suivantes: \n\n\n");
            Color(10, 0);
            printf("\n\t\t\t\t-Utilisez les touches Haut-Bas du clavier pour selectionner  votre choix.\n\n\n");
            Color(0, 15);
            printf("\n\n\n");
            Color(12,0);
            printf("\t-Vous avez choisi la premiere partie.\n");
            Color(0,15);
            printf("\n\n\n");
            menu1= menu(3,"\t\t01.----->Creation et affichage des arbres binaires de recherche d'une maniere aleatoire.","\t\t02.----->Creation et affichage des arbres binaires de recherche manuellement.","\t\t03.----->Revenir au menu principal.");

            switch (menu1)
            {
                case 1:
                aleat1:
                    system("cls");
                    system("color f0");
                    printf("\n");
                    Color(13,15);
                    printf("\t-Vous avez choisi de creer un arbre de recherche binaire aleatoirement.\n");
                    Color(0,15);
                    printf("----->Veuillez introduire le nombre d'elements de votre arbre: ");
                    scanf("%d", &n);
                    creer_combinaison(n, &cpt, tab2);
                    Color(1, 15);
                    printf("\n\n   ----> Le nombre de combinaisons obtenues est: %d", cpt);
                    Color(5,15);
                    printf("\n\n     ----->Les arbres obtenus sont les suivantes: ");
                    printf("\n\n");
                    afficher_1(tab2, cpt);
                    gotoxy(wherex(), wherey()+20);
                    Color(0,15);
                    printf("\n\n\n\t\t\t\t-Voulez vous essayer une autre fois ?(oui/non)");
                    scanf("%s", &rep);
                    if (strcmpi(rep, "oui")== 0 )
                    {
                        goto aleat1;
                    }
                    if (strcmpi(rep, "non")== 0)
                    {
                        goto partie1;
                        system("color 0f");
                    }
                    break;
            case 2:
                manuel1:
                    system("cls");
                    system("color f0");
                    printf("\n");
                    Color(13,15);
                    printf("\t-Vous avez choisi de creer un arbre de recherche binaire manuellement.\n");
                    Color(0,15);
                    printf("----->Veuillez introduire le nombre d'elements de votre arbre: ");
                    scanf("%d", &n);
                    creer_combinaison_man(n, &cpt, tab2);
                    Color(1, 15);
                    printf("\n\n   ----> Le nombre de combinaisons obtenues est: %d", cpt);
                    Color(5,15);
                    printf("\n\n     ----->Les arbres obtenus sont les suivantes: ");
                    printf("\n\n");
                    afficher_1(tab2, cpt);
                    gotoxy(wherex(), wherey()+20);
                    printf("\n\n\n");
                    printf("\n\t\t\t-Voulez vous essayer une autre fois ?(oui/non)");
                    scanf("%s", &rep);
                    if (strcmpi(rep, "oui")== 0 )
                    {
                        goto manuel1;
                    }
                    if (strcmpi(rep, "non")== 0)
                    {
                        goto partie1;
                        system("color 0f");
                    }
                    break;
            case 3:
                    system("cls");
                    system("color f0");
                    printf("\n");
                    Color(13,15);
                    printf("\t-Vous avez choisi de revenir au menu principal.\n");
                    printf("\n\n");
                           printf("\n\n\t\tVoulez-vous vraiment revenir au menu principal.\n");
                    Color(12,15);
                    printf("                         01-oui          02-non     ");
                    Color(0,15);
                    printf("\n\n\tChoisissez votre reponse: ");
                    scanf("%s", &rep);
                    if (strcmpi(rep, "oui")== 0)
                    {
                        goto menu;
                    }
                    if (strcmpi (rep, "non")== 0)
                    {
                        goto partie1;
                    }
                    break;
                      default:
                    system("cls");
                    system("color f0");
                    printf("\n");
                    Color(12,15);
                    printf("\n\t-Votre choix est incorrecte. Le chois doit etre \n");
                    printf("              compris entre 1 et 7.\n");
                    Color(2,15);
                    printf("\n\n\n\t\t\t-Voulez vous essayer une autre fois ?(oui/non)");
                    scanf("%s", &rep);
                    if (strcmpi(rep, "oui")== 0 )
                    {
                        goto partie1;
                    }
                    if (strcmpi(rep, "non")== 0)
                    {
                        goto menu;
                    }
                }
            }while ((menu1 <1) || (menu1 >3));
            break;
            case 2:
                partie2:
                    do
                    {
                system("cls");
                system("color 0f");
                printf("\n");
                               Color(15, 0);
                printf("\n\n\t\t---->Vous choisissez l'une des operations suivantes: \n\n\n");
            Color(10, 0);
            printf("\n\t\t\t\t-Utilisez les touches Haut-Bas du clavier pour selectionner  votre choix.\n\n\n");
            Color(0, 15);
            printf("\n\n\n");
                Color(12,0);
                printf("\t-Vous avez choisi la deuxieme partie.\n");
                printf("\n\n\n");
                Color(0,15);
                menu1= menu(7,"\t\t01.----->Creation des reservations aleatoirement.","\t\t02.----->Creation des reservations manuellement.","\t\t03.----->Affichage de l'agenda des reservations.","\t\t04.----->Ma reservation intersecte-t-elle une autre anterieure?","\t\t05.----->Ajouter une reservation a l'agenda.","\t\t06.----->Supprimer une reservation de l'agenda.","\t\t07.----->Revenir au menu principal.");

                switch (menu1)
                {
                     case 1:
                aleat2:
                    system("cls");
                    system("color f0");
                    printf("\n");
                    Color(13,15);
                    printf("\t-Vous avez choisi de creer des reservations d'une maniere aleatoire.\n");
                    Color(0,15);
                    printf("---->Veuillez introduire le nombre de reservations a creer: ");
                    scanf("%d", &n);
                    creer_arbre_2(&r2, n);
                    printf("\n\n\n");
                    printf("\n\t\t\t-Voulez vous essayer une autre fois ?(oui/non)");
                    scanf("%s", &rep);
                    if (strcmpi(rep, "oui")== 0 )
                    {
                        goto aleat2;
                    }
                    if (strcmpi(rep, "non")== 0)
                    {
                        goto partie2;
                        system("color 0f");
                    }
                    break;
            case 2:
                manuel2:
                    system("cls");
                    system("color f0");
                    printf("\n");
                    Color(13,15);
                    printf("\t-Vous avez choisi de creer des reservations d'une maniere manuelle.\n");
                    Color(0,15);
                    printf("---->Veuillez introduire le nombre de reservations a creer: ");
                    scanf("%d", &n);
                    creer_arbre_2_man(&r2, n);
                    printf("\n\n\n");
                    printf("\n\t\t\t-Voulez vous essayer une autre fois ?(oui/non)");
                    scanf("%s", &rep);
                    if (strcmpi(rep, "oui")== 0 )
                    {
                        goto manuel2;
                    }
                    if (strcmpi(rep, "non")== 0)
                    {
                        goto partie2;
                        system("color 0f");
                    }
                    break;
            case 3:
                affiche2:
                    system("cls");
                    system("color f0");
                    printf("\n");
                    Color(13,15);
                    printf("\t-Vous avez choisi d'afficher toutes vos reservations.\n");
                    Color(1,15);
                    printf("\n\n");
                    printf("\t\t -----> Vos reservations sont representees dans l'arbre suivant: ");
                    Color(0, 15);
                    printf("\n\n\n");
                    initx= wherex();
                    inity= wherey();
                    gotoxy(initx, inity);
                    AFFICHAGEARB_2(r2, -192187);
                    gotoxy(initx, inity+godown);
                    printf("\n\n\n");
                    Color(0, 15);
                    printf("\n\t-Voulez vous essayer une autre fois ?(oui/non)");
                    scanf("%s", &rep);
                    if (strcmpi(rep, "oui")== 0 )
                    {
                        goto affiche2;
                    }
                    if (strcmpi(rep, "non")== 0)
                    {
                        goto partie2;
                        system("color 0f");
                    }
                    break;
            case 4:
                intersecte:
                    system("cls");
                    system("color f0");
                    printf("\n");
                    Color(13,15);
                    printf("\t-Vous avez choisi de verifier si votre reservation intersecte une autre anterieure.\n");
                    Color(1,15);
                    printf("\n       ---->-Veuillez inserer la cle de votre reservation: ");
                    scanf("%d", &u);
                    printf("\n       ---->-Veuillez inserer la borne superieure de votre reservation: ");
                    scanf("%d", &v);
                    Color(0, 15);
                    intersecte(r2, u, v);
                    printf("\n\n\n");
                    printf("\n\t-Voulez vous essayer une autre fois ?(oui/non)");
                    scanf("%s", &rep);
                    if (strcmpi(rep, "oui")== 0 )
                    {
                        goto intersecte;
                    }
                    if (strcmpi(rep, "non")== 0)
                    {
                        goto partie2;
                        system("color 0f");
                    }
                    break;
            case 5:
                ajout:
                    system("cls");
                    system("color f0");
                    printf("\n");
                    Color(13,15);
                    printf("\t-Vous avez choisi d'ajouter une reservation dans votre agenda.\n");
                    Color(1 ,15);
                    printf("\n       ---->-Veuillez inserer la cle de la reservation a ajouter: ");
                    scanf("%d", &u);
                    printf("\n       ---->-Veuillez inserer la borne superieure de la reservation a ajouter: ");
                    scanf("%d", &v);
                    Color(0,15);
                    printf("\n\n");
                    printf("\n\n\t\t-Voulez-vous vraiment ajouter cette reservation.\n");
                    Color(12,15);
                    printf("                         01-oui          02-non     ");
                    Color(0,15);
                    printf("\n\n\tChoisissez votre reponse: ");
                    scanf("%s", &rep);
                    if (strcmpi(rep, "non")== 0)
                    {
                        goto menu;
                    }
                    ajouter(&r2, u, v);
                    printf("\n\n\n");
                    printf("\n\t\t\t-Voulez vous essayer une autre fois ?(oui/non)");
                    scanf("%s", &rep);
                    if (strcmpi(rep, "oui")== 0 )
                    {
                        goto ajout;
                    }
                    if (strcmpi(rep, "non")== 0)
                    {
                        goto partie2;
                        system("color 0f");
                    }
                    break;
            case 6:
                suppr:
                    system("cls");
                    system("color f0");
                    printf("\n");
                    Color(13,15);
                    printf("\t-Vous avez choisi de supprimer une reservation dans votre agenda.\n");
                    Color(1,15);
                    printf("\n       ---->-Veuillez inserer la cle de la reservation a supprimer: ");
                    scanf("%d", &u);
                    printf("\n       ---->-Veuillez inserer la borne superieure de la reservation a supprimer: ");
                    scanf("%d", &v);
                    printf("\n\n");
                    Color(0, 15);
                    printf("\n\n\t\tVoulez-vous vraiment supprimer cette reservation.\n");
                    Color(12,15);
                    printf("                         01-oui          02-non     ");
                    Color(0,15);
                    printf("\n\n\tChoisissez votre reponse: ");
                    scanf("%s", &rep);
                    if (strcmpi(rep, "non")== 0)
                    {
                        goto menu;
                    }
                    supprimer(&r2, u, v);
                    printf("\n\n\n");
                    printf("\n\t-Voulez vous essayer une autre fois ?(oui/non)");
                    scanf("%s", &rep);
                    if (strcmpi(rep, "oui")== 0 )
                    {
                        goto suppr;
                    }
                    if (strcmpi(rep, "non")== 0)
                    {
                        goto partie2;
                        system("color 0f");
                    }
                    break;
            case 7:
                    system("cls");
                    system("color f0");
                    printf("\n");
                    Color(13,15);
                    printf("\t-Vous avez choisi de revenir au menu principal.\n");
                    printf("\n\n");
                    printf("\n\n\t\tVoulez-vous vraiment revenir au menu principal.\n");
                    Color(12,15);
                    printf("                         01-oui          02-non     ");
                    Color(0,15);
                    printf("\n\n\tChoisissez votre reponse: ");
                    scanf("%s", &rep);
                    if (strcmpi(rep, "oui")== 0)
                    {
                        goto menu;
                    }
                    if (strcmpi (rep, "non")== 0)
                    {
                        goto partie2;
                    }
                    break;
                default:
                    system("cls");
                    system("color f0");
                    printf("\n");
                    Color(12,15);
                    printf("\n\t-Votre choix est incorrecte. Le chois doit etre \n");
                    printf("              compris entre 1 et 7.\n");
                    Color(2,15);
                    printf("\n\n\n\t\t\t-Voulez vous essayer une autre fois ?(oui/non)");
                    scanf("%s", &rep);
                    if (strcmpi(rep, "oui")== 0 )
                    {
                        goto partie2;
                    }
                    if (strcmpi(rep, "non")== 0)
                    {
                        goto menu;
                    }
                }
                }while ((menu1 <1) || (menu1 >7));
                break;
            case 3:
                contact:
                    system("cls");
                    system("color f0");
                    printf("\n");
                    Color(13,15);
                    printf("\t-Vous avez choisi de nous contacter.\n");
                    Color(0,15);
                    contacter();
                    printf("\n\n\n");
                    printf("\n\t-Voulez vous essayer une autre fois ?(oui/non)");
                    scanf("%s", &rep);
                    if (strcmpi(rep, "oui")== 0 )
                    {
                        goto contact;
                    }
                    if (strcmpi(rep, "non")== 0)
                    {
                        goto menu;
                        system("color 0f");
                    }
                    break;
            case 4:
                quit:
                    system("cls");
                    system("color f0");
                    printf("\n");
                    Color(13,15);
                    printf("\t-Vous avez choisi de quitter ce programme.\n");
                    Color(8,15);
                    printf("\n\n\t\tVoulez-vous vraiment quitter ce programme.\n");
                    Color(12,15);
                    printf("                         01-oui          02-non     ");
                    Color(0,15);
                    printf("\n\n\tChoisissez votre reponse: ");
                    scanf("%s", &rep);
                    if (strcmpi(rep, "oui")== 0)
                    {
                        goto end;
                    }
                    if (strcmpi (rep, "non")== 0)
                    {
                        goto menu;
                    }
                    break;
            default:
                    system("cls");
                    system("color f0");
                    printf("\n");
                    Color(12,15);
                    printf("\n\t-Votre choix est incorrecte. Le chois doit etre \n");
                    printf("              compris entre 1 et 5.\n");
                    Color(2,15);
                    printf("\n\n\n\t\t\t-Voulez vous essayer une autre fois ?(oui/non)");
                    scanf("%s", &rep);
                    if (strcmpi(rep, "oui")== 0 )
                    {
                        goto menu;
                    }
                    if (strcmpi(rep, "non")== 0)
                    {
                        goto quit;
                    }
            }
        }while ((menu1 <1) || (menu1 >4));
    end:
        return 0;
}
