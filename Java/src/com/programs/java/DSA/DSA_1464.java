package com.programs.java.DSA;

// Maximum Product of Two Elements in an Array

public class DSA_1464 {

    public static int maxProduct(int[] nums) {
        int first = 0;
        int second = 0;
        for (int num : nums){
            if (num > first){
                second = first;
                first = num;
            }
            else if (num > second){
                second = num;
            }
        }
        return (first - 1) * (second - 1);
    }

    static void main() {
        int[] arr = new int[]{1, 5, 7, 2, 9, 3};
        System.out.println(maxProduct(arr));
    }
}

// This also works but this version is less optimised!
//        Arrays.sort(nums);
//        int n = nums.length;
//        return    (nums[n - 1] - 1) * (nums[n - 2] - 1);