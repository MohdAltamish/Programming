package com.programs.java.DSA;

import com.programs.java.code.Array;

import java.util.Arrays;

public class DSA_3016 {
    public int minimumPushes(String word) {

        int[] freq = new int[26];

        for (char c : word.toCharArray()) {
            int i = freq[c - 'a']++;
        }
        Arrays.sort(freq);
        int totalPushes = 0;
        int position = 1;
        int count = 0;

        for (int i = 25; i >= 0; i--) {
            if (freq[i] == 0){
                continue;
            }
            totalPushes += freq[i] * position;
            count++;
            if (count % 8 == 0) {
                position++;
            }
        }
        return totalPushes;
    }
}
