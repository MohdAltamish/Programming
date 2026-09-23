package com.programs.java.OOPS.Encapsulation;

public class Student {
    private String name;
    private int age;
    private long rollno;

    public Student(String name, int age, long rollno) {
        this.name = name;
        this.age = age;
        this.rollno = rollno;
    }

    public Student() {String name = "";
        this.name = name;
    }
    public Student(int age){
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public long getRollno() {
        return rollno;
    }
}
