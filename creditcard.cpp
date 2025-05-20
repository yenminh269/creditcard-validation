#include <iostream>
#include <vector>
#include <string>
int get_odd_numbered_digit(std::string number){
    int sum = 0;
    for(int i = number.size()-1; i >= 0; i -= 2){
        sum += number[i] - 48;
    }
    return sum;
}
int get_digit_sum(int num){
    std::string str = std::to_string(num);
    int sum = 0;
    for(char c:str){
        sum += c - 48;
    }
    return sum;
}
int get_even_numbered_digit(std::string number){
    int temp = 0;
    int sum = 0;
    for(int i = number.size()-2; i >= 0; i -= 2){
        temp = number[i] - 48;
        temp *= 2;
        if(temp >= 10){
            int temp2 = get_digit_sum(temp);
            sum += temp2;
        }
        else{
            sum += temp;
        }
        
    }
    return sum;

}
int main(){
    std::cout<<"***Credit Card Validation***\n";
    std::cout<<"Enter your 16-digit credit card number: ";
    std::string number;
    std::cin>>number;
    int result = get_odd_numbered_digit(number) + get_even_numbered_digit(number);
  
    if(result % 10 == 0){
        std::cout<<"Your credit card number is valid";
    }
    else{
        std::cout<<"Your credit card number is invalid";
    }
    return 0;
}