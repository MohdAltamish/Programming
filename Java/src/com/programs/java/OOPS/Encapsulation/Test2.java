package com.programs.java.OOPS.Encapsulation;

public class Test2 {
    public static void main(String[] args) {

        Student student = new Student("Mohd Altamish", 18, 100077);
        System.out.println(student.getName());
        System.out.println(student.getAge());
        System.out.println(student.getRollno());

        Student student2 = new Student("Huamira", 17 , 100088);
        System.out.println(student2.getName());
        System.out.println(student2.getAge());
        System.out.println(student2.getRollno());
    }
}
