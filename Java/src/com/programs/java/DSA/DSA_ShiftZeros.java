package com.programs.java.DSA;

// This program is used to shift all the zeros in an array to the last position


public class DSA_ShiftZeros {

    public int[] shiftZeroes(int[] nums) {
        int j = 0;
        int i, temp;
        for (i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                if (i != j) {
                    temp = nums[i];
                    nums[i] = nums[j];
                }j++;
            }
        }
        return nums;
    }
}



//        for (int i = 0; i < nums.length; i++) {
//            for (int j = i + 1; j < nums.length - 1; j++) {
//                if (nums[j] == 0) {
//                    int temp = nums[j];
//                    nums[j] = nums[j + 1];
//                    nums[j + 1] = temp;
//                }
//            }
//        }
//        return nums;

//int j = 0;
//        int i, temp;
//
//    for (i = 0; i < n; i++){
//        if (nums[i] != 0) {
//        if (i != j ){
//temp = nums[i];
//nums[i] = nums[j];
//nums[j] = temp;
//            }
//j++;
//        }
//        }
