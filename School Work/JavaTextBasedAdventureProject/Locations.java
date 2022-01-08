/**
 * title: Locations.java
 * description: This class contains the majority of the switch 
 * statements that decide which actions to take based on the 
 * user's answers and calls the appropriate methods from 
 * the Control class.
 * date: January 23, 2021
 * @author Jenna McDonnell
 * @version 1.0
 * 3435506
 */

 /***********************************************************
 * SOURCES USED
 ************************************************************
 * <H1> Sources </H1>
 *
 * <P>
* https://stackoverflow.com/questions/7528045/large-string-split-into-lines-with-maximum-length-in-java
* (used for StringTokenizer)
*
* https://docs.oracle.com/javase/7/docs/api/java/util/StringTokenizer.html
* (used to figure out what to import to use StringTokenizer)
*
* https://stackoverflow.com/questions/68578/multiple-cases-in-switch-statement
* (how to make multiple switch cases do the same thing)
 * </P>
 */
/************************************************************
 * METHODS
 ************************************************************
 * <H3> Methods <H3>
 *
 * <P>
 * public Locations(){<BR>
 	Creates a Locations object that calls the scene methods to 
 	run the game.

 * public void bank(String[] words){<BR>
 	Calls the appropriate methods for the scene by the 
	river bank and uses a switch statement to give the 
	appropriate response for each of the user's answers.

 * public void rabbitHole(String[] words){<BR>
 	Calls the appropriate methods for the scene in the 
	rabbit hole and uses a switch statement to give the 
	appropriate response for each of the user's answers.

 * public void hallway(String[] words){<BR>
 	Calls the appropriate methods for the scene in the 
	hallway and uses a switch statement to give the 
	appropriate response for each of the user's answers.

 * public void forest(String[] words){<BR>
 	Calls the appropriate methods for the scene in the 
	forest and uses a switch statement to give the 
	appropriate response for each of the user's answers.

 * public void castle(String[] words){<BR>
 	Calls the appropriate methods for the scene at the 
	castle and uses a switch statement to give the 
	appropriate response for each of the user's answers.

 * public void makeReader(String fileName){<BR>
 	This method creates a BufferedReader that has a FileReader 
	wrapped inside it that takes the file name as its parameter.
	The reader reads text in the file before the program can 
	display it.

 * public String[] readText(BufferedReader file){<BR>
 	Read text from a file and put each separate paragraph 
	into an array.

 * public void clearArray(String[] words){<BR>
 	Makes all the elements in the words array the null value 
	so the array can be filled with new paragraphs from a 
	different file.
 * </P>
 */

/************************************************************
 * VARIABLES
 ************************************************************
 * <H3> Variables Used </H3>
 *
 * <P>
 * 	
 *	public String fileName; - name of the file being read 
 *	into the game
 *
 *	public boolean complete = false; - true if the first area is 
 *	complete
 *
 *	public Weapons weapon; - creates a new weapon for the character
 *
 *	boolean fightWon = false; - true when bat has been defeated 
 *	meaning the rabbit hole scene has ended
 * 
 *  Enemy bat = new Enemy("bat"); - creates a bat enemy object for 
 *  the bat fight in the rabbit hole
 * 
 *	boolean doorOpen = false; - true if the small door has been 
 *	unlocked
 *
 *	boolean smallAlice = false; - true if Alice is in her shrunken 
 *	state, achieved by drinking the potion
 *
 *	boolean castleFound = false; - when true, the forest scene 
 *	ends and the castle scene starts
 *
 *	boolean gameOver = false; - when this is true, the game ends 
 *	and the program terminates
 * 
 *	BufferedReader file; - used to read files into the game
 *
 *	String fileString; - a single string of the file being read
 *
 *	String[] words = new String[50]; - an array contiaining the 
 *	separate paragraphs in the file being read
 *
 *	String paragraph; - a single paragraph from the file being read,
 *	separated by "/n"
 *
 *	StringBuilder sb = new StringBuilder(50); - builds the paragraphs
 * </P>
 */
import java.util.*; //used for Scanner
import java.io.*; //used for reading files

public class Locations extends Control{

	/*
	* Constructor for the basic parts of the game.
	*/
	public Locations(){
		makeReader("Bank.txt");
		readText(file);
		bank(words);
		clearArray(words);
		complete = false;

		makeReader("RabbitHole.txt");
		readText(file);
		rabbitHole(words);
		clearArray(words);

		makeReader("Hallway.txt");
		readText(file);
		hallway(words);
		clearArray(words);

		makeReader("Forest.txt");
		readText(file);
		forest(words);
		clearArray(words);

		makeReader("Castle.txt");
		readText(file);
		castle(words);
		clearArray(words);

		invent = null;
	}

	//name of the file being read into the game
	public String fileName;

	//true if the first area is complete
	public boolean complete = false;

	//creates a new weapon for the character
	public Weapons weapon;

	/*
	* Calls the appropriate methods for the scene by the 
	* river bank and uses a switch statement to give the 
	* appropriate response for each of the user's answers.
	*
	* @param String[] words 		the array containing the 
	* 								text for this scene
	*/
	public void bank(String[] words){

		bankIntro(words[0].toString());

		while(complete == false){
			switch(answer){
				case "climb down tree":
					climbDownTree(words[1].toString());
					break;

				case "climb higher":
					climbHigher(words[2].toString());
					break;

				case "investigate the red object":
					investigateRedObject(words[3].toString(), words[4].toString());
					break;

				case "go to the river":
					goToRiver(words[6].toString());
					break;

				case "open the chest":
					openChest(words[7].toString());
					break;

				case "go back to sister":
					backToSister(words[8].toString());
					break;

				case "look at sister's book":
					lookAtBook(words[9].toString());
					break;

				case "assassin":
				case "wizard":
				case "shapeshifter":
					classChosen(words[10].toString());
					break;

				case "adventure":
					System.out.print(words[11]);
					weapon = new Weapons();
					weapon.makeWeapon(clas);
					complete = true;
					System.out.print(words[12]);
					break;

				default:
					defaultOutput();
					break;
			}//end of switch statement

		}

	}//end of bank method

	//true when bat has been defeated meaning the rabbit hole 
	//scene has ended
	boolean fightWon = false;

	/*
	* Calls the appropriate methods for the scene in the 
	* rabbit hole and uses a switch statement to give the 
	* appropriate response for each of the user's answers.
	*
	* @param String[] words 		the array containing the text 
	* 								for this scene
	*/
	public void rabbitHole(String[] words){

		rabbitIntro(words[0].toString());

		while(fightWon == false){
			switch(answer){
				case "crawl into the hole": 
					crawlInHole(words[4].toString());
					break;

				case "look around the bush":
					lookAroundBush(words[1].toString());
					break;

				case "pick up the piece of metal":
					invent.addToBag("piece of metal");
					pickUpMetal(words[2].toString());
					break;

				case "look around for more items":
					lookForMoreBushItems(words[3].toString());
					break;

				case "take one of the items":
					takeItem(words[5].toString());
					break;

				case "look around":
					lookAroundHole(words[6].toString());
					break;

				case "open bag":
					answer = openBag(answer);
					break;

				case "matches":
					invent.addToBag("matches");
					pickItem(words[7].toString());
					break;

				case "candlestick":
					invent.addToBag("candlestick");
					pickItem(words[8].toString());
					break;

				case "pick axe":
					invent.addToBag("pick axe");
					pickItem(words[9].toString());
					break;

				case "drop candle":
					dropCandlestick(words[12].toString());
					break;

				case "swing axe":
					swingAxe(words[14].toString());
					break;

				case "drop axe":
					letGoAxe(words[16].toString());
					break;

				case "fight":
					Enemy bat = new Enemy("bat");
					fightWon = bat.fightMechanics(invent, weapon);
					afterBatFight(words[17].toString());
					break;

				default:
					defaultOutput();
					break;
			}
		}
	}

	//true if the small door has been unlocked
	boolean doorOpen = false;

	//true if Alice is in her shrunken state, 
	//achieved by drinking the potion
	boolean smallAlice = false;

	/*
	* Calls the appropriate methods for the scene in the 
	* hallway and uses a switch statement to give the 
	* appropriate response for each of the user's answers.
	*
	* @param String[] words 		the array containing the 
	* 								text for this scene
	*/
	public void hallway(String[] words){
		hallwayIntro(words[0].toString());
		while(doorOpen == false || smallAlice == false){
			switch(answer){
				case "noAnswer":
					System.out.println("What would you like to do?");
					getAnswer();
					break;

				case "open bag":
					answer = openBag(answer);
					break;

				case "try one of the doors":
					tryDoor(words[6].toString());
					break;

				case "examine table 1":
					table1(words[5].toString());
					break;

				case "examine table 2":
					table2(words[1].toString());
					break;

				case "examine table 3":
					table3(words[2].toString(), words[3].toString());
					break;

				case "drink potion":
					smallAlice = usePotion();
					answer = "noAnswer";
					break;

				case "try the small door":
					if(smallAlice == true){
						hallwayEnding(words[7].toString());
						doorOpen = true;
					}else{
						smallDoor(words[4].toString());
						doorOpen = true;
						}
					break;

				case "try the medium door":
					//mediumDoor();
					break;
				case "try the big door":
					//bigDoor();
					break;
			}
		}
	}

	//when true, the forest scene ends and the castle scene starts
	boolean castleFound = false;

	/*
	* Calls the appropriate methods for the scene in the 
	* forest and uses a switch statement to give the 
	* appropriate response for each of the user's answers.
	*
	* @param String[] words 		the array containing the 
	* 								text for this scene
	*/
	public void forest(String[] words){
		//left is race, forward is caterpillar, 
		//right is cheshire cat
		forestIntro(words[0].toString());
		while(castleFound == false){
			switch(answer){
				case "left":
					race(words[1].toString(), words[2].toString());
					break;

				case "forward":
					castleFound = true;
					break;
					
				case "right":
					cheshireCat(words[3].toString());
					break;
			}
		}
		System.out.println(words[4].toString());
	}

	//when this is true, the game ends and the program terminates
	boolean gameOver = false;

	/*
	* Calls the appropriate methods for the scene at the 
	* castle and uses a switch statement to give the 
	* appropriate response for each of the user's answers.
	*
	* @param String[] words 		the array containing the 
	* 								text for this scene
	*/
	public void castle(String[] words){
		castleIntro(words[0].toString());
		while(gameOver == false){
			switch(answer){
				case "agree to play":
					gameOver = queenGame(words[2].toString(), words[3].toString());
					System.out.println(words[4].toString());
					break;
				case "refuse to play":
					System.out.println(words[1].toString());
					gameOver = true;
					break;
			}
		}
	}

	//used to read files into the game
	BufferedReader file;

	/*
	* This method creates a BufferedReader that has a FileReader 
	* wrapped inside it that takes the file name as its parameter.
	* The reader reads text in the file before the program can 
	* display it.
	*
	* @throws 	FileNotFoundException 		if the file does not exist
	*/
	public void makeReader(String fileName){

		try{
			file = new BufferedReader(new FileReader(fileName));

		}catch(FileNotFoundException e){

			System.out.println("I cannot find that file.");
			System.exit(0);

		}
	}//end of makeReader method

	//a single string of the file being read
	String fileString;

	//an array contiaining the separate paragraphs in 
	//the file being read
	String[] words = new String[50];

	//a single paragraph from the file being read,
	//separated by "/n"
	String paragraph;

	/*
	* Read text from a file and put each separate paragraph 
	* into an array.
	*
	* @param BufferedReader file 		the file reader
	* @return words 					the array with the paragraphs in it
	*/
	public String[] readText(BufferedReader file){
		for(int i = 0; i < words.length; i++){
			words[i] = null;
		}

		try{
				StringBuilder sb = new StringBuilder(50);
				while ((fileString = file.readLine()) != null){
					paragraph = (sb.append(fileString).append("\n")).toString();
				}
				words = paragraph.split("/n");

		}catch(IOException e){
			System.out.println("Something went wrong with the reading "
				+ "of the file.");
		}
		return words;
	}//end of readText method

	/*
	* Makes all the elements in the words array the null value 
	* so the array can be filled with new paragraphs from a 
	* different file.
	*
	* @param String[] words 		array being cleared
	*/
	public void clearArray(String[] words){
		for(int i = 0; i < words.length; i++){
			words[i] = null;
		}
		paragraph = null;
		file = null;
	}

}