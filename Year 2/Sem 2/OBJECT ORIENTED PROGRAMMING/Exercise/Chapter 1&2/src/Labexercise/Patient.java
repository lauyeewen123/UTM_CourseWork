package Labexercise;

public class Patient {
    private String name;
    private String id;
    private double paymentAmount;

    // Constructor
    public Patient(String i, String n, double p) {
        id = i;
        name = n;
        paymentAmount = p;
    }

    //Update payment amount
    public void updatePayment (double newAmount) {
        paymentAmount = newAmount;
    }
    //Copy payment amount
    public void copyPaymentFrom(Patient otherPatient){
        this.paymentAmount = otherPatient.paymentAmount;
    }
    @Override
    public String toString() {
        return "Patient ID: " + id + ", Name: " + name + ", Payment : RM " + paymentAmount;
    }
}
