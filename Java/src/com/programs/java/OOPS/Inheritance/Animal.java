package com.programs.java.OOPS.Inheritance;

public class Animal {

    private String name;
    private int age;

    public void eats(){
        System.out.println("This animal eats food!");
    }

    public void greet(){
        System.out.println();
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }
}
