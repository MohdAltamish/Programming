package com.programs.java.code;

class DataTypes {
    static void main() {
        System.out.println("Hello World");

        byte age1 = 10;
        System.out.println(age1);
        short age2 = 20;
        System.out.println(age2);
        int age3 = 30;
        System.out.println(age3);
        long age4 = 40;
        System.out.println(age4);
        float age5 = 5f;
        System.out.println(age5);
        double age6 = 2d;
        System.out.println(age6);
        boolean age7 = true;
        System.out.println(age7);
        char age8 = 'A';
        System.out.println(age8);

        System.out.println(Byte.MIN_VALUE);
        System.out.println(Byte.MAX_VALUE);

        System.out.println(Short.MAX_VALUE);
        System.out.println(Short.MIN_VALUE);

        System.out.println(Integer.MAX_VALUE);
        System.out.println(Integer.MIN_VALUE);

        System.out.println(Long.MAX_VALUE);
        System.out.println(Long.MIN_VALUE);

        System.out.println(Float.MAX_VALUE);
        System.out.println(Float.MIN_VALUE);

        System.out.println(Double.MAX_VALUE);
        System.out.println(Double.MIN_VALUE);

        System.out.println((int) Character.MIN_VALUE);
        System.out.println((int) Character.MAX_VALUE);
        System.out.println((char) 10084);
        char heart = '➤';
        System.out.println(heart);

        for(int i = 0; i < 128; i++) {
            System.out.println((char) i);
        }

    }
}

