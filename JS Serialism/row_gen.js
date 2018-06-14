outlets = 1;
inlets = 1;


function bang()
{
	


//simple code to generate 12 different numbers between 1 and 12
//initalisation of variables
var Row = [];
I = 0;
//bools to ensure check whether a number has been used or not
Counter = 0;
one = false;
two = false;
three = false;
four = false;
five = false;
six = false;
seven = false;
eight = false;
nine = false;
ten = false;
eleven = false;
twelve = false;

function Generate (){
  var List = new Array(12);
  
  
  //now we need to ensure that each number is only used once
  while(Counter < 12)
  {
    
   I = Math.floor((Math.random() * 12) + 1); 
    switch(I)
    {
      case 1:
        if(one === false)
        {
          List[Counter] = I;
          one  = true;
          Counter += 1
        }
        
        break;
      case 2:
        if(two === false)
        {
          List[Counter] = I;
          two = true;
          Counter += 1
          
        }
        break;
        case 3:
        if(three === false)
        {
          List[Counter] = I;
          three = true;
          Counter += 1
        }
        break;
        case 4:
        if(four === false)
        {
          List[Counter] = I;
          four = true;
          Counter += 1
        }
        break;
        case 5:
        if(five === false)
        {
          List[Counter] = I;
          five = true;
          Counter += 1
        }
        break;
        case 6:
        if(six === false)
        {
          List[Counter] = I;
          six = true;
          Counter += 1
        }
        break;
        case 7:
        if(seven === false)
        {
          List[Counter] = I;
          seven = true;
          Counter += 1
        }
        break;
        case 8:
        if(eight === false)
        {
          List[Counter] = I;
          eight = true;
          Counter += 1
          
        }
        break;
        case 9:
        if(nine === false)
        {
          List[Counter] = I;
          nine = true;
          Counter += 1
          
        }
        break;
        case 10:
        if(ten === false)
        {
          List[Counter] = I;
          ten = true;
          Counter += 1
          
        }
        break;
        case 11:
        if(eleven === false)
        {
          List[Counter] = I;
          eleven = true;
          Counter += 1
          
        }
        break;
        case 12:
        if(twelve === false)
        {
          List[Counter] = I;
          twelve = true;
          Counter += 1
          
        }
        break;
        default: 
          break;
    }
    
    
 
  }
  
  return List

}

Row = Generate();


outlet(0,Row);
post(Row);
post();


}
	
	

	
