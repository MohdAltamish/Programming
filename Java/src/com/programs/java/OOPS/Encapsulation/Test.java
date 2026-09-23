package com.programs.java.OOPS.Encapsulation;

public class Test {

    public static void main(String[] args) {
        BankAccount ac = new BankAccount();

        ac.setAccountName("Mohd Altamish");
        ac.setAccountNumber(908415);

        ac.deposit(10000);
        ac.deposit(20000);
        ac.withdraw(2500);

       ac.AccInfo();
    }
}
