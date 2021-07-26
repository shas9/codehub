#include<stdio.h> // General Header File
#include<stdlib.h> // Added to function properly "exit(0)"

void resistanceParallel() // Function to calculate equivalent resistance of n parallel resistance
{
    printf("*** Equivalent Resistor â€“ Parallel ***\n");
    printf("*** Enter -1 to end the input ***\n");

    double ans = 0;

    while(1)
    {
        int resistance;
        printf("Type a resistor value (>0): ");
        scanf("%d", &resistance); // Taking input

        if(resistance == -1) break; // Done with taking input

        if(resistance <= 0) // Resistance invalid
        {
            printf("Invalid Input. Please Try again!\n");
            continue;
        }

        ans += (1.0 / resistance); // adding the resistance value into the answer
    }

    if(ans == 0) // ans == 0 means there was no valid input given
    {
        printf("Error! You must input atleast one resistor\n");
        printf("Please try again!\n");
        resistanceParallel(); // Recursion starts, will take input once again
        return;
    }

    ans = (1.0 / ans); // final answer calculation

    printf("The equivalent resistance is %.2f Ohms!!!\n", ans);

    return;
}

void resistanceSeries() // Function to calculate equivalent resistance of n series resistance
{
    printf("*** Equivalent Resistor â€“ Series ***\n");
    printf("*** Enter -1 to end the input ***\n");

    int ans = 0;

    while(1)
    {
        int resistance;
        printf("Type a resistor value (>0): ");
        scanf("%d", &resistance); // Taking input

        if(resistance == -1) break; // Done with taking input

        if(resistance <= 0) // Resistance invalid
        {
            printf("Invalid Input. Please Try again!\n");
            continue;
        }

        ans += resistance; // Adding answers
    }

    if(ans == 0) // ans == 0 means there is no valid input given
    {
        printf("Error! You must input atleast one resistor\n");
        printf("Please try again!\n");
        resistanceSeries(); // Recursion starts, will take input once again
        return;
    }

    printf("The equivalent resistance is %d Ohms!!!\n", ans);

    return;
}

void powerDissipation() // function to calculate power dissipaton from resistor and voltage drop
{
    printf("*** Resistor Power Dissipation ***\n");
    int resistor, voltage;

    printf("Resistor value (Ohms) (>0): ");
    scanf("%d", &resistor); // Taking resistor as input

    printf("Voltage drop (Volts) (>0): ");
    scanf("%d", &voltage); // Taking voltage drop as input

    if(voltage <= 0 || resistor <= 0) // Validity check
    {
        printf("Invalid Input. Please Try again!\n");
        powerDissipation(); // Resursion, and will take input again.
        return;
    }

    double ans = (voltage * voltage * 1.0) / resistor; // Final calculation

    printf("The power dissipation is %.2f Watts!!!\n", ans);

    return;
}

int displayMenu() // funtction to display menu, will return 1 if option is valid else will return 0
{
    printf("Please select a function:\n");
    printf("<1> Equivalent resistance (parallel)\n");
    printf("<2> Equivalent resistance (series)\n");
    printf("<3> Resistor power dissipation\n");
    printf("<4> Exit\n");
    printf("Type your option: ");

    int option;
    scanf("%d", &option); // taking input as option

    if(option == 1) // User selected option 1
    {
        resistanceParallel();
    }
    else if(option == 2) // User selected option 2
    {
        resistanceSeries();
    }
    else if(option == 3) // User selected option 3
    {
        powerDissipation();
    }
    else if(option == 4) // User selected option 4 aka chooses to exit
    {
        printf("Thanks for using our program!\n");
        exit(0);
    }
    else return 0; // invalid input, so return 0

    return 1; // valid input so return 1;
}

int main()
{
    // Name of author of the code
    printf("\t\tAuthor: Ismam Yeamim Sowad\n");
    printf("\t\tID:161090196\n\n\n\n");

    while(displayMenu()); // will be continuos untill user presses 4 or gives any invalid input

    printf("Sorry! Invalid choice!\n"); // invalid option choosen, thus loop got broke and printed this message;

    return 0;
}
