//Total marks = 12 Marks

//1M - Menggunakan separate file bagi setiap class (simpan dalam Country.java)

public class Country //1M - Class declaration
{
	//2M - 4 attributes
	private String name, factor, status;
	private double index;
    static int count = 0;

	//4M - Initializes attributes through parameter passing
	public Country(String name, String factor, String status, double index){
		this.name = name;
		this.factor = factor;
		this.status = status;
		this.index = index;
		count++;
	}

	public String getName(){ //1M
		return name;
	}

	public String getFactor(){ //1M
		return factor;
	}

	public String getStatus(){ //1M
			return status;
	}

	public double getIndex(){ //1M
			return index;
	}
}