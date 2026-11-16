/*
 Assalam-o-Alaikum Sir,

 Just to let you know, I have been coding for about 2 years now. For this
 helpdesk report I took help from <iomanip> (setw) and string(70, '-'),
 which we have not covered in lectures, only so that the columns and
 separator lines look tidy in the console. Everything else, including the
 digit extraction (only / and %, no arrays or string functions), follows
 the lecture topics.

 Thank you,
 Hamas Jan (BC260444887)
*/

#include <iostream>
#include <string>
#include <iomanip>   // only for table formatting: setw
using namespace std;

int main()
{
    // ----- My information -----
    string name = "Hamas Jan";
    string studentID = "BC260444887";
    int idNumber = 260444887;   // 9-digit numeric part of my ID

    cout << "Student Name: " << name << endl;
    cout << "Student ID  : " << studentID << endl;
    cout << endl;

    // ----- Constants -----
    const int MINUTES_PER_TICKET = 20;
    const int HEAVY_LIMIT = 7;      // 7 or more tickets
    const int MODERATE_LIMIT = 4;   // 4 to 6 tickets

    // ----- Digit extraction using only / and % -----
    // Positions from the left: 1 2 3 4 5 6 7 8 9
    // We need positions 2, 4, 5, 6 and 8, so we peel digits off from the right.
    idNumber = idNumber / 10;              // drop 9th digit
    int pos8 = idNumber % 10;              // 8th digit
    idNumber = idNumber / 10;
    idNumber = idNumber / 10;              // drop 7th digit
    int pos6 = idNumber % 10;              // 6th digit
    idNumber = idNumber / 10;
    int pos5 = idNumber % 10;              // 5th digit
    idNumber = idNumber / 10;
    int pos4 = idNumber % 10;              // 4th digit
    idNumber = idNumber / 10;
    idNumber = idNumber / 10;              // drop 3rd digit
    int pos2 = idNumber % 10;              // 2nd digit

    cout << "Extracted digits: " << pos2 << ", " << pos4 << ", "
         << pos5 << ", " << pos6 << ", " << pos8 << endl;
    cout << endl;

    // ----- Report header -----
    cout << "----- University IT Helpdesk WorkLoad Report -----" << endl;
    cout << string(70, '-') << endl;
    cout << left
         << setw(25) << "Unit"
         << setw(15) << "Total Tickets"
         << setw(20) << "Resolution Time"
         << "Status" << endl;
    cout << string(70, '-') << endl;

    // ----- Counters for the summary -----
    int lightCount = 0;
    int moderateCount = 0;
    int heavyCount = 0;

    // ----- Process the five service desks -----
    for (int desk = 1; desk <= 5; desk++)
    {
        string deskName;
        int tickets;

        // Assign name and digit in the required order
        if (desk == 1)
        {
            deskName = "Network Support:";
            tickets = pos2;
        }
        else if (desk == 2)
        {
            deskName = "Computer Lab Support:";
            tickets = pos4;
        }
        else if (desk == 3)
        {
            deskName = "LMS Support:";
            tickets = pos5;
        }
        else if (desk == 4)
        {
            deskName = "Account Support:";
            tickets = pos6;
        }
        else
        {
            deskName = "Hardware Support:";
            tickets = pos8;
        }

        // Estimated resolution time in minutes
        int resolutionTime = tickets * MINUTES_PER_TICKET;

        // Workload classification
        string status;
        if (tickets >= HEAVY_LIMIT)
        {
            status = "HEAVY";
            heavyCount++;
        }
        else if (tickets >= MODERATE_LIMIT)
        {
            status = "MODERATE";
            moderateCount++;
        }
        else
        {
            status = "LIGHT";
            lightCount++;
        }

        // Print the row
        cout << left
             << setw(25) << deskName
             << setw(15) << tickets
             << setw(20) << resolutionTime
             << status << endl;
    }

    cout << endl;

    // ----- Summary -----
    cout << "===== SUMMARY =====" << endl;
    cout << "LIGHT desks    : " << lightCount << endl;
    cout << "MODERATE desks : " << moderateCount << endl;
    cout << "HEAVY desks    : " << heavyCount << endl;

    return 0;
}