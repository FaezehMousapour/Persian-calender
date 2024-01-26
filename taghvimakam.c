#include <stdio.h>
#include <stdlib.h>
int choice, year, month, esfand, tedad_kabiseh = 0;
int todayy, todaym, todayd, birthy, birthm, birthd;
int past_d, past_m, past_y;
int sh_year, sh_month, sh_day, m_year, m_month, m_day;
int shamsi_year, shamsi_month, shamsi_day, miladi_year, miladi_month, miladi_day;
void menu();
void quit();
void back_to_menu();
int menu_choice_cheker(int choice);
int calender_year_checker(int year);
int calender_month_checker(int month);
int solar_leap_years(int year);
void printing_month(int month);
void taghvim(int esfand, int tedad_kabiseh, int month, int year);
void age_calculate(int todayy, int todaym, int todayd, int birthy, int birthm, int birthd);
int age_dates_checker(int todayy, int todaym, int todayd, int birthy, int birthm, int birthd);
int shamsi_to_miladi_date_checker(int sh_year, int sh_month, int sh_day);
int shamsi_to_miladi(int sh_year, int sh_month, int sh_day, int flagg);
void represent_shamsi_to_miladi(int miladi_year, int miladi_month, int miladi_day, int sh_year, int sh_month, int sh_day);
int miladi_to_shamsi_date_checker(int m_year, int m_month, int m_day);
int miladi_to_shamsi(int m_year, int m_month, int m_day);
void represent_miladi_to_shamsi(int shamsi_year, int shamsi_month, int shamsi_day, int m_year, int m_month, int m_day);
void represent_miladi_tarikh_tavalod(int miladi_year, int miladi_month, int miladi_day);
int main()
{
   menu();
   printf("\033[90mplease enter a option:");
   printf("\033[0m");
   scanf("%d", &choice);
   menu_choice_cheker(choice);
}
void menu()
{
   printf("\033[1m");
   printf("\n------------------MENU------------------");
   printf("\033[0m\n");
   printf("\n");
   printf("\033[90m [0] \033[0m\033[1m Quit\n\n");
   printf("\033[90m [1] \033[0m\033[1m Calender\n\n");
   printf("\033[90m [2] \033[0m\033[1m Age Calculation\n\n");
   printf("\033[90m [3] \033[0m\033[1m Date Conversion\n\n");
   printf("\033[1m");
   printf("----------------------------------------\n");
   printf("\033[0m");
}
void quit()
{
   system("cls");
   printf("\033[1m");
   printf("------------------Quit------------------\033[0m\n\n");
   printf("\033[34m");
   printf("Bye!");
   printf("\033[0m");
}
void back_to_menu()
{
   system("cls");
   printf("\033[32m");
   printf("\033[1m");
   printf("welcome back to home page :)\n");
   printf("\033[0m");
   menu();
   printf("\033[90mplease enter a option:");
   printf("\033[0m");
   scanf("%d", &choice);
   menu_choice_cheker(choice);
}
int menu_choice_cheker(int choice)
{
   while (choice != 0 && choice != 1 && choice != 2 && choice != 3)
   {
      system("cls");
      printf("\033[31m");
      printf("\033[1m");
      printf(" invalid input!\n");
      printf("\033[0m");
      menu();
      printf("\033[0m");
      printf("\033[90mplease enter a option:");
      printf("\033[0m");
      scanf("%d", &choice);
   }
   if (choice == 0)
   {
      quit();
   }
   if (choice == 1)
   {
      system("cls");
      printf("\033[1m");
      printf("-----------------Calender------------------\n");
      printf("\033[0m\n");

      printf("\033[90m [0] \033[0m\033[1m back to menu!\n\n");
      printf("\033[90m [!] \033[0m\033[1m enter a year between 1206 and 1498\n\n");
      printf("\033[90m [!] \033[0m\033[1m enter a month between 1 and 12\n\n");
      printf("-------------------------------------------\n");
      printf("\033[0m");
      printf("\033[90mplease enter a year:\033[0m");
      scanf("%d", &year);

      if (year == 0)
      {
         back_to_menu();
      }
      else if (year != 0)
      {
         calender_year_checker(year);
         printf("\033[90mplease enter a month:\033[0m");
         scanf("%d", &month);
         calender_month_checker(month);
         printing_month(month);
         taghvim(esfand, tedad_kabiseh, month, year);
      }
   }
   if (choice == 2)
   {
      system("cls");
      printf("\033[1m");
      printf("-----------------------Age Calculation----------------------\n");
      printf("\033[0m");
      printf("\033[90m [0] \033[0m\033[1m back to menu!\n\n");
      printf("\033[90m [!] \033[0m\033[1m enter dates in format year:----,month:--,day:-- \n\n");
      printf("------------------------Todays Date------------------------\n\n");
      printf("\033[0m");
      printf("\033[90myear:\033[0m");
      scanf("%4d", &todayy);
      if (todayy == 0)
      {
         back_to_menu();
      }
      else
      {
         printf("\n\033[90mmonth:\033[0m");
         scanf("%2d", &todaym);
         printf("\n\033[90mday:\033[0m");
         scanf("%2d", &todayd);
         printf("\n------------------------Birth Day Date---------------------\n\n");
         printf("\033[90myear:\033[0m");
         scanf("%4d", &birthy);
         printf("\n\033[90mmonth:\033[0m");
         scanf("%2d", &birthm);
         printf("\n\033[90mday:\033[0m");
         scanf("%2d", &birthd);
         while (todayy < birthy || todaym > 12 || todaym < 1 || birthm > 12 || birthm < 1 || todayd < 1 || todayd > 31 || birthd < 1 || birthd > 31)
         {
            if (todayy < birthy)
            {
               system("cls");
               printf("\033[31m");
               printf("\033[1m");
               printf("invalid input for todays year or birth days year please try again!\n");
               printf("\033[0m");
               printf("---------------------------Age Calculation------------------------\n");
               printf("\033[90m [0] \033[0m\033[1m back to menu!\n\n");
               printf("\033[90m [!] \033[0m\033[1m enter years in format year:---- \n\n");
               printf("---------------------------Todays Date---------------------------\n\n");
               printf("\033[0m");
               printf("\033[90myear:\033[0m");
               scanf("%4d", &todayy);
               if (todayy == 0)
               {
                  back_to_menu();
               }
               else
               {
                  printf("\n--------------------------Birth Day Date------------------------\n\n");
                  printf("\033[90myear:\033[0m");
                  scanf("%4d", &birthy);
               }
            }
            else if (todaym > 12 || todaym < 1 || birthm > 12 || birthm < 1)
            {
               system("cls");
               printf("\033[31m");
               printf("\033[1m");
               printf("invalid input for todays month or birth days month please try again!\n");
               printf("\033[0m");
               printf("---------------------------Age Calculation--------------------------\n\n");
               printf("\033[90m [!] \033[0m\033[1m enter months in format month:--\n\n");
               printf("----------------------------Todays Date-----------------------------\n\n");
               printf("\033[0m");
               printf("\n\033[90mmonth:\033[0m");
               scanf("%2d", &todaym);
               printf("\n---------------------------Birth Day Date--------------------------\n\n");
               printf("\n\033[90mmonth:\033[0m");
               scanf("%2d", &birthm);
            }
            else if (todayd < 1 || todayd > 31 || birthd < 1 || birthd > 31)
            {
               system("cls");
               printf("\033[31m");
               printf("\033[1m");
               printf("invalid input for todays day or birth days day please try again!\n");
               printf("\033[0m");
               printf("---------------------------Age Calculation------------------------\n\n");
               printf("\033[90m [!] \033[0m\033[1m enter days in format day:--\n\n");
               printf("---------------------------Todays Date---------------------------\n\n");
               printf("\033[0m");
               printf("\n\033[90mday:\033[0m");
               scanf("%2d", &todayd);
               printf("\n------------------------Birth Day Date---------------------\n\n");
               printf("\n\033[90mday:\033[0m");
               scanf("%2d", &birthd);
            }
         }
         age_calculate(todayy, todaym, todayd, birthy, birthm, birthd);
      }
   }
   if (choice == 3)
   {
      system("cls");
      printf("\033[1m");
      printf("------------------------convertion----------------------\n");
      printf("\033[0m");
      printf("\033[90m [0] \033[0m\033[1m back to menu!\n\n");
      printf("\033[90m [1] \033[0m\033[1m convert Shamsi to Miladi \n\n");
      printf("\033[90m [2] \033[0m\033[1m convert Miladi to Shamsi \n\n");
      printf("-------------------------------------------------------\n\n");
      int option;
      printf("\033[90mplease enter a option:\033[0m");
      scanf("%d", &option);
      if (option == 0)
      {
         back_to_menu();
      }
      else if (option == 1)
      {
         system("cls");
         printf("\033[1m");
         printf("----------------convert Shamsi to Miladi---------------\n\n");
         printf("\033[0m");
         printf("\033[90m [0] \033[0m\033[1m back to menu!\n\n");
         printf("\033[90m [!] \033[0m\033[1m enter a month between 1 and 12\n\n");
         printf("\033[90m [!] \033[0m\033[1m enter a day between 1 and 31\n\n");
         printf("-------------------------------------------------------\n\n");
         printf("\033[90mplease enter a year:\033[0m");
         scanf("%d", &sh_year);
         printf("\033[90mplease enter a month:\033[0m");
         scanf("%d", &sh_month);
         printf("\033[90mplease enter a day:\033[0m");
         scanf("%d", &sh_day);
         shamsi_to_miladi_date_checker(sh_year, sh_month, sh_day);
      }
      else if (option == 2)
      {
         system("cls");
         printf("\033[1m");
         printf("----------------convert Miladi to Shamsi---------------\n\n");
         printf("\033[0m");
         printf("\033[90m [0] \033[0m\033[1m back to menu!\n\n");
         printf("\033[90m [!] \033[0m\033[1m enter a month between 1 and 12\n\n");
         printf("\033[90m [!] \033[0m\033[1m enter a day between 1 and 31\n\n");
         printf("-------------------------------------------------------\n\n");
         printf("\033[90mplease enter a year:\033[0m");
         scanf("%d", &m_year);
         printf("\033[90mplease enter a month:\033[0m");
         scanf("%d", &m_month);
         printf("\033[90mplease enter a day:\033[0m");
         scanf("%d", &m_day);
         miladi_to_shamsi_date_checker(m_year, m_month, m_day);
      }
   }

   return year, month, todayy, todaym, todayd, birthy, birthm, birthd;
}
int calender_year_checker(int year)
{
   while (year < 1206 && year != 0 || year > 1498)
   {
      system("cls");
      printf("\033[31m");
      printf("\033[1m");
      printf("not sopported year!\n");
      printf("\033[0m");
      printf("\n [0] \033[1m back to menu!\n");
      printf("__________________________________________________\n");
      printf("\033[0m");
      printf("\033[90mplease enter another year:\033[0m");
      scanf("%d", &year);
   }
   if (year == 0)
   {
      system("cls");
      printf("\033[32m");
      printf("\033[1m");
      printf("welcome back to home page :)\n");
      printf("\033[0m");
      menu();
      printf("\033[90mplease enter a option:\033[0m");
      scanf("%d", &choice);
      menu_choice_cheker(choice);
   }
   solar_leap_years(year);
   return year, choice;
}
int calender_month_checker(int month)
{
   while (month > 12 || month <= 0)
   {
      printf("\033[31m");
      printf("\033[1m");
      printf("invalid month\n");
      printf("\033[0m");
      printf("\033[90mplease enter another month:\033[0m");
      scanf("%d", &month);
   }
   return month;
}
int solar_leap_years(int year)
{
   tedad_kabiseh = 0;
   int i;
   for (i = 1206; i < year; i++)
   {
      int baghimandehm = i % 33;
      if (baghimandehm == 1 || baghimandehm == 5 || baghimandehm == 9 || baghimandehm == 13 || baghimandehm == 17 || baghimandehm == 22 || baghimandehm == 26 || baghimandehm == 30)
      {
         tedad_kabiseh++;
      }
   }
   int baghimandeh = year % 33;
   if (baghimandeh == 1 || baghimandeh == 5 || baghimandeh == 9 || baghimandeh == 13 || baghimandeh == 17 || baghimandeh == 22 || baghimandeh == 26 || baghimandeh == 30)
   {
      esfand = 30;
   }
   else
   {
      esfand = 29;
   }
   return esfand, tedad_kabiseh;
}
void printing_month(int month)
{
   system("cls");
   if (month == 1)
   {
      printf("\033[48;5;218m");
      printf("\033[1m");
      printf("                     FARVARDIN                     ");
      printf("\033[0m");
   }
   else if (month == 2)
   {
      printf("\033[48;5;218m");
      printf("\033[1m");

      printf("                   ORDIBEHESHT                     ");
      printf("\033[0m");
   }
   else if (month == 3)
   {
      printf("\033[48;5;218m");
      printf("\033[1m");
      printf("                     KHORDAD                       ");
      printf("\033[0m");
   }
   else if (month == 4)
   {
      printf("\033[48;5;156m");
      printf("\033[1m");
      printf("                       TIR                         ");
      printf("\033[0m");
   }
   else if (month == 5)
   {
      printf("\033[48;5;156m");
      printf("\033[1m");
      printf("                      MORDAD                       ");
      printf("\033[0m");
   }
   else if (month == 6)
   {
      printf("\033[48;5;156m");
      printf("\033[1m");
      printf("                     SHAHRIVAR                     ");
      printf("\033[0m");
   }
   else if (month == 7)
   {
      printf("\033[48;5;215m");
      printf("\033[1m");
      printf("                        MEHR                       ");
      printf("\033[0m");
   }
   else if (month == 8)
   {
      printf("\033[48;5;215m");
      printf("\033[1m");
      printf("                       ABAN                        ");
      printf("\033[0m");
   }
   else if (month == 9)
   {

      printf("\033[48;5;215m");
      printf("\033[1m");
      printf("                       AZAR                        ");
      printf("\033[0m");
   }
   else if (month == 10)
   {
      printf("\033[47m");
      printf("\033[1m");
      printf("                        DEY                        ");
      printf("\033[0m");
   }
   else if (month == 11)
   {
      printf("\033[47m");
      printf("\033[1m");
      printf("                       BAHMAN                      ");
      printf("\033[0m");
   }
   else if (month == 12)
   {
      printf("\033[47m");
      printf("\033[1m");
      printf("                      ESFAND                       ");
      printf("\033[0m");
   }
}
void taghvim(int esfand, int tedad_kabiseh, int month, int year)
{
   int tedad_sal = year - 1206;
   int gheireh_kabiseh = tedad_sal - tedad_kabiseh;
   int days, n, i, j, baghimandeh_days;
   if (month == 1 || month == 2 || month == 3 || month == 4 || month == 5 || month == 6 || month == 7)
   {
      days = (gheireh_kabiseh * 365) + (tedad_kabiseh * 366) + ((month - 1) * 31);
   }
   else if (month == 8 || month == 9 || month == 10 || month == 11 || month == 12)
   {
      days = (gheireh_kabiseh * 365) + (tedad_kabiseh * 366) + ((month - 1) * 30) + 6;
   }
   baghimandeh_days = days % 7;
   int jadval_taghvim[6][7];
   printf("\033[1m");
   printf("\n\nsh\tye\tdo\tse\tch\tpa\tjo\n");
   printf("\033[0m\n");
   if (baghimandeh_days == 0)
   {
      for (j = 0; j < 5; j++)
      {
         jadval_taghvim[0][j] = 0;
      }
      jadval_taghvim[0][5] = 1;
      jadval_taghvim[0][6] = 2;
      if (month <= 6)
      {
         jadval_taghvim[5][0] = 31;
      }
      else if (month > 6 && month < 12)
      {
         jadval_taghvim[5][0] = 0;
      }
      int n = jadval_taghvim[0][6] + 1;
      for (int i = 1; i < 5; i++)
      {
         for (int j = 0; j < 7; j++)
         {
            jadval_taghvim[i][j] = n;
            n++;
         }
         for (j = 1; j < 7; j++)
         {
            jadval_taghvim[5][j] = 0;
         }
      }
      if (month == 12)
      {
         jadval_taghvim[5][0] = 0;
         if (esfand == 29)
         {
            jadval_taghvim[4][6] = 0;
         }
         else if (esfand == 30)
         {
            jadval_taghvim[4][6] = 30;
         }
      }
      for (int i = 0; i < 6; i++)
      {
         for (int j = 0; j < 7; j++)
         {
            if (jadval_taghvim[i][j] == 0)
            {
               printf("\t");
            }
            else
            {
               printf("%2d\t", jadval_taghvim[i][j]);
            }
         }
         printf("\n");
      }
   }
   else if (baghimandeh_days == 1)
   {
      for (j = 0; j < 6; j++)
      {
         jadval_taghvim[0][j] = 0;
      }
      jadval_taghvim[0][6] = 1;
      if (month <= 6)
      {
         jadval_taghvim[5][0] = 30;
         jadval_taghvim[5][1] = 31;
      }
      else if (month > 6 && month < 12)
      {
         jadval_taghvim[5][0] = 30;
         jadval_taghvim[5][1] = 0;
      }
      int n = jadval_taghvim[0][6] + 1;
      for (int i = 1; i < 5; i++)
      {
         for (int j = 0; j < 7; j++)
         {
            jadval_taghvim[i][j] = n;
            n++;
         }
         for (j = 2; j < 7; j++)
         {
            jadval_taghvim[5][j] = 0;
         }
      }
      if (month == 12)
      {
         jadval_taghvim[5][1] = 0;
         if (esfand == 29)
         {
            jadval_taghvim[5][0] = 0;
         }
         else if (esfand == 30)
         {
            jadval_taghvim[5][0] = 30;
         }
      }
      for (int i = 0; i < 6; i++)
      {
         for (int j = 0; j < 7; j++)
         {
            if (jadval_taghvim[i][j] == 0)
            {
               printf("\t");
            }
            else
            {
               printf("%2d\t", jadval_taghvim[i][j]);
            }
         }
         printf("\n");
      }
   }
   else if (baghimandeh_days == 2)
   {
      for (j = 0; j < 7; j++)
      {
         jadval_taghvim[4][j] = 0;
         jadval_taghvim[5][j] = 0;
      }
      jadval_taghvim[4][0] = 29;
      if (month <= 6)
      {
         jadval_taghvim[4][1] = 30;
         jadval_taghvim[4][2] = 31;
      }
      else if (month > 6 && month < 12)
      {
         jadval_taghvim[4][1] = 30;
         jadval_taghvim[4][2] = 0;
      }
      int n = 1;
      for (int i = 0; i < 4; i++)
      {
         for (int j = 0; j < 7; j++)
         {
            jadval_taghvim[i][j] = n;
            n++;
         }
      }
      if (month == 12)
      {
         if (esfand == 29)
         {
            jadval_taghvim[4][1] = 0;
            jadval_taghvim[4][2] = 0;
         }
         else if (esfand == 30)
         {
            jadval_taghvim[4][1] = 30;
            jadval_taghvim[4][2] = 0;
         }
      }
      for (int i = 0; i < 6; i++)
      {
         for (int j = 0; j < 7; j++)
         {
            if (jadval_taghvim[i][j] == 0)
            {
               printf("\t");
            }
            else
            {
               printf("%2d\t", jadval_taghvim[i][j]);
            }
         }
         printf("\n");
      }
   }
   else if (baghimandeh_days == 3)
   {
      for (j = 0; j < 7; j++)
      {
         jadval_taghvim[4][j] = 0;
         jadval_taghvim[5][j] = 0;
      }
      int m = 0;
      for (j = 0; j < 7; j++)
      {
         jadval_taghvim[0][j] = m;
         m++;
      }
      int n = jadval_taghvim[0][6] + 1;
      for (int i = 1; i <= 4; i++)
      {
         for (int j = 0; j < 7; j++)
         {
            jadval_taghvim[i][j] = n;
            n++;
         }
      }
      jadval_taghvim[4][4] = 0;
      jadval_taghvim[4][5] = 0;
      jadval_taghvim[4][6] = 0;
      if (month > 6 && month < 12)
      {
         jadval_taghvim[4][3] = 0;
      }
      if (month == 12)
      {
         jadval_taghvim[4][3] = 0;
         if (esfand == 29)
         {
            jadval_taghvim[4][2] = 0;
         }
      }
      for (int i = 0; i < 6; i++)
      {
         for (int j = 0; j < 7; j++)
         {
            if (jadval_taghvim[i][j] == 0)
            {
               printf("\t");
            }
            else
            {
               printf("%2d\t", jadval_taghvim[i][j]);
            }
         }
         printf("\n");
      }
   }
   else if (baghimandeh_days == 4)
   {
      for (j = 0; j < 7; j++)
      {
         jadval_taghvim[5][j] = 0;
      }
      jadval_taghvim[0][0] = 0;
      int m = 0;
      for (j = 1; j < 7; j++)
      {
         jadval_taghvim[0][j] = m;
         m++;
      }
      int n = jadval_taghvim[0][6] + 1;
      for (int i = 1; i <= 4; i++)
      {
         for (int j = 0; j < 7; j++)
         {
            jadval_taghvim[i][j] = n;
            n++;
         }
      }
      jadval_taghvim[4][5] = 0;
      jadval_taghvim[4][6] = 0;
      if (month > 6 && month < 12)
      {
         jadval_taghvim[4][4] = 0;
      }
      else if (month == 12)
      {
         jadval_taghvim[4][4] = 0;
         if (esfand == 29)
         {
            jadval_taghvim[4][3] = 0;
         }
      }
      for (int i = 0; i < 6; i++)
      {
         for (int j = 0; j < 7; j++)
         {
            if (jadval_taghvim[i][j] == 0)
            {
               printf("\t");
            }
            else
            {
               printf("%2d\t", jadval_taghvim[i][j]);
            }
         }
         printf("\n");
      }
   }
   else if (baghimandeh_days == 5)
   {
      for (j = 0; j < 7; j++)
      {
         jadval_taghvim[5][j] = 0;
      }
      jadval_taghvim[0][0] = 0;
      jadval_taghvim[0][1] = 0;
      int m = 0;
      for (j = 2; j < 7; j++)
      {
         jadval_taghvim[0][j] = m;
         m++;
      }
      int n = jadval_taghvim[0][6] + 1;
      for (int i = 1; i <= 4; i++)
      {
         for (int j = 0; j < 7; j++)
         {
            jadval_taghvim[i][j] = n;
            n++;
         }
      }
      jadval_taghvim[4][6] = 0;
      if (month > 6 && month < 12)
      {
         jadval_taghvim[4][5] = 0;
      }
      else if (month == 12)
      {
         jadval_taghvim[4][5] = 0;
         if (esfand == 29)
         {
            jadval_taghvim[4][4] = 0;
         }
      }
      for (int i = 0; i < 6; i++)
      {
         for (int j = 0; j < 7; j++)
         {
            if (jadval_taghvim[i][j] == 0)
            {
               printf("\t");
            }
            else
            {
               printf("%2d\t", jadval_taghvim[i][j]);
            }
         }
         printf("\n");
      }
   }
   else if (baghimandeh_days == 6)
   {
      for (j = 0; j < 7; j++)
      {
         jadval_taghvim[5][j] = 0;
      }
      jadval_taghvim[0][0] = 0;
      jadval_taghvim[0][1] = 0;
      jadval_taghvim[0][2] = 0;
      int m = 0;
      for (j = 3; j < 7; j++)
      {
         jadval_taghvim[0][j] = m;
         m++;
      }
      int n = jadval_taghvim[0][6] + 1;
      for (int i = 1; i <= 4; i++)
      {
         for (int j = 0; j < 7; j++)
         {
            jadval_taghvim[i][j] = n;
            n++;
         }
      }
      if (month > 6 && month < 12)
      {
         jadval_taghvim[4][6] = 0;
      }
      else if (month == 12)
      {
         jadval_taghvim[4][6] = 0;
         if (esfand == 29)
         {
            jadval_taghvim[4][5] = 0;
         }
      }
      for (int i = 0; i < 6; i++)
      {
         for (int j = 0; j < 7; j++)
         {
            if (jadval_taghvim[i][j] == 0)
            {
               printf("\t");
            }
            else
            {
               printf("%2d\t", jadval_taghvim[i][j]);
            }
         }
         printf("\n");
      }
   }
   if (month <= 3)
   {
      printf("\033[48;5;218m");
      printf("\033[1m");
      printf("\n                      %d                         ", year);
      printf("\033[0m");
   }
   else if (month > 3 && month <= 6)
   {
      printf("\033[48;5;156m");
      printf("\033[1m");
      printf("\n                      %d                         ", year);
      printf("\033[0m");
   }
   else if (month > 6 && month <= 9)
   {
      printf("\033[48;5;215m");
      printf("\033[1m");
      printf("\n                      %d                         ", year);
      printf("\033[0m");
   }
   else if (month > 9 && month <= 12)
   {
      printf("\033[47m");
      printf("\033[1m");
      printf("\n                       %d                        ", year);
      printf("\033[0m");
   }
   printf("\n\n");
   printf(" [0] \033[1m back to menu!\n");
   printf("__________________________________________________\n\n");
   printf("\033[90mplease enter a year:\033[0m");
   scanf("%d", &year);
   if (year == 0)
   {
      back_to_menu();
   }
   else if (year != 0)
   {
      calender_year_checker(year);
      printf("\033[90mplease enter a month:\033[0m");
      scanf("%d", &month);
      calender_month_checker(month);
      printing_month(month);
      taghvim(esfand, tedad_kabiseh, month, year);
   }
}
void age_calculate(int todayy, int todaym, int todayd, int birthy, int birthm, int birthd)
{
   int flag, flag2;
   solar_leap_years(birthy);
   int kabiseh_ta_tavalod = tedad_kabiseh;
   solar_leap_years(todayy);
   int kabiseh_ta_emroz = tedad_kabiseh;
   if (todayd >= birthd)
   {
      past_d = todayd - birthd;
   }
   else
   {
      if (todaym <= 6)
      {
         past_d = 31 + todayd - birthd;
      }
      else if (todaym > 6 && todaym < 12)
      {
         past_d = 30 + todayd - birthd;
      }
      else if (todaym == 12)
      {
         if (esfand == 29)
         {
            past_d = 29 + todayd - birthd;
         }
         else if (esfand == 30)
         {
            past_d = 30 + todayd - birthd;
         }
      }
      flag = 1;
      todaym = todaym - 1;
   }
   if (todaym >= birthm)
   {
      past_m = todaym - birthm;
   }
   else
   {
      flag2 = 1;
      past_m = 12 + todaym - birthm;
      todayy = todayy - 1;
   }
   past_y = todayy - birthy;
   int kabiseh = kabiseh_ta_emroz - kabiseh_ta_tavalod, age_in_days;
   if (flag == 1)
   {
      todaym++;
   }
   if (flag2 == 1)
   {
      todayy++;
   }
   age_in_days = ((todayy - birthy) * 365) + kabiseh;
   if (todaym <= 7)
   {
      age_in_days += (todaym - 1) * 31 + (todayd - 1);
   }
   else if (todaym > 7 && todaym <= 12)
   {
      age_in_days += (6 * 31) + (todaym - 1 - 6) * 30 + (todayd - 1);
   }
   if (birthm <= 7)
   {
      age_in_days -= (birthm - 1) * 31 + (birthd - 1);
   }
   else if (birthm > 7 && birthm <= 12)
   {
      age_in_days -= (6 * 31) + (birthm - 1 - 6) * 30 + (birthd - 1);
   }
   // barayeh mohasebeh roz tavalod variable daystbi ro tarif kardam keh ba mabda zamani 1 farvardin 1206 ke
   // midonim ke panjshanbeh hast.
   int daystbi = 0;
   char day;
   if (birthm <= 7)
   {
      daystbi += ((birthm - 1) * 31) + (birthd - 1);
   }
   else if (birthm > 7 && birthm <= 12)
   {
      daystbi += ((birthm - 1 - 6) * 30) + (6 * 31) + (birthd - 1);
   }
   daystbi += ((birthy - 1206) * 365) + kabiseh_ta_tavalod;
   system("cls");
   printf("\033[1m");
   printf("------------------------------Age---------------------------\n\n");
   printf("\033[90mYour age: \033[0m\033[1m%d \033[0myears, \033[1m%d \033[0mmonths, \033[1m%d \033[0mdays \n\n", past_y, past_m, past_d);
   printf("\033[90mNumber of days passed since your birth: \033[0m\033[1m%d\n\n", age_in_days);
   printf("\033[0m\033[90mYou were born on:");
   if (daystbi % 7 == 0)
   {
      printf(" \033[0m\033[1mPanjshanbeh\n\n");
   }
   else if (daystbi % 7 == 1)
   {
      printf("  \033[0m\033[1mJomeh\n\n");
   }
   else if (daystbi % 7 == 2)
   {
      printf("  \033[0m\033[1mShanbeh\n\n");
   }
   else if (daystbi % 7 == 3)
   {
      printf("  \033[0m\033[1mYekshanbeh\n\n");
   }
   else if (daystbi % 7 == 4)
   {
      printf("  \033[0m\033[1mDoshanbeh\n\n");
   }
   else if (daystbi % 7 == 5)
   {
      printf("  \033[0m\033[1mSeshanbeh\n\n");
   }
   else if (daystbi % 7 == 6)
   {
      printf("  \033[0m\033[1mCaharshanbeh\n\n");
   }
   int flagg = 1;

   printf("\033[0m\033[90mShamsi date:\033[0m\033[1m %d/%d/%d\n\n", birthy, birthm, birthd);
   shamsi_to_miladi(birthy, birthm, birthd, flagg);
   printf("\033[0m");
   printf("-------------------------------------------------------------\n");
   printf("\033[0m");
   printf("\033[90m [0] \033[0m\033[1m back to menu!\n\n");
   printf("\033[90m [!] \033[0m\033[1m enter dates in format year:----,month:--,day:-- \n\n");
   printf("-------------------------Todays Date------------------------\n\n");
   printf("\033[0m");
   printf("\033[90myear:\033[0m");
   scanf("%4d", &todayy);
   if (todayy == 0)
   {
      back_to_menu();
   }
   else
   {
      printf("\n\033[90mmonth:\033[0m");
      scanf("%2d", &todaym);
      printf("\n\033[90mday:\033[0m");
      scanf("%2d", &todayd);
      printf("\n------------------------Birth Day Date---------------------\n\n");
      printf("\033[90myear:\033[0m");
      scanf("%4d", &birthy);
      printf("\n\033[90mmonth:\033[0m");
      scanf("%2d", &birthm);
      printf("\n\033[90mday:\033[0m");
      scanf("%2d", &birthd);
      age_dates_checker(todayy, todaym, todayd, birthy, birthm, birthd);
      age_calculate(todayy, todaym, todayd, birthy, birthm, birthd);
   }
}
int age_dates_checker(int todayy, int todaym, int todayd, int birthy, int birthm, int birthd)
{
   while (todayy < birthy || todaym > 12 || todaym < 1 || birthm > 12 || birthm < 1 || todayd < 1 || todayd > 31 || birthd < 1 || birthd > 31)
   {
      if (todayy < birthy)
      {
         system("cls");
         printf("\033[31m");
         printf("\033[1m");
         printf("invalid input for todays year or birth days year please try again!\n");
         printf("---------------------------Age Calculation------------------------\n");
         printf("\033[90m [0] \033[0m\033[1m back to menu!\n\n");
         printf("\033[90m [!] \033[0m\033[1m enter years in format year:---- \n\n");
         printf("---------------------------Todays Date---------------------------\n\n");
         printf("\033[0m");
         printf("\033[90myear:\033[0m");
         scanf("%4d", &todayy);
         if (todayy == 0)
         {
            back_to_menu();
         }
         else
         {
            printf("\n--------------------------Birth Day Date------------------------\n\n");
            printf("\033[90myear:\033[0m");
            scanf("%4d", &birthy);
         }
      }
      else if (todaym > 12 || todaym < 1 || birthm > 12 || birthm < 1)
      {
         system("cls");
         printf("\033[31m");
         printf("\033[1m");
         printf("invalid input for todays month or birth days month please try again!\n");
         printf("\033[0m");
         printf("---------------------------Age Calculation--------------------------\n\n");
         printf("\033[90m [!] \033[0m\033[1m enter months in format month:--\n\n");
         printf("----------------------------Todays Date-----------------------------\n\n");
         printf("\033[0m");
         printf("\n\033[90mmonth:\033[0m");
         scanf("%2d", &todaym);
         printf("\n---------------------------Birth Day Date--------------------------\n\n");
         printf("\n\033[90mmonth:\033[0m");
         scanf("%2d", &birthm);
      }
      else if (todayd < 1 || todayd > 31 || birthd < 1 || birthd > 31)
      {
         system("cls");
         printf("\033[31m");
         printf("\033[1m");
         printf("invalid input for todays day or birth days day please try again!\n");
         printf("\033[0m");
         printf("---------------------------Age Calculation------------------------\n\n");
         printf("\033[90m [!] \033[0m\033[1m enter days in format day:--\n\n");
         printf("---------------------------Todays Date---------------------------\n\n");
         printf("\033[0m");
         printf("\n\033[90mday:\033[0m");
         scanf("%2d", &todayd);
         printf("\n------------------------Birth Day Date---------------------\n\n");
         printf("\n\033[90mday:\033[0m");
         scanf("%2d", &birthd);
      }
   }
   return todayy, todaym, todayd, birthy, birthm, birthd;
}
int shamsi_to_miladi(int sh_year, int sh_month, int sh_day, int flagg)
{
   int shamsi_months[] = {31, 62, 93, 124, 155, 186, 216, 246, 276, 306, 336, 365};
   int miladi_months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   int days = sh_day, miladi_year, miladi_month = 0, miladi_day;
   if (sh_month > 1)
   {
      days += shamsi_months[sh_month - 2];
   }
   miladi_year = sh_year + 621;
   days += 79;
   if ((miladi_year % 400 == 0) || ((miladi_year % 100 != 0) && (miladi_year % 4 == 0)))
   {
      if (days > 366)
      {
         days -= 366;
         miladi_year++;
      }
      miladi_months[1] = 29;
   }
   else if (days > 365)
   {
      days -= 365;
      miladi_year++;
   }
   while (days > miladi_months[miladi_month])
   {
      days -= miladi_months[miladi_month];
      miladi_month++;
   }
   miladi_month++;
   miladi_day = days;
   if (flagg == 0)
   {
      represent_shamsi_to_miladi(miladi_year, miladi_month, miladi_day, sh_year, sh_month, sh_day);
   }
   else if (flagg == 1)
   {
      represent_miladi_tarikh_tavalod(miladi_year, miladi_month, miladi_day);
   }
   return miladi_year, miladi_month, miladi_day;
}
int shamsi_to_miladi_date_checker(int sh_year, int sh_month, int sh_day)
{
   while (sh_month > 12 || sh_month < 1)
   {
      printf("\033[31m");
      printf("\033[1m");
      printf("invalid month please try again\n");
      printf("\033[0m");
      printf("\033[90mplease enter another month:\033[0m");
      scanf("%d", &sh_month);
   }
   while (sh_month < 7 && (sh_day > 31 || sh_day < 1))
   {
      printf("\033[31m");
      printf("\033[1m");
      printf("invalid day please try again\n");
      printf("\033[0m");
      printf("\033[90mplease enter another day:\033[0m");
      scanf("%d", &sh_day);
   }
   while ((sh_month >= 7 && sh_month < 12) && (sh_day > 30 || sh_day < 1))
   {
      printf("\033[31m");
      printf("\033[1m");
      printf("invalid day please try again\n");
      printf("\033[0m");
      printf("\033[90mplease enter another day:\033[0m");
      scanf("%d", &sh_day);
   }
   int flagg = 0;
   shamsi_to_miladi(sh_year, sh_month, sh_day, flagg);
   return sh_year, sh_month, sh_day;
}
void represent_shamsi_to_miladi(int miladi_year, int miladi_month, int miladi_day, int sh_year, int sh_month, int sh_day)
{
   system("cls");
   printf("\033[1m");
   printf("---------------converted Shamsi to Miladi--------------\n\n");
   printf("\033[0m\033[90mShamsi date:\033[1m %d/%d/%d\n\n", sh_year, sh_month, sh_day);
   printf("\033[0m\033[90mMiladi date:\033[0m\033[1m %d/%d/%d\n\n", miladi_year, miladi_month, miladi_day);
   printf("-------------------------------------------------------\n\n");
   printf("\033[0m");
   printf("\033[90m [0] \033[0m\033[1m back to menu!\n\n");
   printf("\033[90m [1] \033[0m\033[1m convert Shamsi to Miladi \n\n");
   printf("-------------------------------------------------------\n\n");
   int option;
   printf("\033[90mplease enter a option:\033[0m");
   scanf("%d", &option);
   if (option == 0)
   {
      menu_choice_cheker(3);
   }
   else
   {
      system("cls");
      printf("\033[1m");
      printf("----------------convert Shamsi to Miladi---------------\n\n");
      printf("\033[0m");
      printf("\033[90m [0] \033[0m\033[1m back to menu!\n\n");
      printf("\033[90m [!] \033[0m\033[1m enter a month between 1 and 12\n\n");
      printf("\033[90m [!] \033[0m\033[1m enter a day between 1 and 31\n\n");
      printf("-------------------------------------------------------\n\n");
      printf("\033[90mplease enter a year:\033[0m");
      scanf("%d", &sh_year);
      if (sh_year == 0)
      {
         menu_choice_cheker(3);
      }
      else
      {
         printf("\033[90mplease enter a month:\033[0m");
         scanf("%d", &sh_month);
         printf("\033[90mplease enter a day:\033[0m");
         scanf("%d", &sh_day);
         shamsi_to_miladi_date_checker(sh_year, sh_month, sh_day);
      }
   }
}
int miladi_to_shamsi_date_checker(int m_year, int m_month, int m_day)
{
   while (m_month > 12 || m_month < 1)
   {
      printf("\033[31m");
      printf("\033[1m");
      printf("invalid month please try again\n");
      printf("\033[0m");
      printf("\033[90mplease enter another month:\033[0m");
      scanf("%d", &m_month);
   }
   while ((m_month == 1 || m_month == 3 || m_month == 5 || m_month == 7 || m_month == 8 || m_month == 10 || m_month == 12) && (m_day > 31 || m_day < 1))
   {
      printf("\033[31m");
      printf("\033[1m");
      printf("invalid day please try again\n");
      printf("\033[0m");
      printf("\033[90mplease enter another day:\033[0m");
      scanf("%d", &sh_day);
   }
   while ((m_month == 4 || m_month == 6 || m_month == 9 || m_month == 11 || m_month == 2) && (m_day > 30 || m_day < 1))
   {
      printf("\033[31m");
      printf("\033[1m");
      printf("invalid day please try again\n");
      printf("\033[0m");
      printf("\033[90mplease enter another day:\033[0m");
      scanf("%d", &sh_day);
   }
   miladi_to_shamsi(m_year, m_month, m_day);
   return m_year, m_month, m_day;
}
int miladi_to_shamsi(int m_year, int m_month, int m_day)
{
   int miladi_months[] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
   int days = m_day;
   if (m_month > 1)
   {
      days += miladi_months[m_month - 2];
   }
   if (((m_year % 400 == 0) || ((m_year % 100 != 0) && (m_year % 4 == 0))) && m_month > 2)
   {
      days++;
   }
   if (days <= 79)
   {
      if ((year - 1) % 4 == 0)
      {
         days += 11;
      }
      else
      {
         days += 10;
      }
      shamsi_year = m_year - 622;
      if ((days % 30) == 0)
      {
         shamsi_month = (days / 30) + 9;
         shamsi_day = 30;
      }
      else
      {
         shamsi_month = (days / 30) + 10;
         shamsi_day = days % 30;
      }
   }
   else
   {
      shamsi_year = m_year - 621;
      days -= 79;
      if (days <= 186)
      {
         if ((days % 31) == 0)
         {
            shamsi_month = days / 31;
            shamsi_day = 31;
         }
         else
         {
            shamsi_month = (days / 31) + 1;
            shamsi_day = days % 31;
         }
      }
      else
      {
         days -= 186;
         if ((days % 30) == 0)
         {
            shamsi_month = (days / 30) + 7;
            shamsi_day = 30;
         }
         else
         {
            shamsi_month = (days / 30) + 8;
            shamsi_day = days % 30;
         }
      }
   }
   represent_miladi_to_shamsi(shamsi_year, shamsi_month, shamsi_day, m_year, m_month, m_day);
   return shamsi_year, shamsi_month, shamsi_day;
}
void represent_miladi_to_shamsi(int shamsi_year, int shamsi_month, int shamsi_day, int m_year, int m_month, int m_day)
{
   system("cls");
   printf("\033[1m");
   printf("---------------converted Miladi to Shamsi--------------\n\n");
   printf("\033[0m\033[90m miladi date:\033[1m %d/%d/%d\n\n", m_year, m_month, m_day);
   printf("\033[0m\033[90m shamsi date:\033[0m\033[1m %d/%d/%d\n\n", shamsi_year, shamsi_month, shamsi_day);
   printf("-------------------------------------------------------\n\n");
   printf("\033[0m");
   printf("\033[90m [0] \033[0m\033[1m back to menu!\n\n");
   printf("\033[90m [1] \033[0m\033[1m convert Miladi to Shamsi \n\n");
   printf("-------------------------------------------------------\n\n");
   int option;
   printf("\033[90mplease enter a option:\033[0m");
   scanf("%d", &option);
   if (option == 0)
   {
      menu_choice_cheker(3);
   }
   else
   {
      system("cls");
      printf("\033[1m");
      printf("----------------convert Miladi to Shamsi---------------\n\n");
      printf("\033[0m");
      printf("\033[90m [0] \033[0m\033[1m back to menu!\n\n");
      printf("\033[90m [!] \033[0m\033[1m enter a month between 1 and 12\n\n");
      printf("\033[90m [!] \033[0m\033[1m enter a day between 1 and 31\n\n");
      printf("-------------------------------------------------------\n\n");
      printf("\033[90mplease enter a year:\033[0m");
      scanf("%d", &m_year);
      if (m_year == 0)
      {
         menu_choice_cheker(3);
      }
      else
      {
         printf("\033[90mplease enter a month:\033[0m");
         scanf("%d", &m_month);
         printf("\033[90mplease enter a day:\033[0m");
         scanf("%d", &m_day);
         miladi_to_shamsi_date_checker(m_year, m_month, m_day);
      }
   }
}
void represent_miladi_tarikh_tavalod(int miladi_year, int miladi_month, int miladi_day)
{
   printf("\033[0m\033[90mMiladi date:\033[0m\033[1m %d/%d/%d\n\n", miladi_year, miladi_month, miladi_day);
}