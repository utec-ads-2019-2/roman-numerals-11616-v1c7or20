#include <iostream>
#include <string>
#include <map>

std::map<char,int> maps;
int divisores[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
std::string romanos[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

void ToNumber(std::string word){
    int num =0;
    int control =0;
    for (auto it = word.rbegin(); it != word.rend() ; it++) {
        *it;
        if(maps.at(*it)>=control){
            num = num+maps.at(*it);
            control = maps.at(*it);
        } else{
            num=num-maps.at(*it);
        }
    }
    std::cout<<num<<std::endl;
}

void ToRoman(std::string word){
    int len = word.size();
    int num = 0;
    if(word[0] > '0' && word[0] <= '9'){
        int p = 1;
        for(int i = 0; i < len; i++){
            num += p * (word[len - i - 1] - 48);
            p *= 10;
        }
        std::string res = "";
        for(int i = 0; i < 13; i++){
            if(num >= divisores[i]){
                int div = num / divisores[i];
                num = num % divisores[i];
                for(int k = 0; k < div; k++)
                    res += romanos[i];
            }
        }
        std::cout << res << std::endl;
}
}

int main() {
    maps.insert(std::pair<char,int>('I',1));
    maps.insert(std::pair<char,int>('V',5));
    maps.insert(std::pair<char,int>('X',10));
    maps.insert(std::pair<char,int>('L',50));
    maps.insert(std::pair<char,int>('C',100));
    maps.insert(std::pair<char,int>('D',500));
    maps.insert(std::pair<char,int>('M',1000));
    std::string word="4";
    while (std::cin>>word){
        if(isdigit(word.at(0))){
            ToRoman(word);
        }else ToNumber(word);
    }
    ToRoman(word);
    return 0;
}