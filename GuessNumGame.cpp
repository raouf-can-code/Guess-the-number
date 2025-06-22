#include <iostream>
#include <vector>
#include <ctime>
#include <string>

using str = std::string;

int random(int min, int max);
bool checkDif(str dif);

int main(){
    str dif;
    str range = "hi";
    str guess;
    bool running = true;
    int att = 0;
    int answer;
    int max;

    std::cout << "---{ Guess The Number }---\n" << "Welcome to the guess the numbe game\n";
    std::cout << "Choose a diffuclty:\n" << "easy (1-10)\n" << "medium (1-25)\n" << "hard (1-50)\n";
    do{getline(std::cin, dif);}while (checkDif(dif));
    switch (dif.at(0)){
    case 'e':
        range = "1 - 10";
        max = 10;
     break;
    case 'm':
        range = "1 - 25";
        max = 25;
     break;
    case 'h':
        range = "1 - 50";
        max = 50;
     break;
    }

    answer = random(1, max);

    std::cout << "You have choosen" << dif << " diffuclty\n now guess a number between " << range << ":\n";
    do{
        std::cin >> guess;
        try{
            int guessNum = std::stoi(guess);
            if(guessNum == answer){
                std::cout <<"Congrats you' ve guessed the number correctly in "<< att <<" attempts\n";
                running = false;
            }else if(guessNum > max || guessNum < 1){
                std::cout <<"Wrong, and please try to enter a number between the range\n";
                att++;
            }else{
                std::cout <<"Wrong, try again :)\n";
                att++;
            }
        }catch(...){
            std::cout << "invalid value, enter a number\n";
        }
    }while(running);

    return 0;
}

int random(int min, int max){
    srand(time(NULL));
    int resault = rand() % (max - min + 1) + min;
    return resault;
}
bool checkDif(str dif){
    if (dif == "easy" || dif == "medium" || dif == "hard") {
        return false;
    } else {
        return true;
    }
}
