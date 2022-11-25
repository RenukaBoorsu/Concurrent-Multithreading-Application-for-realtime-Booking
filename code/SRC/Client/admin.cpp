#define SIZE 300

void travel :: admin_package(tour r){
     fstream fp;
     fp.open(admin,ios::out|ios::app);
     if(!fp){
		LOG_ERROR("\nCannot open file");
		exit(0);
     }
     char data[SIZE];
     strcpy(data,r.admin_code);
     strcat(data,"|");
     strcat(data,r.admin_place);
     strcat(data,"|");
     strcat(data,r.admin_country);
     strcat(data,"|");
     strcat(data,r.admin_days);
     strcat(data,"|");
     strcat(data,r.admin_payments);
     strcat(data,"|");
     strcat(data,r.admin_prices);
     strcat(data,"|");
     for(int index=0;index<SIZE-strlen(data);index++)
            strcat(data,"|");
     fp<<data<<endl;
     fp.close();
}

// To read the added packages
tour travel :: admin_showpackage(char data[]){
	tour r;
	int index=0,indexj=0;
	while(data[indexj]!='|')   
	      r.admin_code[index++]=data[indexj++];
	r.admin_code[index]='\0';
	index=0;
	indexj++;
	while(data[indexj]!='|')
	      r.admin_place[index++]=data[indexj++];
	r.admin_place[index]='\0';
	index=0;
	indexj++;
	while(data[indexj]!='|')
	      r.admin_country[index++]=data[indexj++];
	r.admin_country[index]='\0';
	index=0;
	indexj++;
	while(data[indexj]!='|')
	      r.admin_days[index++]=data[indexj++];
	r.admin_days[index]='\0';
	index=0;
	indexj++;
	while(data[indexj]!='|')
	      r.admin_payments[index++]=data[indexj++];
	r.admin_payments[index]='\0';
	index=0;
	indexj++;
	while(data[indexj]!='|')
	      r.admin_prices[index++]=data[indexj++];
	r.admin_prices[index]='\0';
	
	return(r);
}

// To write data in admin package
void travel :: admin_writedata(){
    tour s;
    LOG_INFO("\nEnter the Destination Code\nD-");
    cin>>s.admin_code;
    LOG_INFO("\nEnter the Destination Place\n");
    cin>>s.admin_place;
    LOG_INFO("\nEnter the Country of the Destination\n");
    cin>>s.admin_country;
    LOG_INFO("\nEnter the Number of days of the Trip\n");
    cin>>s.admin_days;
    LOG_INFO("\nMethod of payment: \n");
    cin>>s.admin_payments;
    LOG_INFO("\nEnter the Cost of the trip: \n");
    cin>>s.admin_prices;
    
    admin_package(s);
}

//display the admin package to the user
void travel :: admin_display(){
 	fstream fp;
   	char data[SIZE];
   	tour r;
    fp.open(admin,ios::in);
    if(!fp){
		LOG_ERROR("\nCannot open file");
		exit(0);
    }
    cout<<"-------------------------------------------------------------------------------------------------\n";
    cout<<"Sr No.\tDEST. CODE\tPLACE\tCOUNTRY\tDAYS\tPAYMENTS\tPRICES\n";
    cout<<"-------------------------------------------------------------------------------------------------\n";
    int serial_no=1;
    while(1){
        fp.getline(data,SIZE);
        if(fp.eof())break;
       		r=admin_showpackage(data);
        cout<<serial_no++<<"\t"<<r.admin_code<<"\t"<<r.admin_place<<"\t"<<r.admin_country<<"\t" <<r.admin_days<<"\t"<<r.admin_payments<<"\t"<<r.admin_prices<<endl;
    }
    fp.close();
    
    return;
}

//To modify the admin packages
void travel :: admin_modify(){
    fstream fp;
    char admin_code[SIZE],data[SIZE];
    int index,indexj,ch;
    tour s[SIZE];
    fp.open(admin,ios::out|ios::in);
    if(!fp){
		LOG_ERROR("\nCannot open file");
		exit(0);
    }
    LOG_INFO("\nENTER THE DESTINATION CODE TO BE MODIFIED: ");
    cin>>admin_code;
    index=0;
   	while(1){
        fp.getline(data,SIZE);
        if(fp.eof())break;
        s[index]=admin_showpackage(data);
        index++;
    }
   	for(indexj=0;indexj<index;indexj++){
       		if(strcmp(s[indexj].admin_code,admin_code)==0){
                    LOG_INFO("\nVALUES OF THE TRIP\n");
                    cout<<"\nDestination Code: "<<s[indexj].admin_code;
                    cout<<"\nDestination Place: "<<s[indexj].admin_place;
                    cout<<"\nDestination Country: "<<s[indexj].admin_country;
                    cout<<"\nNo of days of Trip: "<<s[indexj].admin_days;
                    cout<<"\n Payments method: (card or Cash): "<<s[indexj].admin_payments;
                    cout<<"\nTotal Cost of the Trip: "<<s[indexj].admin_prices;
                    LOG_INFO("\nWhat you want to Update: ");
	  		cout<<"\n\n\t\tEnter 1 for changing DESTINATION PLACE\n";
	  		cout<<"\t\tEnter 2 for changing DAYS OF THE TRIP\n";
	  		cout<<"\t\tEnter 3 for changing COST & PAYMENTS OF THE TRIP\n";
	  		cout<<"\t\t\t";
	  		cin>>ch;
	  		switch(ch){
                case 1:
                    LOG_INFO("\nDestination Place: ");
                    cin>>s[indexj].admin_place;
                    LOG_INFO("\nDestination Country: ");
                    cin>>s[indexj].admin_country;
                    break;
                case 2:
                    LOG_INFO("\nNo of days of Trip: ");
                    cin>>s[indexj].admin_days;
                    break;
                case 3:
                    LOG_INFO("\nTotal Cost of the Trip: ");
                    cin>>s[indexj].admin_prices;
                    break;
			}
		break;
            }
		
    }
   	if(indexj==index){
        LOG_ERROR("\n TRIP NOT FOUND");
        return;
    }
    fp.close();
    fstream fd;
    fd.open(admin,ios::out| ios::trunc);
    if(!fd){
        LOG_INFO("\nFile Not Found");
        exit(0);
    }
   	for(indexj=0;indexj<index;indexj++)
         admin_package(s[indexj]);
   	fd.close();
	
}
