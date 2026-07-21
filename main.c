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
{
    char customer[50];
    int show, row, col;
    int price = 0;
    int ticketCount;
    int student, senior;
    float discount = 0;
    float finalPrice;

    printf("\n========== BOOK A SEAT ==========\n");

    printf("\nAvailable Showtimes:\n");
    for(int i = 0; i < totalShows; i++)
    {
        printf("%d. %s\n", i + 1, showtimes[i]);
    }

    printf("\nSelect Showtime (1-%d): ", totalShows);
    scanf("%d", &show);

    if(show < 1 || show > totalShows)
    {
        printf("Invalid showtime!\n");
        break;
    }

    printf("Enter Customer Name: ");
    scanf("%49s", customer);

    printf("Enter Row (1-5): ");
    scanf("%d", &row);

    printf("Enter Seat Number (1-5): ");
    scanf("%d", &col);

    if(row < 1 || row > 5 || col < 1 || col > 5)
    {
        printf("Invalid seat number!\n");
        break;
    }

    if(seats[row-1][col-1] == 'X')
    {
        printf("Sorry! Seat is already booked.\n");
        break;
    }

    // Price by row
    if(row == 1 || row == 2)
    {
        price = 500;
    }
    else if(row == 3 || row == 4)
    {
        price = 750;
    }
    else
    {
        price = 1000;
    }

    // Only one discount category allowed
    do
    {
        printf("Student? (1=Yes, 0=No): ");
        scanf("%d", &student);

        printf("Senior Citizen? (1=Yes, 0=No): ");
        scanf("%d", &senior);

        if(student == 1 && senior == 1)
        {
            printf("Please select only ONE discount category.\n\n");
        }

    } while(student == 1 && senior == 1);

    printf("Number of tickets: ");
    scanf("%d", &ticketCount);

    if(ticketCount <= 0)
    {
        printf("Invalid number of tickets!\n");
        break;
    }

    discount = 0;

    if(student == 1)
    {
        discount += 10;
    }

    if(senior == 1)
    {
        discount += 20;
    }

    if(ticketCount >= 4)
    {
        discount += 10;
    }

    finalPrice = (price * ticketCount) - ((price * ticketCount) * discount / 100);

    // Book the selected seat
    seats[row-1][col-1] = 'X';

    printf("\n========== BOOKING SUCCESSFUL ==========\n");
    printf("Customer Name : %s\n", customer);
    printf("Showtime      : %s\n", showtimes[show-1]);
    printf("Seat          : Row %d Seat %d\n", row, col);
    printf("Tickets       : %d\n", ticketCount);
    printf("Price/Ticket  : Rs.%d\n", price);
    printf("Discount      : %.0f%%\n", discount);
    printf("Total Amount  : Rs.%.2f\n", finalPrice);

    break;
}
            case 4:

{
                int row, column;

                printf("\n========== CANCEL A BOOKING ==========\n");

                printf("Enter Row (1-5): ");
                scanf("%d", &row);

                printf("Enter Seat Number (1-5): ");
                scanf("%d", &column);

                // 1. Validate seat boundary
                if (row < 1 || row > 5 || column < 1 || column > 5)
                {
                    printf("Invalid seat position! Row and Seat must be between 1 and 5.\n");
                    break;
                }

                // 2. Check if the seat is actually booked ('X')
                if (seats[row - 1][column - 1] == 'O')
                {
                    printf("Seat Row %d, Seat %d is not currently booked.\n", row, column);
                }
                else
                {
                    // 3. Reset seat status to Available ('O')
                    seats[row - 1][column - 1] = 'O';
                    printf("\nBooking for Row %d, Seat %d has been successfully canceled!\n", row, column);
                }

                break;
            }

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
