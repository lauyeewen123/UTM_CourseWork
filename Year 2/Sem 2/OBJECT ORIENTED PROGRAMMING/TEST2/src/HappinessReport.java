//Total marks = 36 marks

import java.io.*;
import java.util.Scanner;
import java.util.Vector; //2M - Import appropriate Package

public class HappinessReport
{
	public static void main(String[] args) throws IOException{

		//2M -> Open file (Scanner in = new Scanner())
		Scanner inp = new Scanner(new FileReader("InputSA.txt"));

		//2M -> Identify the suitable variables, instance and vector declaration where appropriate.
		String level, name, factor;
		double index;
		int totalHH = 0, totalMH = 0, totalLH = 0, totalNH = 0;
		Vector <Country> countryList = new Vector <Country>();

		System.out.println("Category of Happiness");

		//3M -> Print all levels in the LevelList enum class to produce the output as in Figure 2.
		for (LevelList lev : LevelList.values())
		{  System.out.println(lev + ":  " + lev.getIndex() + "\t" + lev.getStatus());}

		while (inp.hasNext()){
			//3M -> Read an input file with a list of name, factor and Country’s Level.
			level = inp.next().toUpperCase();
			name = inp.next();
			factor = inp.nextLine();

			//2M -> Convert string to LevelList (enum) object
			LevelList list = Enum.valueOf(LevelList.class, level);

			//3M -> Create a vector of objects from class Country to store the value read from file
			Country country = new Country(name, factor, list.getStatus(), list.getIndex());

            //2M -> Add Country to vector
            countryList.addElement(country);

			//5M -> Count how many cases for High, Medium, Low and Not Happy.
			//(Use enum value to count the different cases - IF/Switch).
			switch (list){ //1
				case LEVEL1: totalHH++; break; //1
				case LEVEL2: totalMH++; break; //1
				case LEVEL3: totalLH++; break; //1
				default: totalNH++; //1
			} // end switch
		} // end while


		System.out.println("\n\n\t\tCOUNTRY INDEX HAPPINEST REPORT");
		System.out.printf("%-7s%-14s%-13s%-7s%s\n", "Country", "Factor", "Name", "Index", "Category");

		//3M -> Print Country values and use appropriate method for arraylist/vector
		int i = 0;
		for (Country c: countryList) {
			System.out.printf("%-6d%-15s%-13s%-7.1f%s\n", (++i),
								c.getFactor(), c.getName(),
								c.getIndex(), c.getStatus());
		} // end loop

		//3M -> Print number of levels for High, Medium, Low and Not Happy
		System.out.println("\nTotal in HIGH HAPPINESS   = " + totalHH);
		System.out.println("Total in MEDIUM HAPPINESS = " + totalMH);
		System.out.println("Total in LOW HAPPINESS    = " + totalLH);
		System.out.println("Total in NOT HAPPY        = " + totalNH);

		//2M -> Count the number of all levels. Pls refer statements @ Line 10 & 18, in Country.java
		//(You may use static variable to count the total cases)
		System.out.println("Total Countries = " + Country.count); //1M

		//3M -> Use appropriate output formatting

		inp.close();
	}
}