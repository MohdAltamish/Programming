package com.programs.java.code;

import java.util.Scanner;

public class code {
    static void main() {
        Scanner sc = new Scanner(System.in);

        int s;

        System.out.println("Enter a number");
        s = sc.nextInt();

        /* This program is used to double the digit using right shift method: */

        int a = 5 << s;
        System.out.println(a);
    }
}
