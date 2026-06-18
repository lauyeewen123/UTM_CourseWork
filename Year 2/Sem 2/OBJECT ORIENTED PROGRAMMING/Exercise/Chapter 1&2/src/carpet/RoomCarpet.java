package carpet;

public class RoomCarpet {
    private Room room;
    private Carpet carpet;

    public RoomCarpet(Room room, Carpet carpet) {
        this.room = room;
        this.carpet = carpet;
    }

    public double getTotalCost() {
        return room.getArea() * carpet.getPrice();
    }

    @Override
    public String toString() {
        return room.toString() + "\n" + carpet.toString() + "\nTotal Carpet Cost = RM " + getTotalCost();
    }
}
