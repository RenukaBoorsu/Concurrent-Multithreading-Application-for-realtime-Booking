#include"server_header.h"
#define PORT 1721
#define SIZE 2048
#define THREADS 100

pthread_t threads[THREADS];
int threadno=0, fd;
void sig_handler(int signo) {
    if (signo == SIGINT) {
         std::cout << "\t Exiting..." << '\n';
         close (fd);
         exit (1);
     }
 }
/* Structure to hold the necessary parameters to pass into the threaded display_string function */
     struct request {
     int requestno;
     char string[SIZE];
     socklen_t addlen;
     sockaddr_in clientaddr;
 };
 void* display (void*);
 int main(int argc, char const *argv[]) {
     sockaddr_in serveraddr; //server Address
     sockaddr_in clientaddr; //client Address
     socklen_t addrlen = sizeof(clientaddr);
     int recvlen, msgcnt = 0;
     char buffer [SIZE]; // Hold buffer sent in udp packet
     if ((fd = socket (AF_INET, SOCK_DGRAM, 0)) == -1) {
         std::cout << "\n\t Socket creation failed...\n\t Exiting..." << '\n';
         return 0;
     }

         std::cout << "\n\t Socket created..." << '\n';
     memset ((sockaddr*)&serveraddr, 0, sizeof (serveraddr));
     serveraddr.sin_family = AF_INET;   
     serveraddr.sin_addr.s_addr = htonl (INADDR_ANY);  
     serveraddr.sin_port = htons (PORT); 
     if (bind (fd, (sockaddr*)&serveraddr, sizeof (serveraddr)) == -1) {
         std::cout << "\n\t Binding failed...\n\t Exiting..." << '\n';
         return 0;
     }

     std::cout << "\n\t Binding succesful" << '\n';
     signal(SIGINT, sig_handler);
     signal(SIGTSTP, sig_handler);
     while (1) {
         std::cout << "\n\t Waiting on port " << ntohs(serveraddr.sin_port) << '\n';
         recvlen = recvfrom (fd, buffer,SIZE, 0, (sockaddr*) &clientaddr, &addrlen);
         msgcnt++;
         request *obj = new request; //allocates new memory 
         bzero (obj, sizeof (request));  //clears previous memory
         obj->requestno = msgcnt;
         obj->addlen = addrlen;
         obj->clientaddr = clientaddr;
         strcpy (obj->string, buffer);

         //creating threads
         pthread_create (&threads [threadno++], NULL, display, (void*)obj);
         if (threadno == THREADS)
             threadno = 0;

         memset (buffer, 0, sizeof (buffer));
     }

 }
 void* display (void* obj) {

     request rq = *((request*)obj); //type casting
     std::cout << "\n name of client:\t " << rq.string<<std::endl;

    std::cout << "(user: " << rq.requestno << ")" << '\n';
     return NULL;
 }
