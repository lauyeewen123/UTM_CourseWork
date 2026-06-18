/*
TEST 2 (PRACTICAL)
SUBJECT CODE    : SECJ2154
SUBJECT NAME    : OBJECT ORIENTED PROGRAMMING
YEAR/COURSE     : 2 (SECB/ SECJ/ SECP/ SECR/ SECV)
TIME            : 08:00 PM– 10:00 PM MYT (2 HOURS)
DATE            : 29th MAY 2024 (WEDNESDAY)

NAME            : LAU YEE WEN
MATRIC NO       : A23CS0099
YEAR/PROGRAM    : 2/SECPH
SECTION         : 2
LECTURER NAME   : Dr Zuriani
]Objective:
Refer Question Booklet.
*/

import java.util.ArrayList;

class Bank { //Total 15 marks for Bank class
  private String name;
  private Address address;
  private ArrayList<Account> accounts;

  public Bank(String name, Address address){
    this.name=name;
    this.address=address;
    this.accounts = new ArrayList<Account>();
  }

  public String getName() {return name;}
  public Address getdAdress(){return address;}

  public void addAccount(Account account){
    accounts.add(account);
  }

  public void removeAccount(Account account){
    accounts.remove(account);
  }

  public void printAllInfo(){
    System.out.println("\nBank :" + name);
    System.out.println("Address :" + address.getFullAddress());
    System.out.println("Number of Account(s) Registered: " + accounts.size());
    for (int i = 0; i < accounts.size(); i++) {
      System.out.println((i + 1) + ". Account #: " + accounts.get(i).getAccountNumber()
                         + ", Type: " + accounts.get(i).getType());
    }
  }
}

class Account { //Total 15 marks
    private String accountNumber;
    private String owner;
    private double balance;
    private String type;
    private ArrayList<Transaction>transactions;

    public Account(String accountNumber,String type){
        this.accountNumber=accountNumber;
        this.type=type;
        this.transactions = new ArrayList<Transaction>();

    }

    public void setOwner(String owner){
        this.owner=owner;
    }

    public String getAccountNumber(){return accountNumber;}
    public double getBalance(){return balance;}
    public String getType(){return type;}
    
    public void deposit(double amount){
        balance +=amount;
        transactions.add(new Transaction("Deposit", amount));
    }

    public void withdraw(double amount){
        if (balance > amount){
          balance-=amount;
          transactions.add(new Transaction("Withdraw", amount));
        }else{
          System.out.println("Insufficient balance for withdrawal.");
        }
    }

    public void printAllInfo(){
        System.out.println("\nAccount #: " + accountNumber);
        System.out.println("Owner: " + owner);
        System.out.println("Type: " + type);
        System.out.println("Balance: " + balance);
        System.out.println("Number of Transactions: " + transactions.size());
        for (int i = 0; i < transactions.size(); i++) {
            System.out.println((i + 1) + ". Type: " + transactions.get(i).getTransactionType() 
                               + ", Amount: " + transactions.get(i).getAmount());
        }
        
    }

}

class Customer { //Total 15 marks
    private String customerID;
    private String name;
    private Address address;
    private ArrayList<Account> accounts;

    public Customer(String customerID, String name, Address address){
      this.customerID = customerID;
      this.name = name;
      this.address = address;
      this.accounts = new ArrayList<Account>();
    }

    public String getCustomerID(){return customerID;}
    public String getName(){return name;}
    public Address getAddress(){return address;}

    public void addAccount(Account account, Bank bank){
      accounts.add(account);
      account.setOwner(name);
      bank.addAccount(account);
    }

    public void removeAccount(Account account, Bank bank){
      accounts.remove(account);
      bank.removeAccount(account);
    }

    public void printAllInfo(){
      System.out.println("\nCustomer Name:" + name);
      System.out.println("Customer ID:" + customerID);
      System.out.println("Address:" + address.getFullAddress());
      System.out.println("Number of Account(s) Registered:" + accounts.size());
      for ( int acc =0; acc<accounts.size();acc++) {
        System.out.println((acc + 1) + ". Account #: "  + accounts.get(acc).getAccountNumber() 
                           + ", Balance: " + accounts.get(acc).getBalance()
                           + ", Type: " + accounts.get(acc).getType());
      }
    }
}

class Address { //Total 5 marks
    private String roadname;
    private String city;
    private String state;
    private String country;

    public Address(String  roadname, String city, String state, String country){
      this.roadname=roadname;
      this.city=city;
      this.state=state;
      this.country=country;
    }
    
    public String getFullAddress(){
        return roadname + city + state + country;
    }
}

class Transaction { //Total 5 marks
    private String transactionType;
    private double amount;

    public Transaction(String transactionType, double amount){
      this.transactionType = transactionType;
      this.amount=amount;
    }

    public String getTransactionType(){
      return transactionType;
    }

    public double getAmount(){
      return amount;
    }
}

public class BankingSystem { //Total 15 marks
    public static void main(String[] args) {
        // Create TWO (2) address objects, 1 for bank and 1 for customer
        // 1 marks
        // 1 marks
        Address bankAddress = new Address ("Jalan Kebudayaan, ", "Skudai, ", "Johor, ", "Malaysia");
        Address customerAddress = new Address ("Jalan Pendidikan, ", "Skudai, ", "Johor, ", "Malaysia");

        // Create a bank object
        // 1 marks
        Bank newBank = new Bank("Beacon Bank", bankAddress);

        // Create a customer object
        // 1 marks
        Customer newCustomer = new Customer ("C001", "John Doe", customerAddress);

        // Create an account object and link it to the customer object
        // 1 marks
        Account customerAccount = new Account("A001" , "Savings");
        // 1 marks                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
        newCustomer.addAccount(customerAccount, newBank);
 
        // Create another account object and link it to the customer object
        // 1 marks
        Account anotherAccount = new Account("A002", "Current");
        // 1 marks
        newCustomer.addAccount(anotherAccount,newBank);

        // Deposit and withdraw from the first account
        // 1 marks
        customerAccount.deposit(1000);
        // 1 marks
        customerAccount.withdraw(200);
        
        // Deposit to the second account
        // 1 marks
        anotherAccount.deposit(2000);

        // Print info for bank, account 1 & 2, customer
        // 0.5 marks
        newBank.printAllInfo();
        // 0.5 marks
        customerAccount.printAllInfo();
        // 0.5 marks
        anotherAccount.printAllInfo();
        // 0.5 marks
        newCustomer.printAllInfo();
        // Remove account 2 from customer
        // 1 marks
        newCustomer.removeAccount(anotherAccount,newBank);

        // Print info for bank, customer
        // 0.5 marks
        newBank.printAllInfo();
        // 0.5 marks
        newCustomer.printAllInfo();
    }
}
