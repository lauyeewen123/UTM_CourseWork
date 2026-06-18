public class EnumTest1{
    enum Day {SUNDAY, MONDAY, TUESDAY, WEDNESDAY,
    THURSDAY, FRIDAY, SATURDAY}
    
    public static void main(String[] args){
    Day workday;
    workday = Day.THURSDAY;
    System.out.println ("Today is "+ workday);
    System.out.println ("Yesterday was " + Day.WEDNESDAY);
    
    System.out.println ("Ordinal value: " + workday.ordinal());
    Day days1 = Day.SUNDAY;
    System.out.println ("Ordinal value: " + days1.ordinal());
    
    Day myDay = Day.FRIDAY;
    if (myDay.equals(workday))
        System.out.println ("same day ");
    else
        System.out.println ("different day ");

    

    for (Day day : Day.values()) {
        System.out.printf( "%s ", day);
        
    }
    for (Day d : Day.values()) { 
        System.out.printf("Day: %s, Ordinal: %d%n", d, d.ordinal()); 
    }
    }
}