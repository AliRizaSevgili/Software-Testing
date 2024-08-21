#pragma once
#ifndef ADDRESS_H
#define ADDRESS_H

#define NAME_LIMIT 20
//struct Customers;
struct Customers
{
	char custFirst;
	char custLast;
	char streetAddress[125];
	char city;
	char province;
	char postalCode;
};

int addressValidation(char firstN[],char LastN[], char address[], char city[]);


#endif // !ADDRESS_H
