//TEST2_1819
import javax.swing.JOptionPane;
import java.util.Date;

class Account {
	private int id;
	private double balance;
	private static double annualInterestRate;
	private Date dateCreated;

	Account() {
		id = 0;
		balance = 0;
		annualInterestRate = 0;
		dateCreated = new Date();
	}

	Account(int newId, double newBalance) {
		id = newId;
		balance = newBalance;
		dateCreated = new Date();
	}

	public void setId(int newId) {
		id = newId;
	}

	public void setBalance(double newBalance) {
		balance = newBalance;
	}

	public void setAnnualInterestRate(double newAnnualInterestRate) {
		annualInterestRate = newAnnualInterestRate;
	}

	public int getId() {
		return id;
	}

	public double getBalance() {
		return balance;
	}

	public double getAnnualInterestRate() {
		return annualInterestRate;
	}

	public String getDateCreated() {
		return dateCreated.toString();
	}

	public double getMonthlyInterestRate() {
		return annualInterestRate / 12 / 100;
	}

	public double getMonthlyInterest() {
		return balance * getMonthlyInterestRate();
	}

	public void withdraw(double amount) {
		balance -= amount;
	}

	public void deposit(double amount) {
		balance += amount;
	}
}

public class BankAccount {
	public static void main(String [] args)
	{
		String wDraw;
    	double w;

		Account account1 = new Account(1112,20000);
		account1.setAnnualInterestRate(4.5);
		wDraw = JOptionPane.showInputDialog("Amount to withdraw (MYR)");
		w = Double.parseDouble(wDraw);
		account1.withdraw(w);
		account1.deposit(3000);

        System.out.println("------------------------------------------");
		System.out.println("\n          Account Statement");
		System.out.println("------------------------------------------");
		System.out.println("Account ID: " + account1.getId());
		System.out.println("Date created: " + account1.getDateCreated());
		System.out.printf("Balance: MYR%.2f\n", account1.getBalance());
		System.out.printf("Monthly interest: MYR%.2f\n", account1.getMonthlyInterest());
        System.out.println("------------------------------------------");

        Account account2 = new Account(1114,5000);
		account2.setAnnualInterestRate(4.5);
		account2.withdraw(250);
		account2.deposit(300);

        System.out.println("------------------------------------------");
		System.out.println("\n          Account Statement");
		System.out.println("------------------------------------------");
		System.out.println("Account ID: " + account2.getId());
		System.out.println("Date created: " + account2.getDateCreated());
		System.out.printf("Balance: MYR%.2f\n" , account2.getBalance());
		System.out.printf("Monthly interest: MYR%.2f\n" , account2.getMonthlyInterest());
        System.out.println("------------------------------------------");
    }
}
