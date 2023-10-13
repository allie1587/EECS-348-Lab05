
#include <stdio.h>

float average(float salesData[12]){
    float total = 0.0;
    for (int i = 0; i < 12; i++){
        total += salesData[i];
    }
    return total / 12;
}
int main(){
    //Asks the user to input a file name
    char filename[100];
    printf("Please enter the file name: ");
    scanf("%s", filename);

    //Reads the file
    FILE *inputFile = fopen(filename, "r");
    float sales[12];
    for (int i = 0; i < 12; i++) {
        fscanf(inputFile, "%f", &sales[i]);
    }
    fclose(inputFile);

    //Makes a list of month names
    char *months[] = {"January", "Febuary", "March" , "April", "May", "June", "July", "August", "September", "October", "November", "Decemeber"};

    //Prints the sale report for 2023
    printf("Monthly sales report for 2023\n");
    
    //Prints the each months sale in order of month
    printf("Month\t\tSales\n");
    for (int i = 0; i < 12; i++){
        printf("%-10s\t%.2lf\n", months[i], sales[i]);
    }

    //Prints the sales summary
    printf("Sales Summary:\n");
    
    //Finds the minimum sale and prints it
    float min = sales[0];
    int monthmin = 0;
    for (int i = 1; i < 12; i++){
        if (sales[i] < min){
            monthmin = i;
            min = sales[i];
        }
    }
    printf("Minimum sales:\t$%.2lf\t(%s)\n", min, months[monthmin]);

    //Finds the maximum sale and prints it
    float max = sales[0];
    int maxmonth;
    for (int i = 1; i < 12; i++){
        if (sales[i] > max){
            maxmonth = i;
            max = sales[i];
        }
    }
    printf("Maximum sales:\t$%.2lf\t(%s)\n", max, months[maxmonth]);

    //Finds the Average sales by calling the average function
    printf("Average sales:\t$%.2lf\n",average(sales));

    //Prints the six-month moving average
    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i < 12 - 5; i++) {
        double movingAverage = (sales[i] + sales[i + 1] + sales[i + 2] + sales[i + 3] + sales[i + 4] + sales[i + 5]) / 6;
        printf("%-10s - %-10s \t $%.2lf\n", months[i], months[i + 5], movingAverage);
    }

    //Prints the sales report from highest to lowest
    printf("Sales Report (Highest to Lowest):\n");
    printf("Month\t\tSales\n");
    for (int i = 0; i < 11; i++) {
        for (int j = i + 1; j < 12; j++) {
            if (sales[i] < sales[j]) {
                char* temps = months[i];
                float temp = sales[i];

                sales[i] = sales[j];
                months[i] = months[j];

                sales[j] = temp;
                months[j] = temps;
            }
        }
    }
    for (int i = 0; i < 12; i++){
        printf("%-10s\t%.2lf\n", months[i], sales[i]);
    }
    return 0;
}
