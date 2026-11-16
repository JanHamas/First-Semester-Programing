/*
 Dear Sir,

 I have been programming for the last 2 years, so I am already comfortable
 with C++. In this assignment I used a few built-in features that were not
 covered in our lectures: the <iomanip> header (setw) and string(n, '-').
 I used them only to get a clean, well-aligned table in the output,
 exactly like the sample in the assignment. All the logic (variables,
 constants, modulus/division, loops, if/else) uses what we learned in class.

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
    int idNumber = 260444887;   // numeric part of my ID

    cout << "Student Name: " << name << endl;
    cout << "Student ID  : " << studentID << endl;
    cout << endl;

    // ----- Constants -----
    const int RATE_5L = 70;            // Rs. per 5-litre container
    const int RATE_19L = 180;          // Rs. per 19-litre container
    const int DISCOUNT_LIMIT = 50;     // containers needed for discount
    const int DISCOUNT_PERCENT = 10;   // discount percentage

    // ----- Extract the last five digits using % and / -----
    int d5 = idNumber % 10;   idNumber = idNumber / 10;   // 5th digit from right (last)
    int d4 = idNumber % 10;   idNumber = idNumber / 10;
    int d3 = idNumber % 10;   idNumber = idNumber / 10;
    int d2 = idNumber % 10;   idNumber = idNumber / 10;
    int d1 = idNumber % 10;   idNumber = idNumber / 10;

    // ----- Daily totals -----
    int totalContainers = 0;
    int totalOriginal = 0;
    int totalDiscount = 0;
    int totalFinal = 0;

    // ----- Report header -----
    cout << "===== COMMUNITY WATER REFILL DEPOT - DAILY REPORT =====" << endl;
    cout << endl;

    cout << left
         << setw(8) << "Order"
         << setw(10) << "Quantity"
         << setw(22) << "Package Type"
         << setw(15) << "Original(Rs.)"
         << setw(12) << "Discount"
         << "Final(Rs.)" << endl;

    cout << string(75, '-') << endl;

    // ----- Process the five orders -----
    for (int order = 1; order <= 5; order++)
    {
        int digit;
        int rate;
        string packageType;

        // Pick the digit for this order
        if (order == 1)
            digit = d1;
        else if (order == 2)
            digit = d2;
        else if (order == 3)
            digit = d3;
        else if (order == 4)
            digit = d4;
        else
            digit = d5;

        int quantity = digit * 10;

        // First three orders are 5-litre, last two are 19-litre
        if (order <= 3)
        {
            rate = RATE_5L;
            packageType = "5-Litre Container";
        }
        else
        {
            rate = RATE_19L;
            packageType = "19-Litre Container";
        }

        int originalCharge = quantity * rate;

        // 10% discount for 50 or more containers
        int discount = 0;
        if (quantity >= DISCOUNT_LIMIT)
        {
            discount = originalCharge * DISCOUNT_PERCENT / 100;
        }

        int finalCharge = originalCharge - discount;

        // Print the row
        cout << left
             << setw(8) << order
             << setw(10) << quantity
             << setw(22) << packageType
             << setw(15) << originalCharge
             << setw(12) << discount
             << finalCharge << endl;

        // Update totals
        totalContainers = totalContainers + quantity;
        totalOriginal = totalOriginal + originalCharge;
        totalDiscount = totalDiscount + discount;
        totalFinal = totalFinal + finalCharge;
    }

    cout << string(75, '-') << endl;
    cout << endl;

    // ----- Sales status -----
    string salesStatus;

    if (totalFinal < 15000)
    {
        salesStatus = "LOW SALES";
    }
    else if (totalFinal < 30000)
    {
        salesStatus = "NORMAL SALES";
    }
    else
    {
        salesStatus = "HIGH SALES";
    }

    // ----- Daily summary -----
    cout << "===== DAILY SUMMARY =====" << endl;
    cout << "Total Containers Supplied : " << totalContainers << endl;
    cout << "Total Original Charges    : Rs. " << totalOriginal << endl;
    cout << "Total Discount            : Rs. " << totalDiscount << endl;
    cout << "Final Amount Collected    : Rs. " << totalFinal << endl;
    cout << "Sales Status              : " << salesStatus << endl;

    return 0;
}