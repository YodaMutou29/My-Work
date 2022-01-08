/**
 * title: Control.java
 * description: This class contains the majority of the 
 * methods for the Locations class to use.
 * date: January 23, 2021
 * @author Jenna McDonnell
 * @version 1.0
 * 3435506
 */
/************************************************************
 * METHODS
 ************************************************************
 * <H3> Methods <H3>
 *
 * <P>
 * public void bankIntro(String text){<BR>
 	Introduces the river bank scene.

 * public void climbDownTree(String text){<BR>
 	Outputs text and tests for answers after climbing 
 	down the tree.

 * public void climbHigher(String text){<BR>
 	Outputs text and tests for answers after climbing 
 	higher up the tree.

 * public void investigateRedObject(String text, String text2){<BR>
 	Outputs text, adds a heart to inventory and tests for answers 
 	after gaining the heart.

 * public void goToRiver(String text){<BR>
 	Outputs text and tests for answers at the river.

 * public void openChest(String text){<BR>
 	Outputs text and tests for answers after trying to open 
	the chest in the river.

 * public void backToSister(String text){<BR>
 	Outputs text and tests for answers while standing beside
	sister.

 * public void lookAtBook(String text){<BR>
 	Outputs text and tests for answer while looking at 
	sister's book.

 * public void classChosen(String text){<BR>
 	Outputs text and waits for user to type "adventure".

 * public void rabbitIntro(String text){<BR>
 	Outputs text for the rabbit hole introduction and 
	tests for answer.

 * public void lookAroundBush(String text){<BR>
 	Outputs text and tests for answer when looking around the 
	bush above the rabbit hole.

 * public void pickUpMetal(String text){<BR>
 	Outputs text and tests for answer on what the user wants 
	to do after finding the piece of metal.

 * public void crawlInHole(String text){<BR>
 	Outputs text and tests for answer after the player crawls into 
	the rabbit hole.

 * public void lookForMoreBushItems(String text){<BR>
 	Outputs text and tests for answer after player chooses to look for 
	more items around the bush that is above the rabbit hole.

 * public void takeItem(String text){<BR>
 	Outputs text and tests for answer of which item the player 
	wants to take while falling down the rabbit hole.

 * public String openBag(String answer){<BR>
 	Opens bag and tests for player's answer on what they 
	want to do with the item they chose to use in their bag.

 * public void lookAroundHole(String text){<BR>
 	Outputs text and tests for answer on what the player wants 
	to do after looking around the rabbit hole for items.

 * public void pickItem(String text){<BR>
 	Outputs text and tests for answer on what the player wants 
	to do after taking an item in the rabbit hole.

 * public void dropCandlestick(String text){<BR>
 	Outputs text and tests for what player wants to do after 
	dropping the candlestick.

 * public void letGoAxe(String text){<BR>
 	Outputs text and tests for answer on what the 
	player wants to do after letting go of the axe.

 * public void swingAxe(String text){<BR>
 	Outputs text and tests for answer on what the user wants 
	to do after swinging the axe.

 * public void afterBatFight(String text){<BR>
 	Outputs text after the bat fight.

 * public void hallwayIntro(String text){<BR>
 	Outputs text and tests for answer on what the player 
	wants to do upon entering the hallway.

 * public void tryDoor(String text){<BR>
 	Outputs text and tests for answer on what the player wants to 
	do after trying to open one of the doors.

 * public void table1(String text){<BR>
 	Outputs text and tests for answer if the player has already 
	examined table 1.

 * public void table2(String text){<BR>
 	Outputs text and tests for answer if player has already examined 
	table 2.

 * public void table3(String text1, String text2){<BR>
 	Outputs text and tests for answer if player has already examined 
	table 3.

 * public void foundPotion(String text){<BR>
 	Outputs text, adds potion to inventory, and tests for answer 
	on what the player wants to do after finding the potion.

 * public void foundKey(String text){<BR>
 	Outputs text and tests for answer on what the player wants to 
	do after finding the key.

 * public void foundTableHeart(String text1, String text2){<BR>
 	Outputs text and tests for answer on what the player wants 
	to do after finding the extra heart on one of the tables in the 
	hallway.

 * public boolean usePotion(){<BR>
 	Uses potion after testing to make sure it is in the 
	player's inventory and shrinks Alice if she is normal sized or 
	grows her if she is shrunk.

 * public void smallDoor(String text){<BR>
 	Outputs text and gets an answer after Alice tries to 
	go through the small door.

 * public void hallwayEnding(String text){<BR>
 	Outputs text to end the hallway scene.

 * public void forestIntro(String text){<BR>
 	Outputs text to introduce the forest scene and tests 
	for answer on which direction the player wants to go.

 * public boolean race(String text1, String text2){<BR>
 	Implements the race mechanics and explains the rules 
	to the player. Creates five random numbers from 1 to 
	10 and uses them to output three different equations for 
	the user to answer. If the user answers all three correctly,
	they win the game and gain a heart.

 * public void cheshireCat(String text1){<BR>
 	Implements the interaction with the Cheshire Cat. Tests 
	to see if piece of metal is in inventory and gives player 
	the chance to tell the truth and gain 2 hearts or lie and 
	lose 1 heart. If the player does not have the piece of metal,
	they can't do anything here.

 * public void castleIntro(String text){<BR>
 	Outputs text to introduce the castle scene and 
	tests for answer on whether the player agrees to 
	play the Queen's game or not.

 * public boolean queenGame(String text1, String text2){<BR>
 	Outputs text and implements the game of croquet 
	with the Queen. Player gains points by guessing 
	which number the computer chose, either 1 or 2, 
	gaining a point if they guess correctly. If they guess
	incorrectly, the player loses half a heart. The 
	game is over if the player gains 3 points or runs 
	out of hearts.

 * public void defaultOutput(){<BR>
 	Outputs a default text if the user does not input an acceptable 
	answer and tests for their next answer.

 * public void getAnswer(){<BR>
 	Gets the user's answer using the input Scanner and 
	converts the answer to lower case.

 * public String testForMultipleAnswers(String answer, String output,
	String option1, String option2, String option3){<BR>
		Tests answer to see which acceptable answer the user was 
		trying to input.
 * </P>
 */

/************************************************************
 * VARIABLES
 ************************************************************
 * <H3> Variables Used </H3>
 *
 * <P>
 *	public String answer; - the answer the user inputs
 *
 *	public Scanner input = new Scanner(System.in); - 
 *	the Scanner being used to retrieve the user's input
 *
 *	Inventory invent = new Inventory(); - creates an inventory 
 *	object to store items
 * 
 *	String clas; - stores the class of the character chosen
 * 
 *	boolean table1 = false; - true if table 1 has already 
 *	been examined
 *
 *	boolean table2 = false; - true if table 2 has already 
 *	been examined
 *
 *	boolean table3 = false; - true if table 3 has already 
 *	been examined
 * 
 *	Boolean shrunk = false; - true when Alice is in a shrunken 
 *	state after drinking the potion
 *
 *	int points = 0; - number of points player has in the 
 *	croquet game
 * </P>
 */
import java.util.*;
import java.io.*;

public class Control{

	//the answer the user inputs
	public String answer;

	//the Scanner being used to retrieve the user's input
	public Scanner input = new Scanner(System.in);

	//creates an inventory object to store items
	Inventory invent = new Inventory();

	/*
	* Introduces the river bank scene.
	* 
	* @param String text 		the text being output
	*/
	public void bankIntro(String text){
		System.out.println(text);
		getAnswer();
		answer = testForMultipleAnswers(answer, "climb down tree",
			"a", "climb down", "go down");
		answer = testForMultipleAnswers(answer, "climb higher",
			"b", "climb up", "go up");
	}

	/*
	* Outputs text and tests for answers after climbing down the tree.
	* 
	* @param String text 		the text being output
	*/
	public void climbDownTree(String text){
		System.out.println(text);
		getAnswer();
		answer = testForMultipleAnswers(answer, "go to the river",
			"a", "go to river", "river");
		answer = testForMultipleAnswers(answer, "look at sister's book",
			"b", "look at book", "book");
	}

	/*
	* Outputs text and tests for answers after climbing higher up the tree.
	* 
	* @param String text 		the text being output
	*/
	public void climbHigher(String text){
		System.out.println(text);
		getAnswer();
		answer = testForMultipleAnswers(answer, "investigate the red object",
			"a", "red object", "investigate");
		answer = testForMultipleAnswers(answer, "climb down",
			"b", "down", "go down");
	}

	/*
	* Outputs text, adds a heart to inventory and tests for answers after gaining 
	* the heart.
	* 
	* @param String text 		the first text being output
	* @param String text2  		the second text being output
	*/
	public void investigateRedObject(String text, String text2){
		System.out.println(text);
		invent.heartMeter(1);
		System.out.println(text2);
		getAnswer();
		answer = testForMultipleAnswers(answer, "go to the river",
			"a", "go to river", "river");
		answer = testForMultipleAnswers(answer, "look at sister's book",
			"b", "look at book", "book");
	}

	/*
	* Outputs text and tests for answers at the river.
	* 
	* @param String text 		the text being output
	*/
	public void goToRiver(String text){
		System.out.println(text);
		getAnswer();
		answer = testForMultipleAnswers(answer, "open the chest",
			"a", "open chest", "open");
		answer = testForMultipleAnswers(answer, "go back to sister",
			"b", "back to sister", "go back");
	}

	/*
	* Outputs text and tests for answers after trying to open 
	* the chest in the river.
	* 
	* @param String text 		the text being output
	*/
	public void openChest(String text){
		System.out.println(text);
		getAnswer();
		answer = testForMultipleAnswers(answer, "open the chest",
			"a", "open chest", "open");
		answer = testForMultipleAnswers(answer, "go back to sister",
			"b", "back to sister", "go back");
	}

	/*
	* Outputs text and tests for answers while standing beside
	* sister.
	* 
	* @param String text 		the text being output
	*/
	public void backToSister(String text){
		System.out.println(text);
		getAnswer();
		answer = testForMultipleAnswers(answer, "go to the river",
			"a", "go to river", "river");
		answer = testForMultipleAnswers(answer, "look at sister's book",
			"b", "look at book", "book");
	}

	//stores the class of the character chosen
	String clas;

	/*
	* Outputs text and tests for answer while looking at 
	* sister's book.
	* 
	* @param String text 		the text being output
	*/
	public void lookAtBook(String text){
		System.out.println(text);
		getAnswer();
		answer = testForMultipleAnswers(answer, "assassin",
			"a", "a", "1");
		answer = testForMultipleAnswers(answer, "wizard",
			"b", "w", "2");
		answer = testForMultipleAnswers(answer, "shapeshifter",
			"c", "s", "3");
		clas = answer;
	}

	/*
	* Outputs text and waits for user to type "adventure".
	* 
	* @param String text 		the text being output
	*/
	public void classChosen(String text){
		System.out.println(text);
		getAnswer();
	}

	/*
	* Outputs text for the rabbit hole introduction and 
	* tests for answer.
	* 
	* @param String text 		the text being output
	*/
	public void rabbitIntro(String text){
		System.out.println(text);
		getAnswer();
		answer = testForMultipleAnswers(answer, "crawl into the hole",
			"a", "crawl in", "go down");
		answer = testForMultipleAnswers(answer, "look around the bush",
			"b", "look around the bush", "look");
	}

	/*
	* Outputs text and tests for answer when looking around the 
	* bush above the rabbit hole.
	* 
	* @param String text 		the text being output
	*/
	public void lookAroundBush(String text){
		System.out.println(text);
		getAnswer();
		answer = testForMultipleAnswers(answer, "pick up the piece of metal",
			"a", "pick up the piece of metal", "pick up metal");
		answer = testForMultipleAnswers(answer, "crawl into the hole",
			"b", "crawl into the hole", "crawl");
	}

	/*
	* Outputs text and tests for answer on what the user wants 
	* to do after finding the piece of metal.
	* 
	* @param String text 		the text being output
	*/
	public void pickUpMetal(String text){
		System.out.println(text);
		getAnswer();
		answer = testForMultipleAnswers(answer, "look around for more items",
			"a", "look", "look around");
		answer = testForMultipleAnswers(answer, "crawl into the hole",
			"b", "crawl in", "go down");
	}

	/*
	* Outputs text and tests for answer after the player crawls into 
	* the rabbit hole.
	* 
	* @param String text 		the text being output
	*/
	public void crawlInHole(String text){
		System.out.println(text);
		getAnswer();
		answer = testForMultipleAnswers(answer, "take one of the items",
			"a", "take item", "item");
		answer = testForMultipleAnswers(answer, "look around",
			"b", "look", "look more");
		answer = testForMultipleAnswers(answer, "open bag",
			"c", "open", "bag");
	}

	/*
	* Outputs text and tests for answer after player chooses to look for 
	* more items around the bush that is above the rabbit hole.
	* 
	* @param String text 		the text being output
	*/
	public void lookForMoreBushItems(String text){
		System.out.println(text);
		getAnswer();
		answer = testForMultipleAnswers(answer, "look around for more items",
			"a", "look", "look around");
		answer = testForMultipleAnswers(answer, "crawl into the hole",
			"b", "crawl in", "go down");
	}

	/*
	* Outputs text and tests for answer of which item the player 
	* wants to take while falling down the rabbit hole.
	* 
	* @param String text 		the text being output
	*/
	public void takeItem(String text){
		System.out.println(text);
		getAnswer();
		answer = testForMultipleAnswers(answer, "matches",
			"a", "lighter", "fire");
		answer = testForMultipleAnswers(answer, "candlestick",
			"b", "candle", "firestick");
		answer = testForMultipleAnswers(answer, "pick axe",
			"c", "axe", "pick");
	}

	/*
	* Opens bag and tests for player's answer on what they 
	* want to do with the item they chose to use in their bag.
	* 
	* @param String answer 		the current answer
	*
	* @return String answer 	the current answer
	*/
	public String openBag(String answer){
		answer = invent.openBag();
		if(answer.equals("noAnswer")){
			System.out.println("What do you want to do?");
			getAnswer();
		}else{
			String temp = answer;
			switch(temp){
				case "candlestick":
				answer = input.nextLine();
				answer = answer.toLowerCase();
				answer = testForMultipleAnswers(answer, "light candle",
					"a", "light", "candle");
				answer = testForMultipleAnswers(answer, "drop candle",
					"b", "drop", "drop candle");
				break;

				case "pick axe":
				answer = input.nextLine();
				answer = answer.toLowerCase();
				answer = testForMultipleAnswers(answer, "swing axe",
					"a", "swing", "axe");
				answer = testForMultipleAnswers(answer, "drop axe",
					"b", "drop", "drop axe");
				break;

				case "potion":
				answer = input.nextLine();
				answer = answer.toLowerCase();
				answer = testForMultipleAnswers(answer, "drink potion",
					"a", "drink", "potion");
				break;
			}
		}
		return answer;
	}

	/*
	* Outputs text and tests for answer on what the player wants 
	* to do after looking around the rabbit hole for items.
	* 
	* @param String text 		the text being output
	*/
	public void lookAroundHole(String text){
		System.out.println(text);
		getAnswer();
		answer = testForMultipleAnswers(answer, "take one of the items",
			"a", "take item", "item");
		answer = testForMultipleAnswers(answer, "look around",
			"b", "look", "look more");
		answer = testForMultipleAnswers(answer, "open bag",
			"c", "open", "bag");
	}

	/*
	* Outputs text and tests for answer on what the player wants 
	* to do after taking an item in the rabbit hole.
	* 
	* @param String text 		the text being output
	*/
	public void pickItem(String text){
		System.out.println(text);
		getAnswer();
		answer = testForMultipleAnswers(answer, "take one of the items",
			"a", "take item", "item");
		answer = testForMultipleAnswers(answer, "look around",
			"b", "look", "look more");
		answer = testForMultipleAnswers(answer, "open bag",
			"c", "open", "bag");		
	}

	/*
	* Outputs text and tests for what player wants to do after 
	* dropping the candlestick.
	* 
	* @param String text 		the text being output
	*/
	public void dropCandlestick(String text){
		System.out.println(text);
		getAnswer();
		answer = testForMultipleAnswers(answer, "open bag",
			"a", "open", "bag");
		answer = testForMultipleAnswers(answer, "look around",
			"b", "look", "around");
	}

	/*
	* Outputs text and tests for answer on what the 
	* player wants to do after letting go of the axe.
	* 
	* @param String text 		the text being output
	*/
	public void letGoAxe(String text){
		System.out.println(text);
		getAnswer();
		answer = testForMultipleAnswers(answer, "open bag",
			"a", "open", "bag");
		answer = testForMultipleAnswers(answer, "look around",
			"b", "look", "around");
	}

	/*
	* Outputs text and tests for answer on what the user wants 
	* to do after swinging the axe.
	* 
	* @param String text 		the text being output
	*/
	public void swingAxe(String text){
		System.out.println(text);
		getAnswer();
		answer = testForMultipleAnswers(answer, "let go of pick axe",
			"a", "let go", "drop axe");
		answer = testForMultipleAnswers(answer, "open bag",
			"b", "open", "bag");
		answer = testForMultipleAnswers(answer, "fight",
			"c", "weapon", "hit");
	}

	/*
	* Outputs text after the bat fight.
	* 
	* @param String text 		the text being output
	*/
	public void afterBatFight(String text){
		System.out.println(text);
	}

	/*
	* Outputs text and tests for answer on what the player 
	* wants to do upon entering the hallway.
	* 
	* @param String text 		the text being output
	*/
	public void hallwayIntro(String text){
		System.out.println(text);
		getAnswer();
		answer = testForMultipleAnswers(answer, "try one of the doors",
			"a", "doors", "open");
		answer = testForMultipleAnswers(answer, "examine table 1",
			"b", "1", "table 1");
		answer = testForMultipleAnswers(answer, "examine table 2",
			"c", "2", "table 2");
		answer = testForMultipleAnswers(answer, "examine table 3",
			"d", "3", "table 3");
	}

	/*
	* Outputs text and tests for answer on what the player wants to 
	* do after trying to open one of the doors.
	* 
	* @param String text 		the text being output
	*/
	public void tryDoor(String text){
		System.out.println(text);
		getAnswer();
		answer = testForMultipleAnswers(answer, "examine table 1",
			"a", "1", "table 1");
		answer = testForMultipleAnswers(answer, "examine table 2",
			"b", "2", "table 2");
		answer = testForMultipleAnswers(answer, "examine table 3",
			"c", "3", "table 3");
	}

	//true if table 1 has already been examined
	boolean table1 = false;

	//true if table 2 has already been examined
	boolean table2 = false;

	//true if table 3 has already been examined
	boolean table3 = false;

	/*
	* Outputs text and tests for answer if the player has already 
	* examined table 1.
	* 
	* @param String text 		some of the text being output
	*/
	public void table1(String text){
		if(table1 == true){
			System.out.println("You already examined this table.");
			System.out.println("These are your options from here: ");
			System.out.println("		a) open bag");
			System.out.println("		b) examine table 2");
			System.out.println("		c) examine table 3");
			getAnswer();
			answer = testForMultipleAnswers(answer, "open bag",
				"a", "open", "bag");
			answer = testForMultipleAnswers(answer, "examine table 2",
				"b", "2", "table 2");
			answer = testForMultipleAnswers(answer, "examine table 3",
				"c", "3", "table 3");
		}else{
			foundPotion(text);
			table1 = true;
		}
	}

	/*
	* Outputs text and tests for answer if player has already examined 
	* table 2.
	* 
	* @param String text 		some of the text being output
	*/
	public void table2(String text){
		if(table2 == true){
			System.out.println("You already examined this table.");
			System.out.println("These are your options from here: ");
			System.out.println("		a) try the small door");
			System.out.println("		b) try the medium door");
			System.out.println("		c) try the big door");
			getAnswer();
			answer = testForMultipleAnswers(answer, "try the small door",
				"a", "small", "small door");
			answer = testForMultipleAnswers(answer, "try the medium door",
				"b", "medium", "medium door");
			answer = testForMultipleAnswers(answer, "try the big door",
				"c", "big", "big door");					
		}else{
			foundKey(text);
			table2 = true;
		}
	}

	/*
	* Outputs text and tests for answer if player has already examined 
	* table 3.
	* 
	* @param String text1 		the first text being output
	* @param String text2 		the second text being output
	*/
	public void table3(String text1, String text2){
		if(table3 == true){
			System.out.println("You already examined this table.");
			System.out.println("These are your options from here: ");
			System.out.println("		a) examine table 1");
			System.out.println("		b) examine table 2");
			getAnswer();
			answer = testForMultipleAnswers(answer, "examine table 1",
				"a", "1", "table 1");
			answer = testForMultipleAnswers(answer, "examine table 2",
				"b", "2", "table 2");					
		}else{
			foundTableHeart(text1, text2);
			table3 = true;
		}
	}

	/*
	* Outputs text, adds potion to inventory, and tests for answer 
	* on what the player wants to do after finding the potion.
	* 
	* @param String text 		the text being output
	*/
	public void foundPotion(String text){
		System.out.println(text);
		invent.addToBag("potion");
		getAnswer();
		answer = testForMultipleAnswers(answer, "open bag",
			"a", "open", "bag");
		answer = testForMultipleAnswers(answer, "examine table 2",
			"b", "2", "table 2");
		answer = testForMultipleAnswers(answer, "examine table 3",
			"c", "3", "table 3");
	}

	/*
	* Outputs text and tests for answer on what the player wants to 
	* do after finding the key.
	* 
	* @param String text 		the text being output
	*/
	public void foundKey(String text){
		System.out.println(text);
		getAnswer();
		answer = testForMultipleAnswers(answer, "try the small door",
			"a", "small", "small door");
		answer = testForMultipleAnswers(answer, "try the medium door",
			"b", "medium", "medium door");
		answer = testForMultipleAnswers(answer, "try the big door",
			"c", "big", "big door");
	}

	/*
	* Outputs text and tests for answer on what the player wants 
	* to do after finding the extra heart on one of the tables in the 
	* hallway.
	* 
	* @param String text1 		the first text being output
	* @param String text2		the second text being output
	*/
	public void foundTableHeart(String text1, String text2){
		System.out.println(text1);
		invent.heartMeter(1);
		System.out.println(text2);
		getAnswer();
		answer = testForMultipleAnswers(answer, "examine table 1",
			"a", "1", "table 1");
		answer = testForMultipleAnswers(answer, "examine table 2",
			"b", "2", "table 2");
	}

	//true when Alice is in a shrunken state after drinking the potion
	Boolean shrunk = false;

	/*
	* Uses potion after testing to make sure it is in the 
	* player's inventory and shrinks Alice if she is normal sized or 
	* grows her if she is shrunk.
	* 
	* @return boolean shunk 		whether Alice is shrunk or not
	*/
	public boolean usePotion(){
		if(invent.searchBag("potion")){
			if(shrunk == false){
				shrunk = true;
				System.out.println("You shrink to the size of a small garden gnome.");
			}else{
				shrunk = false;
				System.out.println("You grow back to your normal size.");
			}
		}else{
			System.out.println("You do not have the potion.");
		}
		return shrunk;
	}

	/*
	* Outputs text and gets an answer after Alice tries to 
	* go through the small door.
	* 
	* @param String text 		the text being output
	*/
	public void smallDoor(String text){
		System.out.println(text);
		System.out.println("What do you want to do?");
		getAnswer();
	}

	/*
	* Outputs text to end the hallway scene.
	* 
	* @param String text 		the text being output
	*/
	public void hallwayEnding(String text){
		System.out.println(text);
	}

	/*
	* Outputs text to introduce the forest scene and tests 
	* for answer on which direction the player wants to go.
	* 
	* @param String text 		the text being output
	*/
	public void forestIntro(String text){
		System.out.println(text);
		getAnswer();
		answer = testForMultipleAnswers(answer, "left",
			"a", "l", "go left");
		answer = testForMultipleAnswers(answer, "forward",
			"b", "f", "go forward");
		answer = testForMultipleAnswers(answer, "right",
			"c", "r", "go right");
	}

	/*
	* Implements the race mechanics and explains the rules 
	* to the player. Creates five random numbers from 1 to 
	* 10 and uses them to output three different equations for 
	* the user to answer. If the user answers all three correctly,
	* they win the game and gain a heart.
	* 
	* @param String text1 		the first text being output
	* @param String text2		the second text being output
	* 
	* @return boolean 			true if race won, false if lost
	*/
	public boolean race(String text1, String text2){
		int equals;
		System.out.println(text1);
		int num1, num2, num3, num4, num5;
		num1 = (int)(Math.random() * 10 + 1);
		num2 = (int)(Math.random() * 10 + 1);
		num3 = (int)(Math.random() * 10 + 1);
		num4 = (int)(Math.random() * 10 + 1);
		num5 = (int)(Math.random() * 10 + 1);
		System.out.println(num1 + " * " + num2 + " = ");
		equals = input.nextInt();
		if(equals != num1 * num2){
			System.out.println("You lost the race :(");
				return false;
		}
		System.out.println(num3 + " * " + num4 + " + " + num5 + " = ");
		equals = input.nextInt();
		if(equals != num3 * num4 + num5){
			System.out.println("You lost the race :(");
				return false;
		}
		System.out.println(num1 + " + " + num3 + " * " + num5 + " + "
			+ num4 + " - " + num2 + " = ");
		equals = input.nextInt();
		if(equals != num1 + num3 * num5 + num4 - num2){
			System.out.println("You lost the race :(");
				return false;
		}else{
			System.out.println("You won the race :)");
			invent.heartMeter(1);
			System.out.println(text2);
			answer = input.nextLine();
			getAnswer();
			answer = testForMultipleAnswers(answer, "forward",
				"a", "f", "go forward");
			answer = testForMultipleAnswers(answer, "right",
				"b", "r", "go right");
			return true;
		}
	}

	/*
	* Implements the interaction with the Cheshire Cat. Tests 
	* to see if piece of metal is in inventory and gives player 
	* the chance to tell the truth and gain 2 hearts or lie and 
	* lose 1 heart. If the player does not have the piece of metal,
	* they can't do anything here.
	* 
	* @param String text1 		the text being output
	*/
	public void cheshireCat(String text1){
		System.out.println(text1);
		if(invent.findItem("piece of metal") == true){
			System.out.println("	a) give him the piece of metal");
			System.out.println("	b) tell him you don't have it");
			getAnswer();
			answer = testForMultipleAnswers(answer, "give him the piece of metal",
				"a", "give", "give metal");
			answer = testForMultipleAnswers(answer, "tell him you don't have it",
				"b", "don't have it", "tell him");
			if(answer == "give him the piece of metal"){
				System.out.println("The cat thanks you for finding his name tag.");
				System.out.println("To show you his gratitude, he gives you two hearts!");
				invent.heartMeter(2);
			}else if(answer == "tell him you don't have it"){
				System.out.println("The cat looks at you with a frown.");
				System.out.println("It suddenly leaps at you and knocks you to the ground!");
				System.out.println("The piece of metal with his name on it falls out of your bag.");
				System.out.println("He takes the name tag and disappears back into the tree.");
				System.out.println("You lose a heart from your injuries.");
				invent.heartMeter(-1);
			}else{
				defaultOutput();
			}
		}else{
			System.out.println("	a) tell him you don't have it");
			getAnswer();
			answer = testForMultipleAnswers(answer, "tell him you don't have it",
				"a", "don't have it", "tell him");
			if(answer == "tell him you don't have it"){
				System.out.println("The cat looks disappointed and fades back into the darkness.");
				System.out.println("You go back to the crossroads.");
			}else{
				defaultOutput();
			}
		}
		System.out.println("	a) left");
		System.out.println("	b) forward");
		getAnswer();
		answer = testForMultipleAnswers(answer, "left",
			"a", "l", "go left");
		answer = testForMultipleAnswers(answer, "forward",
			"b", "f", "go forward");
	}

	/*
	* Outputs text to introduce the castle scene and 
	* tests for answer on whether the player agrees to 
	* play the Queen's game or not.
	* 
	* @param String text 		the text being output
	*/
	public void castleIntro(String text){
		System.out.println(text);
		getAnswer();
		answer = testForMultipleAnswers(answer, "agree to play",
			"a", "agree", "play");
		answer = testForMultipleAnswers(answer, "refuse to play",
			"b", "refuse", "don't play");
	}

	//number of points player has in the croquet game
	int points = 0;

	/*
	* Outputs text and implements the game of croquet 
	* with the Queen. Player gains points by guessing 
	* which number the computer chose, either 1 or 2, 
	* gainingg a point if they guess correctly. If they guess
	* incorrectly, the player loses half a heart. The 
	* game is over if the player gains 3 points or runs 
	* out of hearts.
	* 
	* @param String text1 		the first text being output
	* @param String text2		the second text being output
	*
	* @return boolean 			returns true when game is won
	*/
	public boolean queenGame(String text1, String text2){
		System.out.println(text1);
			while(points < 3){
				int gameNumber = (int)(Math.random() * 2 + 1);
				System.out.println(text2);
				int userNumber = input.nextInt();
				if(userNumber == gameNumber){
					points++;
					System.out.println("You guessed correctly! You gain 1 point and "
						+ "now have " + points + " points.");
				}else{
					System.out.println("How unfortunate! you have guessed wrong and now "
						+ "lose half a heart.");
					invent.heartMeter((float)(-0.5));
				}
			}
		System.out.println("You won the game! :)");
		return true;
	}

	/*
	* Outputs a default text if the user does not input an acceptable 
	* answer and tests for their next answer.
	*/
	public void defaultOutput(){
		System.out.println("I don't understand what you want me to do.\n"
			+ "Please try entering one of the commands listed.");
		getAnswer();
	}

	/*
	* Gets the user's answer using the input Scanner and 
	* converts the answer to lower case.
	*/
	public void getAnswer(){
		answer = input.nextLine();
		answer = answer.toLowerCase();
	}

	/*
	* Tests answer to see which acceptable answer the user was 
	* trying to input.
	*
	* @param String answer 			the user's answer
	* @param String output 			the acceptable answer
	* @param option1 				one option the user may have entered
	* @param option2 				a second option the user may have entered 
	* @param option3 				a third option the user may have entered
	*
	* @return String answer 		the accepted answer if a match is found or 
	* 								the answer the user gave if no match is found
	*/
	public String testForMultipleAnswers(String answer, String output,
		String option1, String option2, String option3){
		if(answer.equals(option1) || answer.equals(option2) || answer.equals(option3)
			|| answer.equals(output)){
			answer = output;
		}else{
			answer = answer;
		}
		return answer;
	}
}