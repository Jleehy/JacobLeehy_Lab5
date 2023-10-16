#include <stdio.h>
#include <string.h>

void listPrint(char label[][20], float values[]){
    printf("Monthly sales reprt for 2023:\n\n");
    printf("Month\t\tSales\n\n");
    for (int i = 0; i < 12; ++i) {
        printf("%s\t$%.2f\n", label[i], values[i]);
    }
}

void printSummary(char label[][20], float values[]){
    
    float min = values[0];
    char minMonth[20];
    strcpy(minMonth, label[0]);
    float max = values[0];
    char maxMonth[20];
    strcpy(maxMonth, label[0]);
    float average = 0;

    for (int i = 1; i < 12; i++) {
        if (values[i] < min) {
            min = values[i];
            strcpy(minMonth, label[i]);
        }
        if (values[i] > max) {
            max = values[i];
            strcpy(maxMonth, label[i]);
        }
        average += values[i];
    }
    average /= 12;
    printf("Sales Summary:\n\n");
    printf("Minimum Sales:\t$%.2f (%s)\n", min, minMonth);
    printf("Maximum Sales:\t$%.2f (%s)\n", max, maxMonth);
    printf("Average Sales:\t$%.2f", average);

}

void movingAverage(char label[][20], float values[]){
    float average;
    char lowMonth[20];
    char highMonth[20];
    
    printf("Six-Month Moving Average Report:\n\n");
    
    for (int i = 0; i < 7; i++){
        average = (values[i] + values[i+1] + values[i+2] + values[i+3] + values[i+4] + values[i+5])/6;
        strcpy(lowMonth, label[i]);
        strcpy(highMonth, label[i+5]);
        printf("%s\t-\t%s\t$%.2f\n", lowMonth, highMonth, average);
    }

}

void sortPrint(char label[][20], float values[]){
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11 - i; j++) {
            if (values[j] < values[j + 1]) {
                float temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
                
                char labelTemp[20];
                strcpy(labelTemp, label[j]);
                strcpy(label[j], label[j+1]);
                strcpy(label[j+1], labelTemp);
            }
        }
    }
    printf("Sales Report (Highest to Lowest):\n\n");
    printf("Month\t\tSales\n\n");
    for (int i = 0; i < 12; i++) {
        printf("%s\t$%.2f\n", label[i], values[i]);
    }
}


int main(){
    float sales[12] = {23458.01,40112.00,56011.85,37820.88,37904.67,60200.22,72400.31,56210.89,67230.84,68233.12,80950.34,95225.22};
    char months[12][20] = {"January    ", "February   ", "March     ", "April     ", "May      ", "June      ", "July      ", "August   ", "September", "October    ", "November", "December"};
    listPrint(months, sales);
    printf("----------------------------------------------\n");
    char months2[12][20] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printSummary(months2, sales);
    printf("\n----------------------------------------------\n");
    movingAverage(months, sales);
    printf("\n----------------------------------------------\n");
    sortPrint(months, sales);
}