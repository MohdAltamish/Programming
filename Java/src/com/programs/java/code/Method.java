package com.programs.java.code;

public class Method {

    // It Prints the sum of Array
    public static int sumOfArray(int[] arr){
        int sum = 0;
        for(int i: arr){
            sum += i;
        }
        return sum;
    }

    // It removes the space from a string and convert to uppercase:
    public static String upperfun(String str){
        return str.trim().toUpperCase();
    }

    // It can take multiple num and return their sum
    public static int sum(int... a){
        int sum = 0;
        for (int i: a){
            sum += i;
        }
        return sum;
    }

    // It checks whether the given num is prime or not:
    public static boolean isPrime(int n) {
        int res = 0;
        for (int i = 1; i <= n/2; i++){
            if (n % i == 0) {
                res++;
            }
        }
        return res == 1;
    }

    public static void main(String[] args) {

        int[] arr = {1,2,3,4,5};



        System.out.println(sumOfArray(arr));

        System.out.println(upperfun("  mohd altamish   "));

        System.out.println(sum(arr));

        System.out.println(isPrime(4));

    }
}
