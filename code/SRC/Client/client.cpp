#include"header.h"
#include"functions.h"
#include"logger.h"
#include"admin.cpp"
#include"user.cpp"
#include"main.cpp"
#define BUFFER_SIZE 2048
#define PORT 1721
void travel:: login()
{
        int count = 0;
	int client_fd;
        string username,password,user,pass;
        cout<<"please enter the following details to login"<<endl;
        LOG_INFO("USERNAME :");
        cin>>username;
        LOG_INFO("PASSWORD :");
        cin>>password;

        ifstream input("admin_database.txt");
	
        while(input>>user>>pass)
        {
                if(username==user && password==pass)

                {
                        count=1;
                        cout<<("--------------");
                }
        }
        input.close();
        if(count==1)
		
        {
	
                send(client_fd,&count,sizeof(int),0);
                cout<<"\nHello"<<username<<"\n<LOGIN SUCCESSFUL>\nThanks for logging in..\n";
		
        }
        else
       {

                LOG_ERROR("\nLOGIN ERROR\nPlease check your username and password\n");
		login();

        }
}
  
 int fd;
 void sig_handler(int signo) {
     if (signo == SIGINT) {             //signal handler
         std::cout << "\t Exiting..." << '\n';
         close (fd);
         exit (1);
     }
 }

 int main(int argc, char const *argv[]) {

     sockaddr_in myaddr,remaddr;
     int slen = sizeof (remaddr), recvlen;
     char buffer[BUFFER_SIZE]; 
     int rcvlen;
     char *server = "127.0.0.1";         //server address
     if ((fd = socket (AF_INET, SOCK_DGRAM, 0)) == -1 ) {
         std::cout << "\n\t Socket creation failed...\n\t Exiting..." << '\n';
         return 0;
     }
     signal(SIGINT, sig_handler);       //handle CTRL+C
     signal(SIGTSTP, sig_handler);      //handle CTRL+Z
     std::cout << "\n\t Socket created..." << '\n';
     memset ((char*)&myaddr, 0, sizeof (myaddr));
     myaddr.sin_family = AF_INET; 
     myaddr.sin_addr.s_addr = htonl (INADDR_ANY);
     if (bind(fd, (sockaddr*) &myaddr, sizeof (myaddr)) < 0) {
         std::cout << "\n\t Bind failed...\n\t Exiting..." << '\n';
         return 0;
     }
     std::cout << "\n\t Bind succesful..." << '\n';
     memset ((char*) &remaddr, 0, sizeof (remaddr));
     remaddr.sin_family = AF_INET;
     remaddr.sin_port = htons (PORT);
     if (inet_aton (server, &remaddr.sin_addr) == 0) {
         std::cout << "\n\t inet_aton() failed...\n\t Exiting..." << '\n';
         return 0;
     }
     int count = 0; 
     while (1) {
         std::cout << "\n\t Enter your Name : ";
         std::cin.getline (buffer, BUFFER_SIZE);
         std::cout << "\n\t Sending packet " << count++ << " to " << server << " on port " << ntohs(remaddr.sin_port) << '\n';
	  sendto (fd, buffer, strlen (buffer), 0, (sockaddr*) &remaddr, slen);

         memset (buffer, 0, sizeof (buffer));
	 LOG_INIT();
    LOG_INFO("             \t\t WELCOME TO TRAVEL BOOKING APP\n\n\n");
    LOG_INFO("             \t\t  TRAVEL BOOKING APP MENU\n\n\n");
    LOG_INFO("             \t\t    PRESS ENTER TO CONTINUE....\n\n");



      LOG_DEINIT();

    travel t;
    t.menu();
   } 
    return 0;
 }
