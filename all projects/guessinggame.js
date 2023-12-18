var arr = [];
var roll= Randomizer.nextInt(1,100);

/*this shows the user guessing numbers and when its less it displays number is too low and when its more
 it says too high and when its correct the display text appears. The orginal push command takes the 
 random generated number and pushes it to the array.
 */
function start(){
    while(true){
        var number = readInt("Guess the random number ");
        arr.push(number);
        
        if(number>roll){
            println("Number is too high");
        }
        
        if(number<roll){
            println("Number is too low");
        }
        
        if(number==roll){
            println("You guessed the secret number!");
            break;
        }
    }
    theEnd();
}
// the list that saves the tries and the random number 
function theEnd(){
    for(var i = 0; i < arr.length; i++){
    var cur = arr[i];
    println(cur);
    }

//adds a blue congradulations text right above the "you guessed the secret number!" in arial font

var txt = new Text("Congratulations!", "30pt Arial");
txt.setPosition(getWidth()/2 - txt.getWidth()/2, 200);
txt.setColor(Color.blue);
add(txt);

//prints the text "You guessed the secret number!" in green color and arial font
var txt = new Text("You guessed the secret number!", "20pt Arial");
txt.setPosition(getWidth()/2 - txt.getWidth()/2, 250);
txt.setColor(Color.green);
add(txt);
    
//prints out the number random number you had to guess
    
var txt = new Text(cur, "20pt Arial");
txt.setPosition(getWidth()/2, 300);
txt.setColor(Color.purple);
add(txt);
    
//prints out the total amount of tries it took you
var txt = new Text("It took you " + arr.length  + " tries", "20pt Arial");
txt.setPosition(getWidth()/2 - txt.getWidth()/2, 350);
txt.setColor(Color.green);
add(txt);
   
//display guesses
var guesstxt = new Text("Guesses: ", "20pt Arial");
guesstxt.setPosition(20, 400);
guesstxt.setColor(Color.purple);
add(guesstxt);
   
var xpos = guesstxt.getWidth() + 30;
var ypos = 400;
   
    for (i = 0; i < arr.length; i ++){
        //prints all the numbers that you entered
        var txt = new Text(arr[i] + " ", "10pt Arial");
        // example for above fill in: guessList[i]
        txt.setPosition(xpos, ypos);
        txt.setColor(Color.purple);
        add(txt);
   
        xpos += txt.getWidth() + 2 ;
        if (xpos > getWidth() - txt.getWidth() ){
        ypos += 30 ;
        xpos = guesstxt.getWidth() + 30;
        }
     }

}