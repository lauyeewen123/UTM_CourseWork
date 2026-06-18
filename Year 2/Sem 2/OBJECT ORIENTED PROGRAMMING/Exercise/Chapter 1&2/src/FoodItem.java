public class FoodItem {
    private String description;
    private double size;
    private double price;

    public FoodItem(String desc, double aSize, double aPrice) {
        description = desc;
        size = aSize;
        price = aPrice;
    }

    public void setSize(double aSize){
        size = aSize;
    }

    public void setPrice(double aPrice){
        price = aPrice;
    }
    public String getDesc(){
        return description;
    }

    public double getSize(){
        return size;
    }
    public double getPrice(){
        return price;
    }
    public String toString(){
        return description + " , size : " + size + ", price $" +  price;
    }

    public double calcUnitPrice(){
        return price / size;
    }
}

class Main {
    public static void main(String[] args) {
        FoodItem item1 = new FoodItem("Snickers", 6.5, 0.55);
        FoodItem item2 = new FoodItem("Progresso Minestrone", 16.5, 2.35);

        System.out.println(item1.toString());
        System.out.println("Unit price of " + item1.getDesc() + " is $" + item1.calcUnitPrice()); 
        System.out.println("\n");    

        System.out.println(item2.toString());
        System.out.println("Unit price of " + item2.getDesc() + " is $" + item2.calcUnitPrice());
    }
}

