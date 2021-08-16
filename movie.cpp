#include <bits/stdc++.h>
using namespace std;
struct multiticket
{
    string name;
    int ticketid;
};
class movie
{
public:
    int arr[10][25] = {0};
    int filled = 0;
    int vacant = 250;

    void display()
    {
        cout << endl;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 25; j++)
            {
                cout << arr[i][j] << " ";
                if (j % 5 == 0 and j != 0)
                    cout << "  ";
            }
            if (i == 4)
                cout << endl;
            cout << endl;
        }
    }

    void ticketinfo()
    {
        if (vacant > 0)
        {
            int ticket_count;
            cout << "Enter the number of tickets required :  ";
            cin >> ticket_count;
            bookticket(ticket_count);
        }
        else
            cout << "Sorry all the tickets are filled" << endl;
    }
    void bookticket(int n)
    {
        cout << endl;
        cout << "Below seat matrix shows the filled and vacant seats : " << endl;
        cout << endl;
        display();
        cout << endl;
        if (n > vacant)
        {
            cout << "sorry only " << vacant << " are available" << endl;
            return;
        }
        int row_number;
        int column_number;
        multiticket data[n];
        for (int i = 0; i < n; i++)
        {
            cout << endl;
            cout << "Enter the name :   ";
            cin >> data[i].name;
            while (true)
            {
                cout << "Enter the desired row number :   ";
                cin >> row_number;
                while (row_number > 10)
                {
                    cout << "Invalid row number,row should be between 1 to 10 " << endl;
                    cout << "Enter the desired row number :   ";
                    cin >> row_number;
                }
                cout << "Enter the desired column number :   ";
                cin >> column_number;
                while (column_number > 25)
                {
                    cout << "Invalid row number,row should be between 1 to 25 " << endl;
                    cout << "Enter the desired column number :   ";
                    cin >> column_number;
                }
                if (arr[row_number - 1][column_number - 1])

                    cout << "The seat is already filled,choose another seat" << endl;
                else
                {
                    int ticket_id = (row_number - 1) * 25 + column_number;
                    data[i].ticketid = ticket_id;
                    arr[row_number - 1][column_number - 1] = 1;
                    vacant--;
                    break;
                }
            }
        }
        printticket(data, n);
    }
    void printticket(struct multiticket data[], int n)
    {
        cout << "\n ----------------KRISHNA THEATRE-----------------" << endl;
        cout << endl;
        for (int i = 0; i < n; i++)
        {

            cout << "Name            : " << data[i].name << endl;
            cout << "Ticket id       : " << data[i].ticketid << endl;
            cout << "Booking Status  : "
                 << "Confirmed" << endl;
            cout << endl;
        }

        cout << "------------------------------------------------------" << endl;
    }

    void cancelticket()
    {
        int tickid;
        cout << "Enter the ticket id :   ";
        cin >> tickid;
        int row = tickid / 25;
        int column = tickid % 25 - 1;
        if (row > 10 or column > 25)
        {
            cout << "\nInvalid Ticket id  " << endl;
            return;
        }
        if (arr[row][column] == 0)
        {
            cout << "\n The seat is already vacant, make sure you entered correct ticket id : " << endl;
            return;
        }
        arr[row][column] = 0;

        cout << "------------------------------------------------------" << endl;
        cout << endl;
        cout << "Ticket Cancelled Sucessfully  " << endl;
        cout << endl;
        cout << "------------------------------------------------------" << endl;
    }
};
int main()
{
    cout << endl;
    cout << "-----------------WELCOME TO THE KRISHNA THEATRE-------------- " << endl;
    movie sai;
    while (true)
    {
        int choice;
        cout << endl;
        cout << "1.Display seat Matrix" << endl;
        cout << "2.Book a Ticket" << endl;
        cout << "3.Cancel a Ticket" << endl;
        cout << "4.Exit" << endl;
        cout << endl;
        cout << "Select an option to proceed :   ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            sai.display();
            break;
        case 2:
            sai.ticketinfo();
            break;
        case 3:
            sai.cancelticket();
            break;
        case 4:
            exit(0);
        default:
            cout << "\n Invalid Selection \n";
        }
    }
    return 0;
}