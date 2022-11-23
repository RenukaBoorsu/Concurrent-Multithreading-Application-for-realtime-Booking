//header.h
#ifndef HEADER_H
#include<iostream>
#include<fstream>
#include <string.h>
#include <sys/socket.h>
#include <cstring>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <signal.h>
using namespace std;
#define MAX_LENGTH 30

char admin[MAX_LENGTH]="Trip.txt";
char user[MAX_LENGTH]="reservations.txt";

struct tour{
 	char admin_place[MAX_LENGTH],admin_code[MAX_LENGTH],admin_country[MAX_LENGTH],admin_days[MAX_LENGTH],admin_prices[MAX_LENGTH],admin_payments[MAX_LENGTH];
 	char user_phone[MAX_LENGTH],user_name[MAX_LENGTH],user_people[MAX_LENGTH],user_date[MAX_LENGTH],user_status[MAX_LENGTH],user_dcode[MAX_LENGTH],user_prices[MAX_LENGTH],user_payments[MAX_LENGTH];
};
#endif /* HEADER_H */

