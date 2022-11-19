#include "logger.h"
#include<string.h>
#include <assert.h>
#include <stdio.h>
int main()
{
    int loginAttempt = 0;
  // string userName;
//    string userPassword;
  const char* userName;
  const char* userPassword;
    int choice;
    LOG_PRINT("Travel Booking app");
    LOG_PRINT("\n*ADMIN MENU*");
    LOG_PRINT("\nAdmin_Login");
    while (loginAttempt < 5)
    {
 // LOG_PRINT( "\nPlease enter your user name:%s",userName );
        LOG_PRINT( "\nPlease enter your user name:" );
        scanf("%s",&userName);


       // LOG_PRINT( "\nPlease enter your user password:%s",userPassword );
        LOG_PRINT( "\nPlease enter your user password:" );
        scanf("%s",&userPassword);

        if (userName == "renuka" && userPassword == "Group6")
{
            LOG_PRINT( "Welcome renuka!\n");
            break;

}
        else if (userName == "navya" && userPassword == "Group6")
        {
            LOG_PRINT("Welcome navya!\n");
            break;
        }
         else
        {
            LOG_PRINT( "Invalid login attempt. Please try again.\n");
            loginAttempt++;
        }
    }
if (loginAttempt == 5)
    {

            LOG_PRINT( "Too many login attempts! The program will now terminate.");

    }
    LOG_PRINT( "Thank you for logging in.\n");

    return 0;
}