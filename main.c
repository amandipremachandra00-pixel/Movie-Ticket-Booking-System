#include <stdio.h>

int main()
{
    int choice;

    do
    {
        printf("\n=====================================\n");
        printf("     MOVIE TICKET BOOKING SYSTEM\n");
        printf("=====================================\n");
        printf("1. View Showtimes\n");
        printf("2. View Seat Map\n");
        printf("3. Book a Seat\n");
        printf("4. Cancel a Booking\n");
        printf("5. Search Booking\n");
        printf("6. Revenue Report\n");
        printf("7. Exit\n");
        printf("-------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("View Showtimes selected.\n");
                break;

            case 2:
                printf("View Seat Map selected.\n");
                break;

            case 3:
                printf("Book a Seat selected.\n");
                break;

            case 4:
                printf("Cancel Booking selected.\n");
                break;

            case 5:
                printf("Search Booking selected.\n");
                break;

            case 6:
                printf("Revenue Report selected.\n");
                break;

            case 7:
                printf("Thank you for using the system!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while(choice != 7);

    return 0;
}

