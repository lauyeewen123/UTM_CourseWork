import java.util.*;

interface TaxDiscCalculable {
    public static final double TAX_RATE = 0.1;
    public static final double DISC_RATE = 0.2;

    public abstract double calcTax(double amount);
    public abstract double calcDisc(double amount);
}

abstract class Trip implements TaxDiscCalculable {
    private double distance;
    private Vector<Passenger> pList;

    public Trip(double distance) {
        this.distance = distance;
        pList = new Vector<>();
    }

    public double getDistance() {
        return distance;
    }

    public Vector<Passenger> getPassengers() {
        return pList;
    }

    public void addPassenger(Passenger p) {
        pList.add(p);
    }

    public double calcTax(double amount) {
        return amount * TAX_RATE;
    }

    public double calcDisc(double amount) {
        return amount * DISC_RATE;
    }

    public abstract double calcFare();

    public double calcTotalFare() {
        return calcFare() * pList.size();
    }

    public double calcTotalFareWithTax() {
        double totalFare = calcTotalFare();
        return totalFare + calcTax(totalFare);
    }

    public double calcTotalFareWithDisc() {
        double totalFare = calcTotalFare();
        return totalFare - calcDisc(totalFare);
    }
}

class LocalTrip extends Trip {
    public LocalTrip(double distance) {
        super(distance);
    }

    public double calcFare() {
        return getDistance() * 2.00;
    }
}

class LongDistanceTrip extends Trip {
    public LongDistanceTrip(double distance) {
        super(distance);
    }

    public double calcFare() {
        return getDistance() * 1.50;
    }
}

class Passenger {
    private String name;
    public Passenger(String name) {
        this.name = name;
    }
    public String getName() {
        return name;
    }
}

public class TripApp {
    public static void main(String[] args) {
        Vector<Passenger> list;

        Trip trip1 = new LocalTrip(10.5);
        Trip trip2 = new LongDistanceTrip(50.0);

        trip1.addPassenger(new Passenger("Alwi Ahmad"));
        trip1.addPassenger(new Passenger("Ahmad Shariff"));
        trip1.addPassenger(new Passenger("Rabiah Hakim"));

        System.out.println("Information for Local Trip");
        System.out.println("List of passengers:");
        list = trip1.getPassengers();
        for (int i = 0; i < list.size(); i++)
            System.out.println((i + 1) + ") " + list.get(i).getName());

        System.out.printf("\nTotal Fare: RM%.2f\n", trip1.calcTotalFare());
        System.out.printf("Total Fare with Tax: RM%.2f\n", trip1.calcTotalFareWithTax());
        System.out.printf("Total Fare with Discount: RM%.2f\n", trip1.calcTotalFareWithDisc());

        trip2.addPassenger(new Passenger("Halimah Abu"));
        trip2.addPassenger(new Passenger("Rafidah Harun"));

        System.out.println("\n\nInformation for Long-Distance Trip");
        System.out.println("List of passengers:");
        list = trip2.getPassengers();
        for (int i = 0; i < list.size(); i++)
            System.out.println((i + 1) + ") " + list.get(i).getName());

        System.out.printf("\nTotal Fare: RM%.2f\n", trip2.calcTotalFare());
        System.out.printf("Total Fare with Tax: RM%.2f\n", trip2.calcTotalFareWithTax());
        System.out.printf("Total Fare with Discount: RM%.2f\n", trip2.calcTotalFareWithDisc());
    }
}
