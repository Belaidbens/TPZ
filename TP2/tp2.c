  /**--------------------------------------------------------**/
  /**       C o n v e r s i o n   Z vers C (Standard)        **/
  /**             Réalisée par Pr D.E ZEGOUR                 **/
  /**             E S I - Alger                              **/
  /**             Copywrite 2014                             **/
  /**--------------------------------------------------------**/




  #include <stdio.h>
  #include <stdlib.h>
  #include <Time.h>
  #include <stdbool.h>

//  typedef int bool ;

  #define True 1
  #define False 0

  /************************** Implémentation ************************\: *****************ARBRE BINAIRE DE ENTIERS***************/

  /************************************************ Arbres de recherche binaire**********************************************/

  typedef int Typeelem_Ai   ;
  typedef struct Noeud_Ai * Pointeur_Ai ;

  struct Noeud_Ai
    {
      Typeelem_Ai  Val ;
      Pointeur_Ai Fg ;
      Pointeur_Ai Fd ;
      Pointeur_Ai Pere ;
     } ;

  Typeelem_Ai Info_Ai( Pointeur_Ai P )
    { return P->Val;   }

  Pointeur_Ai Fg_Ai( Pointeur_Ai P)
    { return P->Fg ; }

  Pointeur_Ai Fd_Ai( Pointeur_Ai P)
    { return P->Fd ; }

  Pointeur_Ai Pere_Ai( Pointeur_Ai P)
    { return P->Pere ; }

  void Aff_info_Ai ( Pointeur_Ai P, Typeelem_Ai Val)
    {
       P->Val = Val ;
    }

  void Aff_fg_Ai( Pointeur_Ai P, Pointeur_Ai Q)
    { P->Fg =  Q;  }

  void Aff_fd_Ai( Pointeur_Ai P, Pointeur_Ai Q)
    { P->Fd =  Q ; }

  void Aff_pere_Ai( Pointeur_Ai P, Pointeur_Ai Q)
    { P->Pere =  Q ; }

  void Creernoeud_Ai( Pointeur_Ai *P)
    {
      *P = (struct Noeud_Ai *) malloc( sizeof( struct Noeud_Ai))   ;
      (*P)->Fg = NULL;
      (*P)->Fd = NULL;
      (*P)->Pere = NULL;
    }

  void Liberernoeud_Ai( Pointeur_Ai P)
    { free( P ) ; }

  /** Variables du programme principal **/
  Pointeur_Ai A1=NULL;
  Pointeur_Ai A2=NULL;
  Pointeur_Ai A3=NULL;
  Pointeur_Ai P=NULL;
  Pointeur_Ai Q=NULL;
  Pointeur_Ai P1=NULL;
  Pointeur_Ai Q1=NULL;
  Pointeur_Ai P2=NULL;
  int J;
  bool Trouv;
  int _Px1;
  int _Px2;

  /******************************************* Fonctions standards ***************************************************************/

  int Aleanombre( int N )
    { return ( rand() % N ); }


  /****************************************************** Prototypes des fonctions ***********************************************/

  void Inordre (Pointeur_Ai *A);
  void Preordre (Pointeur_Ai *A);
  void Postordre (Pointeur_Ai *A);
  void Premier_inordre (Pointeur_Ai *A , Pointeur_Ai *P);
  void Premier_preordre (Pointeur_Ai *A , Pointeur_Ai *P);
  void Suivant_preordre (Pointeur_Ai *A , Pointeur_Ai *P);
  void Creerarbre (Pointeur_Ai *A , int *N);
  void Inserer (Pointeur_Ai *A , int *N);
  void Suivant_inordre (Pointeur_Ai *A , Pointeur_Ai *P);
  void Premier_postordre (Pointeur_Ai *A , Pointeur_Ai *P);
  void Suivant_postordre (Pointeur_Ai *A , Pointeur_Ai *P);
  void Fusion_ps_ps (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3);
  void Fusion_pr_pr (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3);
  void Fusion_pr_ps (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3);
  void Fusion_in_ps (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3);
  void Fusion_in_pr (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3);

/********************************************IMPLEMENTATION PILE && FILE************************************************************/
struct maillon {
Pointeur_Ai n;
struct maillon *suiv;
}maillon;
static struct maillon* tete = NULL;
static struct maillon* queuee = NULL;

static struct maillon* tete2 = NULL;
static struct maillon* queuee2 = NULL;


bool filevide(void)
{
if(tete == NULL && queuee == NULL)
    return true;

return false;
}

bool filevide2(void)
{
if(tete2 == NULL && queuee2 == NULL)
    return true;

return false;
}

void enfiler(Pointeur_Ai p){
struct maillon *temp =(struct maillon*)malloc(sizeof(struct maillon*));
if (temp==NULL){

    printf("erreur d'allocation");
}
 temp->n=p;
 temp->suiv=NULL;
 if(filevide()){
    tete=queuee=temp;
 }else{

 queuee->suiv=temp;
 queuee=temp;

 }
}


void enfiler2(Pointeur_Ai p){
struct maillon *temp =(struct maillon*)malloc(sizeof(struct maillon*));
if (temp==NULL){

    printf("erreur d'allocation");
}
 temp->n=p;
 temp->suiv=NULL;
 if(filevide2()){
    tete2=queuee2=temp;
 }else{

 queuee2->suiv=temp;
 queuee2=temp;

 }
}


void defiler(Pointeur_Ai* p){
if(filevide()){
    printf("on a rien a defiler car la file est vide");
}
struct maillon*temp=tete;
     if(tete==queuee){//cas d'un seul elem
       *p=tete->n;
       tete=NULL;
       queuee=NULL;
     }
       else{
       *p=tete->n;
       tete=tete->suiv;
       free(temp);
       }
}


void defiler2(Pointeur_Ai* p){
if(filevide2()){
    printf("on a rien a defiler car la file est vide");
}
struct maillon*temp=tete2;
     if(tete2==queuee2){//cas d'un seul elem
       *p=tete2->n;
       tete2=NULL;
       queuee2=NULL;
     }
       else{
       *p=tete2->n;
       tete2=tete2->suiv;
       free(temp);
       }
}












/***____________________________________________LES STATISTIQUES___________________________________________***/

int max(int a, int b) {
    if (a <= b)
        return b;
    else
        return a;
}

int min(int a, int b) {
    if (a <= b)
        return a;
    else
        return b;
}



 /*_____________________________________________STRICTEMENT BINAIRE__________________________________________________*/

 bool arb_strict_binr(Pointeur_Ai r) {
    bool trouv;

    if (r == NULL) {
        trouv = true;
    } else if (Fg_Ai(r) == NULL && Fd_Ai(r) == NULL) {
        trouv = true;
    } else if (Fg_Ai(r) != NULL ^ Fd_Ai(r) != NULL) {
        trouv = false;
    } else {
        trouv = arb_strict_binr(Fg_Ai(r)) && arb_strict_binr(Fd_Ai(r));
    }

    return trouv;
}

/*____________________________________________LA PROFONDEUR_________________________________________________________*/

  int profondeurr(Pointeur_Ai p) {
    int pr;

    if (p == NULL) {
        pr = -1;
    } else {
        if (Fg_Ai(p) == NULL && Fd_Ai(p) == NULL) {
            pr = 0;
        } else {
            pr = max(profondeurr(Fg_Ai(p)), profondeurr(Fd_Ai(p))) + 1;
        }
    }
    return pr;
}

/*____________________________________________NBR DE FEUILLES________________________________________________________*/

  int nb_feuiller(Pointeur_Ai p) {
    int k;
    if (p == NULL) {
        k = 0;
    } else {
        if (Fg_Ai(p) == NULL && Fd_Ai(p) == NULL)
            k = 1;
        else {
            k = nb_feuiller(Fg_Ai(p)) + nb_feuiller(Fd_Ai(p));
        }
    }

    return k;
}

/*_____________________________________________COMPLET??__________________________________________________________________*/

bool arb_completr(Pointeur_Ai r, int* pr) {
    int pr1 = -1, pr2 = -1;
    bool verif = true;

    if (r == NULL) {
        *pr = -1;
        verif = true;
    } else if (arb_completr(Fg_Ai(r), &pr1) && arb_completr(Fd_Ai(r), &pr2) && pr1 == pr2) {
        *pr = pr1 + 1;
        verif = true;
    } else {
        verif = false;
    }

    return verif;
}

/*___________________________________________________ EQUILIBRE ______________________________________________________________*/
bool Equilibre(Pointeur_Ai r){
  bool verif;
  int pr1,pr2;
 if(r==NULL){
    verif=true;
 }else {
  pr1=profondeurr(Fg_Ai(r));
  pr2=profondeurr(Fd_Ai(r));
  int pr=pr1-pr2;
   if (abs(pr)<=1){
     verif=(Equilibre(Fg_Ai(r))&& Equilibre(Fd_Ai(r)));
   }else{
    verif=false;
   }
}
return verif;
}
/*__________________________________________________POURCENTAGE D'EQUILIBRAGE___________________________________________________*/
 int pourcentage(Pointeur_Ai r) {
 Pointeur_Ai n=r;
 int nb=0;
if(r!=NULL){
    enfiler(r);
}
while(!filevide()){
defiler(&n);
if (Equilibre(n))
nb++;
if(Fg_Ai(n)!=NULL){
    enfiler(Fg_Ai(n));
}
if(Fd_Ai(n)!=NULL){
    enfiler(Fd_Ai(n));
}
}

return nb;
 }
/*_____________________________________________NBR NOEUDS PAR NIVEAU________________________________________________________________*/

void nb_noeuds (Pointeur_Ai A)
{ Pointeur_Ai p;
int i;
int lvl=0,nb=1;
p=A;
if(p==A){
  printf("lvl : %d  , nb : %d \n",lvl,nb);
  if (Fg_Ai(p)!=NULL)
  {
      enfiler(Fg_Ai(p));
      enfiler2(Fg_Ai(p));
  }
    if (Fd_Ai(p)!=NULL)
  {
      enfiler(Fd_Ai(p));
      enfiler2(Fd_Ai(p));
  }
}

suite:
nb=0;
lvl++;

while(!filevide2())
{
    defiler2(&p);
    nb++;

}
printf("lvl : %d  , nb : %d \n",lvl,nb);
for (i=1;i<=nb;i++)
{
    defiler(&p);
     if (Fg_Ai(p)!=NULL)
  {
      enfiler(Fg_Ai(p));
      enfiler2(Fg_Ai(p));
  }
    if (Fd_Ai(p)!=NULL)
  {
      enfiler(Fd_Ai(p));
      enfiler2(Fd_Ai(p));
  }
}

if (!filevide2())
{
goto suite;
}

}
/*____________________________________________________HAUTEUR MINIMALE____________________________________________________*/

    int H_min(Pointeur_Ai p) {
    int pr;

    if (p == NULL) {
        pr = -1;
    } else if(Fd_Ai(p)==NULL && Fg_Ai(p)==NULL) {
        pr=0;
    }else if(Fg_Ai(p)!=NULL && Fd_Ai(p)==NULL){
      pr=H_min(Fg_Ai(p))+1;
    }else if(Fg_Ai(p)==NULL && Fd_Ai(p)!=NULL){
      pr=H_min(Fd_Ai(p))+1;
    }else{
      pr=min(H_min(Fg_Ai(p)),H_min(Fd_Ai(p)))+1;
    }
    return pr;

    }




  /*__________________________AFFICHAGE INORDRE_______________________________*/
  void Inordre (Pointeur_Ai *A)
    {
      /** Variables locales **/
      Pointeur_Ai _Px1=NULL;
      Pointeur_Ai _Px2=NULL;

      /** Corps du module **/
     if( *A != NULL) {
       _Px1 =  Fg_Ai ( *A ) ;
       Inordre ( &_Px1) ;
       printf ( " %d", Info_Ai(*A) ) ;
       _Px2 =  Fd_Ai ( *A ) ;
       Inordre ( &_Px2) ;

     } ;

    }
  /*_________________________AFFICHAGE PREORDRE______________________________*/
  void Preordre (Pointeur_Ai *A)
    {
      /** Variables locales **/
      Pointeur_Ai _Px1=NULL;
      Pointeur_Ai _Px2=NULL;

      /** Corps du module **/
     if( *A != NULL) {
       printf ( " %d", Info_Ai(*A) ) ;
       _Px1 =  Fg_Ai ( *A ) ;
       Preordre ( &_Px1) ;
       _Px2 =  Fd_Ai ( *A ) ;
       Preordre ( &_Px2) ;

     } ;

    }
  /*___________________________AFFICHAGE POSTORDRE______________________________*/
  void Postordre (Pointeur_Ai *A)
    {
      /** Variables locales **/
      Pointeur_Ai _Px1=NULL;
      Pointeur_Ai _Px2=NULL;

      /** Corps du module **/
     if( *A != NULL) {
       _Px1 =  Fg_Ai ( *A ) ;
       Postordre ( &_Px1) ;
       _Px2 =  Fd_Ai ( *A ) ;
       Postordre ( &_Px2) ;
       printf ( " %d", Info_Ai(*A) ) ;

     } ;

    }
  /*_________________________PREMIER INORDRE____________________________________*/
  void Premier_inordre (Pointeur_Ai *A , Pointeur_Ai *P)
    {

      /** Corps du module **/
     if( *A == NULL) {
       ;
       *P  =  NULL ;
       }
     else
       {
       *P  =  *A ;
       while( Fg_Ai ( *P ) != NULL) {
         *P  =  Fg_Ai ( *P ) ;

       }
     } ;

    }
  /*_________________________ PREMIER PREORDRE__________________________________*/
  void Premier_preordre (Pointeur_Ai *A , Pointeur_Ai *P)
    {

      /** Corps du module **/
     *P  =  *A ;

    }
  /*__________________________SUIVANT PREORDRE__________________________________*/
  void Suivant_preordre (Pointeur_Ai *A , Pointeur_Ai *P)
    {
      /** Variables locales **/
      bool Trouv;

      /** Corps du module **/
     Trouv  =  True ;
     *P  =  *A ;
     if( Fg_Ai ( *P ) != NULL) {
       *P  =  Fg_Ai ( *P ) ;
       }
     else
       {
       if( Fd_Ai ( *P ) != NULL) {
         *P  =  Fd_Ai ( *P ) ;
         }
       else
         {
         while( ( Pere_Ai ( *P ) != NULL ) && ( Trouv == True )) {
           if( ( *P == Fd_Ai ( Pere_Ai ( *P ) ) ) || ( ( Fd_Ai ( Pere_Ai ( *P ) ) == NULL ) && ( Pere_Ai ( *P ) != NULL ) )) {
             ;
             Trouv  =  True ;
             *P  =  Pere_Ai ( *P ) ;
             }
           else
             {
             Trouv  =  False ;

           } ;

         } ;
         if( Pere_Ai ( *P ) == NULL) {
           *P  =  NULL ;
           }
         else
           {
           if( Fd_Ai ( Pere_Ai ( *P ) ) != NULL) {
             *P  =  Fd_Ai ( Pere_Ai ( *P ) ) ;

           } ;

         } ;

       } ;

     } ;

    }
  /*_______________________________CREER ARBRE__________________________________*/
  void Creerarbre (Pointeur_Ai *A , int *N)
    {
      /** Variables locales **/
      Pointeur_Ai P=NULL;
      Pointeur_Ai P1=NULL;
      Pointeur_Ai P2=NULL;
      int Val;
      int I;

      /** Corps du module **/
     *A  =  NULL ;
     P  =  NULL ;
     for( I  =  1 ;I <=  *N ; ++I){
       Val  =  Aleanombre(20000 ) ;
       Creernoeud_Ai (& P ) ;
       Aff_info_Ai ( P , Val ) ;
       if( ( *A == NULL )) {
         *A  =  P ;
         Aff_pere_Ai ( *A , NULL ) ;
         }
       else
         {
         P1  =  *A ;
         while( P1 != NULL) {
           P2  =  P1 ;
           if( Val <= Info_Ai ( P1 )) {
             P1  =  Fg_Ai ( P1 ) ;
             }
           else
             {
             P1  =  Fd_Ai ( P1 ) ;

           } ;

         } ;
         if( Val <= Info_Ai ( P2 )) {
           Aff_fg_Ai ( P2 , P ) ;
           Aff_pere_Ai ( P , P2 ) ;
           }
         else
           {
           Aff_fd_Ai ( P2 , P ) ;
           Aff_pere_Ai ( P , P2 ) ;

         } ;

       } ;

     } ;

    }
  /*_______________________________INSERTION___________________________________*/
  void Inserer (Pointeur_Ai *A , int *N)
    {
      /** Variables locales **/
      Pointeur_Ai P=NULL;
      Pointeur_Ai R=NULL;
      Pointeur_Ai Q=NULL;

      /** Corps du module **/
     P  =  NULL ;
     Creernoeud_Ai (& P ) ;
     Aff_info_Ai ( P , *N ) ;
     if( *A == NULL) {
       *A  =  P ;
       }
     else
       {
       R  =  *A ;
       while( R != NULL) {
         Q  =  R ;
         if( Info_Ai ( P ) <= Info_Ai ( R )) {
           R  =  Fg_Ai ( R ) ;
           }
         else
           {
           R  =  Fd_Ai ( R ) ;

         } ;

       } ;
       if( Info_Ai ( P ) <= Info_Ai ( Q )) {
         Aff_fg_Ai ( Q , P ) ;
         Aff_pere_Ai ( P , Q ) ;
         }
       else
         {
         Aff_fd_Ai ( Q , P ) ;
         Aff_pere_Ai ( P , Q ) ;

       } ;

     } ;

    }
  /*_____________________________SUIVANT INORDRE________________________________*/
  void Suivant_inordre (Pointeur_Ai *A , Pointeur_Ai *P)
    {
      /** Variables locales **/
      bool Trouv;

      /** Corps du module **/
     Trouv  =  True ;
     *P  =  *A ;
     if( *P != NULL) {
       if( Fd_Ai ( *P ) != NULL) {
         *P  =  Fd_Ai ( *P ) ;
         while( Fg_Ai ( *P ) != NULL) {
           *P  =  Fg_Ai ( *P ) ;

         } ;
         }
       else
         {
         while( ( Pere_Ai ( *P ) != NULL ) && ( Trouv == True )) {
           if( *P == Fd_Ai ( Pere_Ai ( *P ) )) {
             Trouv  =  True ;
             *P  =  Pere_Ai ( *P ) ;
             }
           else
             {
             Trouv  =  False ;

           } ;

         } ;
         *P  =  Pere_Ai ( *P ) ;

       }
     }
    }
  /*_________________________PREMIER POSTORDRE_________________________________*/
  void Premier_postordre (Pointeur_Ai *A , Pointeur_Ai *P)
    {

      /** Corps du module **/
     *P  =  *A ;
     while( ( Fg_Ai ( *P ) != NULL ) || ( Fd_Ai ( *P ) != NULL )) {
       if( Fg_Ai ( *P ) != NULL) {
         *P  =  Fg_Ai ( *P ) ;
         }
       else
         {
         *P  =  Fd_Ai ( *P ) ;

       } ;

     }
    }
  /*___________________________SUIVANT POSTORDRE_________________________________*/
  void Suivant_postordre (Pointeur_Ai *A , Pointeur_Ai *P)
    {
      /** Variables locales **/
      Pointeur_Ai _Px1=NULL;

      /** Corps du module **/
     *P  =  *A ;
     if( Pere_Ai ( *P ) != NULL) {
       if( ( *P == Fd_Ai ( Pere_Ai ( *P ) ) ) || ( Fd_Ai ( Pere_Ai ( *P ) ) == NULL )) {
         *P  =  Pere_Ai ( *P ) ;
         }
       else
         {
         _Px1 =  Fd_Ai ( Pere_Ai ( *P ) ) ;
         Premier_postordre ( &_Px1, & *P ) ;

       } ;
       }
     else
       {
       *P  =  NULL ;

     } ;

    }
  /*___________________________FUSION POSTORDRE**PPOSTORDRE_________________________________*/
  void Fusion_ps_ps (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3)
    {
      /** Variables locales **/
      Pointeur_Ai P=NULL;
      Pointeur_Ai Q=NULL;
      int _Px1;
      int _Px2;
      int _Px3;
      int _Px4;

      /** Corps du module **/
     *A3  =  NULL ;
     Premier_postordre ( & *A1 , & P ) ;
     Premier_postordre ( & *A2 , & Q ) ;
     while( ( ( P != NULL ) && ( Q != NULL ) )) {
       if( Info_Ai ( P ) <= Info_Ai ( Q )) {
         _Px1 =  Info_Ai ( P ) ;
         Inserer ( & *A3 , &_Px1) ;
         Suivant_postordre ( & P , & P ) ;
         }
       else
         {
         _Px2 =  Info_Ai ( Q ) ;
         Inserer ( & *A3 , &_Px2) ;
         Suivant_postordre ( & Q , & Q ) ;

       } ;

     } ;
     if( P != NULL) {
       while( P != NULL) {
         _Px3 =  Info_Ai ( P ) ;
         Inserer ( & *A3 , &_Px3) ;
         Suivant_postordre ( & P , & P ) ;

       } ;
       }
     else
       {
       while( Q != NULL) {
         _Px4 =  Info_Ai ( Q ) ;
         Inserer ( & *A3 , &_Px4) ;
         Suivant_postordre ( & Q , & Q ) ;

       } ;

     } ;

    }
  /*___________________________FUSION PREORDRE**PPREORDRE_________________________________*/
  void Fusion_pr_pr (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3)
    {
      /** Variables locales **/
      Pointeur_Ai P=NULL;
      Pointeur_Ai Q=NULL;
      int _Px1;
      int _Px2;
      int _Px3;
      int _Px4;

      /** Corps du module **/
     *A3  =  NULL ;
     Premier_preordre ( & *A1 , & P ) ;
     Premier_preordre ( & *A2 , & Q ) ;
     while( ( ( P != NULL ) && ( Q != NULL ) )) {
       if( Info_Ai ( P ) <= Info_Ai ( Q )) {
         _Px1 =  Info_Ai ( P ) ;
         Inserer ( & *A3 , &_Px1) ;
         Suivant_preordre ( & P , & P ) ;
         }
       else
         {
         _Px2 =  Info_Ai ( Q ) ;
         Inserer ( & *A3 , &_Px2) ;
         Suivant_preordre ( & Q , & Q ) ;

       } ;

     } ;
     if( P != NULL) {
       while( P != NULL) {
         _Px3 =  Info_Ai ( P ) ;
         Inserer ( & *A3 , &_Px3) ;
         Suivant_preordre ( & P , & P ) ;

       } ;
       }
     else
       {
       while( Q != NULL) {
         _Px4 =  Info_Ai ( Q ) ;
         Inserer ( & *A3 , &_Px4) ;
         Suivant_preordre ( & Q , & Q ) ;

       } ;

     } ;

    }
  /*___________________________FUSION PREORDRE**PPOSTORDRE_________________________________*/
  void Fusion_pr_ps (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3)
    {
      /** Variables locales **/
      Pointeur_Ai P=NULL;
      Pointeur_Ai Q=NULL;
      int _Px1;
      int _Px2;
      int _Px3;
      int _Px4;

      /** Corps du module **/
     *A3  =  NULL ;
     Premier_preordre ( & *A1 , & P ) ;
     Premier_postordre ( & *A2 , & Q ) ;
     while( ( ( P != NULL ) && ( Q != NULL ) )) {
       if( Info_Ai ( P ) <= Info_Ai ( Q )) {
         _Px1 =  Info_Ai ( P ) ;
         Inserer ( & *A3 , &_Px1) ;
         Suivant_preordre ( & P , & P ) ;
         }
       else
         {
         _Px2 =  Info_Ai ( Q ) ;
         Inserer ( & *A3 , &_Px2) ;
         Suivant_postordre ( & Q , & Q ) ;

       } ;

     } ;
     if( P != NULL) {
       while( P != NULL) {
         _Px3 =  Info_Ai ( P ) ;
         Inserer ( & *A3 , &_Px3) ;
         Suivant_preordre ( & P , & P ) ;

       } ;
       }
     else
       {
       while( Q != NULL) {
         _Px4 =  Info_Ai ( Q ) ;
         Inserer ( & *A3 , &_Px4) ;
         Suivant_postordre ( & Q , & Q ) ;

       } ;

     } ;

    }
  /*___________________________FUSION INORDRE**PPOSTORDRE_________________________________*/
  void Fusion_in_ps (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3)
    {
      /** Variables locales **/
      Pointeur_Ai P=NULL;
      Pointeur_Ai Q=NULL;
      int _Px1;
      int _Px2;
      int _Px3;
      int _Px4;

      /** Corps du module **/
     *A3  =  NULL ;
     Premier_inordre ( & *A1 , & P ) ;
     Premier_postordre ( & *A2 , & Q ) ;
     while( ( ( P != NULL ) && ( Q != NULL ) )) {
       if( Info_Ai ( P ) <= Info_Ai ( Q )) {
         _Px1 =  Info_Ai ( P ) ;
         Inserer ( & *A3 , &_Px1) ;
         Suivant_inordre ( & P , & P ) ;
         }
       else
         {
         _Px2 =  Info_Ai ( Q ) ;
         Inserer ( & *A3 , &_Px2) ;
         Suivant_postordre ( & Q , & Q ) ;

       } ;

     } ;
     if( P != NULL) {
       while( P != NULL) {
         _Px3 =  Info_Ai ( P ) ;
         Inserer ( & *A3 , &_Px3) ;
         Suivant_inordre ( & P , & P ) ;

       } ;
       }
     else
       {
       while( Q != NULL) {
         _Px4 =  Info_Ai ( Q ) ;
         Inserer ( & *A3 , &_Px4) ;
         Suivant_postordre ( & Q , & Q ) ;

       } ;

     } ;

    }
  /*___________________________FUSION INORDRE**PPREORDRE_________________________________*/
  void Fusion_in_pr (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3)
    {
      /** Variables locales **/
      Pointeur_Ai P=NULL;
      Pointeur_Ai Q=NULL;
      int _Px1;
      int _Px2;
      int _Px3;
      int _Px4;

      /** Corps du module **/
     *A3  =  NULL ;
     Premier_inordre ( & *A1 , & P ) ;
     Premier_preordre ( & *A2 , & Q ) ;
     while( ( ( P != NULL ) && ( Q != NULL ) )) {
       if( Info_Ai ( P ) <= Info_Ai ( Q )) {
         _Px1 =  Info_Ai ( P ) ;
         Inserer ( & *A3 , &_Px1) ;
         Suivant_inordre ( & P , & P ) ;
         }
       else
         {
         _Px2 =  Info_Ai ( Q ) ;
         Inserer ( & *A3 , &_Px2) ;
         Suivant_preordre ( & Q , & Q ) ;

       } ;

     } ;
     if( P != NULL) {
       while( P != NULL) {
         _Px3 =  Info_Ai ( P ) ;
         Inserer ( & *A3 , &_Px3) ;
         Suivant_inordre ( & P , & P ) ;

       } ;
       }
     else
       {
       while( Q != NULL) {
         _Px4 =  Info_Ai ( Q ) ;
         Inserer ( & *A3 , &_Px4) ;
         Suivant_preordre ( & Q , & Q ) ;

       } ;

     } ;

    }

  int main(int argc, char *argv[])
    {
     srand(time(NULL));
      int m,l,h;
      float pource;
     bool exist,trouve;
    for( J  =  1 ;J <=  50 ; ++J){
       _Px1 =  10000 ;
       Creerarbre ( & A1 , &_Px1) ;
       _Px2 = 10000;
       Creerarbre ( & A2 , &_Px2) ;
       A3  =  NULL ;

       Fusion_in_pr ( & A1 , & A2 , & A3 ) ;
        m = profondeurr(A3);
        exist=arb_strict_binr(A3);
        l=nb_feuiller(A3);
        trouve=arb_completr(A3,&m);
        pource=pourcentage(A3);
        pource=pource*100/20000;
        h=H_min(A3);
printf("\n/********************************************************************************/\n");
      printf("la hauteur maximale lors du parcours inordre_preordre est %d\n",m);
       printf("la hauteur minimale lors du parcours inordre_preordre est%d\n",h);
       printf("le nombre de feuilles apres fusion inordre_preordre %d\n",l);
       printf("le pourcentage d'equilibrage lors du parcours inordre_preordre est %.2f",pource);
        //nb_noeuds(A3);

       A3  =  NULL ;
        Fusion_in_ps ( & A1 , & A2 , & A3 ) ;
        m = profondeurr(A3);
        exist=arb_strict_binr(A3);
        l=nb_feuiller(A3);
        trouve=arb_completr(A3,&m);
        pource=pourcentage(A3);
        pource=pource*100/20000;
        h=H_min(A3);
        printf("/********************************************************************************/\n");
       printf("la hauteur maximale lors du parcours inordre_postordre est %d\n",m);
       printf("la hauteur minimale lors du parcours inordre_postordre est%d\n",h);
       printf("le nombre de feuilles apres fusion inordre_postordre %d\n",l);
       printf("le pourcentage d'equilibrage lors du parcours inordre_postordre est %.2f",pource);
         //nb_noeuds(A3);
       A3  =  NULL ;
       Fusion_pr_pr ( & A1 , & A2 , & A3 ) ;
       m = profondeurr(A3);
        exist=arb_strict_binr(A3);
        l=nb_feuiller(A3);
        trouve=arb_completr(A3,&m);
        pource=pourcentage(A3);
        pource=pource*100/20000;
        h=H_min(A3);
        printf("/********************************************************************************/\n");
     printf("la hauteur maximale lors du parcours preordre_preordre est %d\n",m);
      printf("la hauteur minimale lors du parcours preordre_preordre est%d\n",h);
       printf("le nombre de feuilles apres fusion preordre_preordre %d\n",l);
       printf("le pourcentage d'equilibrage lors du parcours preordre_preordre est %.2f",pource);
       // nb_noeuds(A3);
       A3  =  NULL ;
       Fusion_pr_ps ( & A1 , & A2 , & A3 ) ;
       m = profondeurr(A3);
        exist=arb_strict_binr(A3);
        l=nb_feuiller(A3);
        trouve=arb_completr(A3,&m);
        pource=pourcentage(A3);
        pource=pource*100/20000;
        h=H_min(A3);
        printf("/********************************************************************************/\n");
       printf("la hauteur maximale lors du parcours preordre_postordre est %d\n",m);
       printf("la hauteur minimale lors du parcours preordre_postordre est%d\n",h);
       printf("le nombre de feuilles apres fusion preordre_postordre %d\n",l);
        printf("le pourcentage d'equilibrage lors du parcours preordre_postordre est %.2f",pource);
         //nb_noeuds(A3);
       A3  =  NULL ;
       Fusion_ps_ps ( & A1 , & A2 , & A3 ) ;
       m = profondeurr(A3);
        exist=arb_strict_binr(A3);
        l=nb_feuiller(A3);
        trouve=arb_completr(A3,&m);
        pource=pourcentage(A3);
        pource=pource*100/20000;
        h=H_min(A3);
        printf("/********************************************************************************/\n");
       printf("la hauteur maximale lors du parcours postordre_postordre est %d\n",m);
       printf("la hauteur minimale lors du parcours postordre_postordre est%d\n",h);
       printf("le nombre de feuilles apres fusion postordre_postordre %d\n",l);
        printf("le pourcentage d'equilibrage lors du parcours postordre_postordre est %.2f",pource);
         //nb_noeuds(A3);

       A1  =  NULL ;
       A2  =  NULL ;
     }

      system("PAUSE");
      return 0;
    }
