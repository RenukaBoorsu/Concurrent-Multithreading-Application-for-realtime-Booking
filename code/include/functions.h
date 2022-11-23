// FUNCTIONS.H
#ifndef FUNCTIONS_H
// class name travel
class travel{
             public:
             travel()
             { 
                 cout<<"Travel Booking App"<<endl;
             }
             
                void menu();
		void login();
                void admin_package(tour r);
	            tour admin_showpackage(char a[]);
	            void admin_writedata();
	            void admin_display();
	            void admin_modify();
	            void user_registration();
	            void user_login();
	            void user_forgot();
	            void user_package(tour r);
	            tour user_showpackage(char a[]);
	            void user_writedata();
		    void choosevehicle();
	            void user_display();
	            void user_search();
	            void user_cancel();
};
#endif /* FUNCTIONS_H */
