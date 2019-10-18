#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "Fonction_TP2.h"
#define Tfen 170
#define godown 30
#define p1 10

/**< ************************************************************************************************************************* */
/**<                                         Les fonctions de la première partie                                               */
/**< ************************************************************************************************************************* */
void creer_arbre_1 (struct noeud_1 **r, int n)
/**< elle permet de créer un arbre de la première partie d'une manière aléatoirement*/
{
    int i, val, bool;

    *r= NULL;

    i=1;
    bool= -1;
    while ((i<= n) || (bool == -1))
    {
        bool= 0;
        val= random_1(1,500);
        insert_arbre_1(&r, val, &bool); /**< insertion de la valeur dans l'arbre */
        printf("\n       ---->-La valeur du noeud %d est: %d", i, val);
        if (bool != -1)
            i++;
    }
}

void rech_arbre_1 (struct noeud_1 *r, int val, struct noeud_1 **pere, struct noeud_1 **noeud)
/**< elle permet de rechercher une valeur dans un arbre et de rendre son adresse et son pere */
{
    int trouv;

    *noeud = NULL;
    *pere = NULL;
    trouv = -1;
    while ((r!= NULL) && (trouv == -1))
    {
        if (info_noeud(r)== val)
        {
            trouv= 0;           /**< la valeur recherchée est trouvée */
            *noeud= r;
        }
        *pere= r;
        if (info_noeud(r)< val)
              r= FD_1(r);
        else
            r= FG_1(r);
    }
}

void insert_arbre_1 (struct noeud_1 **r, int val, int *bool)
/**< elle permet d'inserer un valeur donnée dans un arbre  */
{
    struct noeud_1 *pere, *noeud, *q;

    rech_arbre_1(*r, val, &pere, &noeud);   /**< faire une recherche de la valeur dans l'arbre avant de l'inserer */
    if (noeud != NULL)
    {
        printf("\n   -Insertion impossible!! l'element existe deja dans cet arbre.\n");
        *bool= -1;      /**< la valeur existe déja dans l'arbre */
    }
    else
    {
        /**< la valeur n'existe pas donc on va l'inserer */
        Creer_noeud_1 (&q, val);
        if (pere == NULL)
        {
            *r= q;
            *bool= 0;
        }
        else
        {
            if (info_noeud(pere)> val)
                Aff_FG_1(&pere,q);
            else
                Aff_FD_1(&pere, q);
        }
    }
}

int arbre_egal (struct noeud_1 *r1, struct noeud_1 *r2)
/**< elle permet de tester si deux arbre sont egaux ou non */
{
    int bool;

    if ((r1== NULL) && (r2== NULL))
    {
        bool= 1;
    }
    else
    {
        if (info_noeud(r1) != info_noeud(r2))
        {
            bool= 0;
        }
        else
        {                   /**< le test se fait d'une manière récursive */
            bool= (arbre_egal(FG_1(r1), FG_1(r2))) * (arbre_egal(FD_1(r1), FD_1(r2)));
        }

    }
    return bool;
}

int existe (struct noeud_1 *tab2[1000],int n, struct noeud_1 *r)
/**< elle permet de savoir si un element donne existe dans le tableau ou non */
{
    int bool, i;
    struct noeud_1 *p;

    bool= 0;
    i=0;
        while ((i< n) && (bool== 0))
        {
            p= tab2[i];
            bool= arbre_egal(p, r); /**< tester l'element donne avec les element du tableau */
            i++;
        }
    return bool;
}

void creer_mat (int n, int tab[100], int mat[ligne][colonne])
/**< elle permet de creer la matrice qui contient toutes les combinaisons possibles des elements d'un ensemble donné */
{
    int l,i,k,j,cpt, m;
    int bool;

    i=0;
    while (i< n)
    {
        tab[i]= random_1(1,900); /**< genere une valeur aleatoire */
        i++;
    }
    printf("\n\n\t-----> l'ensemble genere est le suivant: ");
    ECRT1D(tab, n);

    l=0;
    cpt=0;
    for (i=0; i< n; i++)    /**< l'indice qui va parcourire les colonnes de la matrice*/
    {
        cpt++;
        k=0;
        while (k< fact(n))  /**< l'indice qui va parcourire les lignes de la matrice */
        {
            j=0;
            while (j< fact(n-cpt)) /**< l'indice qui permet de parcourir la ligne de la matrice et de savoir si l'element
                                                   existe deja ou non */
            {
                bool= 0;
                for (m=0; m<=i; m++)    /**< l'indice qui permet d'inserer l'element dans la ligne */
                {
                    if (mat[k][m]== tab[l])
                        bool= 1;
                }
                if (bool != 1)
                {
                    mat[k][i]= tab[l];
                    k++;
                    j++;
                }
                else
                {
                    l++;
                    if (l> n-1)
                        l=0;
                }
            }
            l++;  /**< l'indice qui parcourir le tableau qui contient les element de l'ensemble */
            if (l> n-1)
                l= 0;
        }
    }
}

void creer_combinaison (int n, int *cpt, struct noeud_1 *tab2[1000])
/**< elle permet de creer toutes les combinaisons d'arbres binaires de recherche sans doubles */
{
    int   m,bool, i, j;
    struct noeud_1 *r;
    int mat[ligne][colonne];
    int tab[100];

    *cpt=0;
    m= 0;
    creer_mat(n, tab, mat); /**< generer la matrice qui va contenir tous les combinaisons de l'ensemble */
    for (i=0; i< fact(n); i++)
    {
        r= NULL;
        for (j=0; j<n; j++)
        {
            insert_arbre_1(&r, mat[i][j], &bool);
        }
        bool= existe(tab2,m, r); /**< savoir si l'arbre existe déja ou non */
        if (bool ==0)
        {
            tab2[m]= r; /**< sauvegarder la racine de l'arbre dans un tableau */
            m++;
        }
    }
    *cpt= m;
}

void creer_mat_man (int n, int tab[100], int mat[ligne][colonne])
/**< elle permet de creer la matrice qui contient toutes les combinaisons possibles des elements d'un ensemble donné */
{
    int l,i,k,j,cpt, m, val;
    int bool;

    i=0;
    while (i< n)
    {
        printf("\n\t\t  ---->Introduisez la valeur du noeud: ");
        scanf("%d", &val);
        bool=0;
        j=0;
        while ((j< i) && (bool == 0))
        {
            if (tab[j] == val)
                bool= 1;
            else
                bool= 0;
            j++;
        }
        if (bool == 0)
        {
            tab[i]= val;
            i++;
        }
        else
            printf(" \n\n\t\t-L'element existe deja dans l'ensemble.");
    }
    printf("\n\n\t-----> l'ensemble genere est le suivant: ");
    ECRT1D(tab, n);

    l=0;
    cpt=0;
    for (i=0; i< n; i++)    /**< l'indice qui va parcourire les colonnes de la matrice*/
    {
        cpt++;
        k=0;
        while (k< fact(n))  /**< l'indice qui va parcourire les lignes de la matrice */
        {
            j=0;
            while (j< fact(n-cpt)) /**< l'indice qui permet de parcourir la ligne de la matrice et de savoir si l'element
                                                   existe deja ou non */
            {
                bool= 0;
                for (m=0; m<=i; m++)    /**< l'indice qui permet d'inserer l'element dans la ligne */
                {
                    if (mat[k][m]== tab[l])
                        bool= 1;
                }
                if (bool != 1)
                {
                    mat[k][i]= tab[l];
                    k++;
                    j++;
                }
                else
                {
                    l++;
                    if (l> n-1)
                        l=0;
                }
            }
            l++;  /**< l'indice qui parcourir le tableau qui contient les element de l'ensemble */
            if (l> n-1)
                l= 0;
        }
    }
}

void creer_combinaison_man (int n, int *cpt, struct noeud_1 *tab2[1000])
/**< elle permet de creer toutes les combinaisons d'arbres binaires de recherche sans doubles */
{
    int   m,bool, i, j;
    struct noeud_1 *r;
    int mat[ligne][colonne];
    int tab[100];

    *cpt=0;
    m= 0;
    creer_mat_man(n, tab, mat); /**< generer la matrice qui va contenir tous les combinaisons de l'ensemble */
    for (i=0; i< fact(n); i++)
    {
        r= NULL;
        for (j=0; j<n; j++)
        {
            insert_arbre_1(&r, mat[i][j], &bool);
        }
        bool= existe(tab2,m, r); /**< savoir si l'arbre existe déja ou non */
        if (bool ==0)
        {
            tab2[m]= r; /**< sauvegarder la racine de l'arbre dans un tableau */
            m++;
        }
    }
    *cpt= m;
}

void affichval(struct noeud_1 *A)
/**< permet d'afficher la valeur du noeud */
{
    char S[30];
    sprintf(S," %d ",info_noeud(A));
    long l=strlen(S);
    long c=1;
    if (l%2==0) c--;
    long indx=wherex();
    gotoxy(wherex()-l/2-1,wherey());
    printf("%c",201);
    while (wherex()<indx+l/2+c) printf("%c",205);
    printf("%c",187);
    gotoxy(indx-l/2-1,wherey()+1);
    printf("%c",186);
    gotoxy(indx+l/2+c,wherey());
    printf("%c",186);
    gotoxy(indx-l/2,wherey());
    printf("%s",S);
    gotoxy(indx-l/2-1,wherey()+1);
    printf("%c",200);
    while (wherex()!=indx+l/2+c) printf("%c",205);
    printf("%c",188);
    gotoxy(indx,wherey()-1);
}

void affichARB(struct noeud_1 *A,long i,long j,long mid,long val)
/**< elle permet d'afficher l'arbre */
{
    system("color f0");
    if (A!=NULL)
    {
         gotoxy(i,j);
         long indx=wherex();
         if (FG_1(A)!=NULL)
         {
            gotoxy(i-((mid/2)),j+4);
            printf("%c",31);
            gotoxy(wherex()-1,wherey()-1);
            printf("%c",179);
            gotoxy(wherex()-1,wherey()-1);
            printf("%c",179);
            gotoxy(wherex()-1,wherey()-1);

            printf("%c",218);

            while (wherex()!=indx) printf("%c",196);
         }
         gotoxy(i,j+1);
         if (FD_1(A)!=NULL)
         {
            while (wherex()!=indx+mid/2) printf("%c",196);
            printf("%c",191);
            gotoxy(wherex()-1,wherey()+1);
            printf("%c",179);
            gotoxy(wherex()-1,wherey()+1);
            printf("%c",179);
            gotoxy(wherex()-1,wherey()+1);
            printf("%c",31);
            gotoxy(wherex()-1,wherey()+1);
         }
         gotoxy(i,j);
         textbackground(1);
         if (info_noeud(A)==val) textcolor(p1);
         affichval(A);
         textcolor(0);

         affichARB(FG_1(A),i-((mid/2)),j+5,mid/2,val);
         affichARB(FD_1(A),i+((mid/2)),j+5,mid/2,val);
    }

}

void afficher_1 (struct noeud_1 *tab[1000], int n)
/**< elle permet d'afficher toutes les arbres obtenues lors des combinaisons */
{
    struct noeud_1 *p;
    int i, j;
    long initx= wherex();
    long inity= wherey();

    i= 0;
    j= 1;

    while (i < n)
    {
        p= tab[i];
        gotoxy(initx,  wherey());
        printf("\n\n\t\t  ********************************** L'arbre %d est: ************************************", j);
         printf("\n\n\n\n");
        AFFICHAGEARB(p, 300);
        printf("\n\n\n\n");
        i++;
        j++;
    }
}

void AFFICHAGEARB(struct noeud_1 *A,long val)
{
    long initx=wherex();
    long inity=wherey();

    affichARB(A,Tfen/2,inity,Tfen/2,val);
    initx= wherex();
    inity= wherey()+6;
    gotoxy(initx,wherey()+58);
    gotoxy(initx,inity-1);
}

/**< ************************************************************************************************************************* */
/**<                                            Les fonctions de la deuxième partie                                            */
/**< ************************************************************************************************************************* */
void creer_arbre_2 (struct noeud_2 **r, int n)
/**< elle permet de creer un arbre de la deuxieme partie */
{
    int i,u,v, bool;

    *r= NULL;
    u=0;
    v=0;

    i=1;
    bool= -1;
    while ((i<=n) || (bool == -1))
    {
        bool= 0;
        random_2(&u, &v);   /**< generer deux valeurs aleatoires qui va etre la cle et la borne suo de l'intervalle */
        insert_arbre_2(r,u,v,&bool);    /**< inserer l'intervalle generer dans l'arbre */
        if (bool != -1)
        {
            printf("\n       ---->-La cle de la reservation %d est: %d", i, u);
            printf("\n       ---->-La borne superieure de la reservation %d est: %d", i, v);
            printf("\n");
            i++;
        }
    }
}

void creer_arbre_2_man (struct noeud_2 **r, int n)
/**< elle permet de creer un arbre des reservations d'une maniere manuelle */
{
    int i,u,v, bool;

    *r= NULL;
    u=0;
    v=0;

    i=1;
    bool= -1;
    while ((i<=n) || (bool == -1))
    {
        bool= 0;
        printf("\n       ---->-Veuillez inserer la cle de la reservation %d: ", i);
        scanf("%d", &u);    /**< lire la cle de l'intervalle */
        printf("\n       ---->-Veuillez inserer la borne superieure de la reservation %d: ", i);
        scanf("%d", &v);    /**< lire la borne sup de l'intervalle */
        if (u> v)
            printf("  \n-DESOLE! la cle de la reservation est superieure a la borne superieure.");
        insert_arbre_2(r,u,v,&bool);    /**< inserer l'intervalle dans l'arbre */
        if (bool != -1)
        {
            printf("\n");
            i++;
        }
        else
            printf("  \n-Votre reservation n'a pa pu etre inseree!");
    }
}

void rech_arbre_2 (struct noeud_2 *r, int u, int v, struct noeud_2 **pere, struct noeud_2 **noeud)
/**< elle permet de rechercher un intervalle dans un arbre et de sortir son adresse ainsi que l'adresse de son parent */
{
    int trouv;
    struct noeud_2 *p;

    *noeud = NULL;
    *pere = NULL;
    p= r;
    trouv = -1; /**< le booleen qui va me dire si l'element est trouve ou non  */
    while ((p!= NULL) && (trouv == -1))
    {
        if (((u >= Cle_noeud_2(p))&&(u<= Sup_noeud_2(p))) || ((v>= Cle_noeud_2(p))&&(v<= Sup_noeud_2(p))))
        {
            trouv= 0;
            *noeud= p;
        }
        else
        {
            *pere= p;
            if (Cle_noeud_2(p) < u)
                p= FD_2(p);
            else
                p= FG_2(p);
        }
    }
}

void insert_arbre_2 (struct noeud_2 **r, int u, int v, int *bool)
/**< elle permet d'inserer un intervalle dans un arbre */
{
    struct noeud_2 *pere, *noeud, *q;

    rech_arbre_2(*r,u,v, &pere, &noeud);    /**< rechercher l'intervalle s'il existe ou non dans l'arbre */
    if ((noeud != NULL) || (u>= v ))
    {
        *bool= -1;
    }
    else
    {
            Creer_noeud_2(&q, u, v);
            if (pere == NULL)
            {
                *r= q;
                *bool= 0;
            }
            else
            {
                Aff_PERE_2(&q, pere);
                if (Cle_noeud_2(pere)> u)
                    Aff_FG_2(&pere,q);
                else
                    Aff_FD_2(&pere, q);
            }
    }
}

int  intersecte (struct noeud_2 *r, int u, int v)
/**< elle permet de savoir si une reservation intersecte une autre anterieure ou non */
{
    int bool;
    struct noeud_2 *pere, *noeud;

    if (u> v)
        printf("  \n-DESOLE! la cle de la reservation est superieure a la borne superieure.");
    if (r== NULL)   /**< l'arbre n'existe pas */
    {
        printf("-Votre agenda ne contient aucune reservation a ce moment.");
        bool = -1;
    }
    else
    {
        rech_arbre_2(r, u, v, &pere, &noeud);
        if (noeud == NULL)
        {
            bool= 0;
            printf("\n   -Votre demande n'intersecte aucune reservation anterieure.");
        }
        else
        {
            bool= -1;
            printf("\n   -DESOLE! Votre demande intersecte une reservation anterieure.");
        }
    }
    return bool;
}

void ajouter (struct noeud_2 **r, int u, int v)
/**< elle permet d'ajouter une reservation a l'arbre */
{
    int bool;

    if (u> v)
        printf("  \n-DESOLE! la cle de la reservation est superieure a la borne superieure.");
    bool=5;
    bool= intersecte(*r, u,v);/**< savoir si la reservation intersecte une autre ou non */
    insert_arbre_2(r, u, v, &bool); /**< inserer la reservation */
    if (bool != -1)
    {
          printf("\n   -Votre reservation a ete ajoutee avec succes.");
    }
    else
    {
        printf("\n   -DESOLE! Cette demande ne peut pas etre ajoutee dans vos reservations.");
    }
}

void supprimer (struct noeud_2 **r, int u, int v)
/**< elle permet de supprimer une reservation dans l'arbre  */
{
    struct noeud_2 *pere, *noeud;
    struct noeud_2 *p, *q;

    if (*r== NULL)  /**< l'arbre n'existe pas */
    {
        printf("-Votre agenda ne contient aucune reservation a ce moment.");
    }
    else
    {
        rech_arbre_2(*r,u, v, &pere, &noeud);   /**< rechercher la reservation a supprimer */
        if (noeud == NULL)  /**< la reservation n'existe pas dans l'arbre */
        {
            printf("\n   -SUPPRESSION IMPOSSIBLE! Votre demande n'existe pas dans vos reservations.");
        }
        else    /**< la reservation existe  */
        {
            if (FG_2(noeud)== NULL)
            {
                if (FD_2(noeud)== NULL) /**< le FG et le FD du noeud son a nil */
                {
                    if (Cle_noeud_2(noeud)< Cle_noeud_2(pere))
                        Aff_FG_2(&pere, NULL);
                    else
                        Aff_FD_2(&pere, NULL);
                }
                else    /**< le FG du noeud est a nil et son FD n'est pas a nil */
                {
                    if (Cle_noeud_2(noeud)< Cle_noeud_2(pere))
                        Aff_FG_2(&pere, FD_2(noeud));
                    else
                        Aff_FD_2(&pere, FD_2(noeud));
                }
                Liberer_noeud_2(noeud);
            }
            else
            {
                if (FD_2(noeud)== NULL) /**< le FD du noeud est a nil et le FG n'est pas a nil */
                {
                    if (Cle_noeud_2(noeud)< Cle_noeud_2(pere))
                        Aff_FG_2(&pere, FG_2(noeud));
                    else
                        Aff_FD_2(&pere, FG_2(noeud));
                    Liberer_noeud_2(noeud);
                }
                else    /**< le FD et FG du noeud sont a nil */
                {
                    q= noeud;
                    p= FD_2(noeud);
                    while (FG_2(p)!= NULL)
                    {
                        q= p;
                        p= FG_2(p);     /**< rechercher la plus petite valeur gauche du FD du noeud */
                    }
                    Aff_Cle(&noeud, Cle_noeud_2(p));    /**< remplacer la valeur du noeud a supprimer par la petite valeur */
                    Aff_Sup(&noeud, Sup_noeud_2(p));
                    if (q!= noeud)
                        Aff_FG_2(&q, FD_2(p));  /**< faire le chainage adequat  */
                    else
                        Aff_FD_2(&q, FD_2(p));
                    Liberer_noeud_2(p);
                }
            }
                printf("\n  -La suppression de votre demande a ete effecteuee avec succes.");
        }
    }
}

void affichval_2 (struct noeud_2 *A)
/**< elle permet d'afficher le noeud qui contient la reservation */
{
    char S[30];
    sprintf(S," [%d..%d] ",Cle_noeud_2(A), Sup_noeud_2(A));
    long l=strlen(S);
    long c=1;
    if (l%2==0) c--;
    long indx=wherex();
    gotoxy(wherex()-l/2-1,wherey());
    printf("%c",201);
    while (wherex()<indx+l/2+c) printf("%c",205);
    printf("%c",187);
    gotoxy(indx-l/2-1,wherey()+1);
    printf("%c",186);
    gotoxy(indx+l/2+c,wherey());
    printf("%c",186);
    gotoxy(indx-l/2,wherey());
    printf("%s",S);
    gotoxy(indx-l/2-1,wherey()+1);
    printf("%c",200);
    while (wherex()!=indx+l/2+c) printf("%c",205);
    printf("%c",188);
    gotoxy(indx,wherey()-1);
}

void affichARB_2 (struct noeud_2 *A,long i,long j,long mid,long val)
/**< elle permet d'afficher l'arbre qui contient les reservations */
{
    system("color f0");
    if (A!=NULL)
    {
         gotoxy(i,j);
         long indx=wherex();
         if (FG_2(A)!=NULL)
         {
            gotoxy(i-((mid/2)),j+4);
            printf("%c",31);
            gotoxy(wherex()-1,wherey()-1);
            printf("%c",179);
            gotoxy(wherex()-1,wherey()-1);
            printf("%c",179);
            gotoxy(wherex()-1,wherey()-1);

            printf("%c",218);

            while (wherex()!=indx) printf("%c",196);
         }
         gotoxy(i,j+1);
         if (FD_2(A)!=NULL)
         {
            while (wherex()!=indx+mid/2) printf("%c",196);
            printf("%c",191);
            gotoxy(wherex()-1,wherey()+1);
            printf("%c",179);
            gotoxy(wherex()-1,wherey()+1);
            printf("%c",179);
            gotoxy(wherex()-1,wherey()+1);
            printf("%c",31);
            gotoxy(wherex()-1,wherey()+1);
         }
         gotoxy(i,j);
         textbackground(1);
         if (Cle_noeud_2(A)==val) textcolor(p1);
         affichval_2(A);
         textcolor(0);

         affichARB_2(FG_2(A),i-((mid/2)),j+5,mid/2,val);
         affichARB_2(FD_2(A),i+((mid/2)),j+5,mid/2,val);
    }

}

void AFFICHAGEARB_2 (struct noeud_2 *A,long val)
{
    long initx=wherex();
    long inity=wherey();

    affichARB_2 (A,Tfen/2,inity,Tfen/2,val);
    gotoxy(initx,inity);
}
/**< ************************************************************************************************************************* */
/**<                                            Autres fonctions utiles                                                        */
/**< ************************************************************************************************************************* */
int random_1(int brnI,int brnS)
{
    int a;

    srand(time(NULL)*rand());
    a=rand()%(brnS-brnI)+brnI;
    return a;
}

void random_2 (int *val1, int *val2)
{
    srand(time(NULL)*rand());
    *val1= rand()%(365-0)+0;
    *val2= random_1((*val1)+1, (*val1)+7);
}

int fact( int n)
{
    int i, res;

    res= 1;
    for (i=2; i<= n; i++)
        res= res* i;
    return res;
}

void ECRT1D (int tab[1000], int tai)
/*LECTURE D'UN TABLEAU A UNE DIMENSION*/
{
    int i;      /*l'indice du tableau*/

    for (i=0; i<tai; i++)
        printf("\t%d ", tab[i]);
    printf("\n");

    return ;
}

void ECRT2D_ord (int tab[ligne][colonne], int lig, int col)
/*Affichage d'un tableau à deux dimension*/
{
    int i;
    int j;

    printf ("\n");
    printf ("Le tableau final est: \n");
    for (i=0; i<lig; i++)
    {
        printf ("\n");
        for (j=0; j< col; j++)
        {
            printf ("\t%d", tab[i][j]);
        }
    }
    return ;
}

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void entree ()
{
    system("cls");

    textcolor(5);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t");
    printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
    printf("\t\t\t\t\t");
    printf("  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t\t");
    printf(" *");
    textcolor(3);
    printf("             _");
    textcolor(15);
    printf("      REPUBLIQUE ALGERIENNE DEMOCRATIQUE ET POPULAIRE ");

    textcolor(5);
    printf("       *\n");
    printf("\t\t\t\t\t");
    printf(" *            ");

    textcolor(3);
    printf("|_|");
    textcolor(15);
    printf("    MINISTERE DE L'ENSEIGNEMENT SUPERIEUR ET DE LA ");
    textcolor(5);
    printf("        *\n");
    printf("\t\t\t\t\t");
    printf(" *           ");
    textcolor(3);
    printf("/_/");
    textcolor(15);
    printf("                   RECHERCHE SCIENTIFIQUE ");
    textcolor(5);
    printf("                   *\n");
    printf("\t\t\t\t\t");
    printf(" *   ");
    textcolor(15);
    printf("___  ___ _");

    textcolor(5);
    printf("                                                            *\n");
    printf("\t\t\t\t\t");
    printf(" *  ");
    textcolor(15);

    printf("/ _ \\/ __| |");

    textcolor(5);
    printf("                                                             *\n");
    printf("\t\t\t\t\t");
    printf(" * ");
    textcolor(15);

    printf("|  __/\\__ \\ |        ECOLE NATIONALE SUPERIEURE D'INFORMATIQUE");

    textcolor(5);
    printf("          *\n");
    printf("\t\t\t\t\t");
    printf(" *  ");
    textcolor(15);

    printf("\\___||___/_|     ALGORITHME ET STRUCTURES DES DONNEES DYNAMIQUES");

    textcolor(5);
    printf("         * \n");
    printf("\t\t\t\t\t");
    printf(" *  ");
    textcolor(15);
    printf("                                  -ALSDD-");
    textcolor(5);
    printf("                              *\n");
    printf("\t\t\t\t\t");
    printf(" *  ");
    textcolor(4);
    printf("         --------------------------------------------------------      ");
    textcolor(5);
    printf("  *\n");
    printf("\t\t\t\t\t");
    printf(" *  ");
    textcolor(4);
    printf("         -");
    textcolor(15);
    printf("        Le deuxieme tavail pratique d'ALSDD.");
    textcolor(4);
    printf("           -");
    textcolor(5);
    printf("      *\n");
    printf("\t\t\t\t\t");
    printf(" *  ");
    textcolor(4);
    printf("      -");
    textcolor(15);;
    printf("  Le theme est: Arbres Binaires de Recherches -ABR-.");
    textcolor(4);
    printf("    -");
    textcolor(5);
    printf("        *\n");
    printf("\t\t\t\t\t");
    printf(" *  ");
    textcolor(4);
    printf("         -");
    textcolor(15);
    printf("  Realise par: IKHERBANE Jugurta et SADI Lynda");
    textcolor(4);
    printf("        -");
    textcolor(5);
    printf("      *\n");
    printf("\t\t\t\t\t");
    printf(" *  ");
    textcolor(4);
    printf("         -");
    textcolor(15);
    printf("      Section: B           Groupe: 07         ");
    textcolor(4);
    printf("        -");
    textcolor(5);
    printf("        *\n");
    printf("\t\t\t\t\t");
    printf(" *  ");
    textcolor(4);
    printf("         -");
    textcolor(15);
    printf("  Encadre par: Dr KERMI Adel                  ");
    textcolor(4);
    printf("        -");
    textcolor(5);
    printf("      *\n");
    printf("\t\t\t\t\t");
    printf(" *  ");
    textcolor(4);
    printf("         -");
    textcolor(15);
    printf("  Annee Universitaire:   2013/2014            ");
    textcolor(4);
    printf("        -");
    textcolor(5);
    printf("        *\n");
    printf("\t\t\t\t\t");
    printf(" *  ");
    textcolor(4);
    printf("         --------------------------------------------------------      ");
    textcolor(5);
    printf("*\n");
    printf("\t\t\t\t\t");
    textcolor(5);
    printf(" *  ");
    printf("                                                                         *\n");
    printf("\t\t\t\t\t");
    printf(" *  ");
    printf("                                                                       *\n");
    printf("\t\t\t\t\t");
    printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
    printf("\t\t\t\t\t");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");

    textcolor(2);
    printf("\n\n\t\t");
    system("pause");
}


/*-----------------------------------------------------------------------------------------------------------------------------*/
void contacter ()
{
    printf("\n");
    Color(12,15);
    printf("                         **************************\n");
    printf("                         *");
    printf("  POUR NOUS CONTACTER:  * \n");
    printf("                         **************************\n");
    Color(10,15);
     printf("\n\n \t+------------------------------------------------+\n");
     Color(0,15);
     printf(" \t|Mr. IKHERBANE Jugurta Etudiant a l'esi          |\n");
     printf(" \t|Melle.  SADI LYNDA Etudiante a l'esi            |\n");
     Color(10,15);
     printf(" \t+------------------------------------------------+\n");
     Color(0,15);
     printf(" \t|Adresse: Tizi-Ouzou,Algerie.                    |\n");
     Color(10,15);
     printf(" \t+------------------------------------------------+\n");
     Color(0,15);
     printf(" \t|Telephone: 0552-05-33-86                        |\n");
     Color(10,15);
     printf(" \t+------------------------------------------------+\n");
     Color(0,15);
     printf(" \t|E_mail: dj_ikherbane@esi.dz                     |\n");
     Color(10,15);
     printf(" \t+------------------------------------------------+\n");
     Color(0,15);
     printf(" \t|Facebook: Jugurta Lier                          |\n");
     Color(10,15);
     printf(" \t+------------------------------------------------+\n");
     Color(0,15);
     printf(" \t|Adresse de l'ecole: OUED SMAR,Alger,Algerie.    |\n");
     Color(10,15);
     printf(" \t+------------------------------------------------+\n");
     Color(0,15);
     printf(" \t|Site web de l'ecole: www.esi.dz                 |\n");
     Color(10,15);
     printf(" \t+------------------------------------------------+\n\n");
}

int menu(int max,...)
{
   int choi,a,i,b,d,y;
   char p[tmax];
   char **choix=NULL;
   choix=malloc(max*sizeof(p));
   va_list marker;
   va_start( marker,max );     /* Initialize variable arguments. */
   for (i=0;i<max;i++)
   {
      choix[i] = va_arg( marker,char*);
   }
    va_end( marker );
    d=wherey();
    y=d;
    textcolor (selected_color);
    textbackground (selected_background);
    printf("%s\n",choix[0]);
    textbackground (not_selected_background);
    textcolor(not_selected_color);
    for (i=1;i<max;i++)
    {
        printf("%s\n",choix[i]);
    }
    abbbbb:
    while((a=getch())==224)
    {
        b=getch();
        if(b==80 && y<d+max-1)
        {
            gotoxy(1,y);
            textcolor(not_selected_color);
            i=y-d;
            textbackground (not_selected_background);
            printf("%s",choix[i]);
            y++;
            textcolor (selected_color);
            gotoxy(1,y);
            textbackground (selected_background);
            printf("%s",choix[i+1]);
        }
        if(b==72 && y>d)
        {
            gotoxy(1,y);
            textcolor(not_selected_color);
            i=y-d;
            textbackground (not_selected_background);
            printf("%s",choix[i]);
            y--;
            textcolor (selected_color);
            gotoxy(1,y);
            textbackground (selected_background);
            printf("%s",choix[i-1]);
        }


        }
        if (a!=13)goto abbbbb;

    choi=y-d;
    textbackground (not_selected_background);
    textcolor(not_selected_color);
    gotoxy(1,d+4);
    return choi+1;
}
