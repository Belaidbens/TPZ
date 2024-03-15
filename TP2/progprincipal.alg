
   SOIENT
/*_____________________________LES MODULES UTILISéS_______________________*/
       Creerarbre UNE ACTION ;
       Inordre UNE ACTION ;
       Preordre UNE ACTION ;
       Postordre UNE ACTION ;
       Premier_inordre UNE ACTION ;
       Suivant_inordre UNE ACTION ;
       Premier_preordre UNE ACTION ;
       Suivant_preordre UNE ACTION ;
       Premier_postordre UNE ACTION ;
       Suivant_postordre UNE ACTION;
       Inserer UNE ACTION ;
       fusion_ps_ps UNE ACTION;
       fusion_pr_pr UNE ACTION ;
       fusion_pr_ps UNE ACTION ;
       fusion_in_ps UNE ACTION ;
       fusion_in_pr UNE ACTION ;
/*___________________________________ LES DECLARATIONS_______________________*/
       A1 UN ARB DE ENTIER ;
       A2 UN ARB DE ENTIER ;
       A3 UN ARB DE ENTIER ;
       P , Q , P1 , Q1 , P2 DES POINTEURS VERS ARB DE ENTIER ;
       J : ENTIER ;
       Trouv : BOOLEEN ;
 /*_____________________________PROGRAMME PRINCIPAL__________________________*/

   DEBUT



POUR J:=1,10
    APPEL creerarbre(A1,50);
    APPEL  creerarbre(A2,50);
  A3:=NIL;
   APPEL fusion_in_pr(A1,A2,A3);
   A3:=NIL;
   APPEL fusion_in_ps(A1,A2,A3);
   A3:=NIL;
   APPEL fusion_pr_pr(A1,A2,A3);
   A3:=NIL;
   APPEL fusion_pr_ps(A1,A2,A3);
   A3:=NIL;
   APPEL fusion_ps_ps(A1,A2,A3);
    A1:=NIL;
    A2:=NIL;
FPOUR




   FIN
 /*_________________________FIN DU PROGRAMME_________________________________*/


 /*__________________________AFFICHAGE INORDRE_______________________________*/
  ACTION Inordre ( A )
   SOIT
       A UN POINTEUR VERS ARB DE ENTIER ;
      
   DEBUT
       SI A <> NIL
           APPEL Inordre ( FG ( A ) ) ;
           ECRIRE ( INFO ( A ) ) ;
           APPEL Inordre ( FD ( A ) ) ;
          
       FSI ;
      
   FIN

 /*_________________________AFFICHAGE PREORDRE______________________________*/

   ACTION Preordre ( A )
   SOIT
       A UN POINTEUR VERS ARB DE ENTIER ;
      
   DEBUT
       SI A <> NIL
           ECRIRE ( INFO ( A ) ) ;
           APPEL Preordre ( FG ( A ) ) ;
           APPEL Preordre ( FD ( A ) ) ;
          
       FSI ;
      
   FIN

/*___________________________AFFICHAGE POSTORDRE______________________________*/

      ACTION Postordre ( A )
   SOIT
       A UN POINTEUR VERS ARB DE ENTIER ;

   DEBUT
       SI A <> NIL
           APPEL Postordre ( FG ( A ) ) ;
           APPEL Postordre ( FD ( A ) ) ;
           ECRIRE ( INFO ( A ) ) ;
       FSI ;

   FIN
/*_________________________PREMIER INORDRE____________________________________*/

   ACTION Premier_inordre ( A , P )
   SOIENT
       A UN POINTEUR VERS ARB DE ENTIER ;
       P UN POINTEUR VERS ARB DE ENTIER ;
      
   DEBUT
       SI A = NIL
           ;
           P := NIL ;
          
       SINON
           P := A ;
           TANTQUE FG ( P ) <> NIL
               P := FG ( P ) ;
              
           FTQ
       FSI ;
      
   FIN

/*_________________________ PREMIER PREORDRE__________________________________*/

   ACTION Premier_preordre ( A , P )
   SOIT
       A UN POINTEUR VERS ARB DE ENTIER ;
       P UN POINTEUR VERS ARB DE ENTIER ;
      
   DEBUT
       P := A ;
      
   FIN
/*__________________________SUIVANT PREORDRE__________________________________*/
   ACTION Suivant_preordre ( A , P )
   SOIT
       A UN POINTEUR VERS ARB DE ENTIER ;
       P UN POINTEUR VERS ARB DE ENTIER ;
       TROUV : BOOLEEN;
   DEBUT
       TROUV:=VRAI;
       P := A ;
       SI FG ( P ) <> NIL
           P := FG ( P ) ;
          
       SINON
           SI FD ( P ) <> NIL
               P := FD ( P ) ;
              
           SINON
             TANTQUE (PERE(P)<>NIL) ET (TROUV=VRAI)
              SI (P=FD ( PERE ( P ) ) ) OU ( ( FD ( PERE ( P ) ) = NIL ) ET ( PERE ( P ) <> NIL ));
                trouv:=VRAI ;
                   P:= PERE ( P ) ;
              SINON
                trouv:=FAUX;
              FSI;
             FTQ;
               SI PERE(P)=NIL
                P:=NIL ;
               SINON
                SI FD ( PERE ( P ) ) <> NIL
                   P := FD ( PERE ( P ) ) ;
                FSI;
               FSI ;
              
           FSI ;
          
       FSI ;
      
   FIN
/*_______________________________CREER ARBRE__________________________________*/
   ACTION Creerarbre ( A , N )
   SOIENT
       A UN ARB DE ENTIER ;
       P , P1 , P2 DES POINTEURS VERS ARB DE ENTIER ;
       N , Val,I : ENTIER ;
      
   DEBUT
       A := NIL ;
       P := NIL ;
       POUR I := 1 , N
           Val := ALEANOMBRE ( 100 ) ;
           CREERNOEUD ( P ) ;
           AFF_INFO ( P , Val ) ;
           SI ( A = NIL )
               A := P ;
               AFF_PERE ( A , NIL ) ;
              
           SINON
               P1 := A ;
               TQ P1 <> NIL
                   P2 := P1 ;
                   SI Val <= INFO ( P1 )
                       P1 := FG ( P1 ) ;
                      
                   SINON
                       P1 := FD ( P1 ) ;
                      
                   FSI ;
                  
               FTQ ;
               SI Val <= INFO ( P2 )
                   AFF_FG ( P2 , P ) ;
                   AFF_PERE ( P , P2 ) ;
                  
               SINON
                   AFF_FD ( P2 , P ) ;
                   AFF_PERE ( P , P2 ) ;
                  
               FSI ;
              
           FSI ;
          
       FINPOUR ;
      
   FIN
/*_______________________________INSERTION___________________________________*/
   ACTION Inserer ( A , N )
   SOIENT
       A UN POINTEUR VERS ARB DE ENTIER ;
       P UN POINTEUR VERS ARB DE ENTIER ;
       R UN POINTEUR VERS ARB DE ENTIER ;
       Q UN POINTEUR VERS ARB DE ENTIER ;
       N : ENTIER ;
      
   DEBUT
       P := NIL ;
       CREERNOEUD ( P ) ;
       AFF_INFO ( P , N ) ;
       SI A = NIL
           A := P ;
          
       SINON
           R := A ;
           TANTQUE R <> NIL
               Q := R ;
               SI INFO ( P ) <= INFO ( R )
                   R := FG ( R ) ;
                  
               SINON
                   R := FD ( R ) ;
                  
               FSI;
           FTQ ;
        SI INFO ( P ) <= INFO ( Q )
           AFF_FG ( Q , P ) ;
           AFF_PERE ( P , Q ) ;
          
        SINON
           AFF_FD ( Q , P ) ;
           AFF_PERE ( P , Q ) ;
        FSI ;
       FSI;
   FIN

/*_____________________________SUIVANT INORDRE________________________________*/

ACTION Suivant_inordre(A , P)
   SOIENT
     A UN POINTEUR VERS ARB DE ENTIER ;
     P UN POINTEUR VERS ARB DE ENTIER ;
     TROUV :BOOLEEN ;
   DEBUT
     TROUV:=VRAI;
     P:=A ;
     SI P <> NIL
       SI FD(P)<> NIL
         P:=FD(P) ;
         TANTQUE FG(P)<> NIL
          P:=FG(P);
         FTQ ;
       SINON
         TANTQUE (PERE(P)<>NIL) ET (TROUV=VRAI)
          SI  P=FD(PERE(P))
            TROUV:=VRAI ;
            P:=PERE(P);
          SINON
            TROUV:=FAUX;
          FSI;
         FTQ ;
            P:=PERE(P);
       FSI
     FSI
   FIN
/*_________________________PREMIER POSTORDRE_________________________________*/

ACTION Premier_postordre(A , P)
   SOIENT
     A UN POINTEUR VERS ARB DE ENTIER ;
     P UN POINTEUR VERS ARB DE ENTIER ;
   DEBUT
     P:=A;
     TANTQUE (FG(P)<>NIL) OU (FD(P)<>NIL)
      SI FG(P)<>NIL
       P:=FG(P);
      SINON
       P:=FD(P);
      FSI;
     FTQ

   FIN
/*___________________________SUIVANT POSTORDRE_________________________________*/

ACTION Suivant_postordre (A,P)
   SOIENT
     A UN POINTEUR VERS ARB DE ENTIER ;
     P UN POINTEUR VERS ARB DE ENTIER ;
   DEBUT
    P:=A;
   SI PERE(P)<>NIL
    SI (P=FD(PERE(P))) OU (FD(PERE(P))=NIL )
     P:=PERE(P);
    SINON
     APPEL Premier_postordre(FD(PERE(P)),P);
    FSI;
   SINON
    P:=NIL;
   FSI;
   FIN

/*___________________________FUSION POSTORDRE**POSTORDRE_________________________________*/

ACTION fusion_ps_ps(A1,A2,A3)

    SOIENT
     A1 UN POINTEUR VERS ARB DE ENTIER ;
     A2 UN POINTEUR VERS ARB DE ENTIER ;
     A3 UN POINTEUR VERS ARB DE ENTIER ;
     P UN POINTEUR VERS ARB DE ENTIER ;
     Q UN POINTEUR VERS ARB DE ENTIER ;

    DEBUT
     A3:=NIL;
     APPEL Premier_postordre(A1,P);
     APPEL Premier_postordre(A2,Q);

     TANTQUE ((P<>NIL) ET (Q<>NIL) )
      SI INFO(P)<=INFO(Q)
        APPEL Inserer(A3,INFO(P));
        APPEL Suivant_postordre(P,P) ;

      SINON
        APPEL Inserer(A3,INFO(Q));
        APPEL Suivant_postordre(Q,Q) ;

      FSI;
     FTQ;
     SI P<>NIL
      TANTQUE P<>NIL
        APPEL Inserer(A3,INFO(P));
        APPEL Suivant_postordre(P,P) ;
      FTQ ;
     SINON
      TANTQUE Q<>NIL
        APPEL Inserer(A3,INFO(Q));
        APPEL Suivant_postordre(Q,Q) ;
      FTQ;
     FSI;
    FIN

/*___________________________FUSION PREORDRE**PREORDRE_________________________________*/

  ACTION fusion_pr_pr(A1,A2,A3)

    SOIENT
     A1 UN POINTEUR VERS ARB DE ENTIER ;
     A2 UN POINTEUR VERS ARB DE ENTIER ;
     A3 UN POINTEUR VERS ARB DE ENTIER ;
     P UN POINTEUR VERS ARB DE ENTIER ;
     Q UN POINTEUR VERS ARB DE ENTIER ;

    DEBUT
     A3:=NIL;
     APPEL Premier_preordre(A1,P);
     APPEL Premier_preordre(A2,Q);

     TANTQUE ((P<>NIL) ET (Q<>NIL) )
      SI INFO(P)<=INFO(Q)
        APPEL Inserer(A3,INFO(P));
        APPEL Suivant_preordre(P,P) ;

      SINON
        APPEL Inserer(A3,INFO(Q));
        APPEL Suivant_preordre(Q,Q) ;

      FSI;
     FTQ;
     SI P<>NIL
      TANTQUE P<>NIL
        APPEL Inserer(A3,INFO(P));
        APPEL Suivant_preordre(P,P) ;
      FTQ ;
     SINON
      TANTQUE Q<>NIL
        APPEL Inserer(A3,INFO(Q));
        APPEL Suivant_preordre(Q,Q) ;
      FTQ;
     FSI;
    FIN

/*___________________________FUSION PREORDRE**POSTORDRE_________________________________*/

   ACTION fusion_pr_ps(A1,A2,A3)

    SOIENT
     A1 UN POINTEUR VERS ARB DE ENTIER ;
     A2 UN POINTEUR VERS ARB DE ENTIER ;
     A3 UN POINTEUR VERS ARB DE ENTIER ;
     P UN POINTEUR VERS ARB DE ENTIER ;
     Q UN POINTEUR VERS ARB DE ENTIER ;

    DEBUT
     A3:=NIL;
     APPEL Premier_preordre(A1,P);
     APPEL Premier_postordre(A2,Q);

     TANTQUE ((P<>NIL) ET (Q<>NIL) )
      SI INFO(P)<=INFO(Q)
        APPEL Inserer(A3,INFO(P));
        APPEL Suivant_preordre(P,P) ;

      SINON
        APPEL Inserer(A3,INFO(Q));
        APPEL Suivant_postordre(Q,Q) ;

      FSI;
     FTQ;
     SI P<>NIL
      TANTQUE P<>NIL
        APPEL Inserer(A3,INFO(P));
        APPEL Suivant_preordre(P,P) ;
      FTQ ;
     SINON
      TANTQUE Q<>NIL
        APPEL Inserer(A3,INFO(Q));
        APPEL Suivant_postordre(Q,Q) ;
      FTQ;
     FSI;
    FIN

/*___________________________FUSION INORDRE**POSTORDRE_________________________________*/

   ACTION fusion_in_ps(A1,A2,A3)

    SOIENT
     A1 UN POINTEUR VERS ARB DE ENTIER ;
     A2 UN POINTEUR VERS ARB DE ENTIER ;
     A3 UN POINTEUR VERS ARB DE ENTIER ;
     P UN POINTEUR VERS ARB DE ENTIER ;
     Q UN POINTEUR VERS ARB DE ENTIER ;

    DEBUT
     A3:=NIL;
     APPEL Premier_inordre(A1,P);
     APPEL Premier_postordre(A2,Q);

     TANTQUE ((P<>NIL) ET (Q<>NIL) )
      SI INFO(P)<=INFO(Q)
        APPEL Inserer(A3,INFO(P));
        APPEL Suivant_inordre(P,P) ;

      SINON
        APPEL Inserer(A3,INFO(Q));
        APPEL Suivant_postordre(Q,Q) ;

      FSI;
     FTQ;
     SI P<>NIL
      TANTQUE P<>NIL
        APPEL Inserer(A3,INFO(P));
        APPEL Suivant_inordre(P,P) ;
      FTQ ;
     SINON
      TANTQUE Q<>NIL
        APPEL Inserer(A3,INFO(Q));
        APPEL Suivant_postordre(Q,Q) ;
      FTQ;
     FSI;
    FIN

/*___________________________FUSION INORDRE**PREORDRE_________________________________*/

  ACTION fusion_in_pr(A1,A2,A3)

    SOIENT
     A1 UN POINTEUR VERS ARB DE ENTIER ;
     A2 UN POINTEUR VERS ARB DE ENTIER ;
     A3 UN POINTEUR VERS ARB DE ENTIER ;
     P UN POINTEUR VERS ARB DE ENTIER ;
     Q UN POINTEUR VERS ARB DE ENTIER ;

    DEBUT
     A3:=NIL;
     APPEL Premier_inordre(A1,P);
     APPEL Premier_preordre(A2,Q);

     TANTQUE ((P<>NIL) ET (Q<>NIL) )
      SI INFO(P)<=INFO(Q)
        APPEL Inserer(A3,INFO(P));
        APPEL Suivant_inordre(P,P) ;

      SINON
        APPEL Inserer(A3,INFO(Q));
        APPEL Suivant_preordre(Q,Q) ;

      FSI;
     FTQ;
     SI P<>NIL
      TANTQUE P<>NIL
        APPEL Inserer(A3,INFO(P));
        APPEL Suivant_inordre(P,P) ;
      FTQ ;
     SINON
      TANTQUE Q<>NIL
        APPEL Inserer(A3,INFO(Q));
        APPEL Suivant_preordre(Q,Q) ;
      FTQ;
     FSI;
    FIN
