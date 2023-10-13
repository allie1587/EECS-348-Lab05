#include <stdio.h>
void findCombinations(int score){
    int td, fg, saftey, tdFG, tdConversion;
    for (tdConversion = 0; tdConversion <= score / 8; tdConversion++){
        for (tdFG = 0; tdFG <= score / 7; tdFG++){
            for (td = 0; td <= score / 6; td++){
                for (fg = 0; fg <= score / 3; fg++){
                    for (saftey = 0; saftey <= score / 2; saftey++){
                        int total = td*6 + fg*3 + saftey*2 + tdFG*7 + tdConversion*8;
                        if (total == score){
                            printf("%d TD + 2pts, %d TD + FG, %d TD, %d 3pt FG, %d Saftey\n", tdConversion, tdFG, td, fg, saftey);
                        }
                    }
                }
            }
        }
    }
}
int main(){
    int score;
    while(1){

        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if (score <= 1){
            break;
        }else{
            printf("Possible combinations of scoring plays: \n");
            char combination[100] = "";
            findCombinations(score);
        }
    }

    return 0;
}