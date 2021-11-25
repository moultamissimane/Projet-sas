#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct compteBancaire
{
    char nom[30];
    char prenom[30];
    char CIN[30];
    float montant;
} compteBancaire;

void classerCroix(compteBancaire T[], int taille);
void trierParSelection(compteBancaire T[], int taille, char type[4], int chiffre);
void ajouterFidelisation(compteBancaire T[], int taille);
void neew(char *menu[]);
int main()
{

    int i = 0, j = 0, tailleCB = 0;
    int choix = 0;
    int anyKey;//just to stop the process and press any key to complete
    int addFidelisation = 0;//check if i added fidelisation 0 means not yet
    int chiffre;//classement par montant
    int iOfChoosedAcc = 0;//i of choosed account when i compare the cin scanf with the cb[i].CIN
    float montantARetrait = 0;
    float montantADepot = 0;
    int numOfAcc = 0;//add 1 account or many
    char searchCIN[10];//var for storing the scanf of CIN
    char firstNames[15][30] = {"AAAA", "BBBB", "CCCC", "DDDD", "EEEE", "FFFF", "JJJJ", "HHHH", "KKKK", "IIII", "MMMM", "NNNN", "OOOO", "PPPP", "QQQQ"};
    char lastNames[15][30] = {"AAAA", "BBBB", "CCCC", "DDDD", "EEEE", "FFFF", "JJJJ", "HHHH", "KKKK", "IIII", "MMMM", "NNNN", "OOOO", "PPPP", "QQQQ"};
    char arrCIN[15][30] = {"AAAA", "BBBB", "CCCC", "DDDD", "EEEE", "FFFF", "JJJJ", "HHHH", "KKKK", "IIII", "MMMM", "NNNN", "OOOO", "PPPP", "QQQQ"};
    float arrMon[15] = {10000.00, 24000.00, 3000.00, 2000.00, 10000.00, 40000.00, 5800.00, 3490.00, 23456.00, 19870.00, 12987.00, 19990.00, 23000.00, 30000.00, 45600.00};int arrPin[15] = {1111, 2222, 3333, 4444, 5555, 6666, 7777, 8888, 9999, 1010, 1111, 1212, 1313, 1414, 1515};

    compteBancaire compteBancaires[tailleCB];//create table of compteBancaires based on struct contain taillebc of elements

Menu:

    do
    {
        system("cls");
        neew("BIENVENUE DANS VOTRE MENU");
        printf("\n\n");
        printf("\n 1: Ajouter compte\n");
        printf("\n 2: Gestion compte\n");
        printf("\n 3: Retour\n");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            goto MenuAddAcc;
            choix = 0;
            break;
        case 2:
            goto MenuSearchAcc;
            choix = 0;
            break;
        case 3:
            printf("Au revoir");
            choix = 0;
            break;
        default:
            printf("Choix Inattendu! Entrer une autre fois");
            choix = 0;
            break;
        }
    } while (choix > 3);

MenuAddAcc:

    do
    {
        system("cls");
        printf("\t\t\tMenu ajouter compte**\n");
        printf("\n1: Ajouter un seul compte\n");
        printf("\n2: Ajouter Plusieurs comptes\n");
        printf("\n3: Ajouter Plusieurs comptes (Auto 15 comptes)\n");
        printf("\n4: Retour\n");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            goto addAcc;
            break;
        case 2:
            goto addAcc;
            break;
        case 3:
            goto addAccAuto;
            break;
        case 4:
            printf("Au revoir");
            Sleep(1000);
            system("cls");
            goto Menu;
            break;
        default:
            printf("Choix Inattendu! Entrer Une Autre Fois");
            break;
        }
    } while (choix > 3);

MenuSearchAcc:

    do
    {
        system("cls");
        printf("\t\t\t*Menu Rechercher compte*\n");
        printf("\n1: Rechercher un compte\n");
        printf("\n2: Afficher tout les comptes\n");
        printf("\n3: Ajoutez fidelisation 1.3%% pour les 3 premiers\n");
        printf("\n4: Retour\n");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            goto search1Compte;
            break;
        case 2:
            goto AffTtAcc;
            break;
        case 3:
            if(addFidelisation == 0){
            goto AjouterFidelisation;
            }else{
            system("cls");
            printf("Vous avez deja ajouter la fidelasation\n Entrer 0 pour revenir:");
            scanf("%d",&choix);
            goto Menu;
            }
            break;
        case 4:
            printf("Au revoir");
            Sleep(1000);
            system("cls");
            goto Menu;
            break;
        default:
            printf("Choix Inattendu! Entrer Une Autre Fois");
            break;
        }
    } while (choix > 3);

AjouterFidelisation :

ajouterFidelisation(compteBancaires,tailleCB);
 addFidelisation=1;
printf("\nLa Fidelisation a ete ajoute avec succees\n");
do{
    printf("Entrer 0 pour revenir:");
    scanf("%d",&choix);
    system("cls");
}
while(choix != 0);
goto MenuSearchAcc;


AffTtAcc:
    do
    {
       neew("Tous les comptes sont statistiques");

        //affichage de tous les compte
        for (i = 0; i < tailleCB; i++)
        {
            printf("%d: %s %s \t %s \t %.2lf\n", i + 1, compteBancaires[i].nom, compteBancaires[i].prenom, compteBancaires[i].CIN, compteBancaires[i].montant);
        }

        do
        {
            printf("\t\t**Trier par:\n");
            printf("\n1: ASC\n");
            printf("\n2: DESC\n");
            printf("\n3: ASC avec limite\n");
            printf("\n4: DESC avec limite\n");
            printf("\n5: Retour\n");
            scanf("%d", &choix);

            switch (choix)
            {
            case 1:
                system("cls");
                trierParSelection(compteBancaires, tailleCB, "ASC", 0);
                break;
            case 2:
                system("cls");
                trierParSelection(compteBancaires, tailleCB, "DESC", 0);
                break;
            case 3:
                printf("Entrer un montant:");
                scanf("%d", &chiffre);
                system("cls");
                trierParSelection(compteBancaires, tailleCB, "ASC", chiffre);
                break;
            case 4:
                printf("Entrer un montant:");
                scanf("%d", &chiffre);
                system("cls");
                trierParSelection(compteBancaires, tailleCB, "DESC", chiffre);
                break;
            case 5:
                printf("Au revoir");
                Sleep(1000);
                system("cls");
                goto Menu;
                break;
            default:
                printf("Choix Inattendu! Entrer Une Autre Fois");
                break;
            }
        } while (choix > 3);
        printf("\n");

        printf("Entrer 0 pour retourner au menu:\n");
        scanf("%d", &anyKey);
        goto Menu;
    } while (anyKey != 0);

search1Compte:

    neew("Rechercher un compte avec CIN");
    printf("Entrer la CIN:");
    scanf("%s", &searchCIN);

    for (i = 0; i < tailleCB; i++)
    {
        if (strcmp(searchCIN, compteBancaires[i].CIN) == 0)
        {
            iOfChoosedAcc =i;//pour memoiriser le I de compte banquaire pour fair le retrait ou le depot
            neew("menu");
            printf("\n\n\n%d: %s %s \t %s \t %.2lf\n", i + 1, compteBancaires[i].nom, compteBancaires[i].prenom, compteBancaires[i].CIN, compteBancaires[i].montant);

            do
            {
                system("cls");
                printf("\t\t*Operations*\n");
                printf("\n1: RETRAIT\n");
                printf("\n2: DEPOT\n");
                printf("\n3: Retour\n");
                scanf("%d", &choix);

                switch (choix)
                {
                case 1:
                    goto retrait;
                    break;
                case 2:
                    goto depot;
                    break;
                case 3:
                    printf("Au revoir");
                    Sleep(1000);
                    system("cls");
                    goto Menu;
                    break;
                default:
                    printf("Choix Inattendu!Entrer une autre fois");
                    break;
                }
            } while (choix > 3);
        }
        else
        {
            printf("\n Aucun compte trouve avec cette CIN\n");
        }
    }

    printf("Entrer 0 pour retourner au menu:\n");
    scanf("%d", &anyKey);
    goto Menu;



retrait:
    system("cls");
    printf("Retrait de Mr %s qui a %.2f", compteBancaires[iOfChoosedAcc].prenom, compteBancaires[iOfChoosedAcc].montant);
    printf("Entrer le montant a retirer:");
    scanf("%f", &montantARetrait);
    if (compteBancaires[iOfChoosedAcc].montant >= montantARetrait)
    {

        compteBancaires[iOfChoosedAcc].montant = compteBancaires[iOfChoosedAcc].montant - montantARetrait;
        printf("Operation Reussite \n Merci");
        Sleep(3000);
        goto Menu;
    }
    else
    {
        printf("Solde Insuffisant\n");
        Sleep(3000);
        goto Menu;
    }

depot:
    printf("Depot de Mr %s qui a %.2f:", compteBancaires[iOfChoosedAcc].prenom, compteBancaires[iOfChoosedAcc].montant);
    printf("Entrer le montant a debiter:");
    scanf("%f", &montantADepot);
        compteBancaires[iOfChoosedAcc].montant = compteBancaires[iOfChoosedAcc].montant + montantADepot;
        if(montantADepot > 100){
        printf("Operation Reussite \n Merci");
        }else{
            printf("Veuillez inserer plus que 100 dh\n");
        Sleep(3000);
        goto Menu;



//affichage de menu
addAcc:

    printf("\t\t\n ");

    system("cls");

    if (choix == 1)
    {
        tailleCB = 1;
    }
    else
    {
        printf("Entrer la taille du tableau des comptes bancaires:\n");
        scanf("%d", &tailleCB);
    }
    system("cls");

    printf("Entrer votre nom . prenom . CIN et montant:\n");

    for (i = 0; i < tailleCB; i++)
    {
        printf("%d:\n", i + 1);
        printf("Entrer votre NOM:");
        scanf("%s", &compteBancaires[i].nom);
        printf("\nEntrer votre PRENOM:");
        scanf("%s", &compteBancaires[i].prenom);
        printf("\nEntrer votre CIN:");
        scanf("%s", &compteBancaires[i].CIN);
        printf("\nEntrer votre MONTANT:");
        scanf("%f", &compteBancaires[i].montant);
        system("cls");
        printf("Votre compte a ete cree successivement!");
        Sleep(500);
        system("cls");
        numOfAcc++;
    }
    goto Menu;

addAccAuto:

    tailleCB = 15;
    system("cls");
    for (i = 0; i < tailleCB ; i++)
    {
        printf("%s - %s - %s - %.2f \n", firstNames[i], lastNames[i], arrCIN[i], arrMon[i]);
        Sleep(50);
        strcpy(compteBancaires[i].nom, firstNames[i]);
        strcpy(compteBancaires[i].prenom, lastNames[i]);
        strcpy(compteBancaires[i].CIN, arrCIN[i]);
        compteBancaires[i].montant = arrMon[i];
    }
    printf("\nLes 15 comptes ont ete ajouter avec succes\n Entrer 0:");
    scanf("%d", &anyKey);
    goto Menu;

    return 0;
}

void neew (char *menu[])
{
    system("cls");
    printf("****%s*****\n\n\n", menu);
}

void classerCroix(compteBancaire T[], int taille)
{
    int i = 0;
    for (i = 0; i < taille; i++)
    {
        printf("%.2f\n", T[i].montant);
    }
}

void trierParSelection(compteBancaire T[], int taille, char type[4], int chiffre)
{
    int i = 0, j = 0;
    compteBancaire temp;
    for (i = 0; i < taille; i++)
    {
        for (j = i + 1; j < taille; j++)
        {
            if (strcmp(type, "ASC") == 0)
            {
                if (T[i].montant < T[j].montant)
                {
                    temp = T[i];
                    T[i] = T[j];
                    T[j] = temp;
                }
            }
            else if (strcmp(type, "DESC") == 0)
            {
                if (T[i].montant > T[j].montant)
                {
                    temp = T[i];
                    T[i] = T[j];
                    T[j] = temp;
                }
            }
        }
    }
    printf("trier par :\n");
    for (i = 0; i < taille; i++)
    {
        if (T[i].montant > chiffre)
        {
            printf("\n%d: %s %s \t %s \t %.2lf", i + 1, T[i].nom, T[i].prenom, T[i].CIN, T[i].montant);
        }
    }
}


void ajouterFidelisation(compteBancaire T[], int taille)
{
    int i = 0, j = 0;
    compteBancaire temp;
    for (i = 0; i < taille; i++)
    {
        for (j = i + 1; j < taille; j++)
        {
                if (T[i].montant < T[j].montant)
                {
                    temp = T[i];
                    T[i] = T[j];
                    T[j] = temp;
                }
        }
    }
    for (i = 0; i < 3; i++)
    {
            T[i].montant = T[i].montant + T[i].montant*1.3;
    }
}

