#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct etudiants
{
    int id;
    char nom[50];
    char prenom[50];
    char date_de_nessance[10];
    char departement[50];
    float note_general;
};

void choisir(int *choix)
{
    printf("\n\n\n\t\t\t MAIN MENU \n\t\t=====================\n");
    printf("\t\t1 - Ajouter un etudiant. \n");
    printf("\t\t2 - Modifier ou supprimer un etudiant. \n");
    printf("\t\t3 - Afficher les details d'un etudiant.\n");
    printf("\t\t4 - Calculer la moyenne generale.\n");
    printf("\t\t5 - Statistiques.\n");
    printf("\t\t6 - Rechercher un etudiant.\n");
    printf("\t\t7 - Trier un etudiant.\n");
    printf("\t\t8 - Quitter\n");
    printf("entrer votre choix : ");
    scanf("%d", choix);
}

void supprimer_ou_modiffier(int *ModdifierSupprimer)
{
    printf("\n\t\t 1- modifier.\n \t\t 2-Supprimer.\n\t\t 3-Retour\n");
    printf("entrer votre choix : ");
    scanf("%d", ModdifierSupprimer);

}
void liste_moddifier()
{
    printf("1-Numero identite \n\t\t 2-Nom \n\t\t 3-Prenom\n\t\t 4-Date de naissance\n\t\t 5-Departement\n\t\t 6-Note general\n");
}
void list_departement(char *departement_choix)
{
    int choix_departement;
    printf("Departement\n");
    printf("1-Biologie\n");
    printf("2-Chimie\n");
    printf("3-Geologie\n");
    printf("4-Informatique\n");
    printf("5-Mathematiques\n");
    printf("6-Physique\n");
    printf("Entrer le departement : ");
    scanf("%d", &choix_departement);
    switch(choix_departement)
    {
    case 1:
        strcpy(departement_choix,"Biologie");
        break;
    case 2:
        strcpy(departement_choix,"Chimie");
        break;
    case 3:
        strcpy(departement_choix,"Geologie");
        break;
    case 4:
        strcpy(departement_choix,"Informatique");
        break;
    case 5:
        strcpy(departement_choix,"Mathematiques");
        break;
    case 6:
        strcpy(departement_choix,"Physique");
        break;
    case 7:
        strcpy(departement_choix,"Humanites");
        break;
    }

}

void liste_statiques()
{
    printf("1-Afficher le nombre total d'étudiants inscrits. \n");
    printf("\t\t 2-Afficher le nombre d'étudiants dans chaque département. \n");
    printf("\t\t 3-Afficher les étudiants ayant une moyenne générale supérieure à un certain seuil. \n");
    printf("\t\t 4-Afficher les 3 étudiants ayant les meilleures notes. \n");
    printf("\t\t 5-Afficher le nombre d'étudiants ayant réussi dans chaque département . \n");
    printf("\t\t 6-Retour.\n");
}

void liste_de_tri(int *tri)
{
    printf("\t\t 1-Tri alphabetique des etudiants en fonction de leur nom.\n");
    printf("\t\t 2-Tri des etudiants par moyenne generale du plus eleve au plus faible. \n");
    printf("\t\t 3-Tri des etudiants selon leur statut de reussite. \n");
    printf("entrer votre choix :  \n");
    scanf("%d", tri);
}

void ajouter_etudiant(struct etudiants etudiant[], int *n)
{
    printf("Entrer les informations de l'etudiant : \n");
    printf("Numero identite : ");
    scanf("%d", &etudiant[*n].id);

    printf("Nom : ");
    scanf(" %[^\n]s", etudiant[*n].nom);

    printf("Prenom : ");
    scanf(" %[^\n]s", etudiant[*n].prenom);

    printf("Date de naissance (dd/mm/yyyy) : ");
    scanf("%s", etudiant[*n].date_de_nessance);

    list_departement(etudiant[*n].departement);

    printf("Note general : ");
    scanf("%f", &etudiant[*n].note_general);

    (*n)++;
    printf("Les informations sont ajoutees avec succes.\n");
}

void modifier(struct etudiants etudiant[], int *n)
{
    int found = 0, id, choix1, new_id;
    char new_nom[50], new_prenom[50], new_date_de_naissance[10], new_departement[50];
    float new_note_general;

    printf("Entrer le numero d'identite de l'etudiant : ");
    scanf("%d", &id);

    for(int i = 0; i < n; i++)
    {
        if (etudiant[i].id == id)
        {
            found = 1;

            printf("Selectioner :\n");
            printf("1-Identite\n");
            printf("2-Nom\n");
            printf("3-Prenom\n");
            printf("4-Date de naissance\n");
            printf("5-Departement\n");
            printf("6-Note general\n");
            printf("Entrer votre choix : ");
            scanf("%d", &choix1);

            switch(choix1)
            {
            case 1:
                printf("Entrer la nouvelle identite : ");
                scanf("%d", &new_id);
                etudiant[i].id = new_id;
                printf("L'identite mise a jour avec succes.\n");
                break;
            case 2:
                printf("Entrer le nouveau nom : ");
                scanf(" %[^\n]s", new_nom);
                strcpy(etudiant[i].nom, new_nom);
                printf("Le nom mis a jour avec succes.\n");
                break;
            case 3:
                printf("Entrer le nouveau prenom : ");
                scanf(" %[^\n]s", new_prenom);
                strcpy(etudiant[i].prenom, new_prenom);
                printf("Le prenom mis a jour avec succes.\n");
                break;
            case 4:
                printf("Entrer la nouvelle date de naissance : ");
                scanf("%s", new_date_de_naissance);
                strcpy(etudiant[i].date_de_nessance, new_date_de_naissance);
                printf("La date de naissance mise a jour avec succes.\n");
                break;
            case 5:
                printf("Selectionner le nouveau departement : \n");
                list_departement(new_departement);
                strcpy(etudiant[i].departement, new_departement);
                printf("Le departement mis a jour avec succes.\n");
                break;
            case 6:
                printf("Entrer la nouvelle note generale : ");
                scanf("%f", &new_note_general);
                etudiant[i].note_general = new_note_general;
                printf("La note generale mise a jour avec succes.\n");
                break;
            default:
                printf("Votre choix est incorrect. Ressayez.\n");
            }
            break;
        }
    }

    if (!found)
        printf("L'etudiant avec l'ID %d n'a pas ete trouve.\n", id);
}

int recherche_etudiant(struct etudiants etudiant[],int id, int n)
{
    for(int i=0; i<n; i++ )
    {
        if (etudiant[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

void supprimer(struct etudiants etudiant[], int *n)
{
    int index,id;
    printf("Entrer identite de l'etudiant à supprimer :  ");
    scanf("%d", &id);
    index = recherche_etudiant(etudiant,id,*n);

    if (index == -1)
    {
        printf("L'etudiant avec l'ID %d n'a pas ete trouve.\n", id);
        return;
    }

    for(int i = index; i < (*n)-1; i++)
    {
        etudiant[i] = etudiant[i+1];
    }
    (*n) --;
    printf("l'etudiant a ete supprime avec success.\n");
}

void affichier_un_etudiants(struct etudiants etudiant[], int n)
{
    int id,index;
    printf("\n\nEntrez l'ID de l'etudiant que vous voulez afficher : ");
    scanf("%d", &id);
    index = recherche_etudiant(etudiant, id, n);
    if(index != -1)
    {
        printf("========================================================================================");
        printf("\n No Identite: %d",etudiant[index].id);
        printf("\n Nom : %s",etudiant[index].nom);
        printf("\nPrenom : %s",etudiant[index].prenom);
        printf("\nDate de naissance : %s",etudiant[index].date_de_nessance);
        printf("\nDepartement : %s",etudiant[index].departement);
        printf("\nNote general: %s",etudiant[index].note_general);
        printf("\n\n=========================================================================================");
    }
}

void moyenne_general(struct etudiants etudiant[], int n)
{
    float somme_des_notes =0, moyenne;
    for(int i=0; i<n; i++)
    {
        somme_des_notes += etudiant[i].note_general;
    }
    moyenne=somme_des_notes/n;
    printf("\n\t La moyenne general est :%.2f\n", moyenne);
}

void moyene_par_departement(struct etudiants etudiant[], int n)
{
    float somme_physique=0, somme_mathematiques=0, somme_informatique=0, somme_geologie=0,somme_chimie=0, somme_biologie=0;
    int physique=0,math=0,info=0,geo=0,chimie=0,bio=0;
    for(int i=0; i<n; i++)
    {
        if (strcasecmp(etudiant[i].departement, "physique") == 0)
        {
            somme_physique += etudiant[i].note_general;
            physique+=1;
        }
        else if (strcasecmp(etudiant[i].departement, "mathematiques" )== 0)
        {
            somme_mathematiques += etudiant[i].note_general;
            math+=1;
        }
        else if (strcasecmp(etudiant[i].departement, "informatique") == 0)
        {
            somme_informatique += etudiant[i].note_general;
            info+=1;
        }
        else if (strcasecmp(etudiant[i].departement, "geologie") == 0)
        {
            somme_geologie += etudiant[i].note_general;
            geo+=1;
        }
        else if (strcasecmp(etudiant[i].departement, "chimie") == 0)
        {
            somme_chimie += etudiant[i].note_general;
            chimie+=1;
        }
        else if (strcasecmp(etudiant[i].departement, "biologie") == 0)
        {
            somme_biologie += etudiant[i].note_general;
            bio+=1;
        }
    }
    printf("\n\tLa moyenne generale de chaque departement est : \n");

    if (physique > 0)
        printf("\n\t\tLa moyenne generale de Physique: %.2f\n", somme_physique / physique);
    else
        printf("\n\t\tAucun etudiant en Physique.\n");

    if (math > 0)
        printf("\n\t\tLa moyenne generale de Mathematiques: %.2f\n", somme_mathematiques / math);
    else
        printf("\n\t\tAucun etudiant en Mathematiques.\n");

    if (info > 0)
        printf("\n\t\tLa moyenne generale de Informatique: %.2f\n", somme_informatique / info);
    else
        printf("\n\t\tAucun etudiant en Informatique.\n");

    if (geo > 0)
        printf("\n\t\tLa moyenne generale de Geologie: %.2f\n", somme_geologie / geo);
    else
        printf("\n\t\tAucun etudiant en Geologie.\n");

    if (chimie > 0)
        printf("\n\t\tLa moyenne generale de Chimie: %.2f\n", somme_chimie / chimie);
    else
        printf("\n\t\tAucun etudiant en Chimie.\n");

    if (bio > 0)
        printf("\n\t\tLa moyenne generale de Biologie: %.2f\n", somme_biologie / bio);
    else
        printf("\n\t\tAucun etudiant en Biologie.\n");
}

void statistique(struct etudiants etudiant[], int n)
{
    int counter = 0;
    int physique=0,math=0,info=0,geo=0,chimie=0,bio=0;
     int physique_reussi = 0, math_reussi = 0, info_reussi = 0, geo_reussi = 0, chimie_reussi = 0, bio_reussi = 0;

//voir tous les etudians inscrits

    for(int i=0; i<n; i++)
    {
        counter += 1;
    }
    printf("\n\tle nombre total d'etudiants inscrits sont : %d\n", counter);
//voir le nombre d'etudiants de cahque departement
    for (int i=0; i<n; i++)
    {
        if (strcasecmp(etudiant[i].departement, "physique") == 0)
        {
            physique+=1;
        }
        else if (strcasecmp(etudiant[i].departement, "mathematiques") == 0)
        {
            math+=1;
        }
        else if (strcasecmp(etudiant[i].departement, "informatique") == 0)
        {
            info+=1;
        }
        else if (strcasecmp(etudiant[i].departement, "geologie") == 0)
        {
            geo+=1;
        }
        else if (strcasecmp(etudiant[i].departement, "chimie") == 0)
        {
            chimie+=1;
        }
        else if (strcasecmp(etudiant[i].departement, "biologie") == 0)
        {
            bio+=1;
        }
    }
    printf("\tLe nombre d'etudiants inscrit dans Biologie sont : %d\n", bio);
    printf("\tLe nombre d'etudiants inscrit dans Chimie sont : %d\n", chimie);
    printf("\tLe nombre d'etudiants inscrit dans Geologie sont : %d\n", geo);
    printf("\tLe nombre d'etudiants inscrit dans Informatique sont : %d\n", info);
    printf("\tLe nombre d'etudiants inscrit dans Mathematiques sont : %d\n", math);
    printf("\tLe nombre d'etudiants inscrit dans Physique sont : %d\n", physique);

//Afficher les étudiants ayant une moyenne générale supérieure à un certain seuil.
    float seuil;
    printf("entrer la seuil : ");
    scanf("%f", &seuil);
    printf("\tles etudiants ayant une moyenne generale superieure a seuil :");
    for (int i=0; i<n; i++)
    {
        if (etudiant[i].note_general>=seuil)
        {
            printf("\n\n No Identite: %d",etudiant[i].id);
            printf("\n Nom : %s",etudiant[i].nom);
            printf("\nPrenom : %s",etudiant[i].prenom);
            printf("\nDate de naissance : %s",etudiant[i].date_de_nessance);
            printf("\nDepartement : %s",etudiant[i].departement);
            printf("\nNote general: %.2f",etudiant[i].note_general);
            printf("\n\n=========================================================================================");
        }
    }
    for (int i = 0; i < n; i++)
    {

        if (strcasecmp(etudiant[i].departement, "physique") == 0)
        {
            if (etudiant[i].note_general >= 10)
                physique_reussi++;
        }
        else if (strcasecmp(etudiant[i].departement, "mathematiques") == 0)
        {
            if (etudiant[i].note_general >= 10)
                math_reussi++;
        }
        else if (strcasecmp(etudiant[i].departement, "informatique") == 0)
        {
            if (etudiant[i].note_general >= 10)
                info_reussi++;
        }
        else if (strcasecmp(etudiant[i].departement, "geologie") == 0)
        {
            if (etudiant[i].note_general >= 10)
                geo_reussi++;
        }
        else if (strcasecmp(etudiant[i].departement, "chimie") == 0)
        {
            if (etudiant[i].note_general >= 10)
                chimie_reussi++;
        }
        else if (strcasecmp(etudiant[i].departement, "biologie") == 0)
        {
            if (etudiant[i].note_general >= 10)
                bio_reussi++;
        }
    }

    printf("\n\tLe nombre d'etudiants inscrit dans Biologie : %d (Reussis : %d)\n", bio, bio_reussi);
    printf("\tLe nombre d'etudiants inscrit dans Chimie : %d (Reussis : %d)\n", chimie, chimie_reussi);
    printf("\tLe nombre d'etudiants inscrit dans Geologie : %d (Reussis : %d)\n", geo, geo_reussi);
    printf("\tLe nombre d'etudiants inscrit dans Informatique : %d (Reussis : %d)\n", info, info_reussi);
    printf("\tLe nombre d'etudiants inscrit dans Mathematiques : %d (Reussis : %d)\n", math, math_reussi);
    printf("\tLe nombre d'etudiants inscrit dans Physique : %d (Reussis : %d)\n", physique, physique_reussi);
}

//Afficher les 3 étudiants ayant les meilleures notes.
void trier_par_note(struct etudiants etudiant[], int n)
{
    struct etudiants temp;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (etudiant[j].note_general < etudiant[j+1].note_general)
            {
                temp = etudiant[j];
                etudiant[j] = etudiant[j+1];
                etudiant[j+1] = temp;
            }
        }
    }
}

// Function to display the top 3 students based on general note
void afficher_top_3(struct etudiants etudiant[], int n)
{
    trier_par_note(etudiant, n);

    printf("\n\t Les 3 etudiants ayant les meilleures notes sont : \n");
    for (int i = 0; i < 3 && i < n; i++)
    {
        printf("========================================================================================\n");
        printf("\tNo Identite: %d\n", etudiant[i].id);
        printf("\tNom : %s\n", etudiant[i].nom);
        printf("\tPrenom : %s\n", etudiant[i].prenom);
        printf("\tDate de naissance : %s\n", etudiant[i].date_de_nessance);
        printf("\tDepartement : %s\n", etudiant[i].departement);
        printf("\tNote generale: %.2f\n", etudiant[i].note_general);
        printf("========================================================================================\n");
    }
}


void rehcerche_par_nom(struct etudiants etudiant[], int n)
{
    char nom[50];
    int found=0;
    printf("entrer le nom d'etudiant : ");
    scanf(" %[^\n]s", nom);
    for (int i=0; i<n; i++)
    {
        found =1;
        if (strcmp(etudiant[i].nom, nom) == 0)
        {
            printf("Resultat trouve : \n");
            printf("========================================================================================\n");
            printf("No Identite: %d\n", etudiant[i].id);
            printf("Nom : %s\n", etudiant[i].nom);
            printf("Prenom : %s\n", etudiant[i].prenom);
            printf("Date de naissance : %s\n", etudiant[i].date_de_nessance);
            printf("Departement : %s\n", etudiant[i].departement);
            printf("Note generale: %.2f\n", etudiant[i].note_general);
            printf("========================================================================================\n");
            break;
        }
        if (!found)
            printf("l'etudiant %s n'est pas trouver.\n", nom);
    }

}

void affichier_les_etudiants(struct etudiants etudiant[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("========================================================================================");
        printf("\n No Identite: %d",etudiant[i].id);
        printf("\nNom : %s",etudiant[i].nom);
        printf("\nPrenom : %s",etudiant[i].prenom);
        printf("\nDate de naissance : %s",etudiant[i].date_de_nessance);
        printf("\nDepartement : %s",etudiant[i].departement);
        printf("\nNote general: %.2f",etudiant[i].note_general);
        printf("\n\n=========================================================================================\n");
    }
}

void afficher_etudiant_par_departement(struct etudiants etudiant[], int n)
{
    char departement_choix[50];
    int found;
    printf("\n==== Afficher les étudiants par département ====\n");
    list_departement(departement_choix);
    printf("\nListe des étudiants inscrits en %s:\n", departement_choix);
    for (int i = 0; i < n; i++)
    {
        if (strcasecmp(etudiant[i].departement, departement_choix) == 0)
        {
            found = 1;

            printf("========================================================================================");
            printf("\n No Identite: %d",etudiant[i].id);
            printf("\n Nom : %s",etudiant[i].nom);
            printf("\nPrenom : %s",etudiant[i].prenom);
            printf("\nDate de naissance : %s",etudiant[i].date_de_nessance);
            printf("\nDepartement : %s",etudiant[i].departement);
            printf("\nNote general: %.2f",etudiant[i].note_general);
            printf("\n\n=========================================================================================");
        }
    }

    if (!found)
    {
        printf("\nAucun étudiant trouvé dans le département %s.\n", departement_choix);
    }

}

void tri_par_nom(struct etudiants etudiant[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcasecmp(etudiant[i].nom, etudiant[j].nom) > 0)
            {
                struct etudiants temp = etudiant[i];
                etudiant[i] = etudiant[j];
                etudiant[j] = temp;
            }
        }
    }
}

void tri_reussite(struct etudiants etudiant[], int n)
{
    struct etudiants temp;
    int found = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (etudiant[i].note_general >= 10 && etudiant[j].note_general >= 10 &&
                    etudiant[i].note_general < etudiant[j].note_general)
            {
                temp = etudiant[i];
                etudiant[i] = etudiant[j];
                etudiant[j] = temp;
            }
        }
    }

    printf("\nLes etudiants ayant une moyenne >= 10 (reussite) sont : \n");
    for (int i = 0; i < n; i++)
    {
        if (etudiant[i].note_general >= 10)
        {
            found = 1;
            printf("========================================================================================\n");
            printf("No Identite: %d\n", etudiant[i].id);
            printf("Nom : %s\n", etudiant[i].nom);
            printf("Prenom : %s\n", etudiant[i].prenom);
            printf("Date de naissance : %s\n", etudiant[i].date_de_nessance);
            printf("Departement : %s\n", etudiant[i].departement);
            printf("Note generale: %.2f\n", etudiant[i].note_general);
            printf("========================================================================================\n");
        }
    }

    if (!found)
    {
        printf("Aucun etudiant avec une note >= 10.\n");
    }
}


void trier_un_etudiant(struct etudiants etudiant[], int n)
{
    int tri,choix;
    liste_de_tri(&tri);
    switch(tri)
    {
    case 1:
        tri_par_nom(etudiant, n);
        printf("\tEtudiants tries par nom :\n");
        affichier_les_etudiants(etudiant, n);
        break;
    case 2:
        trier_par_note(etudiant, n);
        printf("\tEtudiants tries par note generale :\n");
        affichier_les_etudiants(etudiant, n);
        break;
    case 3:
        tri_reussite(etudiant, n);
        break;
    default:
        printf("Choix non disponible.\n");
        break;

    }
}


int main()
{
    int choix, n=0, id, choix_recherche;
    int i;
    struct etudiants etudiant[200];

    do
    {
        choisir(&choix);
        switch(choix)
        {
            int ModdifierSupprimer=0;
        case 1:
            ajouter_etudiant(etudiant, &n);
            break;
        case 2:
            supprimer_ou_modiffier(&ModdifierSupprimer);
            switch(ModdifierSupprimer)
            {
            case 1:
                modifier(etudiant, n);
                break;
            case 2:
                supprimer(etudiant, &n);
                break;
            case 3:
                choisir(&choix);
                break;
            default:
                printf("votre choix n'est pas disponible");
            }
            break;
        case 3:
            affichier_un_etudiants(etudiant, n);
            break;
        case 4:
            moyenne_general(etudiant,n);
            moyene_par_departement(etudiant,n);
            break;
        case 5:
            statistique(etudiant, n);
            afficher_top_3(etudiant, n);
            break;
        case 6:
            printf("Recherche : \n");
            printf("\n\t\t1-Rechercher un etudiant par son nom.\n");
            printf("\n\t\t2-Afficher la liste des etudiants inscrits dans un departement specifique.\n");
            printf("\n\t\t3-Retour.\n");
            printf("Entrer votre choix : ");
            scanf ("%d", &choix_recherche);
            switch (choix_recherche)
            {

            case 1:
                rehcerche_par_nom(etudiant,n);
                break;
            case 2:
                afficher_etudiant_par_departement(etudiant,n);
                break;
            case 3:
                choisir(&choix);
                break;
            default:
                printf("cette choix n'est pas disponible veuillez reessayer");
            }
            break;
        case 7:
            trier_un_etudiant(etudiant, n);
            break;
        case 8:
            printf("\tVous avez quitte.");
            exit(1);
            break;
        default:
            printf("votre choix n'est pas dans la liste.");
            break;
        }
    }
    while(choix!=0);
}

