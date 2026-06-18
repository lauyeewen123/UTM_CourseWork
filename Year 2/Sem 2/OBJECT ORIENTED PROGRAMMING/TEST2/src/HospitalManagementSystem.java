//Refer class 22th May - incomplete.pdf for UML class diagram

import java.util.ArrayList;

class Name {
    
    private String firstName;
    private String lastName;

    public Name(String firstName, String lastName) {
        this.firstName = firstName;
        this.lastName = lastName;
    }
    public String getFullName() {
        return firstName+ " " + lastName;
    }

}

class Address {
    private String street;
    private String city;
    private String postcode;

    public Address(String street, String city, String postcode) {
        this.street = street;
        this.city = city;
        this.postcode = postcode;
    }
    public String getFullAddress() {
        return street + ", " + city + ", " + postcode;
    }
}


class Patient {
    private Name name;
    private Address address;

    public Patient (String firstName, String lastName, Address address) {
        this.name = new Name(firstName, lastName);
        this.address = address;
    }

    public void display() {
        System.out.println("Patient Name: " + name.getFullName());
        System.out.println("Address: " + address.getFullAddress());
    }

}

class Hospital {
    private String name;
    private ArrayList<Patient> patients;

    public Hospital(String name) {
        this.name = name;
        this.patients = new ArrayList <Patient> ();
    }

    public void addPatient(Patient p) {
        patients.add(p);
    }

    public void displayInfo() {
        System.out.println("Hospital Name: " + name);
        System.out.println("Patients List:");
        for (Patient p : patients) {
            p.display();
            System.out.println("-------------------");
        }
    }
}

// Main class
public class HospitalManagementSystem {
    public static void main(String[] args) {
        
        // Create Address objects 
        Address address1 = new Address("Jalan Teman 1", "Melaka", "77000");
        // Create Patient objects 
        Patient patient1 = new Patient ("Lau", "Yee Wen", address1 );
        // Create Hospital object
        Hospital hospital1 = new Hospital("Melaka General Hospital");

        // Association: Add patients to hospital
        hospital1.addPatient(patient1);
        hospital1.addPatient(new Patient("Tan", "Seng", new Address("Jalan Teman 2", "Melaka", "77000")));


        // Output
        hospital1.displayInfo();


    }
}

