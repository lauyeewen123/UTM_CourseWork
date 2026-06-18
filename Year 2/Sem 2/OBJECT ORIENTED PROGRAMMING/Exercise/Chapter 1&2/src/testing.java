class Analyze1{
    static final int MAXVALUE = 100;
    final static double pi = 3.14159;

    public static void main(String[] args) {
        int number1 = 10;
        double myDouble = 20.5;
        
        int a = 5;
        int b = a++;
        int c = --b;

        int smallNumber = 100;
        double largeNumber = smallNumber;
        int convertedValue = (int) largeNumber; // Explicit casting
        
        String name = "Sarah";
        String anotherName = new String("Sarah");

        if (name.equals(anotherName)) {
            System.out.println("Names are equal");
        } else {
            System.out.println("Names are not equal");
        }
        
        final int FinalVariable = 50;
        
        System.out.println("Value: " + FinalVariable);
    }
}