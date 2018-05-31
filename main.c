//Coder- AMAMA DESMOND USHANG

#include <stdio.h> //Bibliotheque pour les entrees et sorties
#include <stdlib.h> //Bibliotheque pour les fonctions
#include <string.h> //Bibliotheque pour les strings

//Structure pour les donnees de la cassette
typedef struct VCassette{
    char cas_nom[25]; //le nom d'un cassette
    int cas_annee; //l'annee de la cassette
    int cas_code; //le code unique de chaque cassette
    int cas_quant; //la quantite de chaque cassette
}Cassette;

//Structure pour les donnees des emprunteurs
typedef struct VEmprunteur{
    char emp_nom[25];//le nom d'un emprunteur
    char emp_prenom[25];//le prenom d'un emprunteur
    char emp_casNom[25];//le nom d'une cassette
    char emp_adresse[35];//l'adresse d'un emprunteur
    int emp_numero;//le numro de telephone d'un emprunteur
}Emprunteur;

//Les prototypes
void ajouterCassette();
void afficherCassette(FILE *pborne);
void ajouterEmprunteur();
void emprunterCassette();
void afficherEmprunteur(FILE *pBorne);
void retourneCassette();
void supprimerEmprunteur();
void quitterPrograme();

//la fonction principal
int main(){
    FILE *pborne = NULL;//Le pointeur qui pointe dans le fichier
    FILE *pBorne = NULL;//Le pointeur qui pointe dans le fichier
    pborne = fopen("ListedesCassette.txt", "r");//Lecture du fichier qui prend des détails d'une cassette dans le mode READ
    pBorne = fopen("DetailsdesEmprunteurs.txt", "r");//Lecture du fichier qui prend des détails d'emprunteur dans le mode READ
    system("color 0b"); //La couleur pour la console
    char choix;
    while(1){
        //Le menu de la programme de reservation
        printf("*********************BIENVENUE AU MON SYSTEME DE RESERVATION*********************\n");
        printf("\n");
        printf("\t\t\ta: AJOUTER UNE NOUVELLE CASSETTE \n");
        printf("\t\t\tb: AFFICHIER LA LISTE DES CASSETTES DISPONIBLE \n");
        printf("\t\t\tc: AJOUTER UN EMPRUNTEUR \n");
        printf("\t\t\td: EMPRUNTER UNE OU DES CASSETTE(s) \n");
        printf("\t\t\te: AFFICHIER LA LISTE DES EMPRUNTEURS \n");
        printf("\t\t\tf: RETOURNE UNE CASSETTE OU PLUSIEURS \n");
        printf("\t\t\tg: SUPPRIMER UN EMPRUNTEUR OU PLUSIEURS \n");
        printf("\t\t\th: QUITTER LE PROGRAM \n");
        printf("\n\n");
        printf("Faites votre choix: \n");
        scanf("%c", &choix);
    switch (choix){
    case 'a':
        ajouterCassette();
        break;
    case 'b':
        afficherCassette(pborne);
        break;
    case 'c':
        ajouterEmprunteur();
        break;
    case 'd':
        emprunterCassette();
        break;
    case 'e':
        afficherEmprunteur(pBorne);
        break;
    case 'f':
        retourneCassette();
        break;
    case 'g':
        supprimerEmprunteur();
        break;
    case 'h':
        quitterPrograme();
        break;
    }
    return 0;
    }
}

//Fonction pour ajouter une cassette video
void ajouterCassette(){
    FILE *pborne = NULL; //Le pointeur qui pointe dans le fichier
    Cassette vcas; //Reference pour le structure de la cassette
    pborne = fopen("ListedesCassette.txt", "a+"); //Création du fichier qui prend des détails d'une cassette dans mode APPEND
    if(pborne != NULL){
        printf("Entrer le nom de la cassette: \n"); //L'entrer d'un nom d'une cassette
        scanf("%s", &vcas.cas_nom);
        printf("Entrer l'annee de production de la cassette: \n"); //L'entrer de l'annee de la cassette
        scanf("%d", &vcas.cas_annee);
        printf("Entrer une code unique pour ce cassette: \n"); //Un code specifier à une cassette
        scanf("%d", &vcas.cas_code);
        printf("Entrer la quantite de cette cassette: \n"); //La quantite de la cassette
        scanf("%d", &vcas.cas_quant);
        fprintf(pborne,"%-10s%-10d%-10d%d\n", vcas.cas_nom, vcas.cas_annee, vcas.cas_code, vcas.cas_quant);// Pour ecrire les détails dans le fichier
        printf("LA CASSETTE EST ENREGISTRE! \n\n");//Message de confirmation
        fclose(pborne); //pour fermer le fichier qui a été ouvert
    }else{
        printf("LA CASSETTE NE PEUX PAS AJOUTER! \n\n");//Message d'erreur
    }

}

//Fonction pour affichier des cassettes qui sont disponible sur le console
void afficherCassette(FILE *pborne){
    char chaine[100];
    printf("VOICI LES CASSETTES VIDEO QUI SONT DISPONIBLE \n\n");
    while(fgets(chaine,100,pborne)!=NULL){
        printf("%s", chaine);
    }
    fclose(pborne);//pour fermer le fichier qui a été ouvert

}

//Fonction pour ajouter un emprunteur qui veut une cassette
void ajouterEmprunteur(){
    FILE *pBorne = NULL;//Le pointeur qui pointe dans le fichier
    Emprunteur emp;//Reference pour le structure de l'emprunteur
    pBorne = fopen("DetailsdesEmprunteurs.txt", "a+c");//Création du fichier qui prend des détails d'un emprunteur dans mode APPEND
    FILE *pborne = NULL;//Le pointeur qui pointe dans le fichier
    char emp_casNom[25];
    char cas_nom[25];
    Cassette vcas; //Reference pour le structure de la cassette
    pborne = fopen("ListedesCassette.txt", "r"); //Ouvrir le fichier pour lecture
    if(pBorne != NULL){
        printf("Entrer le nom d'emprunteur: \n"); //L'entrer du nom d'un emprunteur d'une cassette
        scanf("%s", &emp.emp_nom);
        printf("Entrer le prenom d'emprunteur: \n"); //L'entrer du prenom d'un emprunteur d'une cassette
        scanf("%s", &emp.emp_prenom);
        printf("Entrer le nom de la cassette: \n"); //Le nom specifique d'une cassette
        scanf("%s", &emp.emp_casNom);
        pborne = fopen("ListedesCassette.txt", "r"); //Ouvrir le fichier pour lecture
        char t[100];
        int found = 0;
        while(!feof(pborne)){ //La boucle pour verifier si la cassette exacte existe
            fscanf(pborne, "%s", &t);
            if(strcmp(t, emp.emp_casNom) == 0){
                    found = 1;
                    break;
            }
            fscanf(pborne, "%s", &t);
            fscanf(pborne, "%s", &t);
            fscanf(pborne, "%s", &t);
        }

        if(found == 1){
            printf("LA CASSETTE DEMANDE EST DISPONIBLE \n");

            printf("Entrer l'adresse de l'emprunteur: \n"); //L'adresse d'un emprunteur
            scanf("%s", &emp.emp_adresse);
            printf("Entrer le numero de telephone de l'emprunteur: \n"); //Le numero de téléphone d'un emprunteur
            scanf("%d", &emp.emp_numero);
            fprintf(pBorne,"%-10s%-10s%-10s%-10s%d \n", emp.emp_nom,emp.emp_prenom, emp.emp_casNom, emp.emp_adresse, emp.emp_numero);// Pour ecrire les détails dans le fichier
            printf("CETTE EMPRUNTEUR EST ENREGISTRE! :)\n");//Message de confirmation
        }
        else{
            printf("LA CASSETTE DEMANDE N'EST PAS DISPONIBLE\n"); //Message d'erreur
            printf("LE PROGRAM VA SE TERMINER.\n");

            system("PAUSE");

        }


    }

     fclose(pBorne); //pour fermer le fichier qui a été ouvert
}

//Fonction qui permet un emprunteur à emprunter un ou plusieurs cassette(s)
void emprunterCassette(){
    FILE *pborne = NULL;//Le pointeur qui pointe dans le fichier
    pborne = fopen("ListedesCassette.txt", "r");//Lecture du fichier qui prend des détails d'une cassette dans le mode READ
    Cassette vcas;//Reference pour le structure de la cassette

    if(pborne != NULL){
        printf("Entrer le nom de la cassette: \n");//L'entrer du nom d'un emprunteur d'une cassette
        scanf("%s", &vcas.cas_nom);

        pborne = fopen("ListedesCassette.txt", "r");
        char t[100];
        int found = 0;
        while(!feof(pborne)){ //La boucle pour verifier si la cassette exacte existe
            fscanf(pborne, "%s", &t);
            if(strcmp(t, vcas.cas_nom) == 0)
                    found = 1;

                    break;

            fscanf(pborne, "%s", &t);
            fscanf(pborne, "%s", &t);
            fscanf(pborne, "%s", &t);
        }

        if(found == 1){
            printf("TROUVE :)\n");
            printf("Entrer la quantite de la cassette vous voulez: \n"); //Apres on teste pour le nom de la cassette on verifie la quantite disponible avec la quantite demander
            scanf("%d", &vcas.cas_quant);

            char n[20];
            int num;

            fscanf(pborne, "%s", &n);
            fscanf(pborne, "%s", &n);
            fscanf(pborne, "%d", &num);

            if(vcas.cas_quant > num){
                printf("LA QUANTITE DEMANDER EST SUPERIEURE QUE LA QUANTITE DISPONIBLE\n"); //Cas d'erreur
            }
            else if(vcas.cas_quant <= 0){
                printf("LA QUANTITE DEMANDER EST INFERIEURE\n"); //Cas d'erreur
            }
            else{
                num = num - vcas.cas_quant;
                printf(" VOUS VOULEZ %d CASSETTES & LA QUANTITE RESTANT = %d\n", vcas.cas_quant, num);

                pborne = fopen("ListedesCassette.txt", "r");
                FILE* tmp = fopen("tmp.txt", "w");
                char k[100];
                while(!feof(pborne)){ //La boucle pour faire la calculation et le mis a jours de la quantite
                    fscanf(pborne, "%s", &k);

                    fprintf(tmp, "%-10s", k);
                    if(strcmp(k, vcas.cas_nom) == 0){

                            fscanf(pborne, "%s", &k);
                            fprintf(tmp, "%-10s", k);
                            fscanf(pborne, "%s", &k);
                            fprintf(tmp, "%-10s", k);

                            fscanf(pborne, "%s", &k);
                            fprintf(tmp, "%d\n", num);

                            if(feof(pborne)){
                            	break;
							}
                    }
                    else{
                        fscanf(pborne, "%s", &k);
                        fprintf(tmp, "%-10s", k);
                        fscanf(pborne, "%s", &k);
                        fprintf(tmp, "%-10s", k);
                        fscanf(pborne, "%s", &k);
                        fprintf(tmp, "%-10s\n", k);

                        if(feof(pborne)){
                            	break;
						}
                    }
                }

                system("PAUSE");

                pborne = fopen("ListedesCassette.txt", "w"); //Ecriture dans le fichier pour
                fclose(tmp);
                tmp = fopen("tmp.txt", "r"); //Ouvrir le fichier temporaire pour lecture

                while(!feof(tmp)){
                    fscanf(tmp, "%s", &k);
                    fprintf(pborne, "%-10s", k);
                    fscanf(tmp, "%s", &k);
                    fprintf(pborne, "%-10s", k);
                    fscanf(tmp, "%s", &k);
                    fprintf(pborne, "%-10s", k);
                    fscanf(tmp, "%s", &k);
                    fprintf(pborne, "%-10s\n", k);
                }
                printf("ON A FAIT UN MIS A JOURS AU FICHIER APRES VOTRE ACTION. MERCI POUR LA VISITE\n"); //Message de confirmer que tous les mis a jours c'etait possible

            }
        }
        else{
            printf("NON TROUVE\n");
        }

        /*THE QUANTITY OF CASSETTE THE BORROWER WANTS WOULD BE SUBTRACTED FROM QUANTITY OF THE CASSETTE AVAILABLE IN THE FILE AND KEEP
        RECORD OF THE NEW VALUE IN THE FILE*/
    }else{
        printf("LA CASSETTE NE PEUX PAS EMPRUNTER \n");//Message d'erreur
    }

    fclose(pborne);//pour fermer le fichier qui a été ouvert
}

//Fonction pour affichier des emprunteurs sur le console
void afficherEmprunteur(FILE *pBorne){
    char chaine[100];
    printf("CECI LES EMPRUNTEURS \n\n");
    while(fgets(chaine,100,pBorne)!=NULL){
        printf("%s", chaine);
    }
    fclose(pBorne);//pour fermer le fichier qui a été ouvert

}

//Fonction qui prendre compte quand un emprunteur retourne un ou des cassette(s)
void retourneCassette(){
    FILE *pborne = NULL;//Le pointeur qui pointe dans le fichier
    pborne = fopen("ListedesCassette.txt", "r");//Lecture du fichier qui contient les cassettes dans le mode READ
    Cassette vcas;//Reference pour le structure de la cassette

    if(pborne != NULL){
        printf("Entrer le nom de la cassette: \n");
        scanf("%s", &vcas.cas_nom);

        pborne = fopen("ListedesCassette.txt", "r");
        char t[100];
        int found = 0;
        while(!feof(pborne)){
            fscanf(pborne, "%s", &t);
            if(strcmp(t, vcas.cas_nom) == 0){
                    found = 1;

                    break;
            }
            fscanf(pborne, "%s", &t);
            fscanf(pborne, "%s", &t);
            fscanf(pborne, "%s", &t);
        }

        if(found == 1){
            printf("TROUVE \n");
            printf("Entrer la quantite a retourner: \n");
            scanf("%d", &vcas.cas_quant);

            char n[20];
            int num;

            fscanf(pborne, "%s", &n);
            fscanf(pborne, "%s", &n);
            fscanf(pborne, "%d", &num);

            if(vcas.cas_quant <= 0){
                printf("LA QUANTITE DEMANDER EST INFERIEURE\n");
            }
            else{
                num = num + vcas.cas_quant;
                printf("VOUS VOULEZ RETOURNER %d CASSETTES & LA QUANTITE DISPONIBLE MAINTENANT DEVIENT = %d\n", vcas.cas_quant, num);
                printf("MERCI DE RETOURNER LA CASSETTE ;)\n");
                pborne = fopen("ListedesCassette.txt", "r");
                FILE* tmp = fopen("tmp.txt", "w");
                char k[100];
                while(!feof(pborne)){
                    fscanf(pborne, "%s", &k);

                    fprintf(tmp, "%-10s", k);
                    if(strcmp(k, vcas.cas_nom) == 0){

                            fscanf(pborne, "%s", &k);
                            fprintf(tmp, "%-10s", k);
                            fscanf(pborne, "%s", &k);
                            fprintf(tmp, "%-10s", k);

                            fscanf(pborne, "%s", &k);
                            fprintf(tmp, "%d\n", num);

                            if(feof(pborne)){
                            	break;
							}
                    }
                    else{
                        fscanf(pborne, "%s", &k);
                        fprintf(tmp, "%-10s", k);
                        fscanf(pborne, "%s", &k);
                        fprintf(tmp, "%-10s", k);
                        fscanf(pborne, "%s", &k);
                        fprintf(tmp, "%-10s\n", k);

                        if(feof(pborne)){
                            	break;
						}
                    }
                }

                system("PAUSE");

                pborne = fopen("ListedesCassette.txt", "w");
                fclose(tmp);
                tmp = fopen("tmp.txt", "r");

                while(!feof(tmp)){
                    fscanf(tmp, "%s", &k);
                    fprintf(pborne, "%-10s", k);
                    fscanf(tmp, "%s", &k);
                    fprintf(pborne, "%-10s", k);
                    fscanf(tmp, "%s", &k);
                    fprintf(pborne, "%-10s", k);
                    fscanf(tmp, "%s", &k);
                    fprintf(pborne, "%-10s\n", k);
                }
                 printf("ON A FAIT UN MIS A JOURS AU FICHIER APRES VOTRE ACTION. MERCI POUR LA VISITE\n"); //Message de confirmer que tous les mis a jours c'etait possible

            }
        }
        else{
            printf("NON TROUVE\n");
        }

    }else{
        printf("LA CASSETTE NE PEUX PAS EMPRUNTER \n");//Message d'erreur
    }

    fclose(pborne);//pour fermer le fichier qui a été ouvert




}

//Fonction pour supprimer un emprunteur avec son details apres retouner la cassette emprunter
void supprimerEmprunteur(){
    FILE *pBorne = NULL;//Le pointeur qui pointe dans le fichier
    pBorne = fopen("DetailsdesEmprunteurs.txt", "r");//Lecture du fichier qui prend des détails d'une cassette dans le mode READ
    Emprunteur emp;//Reference pour le structure de la cassette

    if(pBorne != NULL){
        printf("Entrer le nom de l'emprunteur: \n");
        scanf("%s", &emp.emp_nom);

        pBorne = fopen("DetailsdesEmprunteurs.txt", "r");
        FILE* tmp = fopen("tmp.txt", "w");
        char t[100];
        while(!feof(pBorne)){
            fscanf(pBorne, "%s", &t);
            if(strcmp(t, emp.emp_nom) == 0){
                    fscanf(pBorne, "%s", &t);
                    fscanf(pBorne, "%s", &t);
                    fscanf(pBorne, "%s", &t);
                    fscanf(pBorne, "%s", &t);
                    break;
            }
            else{
                fprintf(tmp, "%-10s", t);
                fscanf(pBorne, "%s", &t);
                fprintf(tmp, "%-10s", t);
                fscanf(pBorne, "%s", &t);
                fprintf(tmp, "%-10s", t);
                fscanf(pBorne, "%s", &t);
                fprintf(tmp, "%-10s", t);
                fscanf(pBorne, "%s", &t);
                fprintf(tmp, "%-10s\n", t);
            }

        }
        pBorne = fopen("DetailsdesEmprunteurs.txt", "w");
        fclose(tmp);
        tmp = fopen("tmp.txt", "r");
        while(!feof(tmp)){
            fscanf(tmp, "%s", &t);
            fprintf(pBorne, "%-10s", t);
            fscanf(tmp, "%s", &t);
            fprintf(pBorne, "%-10s", t);
            fscanf(tmp, "%s", &t);
            fprintf(pBorne, "%-10s", t);
            fscanf(tmp, "%s", &t);
            fprintf(pBorne, "%-10s", t);
            fscanf(tmp, "%s", &t);
            fprintf(pBorne, "%-10s\n", t);
        }

         printf("CET EMPRUNTEUR A ETAIT SUPPRIMER \n");
    }else{
        printf("IMPOSSIBLE DE SUPPRIMER CAR CET EMPRUNTEUR N'EXISTE PAS\n");//Message d'erreur
    }

    fclose(pBorne);//pour fermer le fichier qui a été ouvert
}

void quitterPrograme(){
    printf("LE PROGRAM VA QUITTER MAINTENANT. AU VOIR \n");
    return 0;
}
