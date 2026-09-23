package com.programs.java.DSA;

public class TwoSum {
    public int[] twoSum(int[] nums, int target) {
        int base = nums[0];
        int[] result = null;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (target == nums[i] + nums[j]) {
                    result = new int[]{i, j};
            }
            }
        }
        return result;
    }
}
