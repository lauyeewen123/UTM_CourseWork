package carpet;

public class Room {
    private double length;
    private double width;

    public Room(double length, double width) {
        this.length = length;
        this.width = width;
    }

    public double getArea() {
        return length * width;
    }

    @Override
    public String toString() {
        return "Room [Length = " + length + ", Width = " + width + ", Area = " + getArea() + " sq. meters]";
    }

    public boolean equals(Room otherRoom) {
        return this.getArea() == otherRoom.getArea();
    }
}

