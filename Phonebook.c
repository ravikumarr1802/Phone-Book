/******************************************************************************
This is C program which works like a phone book to store contact numbers
using structurs in C.
*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_CONTACTS 100
struct Address 
{
    char street[50];
    char city[50];
    char state[20];
    char group[10];
};
struct Contact
{
    char name[50];
    char phone[10];
    struct Address address;
};
struct AddressBook 
{
    int num_contacts;
    struct Contact contacts[MAX_CONTACTS];
};
void add_contact(struct AddressBook *book);
void display_contacts(struct AddressBook *book);
void search_contacts(struct AddressBook *book);
int main() 
{
    struct AddressBook book={0};
    int choice;
    do {
        printf("\nAddress Book\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact(&book);
                break;
            case 2:
                display_contacts(&book);
                break;
            case 3:
                search_contacts(&book);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice!= 4);
    return 0;
}
void add_contact(struct AddressBook *book)
{
    if (book->num_contacts >= MAX_CONTACTS)
    {
        printf("Address book is full\n");
        return;
    }
    struct Contact *contact = &book->contacts[book->num_contacts];
    int n;
    printf("Enter no of contacts:");
    scanf("%d",&n); 
    for(int i=0;i<n;i++)
    {
    printf("Enter name %d: ",i+1);
    scanf("%s", contact->name);
    printf("Enter phone: ");
    scanf("%s", contact->phone);
    printf("Enter street: ");
    scanf("%s", contact->address.street);
    printf("Enter city: ");
    scanf("%s", contact->address.city);
    printf("Enter state: ");
    scanf("%s", contact->address.state);
    printf("Enter group: ");
    scanf("%s", contact->address.group);
    book->num_contacts++;
    }
}
void display_contacts(struct AddressBook *book)
{
    if (book->num_contacts == 0) 
    {
        printf("No contacts in address book\n");
        return;
    }
    printf("%s\t%s\t%s\t%s\t%s\t%s\n", "Name", "Phone", "Street", "City", "State", "Group");
    for (int i = 0; i < book->num_contacts; i++)
    {
        struct Contact *contact = &book->contacts[i];
        printf("%s\t%s\t%s\t%s\t%s\t%s\n", contact->name, contact->phone, contact->address.street, contact->address.city, contact->address.state, contact->address.group);
    }
}
void search_contacts(struct AddressBook *book)
{
    if (book->num_contacts == 0)
    {
        printf("No contacts in address book\n");
        return;
    }
    char search_name[50];
    printf("Enter name to search: ");
    scanf("%s", search_name);
    int found = 0;
    for (int i = 0; i < book->num_contacts; i++)
    {
        struct Contact *contact = &book->contacts[i];
        if (strcmp(contact->name, search_name)== 0)
        {
            printf("%s\t%s\t%s\t%s\t%s\t%s\n", "Name", "Phone", "Street", "City", "State", "Group");
            printf("%s\t%s\t%s\t%s\t%s\t%s\n", contact->name, contact->phone, contact->address.street, contact->address.city, contact->address.state, contact->address.group);
            found=1;
            break;
        }
    }
    if (!found) 
    {
        printf("Contact not found\n");
    }
}



