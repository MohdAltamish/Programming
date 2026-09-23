package com.programs.java.DSA;

public class DSA_3014 {
    public int minimumPushes(String word) {
        int n = word.length();
        int totalpushes = 0;
        for (int i = 0; i < n; i++) {
            int position = ((i / 8) + 1);
            totalpushes += position;
        }return  totalpushes;
    }
}
