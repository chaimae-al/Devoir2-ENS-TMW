#include "headerdev.h"

void mainMenu()
{
        printf("|                        Bienvenu                      |\n");
        printf("--------------------------------------------------------\n");
        printf("|   Veuillez choisir une des operations suivantes:     |\n");
        printf("--------------------------------------------------------\n");
        MainChoix();

}
void MainChoix()
{
    printf("|\t  1. Afficher la liste des employes            |\n");
    printf("|\t  2. Ajouter un nouveau employe                |\n");
    printf("|\t  3. Supprimer un employe \n");
    printf("\t\t     1. Supprimer un employe avec son code\n");
    printf("\t\t     2. Supprimer un employe avec son nom\n");
    printf("|\t  4. Rechercher un employe par son code        | \n");
    printf("\t\t     1. Rechercher un employe par son code   \n");
    printf("\t\t     2. Rechercher un employe son nom\n");
    printf("\t\t     3. Rechercher un employe son prenom\n");
    printf("|\t  5.  Modification                              |\n");
    printf("|\t  6.  afficher Menu                             |\n");
    printf("|\t  7.  Quitter                                   |\n");
}

struct listEmp* initiList()
{
  struct listEmp *list  = malloc(sizeof(struct listEmp));
  list->head = NULL;

  return list;

};

int estVide(struct listEmp* list)
{
     return list->head == NULL;
}

void afficherList(struct listEmp* list)
{
    if(estVide(list))
    {
        printf("la liste est vide. \n");
        return;
    }

    struct elemntsEmp* it =  list->head;
    while(it != NULL)
    {
        printf("%d %s %s %d/%d/%d %s %.2f\n",
               it->data.code,it->data.nom,it->data.prenom,it->data.dateNaissance.jour,
               it->data.dateNaissance.mois,it->data.dateNaissance.annee,
               it->data.titrePoste,it->data.salaire);
        it = it->next;
    }
    printf("\n");
}

int employeExiste(struct listEmp* list, int codeEmploye)
{
    if (estVide(list))
    {
        return 0; // La liste est vide, donc l'employé n'existe pas
    }

    struct elemntsEmp* it = list->head;
    while (it != NULL)
    {
        if (it->data.code == codeEmploye)
        {
            return 1; // L'employé avec le code spécifié a été trouvé
        }
        it = it->next;
    }

    return 0; // Aucun employé avec le code spécifié n'a été trouvé
}


void afficherEmployeParCode(struct listEmp* list, int codeEmploye)
{
    if (estVide(list))
    {
        printf("La liste est vide. Aucun employe a afficher.\n");
        return;
    }

    struct elemntsEmp* it = list->head;
    while (it != NULL)
    {
        if (it->data.code == codeEmploye)
        {
            printf("%d %s %s %d/%d/%d %s %.2f\n",
                   it->data.code, it->data.nom, it->data.prenom,it->data.dateNaissance.jour,
               it->data.dateNaissance.mois,it->data.dateNaissance.annee,
                   it->data.titrePoste, it->data.salaire);
            return; 
        }
        it = it->next;
    }

    printf("Aucun employe avec le code %d n'a ete trouve.\n", codeEmploye);
}

void afficherEmployeParNom(struct listEmp* list, char nomEmploye[])
{
    if (estVide(list))
    {
        printf("La liste est vide. Aucun employe a afficher.\n");
        return;
    }
    int found =0;
    struct elemntsEmp* it = list->head;
    while (it != NULL)
    {
        if (strcmp(it->data.nom, nomEmploye) == 0)
        {
            printf("%d %s %s %d/%d/%d %s %.2f\n",
                   it->data.code, it->data.nom, it->data.prenom,it->data.dateNaissance.jour,
               it->data.dateNaissance.mois,it->data.dateNaissance.annee,
                   it->data.titrePoste, it->data.salaire);
            found = 1;
        }
        it = it->next;
    }
     if(!found)
    {
    printf("Aucun employe avec le nom %s n'a ete trouve.\n", nomEmploye);
    }
}

void afficherEmployeParPrenom(struct listEmp* list, char prenomEmploye[])
{
    if (estVide(list))
    {
        printf("La liste est vide. Aucun employe a afficher.\n");
        return;
    }

    struct elemntsEmp* it = list->head;
    int found = 0;
    while (it != NULL)
    {
        if (strcmp(it->data.prenom, prenomEmploye) == 0)
        {
            printf("%d %s %s %d/%d/%d %s %.2f\n",
                   it->data.code, it->data.nom, it->data.prenom,it->data.dateNaissance.jour,
               it->data.dateNaissance.mois,it->data.dateNaissance.annee,
                   it->data.titrePoste, it->data.salaire);
                found = 1;
        }
        it = it->next;
    }
    if(!found)
    {
     printf("Aucun employe avec le prenom %s n'a ete trouve.\n", prenomEmploye);

    }

}

void ajouterEmploye(struct listEmp* list,struct employe emp)
{
    struct elemntsEmp*  nouveau = malloc(sizeof(struct elemntsEmp));
    nouveau->data = emp;
    nouveau->next = NULL;

    if(list->head == NULL)
    {
        list->head = nouveau;
    }
    else
    {
        struct elemntsEmp* it =  list->head;
        while(it->next != NULL)
        {
            it = it->next;
        }
         it->next = nouveau;
    }

}
void supprimerEmployeParCode(struct listEmp* list, int codeEmploye)
{
    if (estVide(list))
    {
        printf("La liste est vide, impossible de supprimer.\n");
        return;
    }

    struct elemntsEmp* current = list->head;
    struct elemntsEmp* previous = NULL;

    while (current != NULL)
    {
        if (current->data.code == codeEmploye)
        {
            if (previous == NULL)
            {
                // Case where the employee to delete is at the beginning of the list
                list->head = current->next;
            }
            else
            {
                // Case where the employee to delete is inside the list
                previous->next = current->next;
            }

            free(current); // Free the memory of the node to be deleted
            printf("Employe avec le code %d supprime avec succes.\n", codeEmploye);
            return;
        }

        previous = current;
        current = current->next;
    }

    printf("Aucun employe avec le code %d n'a ete trouve.\n", codeEmploye);
}


void saisieCode(struct listEmp* list, struct employe* nouveauEmploye)
{
	do
    {
        printf("Code : ");
        scanf("%d", &nouveauEmploye->code);

        if (!estUnique(list, nouveauEmploye->code))
        {
            printf("Le code existe deja. Veuillez entrer un code unique.\n");
        }

    } while (!estUnique(list, nouveauEmploye->code));
}
void saisieDateN(struct listEmp* list, struct employe* nouveauEmploye)
{
    printf("date naissance : \n");
	do
    {
        printf(" jour : ");
        scanf("%d",&nouveauEmploye->dateNaissance.jour);

        if (nouveauEmploye->dateNaissance.jour < 1 || nouveauEmploye->dateNaissance.jour > 31)
        {
            printf("Le jour de naissance doit �tre entre 1 et 31. Veuillez reessayer.\n");
        }

    }while (nouveauEmploye->dateNaissance.jour < 1 || nouveauEmploye->dateNaissance.jour > 31);

    do
    {
        printf(" mois  : ");
        scanf("%d",&nouveauEmploye->dateNaissance.mois);

        if (nouveauEmploye->dateNaissance.mois < 1 || nouveauEmploye->dateNaissance.mois > 12)
        {
            printf("Le mois doit etre entre 1 et 12. Veuillez reessayer.\n");
        }

    } while (nouveauEmploye->dateNaissance.mois < 1 || nouveauEmploye->dateNaissance.mois > 12);


     do
    {
       printf(" annee  : ");
        scanf("%d",&nouveauEmploye->dateNaissance.annee);

        if (nouveauEmploye->dateNaissance.annee > 2024)
        {
            printf("l'annee saisie est incorrecte . Veuillez reessayer.\n");
        }

    } while (nouveauEmploye->dateNaissance.annee > 2024);

}
void saisiePoste(struct listEmp* list, struct employe* nouveauEmploye)
{
    printf("les postes qui existent sont :  \n -- President -- VP-Sales -- VP-Marketing -- Sales-Manager --  Sales-Rep \n ");
    do
    {
        printf("Titre du poste : ");
        scanf("%s",nouveauEmploye->titrePoste);

        if(strcmp(nouveauEmploye->titrePoste, "President") != 0 && strcmp(nouveauEmploye->titrePoste, "VP-Sales") != 0 &&
        strcmp(nouveauEmploye->titrePoste, "Sales-Manager ") != 0  && strcmp(nouveauEmploye->titrePoste, "Sales-Rep")!= 0 &&
        strcmp(nouveauEmploye->titrePoste, "VP-Marketing")!= 0 )
        {
             printf("le poste que vous avez entrer est invalide. \n");
        }

    }while(strcmp(nouveauEmploye->titrePoste, "President") != 0 && strcmp(nouveauEmploye->titrePoste, "VP-Sales") != 0 &&
        strcmp(nouveauEmploye->titrePoste, "Sales-Manager ") != 0  && strcmp(nouveauEmploye->titrePoste, "Sales-Rep")!= 0 &&
        strcmp(nouveauEmploye->titrePoste, "VP-Marketing")!= 0  );

}
void saisieNom(struct listEmp* list, struct employe* nouveauEmploye)
{
    printf("Nom : ");
    scanf("%s", nouveauEmploye->nom);
}
void saisiePrenom(struct listEmp* list, struct employe* nouveauEmploye)
{
    printf("Prenom : ");
    scanf("%s", nouveauEmploye->prenom);
}
void saisieSalaire(struct listEmp* list, struct employe* nouveauEmploye)
{
    do
    {
       printf("Salaire : ");
        scanf("%f",&nouveauEmploye->salaire);

        if (nouveauEmploye->salaire < 0)
        {
            printf("le salaire  saisie est incorrecte . Veuillez r�essayer.\n");
        }

    } while (nouveauEmploye->salaire < 0);
}

void saisieInfo(struct listEmp* list, struct employe* nouveauEmploye)
{

    saisieCode(list, nouveauEmploye);
    saisieNom(list,nouveauEmploye);
    saisiePrenom(list,nouveauEmploye);
    saisieDateN(list,nouveauEmploye);
    saisieSalaire(list,nouveauEmploye);
    saisiePoste(list,nouveauEmploye);
    ajouterEmploye(list, *nouveauEmploye);
    printf("employe ajoute avec succes \n");
}
bool estUnique(struct listEmp* list, int codeV)
{
    struct elemntsEmp* it = list->head;
     while (it != NULL)
    {
        if (it->data.code == codeV)
        {
            return false;
        }
        it = it->next;
    }
    return true;
}

void modificationEmp(struct listEmp* list, int codeEmploye)
{
    int found = 0;
    char res[10];
    if (estVide(list))
    {
        printf("La liste est vide. Aucun employe a afficher.\n");
        return;
    }

    struct elemntsEmp* it = list->head;
    while (it != NULL)
    {
        if (it->data.code == codeEmploye)
        {
            afficherEmployeParCode(list,codeEmploye);
            printf("qu'est ce vous voullez modifier ? ");
            printf("-- Nom -- Prenom -- Poste --  Salaire  -- DateNaiss :   ");
            scanf("%s",res);
             if(strcmp(res, "Nom") == 0)
            {
                saisieNom(list,&(it->data));
                printf("nom modifie avec succes \n");
            }
             if(strcmp(res, "Prenom") == 0)
            {
                saisiePrenom(list,&(it->data));
                printf("prenom modifie avec succes\n");
            }
            if(strcmp(res, "Poste") == 0)
            {
                saisiePoste(list,&(it->data));
                printf("poste modifie avec succes \n");
            }
            if(strcmp(res, "Salaire") == 0)
            {
                saisieSalaire(list,&(it->data));
                printf("salaire modifie avec succes \n");
            }
            if(strcmp(res, "DateNaiss") == 0)
            {
                saisieDateN(list,&(it->data));
                printf("date naissance modifiee avec succes \n");
            }

            return;
        }
        it = it->next;
    }

    printf("Aucun employe avec le code %d n'a ete trouve.\n", codeEmploye);
}
void sauvegarderListeDansFichier(struct listEmp* list, const char* fileName)
{
    FILE* fichier = fopen(fileName, "w");

    if (fichier == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier %s\n", fileName);
        return;
    }

    struct elemntsEmp* it = list->head;

    while (it != NULL)
    {
        fprintf(fichier, "%d %s %s %d/%d/%d %s %.2f\n",
                it->data.code, it->data.nom, it->data.prenom, it->data.dateNaissance.jour,
                it->data.dateNaissance.mois, it->data.dateNaissance.annee,
                it->data.titrePoste, it->data.salaire);
        it = it->next;
    }

    fclose(fichier);
    printf("Liste sauvegardee dans le fichier %s avec succes.\n", fileName);
}

void chargerListeDepuisFichier(struct listEmp* list, const char* fileName)
{
    FILE* fichier = fopen(fileName, "r");

    if (fichier == NULL)
    {
        printf("Le fichier %s n'existe pas. Une nouvelle liste vide sera creee.\n", fileName);
        return;
    }

    struct employe emp;

    while (fscanf(fichier, "%d %s %s %d/%d/%d %s %f",
                  &emp.code, emp.nom, emp.prenom, &emp.dateNaissance.jour,
                  &emp.dateNaissance.mois, &emp.dateNaissance.annee,
                  emp.titrePoste, &emp.salaire) != EOF)
    {
        ajouterEmploye(list, emp);
    }

    fclose(fichier);
    printf("Liste chargee depuis le fichier %s avec succes.\n", fileName);
}
