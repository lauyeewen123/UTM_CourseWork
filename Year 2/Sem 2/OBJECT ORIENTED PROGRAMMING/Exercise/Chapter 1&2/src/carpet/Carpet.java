package carpet;

public class Carpet {
    private double pricePerSqMeter;

    public Carpet(double price) {
        this.pricePerSqMeter = price;
    }

    public double getPrice() {
        return pricePerSqMeter;
    }

    @Override
    public String toString() {
        return "Carpet [Price per square meter = RM " + pricePerSqMeter + "]";
    }
}

