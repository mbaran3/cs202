#include <iostream>
#include "StopWatch.h"

int fib_loop(int n){
    if(n <= 1)
        return n;  
    else 
       return fib_loop(n-1) + fib_loop(n -2);
}
int fib(int n){
    int first = 0;
    int second = 1;
    int next = 1;

    for(int i = 0; i < n-1; i++){
            next = first + second;
            first = second;
            second = next;
    }
    return next;

}
int ack(int m, int n){
    
    if(m == 0)
       return n+1;
    else if(m > 0 && n == 0)
       return ack(m-1, 1);
    else if(m > 0 && n > 0)
        return ack(m-1,ack(m, n-1));

    
}
int main(int argc, char *argv[]){

    StopWatch timer;
    if(argc ==  2){
        long n = strtol(argv[1], NULL , 10);
        int normal = fib(n);
        int recursion = fib_loop(n);
        //I can compute out to n = 46
        if(normal == recursion)
            std::cout << "They both equal " << normal << std::endl;
        else
            std::cout << "normal =" << normal << " recursion =" << recursion << std::endl;  
    }
    if(argc == 3){
        long m = strtol(argv[1], NULL, 10);
        long n = strtol(argv[2], NULL, 10);
        std::cout << ack(m, n) << std::endl;
        std::cout << "It took :" << timer.getDurationmilli() << std::endl;
    }  





    return 0;
}