package com.programs.java.DSA;

import java.util.ArrayList;
import java.util.List;

public class DSA_412_FizzBuzz {

    public List<String> fizzBuzz(int n) {
        List<String> list = new ArrayList<>();

        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                list.add("FizzBuzz");
            }
            else if (i % 3 == 0) {
                list.add("Fizz");
            }
            else if (i % 5 == 0) {
                list.add("Buzz");
            }
            else {
                list.add(String.valueOf(i));
            }
        }return list;
    }
}




/*
char** fizzBuzz( int n, int* returnSize) {
    char**result=(char**)malloc(n *sizeof(char*));
    for(int i=0;i<n;i++)
    {
        result[i]=(char*)malloc(12 *sizeof(char));
        if((i+1)%15==0)
        {
            sprintf(result[i],"FizzBuzz");
        }
        else if((i+1)%3==0)
        {
            sprintf(result[i],"Fizz");
        }
        else if((i+1)%5==0)
        {
            sprintf(result[i],"Buzz");
        }
        else
        {
            sprintf(result[i],"%d",i+1);
        }
    }
 *returnSize=n;
    return result;
}
 */