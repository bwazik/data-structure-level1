#pragma once
#include <iostream>
#include "clsDate.h"
#include "queue"
#include "stack"

using namespace std;

class clsQueueLine
{
private:    
    short _totalTickets = 0;
    short _averageServeTime = 0;
    string _prefix = "";

    class clsTicket
    {
    private:
        short _number = 0;
        string _prefix;
        string _ticketTime;
        short _waitingClients = 0;
        short _averageServeTime = 0;
        short _expectedServeTime = 0;

    public:
        clsTicket(string prefix, short number, short waitingClients, short averageServeTime)
        {
            _number = number;
            _ticketTime = clsDate::getSystemDateTime();
            _prefix = prefix;
            _waitingClients = waitingClients;
            _averageServeTime = averageServeTime;
        }

        string prefix()
        {
            return _prefix;
        }

        short number()
        {
            return _number;
        }

        string fullNumber()
        {
            return _prefix + to_string(_number);
        }

        string ticketTime()
        {
            return _ticketTime;
        }

        short waitingClients()
        {
            return _waitingClients;
        }

        short expectedServeTime()
        {
            return _averageServeTime * _waitingClients;
        }

        void Print()
        {
            cout << "\n\t\t\t  _______________________\n";
            cout << "\n\t\t\t\t    " << fullNumber();
            cout << "\n\n\t\t\t    " << _ticketTime;
            cout << "\n\t\t\t    Wating Clients = " << _waitingClients;
            cout << "\n\t\t\t      Serve Time In";
            cout << "\n\t\t\t       " << expectedServeTime() << " Minutes.";
            cout << "\n\t\t\t  _______________________\n";
        }
    };
public:
	queue <clsTicket> queueLine;

    clsQueueLine(string prefix, short averageServeTime)
    {
        _prefix = prefix;
        _totalTickets = 0;
        _averageServeTime = averageServeTime;
    }

    void issueTicket()
    {
        _totalTickets++;
        clsTicket ticket(_prefix, _totalTickets, waitingClients(), _averageServeTime);
        queueLine.push(ticket);
    }

    int waitingClients()
    {
        return queueLine.size();
    }

    string whoIsNext()
    {
        if (queueLine.empty())
            return "No Clients Left.";
        else
            return queueLine.front().fullNumber();
    }

    bool serveNextClient()
    {
        if (queueLine.empty())
            return false;

        queueLine.pop();

        return true;
    }

    short servedClients()
    {
        return _totalTickets - waitingClients();
    }

    void printInfo()
    {
        cout << "\n\t\t\t _________________________\n";
        cout << "\n\t\t\t\tQueue Info";
        cout << "\n\t\t\t _________________________\n";
        cout << "\n\t\t\t    Prefix   = " << _prefix;
        cout << "\n\t\t\t    Total Tickets   = " << _totalTickets;
        cout << "\n\t\t\t    Served Clients  = " << servedClients();
        cout << "\n\t\t\t    Wating Clients  = " << waitingClients(); ;
        cout << "\n\t\t\t _________________________\n";
        cout << "\n";

    }

    void printTicketsLineRTL()
    {
        if (queueLine.empty())
            cout << "\n\t\tTickets: No Tickets.";
        else
            cout << "\n\t\tTickets: ";

        // We copy the queue in order not to lose the original
        queue <clsTicket> tempQueueLine = queueLine;

        while (!tempQueueLine.empty())
        {
            clsTicket ticket = tempQueueLine.front();

            cout << " " << ticket.fullNumber() << " <-- ";

            tempQueueLine.pop();
        }

        cout << "\n";
    }

    void printTicketsLineLTR()
    {
        if (queueLine.empty())
            cout << "\n\t\tTickets: No Tickets.";
        else
            cout << "\n\t\tTickets: ";

        // We copy the queue in order not to lose the original
        queue <clsTicket> tempQueueLine = queueLine;
        stack <clsTicket> tempStackLine;

        while (!tempQueueLine.empty())
        {
            tempStackLine.push(tempQueueLine.front());
            tempQueueLine.pop();
        }

        while (!tempStackLine.empty())
        {
            clsTicket ticket = tempStackLine.top();

            cout << " " << ticket.fullNumber() << " --> ";

            tempStackLine.pop();
        }
        cout << "\n";
    }

    void printAllTickets()
    {
        cout << "\n\n\t\t\t       ---Tickets---";

        if (queueLine.empty())
            cout << "\n\n\t\t\t     ---No Tickets---\n";

        // We copy the queue in order not to lose the original
        queue <clsTicket> tempQueueLine = queueLine;
        while (!tempQueueLine.empty())
        {
            tempQueueLine.front().Print();
            tempQueueLine.pop();
        }
    }
};

