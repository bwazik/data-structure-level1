#include <iostream>
#include "clsQueueLine.h";

using namespace std;

int main()
{
    clsQueueLine PayBillsQueue("A0", 10);
    clsQueueLine SubscriptionsQueue("B0", 5);


    PayBillsQueue.issueTicket();
    PayBillsQueue.issueTicket();
    PayBillsQueue.issueTicket();
    PayBillsQueue.issueTicket();
    PayBillsQueue.issueTicket();

    cout << "\nPay Bills Queue Info:\n";
    PayBillsQueue.printInfo();

    PayBillsQueue.printTicketsLineRTL();
    PayBillsQueue.printTicketsLineLTR();

    PayBillsQueue.printAllTickets();

    PayBillsQueue.serveNextClient();
    cout << "\nPay Bills Queue After Serving One client\n";
    PayBillsQueue.printInfo();

    cout << "\nSubscriptions Queue Info:\n";

    SubscriptionsQueue.issueTicket();
    SubscriptionsQueue.issueTicket();
    SubscriptionsQueue.issueTicket();


    SubscriptionsQueue.printInfo();

    SubscriptionsQueue.printTicketsLineRTL();
    SubscriptionsQueue.printTicketsLineLTR();

    SubscriptionsQueue.printAllTickets();

    SubscriptionsQueue.serveNextClient();
    cout << "\nSubscriptions Queue After Serving One client\n";
    SubscriptionsQueue.printInfo();
	system("pause>0");
}