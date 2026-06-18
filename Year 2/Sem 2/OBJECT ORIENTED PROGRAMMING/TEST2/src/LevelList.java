//Total marks = 12 marks

//1M -> Menggunakan separate file bagi setiap class (simpan dalam LevelList.java)

public enum LevelList //1M -> enum LevelList
{
	//4M -> Define enum data type based on all cases listed in Table 1
	LEVEL1(8.0,"HIGH HAPPINESS"),
	LEVEL2(6.0,"MEDIUM HAPPINESS"),
	LEVEL3(4.0,"LOW HAPPINESS"),
	LEVEL4(1.0,"NOT HAPPY");

	private String status; //2M -> LevelList attributes
	private double index;

	//2M -> LevelList constructor - initializes LevelList attributes through parameter passing.
	private LevelList(double index, String status){
		this.index = index;
		this.status = status;
	}

	public double getIndex(){ //1M
		return index;
	}

	public String getStatus(){ //1M
		return status;
	}
}