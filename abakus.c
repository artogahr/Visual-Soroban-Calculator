#include <stdio.h>
#include <unistd.h>
void printabacus(int ones, int tens, int huns, int thos);
void addition(int n1, int n2);
void initialprint();
void numbersset(int c, int b);
void resetabacus();
void incrementones();
void decrementones();
void decrementtens();
void incrementtens();
void decrementhuns();
void incrementhuns();
void substraction(int nr1, int nr2);

//tum rakamlari saklayan bir array
char a[10][5];
int oper, n1, n2, nrr1, nrr2, ones1, ones2, tens1, tens2, huns1, huns2, thos1, thos2, milliseconds;

int main()
{
    //girilen rakamlari ve operasyon secimini alir
    initialprint();

    switch (oper)
    {
    case 1:
        addition(n1, n2);
        break;
    case 2:
        substraction(n1, n2);
        break;
    case 3:
        printf("\nDoes not work a.t.m.\n");
        break;
    }

    return 0;
}

void addition(int nr1, int nr2)
{
    //10a modul alma yoluyla teklik onluk ve s. basamaklari aliyor
    n1 = nr1;
    n2 = nr2;
    nrr1 = nr1;
    nrr2 = nr2;
    ones1 = n1 % 10;
    n1 = n1 / 10;
    tens1 = n1 % 10;
    n1 = n1 / 10;
    huns1 = n1 % 10;
    n1 = n1 / 10;
    thos1 = n1 % 10;
    ones2 = n2 % 10;
    n2 = n2 / 10;
    tens2 = n2 % 10;
    n2 = n2 / 10;
    huns2 = n2 % 10;
    n2 = n2 / 10;
    thos2 = n2 % 10;
    printf("\n\n\033c\n\n");
    printf("\n%d + %d\n\n\n", nr1, nr2);
    printabacus(ones1, tens1, huns1, thos1);//birinci girilen rakamin abakusunu bastiriyor
    sleep(1);
    printf("Program Basliyor\n");
    sleep(2);
    printf("\n\n\033c\n\n");

    if (ones2 != 0) // ikinci rakamda bir basamak 0sa o basamaga bir sey eklemiyor
    {
        
        for (int i = 0; i < ones2; i++)
        {
            //her defasinda abakusu print ediyor bir adet arttiriyor 1 san bekliyor ve ekrani temizliyor
            printf("\nTeklikler %d kadar artirilacak\n\n\n", ones2);
            printabacus(ones1, tens1, huns1, thos1);
            incrementones();
            usleep(1000 * milliseconds);

            printf("\n\n\033c\n\n");
        }
    }

    if (tens2 != 0)
    {
        
        for (int i = 0; i < tens2; i++)
        {

            printf("\nOnluklarr %d kadar artirilacak\n\n\n", tens2);
            printabacus(ones1, tens1, huns1, thos1);
            incrementtens();
            usleep(1000 * milliseconds);

            printf("\033c");
        }
    }

    if (huns2 != 0)
    {

        for (int i = 0; i < huns2; i++)
        {

            printf("\nYuzlukler %d kadar artirilacak\n\n\n", huns2);
            printabacus(ones1, tens1, huns1, thos1);
            incrementhuns();
            usleep(1000 * milliseconds);
            printf("\033c");
        }
    }
    if (thos2 != 0)
    {
        for (int i = 0; i <= thos2; i++)
        {

            printf("\nYuzlukler %d kadar artirilacak\n\n\n", huns2);
            printabacus(ones1, tens1, huns1, thos1);
            thos1++;
            usleep(1000 * milliseconds);
            printf("\033c");
        }
    }

    printf("\n%d + %d = %d\n\n\n", nrr1, nrr2, nrr1 + nrr2);
    //fonksiyon sonlandiginda en sondaki abakusu bastiriyor
    printabacus(ones1, tens1, huns1, thos1);
}
void incrementones()
{
    printf("\n%d %d %d %d\n", thos1, huns1, tens1, ones1);
    //eger 1likler 9 sa 1likleri 0a esitliyor ve onluklari 1 adet aartiriyor
    if (ones1 == 9)
    {
        ones1 = 0;
        tens1++;
    }
    else
    {
        ones1++;
    }
    if (tens1 == 10)
    {
        tens1 = 0;
        huns1++;
    }
    if (huns1 == 10)
    {
        huns1 = 0;
        thos1++;
    }
}

void substraction(int nr1, int nr2)
{
    n1 = nr1;
    n2 = nr2;
    nrr1 = nr1;
    nrr2 = nr2;
    ones1 = n1 % 10;
    n1 = n1 / 10;
    tens1 = n1 % 10;
    n1 = n1 / 10;
    huns1 = n1 % 10;
    n1 = n1 / 10;
    thos1 = n1 % 10;
    ones2 = n2 % 10;
    n2 = n2 / 10;
    tens2 = n2 % 10;
    n2 = n2 / 10;
    huns2 = n2 % 10;
    n2 = n2 / 10;
    thos2 = n2 % 10;
    printf("\n\n\033c\n\n");
    printf("\n%d - %d\n\n\n", nr1, nr2);
    printabacus(ones1, tens1, huns1, thos1);
    sleep(1);
    printf("Program Basliyor\n");
    sleep(2);
    printf("\n\n\033c\n\n");

    if (ones2 != 0)
    {
       
        for (int i = 0; i < ones2; i++)
        {

            printf("\nTeklikler %d kadar azaltilacak\n\n\n", ones2);
            printabacus(ones1, tens1, huns1, thos1);
            decrementones();
            usleep(1000 * milliseconds);
            printf("\n\n\033c");
        }
    }

    if (tens2 != 0)
    {
        
        for (int i = 0; i < tens2; i++)
        {

            printf("\nOnluklarr %d kadar azaltilacak\n\n\n", tens2);
            printabacus(ones1, tens1, huns1, thos1);
            decrementtens();
            usleep(1000 * milliseconds);
            printf("\n\n\033c");
        }
        
    }

    if (huns2 != 0)
    {
        
        for (int i = 0; i < huns2; i++)
        {

            printf("\nYuzlukler %d kadar azaltilacak\n\n\n", huns2);
            printabacus(ones1, tens1, huns1, thos1);
            decrementhuns();
            usleep(1000 * milliseconds);
            printf("\n\n\033c");
        }
    }
    printf("\n%d - %d = %d\n\n\n", nrr1, nrr2, nrr1 - nrr2);
    printabacus(ones1, tens1, huns1, thos1);
}

void printabacus(int ones, int tens, int huns, int thos)
{
    resetabacus();
    numbersset(9, ones);
    numbersset(8, tens);
    numbersset(7, huns);
    numbersset(6, thos);

    printf("%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\n", a[0][0], a[1][0], a[2][0], a[3][0], a[4][0], a[5][0], a[6][0], a[7][0], a[8][0], a[9][0]);
    for (int i = 0; i < 75; i++)
    {

        printf("-");
    }
    printf("\n");
    printf("%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\n", a[0][1], a[1][1], a[2][1], a[3][1], a[4][1], a[5][1], a[6][1], a[7][1], a[8][1], a[9][1]);
    printf("%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\n", a[0][2], a[1][2], a[2][2], a[3][2], a[4][2], a[5][2], a[6][2], a[7][2], a[8][2], a[9][2]);
    printf("%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\n", a[0][3], a[1][3], a[2][3], a[3][3], a[4][3], a[5][3], a[6][3], a[7][3], a[8][3], a[9][3]);
    printf("%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\n", a[0][4], a[1][4], a[2][4], a[3][4], a[4][4], a[5][4], a[6][4], a[7][4], a[8][4], a[9][4]);
    printf("\n\n");
    for (int i = 0; i < 75; i++)
    {
        printf("|");
    }
    printf("\n\n");
    resetabacus(); //ondan onceki abakusten izler kalmasin diye tum abakusu deaktiv durumuna getiriyor
}

void initialprint()
{
    printf("\nIsleminizi secin:\n1) Toplama\n2) Cikma\n3) Carpma\n\n");
    scanf("%d", &oper);
    printf("Rakamlarinizi giriniz:\n\n");
    scanf("%d %d", &n1, &n2);
    printf("Programin calisma periodunu millisaniye ile giriniz:\n\n");
    scanf("%d", &milliseconds);
}

void numbersset(int c, int b)
{
    //rakam 5ten buyukse 5lik basamaktaki degeri etkinlestirip rakamdan 1 cikiyor
    if (b >= 5)
    {
        a[c][0] = 'O';
        b = b - 5;
    }
    for (int i = 1; i <= b; i++)//kalan rakam kac adetse o kadar basamagi etkinlestiriyor
    {
        a[c][i] = 'O';
    }
}

void resetabacus()
{
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 5; j++)
        {
            a[i][j] = '|';
        }
    }
}

void decrementones()
{
    printf("\n%d %d %d %d\n", thos1, huns1, tens1, ones1);
    if (ones1 == 0)
    {
        ones1 = 9;
        tens1--;
    }
    else
    {
        ones1--;
    }
    if (tens1 == -1)
    {
        tens1 = 9;
        huns1--;
    }
    if (huns1 == -1)
    {
        huns1 = 9;
        thos1--;
    }
}

void decrementtens()
{
    printf("\n%d %d %d %d\n", thos1, huns1, tens1, ones1);
    if (tens1 == 0)
    {
        tens1 = 9;
        huns1--;
    }
    else
    {

        tens1--;
    }
    if (huns1 == -1)
    {
        huns1 = 9;
        thos1--;
    }
}
void incrementtens()
{
    printf("\n%d %d %d %d\n", thos1, huns1, tens1, ones1);

    if (tens1 == 9)
    {
        tens1 = 0;
        huns1++;
    }
    else
    {

        tens1++;
    }
    if (huns1 == 10)
    {
        huns1 = 0;
        thos1++;
    }
}
void incrementhuns()
{
    printf("\n%d %d %d %d\n", thos1, huns1, tens1, ones1);
    if (huns1 == 9)
    {
        huns1 = 0;
        thos1++;
    }
    else
    {

        huns1++;
    }
}

void decrementhuns()
{
    if (huns1 == 0)
    {
        huns1 = 9;
        thos1--;
    }
    else
    {

        huns1--;
    }
}
