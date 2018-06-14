outlets = 2;

function bang()
{
	//initialising our key variable
	Key = "";
	
	//keys will be values between 1 and twelve - a = 1, g# = 12
	
	
	I = Math.floor((Math.random() * 12) + 1); 
	
	//code to print out key values for user
	switch(I)
	{
		case 1:
			Key = "A";
			break;
		case 2:
			Key = "A#";
			break;
		case 3:
			Key = "B";
			break;
		case 4:
			Key = "C";
			break;
		case 5:
			Key = "C#";
			break;
		case 6:
			Key = "D";
			break;
		case 7:
			Key = "D#";
			break;
		case 8:
			Key = "E";
			break;
		case 9:
			Key = "F";
			break;
		case 10:
			Key = "F#";
			break;
		case 11:
			Key = "G";
			break;
		case 12:
			Key = "G#";
			break;
	}
				
			
	
	
	//code to convert to midi number
	
	I += 48;
	
			
	outlet(0, I);
	outlet(1, Key);
	
}	
	
	
	
	