outlets = 3;

function bang()
{
	//generate a random number between 15 and 40
	//this is our number of transformations.
	I = Math.floor((Math.random() * 40) + 15); 
	
	//initialisation of our output lists
	var list_p = new Array(I);
	var list_t = new Array(I);
	Variations = "";
	
	
	for(i = 0; i < I ; i ++)
	{
		//below will assign our list one of 42 values
		//eg: RI_3 would be a Retrograde Inversion of Key + 3
		Choice = Math.floor((Math.random() * 4) + 1); 
		
		//this will create 1 of 4, Prime, Retrograde, Inv and RI
		switch(Choice)
		{
			case 1:
				Variations = "P";
				break;
			case 2:
				Variations = "R";
				break;
			case 3:
				Variations = "I";
				break;
			case 4:
				Variations = "RI";
				break;
			default:
				break;
				
		}
		
		//this will choose transposition.
		
		Transpose = Math.floor((Math.random() * 12) + 1); 
		
		list_p[i] = Variations;
		list_t[i] = Transpose;
		
		
		 
		
		
	}
	
	
	
		
	
	
	
	
	
	
	//sends out our number of variations for further use
	outlet(0, I);
	outlet(1, list_p);
	outlet(2, list_t);
	
	
	
}
	