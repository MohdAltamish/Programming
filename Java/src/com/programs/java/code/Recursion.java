package com.programs.java.code;

import java.util.Scanner;

public class Recursion {

    // Factorial using recursion:
    public static int fact(int num){
        if (num == 1){
            return 1;
        }
        return num * fact(num - 1);
    }

    // Fibonacci series using recursion:
    public static int fab(int num){
        if (num == 0 || num == 1){
            return 1;
        }
        return num + fab(num - 1);
    }

    // Sum of Natural number using recursion:
    public static int sum(int num){
        if (num == 1){
            return 1;
        }
        return num + sum(num - 1);
    }
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);


        int num = sc.nextInt();
        System.out.println(fact(num));

        int sum = sum(num);
        System.out.println(sum);

    }
}
