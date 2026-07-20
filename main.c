#include <stdio.h>

int main()
{
    int choice;

    // Showtimes
    char showtimes[][50] =
    {
        "10:00 AM - Avatar 2",
        "01:00 PM - Room No. 106",
        "04:00 PM - Toy Story 5",
        "07:00 PM - Minions",
        "10:00 PM - Spider-Man"
    };

    int totalShows = 5;

    // Seat Map (O = Available, X = Booked)
    char seats[5][5] =
    {
        {'O','O','O','O','O'},
        {'O','O','X','O','O'},
        {'O','O','O','O','O'},
        {'X','O','O','O','X'},
        {'O','O','X','X','O'}
    };

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
            {
                printf("\n========== TODAY'S SHOWTIMES ==========\n");

                for(int i = 0; i < totalShows; i++)
                {
                    printf("%d. %s\n", i + 1, showtimes[i]);
                }

                break;
            }

            case 2:
            {
                printf("\n========== SEAT MAP ==========\n\n");

                printf("      1 2 3 4 5\n");

                for(int i = 0; i < 5; i++)
                {
                    printf("Row %d ", i + 1);

                    for(int j = 0; j < 5; j++)
                    {
                        printf("%c ", seats[i][j]);
                    }

                    printf("\n");
                }

                break;
            }

            case 3:
                printf("\nBook a Seat selected.\n");
                break;

            case 4:
                printf("\nCancel Booking selected.\n");
                break;

            case 5:
                printf("\nSearch Booking selected.\n");
                break;

            case 6:
                printf("\nRevenue Report selected.\n");
                break;

            case 7:
                printf("\nThank you for using the Movie Ticket Booking System!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while(choice != 7);

    return 0;
}
