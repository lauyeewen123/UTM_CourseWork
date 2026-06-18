package Labexercise;

public class Hospital {
    public static void main (String args[]) {
        // Create two Patient objects
        Patient p1 = new Patient("P001", "Ali", 120.5); 
        Patient p2 = new Patient("P002", "Siti", 80.0);

        // Display original details
        System.out.println("Original Details:");
        System.out.println(p1.toString());
        System.out.println(p2.toString());

        p1.updatePayment(150.0); //Update payment for the first patient

        p2.copyPaymentFrom(p1); // Copy payment from the first patient to the second patient

        // Display updated details
        System.out.println("\nAfter Changes:");
        System.out.println(p1.toString());
        System.out.println(p2.toString());
    }
}
