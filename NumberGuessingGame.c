#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){

//1. Random number generation between 1 and 100
int min_num = 1;
int max_num = 100;
srand(time(NULL));
int number = rand() % max_num + min_num; // number between 1 and 10

int max = 10; // Total number of guesses that the user has
int guesscounter = 0;
int guess; // The user's guess

int bottom = min_num;
int top = max_num;

//Welcome message
printf("\n\nIn this game you will have %d guesses to guess a number between %d and %d. Good luck!\n",max,min_num,max_num);


//3. Loops through the code
for(int i = 1; i <= max ; i++){
    //2. & 5. Input from the user and the number of the players guesses is i in this case
    printf("The number will be between %d and %d.\nPlease provide guess #%d of %d that is between 1 and 100: ",bottom,top,i,max);
    scanf("%d",&guess);

    //4. Guess checker
    if(guess>number){
    printf("Too High\n");
    top = guess;

    }else if(guess<number){
    printf("Too Low\n");
    bottom = guess;

    }else{
    printf("Correct! You got it right on guess number %d.\n",i);
    break; // Ends the code early if the user guesses the correct answer
    }

//Could count the guess this way too, useful for the statement after the code..
guesscounter++;

}

if(guesscounter==max){
printf("The correct answer was %d!",number);

}

}

