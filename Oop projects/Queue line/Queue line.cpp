#include <iostream>
#include "clsQueueLine.h"
using namespace std; 

int main()
{
	clsQueueLine payBillsQueue("A0", 10); 

	payBillsQueue.issueTicket();
	payBillsQueue.issueTicket();
	payBillsQueue.issueTicket();
	payBillsQueue.issueTicket();
	payBillsQueue.issueTicket();

	payBillsQueue.printQueueInfo(); 

	payBillsQueue.printTicketsLineRTL();
	payBillsQueue.printAllTickets(); 



	cout << "The queue after serving one client : " << endl << endl; 
	payBillsQueue.serveNextClient(); 

	payBillsQueue.printQueueInfo(); 
	payBillsQueue.printAllTickets(); 

}