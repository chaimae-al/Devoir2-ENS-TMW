#ifndef HEADERDEV_H_INCLUDED
#define HEADERDEV_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//la declaration des structures
typedef struct dateNaissance
{
    int jour;
    int mois;
    int annee;
}DateNaissance;
struct employe
{
    int code;
    char nom[20];
    char prenom[20];
    DateNaissance dateNaissance;
    char titrePoste[20];
    float salaire;
};
struct  elemntsEmp
{
    struct employe data;
    struct elemntsEmp *next;
};
struct listEmp
{
    struct elemntsEmp *head;
};

// les prototypes des fonctions utilis�es
void mainMenu();
void MainChoix();
struct listEmp* initiList();

// les fonctions de verifications
int estVide(struct listEmp* list);
bool estUnique(struct listEmp* list, int codeV);

// les fonctions d'affichage :
void afficherList(struct listEmp* list);
void afficherEmployeParCode(struct listEmp* list, int codeEmploye);
void afficherEmployeParNom(struct listEmp* list, char nomEmploye[]);
void afficherEmployeParPrenom(struct listEmp* list, char prenomEmploye[]);

// la fonction d'ajout
void ajouterEmploye(struct listEmp* list,struct employe emp);

// la fonction de suppression
void supprimerEmployeParCode(struct listEmp* list, int codeEmploye);

// les fonctions des saisies
void saisieCode(struct listEmp* list, struct employe* nouveauEmploye);
void saisieNom(struct listEmp* list, struct employe* nouveauEmploye);
void saisiePrenom(struct listEmp* list, struct employe* nouveauEmploye);
void saisieDateN(struct listEmp* list, struct employe* nouveauEmploye);
void saisieSalaire(struct listEmp* list, struct employe* nouveauEmploye);
void saisiePoste(struct listEmp* list, struct employe* nouveauEmploye);
void saisieInfo(struct listEmp* list, struct employe* nouveauEmploye);

// la fonction de modification
void modificationEmp(struct listEmp* list, int codeEmploye);

// les fonctions de traitement sur les fichiers
void chargerListeDepuisFichier(struct listEmp* list, const char* fileName);
void sauvegarderListeDansFichier(struct listEmp* list, const char* fileName);


#endif // HEADERDEV_H_INCLUDED
