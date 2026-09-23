package com.programs.java.OOPS.Encapsulation;

public class BankAccount {

    private long accountNumber;
    private String accountName;
    private double balance;

    public void AccInfo() {
        System.out.println("Account Number: " + this.accountNumber);
        System.out.println("Account Name: " + this.accountName);
        System.out.println("Account Balance: " + this.balance);
    }

   public void deposit(double amount) {
       if (amount > 0) {
           this.balance += amount;
           System.out.println("Deposited " + amount);
       }
       else  {
           System.out.println("Invalid amount");
       }
   }

   public void withdraw(double amount) {
       if (amount > 0) {
           this.balance -= amount;
           System.out.println("Withdrawn " + amount);
       }
       else  {
           System.out.println("Invalid amount");
       }
   }

    public void setAccountNumber(long accountNumber) {
        this.accountNumber = accountNumber;
    }


    public void setAccountName(String accountName) {
        this.accountName = accountName;
    }



}
