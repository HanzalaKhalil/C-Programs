// \ = ||

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Auth();
void Admin();
void User();

void New_Ent();
void Comp_Ent();
void Bio_Ent();

void Upd_Res();
void Comp_Upd();
void Bio_Upd();

void Del_Ent();
void Comp_Del();
void Bio_Del();

void View_Res();
void Comp_View();
void Bio_View();

int delay(int);

int choice, counter = 0;

#define MATH 75.00
#define ENG 75.00
#define URDU 75.00
#define CHEM 60.00
#define PHY 60.00
#define BIO 60.00
#define COMP 50.00
#define ISL 50.00
#define PAK 50.00

#define TOTAL_COMP (MATH + COMP + CHEM + ISL + URDU + PAK + PHY + ENG)
#define TOTAL_BIO (MATH + BIO + CHEM + ISL + URDU + PAK + PHY + ENG)

const int UPPER_LIMIT = 600000;
const int LOWER_LIMIT = 500000;

struct Percentage
{
    float math;
    float chem;
    float comp;
    float bio;
    float phy;
    float urdu;
    float isl;
    float eng;
    float pak;
    float total;
};

struct Marks
{
    int math;
    int chem;
    int comp;
    int bio;
    int phy;
    int urdu;
    int isl;
    int eng;
    int pak;
    int total;
};

struct Student
{
    char f_name[25];
    char l_name[25];
    int roll;
    struct Marks marks;
    struct Percentage perc;
};

void main()
{
    printf("\tResult Management System");
    printf("\n\n1.Admin");
    printf("\n2.User");
    printf("\n3.Exit");

Main_Menu:
    printf("\n\tEnter Choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        switch (counter)
        {
        case 0:
            Auth();
            break;
        case 1:
            Admin();
            break;
        default:
            break;
        }
        break;
    case 2:
        system("clear");
        User();
        break;
    case 3:
        system("clear");
        printf("\n\n\n\nThank You!\n\n\n\n");
        goto Exit;
        break;
    default:
        printf("\nError : Invalid Option\n");
        goto Main_Menu;
        break;
    }

Exit:
}

void Auth()
{
    system("clear");

    char username[30], password[30], temp[30] = " ";
    int k = 0;

    printf("\tLogin\n\n");
    printf("Enter Username: ");
    scanf("%s", username);

    FILE *Crepointer = fopen("Credentials.dat", "r");

    for (int i = 0; i < 100000; i++)
    {
        fscanf(Crepointer, "%s", temp);
        if (strcmp(username, temp) == 0)
        {
            goto Loop_End;
        }

        fscanf(Crepointer, "%s", temp);
    }

    printf("\nError : Username Not Found\n\n");
    delay(1);
    system("clear");

    printf("1.Try Again\n");
    printf("2.Main Menu\n");
    printf("3.Exit\n");

Retry:
    printf("\n\tEnter Choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        Auth();
        break;
    case 2:
        main();
        break;
    case 3:
        system("clear");
        printf("\n\n\n\nThank You!\n\n\n\n");
        goto Exit;
        break;
    default:
        printf("\nError : Invalid Option\n\n");
        goto Retry;
        break;
    }

Loop_End:

    printf("Enter Password: ");
    scanf("%s", password);
    fscanf(Crepointer, "%s", temp);

    if (strcmp(password, temp) != 0)
    {
        printf("\nError : Incorrect Password\n\n");
        delay(1);
        system("clear");

        printf("1.Try Again\n");
        printf("2.Main Menu\n");
        printf("3.Exit\n");

    Retry_2:
        printf("\n\tEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system("clear");
            Auth();
            break;
        case 2:
            main();
            break;
        case 3:
            system("clear");
            printf("\n\n\n\nThank You!\n\n\n\n");
            goto Exit;
            break;
        default:
            printf("\nError : Invalid Option\n\n");
            goto Retry_2;
            break;
        }
    }
    else
    {
        counter++;
        Admin();
    }

    fclose(Crepointer);

Exit:
}

void Admin()
{
    system("clear");

    printf("\tAdmin");
    printf("\n\n1.New Entry");
    printf("\n2.Update Result");
    printf("\n3.Delete Entry");
    printf("\n4.View Result");
    printf("\n5.Exit");

Main_Menu:
    printf("\n\tEnter Choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        New_Ent();
        break;
    case 2:
        Upd_Res();
        break;
    case 3:
        Del_Ent();
        break;
    case 4:
        View_Res();
        break;
    case 5:
        system("clear");
        printf("\n\n\n\nThank You!\n\n\n\n");
        goto Exit;
        break;
    default:
        printf("\nError : Invalid Option\n");
        goto Main_Menu;
        break;
    }

Exit:
}

void New_Ent()
{
    system("clear");

    printf("\tNew Entry\n");
    printf("\n1.Computer");
    printf("\n2.Biology");
    printf("\n3.Main Menu");
    printf("\n4.Exit");

Bio_Comp:
    printf("\n\n\tEnter Choice:");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("clear");
        Comp_Ent();
        break;
    case 2:
        system("clear");
        Bio_Ent();
        break;
    case 3:
        system("clear");
        Admin();
        break;
    case 4:
        system("clear");
        printf("\n\n\n\nThank You!\n\n\n\n");
        goto Exit;
        break;
    default:
        printf("\nError : Invalid Option\n\n");
        goto Bio_Comp;
        break;
    }
Exit:
}

void Comp_Ent()
{
    int temp = 0, temp2 = 1;
    int *ptemp;
    ptemp = &temp;

    struct Student st;

Roll_Entry:

    printf("Enter Roll No.(%d-%d): ", LOWER_LIMIT, UPPER_LIMIT);

    scanf("%d", &st.roll);
    if (st.roll < LOWER_LIMIT || st.roll > UPPER_LIMIT)
    {
        printf("Error : Invalid Roll Number\n");
        goto Roll_Entry;
    }

    FILE *Rollpointer = fopen("Comp_Roll_No.dat", "r");

    for (int i = 0; i < 100000; i++)
    {
        fscanf(Rollpointer, "%d", ptemp);
        if (st.roll == temp)
        {
            printf("\nError : Entry Already Exists\n");
            delay(1);
            New_Ent();
        }
        else
        {
            if (temp == temp2)
            {
                i = 100000;
            }
            else
            {
                temp2 = temp;
            }
        }
    }

    fclose(Rollpointer);

    Rollpointer = fopen("Bio_Roll_No.dat", "r");

    for (int i = 0; i < 100000; i++)
    {
        fscanf(Rollpointer, "%d", ptemp);
        if (st.roll == temp)
        {
            printf("\nError : Entry Already Exists\n");
            delay(1);
            New_Ent();
        }
        else
        {
            if (temp == temp2)
            {
                i = 100000;
            }
            else
            {
                temp2 = temp;
            }
        }
    }

    fclose(Rollpointer);

    printf("Enter Name: ");
    scanf("%s%s", st.f_name, st.l_name);

Math:
    printf("Enter Marks in Mathematics  (Total Matks:%.0f): ", MATH);
    scanf("%d", &st.marks.math);
    if (st.marks.math < 0 || st.marks.math > MATH)
    {
        printf("Error :Limit Exceeded\n");
        goto Math;
    }

Eng:
    printf("Enter Marks in English  (Total Matks:%.0f): ", ENG);
    scanf("%d", &st.marks.eng);
    if (st.marks.eng < 0 || st.marks.eng > ENG)
    {
        printf("Error :Limit Exceeded\n");
        goto Eng;
    }

Urdu:
    printf("Enter Marks in Urdu  (Total Matks:%.0f): ", URDU);
    scanf("%d", &st.marks.urdu);
    if (st.marks.urdu < 0 || st.marks.urdu > URDU)
    {
        printf("Error :Limit Exceeded\n");
        goto Urdu;
    }

Chem:
    printf("Enter Marks in Chemistry  (Total Matks:%.0f): ", CHEM);
    scanf("%d", &st.marks.chem);
    if (st.marks.chem < 0 || st.marks.chem > CHEM)
    {
        printf("Error :Limit Exceeded\n");
        goto Chem;
    }

Phy:
    printf("Enter Marks in Physics  (Total Matks:%.0f): ", PHY);
    scanf("%d", &st.marks.phy);
    if (st.marks.phy < 0 || st.marks.phy > PHY)
    {
        printf("Error :Limit Exceeded\n");
        goto Phy;
    }

Comp:
    printf("Enter Marks in Computer  (Total Matks:%.0f): ", COMP);
    scanf("%d", &st.marks.comp);
    if (st.marks.comp < 0 || st.marks.comp > COMP)
    {
        printf("Error :Limit Exceeded\n");
        goto Comp;
    }

Isl:
    printf("Enter Marks in Islamiyat  (Total Matks:%.0f): ", ISL);
    scanf("%d", &st.marks.isl);
    if (st.marks.isl < 0 || st.marks.isl > ISL)
    {
        printf("Error :Limit Exceeded\n");
        goto Isl;
    }

Pak:
    printf("Enter Marks in Pakistan Studies  (Total Matks:%.0f): ", PAK);
    scanf("%d", &st.marks.pak);
    if (st.marks.pak < 0 || st.marks.pak > PAK)
    {
        printf("Error :Limit Exceeded\n");
        goto Pak;
    }

    st.marks.total = st.marks.chem + st.marks.isl + st.marks.eng + st.marks.pak + st.marks.phy + st.marks.urdu + st.marks.math + st.marks.comp;
    st.perc.math = (st.marks.math / MATH) * 100;
    st.perc.eng = (st.marks.eng / ENG) * 100;
    st.perc.urdu = (st.marks.urdu / URDU) * 100;
    st.perc.chem = (st.marks.chem / CHEM) * 100;
    st.perc.phy = (st.marks.phy / PHY) * 100;
    st.perc.comp = (st.marks.comp / COMP) * 100;
    st.perc.isl = (st.marks.isl / ISL) * 100;
    st.perc.pak = (st.marks.pak / PAK) * 100;
    st.perc.total = (st.marks.total / TOTAL_COMP) * 100;

    Rollpointer = fopen("Comp_Roll_No.dat", "a");

    fprintf(Rollpointer, "%d\n", st.roll);

    fclose(Rollpointer);

    FILE *Respointer = fopen("Comp_Result.dat", "a");

    fprintf(Respointer, "Name : %s %s\n", st.f_name, st.l_name);
    fprintf(Respointer, "Roll No. : %d\n", st.roll);
    fprintf(Respointer, "Subject   Obt.Marks   Total.Marks   Percentage  \n");
    fprintf(Respointer, "Math      %d          %.0f            %.2f        \n", st.marks.math, MATH, st.perc.math);
    fprintf(Respointer, "Eng       %d          %.0f            %.2f        \n", st.marks.eng, ENG, st.perc.eng);
    fprintf(Respointer, "Urdu      %d          %.0f            %.2f        \n", st.marks.urdu, URDU, st.perc.urdu);
    fprintf(Respointer, "Chem      %d          %.0f            %.2f        \n", st.marks.chem, CHEM, st.perc.chem);
    fprintf(Respointer, "Phy       %d          %.0f            %.2f        \n", st.marks.phy, PHY, st.perc.phy);
    fprintf(Respointer, "Comp      %d          %.0f            %.2f        \n", st.marks.comp, COMP, st.perc.comp);
    fprintf(Respointer, "Isl       %d          %.0f            %.2f        \n", st.marks.isl, ISL, st.perc.isl);
    fprintf(Respointer, "Pak       %d          %.0f            %.2f        \n", st.marks.pak, PAK, st.perc.pak);
    fprintf(Respointer, "Total     %d         %.0f           %.2f         \n", st.marks.total, TOTAL_COMP, st.perc.total);
    fclose(Respointer);

    system("clear");

    printf("\n1.New Entry");
    printf("\n2.Main Menu");
    printf("\n3.Exit");

Main_Menu:
    printf("\n\n\tEnter Choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("clear");
        New_Ent();
        break;
    case 2:
        system("clear");
        Admin();
        break;
    case 3:
    Exit:
        system("clear");
        printf("\n\n\n\nThank You!\n\n\n\n");
        break;
    default:
        printf("\nError : Invalid Option\n\n");
        goto Main_Menu;
        break;
    }
}

void Bio_Ent()
{
    int temp = 0, temp2 = 1;
    int *ptemp;
    ptemp = &temp;

    struct Student st;

Roll_Entry:

    printf("Enter Roll No.(%d-%d): ", LOWER_LIMIT, UPPER_LIMIT);

    scanf("%d", &st.roll);
    if (st.roll < LOWER_LIMIT || st.roll > UPPER_LIMIT)
    {
        printf("Error : Invalid Roll Number\n");
        goto Roll_Entry;
    }

    FILE *Rollpointer = fopen("Bio_Roll_No.dat", "r");

    for (int i = 0; i < 100000; i++)
    {
        fscanf(Rollpointer, "%d", ptemp);
        if (st.roll == temp)
        {
            printf("\nError : Entry Already Exists\n");
            delay(1);
            New_Ent();
        }
        else
        {
            if (temp == temp2)
            {
                i = 100000;
            }
            else
            {
                temp2 = temp;
            }
        }
    }

    fclose(Rollpointer);

    Rollpointer = fopen("Comp_Roll_No.dat", "r");

    for (int i = 0; i < 100000; i++)
    {
        fscanf(Rollpointer, "%d", ptemp);
        if (st.roll == temp)
        {
            printf("\nError : Entry Already Exists\n");
            delay(1);
            New_Ent();
        }
        else
        {
            if (temp == temp2)
            {
                i = 100000;
            }
            else
            {
                temp2 = temp;
            }
        }
    }

    fclose(Rollpointer);

    printf("Enter Name: ");
    scanf("%s%s", st.f_name, st.l_name);

Math:
    printf("Enter Marks in Mathematics  (Total Matks:%.0f): ", MATH);
    scanf("%d", &st.marks.math);
    if (st.marks.math < 0 || st.marks.math > MATH)
    {
        printf("Error :Limit Exceeded\n");
        goto Math;
    }

Eng:
    printf("Enter Marks in English  (Total Matks:%.0f): ", ENG);
    scanf("%d", &st.marks.eng);
    if (st.marks.eng < 0 || st.marks.eng > ENG)
    {
        printf("Error :Limit Exceeded\n");
        goto Eng;
    }

Urdu:
    printf("Enter Marks in Urdu  (Total Matks:%.0f): ", URDU);
    scanf("%d", &st.marks.urdu);
    if (st.marks.urdu < 0 || st.marks.urdu > URDU)
    {
        printf("Error :Limit Exceeded\n");
        goto Urdu;
    }

Chem:
    printf("Enter Marks in Chemistry  (Total Matks:%.0f): ", CHEM);
    scanf("%d", &st.marks.chem);
    if (st.marks.chem < 0 || st.marks.chem > CHEM)
    {
        printf("Error :Limit Exceeded\n");
        goto Chem;
    }

Phy:
    printf("Enter Marks in Physics  (Total Matks:%.0f): ", PHY);
    scanf("%d", &st.marks.phy);
    if (st.marks.phy < 0 || st.marks.phy > PHY)
    {
        printf("Error :Limit Exceeded\n");
        goto Phy;
    }

Comp:
    printf("Enter Marks in Biology  (Total Matks:%.0f): ", BIO);
    scanf("%d", &st.marks.bio);
    if (st.marks.bio < 0 || st.marks.bio > BIO)
    {
        printf("Error :Limit Exceeded\n");
        goto Comp;
    }

Isl:
    printf("Enter Marks in Islamiyat  (Total Matks:%.0f): ", ISL);
    scanf("%d", &st.marks.isl);
    if (st.marks.isl < 0 || st.marks.isl > ISL)
    {
        printf("Error :Limit Exceeded\n");
        goto Isl;
    }

Pak:
    printf("Enter Marks in Pakistan Studies  (Total Matks:%.0f): ", PAK);
    scanf("%d", &st.marks.pak);
    if (st.marks.pak < 0 || st.marks.pak > PAK)
    {
        printf("Error :Limit Exceeded\n");
        goto Pak;
    }

    st.marks.total = st.marks.chem + st.marks.isl + st.marks.eng + st.marks.pak + st.marks.phy + st.marks.urdu + st.marks.math + st.marks.bio;
    st.perc.math = (st.marks.math / MATH) * 100;
    st.perc.eng = (st.marks.eng / ENG) * 100;
    st.perc.urdu = (st.marks.urdu / URDU) * 100;
    st.perc.chem = (st.marks.chem / CHEM) * 100;
    st.perc.phy = (st.marks.phy / PHY) * 100;
    st.perc.bio = (st.marks.bio / BIO) * 100;
    st.perc.isl = (st.marks.isl / ISL) * 100;
    st.perc.pak = (st.marks.pak / PAK) * 100;
    st.perc.total = (st.marks.total / TOTAL_BIO) * 100;

    Rollpointer = fopen("Bio_Roll_No.dat", "a");

    fprintf(Rollpointer, "%d\n", st.roll);

    fclose(Rollpointer);

    FILE *Respointer = fopen("Bio_Result.dat", "a");

    fprintf(Respointer, "Name : %s %s\n", st.f_name, st.l_name);
    fprintf(Respointer, "Roll No. : %d\n", st.roll);
    fprintf(Respointer, "Subject   Obt.Marks   Total.Marks   Percentage  \n");
    fprintf(Respointer, "Math      %d          %.0f            %.2f        \n", st.marks.math, MATH, st.perc.math);
    fprintf(Respointer, "Eng       %d          %.0f            %.2f        \n", st.marks.eng, ENG, st.perc.eng);
    fprintf(Respointer, "Urdu      %d          %.0f            %.2f        \n", st.marks.urdu, URDU, st.perc.urdu);
    fprintf(Respointer, "Chem      %d          %.0f            %.2f        \n", st.marks.chem, CHEM, st.perc.chem);
    fprintf(Respointer, "Phy       %d          %.0f            %.2f        \n", st.marks.phy, PHY, st.perc.phy);
    fprintf(Respointer, "Biol      %d          %.0f            %.2f        \n", st.marks.bio, BIO, st.perc.bio);
    fprintf(Respointer, "Isl       %d          %.0f            %.2f        \n", st.marks.isl, ISL, st.perc.isl);
    fprintf(Respointer, "Pak       %d          %.0f            %.2f        \n", st.marks.pak, PAK, st.perc.pak);
    fprintf(Respointer, "Total     %d         %.0f           %.2f         \n", st.marks.total, TOTAL_BIO, st.perc.total);
    fclose(Respointer);

    system("clear");

    printf("\n1.New Entry");
    printf("\n2.Main Menu");
    printf("\n3.Exit");

Main_Menu:
    printf("\n\n\tEnter Choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("clear");
        New_Ent();
        break;
    case 2:
        system("clear");
        Admin();
        break;
    case 3:
    Exit:
        system("clear");
        printf("\n\n\n\nThank You!\n\n\n\n");
        break;
    default:
        printf("\nError : Invalid Option\n\n");
        goto Main_Menu;
        break;
    }
}

void Upd_Res()
{
    system("clear");

    printf("\tUpdate Result\n");
    printf("\n1.Computer");
    printf("\n2.Biology");
    printf("\n3.Main Menu");
    printf("\n4.Exit");

Bio_Comp:
    printf("\n\n\tEnter Choice:");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("clear");
        Comp_Upd();
        break;
    case 2:
        system("clear");
        Bio_Upd();
        break;
    case 3:
        system("clear");
        Admin();
        break;
    case 4:
        system("clear");
        printf("\n\n\n\nThank You!\n\n\n\n");
        break;
    default:
        printf("\nError : Invalid Option\n\n");
        goto Bio_Comp;
        break;
    }
}

void Comp_Upd()
{
    int roll_no, index1 = -2, index2 = -2;

    struct Student st;

    char output[51], indicator;

    FILE *Rollpointer, *Temppointer, *Respointer, *Temp_2pointer;

Roll_Entry:
    int temp1 = 0, temp2 = 1;
    int *ptemp1;
    ptemp1 = &temp1;

    printf("Enter Roll No.(%d-%d): ", LOWER_LIMIT, UPPER_LIMIT);
    scanf("%d", &roll_no);
    if (roll_no < LOWER_LIMIT || roll_no > UPPER_LIMIT)
    {
        printf("Error : Invalid Roll Number\n");
        goto Roll_Entry;
    }

    Rollpointer = fopen("Comp_Roll_No.dat", "r");

    for (int i = 0; i < 100000; i++)
    {
        fscanf(Rollpointer, "%d", ptemp1);
        if (roll_no == temp1)
        {
            index1 = i;
            i = 100000;
        }
        else
        {
            if (temp1 == temp2)
            {
                printf("\nError : Entry Not Found\n");
                delay(1);
                i = 100000;
                Upd_Res();
            }
            else
            {
                temp2 = temp1;
            }
        }
    }

    fclose(Rollpointer);

    temp1 = 0;
    temp2 = 1;

    Rollpointer = fopen("Comp_Roll_No.dat", "r");

    for (int i = 0; i < 100000; i++)
    {
        fscanf(Rollpointer, "%d", ptemp1);
        if (temp1 == temp2)
        {
            i = 100000;
        }
        else
        {
            temp2 = temp1;
        }
    }

    fclose(Rollpointer);

    Rollpointer = fopen("Comp_Roll_No.dat", "r");

    Temppointer = fopen("Temp_Roll_No.dat", "w");

    for (int i = index1; i > 0; i--)
    {
        fscanf(Rollpointer, "%d", ptemp1);
        fprintf(Temppointer, "%d\n", temp1);
    }

    fscanf(Rollpointer, "%d", ptemp1);

    for (int i = 0; i < 100000; i++)
    {
        if (temp1 == temp2)
        {
            index2 = i;
            i = 100000;
        }
        else
        {
            fscanf(Rollpointer, "%d", ptemp1);
            fprintf(Temppointer, "%d\n", temp1);
        }
    }

    fclose(Temppointer);

    fclose(Rollpointer);

    system("clear");

    Respointer = fopen("Comp_Result.dat", "r");

    Temp_2pointer = fopen("Temp_Result.dat", "w");

    for (int i = index1; i > 0; i--)
    {
        for (int i = 0; i < 20; i++)
        {
            fgets(output, 50, Respointer);
            fprintf(Temp_2pointer, "%s", output);
        }
    }

    for (int i = 0; i < 20; i++)
    {
        fgets(output, 50, Respointer);
    }

    fseek(Temp_2pointer, -1, SEEK_CUR);

    for (int i = index2; i > 0; i--)
    {
        for (int i = 0; i < 20; i++)
        {
            fgets(output, 50, Respointer);
            fprintf(Temp_2pointer, "%s", output);
        }
    }

    fclose(Temp_2pointer);

    fclose(Respointer);

    Rollpointer = fopen("Comp_Roll_No.dat", "w");

    Temppointer = fopen("Temp_Roll_No.dat", "r");

    for (int i = index1 + index2; i > 0; i--)
    {
        fscanf(Temppointer, "%d", ptemp1);
        fprintf(Rollpointer, "%d\n", temp1);
    }

    fclose(Temppointer);

    fclose(Rollpointer);

    Respointer = fopen("Comp_Result.dat", "w");

    Temp_2pointer = fopen("Temp_Result.dat", "r");

    for (int i = index1 + index2; i > 0; i--)
    {
        for (int i = 0; i < 20; i++)
        {
            fgets(output, 50, Temp_2pointer);
            fprintf(Respointer, "%s", output);
        }
    }

    fclose(Temp_2pointer);

    fclose(Respointer);

    system("clear");

    printf("Enter Name: ");
    scanf("%s%s", st.f_name, st.l_name);

Math:
    printf("Enter Marks in Mathematics  (Total Matks:%.0f): ", MATH);
    scanf("%d", &st.marks.math);
    if (st.marks.math < 0 || st.marks.math > MATH)
    {
        printf("Error :Limit Exceeded\n");
        goto Math;
    }

Eng:
    printf("Enter Marks in English  (Total Matks:%.0f): ", ENG);
    scanf("%d", &st.marks.eng);
    if (st.marks.eng < 0 || st.marks.eng > ENG)
    {
        printf("Error :Limit Exceeded\n");
        goto Eng;
    }

Urdu:
    printf("Enter Marks in Urdu  (Total Matks:%.0f): ", URDU);
    scanf("%d", &st.marks.urdu);
    if (st.marks.urdu < 0 || st.marks.urdu > URDU)
    {
        printf("Error :Limit Exceeded\n");
        goto Urdu;
    }

Chem:
    printf("Enter Marks in Chemistry  (Total Matks:%.0f): ", CHEM);
    scanf("%d", &st.marks.chem);
    if (st.marks.chem < 0 || st.marks.chem > CHEM)
    {
        printf("Error :Limit Exceeded\n");
        goto Chem;
    }

Phy:
    printf("Enter Marks in Physics  (Total Matks:%.0f): ", PHY);
    scanf("%d", &st.marks.phy);
    if (st.marks.phy < 0 || st.marks.phy > PHY)
    {
        printf("Error :Limit Exceeded\n");
        goto Phy;
    }

Comp:
    printf("Enter Marks in Computer  (Total Matks:%.0f): ", COMP);
    scanf("%d", &st.marks.comp);
    if (st.marks.comp < 0 || st.marks.comp > COMP)
    {
        printf("Error :Limit Exceeded\n");
        goto Comp;
    }

Isl:
    printf("Enter Marks in Islamiyat  (Total Matks:%.0f): ", ISL);
    scanf("%d", &st.marks.isl);
    if (st.marks.isl < 0 || st.marks.isl > ISL)
    {
        printf("Error :Limit Exceeded\n");
        goto Isl;
    }

Pak:
    printf("Enter Marks in Pakistan Studies  (Total Matks:%.0f): ", PAK);
    scanf("%d", &st.marks.pak);
    if (st.marks.pak < 0 || st.marks.pak > PAK)
    {
        printf("Error :Limit Exceeded\n");
        goto Pak;
    }

    st.marks.total = st.marks.chem + st.marks.isl + st.marks.eng + st.marks.pak + st.marks.phy + st.marks.urdu + st.marks.math + st.marks.comp;
    st.perc.math = (st.marks.math / MATH) * 100;
    st.perc.eng = (st.marks.eng / ENG) * 100;
    st.perc.urdu = (st.marks.urdu / URDU) * 100;
    st.perc.chem = (st.marks.chem / CHEM) * 100;
    st.perc.phy = (st.marks.phy / PHY) * 100;
    st.perc.comp = (st.marks.comp / COMP) * 100;
    st.perc.isl = (st.marks.isl / ISL) * 100;
    st.perc.pak = (st.marks.pak / PAK) * 100;
    st.perc.total = (st.marks.total / TOTAL_COMP) * 100;

    Rollpointer = fopen("Comp_Roll_No.dat", "a");

    fprintf(Rollpointer, "%d\n", roll_no);

    fclose(Rollpointer);

    Respointer = fopen("Comp_Result.dat", "a");

    fprintf(Respointer, "Name : %s %s\n", st.f_name, st.l_name);
    fprintf(Respointer, "Roll No. : %d\n", roll_no);
    fprintf(Respointer, "Subject   Obt.Marks   Total.Marks   Percentage  \n");
    fprintf(Respointer, "Math      %d          %.0f            %.2f        \n", st.marks.math, MATH, st.perc.math);
    fprintf(Respointer, "Eng       %d          %.0f            %.2f        \n", st.marks.eng, ENG, st.perc.eng);
    fprintf(Respointer, "Urdu      %d          %.0f            %.2f        \n", st.marks.urdu, URDU, st.perc.urdu);
    fprintf(Respointer, "Chem      %d          %.0f            %.2f        \n", st.marks.chem, CHEM, st.perc.chem);
    fprintf(Respointer, "Phy       %d          %.0f            %.2f        \n", st.marks.phy, PHY, st.perc.phy);
    fprintf(Respointer, "Comp      %d          %.0f            %.2f        \n", st.marks.comp, COMP, st.perc.comp);
    fprintf(Respointer, "Isl       %d          %.0f            %.2f        \n", st.marks.isl, ISL, st.perc.isl);
    fprintf(Respointer, "Pak       %d          %.0f            %.2f        \n", st.marks.pak, PAK, st.perc.pak);
    fprintf(Respointer, "Total     %d         %.0f           %.2f         \n", st.marks.total, TOTAL_COMP, st.perc.total);

    fclose(Respointer);

    system("clear");

    printf("\n1.Update Result");
    printf("\n2.Main Menu");
    printf("\n3.Exit");

Main_Menu:
    printf("\n\n\tEnter Choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("clear");
        Upd_Res();
        break;
    case 2:
        system("clear");
        Admin();
        break;
    case 3:
    Exit:
        system("clear");
        printf("\n\n\n\nThank You!\n\n\n\n");
        break;
    default:
        printf("\nError : Invalid Option\n\n");
        goto Main_Menu;
        break;
    }
}

void Bio_Upd()
{
    int roll_no, index1 = -2, index2 = -2;

    struct Student st;

    char output[51], indicator;

    FILE *Rollpointer, *Temppointer, *Respointer, *Temp_2pointer;

Roll_Entry:
    int temp1 = 0, temp2 = 1;
    int *ptemp1;
    ptemp1 = &temp1;

    printf("Enter Roll No.(%d-%d): ", LOWER_LIMIT, UPPER_LIMIT);
    scanf("%d", &roll_no);
    if (roll_no < LOWER_LIMIT || roll_no > UPPER_LIMIT)
    {
        printf("Error : Invalid Roll Number\n");
        goto Roll_Entry;
    }

    Rollpointer = fopen("Bio_Roll_No.dat", "r");

    for (int i = 0; i < 100000; i++)
    {
        fscanf(Rollpointer, "%d", ptemp1);
        if (roll_no == temp1)
        {
            index1 = i;
            i = 100000;
        }
        else
        {
            if (temp1 == temp2)
            {
                printf("\nError : Entry Not Found\n");
                delay(1);
                i = 100000;
                Upd_Res();
            }
            else
            {
                temp2 = temp1;
            }
        }
    }

    fclose(Rollpointer);

    temp1 = 0;
    temp2 = 1;

    Rollpointer = fopen("Bio_Roll_No.dat", "r");

    for (int i = 0; i < 100000; i++)
    {
        fscanf(Rollpointer, "%d", ptemp1);
        if (temp1 == temp2)
        {
            i = 100000;
        }
        else
        {
            temp2 = temp1;
        }
    }

    fclose(Rollpointer);

    Rollpointer = fopen("Bio_Roll_No.dat", "r");

    Temppointer = fopen("Temp_Roll_No.dat", "w");

    for (int i = index1; i > 0; i--)
    {
        fscanf(Rollpointer, "%d", ptemp1);
        fprintf(Temppointer, "%d\n", temp1);
    }

    fscanf(Rollpointer, "%d", ptemp1);

    for (int i = 0; i < 100000; i++)
    {
        if (temp1 == temp2)
        {
            index2 = i;
            i = 100000;
        }
        else
        {
            fscanf(Rollpointer, "%d", ptemp1);
            fprintf(Temppointer, "%d\n", temp1);
        }
    }

    fclose(Temppointer);

    fclose(Rollpointer);

    system("clear");

    Respointer = fopen("Bio_Result.dat", "r");

    Temp_2pointer = fopen("Temp_Result.dat", "w");

    for (int i = index1; i > 0; i--)
    {
        for (int i = 0; i < 20; i++)
        {
            fgets(output, 50, Respointer);
            fprintf(Temp_2pointer, "%s", output);
        }
    }

    for (int i = 0; i < 20; i++)
    {
        fgets(output, 50, Respointer);
    }

    fseek(Temp_2pointer, -1, SEEK_CUR);

    for (int i = index2; i > 0; i--)
    {
        for (int i = 0; i < 20; i++)
        {
            fgets(output, 50, Respointer);
            fprintf(Temp_2pointer, "%s", output);
        }
    }

    fclose(Temp_2pointer);

    fclose(Respointer);

    Rollpointer = fopen("Bio_Roll_No.dat", "w");

    Temppointer = fopen("Temp_Roll_No.dat", "r");

    for (int i = index1 + index2; i > 0; i--)
    {
        fscanf(Temppointer, "%d", ptemp1);
        fprintf(Rollpointer, "%d\n", temp1);
    }

    fclose(Temppointer);

    fclose(Rollpointer);

    Respointer = fopen("Bio_Result.dat", "w");

    Temp_2pointer = fopen("Temp_Result.dat", "r");

    for (int i = index1 + index2; i > 0; i--)
    {
        for (int i = 0; i < 20; i++)
        {
            fgets(output, 50, Temp_2pointer);
            fprintf(Respointer, "%s", output);
        }
    }

    fclose(Temp_2pointer);

    fclose(Respointer);

    system("clear");

    printf("Enter Name: ");
    scanf("%s%s", st.f_name, st.l_name);

Math:
    printf("Enter Marks in Mathematics  (Total Matks:%.0f): ", MATH);
    scanf("%d", &st.marks.math);
    if (st.marks.math < 0 || st.marks.math > MATH)
    {
        printf("Error :Limit Exceeded\n");
        goto Math;
    }

Eng:
    printf("Enter Marks in English  (Total Matks:%.0f): ", ENG);
    scanf("%d", &st.marks.eng);
    if (st.marks.eng < 0 || st.marks.eng > ENG)
    {
        printf("Error :Limit Exceeded\n");
        goto Eng;
    }

Urdu:
    printf("Enter Marks in Urdu  (Total Matks:%.0f): ", URDU);
    scanf("%d", &st.marks.urdu);
    if (st.marks.urdu < 0 || st.marks.urdu > URDU)
    {
        printf("Error :Limit Exceeded\n");
        goto Urdu;
    }

Chem:
    printf("Enter Marks in Chemistry  (Total Matks:%.0f): ", CHEM);
    scanf("%d", &st.marks.chem);
    if (st.marks.chem < 0 || st.marks.chem > CHEM)
    {
        printf("Error :Limit Exceeded\n");
        goto Chem;
    }

Phy:
    printf("Enter Marks in Physics  (Total Matks:%.0f): ", PHY);
    scanf("%d", &st.marks.phy);
    if (st.marks.phy < 0 || st.marks.phy > PHY)
    {
        printf("Error :Limit Exceeded\n");
        goto Phy;
    }

Comp:
    printf("Enter Marks in Biology  (Total Matks:%.0f): ", BIO);
    scanf("%d", &st.marks.bio);
    if (st.marks.bio < 0 || st.marks.bio > BIO)
    {
        printf("Error :Limit Exceeded\n");
        goto Comp;
    }

Isl:
    printf("Enter Marks in Islamiyat  (Total Matks:%.0f): ", ISL);
    scanf("%d", &st.marks.isl);
    if (st.marks.isl < 0 || st.marks.isl > ISL)
    {
        printf("Error :Limit Exceeded\n");
        goto Isl;
    }

Pak:
    printf("Enter Marks in Pakistan Studies  (Total Matks:%.0f): ", PAK);
    scanf("%d", &st.marks.pak);
    if (st.marks.pak < 0 || st.marks.pak > PAK)
    {
        printf("Error :Limit Exceeded\n");
        goto Pak;
    }

    st.marks.total = st.marks.chem + st.marks.isl + st.marks.eng + st.marks.pak + st.marks.phy + st.marks.urdu + st.marks.math + st.marks.bio;
    st.perc.math = (st.marks.math / MATH) * 100;
    st.perc.eng = (st.marks.eng / ENG) * 100;
    st.perc.urdu = (st.marks.urdu / URDU) * 100;
    st.perc.chem = (st.marks.chem / CHEM) * 100;
    st.perc.phy = (st.marks.phy / PHY) * 100;
    st.perc.bio = (st.marks.bio / BIO) * 100;
    st.perc.isl = (st.marks.isl / ISL) * 100;
    st.perc.pak = (st.marks.pak / PAK) * 100;
    st.perc.total = (st.marks.total / TOTAL_BIO) * 100;

    Rollpointer = fopen("Bio_Roll_No.dat", "a");

    fprintf(Rollpointer, "%d\n", roll_no);

    fclose(Rollpointer);

    Respointer = fopen("Bio_Result.dat", "a");

    fprintf(Respointer, "Name : %s %s\n", st.f_name, st.l_name);
    fprintf(Respointer, "Roll No. : %d\n", roll_no);
    fprintf(Respointer, "Subject   Obt.Marks   Total.Marks   Percentage  \n");
    fprintf(Respointer, "Math      %d          %.0f            %.2f        \n", st.marks.math, MATH, st.perc.math);
    fprintf(Respointer, "Eng       %d          %.0f            %.2f        \n", st.marks.eng, ENG, st.perc.eng);
    fprintf(Respointer, "Urdu      %d          %.0f            %.2f        \n", st.marks.urdu, URDU, st.perc.urdu);
    fprintf(Respointer, "Chem      %d          %.0f            %.2f        \n", st.marks.chem, CHEM, st.perc.chem);
    fprintf(Respointer, "Phy       %d          %.0f            %.2f        \n", st.marks.phy, PHY, st.perc.phy);
    fprintf(Respointer, "Biol      %d          %.0f            %.2f        \n", st.marks.bio, BIO, st.perc.bio);
    fprintf(Respointer, "Isl       %d          %.0f            %.2f        \n", st.marks.isl, ISL, st.perc.isl);
    fprintf(Respointer, "Pak       %d          %.0f            %.2f        \n", st.marks.pak, PAK, st.perc.pak);
    fprintf(Respointer, "Total     %d         %.0f           %.2f         \n", st.marks.total, TOTAL_BIO, st.perc.total);
    fclose(Respointer);

    system("clear");

    printf("\n1.Update Result");
    printf("\n2.Main Menu");
    printf("\n3.Exit");

Main_Menu:
    printf("\n\n\tEnter Choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("clear");
        Upd_Res();
        break;
    case 2:
        system("clear");
        Admin();
        break;
    case 3:
    Exit:
        system("clear");
        printf("\n\n\n\nThank You!\n\n\n\n");
        break;
    default:
        printf("\nError : Invalid Option\n\n");
        goto Main_Menu;
        break;
    }
}

void Del_Ent()
{
    system("clear");

    printf("\tDelete Entry\n");
    printf("\n1.Computer");
    printf("\n2.Biology");
    printf("\n3.Main Menu");
    printf("\n4.Exit");

Bio_Comp:
    printf("\n\n\tEnter Choice:");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("clear");
        Comp_Del();
        break;
    case 2:
        system("clear");
        Bio_Del();
        break;
    case 3:
        system("clear");
        Admin();
        break;
    case 4:
        system("clear");
        printf("\n\n\n\nThank You!\n\n\n\n");
        break;
    default:
        printf("\nError : Invalid Option\n\n");
        goto Bio_Comp;
        break;
    }
}

void Comp_Del()
{
    int roll_no, index1 = -2, index2 = -2;

    char output[51], indicator;

    FILE *Rollpointer, *Temppointer, *Respointer, *Temp_2pointer;

Roll_Entry:
    int temp1 = 0, temp2 = 1;
    int *ptemp1;
    ptemp1 = &temp1;

    printf("Enter Roll No.(%d-%d): ", LOWER_LIMIT, UPPER_LIMIT);
    scanf("%d", &roll_no);
    if (roll_no < LOWER_LIMIT || roll_no > UPPER_LIMIT)
    {
        printf("Error : Invalid Roll Number\n");
        goto Roll_Entry;
    }

    Rollpointer = fopen("Comp_Roll_No.dat", "r");

    for (int i = 0; i < 100000; i++)
    {
        fscanf(Rollpointer, "%d", ptemp1);
        if (roll_no == temp1)
        {
            index1 = i;
            i = 100000;
        }
        else
        {
            if (temp1 == temp2)
            {
                printf("\nError : Entry Not Found\n");
                delay(1);
                i = 100000;
                Del_Ent();
            }
            else
            {
                temp2 = temp1;
            }
        }
    }

    fclose(Rollpointer);

    temp1 = 0;
    temp2 = 1;

    Rollpointer = fopen("Comp_Roll_No.dat", "r");

    for (int i = 0; i < 100000; i++)
    {
        fscanf(Rollpointer, "%d", ptemp1);
        if (temp1 == temp2)
        {
            i = 100000;
        }
        else
        {
            temp2 = temp1;
        }
    }

    fclose(Rollpointer);

    Rollpointer = fopen("Comp_Roll_No.dat", "r");

    Temppointer = fopen("Temp_Roll_No.dat", "w");

    for (int i = index1; i > 0; i--)
    {
        fscanf(Rollpointer, "%d", ptemp1);
        fprintf(Temppointer, "%d\n", temp1);
    }

    fscanf(Rollpointer, "%d", ptemp1);

    for (int i = 0; i < 100000; i++)
    {
        if (temp1 == temp2)
        {
            index2 = i;
            i = 100000;
        }
        else
        {
            fscanf(Rollpointer, "%d", ptemp1);
            fprintf(Temppointer, "%d\n", temp1);
        }
    }

    fclose(Temppointer);

    fclose(Rollpointer);

    system("clear");

    Respointer = fopen("Comp_Result.dat", "r");

    Temp_2pointer = fopen("Temp_Result.dat", "w");

    for (int i = index1; i > 0; i--)
    {
        for (int i = 0; i < 20; i++)
        {
            fgets(output, 50, Respointer);
            fprintf(Temp_2pointer, "%s", output);
        }
    }

    for (int i = 0; i < 20; i++)
    {
        fgets(output, 50, Respointer);
    }

    fseek(Temp_2pointer, -1, SEEK_CUR);

    for (int i = index2; i > 0; i--)
    {
        for (int i = 0; i < 20; i++)
        {
            fgets(output, 50, Respointer);
            fprintf(Temp_2pointer, "%s", output);
        }
    }

    fclose(Temp_2pointer);

    fclose(Respointer);

    Rollpointer = fopen("Comp_Roll_No.dat", "w");

    Temppointer = fopen("Temp_Roll_No.dat", "r");

    for (int i = index1 + index2; i > 0; i--)
    {
        fscanf(Temppointer, "%d", ptemp1);
        fprintf(Rollpointer, "%d\n", temp1);
    }

    fclose(Temppointer);

    fclose(Rollpointer);

    Respointer = fopen("Comp_Result.dat", "w");

    Temp_2pointer = fopen("Temp_Result.dat", "r");

    for (int i = index1 + index2; i > 0; i--)
    {
        for (int i = 0; i < 20; i++)
        {
            fgets(output, 50, Temp_2pointer);
            fprintf(Respointer, "%s", output);
        }
    }

    fclose(Temp_2pointer);

    fclose(Respointer);

    system("clear");

    printf("\n1.Delete Entry");
    printf("\n2.Main Menu");
    printf("\n3.Exit");

Main_Menu:
    printf("\n\n\tEnter Choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("clear");
        Del_Ent();
        break;
    case 2:
        system("clear");
        Admin();
        break;
    case 3:
    Exit:
        system("clear");
        printf("\n\n\n\nThank You!\n\n\n\n");
        break;
    default:
        printf("\nError : Invalid Option\n\n");
        goto Main_Menu;
        break;
    }
}

void Bio_Del()
{
    int roll_no, index1 = -2, index2 = -2;

    char output[51], indicator;

    FILE *Rollpointer, *Temppointer, *Respointer, *Temp_2pointer;

Roll_Entry:
    int temp1 = 0, temp2 = 1;
    int *ptemp1;
    ptemp1 = &temp1;

    printf("Enter Roll No.(%d-%d): ", LOWER_LIMIT, UPPER_LIMIT);
    scanf("%d", &roll_no);
    if (roll_no < LOWER_LIMIT || roll_no > UPPER_LIMIT)
    {
        printf("Error : Invalid Roll Number\n");
        goto Roll_Entry;
    }

    Rollpointer = fopen("Bio_Roll_No.dat", "r");

    for (int i = 0; i < 100000; i++)
    {
        fscanf(Rollpointer, "%d", ptemp1);
        if (roll_no == temp1)
        {
            index1 = i;
            i = 100000;
        }
        else
        {
            if (temp1 == temp2)
            {
                printf("\nError : Entry Not Found\n");
                delay(1);
                i = 100000;
                Del_Ent();
            }
            else
            {
                temp2 = temp1;
            }
        }
    }

    fclose(Rollpointer);

    temp1 = 0;
    temp2 = 1;

    Rollpointer = fopen("Bio_Roll_No.dat", "r");

    for (int i = 0; i < 100000; i++)
    {
        fscanf(Rollpointer, "%d", ptemp1);
        if (temp1 == temp2)
        {
            i = 100000;
        }
        else
        {
            temp2 = temp1;
        }
    }

    fclose(Rollpointer);

    Rollpointer = fopen("Bio_Roll_No.dat", "r");

    Temppointer = fopen("Temp_Roll_No.dat", "w");

    for (int i = index1; i > 0; i--)
    {
        fscanf(Rollpointer, "%d", ptemp1);
        fprintf(Temppointer, "%d\n", temp1);
    }

    fscanf(Rollpointer, "%d", ptemp1);

    for (int i = 0; i < 100000; i++)
    {
        if (temp1 == temp2)
        {
            index2 = i;
            i = 100000;
        }
        else
        {
            fscanf(Rollpointer, "%d", ptemp1);
            fprintf(Temppointer, "%d\n", temp1);
        }
    }

    fclose(Temppointer);

    fclose(Rollpointer);

    system("clear");

    Respointer = fopen("Bio_Result.dat", "r");

    Temp_2pointer = fopen("Temp_Result.dat", "w");

    for (int i = index1; i > 0; i--)
    {
        for (int i = 0; i < 20; i++)
        {
            fgets(output, 50, Respointer);
            fprintf(Temp_2pointer, "%s", output);
        }
    }

    for (int i = 0; i < 20; i++)
    {
        fgets(output, 50, Respointer);
    }

    fseek(Temp_2pointer, -1, SEEK_CUR);

    for (int i = index2; i > 0; i--)
    {
        for (int i = 0; i < 20; i++)
        {
            fgets(output, 50, Respointer);
            fprintf(Temp_2pointer, "%s", output);
        }
    }

    fclose(Temp_2pointer);

    fclose(Respointer);

    Rollpointer = fopen("Bio_Roll_No.dat", "w");

    Temppointer = fopen("Temp_Roll_No.dat", "r");

    for (int i = index1 + index2; i > 0; i--)
    {
        fscanf(Temppointer, "%d", ptemp1);
        fprintf(Rollpointer, "%d\n", temp1);
    }

    fclose(Temppointer);

    fclose(Rollpointer);

    Respointer = fopen("Bio_Result.dat", "w");

    Temp_2pointer = fopen("Temp_Result.dat", "r");

    for (int i = index1 + index2; i > 0; i--)
    {
        for (int i = 0; i < 20; i++)
        {
            fgets(output, 50, Temp_2pointer);
            fprintf(Respointer, "%s", output);
        }
    }

    fclose(Temp_2pointer);

    fclose(Respointer);

    system("clear");

    printf("\n1.Delete Entry");
    printf("\n2.Main Menu");
    printf("\n3.Exit");

Main_Menu:
    printf("\n\n\tEnter Choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("clear");
        Del_Ent();
        break;
    case 2:
        system("clear");
        Admin();
        break;
    case 3:
    Exit:
        system("clear");
        printf("\n\n\n\nThank You!\n\n\n\n");
        break;
    default:
        printf("\nError : Invalid Option\n\n");
        goto Main_Menu;
        break;
    }
}

void User()
{
    system("clear");

    printf("\tUser\n");
    printf("\n1.View Result");
    printf("\n2.Exit");

Main_Menu:
    printf("\n\tEnter Choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        View_Res();
        break;
    case 2:
        system("clear");
        printf("\n\n\n\nThank You!\n\n\n\n");
        goto Exit;
        break;
    default:
        printf("\nError : Invalid Option\n");
        goto Main_Menu;
        break;
    }

Exit:
}

void View_Res()
{
    system("clear");

    printf("\tView Result\n");
    printf("\n1.Computer");
    printf("\n2.Biology");
    printf("\n3.Main Menu");
    printf("\n4.Exit");

Bio_Comp:
    printf("\n\n\tEnter Choice:");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("clear");
        Comp_View();
        break;
    case 2:
        system("clear");
        Bio_View();
        break;
    case 3:
        system("clear");
        switch (counter)
        {
        case 0:
            User();
            break;
        case 1:
            Admin();
            break;
        default:

            break;
        }
        break;
    case 4:
        system("clear");
        printf("\n\n\n\nThank You!\n\n\n\n");
        break;
    default:
        printf("\nError : Invalid Option\n\n");
        goto Bio_Comp;
        break;
    }
}

void Comp_View()
{
    int roll_no, index;

    char output[50], indicator;

Roll_Entry:
    int temp = 0, temp2 = 1;
    int *ptemp;
    ptemp = &temp;

    printf("Enter Roll No.(%d-%d): ", LOWER_LIMIT, UPPER_LIMIT);
    scanf("%d", &roll_no);
    if (roll_no < LOWER_LIMIT || roll_no > UPPER_LIMIT)
    {
        printf("Error : Invalid Roll Number\n");
        goto Roll_Entry;
    }

    FILE *Rollpointer = fopen("Comp_Roll_No.dat", "r");

    for (int i = 0; i < 100000; i++)
    {
        fscanf(Rollpointer, "%d", ptemp);
        if (roll_no == temp)
        {
            index = i;
            i = 100000;
        }
        else
        {
            if (temp == temp2)
            {
                printf("\nError : Entry Not Found\n");
                delay(1);
                i = 100000;
                View_Res();
            }
            else
            {
                temp2 = temp;
            }
        }
    }

    fclose(Rollpointer);

    system("clear");

    FILE *Respointer = fopen("Comp_Result.dat", "r");

    for (size_t i = index; i > 0; i--)
    {
        for (int i = 0; i < 20; i++)
        {
            fgets(output, 50, Respointer);
        }
    }

    for (int i = 0; i < 20; i++)
    {
        fgets(output, 50, Respointer);
        printf("%s", output);
    }

    fclose(Respointer);

    printf("\n\nPress Enter to Continue");
    scanf("%c", &indicator);
    scanf("%c", &indicator);

    system("clear");

    printf("\n1.View Result");
    printf("\n2.Main Menu");
    printf("\n3.Exit");

Main_Menu:
    printf("\n\n\tEnter Choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("clear");
        View_Res();
        break;
    case 2:
        system("clear");
        switch (counter)
        {
        case 0:
            User();
            break;
        case 1:
            Admin();
            break;
        default:

            break;
        }
        break;
    case 3:
        system("clear");
        printf("\n\n\n\nThank You!\n\n\n\n");
        break;
    default:
        printf("\nError : Invalid Option\n\n");
        goto Main_Menu;
        break;
    }
}

void Bio_View()
{
    int roll_no, index;

    char output[50], indicator;

Roll_Entry:
    int temp = 0, temp2 = 1;
    int *ptemp;
    ptemp = &temp;

    printf("Enter Roll No.(%d-%d): ", LOWER_LIMIT, UPPER_LIMIT);
    scanf("%d", &roll_no);
    if (roll_no < LOWER_LIMIT || roll_no > UPPER_LIMIT)
    {
        printf("Error : Invalid Roll Number\n");
        goto Roll_Entry;
    }

    FILE *Rollpointer = fopen("Bio_Roll_No.dat", "r");

    for (int i = 0; i < 100000; i++)
    {
        fscanf(Rollpointer, "%d", ptemp);
        if (roll_no == temp)
        {
            index = i;
            i = 100000;
        }
        else
        {
            if (temp == temp2)
            {
                printf("\nError : Entry Not Found\n");
                delay(1);
                i = 100000;
                View_Res();
            }
            else
            {
                temp2 = temp;
            }
        }
    }

    fclose(Rollpointer);

    system("clear");

    FILE *Respointer = fopen("Bio_Result.dat", "r");

    for (size_t i = index; i > 0; i--)
    {
        for (int i = 0; i < 20; i++)
        {
            fgets(output, 50, Respointer);
        }
    }

    for (int i = 0; i < 20; i++)
    {
        fgets(output, 50, Respointer);
        printf("%s", output);
    }

    fclose(Respointer);

    printf("\n\nPress Enter to Continue");
    scanf("%c", &indicator);
    scanf("%c", &indicator);

    system("clear");

    printf("\n1.View Result");
    printf("\n2.Main Menu");
    printf("\n3.Exit");

Main_Menu:
    printf("\n\n\tEnter Choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("clear");
        View_Res();
        break;
    case 2:
        system("clear");
        switch (counter)
        {
        case 0:
            User();
            break;
        case 1:
            Admin();
            break;
        default:

            break;
        }
        break;
    case 3:
        system("clear");
        printf("\n\n\n\nThank You!\n\n\n\n");
        break;
    default:
        printf("\nError : Invalid Option\n\n");
        goto Main_Menu;
        break;
    }
}

int delay(int para)
{
    int temp;
    for (int i = 1; i <= para; i++)
    {
        for (int i = 0; i < 500000000; i++)
        {
            temp = temp * 2;
        }
    }
    return 0;
}