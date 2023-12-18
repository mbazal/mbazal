var coal;
var goldenTicket;
var item = coal;
var score = 0;
var scoreText;
var newItem;
function start(){
    topMessage();
    setTimer(changeItems, 700);
    mouseClickMethod(clickHandler);
    scoreText = new Text(score);
	scoreText.setPosition(0, getHeight());
	add(scoreText);
    
}
function topMessage(){
    displayMessage2("Tap on Golden Ticket to Win!");

}
function goldenTickets(){
    goldenTicket= new WebImage("https://codehs.com/uploads/8ee5bf2b8cb2432ee7965578b6e7d024");
    goldenTicket.setSize(150,80);
    var x = Randomizer.nextInt(0,350);
    var y = Randomizer.nextInt(0,350);
    goldenTicket.setPosition(x,y);
    add(goldenTicket);
    
    
}


function setupCoal(){
    coal= new WebImage("https://codehs.com/uploads/6feba02fe5290ae952b2421104dac52b");
    coal.setSize(80,80);
    var x = Randomizer.nextInt(0,350);
    var y = Randomizer.nextInt(0,350);
    coal.setPosition(x,y);
    add(coal);
     

}


function clickHandler(e){
	var elem = getElementAt(e.getX(), e.getY());
	if(elem != null && elem == goldenTicket){
		score++;
	}else{
		score--;
	}
	
	if(score == -1){
		displayMessage("You Lose, Try Again ;( ");
	    
	}
	if(score == 1){
		displayMessage("I won! ");
		
	
		
		
	}
	
	scoreText.setText(score);
}
function displayMessage(text){
	stopTimer(changeItems);
	var msg = new Text(text);
	msg.setPosition(getWidth()/2 - msg.getWidth()/2, 200);
	add(msg);
}
function displayMessage2(text){
	var msg = new Text(text);
	msg.setPosition(0, 30);
	add(msg);
}

function changeItems(){
 var random = Randomizer.nextInt(0,350);
 var done = remove(coal);
 var done2 = remove(goldenTicket);
 if(random < 250){
     setupCoal();
    done;
 }else{
     goldenTickets();
     done2;
    
 }
}