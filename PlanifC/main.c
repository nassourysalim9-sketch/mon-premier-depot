#include<stdio.h>
/* VARIABLES GLOBALES */
int debut[10] = {8, 10, 13, 15};
int fin[10] = {10, 12, 15, 17};// Apparement le tableau peut rester a 4 l'essentiel est NB_CRENEAUX soit superieur a nb_creneaux
#define NB_CRENEAUX 10

int nb_creneaux = 4;
/* PROTOTYPES */
void afficher_menu_principal(void);
void gestion_creneaux(void);

void afficher_menu_creneaux(void);
void afficher_creneaux(void);
void rechercher_creneaux(void);
void modifier_creneaux(void);
void reinitialiser_creneaux(void);
void ajouter_creneaux(void);
void supprimer_creneaux(void);

int main(){
    int choix = -1;
    do{
        afficher_menu_principal();
        printf("Votre choix : ");
        scanf("%d", &choix);
        switch(choix){
        case 1 :
            gestion_creneaux();
            break;
        case 0 :
            printf("Fin du programme PLANIFC.\n");
            break;
        default :
            printf("Erreur : Choix invalide.\n");
            break;
        }
    }while(choix != 0);
    return 0;
}
void afficher_menu_principal(void){
    printf("\n=====PLANIFC======\n");
    printf("1.Gestion des creneaux\n");
    printf("2.Gestion des seances(non disponible)\n");
    printf("3.Gestion des matieres(non disponible)\n");
    printf("0.Quitter\n");
}
void gestion_creneaux(void){
    int choix = -1;
    do{
        afficher_menu_creneaux();
        printf("Votre choix : ");
        scanf("%d", &choix);
        switch(choix){
        case 1 :
            afficher_creneaux();
            break;
        case 2 :
            rechercher_creneaux();
            break;
        case 3 :
            modifier_creneaux();
            break;
        case 4 :
            reinitialiser_creneaux();
            break;
        case 5 :
            ajouter_creneaux();
            break;
        case 6 :
            supprimer_creneaux();
            break;
        case 0 :
            printf("Retour au menu principal\n");
            break;
        default :
            printf("Choix invalide.\n");
            break;
            }
    }while(choix != 0);
}
    /* MENU SECONDAIRE */

void afficher_menu_creneaux(void){
    printf("\n====GESTION DES CRENEAUX====\n");
    printf("1.Afficher les creneaux\n");
    printf("2.Rechercher un creneau\n");
    printf("3.Modifier un creneau\n");
    printf("4.Reinitialiser les creneaux\n");
    printf("5.Ajouter les creneaux\n");
    printf("6.Supprimer les creneaux\n");
    printf("0.Retour\n");
}

/* FONCTIONS CRENEAUX */

void afficher_creneaux(void){
    printf("\nListe Des Creneaux : \n");
    for(int i = 0; i < NB_CRENEAUX; i++){
            if(debut[i] != 0){
        printf("Creneau %d : %dh - %dh\n", i + 1, debut[i], fin[i]);
            }
    }
}
void rechercher_creneaux(void){
    int numero;
    printf("\nEntrez le numero du creneau(1-%d) : ", NB_CRENEAUX);
    scanf("%d", &numero);

    if(numero < 1 || numero > NB_CRENEAUX){
        printf("Erreur : Numero de creneau invalide.\n");
    }else {
        if(debut[numero - 1] == 0){
            printf("Ce creneau n'existe pas.\n");
            return;
        }
        printf("Creneau %d : %dh - %dh\n", numero, debut[numero - 1], fin[numero - 1]);

    }
}
void modifier_creneaux(void){
    int numero;
    printf("\nEntrez le numero du creneau(1 - %d) : ", NB_CRENEAUX);
    scanf("%d", &numero);

    if(numero < 1 || numero > NB_CRENEAUX){
        printf("Numero de creneau invalide.\n");
    }else{
        if(debut[numero - 1] == 0){
            printf("Ce creneau n'existe pas.\n");
            return;
        }
        int nouvelle_debut, nouvelle_fin;
        printf("Nouvelle heure de debut(ex : 10): ");
        scanf("%d", &nouvelle_debut);

        printf("Nouvelle heure de fin(ex : 12): ");
        scanf("%d", &nouvelle_fin);

        if(nouvelle_debut >= nouvelle_fin){
            printf("Cette plage horraire est incoherente.\n");
            return;
        }
        debut[numero - 1] = nouvelle_debut;
        fin[numero - 1] = nouvelle_fin;
        printf("Creneau %d modifie : %dh - %dh\n", numero, debut[numero - 1], fin[numero - 1]);
    }
}

void reinitialiser_creneaux(void){
    for(int i = 0; i < NB_CRENEAUX; i++){
        debut[i] = 0;
        fin[i] = 0;
    }
    // On remet les valeurs par defaut
    debut[0] = 8;   fin[0] = 10;
    debut[1] = 10;  fin[1] = 12;
    debut[2] = 13;  fin[2] = 15;
    debut[3] = 15;  fin[3] = 17;
    nb_creneaux = 4;
    printf("Les creneaux ont ete reinitialisés.\n");
}
void ajouter_creneaux(void){
    if(nb_creneaux >= NB_CRENEAUX){
        printf("Le nombre de creneau est atteint.\n");
        return;
    }
    int numero;
    printf("Entrez le numero du creneau.\n");
    scanf("%d", &numero);
    if(numero < 1 || numero > NB_CRENEAUX){
        printf("Le numero du creneau n'est pas valide.\n");
        return;
    }
    if(debut[numero - 1] != 0){
        printf("Ce numero de creneau est deja utilisé.\n");
        return;
    }
    int heure_debut;
    int heure_fin;
    printf("Quelle heure pour le debut ?\n");
    scanf("%d", &heure_debut);
    printf("Quelle heure pour la fin ?\n");
    scanf("%d", &heure_fin);
    if(heure_fin <= heure_debut){
        printf("La plage d'horaire n'est pas coherente.\n");
        return;
    }
    debut[numero - 1] = heure_debut;
    fin[numero - 1] = heure_fin;

    nb_creneaux++;

    printf("Le creneau a ete bien ajouté.\n");
}
void supprimer_creneaux(void){
    int numero;
    printf("Entrez le numero de creneau a supprimer.\n");
    scanf("%d", &numero);
    if(nb_creneaux == 0){
        printf("Aucun creneau a supprimer.\n");
        return;
    }
    // Demander numero
    if(numero < 1 || numero > NB_CRENEAUX){
        printf("Le numero n'est pas valide.\n");
        return;
    }
    if(debut[numero-1]== 0){
        printf("Le creneau n'esiste pas.\n");
        return;
    }
    debut[numero - 1] = 0;
    fin[numero - 1] = 0;
    nb_creneaux--;

    printf("Ce creneau a ete supprime.\n");
}

