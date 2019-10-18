#ifndef MODELE_TP2_H_INCLUDED
#define MODELE_TP2_H_INCLUDED

int info_noeud (struct noeud_1 *r);
struct noeud_1 *FD_1(struct noeud_1 *r);
struct noeud_1 *FG_1 (struct noeud_1 *r);
void Aff_info (struct noeud_1 **r, int x);
void Aff_FD_1 (struct noeud_1 **r, struct noeud_1 *p);
void Aff_FG_1 (struct noeud_1 **r, struct noeud_1 *p);
void Creer_noeud_1(struct noeud_1 **r, int x);
void Liberer_noeud_1 (struct noeud_1 *r);

void  Allouer (struct maillon **p);
void Liberer (struct maillon *p);
struct noeud_1 *Valeur (struct maillon *p);
struct maillon *suivant (struct maillon *p);
void Aff_Adr (struct maillon *p, struct maillon *q);
void Aff_Val (struct maillon *p, struct noeud_1 *q);

int Cle_noeud_2 (struct noeud_2 *r);
int Sup_noeud_2 (struct noeud_2 *r);
struct noeud_2 *FD_2 (struct noeud_2 *r);
struct noeud_2 *FG_2 (struct noeud_2 *r);
struct noeud_2 *PERE_2 (struct noeud_2 *r);
void Aff_Cle (struct noeud_2 **r, int u);
void Aff_Sup (struct noeud_2 **r, int v);
void Aff_FD_2 (struct noeud_2 **r, struct noeud_2 *p);
void Aff_FG_2 (struct noeud_2 **r, struct noeud_2 *p);
void Aff_PERE_2 (struct noeud_2 **r, struct noeud_2 *p);
void Creer_noeud_2(struct noeud_2 **r, int u, int v);
void Liberer_noeud_2 (struct noeud_2 *r);


#endif // MODELE_TP2_H_INCLUDED
