#include <iostream>

int fib_loop(int n){
    if(n <= 1)
        return n;  
    else 
       return fib_loop(n-1) + fib_loop(n -2);
}

int main(int argc, char *argv[]){

    long n = strtol(argv[1], NULL , 10);
    std::cout << fib_loop(n) << std::endl;

    return 0;
}