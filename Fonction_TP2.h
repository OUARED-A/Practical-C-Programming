#ifndef FONCTION_TP2_H_INCLUDED
#define FONCTION_TP2_H_INCLUDED
#define ligne 1000
#define colonne 100
#define tmax 50
#define selected_color 12
#define selected_background 10
#define not_selected_color 15
#define not_selected_background 0

/**< ************************************************************************************************************************* */
/**<                                            Structure de la première partie                                                */
/**< ************************************************************************************************************************* */
struct noeud_1
{
    int info;
    struct noeud_1 *FG;
    struct noeud_1 *FD;
};

struct maillon
{
    struct noeud_1 *val;
    struct maillon *suiv;
};

/**< ************************************************************************************************************************* */
/**<                                            Structure de la deuxième partie                                                */
/**< ************************************************************************************************************************* */
struct noeud_2
{
    int u;
    int v;
    struct noeud_2 *FG;
    struct noeud_2 *FD;
    struct noeud_2 *PERE;
};

/**< ************************************************************************************************************************* */
/**<                                         Les fonctions de la première partie                                               */
/**< ************************************************************************************************************************* */
void creer_arbre_1 (struct noeud_1 **r, int n);
void rech_arbre_1 (struct noeud_1 *r, int val, struct noeud_1 **pere, struct noeud_1 **noeud);
void insert_arbre_1 (struct noeud_1 **r, int val, int *bool);
int arbre_egal (struct noeud_1 *r1, struct noeud_1 *r2);
int existe (struct noeud_1 *tab2[1000],int n, struct noeud_1 *r);
void creer_mat (int n, int tab[100], int mat[ligne][colonne]);
void creer_combinaison (int n, int *cpt, struct noeud_1 *tab2[1000]);
void creer_mat_man (int n, int tab[100], int mat[ligne][colonne]);
void creer_combinaison_man (int n, int *cpt, struct noeud_1 *tab2[1000]);
void affichval(struct noeud_1 *A);
void affichARB(struct noeud_1 *A,long i,long j,long mid,long val);
void afficher_1 (struct noeud_1 *tab[1000], int n);
void AFFICHAGEARB(struct noeud_1 *A,long val);
/**< ************************************************************************************************************************* */
/**<                                            Les fonctions de la deuxième parties                                           */
/**< ************************************************************************************************************************* */
void creer_arbre_2 (struct noeud_2 **r, int n);
void creer_arbre_2_man (struct noeud_2 **r, int n);
void rech_arbre_2 (struct noeud_2 *r, int u, int v, struct noeud_2 **pere, struct noeud_2 **noeud);
void insert_arbre_2 (struct noeud_2 **r, int u, int v, int *bool);
int  intersecte (struct noeud_2 *r, int u, int v);
void ajouter (struct noeud_2 **r, int u, int v);
void supprimer (struct noeud_2 **r, int u, int v);
void affichval_2 (struct noeud_2 *A);
void affichARB_2 (struct noeud_2 *A,long i,long j,long mid,long val);
void AFFICHAGEARB_2 (struct noeud_2 *A,long val);
/**< ************************************************************************************************************************* */
/**<                                            Autres fonctions utiles                                                        */
/**< ************************************************************************************************************************* */
int random_1(int brnI,int brnS);
void random_2 (int *val1, int *val2);
int fact( int n);
void ECRT1D (int tab[100], int tai);
void ECRT2D_ord (int tab[ligne][colonne], int lig, int col);
void Color(int couleurDuTexte,int couleurDeFond);
void entree ();
void contacter ();
int menu(int max,...);

#endif // FONCTION_TP2_H_INCLUDED
