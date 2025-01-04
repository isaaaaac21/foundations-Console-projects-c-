#pragma once
#include <iostream>
#include <string>
#include <queue>
#include "clsDate.h"
#include <iomanip>
using namespace std; 
class clsQueueLine
{
private: 
	string linePref;
	int serviceDuration; 
    int totalTickets;
    int servedClients;
    //int waitingClients;

	struct sTicket
	{
		string code  ; 
		string dateTime = clsDate::GetSystemDateTimeString();

		void printTicket(queue<sTicket> line, int waiting, int duration)
		{
			cout << setw(30) << left << "" << "____________________________" << endl << endl;
			cout << setw(40) << left << "" <<  code << endl;
			cout << setw(32) << left << "" << dateTime << endl;
			cout << setw(32) << left << "" << "Waiting clients : " << waiting << endl;
			cout << setw(32) << left << "" << "Service time In" << endl;
			cout << setw(32) << left << "" << waiting * duration << " min" << endl;
			cout << setw(30) << left << "" << "____________________________" << endl << endl;
		}
	};




	queue <sTicket> line; 
	 sTicket _generateTicket()
	{
		sTicket ticket;
		ticket.code = linePref + to_string(totalTickets);  
		return ticket; 
	}
public: 
	clsQueueLine(string pref, int sd) : linePref(pref), serviceDuration(sd)
	{
		totalTickets = 0; 
		servedClients = 0; 
	
	}; 

	void issueTicket()
	{
		totalTickets++;
		sTicket ticket = _generateTicket();
		line.push(ticket); 
	}

	void printAllTickets()
	{
		int waiting = 0; 
		queue<sTicket> copy = line;
		cout << setw(35) << left << "" << "** Tickets **" << endl;

		while (!copy.empty())
		{
			copy.front().printTicket(copy, waiting, serviceDuration ); 
			waiting++; 
			copy.pop();
		}
	}

	void printQueueInfo()
	{
		
		cout << setw(30) << left << "" << "____________________________" << endl << endl;
		cout << setw(38) << left << "" << "Queue Info" << endl;
		cout << setw(30) << left << "" << "____________________________" << endl << endl;
		cout << setw(33) << left << "" << "Prefix          : " << linePref << endl;
		cout << setw(33) << left << "" << "Total Tickets   : " << totalTickets << endl;
		cout << setw(33) << left << "" << "Served clients  : " << servedClients << endl;
		cout << setw(33) << left << "" << "Waiting clients : " << line.size()  << endl;
		cout << setw(30) << left << "" << "____________________________"  << endl<<  endl;

		
	}

	void serveNextClient()
	{
		line.pop(); 
		servedClients++; 
	}

	void printTicketsLineRTL()
	{
		queue<sTicket> copy = line;
		cout << setw(20) << left << "" << "Tickets : ";
		while (!copy.empty())
		{
			cout << copy.front().code;
			if (copy.size() != 1) cout << "  <--   ";
			copy.pop(); 
		}
		cout << endl << endl; 

	}
};

