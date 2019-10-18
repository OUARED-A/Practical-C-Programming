#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "Fonction_TP2.h"
#include "Modele_TP2.h"

/**< ************************************************************************************************************************* */
/**<                                         Le modèle utilisé pour la première partie                                         */
/**< ************************************************************************************************************************* */
int info_noeud (struct noeud_1 *r)
{
    return (r->info);
}

struct noeud_1 *FD_1(struct noeud_1 *r)
{
    return (r->FD);
}

struct noeud_1 *FG_1 (struct noeud_1 *r)
{
    return (r->FG);
}

void Aff_info (struct noeud_1 **r, int x)
{
    (*r)->info= x;
}

void Aff_FD_1 (struct noeud_1 **r, struct noeud_1 *p)
{
    (*r)->FD= p;
}

void Aff_FG_1 (struct noeud_1 **r, struct noeud_1 *p)
{
    (*r)->FG= p;
}

void Creer_noeud_1(struct noeud_1 **r, int x)
{

    *r= ((struct noeud_1 *) malloc(sizeof (struct noeud_1)));
    Aff_info(r, x);
    Aff_FD_1(r,NULL);
    Aff_FG_1(r, NULL);
}

void Liberer_noeud_1 (struct noeud_1 *r)
{
    free(r);
}

/**< ************************************************************************************************************************* */
/**<                                         Le modèle des LLC pour la première partie                                         */
/**< ************************************************************************************************************************* */
void  Allouer (struct maillon **p)
/*Permet d'allouer un nouveau maillon et retourner son adresse dans un pointeur*/
{
    *p=((struct maillon *) malloc (sizeof (struct maillon)));

}

void Liberer (struct maillon *p)
/*Permet de détruire un maillon donné*/
{
    free (p);
}

struct noeud_1 *Valeur (struct maillon *p)
/*Permet de rerourner la valeur qui se trouve dans le champs valeur dans un maillon donné*/
{
    return (p->val);
}

struct maillon *suivant (struct maillon *p)
/*Permet de retourner l'adresse du maillon suivant qui se trouve dans le champs suiv de maillon p*/
{
    return (p->suiv) ;
}

void Aff_Adr (struct maillon *p, struct maillon *q)
/*Permet d'affecter une adresse dans le champs suiv d'un maillon donné*/
{
    p->suiv= q;
}

void Aff_Val (struct maillon *p, struct noeud_1 *q)
/*Permet d'affecter une valeur donnée dans le champs val d'un maillon donné*/
{
    p->val= q;
}
/**< ************************************************************************************************************************* */
/**<                                         Le modèle utilisé pour la deuxième partie                                         */
/**< ************************************************************************************************************************* */
int Cle_noeud_2 (struct noeud_2 *r)
{
    return (r->u);
}

int Sup_noeud_2 (struct noeud_2 *r)
{
    return (r->v);
}

struct noeud_2 *FD_2 (struct noeud_2 *r)
{
    return (r->FD);
}

struct noeud_2 *FG_2 (struct noeud_2 *r)
{
    return (r->FG);
}

struct noeud_2 *PERE_2 (struct noeud_2 *r)
{
    return (r->PERE);
}

void Aff_Cle (struct noeud_2 **r, int u)
{
    (*r)->u = u;
}

void Aff_Sup (struct noeud_2 **r, int v)
{
    (*r)->v = v;
}

void Aff_FD_2 (struct noeud_2 **r, struct noeud_2 *p)
{
    (*r)->FD= p;
}

void Aff_FG_2 (struct noeud_2 **r, struct noeud_2 *p)
{
    (*r)->FG= p;
}

void Aff_PERE_2 (struct noeud_2 **r, struct noeud_2 *p)
{
    (*r)->PERE = p;
}

void Creer_noeud_2(struct noeud_2 **r, int u, int v)
{
    *r= ((struct noeud_2 *) malloc(sizeof (struct noeud_2)));
    Aff_Cle(r, u);
    Aff_Sup(r, v);
    Aff_FD_2(r,NULL);
    Aff_FG_2(r, NULL);
    Aff_PERE_2(r, NULL);
}

void Liberer_noeud_2 (struct noeud_2 *r)
{
    free(r);
}
