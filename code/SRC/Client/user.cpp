#define SIZE 300
// USER PANEL
//User registration
void travel :: user_registration()
{

        string username,password,user,pass;
        LOG_INFO("Enter the username :");
        cin>>username;
        LOG_INFO("\nEnter the password :");
        cin>>password;

        ofstream registration("database.txt",ios::app);
        registration<<username<<' '<<password<<endl;
        LOG_INFO("\nRegistration Sucessful\n");
        user_login();

}

//User login
void travel :: user_login()
{
        int count;
        string username,password,user,pass;
        LOG_INFO("\nplease enter the following details to login");
        LOG_INFO("\nUSERNAME :");
         cin>>username;
        LOG_INFO("\nPASSWORD :");
        cin>>password;

        ifstream input("database.txt");
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
                cout<<"\nHello"<<username<<"\n<LOGIN SUCCESSFUL>\nThanks for logging in..\n";
        }
        else
        {
                LOG_ERROR("\nLOGIN ERROR\nPlease check your username and password\n");
                user_forgot();
 }

}

// displays login credentials if user forgot
void travel :: user_forgot()
{
    int ch;
    LOG_INFO("\nForgotten ?\n");
    LOG_INFO("\n1.Search your id by username");

        LOG_INFO("\n2.Main menu");
        LOG_INFO("\nEnter your choice :");
        cin>>ch;
        switch(ch)
        {
                case 1:
                {
                        int count=0;
                        string search_user,user,password;
                        LOG_INFO("\nEnter your remembered username :");
                        cin>>search_user;

                        ifstream search("database.txt");
                        while(search>>user>>password)
                        {
 if(user==search_user)
                                {
                                        count=1;
                                }
                        }
                        search.close();
                        if(count==1)
                        {
                                LOG_INFO("\n account found\n");
                                cout<<"\nYour password is "<<password;
                                cin.get();
                                cin.get();
                                user_login();
                        }
                        else
                        {
                                LOG_INFO("\nSorry, Your userID is not found in our database\n");
                                LOG_INFO("\nPlease kindly contact your system administrator for more details \n");
                                cin.get();
                                cin.get();
                                user_registration();
                        }
                        break;
 }

                case 2:
                {
                        cin.get();
                        menu();
                }
                default:
                        LOG_INFO("\nSorry, You entered wrong choice. Kindly try again");
                        user_forgot();
        }
}
//To add data to the user package
void travel :: user_package(tour r){
    fstream fp;
    fp.open(user,ios::out|ios::app);
    if(!fp){
        LOG_INFO("\nFile Not Found");
                exit(0);
    }
    char data[SIZE];
    strcpy(data,r.user_name);
    strcat(data,"|");
    strcat(data,r.user_phone);
    strcat(data,"|");
    strcat(data,r.user_people);
strcat(data,"|");
    strcat(data,r.user_dcode);
    strcat(data,"|");
    strcat(data,r.user_date);
    strcat(data,"|");
    strcat(data,r.user_payments);
    strcat(data,"|");
    strcat(data,r.user_prices);
    strcat(data,"|");
    strcat(data,r.user_status);
    strcat(data,"|");
    for(int index=0;index<SIZE-strlen(data);index++)
        strcat(data,"|");
    fp<<data<<endl;
    fp.close();
}

// To read data from the user package
tour travel :: user_showpackage(char data[]){
        tour r;
        int index=0,indexj=0;
        while(data[indexj]!='|')
              r.user_name[index++]=data[indexj++];
        r.user_name[index]='\0';
        index=0;
        indexj++;
        while(data[indexj]!='|')
r.user_phone[index++]=data[indexj++];
        r.user_phone[index]='\0';
        index=0;
        indexj++;
        while(data[indexj]!='|')
              r.user_people[index++]=data[indexj++];
        r.user_people[index]='\0';
        index=0;
        indexj++;
        while(data[indexj]!='|')
              r.user_dcode[index++]=data[indexj++];
        r.user_dcode[index]='\0';
        index=0;
        indexj++;
        while(data[indexj]!='|')
              r.user_date[index++]=data[indexj++];
        r.user_date[index]='\0';
        index=0;
        indexj++;
        while(data[index]!='|')
              r.user_payments[index++]=data[indexj++];
        r.user_payments[index]='\0';
        index=0;
        indexj++;
        while(data[index]!='|')
              r.user_prices[index++]=data[indexj++];
        r.user_prices[index]='\0';
        index=0;
        indexj++;
        while(data[indexj]!='|')
        r.user_status[indexj++]=data[indexj++];
        r.user_status[index]='\0';
        return(r);
}
//To write data to the user package
void travel :: user_writedata(){
    tour r;
  char data[SIZE];
  LOG_INFO("\nENTER YOUR NAME: ");
  cin >> r.user_name;
  LOG_INFO("\nENTER YOUR CONTACT NO.: ");
  cin >> r.user_phone;
  LOG_INFO("\nENTER NO. OF TOURIST: ");
  cin >> r.user_people;
  int People = atoi (r.user_people);
  LOG_INFO("\nENTER THE DESTINATION CODE: D-");
  cin >> r.user_dcode;
  LOG_INFO("\nENTER DATE OF JOURNEY (DD/MM/YY): ");
  cin >> r.user_date;
  LOG_INFO("\nENTER PAYMENT METHOD CASH OR CARD: ");
  cin >> r.user_payments;
  LOG_INFO("\nTOTAL PRICES ");

 fstream fp;
  fp.open (admin, ios::in);
       if(r.admin_code==r.user_dcode)
            cout<<r.admin_prices;
    fp.close();
  int prices = atoi (r.admin_prices);
  cout << "=" << prices * People;
  LOG_INFO("\nPaid amount: ");
  cin>>r.user_prices;
  LOG_INFO("\nENTER 'Confirm' TO CONFIRM YOUR RESERVATION: ");
  cin>>r.user_status;

  user_package (r);
}
void travel::choosevehicle(){

    int choice;
    LOG_INFO("\n1.car\n2.Bus");
    LOG_INFO("\nEnter your choice");
    cin>>choice;
    switch(choice)
    {
        case 1:
        int passengers,cabChoice,kilometers,carCost;
        LOG_INFO("\nYou choosed car");
        LOG_INFO("\n1.Standard Cab - Rs.15 for 1KM");
        LOG_INFO("\n2.Luxury Cab - Rs.25 per 1KM");

        LOG_INFO("\n1.Standard car\n2.Luxury car");
        LOG_INFO("\nEnter which kind of cab you need: ");
        cin >> cabChoice;
        LOG_INFO("\nEnter no of passengers");
        cin>>passengers;
        LOG_INFO("\nEnter Kilometers you have to travel: ");
        cin >> kilometers;
        if(cabChoice==1){

        carCost = (kilometers * 15)* passengers;
        cout<<"\nYour tour will cost " << carCost  << endl;
        }
        else
        {

        carCost = (kilometers * 25)*passengers;
            cout << "\nYour tour will cost " << carCost  << endl;
        }
        break;
        case 2:
        int Tourists,Distance,Buscharge,BusChoice;
        LOG_INFO("\nYou choosed Bus");
        LOG_INFO("\n1.Non-Ac Bus - Rs.12 for 1KM");
        LOG_INFO("\n2.Ac Bus- Rs. 30 per 1KM");
        LOG_INFO("\n1.AC\n2.Non-AC");
        LOG_INFO("\nEnter which kind of Busyou need: ");
        cin >> BusChoice;
        LOG_INFO("\nEnter no of passengers");
        cin>>Tourists;
        LOG_INFO("\nEnter Kilometers you have to travel: ");
        cin >>Distance;
        if(BusChoice==1){

        Buscharge =(Distance * 12) * Tourists;
        cout << "\nYour tour will cost " << Buscharge << endl;
        }
        else
        {

        Buscharge =(Distance * 30) * Tourists;
        cout << "\nYour tour will cost " << Buscharge  << endl;
        }
        break;

        default:
        LOG_ERROR("\nInvalid choice");

    }
    LOG_INFO("\nYour Booking is sucessful");
}
//displays the user data
void travel :: user_display(){
        fstream fp;
        char data[SIZE];
        tour r;
    fp.open(user,ios::in);
    if(!fp){
                LOG_ERROR("\nCannot open file");
                exit(0);
    }
    cout<<"------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"Sr No.\tNAME\tCONTACT NO\tTOTAL PEOPLE\tDATE\tDEST. CODE\tPAYMENT\tPRICE\tSTATUS\n";
    cout<<"------------------------------------------------------------------------------------------------------------------------\n";
    int serial_no=1;
    while(1){
        fp.getline(data,SIZE);
        if(fp.eof())break;
                r=user_showpackage(data);
        cout<<serial_no++<<"\t"<<r.user_name<<"\t"<<r.user_phone<<"\t"<<r.user_people<<"\t"<<r.user_date<<"\t"<<r.user_dcode<<"\t"<<r.user_payments<<"\t"<<r.user_prices<<"\t"<<r.user_status<<endl;
}
    fp.close();
    return;
}

//To cancel the data in user package
void travel :: user_cancel(){
    fstream fp;
    char user_name[SIZE],data[SIZE];
    int index,indexj;
    tour s[SIZE];
    fp.open(user,ios::in);
    if(!fp){
                LOG_ERROR("\nFile not Found");
                exit(0);
    }
    LOG_INFO("\nEnter Your name to cancel  your reservation: ");
    cin>>user_name;
    index=0;
        while(1){
        fp.getline(data,SIZE);
        if(fp.eof())break;
        s[index]=user_showpackage(data);
        index++;
    }
        for(indexj=0;indexj<index;indexj++){
 if(strcmp(s[indexj].user_name,user_name)==0){
                        LOG_INFO("\nYour Reservation Details are:\n");
                        cout<<"\nName: "<<s[indexj].user_name;
                        cout<<"\nContact No.: "<<s[indexj].user_phone;
                        cout<<"\nNo.of People: "<<s[indexj].user_people;
                        cout<<"\nDestination: "<<s[indexj].user_dcode;
                        cout<<"\nDate of Journey: "<<s[indexj].user_date;
                        LOG_INFO("\n\nENTER 'Cancel' TO CANCEL YOUR TICKET: \n");
                        cin>>s[indexj].user_status;
                        LOG_INFO("\nYour Reservation has been Cancelled\n");
                        cout<<"\n\nName: "<<s[indexj].user_name;
                        cout<<"\nContact No.: "<<s[indexj].user_phone;
                        cout<<"\nNo.of People: "<<s[indexj].user_people;
                        cout<<"\nDestination: "<<s[indexj].user_dcode;
                        cout<<"\nDate of Journey: "<<s[indexj].user_date;
            break;
        }
    }
  if(indexj==index){
        LOG_ERROR("\nRECORD NOT FOUND");
        return;
    }
    fp.close();
    fstream fd;
    fd.open(user,ios::out|ios::in);
    if(!fd){
        LOG_ERROR("\nCannot open file");
        exit(0);
    }
        for(indexj=0;indexj<index;indexj++)
        user_package(s[indexj]);
        fd.close();
}

// To search the user reservations
void travel :: user_search(){
        fstream fp;
        char user_name[SIZE],data[SIZE];
        int index,indexj;
        tour s;
    fp.open(user,ios::in);
    if(!fp){
                LOG_ERROR("\nCannot open file");
                exit(0);
 }
    LOG_INFO("\nENTER THE NAME TO BE SEARCHED: ");
    cin>>user_name;
    index=0;
        while(1){
        fp.getline(data,SIZE);
        if(fp.eof())break;
        s=user_showpackage(data);
        if(strcmp(s.user_name,user_name)==0){
                        LOG_INFO("\n RESERVATION FOUND\n");
                        cout<<"\nNAME: "<<s.user_name;
                        cout<<"\nCONTACT NO.: "<<s.user_phone;
                        cout<<"\nNO. OF PEOPLE: "<<s.user_people;
                        cout<<"\nDATE OF JOURNEY: "<<s.user_date;
                        return;
                }
    }
    LOG_INFO("\nRESERVATION NOT FOUND");
    return;
}

