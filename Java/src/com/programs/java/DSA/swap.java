package com.programs.java.DSA;

import java.util.Arrays;
import java.util.Scanner;

public class swap {
    static void main() {
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[2];
        arr[0] = sc.nextInt();
        arr[1] = sc.nextInt();

        int temp = arr[0];
        arr[0] = arr[1];
        arr[1] = temp;
        System.out.println(Arrays.toString(arr));
    }
}
