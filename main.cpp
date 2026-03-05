/**
 * @file main.cpp
 * @brief Test driver for the generic linearSearch template.
 */

#include "bookType.h"
#include "searchUtil.h"

#include <iostream>
#include <string>

int main() {
    using std::cout;
    using std::string;

    cout << "============================\n";
    cout << "  Testing linearSearch<int>\n";
    cout << "============================\n";

    int numbers[] = {10, 25, 30, 47, 55};
    const int numberCount = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Array: {";
    for (int i = 0; i < numberCount; ++i) {
        cout << numbers[i];
        if (i < numberCount - 1) {
            cout << ", ";
        }
    }
    cout << "}\n";

    const int intFoundTarget = 30;
    const int intMissingTarget = 99;

    int intFoundIndex = linearSearch(numbers, numberCount, intFoundTarget);
    int intMissingIndex = linearSearch(numbers, numberCount, intMissingTarget);

    cout << "Searching for " << intFoundTarget << "... ";
    if (intFoundIndex != -1) {
        cout << "Found at index " << intFoundIndex << '\n';
    } else {
        cout << "Not found\n";
    }

    cout << "Searching for " << intMissingTarget << "... ";
    if (intMissingIndex != -1) {
        cout << "Found at index " << intMissingIndex << '\n';
    } else {
        cout << "Not found\n";
    }

    cout << "\n===============================\n";
    cout << "  Testing linearSearch<string>\n";
    cout << "===============================\n";

    string names[] = {"Alice", "Bob", "Charlie"};
    const int nameCount = sizeof(names) / sizeof(names[0]);

    cout << "Array: {";
    for (int i = 0; i < nameCount; ++i) {
        cout << '"' << names[i] << '"';
        if (i < nameCount - 1) {
            cout << ", ";
        }
    }
    cout << "}\n";

    const string stringFoundTarget = "Bob";
    const string stringMissingTarget = "Zara";

    int stringFoundIndex = linearSearch(names, nameCount, stringFoundTarget);
    int stringMissingIndex = linearSearch(names, nameCount, stringMissingTarget);

    cout << "Searching for \"" << stringFoundTarget << "\"... ";
    if (stringFoundIndex != -1) {
        cout << "Found at index " << stringFoundIndex << '\n';
    } else {
        cout << "Not found\n";
    }

    cout << "Searching for \"" << stringMissingTarget << "\"... ";
    if (stringMissingIndex != -1) {
        cout << "Found at index " << stringMissingIndex << '\n';
    } else {
        cout << "Not found\n";
    }

    cout << "\n=================================\n";
    cout << "  Testing linearSearch<bookType>\n";
    cout << "=================================\n";

    BookType books[] = {
        BookType("Sandwich", "978-0-321-56384-2",
                 "Guy Startup", "Publisher", "01/15/2026", 12,
                 54.99f, 79.99f),
        BookType("Clean Code", "978-0-132-35088-4", "Patrick Star",
                 "Carnegie Hall", "01/18/2026", 8, 28.50f, 45.99f),
        BookType("Design Patterns", "978-0-201-63361-0", "Spongebob Squarepants",
                 "Penguin Haus", "01/22/2026", 5, 35.00f, 57.99f)};
    const int bookCount = sizeof(books) / sizeof(books[0]);

    cout << "Inventory (" << bookCount << " books):\n";
    for (int i = 0; i < bookCount; ++i) {
        cout << "  [" << i << "] " << books[i];
    }

    BookType foundBookTarget;
    foundBookTarget.setISBN("978-0-132-35088-4");
    int foundBookIndex = linearSearch(books, bookCount, foundBookTarget);

    cout << "\nSearching for ISBN " << foundBookTarget.getISBN() << "...\n";
    if (foundBookIndex != -1) {
        cout << "  Found at index " << foundBookIndex << ":\n";
        cout << books[foundBookIndex];
    } else {
        cout << "  Not found\n";
    }

    BookType missingBookTarget;
    missingBookTarget.setISBN("000-0-000-00000-0");
    int missingBookIndex = linearSearch(books, bookCount, missingBookTarget);

    cout << "\nSearching for ISBN " << missingBookTarget.getISBN() << "...\n";
    if (missingBookIndex != -1) {
        cout << "  Found at index " << missingBookIndex << ":\n";
        cout << books[missingBookIndex];
    } else {
        cout << "  Not found\n";
    }

    return 0;
}
