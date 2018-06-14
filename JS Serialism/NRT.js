/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

outlets = 2;

//Generation code:
//global random length
I = Math.floor((Math.random() * 40) + 15); 
function Generate_Key()
{
	
	//initialising our key variable
	Key = "";
	
	//keys will be values between 1 and twelve - a = 1, g# = 12
	R = Math.floor((Math.random() * 12) + 1); 
	
	//code to print out key values for user
	switch(R)
	{
		case 1:
			Key = "a";
			break;
		case 2:
			Key = "A";
			break;
		case 3:
			Key = "b";
			break;
		case 4:
			Key = "c";
			break;
		case 5:
			Key = "C";
			break;
		case 6:
			Key = "d";
			break;
		case 7:
			Key = "D";
			break;
		case 8:
			Key = "e";
			break;
		case 9:
			Key = "f";
			break;
		case 10:
			Key = "F";
			break;
		case 11:
			Key = "g";
			break;
		case 12:
			Key = "G";
			break;
	}
				
			
	return Key;
	
	//code to convert to midi number
	
	//I += 48;
	
	
}

//tonality function
function TONE()
{
	Tone = "";
	R = Math.floor((Math.random()*2) + 1)
	
	switch(R)
	{
		case 1: 
			Tone = "M"; // minor tone
			break;
		case 2:
			Tone = "m"; // major tone
			break;
		default:
			break;
	}
	return Tone;
}

//main generation function			
function Generate_List(I)
{	
	//generate a random number between 15 and 40
	
	//create a new array object for output
	
	var List_T = new Array(I);
	
	variations = "";	
	
	//generate our list of transformations
	for(i = 0; i < I; i++)
	{
		
		R = Math.floor((Math.random() * 4) + 1);
			
		switch(R)
		{
			case 1:
				variations = "P";
				break;
			case 2:
				variations = "R";
				break;
			case 3:
				variations = "L";
				break;
			default:
				break;
		}
		List_T[i] = variations;
	}
	return List_T;
	
}	


//translator code:
//this assigns each key a number for later use
//upeercase letters are Sharpened Keys - A = A#
function Num_Assign(K)
{
	//initialise our Num Value
	Num = 0;
	//numbers correlate with approprate midi number
	switch(K)
	{
		case "a":
			Num = 49;
			break;
		case "A":
			Num = 50;
			break;
		case "b":
			Num = 51;
			break;
		case "c":
			Num = 52;
			break;
		case "C":
			Num = 53;
			break;
		case "d":
			Num = 54;
			break;
		case "D":
			Num = 55;
			break;
		case "e":
			Num = 56;
			break;
		case "f":
			Num = 57;
			break;
		case "F":
			Num = 58;
			break;
		case "g":
			Num = 59;
			break;
		case "G":
			Num = 60;
			break;
		default:
			break;
	
	}
	return Num;				
	
}
	
//functions to process generated transformations
function Chord_Output(Key, Tone, Transform)
{
	//create and init output array;
	Chords = "";
	N = Num_Assign(Key);
	//modifier defenition
	Mod = 0;
	switch(Transform)
	{
		case "L":
			Mod = 4
			break;
		case "R":
			Mod = 9
			break;
		default:
			break;
	}
	

		//seperate out P from N and R
		if (Transform !== "P")
		{
			R = Math.floor((Math.random() * 3) + 1);
			//minor/major conditional
			if(Tone === "m")
			{
				switch(R)
				{
					case 1:
					//root of triad
						N += Mod;
						break;
					case 2:
					//third of triad
						N += Mod + 4;
						break;
					case 3:
					//fifth of triad
						N += Mod + 7
						break;
					default:
						break;
				}
			}
			else if(Tone === "M")
			{
				switch(R)
				{
					case 1:
					//root of triad
						N -= Mod;
						break;
					case 2:
					//third of triad
						N -= Mod + 3;
						break;
					case 3:
					//fifth of triad
						N -= Mod + 7
						break;
					default:
						break;
				}
			}
		}
		else
		{
			switch(R)
				{
					case 1:
					//root of triad
						N = N;
						break;
					case 2:
					//third of triad
						if(Tone === "m")
						{
							N += Mod + 3;
						}
						else if(Tone === "M")
						{
							N += Mod + 4;
						}
						break;
					case 3:
					//fifth of triad
						N += 7
						break;
					default:
						break;
				}
		
		}
		
		Chords = N;
			
	
	
	return Chords;
	
	
}
//set addition modifiers


function Generate_Chords(NRT, Key, Tone)
{
  var Chordarr = new Array(4)
	var Output = new Array(I * 4);
	counter = 0;
	c = 0;
	for(i = 0; i < I*4; i++)
	{
	  
	  Output[i] = Chord_Output(Key, Tone, NRT[counter]); 
	  
	  c += 1;
	  if(c >= 4)
	  {
		  counter += 1;
		  c = 0;
	  }
		
	}
	
	return Output;	
	
}

//main program function
function bang()
{
	//generate a key from random
	KEY = Generate_Key();
	Tonality = TONE();
		
	var RID =  Generate_List(I);
	var Chords = Generate_Chords(RID, Key, Tonality);


	outlet(0, Chords);
	outlet(1, I);
	
	

}
