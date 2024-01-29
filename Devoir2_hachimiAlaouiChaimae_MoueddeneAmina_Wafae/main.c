#include "headerdev.h"

int main()
{
    int choix = 0;
    int choixSupp = 0;
    int choixRech = 0;
    struct listEmp* list1 = initiList();
    chargerListeDepuisFichier(list1, "employees.txt");

    struct employe emp;

    mainMenu();
    do
    {
        printf("--------------------------------------------------------\n");
        printf("veuillez effectuer  votre choix : ");
        scanf("%d",&choix);
        printf("--------------------------------------------------------\n");
        switch(choix)
        {
        case 1:
        {
            printf("-------------------------------------------\n");
            printf("voici la liste des employees : \n");
            afficherList(list1);
            printf("-------------------------------------------\n");
            break;

        }
        case 2:
        {
            printf("-------------------------------------------\n");
            printf("pour ajouter un nouveau employe veuiller entrer les informations sivantes :\n");
            saisieInfo(list1, &emp);
            break;
        }
        case 3:
        {
            printf("-------------------------------------------\n");
            printf("pour supprimer un employe veuiller effectuer votre choix de suppression : ");
            scanf("%d",&choixSupp);
            switch(choixSupp)
            {
            case 1:
            {
                int codeAsupprimer ;
                char res[5];
                printf("entrer le code de l'employe que vous voulez supprimer : ");
                scanf(" %d",&codeAsupprimer);
                afficherEmployeParCode(list1,codeAsupprimer);
                printf("Voulez-vous vraiment supprimer cet employe ? [yes | no] : ");
                scanf("%s", res);

                if (strcmp(res, "yes") == 0)
                {
                        supprimerEmployeParCode(list1, codeAsupprimer);
                }
                    else
                    {

                        printf("\nL'employe ne sera pas supprime .\n");
                    }


                break;
            }
            case 2:
            {
                char nom[20];
                char result[5];
                int codeAsupp;
                printf("entrer le nom de l employe que vous voulez supprimer : ");
                scanf(" %s",nom);
                afficherEmployeParNom(list1,nom);
                printf("veuiller entrer le code de l employe que vous voulez :");
                scanf("%d",&codeAsupp);
                afficherEmployeParCode(list1,codeAsupp);
                printf("Voulez-vous vraiment supprimer cet employe ? [yes | no] : ");
                scanf("%s", result);

                if (strcmp(result, "yes") == 0)
                {


                    supprimerEmployeParCode(list1, codeAsupp);
                    break;
                }
                else
                {
                    // Handle the case where the user entered something other than "yes"
                    printf("\nL'employe ne sera pas supprime .\n");
                }
                break;
            }

        }
        break;
        }
        case 4:
        {
            printf("-------------------------------------------\n");
            printf("pour effectuer une recherche , veuiller  entrer votre choix : ");
            scanf("%d",&choixRech);
            if(choixRech == 1)
            {
                int codeAchercher;
                printf("-------------------------------------------\n");
                printf("pour chercher un employe par son code  , veuillez le saisir :");
                scanf("%d",&codeAchercher);
                afficherEmployeParCode(list1,codeAchercher);
                break;
            }
            if(choixRech == 2)
            {
                char nom[20];
                printf("-------------------------------------------\n");
                printf("pour chercher un employe par son nom  , veuillez le saisir :");
                scanf("%s",nom);
                afficherEmployeParNom(list1,nom);
                break;
            }
            if(choixRech == 3)
                {
                    char prenom[20];
                    printf("-------------------------------------------\n");
                    printf("pour chercher un employe par son prenom  , veuillez le saisir :");
                    scanf("%s",prenom);
                    afficherEmployeParPrenom(list1,prenom);
                    break;
                }

            break;
        }
        case 5:
        {
            int codeModi ;
            printf("pour modifier veuiller entrer le code de l'empl : ");
            scanf("%d",&codeModi);
            modificationEmp(list1,codeModi);
            break;
        }
        case 6:
        {

            MainChoix();
            break;
        }
         case 7:
        {
            printf("Au revoir!\n");
            sauvegarderListeDansFichier(list1, "employees.txt");
            break;
        }
        default:
            printf("Choix non valide. Veuillez ressayer.\n");
        }
    }while(choix != 7);


    return 0;
}
