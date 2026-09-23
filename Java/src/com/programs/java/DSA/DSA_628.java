package com.programs.java.DSA;

import java.util.Arrays;

// This program returns the maximum product of three largest number in an Array!

public class DSA_628 {
    public int maximumProduct(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int product = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int product2 = nums[0] * nums[1] * nums[n - 1];
        return Math.max(product, product2);
    }
}