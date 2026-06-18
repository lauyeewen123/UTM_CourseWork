package carpet;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter room length (in meters): ");
        double length = input.nextDouble();

        System.out.print("Enter room width (in meters): ");
        double width = input.nextDouble();

        System.out.print("Enter carpet price per square meter: RM ");
        double price = input.nextDouble();

        Room room = new Room(length, width);
        Carpet carpet = new Carpet(price);
        RoomCarpet roomCarpet = new RoomCarpet(room, carpet);

        System.out.println("\n=== Room Carpet Summary ===");
        System.out.println(roomCarpet.toString());

        Room anotherRoom = new Room(5, 4);
        System.out.println("\nIs this room equal to another room with the same size?");
        System.out.println(room.equals(anotherRoom));

        input.close();
    }
}