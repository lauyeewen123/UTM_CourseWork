import java.util.ArrayList;
import java.util.Scanner;

public class StaffSalary {

    static ArrayList <Staff> staffList = new ArrayList <>(); 

    static final int fulltimeBonus = 500; 

    public static void main(String[] args) {

        StaffSalary obj = new StaffSalary();
        obj.populateData();

        obj.calculateSalary(staffList); 
    }

    public void populateData() {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter number of staff: ");
        int total = input.nextInt(); 
        input.nextLine(); // Consume the newline character

        for (int i = 0; i < total; i++) {
            System.out.println("\nStaff #" + (i + 1) + ":");
            System.out.print("Enter Staff ID: ");
            String id = input.nextLine();

            System.out.print("Enter Name: ");
            String name = input.nextLine();


            System.out.print("Enter Staff Type (F/P): ");
            char type = input.nextLine().charAt(0);

            if (type == 'F') {
                System.out.print("Enter Basic Salary: ");
                double salary = input.nextDouble(); 
                input.nextLine(); // Consume the newline character

                Staff s = new Staff(id, name, salary, 0, 0, "FullTime"); 
                staffList.add(s);
            } else if (type == 'P') {
                System.out.print("Enter rate/hour: ");
                double rate = input.nextDouble(); 

                System.out.print("Enter total hours: ");
                int hrs = input.nextInt();
                input.nextLine(); // Consume the newline character

                Staff s = new Staff(id, name, 0, rate, hrs, "PartTime"); 
                staffList.add(s);
            }
        }
    }

    public void calculateSalary(ArrayList<Staff> list) { 
        for (int i = 0; i < list.size(); i++) {
            Staff ob = list.get(i); 
            Staff s = ob; 

            double salary = s.getSalary(); 
            display(s, salary);
        }
    }

    public void display(Staff s, double amount) {
        System.out.println("\nStaff ID: " + s.staffID);
        System.out.println("Name: " + s.name);
        System.out.println("Salary: " + amount);
    }
}

class Staff {
    String staffID;
    String name;
    double basicSalary;
    double ratePerHour;
    int totalHours;
    String type;

    public Staff(String id, String name, double salary, double rate, int hours, String t) {
        staffID = id;
        this.name = name;
        basicSalary = salary;
        ratePerHour = rate;
        totalHours = hours;
        type = t;
    }

    public double getSalary() { 
        if (type.equals("FullTime")) {
            return basicSalary + StaffSalary.fulltimeBonus; 
        } else if (type.equals("PartTime")) {
            return ratePerHour * totalHours;
        } else {
            return 0.0;
        }
    }
}
