#include <stdio.h>

int points[5] = {2, 3, 6, 7, 8};
int possibilities[1000];

void printCombos(int currPoints, int pointsIndex, int possIndex) {
    int solution = 0;
    int i = 0;
    
    int td = 0;
    int fg = 0;
    int sft = 0;
    int tdc = 0;
    int tdfg = 0;
    
    if (currPoints == 0) {
        for (i = 0; i < possIndex; i++) {
            solution = possibilities[i];

            switch (solution) {
                case 2:
                    sft++;
                    break;
                case 3:
                    fg++;
                    break;
                case 6:
                    td++;
                    break;
                case 7:
                    tdfg++;
                    break;
                case 8:
                    tdc++;
                    break;
            }

            if (i == possIndex - 1) {
                printf("\n%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety", tdc, tdfg, td, fg, sft);
                td = 0;
                fg = 0;
                sft = 0;
                tdc = 0;
                tdfg = 0;
            }
        }
    } else if (currPoints > 0) {
        for (i = pointsIndex; i < 5; i++) {
            possibilities[possIndex] = points[i];
            printCombos(currPoints - points[i], i, possIndex + 1);
        }
    }
}

int main() {

    for (int i = 0; i < 1000; i++) {
        possibilities[i] = 0;
    }

    int input = 2;
    
    while(input > 1){
        printf("\n\nEnter 0 or 1 to STOP\n");
        printf("Enter the NFL currPoints: ");
        scanf("%d", &input);
        if (input > 1){
            printCombos(input, 0, 0);
        }
    }
    return 0;

}