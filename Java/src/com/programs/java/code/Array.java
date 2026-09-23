package com.programs.java.code;

public class Array {
    public static void main(String[] args) {
        int[] arr = {1,2,-3,4,-5,6};

        // Search an element in array:

        for(int i: arr){
            if(i == 4){
                System.out.println("Found");
            }
        }

        // Finding the maximum element in array:

        int min = Integer.MIN_VALUE;
        for(int i = 0; i < arr.length; i++){
            if(arr[i] > min){
                min = arr[i];
            }
        }
        System.out.println("Minimum Value: " + min);

        // Finding the maximum element in array:

        int max = Integer.MAX_VALUE;
        for(int i = 0; i < arr.length; i++){
            if(arr[i] < max){
                max = arr[i];
            }
        }
        System.out.println("Maximum Value: " + max);

        // Reversing an array:

        int reverse = 0;
        for(int i = arr.length - 1; i >= 0; i--){
            System.out.println("Reverse Value: " + reverse);
        }

        // Sum of an array:

        int sum = 0;
        for (int j : arr) {
            sum += j;
        }
        System.out.println("Sum: " + sum);

    }
}
