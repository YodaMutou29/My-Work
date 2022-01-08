/**
 * title: WonderlandGame.java
 * description: This program allows the reader to play a text-based 
 * adventure game that is adapted from "Alice's Adventures in 
 * Wonderland", by Lewis Carroll.
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
 * https://significantinsignificance.wordpress.com/2009/11/01/
 * things-not-all-programmers-know-1/
 * (used to figure out why the compiler was saying I had cyclic
 * inheritance)
 *
 * https://www.geeksforgeeks.org/garbage-collection-java/
 * (used to learn how to call garbage collector)
 *
 * https://docs.oracle.com/javase/7/docs/api/java/lang/StringBuilder.html
 * (used for StringBuilder for reading text files)
 *
 * https://www.javatpoint.com/understanding-toString()-method
 * (used for converting array values to Strings)
 *
 * https://docs.oracle.com/javase/7/docs/api/java/io/BufferedReader.html
 * (used for BufferedReader when reading text files)
 *
 * https://www.javatpoint.com/java-string-equals
 * (used for string equals() method)
 *
 * https://beginnersbook.com/2013/12/how-to-convert-string-to-int-in-java/
 * (used to convert a string to an integer)
 *
 * https://stackoverflow.com/questions/7320315/how-to-test-for-blank-line-
 * with-java-scanner#:~:text=If%20you're%20using%20nextLine,
 * read%20blank%20lines%20at%20all.
 * (used to detect blank input)
 * 
 * https://beginnersbook.com/2013/12/java-arraylist/
 * (used to figure out how to use array lists)
 * </P>
 */

/************************************************************
 * DOCUMENTATION
 ************************************************************
 * <H1> Alice in Wonderland Text-Based Adventure </H1>
 * 
 * <H3> Purpose and Description </H3>
 * 
 * <P> 
 * The purpose of this program is to provide entertainment and 
 * to put my own twists on Alice's Adventures in Wonderland by Lewis
 * Carroll.
 * </P>
 * <P> 
 * I have implemented this game using Scanners for answers and 
 * output, and switch statements to determine the correct output 
 * and actions for each answer.
 * </P>
 *
 * <DL>
 * <DT> Compiling and Running Instructions </DT>
 * <DT> Assuming SDK 11.0.2 or later and the CLASSPATH are set up properly.</DT>
 * <DT> Change to the directory containing the source code. </DT>
 * <DD> Compile: javac WonderlandGame.java 
 *				 javac Locations.java
 * 				 javac Control.java
 * 				 javac Inventory.java
 * 				 javac Weapons.java
 * 				 javac Enemy.java </DD>
 * <DD> Run: java WonderlandGame</DD>
 */

/************************************************************
 * CLASSES & METHODS
 ************************************************************
 * <H3> Classes </H3>
 * <P>
 * public class WonderlandGame{<BR>
 	This is the main class for this game. It creates a locations
 	object and deletes it when the game is over.
 
 * public class Locations extends Control{<BR>
 	This class holds the majority of the switch statements that 
 	determine which action to take based on the user's answer.
 	It then calls the appropriate methods in the Control class.

 * public class Control{<BR>
 	This class contains the majority of the methods called by 
 	the Locations class. These methods are more specific to 
 	certain situations.

 * public class Inventory{<BR>
 	This class implements the bag and heart storage. All items 
 	collected in the game are stored here.

 * public class Weapons{<BR>
 	This class holds the weapon creation methods and the attack 
 	method.

 * public class Enemy{<BR>
 	This class holds enemy health and attack methods, as well as 
 	information about the enemies, such as their names.
 * </P>
 *
 * <H3> Methods <H3>
 *
 * <P>
 * (all methods are described in their respective class files)
 *
 * public static void main(String[] args){<BR>
 	This is the main method for this class and it creates a 
 	Locations object and deletes the object when the game is 
 	over.
 * </P>
 */

/************************************************************
 * VARIABLES
 ************************************************************
 * <H3> Variables Used </H3>
 *
 * <P>
 * (all variables are explained in their respective class files)
 *
 * Locations game; - the object that runs the game
 * </P>
 */

/************************************************************
 * TESTING
 ************************************************************
 * <H1> Test Plan </H1>
 * <P> 
 * 1. Run the application.
 * EXPECTED:
 * 		Command prompt displays the following:
 *		"You are sitting in a tree near a river bank.
 * 		Your older sister is sitting at the bottom of the
 * 		tree reading a book. You look at her and then at
 * 		the bank, and you wonder what kind of adventure
 * 		you'll embark on today.
 *
 * 		Do you:
 *		       a)climb down tree
 * 		       b)climb higher"
 * ACTUAL:
 *		Command prompt displays text as expected.
 * </P>
 * <P>
 * 2. Good Data Cases
 * EXPECTED:
 * 		Run the following test case by typing the following commands 
 * 		when prompted to and hitting enter:
 * 		
 * 		climb down tree -> output should be
 * 		"You climb down the tree and stand next to your sister.
 * 		She tells you to be careful climbing up trees like
 * 		that but you're too distracted by something you see in
 *		the river to pay any attention to her grown-up speech.
 *
 *		Do you:
 * 		       a)go to the river
 *		       b)look at sister's book"
 * 		
 * 		look at sister's book -> output should be
 * 		"You look at the book your sister is reading and see three
 * 		versions of...it can't be! They are pictures of you!
 *
 * 		The first picture shows you in a tight, flexable suit of
 * 		armour, with a small dagger in your hand. Under the picture
 * 		are the words "Alice the Assassin".
 * 
 * 		The second picture shows you in a long, purple cloak
 * 		with a wand in your hand. Under the picture are the
 * 		words "Alice the Wizard".
 * 
 * 		The third picture shows you with a necklace that has a
 * 		carving of a wolf on it. Under the picture are the
 * 		words "Alice the Shapeshifter".
 * 
 * 		Choose your class:
 *		       a)assassin
 *		       b)wizard
 *		       c)shapeshifter"
 * 	
 * 		assassin -> output should be
 * 		"Having chosen your class, you are now ready to set out
 * 		on your adventure. You go back to the river and jump into
 * 		the water where a chest lies.
 * 		(Type "adventure" when you are ready to open the chest
 * 		and start your adventure.)"
 * 
 * 		adventure -> output should be
 * 		"The chest opens and a magical light shines out.
 * 
 * 		You have found a dagger with <random number> attack damage!
 *
 *
 *
 * 		After retrieving your weapon, you
 * 		see a white rabbit go running past you.
 * 		You run after the rabbit as fast as you
 * 		can. He is a lot faster than you but you
 *		manage to stay close enough to see him
 * 		crawl into a little hole in the bush.
 *
 * 		Do you:
 * 		      a)crawl into the hole
 *		      b)look around the bush"
 *
 * 		crawl into the hole -> output should be
 * 		"You crawl into the hole in the bush and
 * 		suddenly feel yourself falling! You assume it
 * 		is a small drop, as it's only a rabbit hole,
 * 		but you don't see the ground at all. There are
 * 		items falling around you, including matches, a
 * 		candlestick, and a pick axe.
 * 
 * 		Do you:
 *		       a)take one of the items
 *		       b)look around
 *		       c)open bag"
 *
 * 		take one of the items -> output should be
 * 		"Which item do you want to take?
 *		       a)matches
 *		       b)candlestick
 *		       c)pick axe"
 *
 * 		pick axe -> output should be
 * 		"You take the pick axe.
 *
 *		***** pick axe has been added to inventory *****
 *
 * 		Do you:
 *		       a)take one of the items
 *		       b)look around
 *		       c)open bag"
 *
 *		open bag -> output should be
 * 		"Here are the items in your bag:
 *
 *		       1. pick axe
 *
 * 		Would you like to use one of the items?"
 *
 *		yes -> output should be
 * 		"Which item do you want to use?"
 *
 * 		1 -> output should be
 * 		"Item found.
 *		Here are the things you can do with this item:
 *		       a) swing axe
 *		       b) drop axe"
 *
 * 		swing axe -> output should be
 * 		"You take a swing at the wall of the rabbit hole
 * 		with the pick axe and it sticks! You're not sure
 *		exactly how you're going to get out of the hole
 *		but you're glad to take a break from falling.
 *
 * 		What's that?? You hear a screeching noise and the
 * 		sound of wings flapping...suddenly something dives
 * 		at your head and spits out a burst of flames that just
 * 		misses your head! It flies the other way but you can
 * 		tell it's not going to leave you alone.
 *
 *		Do you:
 *		       a)let go of pick axe
 *		       b)open bag
 *		       c)fight"
 *
 * 		fight -> output should be
 * 		"The bat now has 100 health points.
 * 		Press enter to continue fight."
 *
 * 		(continue pressing enter until fight is over) ->
 *		output should be
 * 		"The bat starts falling with you and you grab onto one
 *		of its wings. As you do, you notice a magical barrier
 * 		beneath you starts to open up and there seems to be light
 *		on the other side. Holding the bat's wing, you glide down
 *		to the floor and land in a hallway with many doors of
 *		different shapes and sizes.
 *
 *
 *		As you enter the hallway you see three tables before you.
 *
 *		Do you:
 *		       a)try one of the doors
 *		       b)examine table 1
 *		       c)examine table 2
 *		       d)examine table 3"
 * 		
 * 		try one of the doors -> output should be
 * 		"All the doors are locked.
 *
 *		Do You:
 *		       a) examine table 1
 *		       b) examine table 2
 *		       c) examine table 3"
 * 		
 *		examine table 1 -> output should be
 * 		"You find a potion on the table, but you are not sure what
 * 		it does.
 *
 *		POTION HAS BEEN ADDED TO INVENTORY
 *
 *		Do you:
 *		       a)open bag
 *		       b)examine table 2
 *		       c)examine table 3"
 *		
 *		open bag -> output should be
 *		"Here are the items in your bag:
 *
 *		       1. pick axe
 *		       2. potion
 *
 *		Would you like to use one of the items?"
 * 		
 * 		yes -> output should be 
 * 		"Which item do you want to use?"
 * 		
 * 		2 -> output should be 
 * 		"Item found.
 * 		Here are the things you can do with this item:
 *		       a) drink potion"
 *
 * 		drink potion -> output should be
 * 		"You shrink to the size of a small garden gnome.
 *		What would you like to do?"
 *
 * 		examine table 2 -> output should be
 * 		"You find a key on the table! It must belong to one of the
 * 		doors.
 *
 *		Do you:
 *		       a)try the small door
 *		       b)try the middle door
 *		       c)try the big door"
 *
 * 		try the small door -> output should be 
 * 		"The door opens and after having drank the potion,
 *		you are small enough to walk through it! On the other
 *		side of the door you find a beautiful forest.
 *
 *
 *		There are three paths to take:
 *		       a) left
 *		       b) forward
 *		       c) right"
 * 
 * 		left -> output should be
 * 		"You go left and come into a clearing with
 * 		a bunch of animals lined up and a crowd of animals
 *		surrounding them. The crowd starts pushing you into
 *		the line and suddenly a gun goes off and the
 *		animals in the line start running in the same
 *		direction...you are in a race!
 * 		
 *		To win the race, enter the correct answers to the
 *		following equations:"
 * 	
 *		(enter the correct answers to the 3 equations) ->
 * 		output should be
 * 		"You won the race :)
 *		You have <number of hearts> hearts.
 *
 *
 * 		You gained an extra heart!
 *
 *		You wave goodbye to the animals and go back to the
 *		crossroads. Which way do you want to go?
 *		       a) forward
 *		       b) right"
 * 		
 * 		right -> output should be 
 * 		"You go right and see a pair of eyes up in a tree.
 * 		They are glowing yellow and staring right at you!
 *		As you approach the tree a body starts to form around
 *		the eyes and you realize it is a pink striped cat.
 * 		It tells you it lost the name tag on it's collar and
 * 		asks if you've seen it.
 *
 *		       a) tell him you don't have it"
 * 
 * 		tell him you don't have it -> output should be
 * 		"The cat looks disappointed and fades back into the darkness.
 *		You go back to the crossroads.
 *		       a) left
 *		       b) forward"
 * 
 * 		forward -> output should be
 * 		"You go forward and see a majestic black and red castle
 *		before you. As you walk up to it, you are stopped by
 * 		some talking cards, which appear to be the guards of the
 * 		castle.
 *
 *
 * 		The guards take you around the palace to a large
 *		garden where a rather round lady is standing
 *		with a frown on her face. She introduces herself
 *		as the Queen of Hearts and hands you a flamingo
 *		who looks quite terrified. She tells you to play
 *		her in a game of croquet if you wish to keep your
 *		human form.
 *
 *		Do you:
 * 		       a) agree to play
 * 		       b) refuse to play"
 *
 * 		agree to play -> output should be
 * 		"One of the guards comes over to explain the rules:
 *
 * 		To get hit the ball through the hoop select either
 *		1 or 2. The game randomly chooses either a 1 or a
 *		2, and if you choose correctly, you get 1 point.
 *		If you choose wrong, you lose half a heart.
 *
 *		To win the game, you must get 3 points.
 *
 *
 *
 *
 * 		Please enter a 1 or a 2:"
 * 		
 *		(Enter 1 or 2 until you get 3 points) -> output should be
 * 		"You won the game! :)
 *
 *
 * 		A hush comes over the crowd of the guards and the
 * 		Queen lets out a loud scream. You have lifted the
 *		curse she put on the guards and they turn into
 *		forest animals. One of them turns into the White
 *		Rabbit you were chasing and you realize he must've
 *		had an unfortunate encounter with the queen just
 *		before you arrived. The Queen runs off into the
 *		forest out of embarassment after losing the game,
 *		and the animals crown you the new Queen of
 *		Wonderland.
 *
 *		THE END"
 * 		(program terminates)
 *
 * ACTUAL: 
 *		Runs as expected.
 * </P>
 * <P>
 * 3. Bad Data Cases:
 * EXPECTED: 
 *		Run the following test case by typing the following command
 * 		at the beginning of the game and hitting enter:
 * 		
 *		unicorn -> output should be
 * 		"I don't understand what you want me to do.
 * 		Please try entering one of the commands listed."
 *
 * ACTUAL: 
 * 		Runs as expected.
 * </P>
 */

/***************************************************************
 * CODE
 *************************************************************** 
 */
/*
* ROUGH DRAFT STORY PLAN
* Start in woods where Alice finds weapon under water.
* Follows rabbit who appears only after Alice has found 
* the weapon for class chosen. Fights bat while falling in hole.
* Bat drops a key. Test all doors for key. Key works on third door.
* Alice is too big. Search room, take key with because don't want to 
* lose it. Find drink me on table. Check for poison. Drink and shrink.
* Key is on table. Find cake on ground. Eat and grow. Too big. Cry. Rabbit 
* runs by again, sees Alice, drops little gloves and fan. Alice pick 
* up gloves and shrink. Swim in tears to door. Go left or right. Left is 
* race. Right is caterpillar fight. Blows smoke. Defeat and he drops mushroom 
* (can now grow or shrink on command). Continue in forest, find cheshire cat, 
* get extra life. Move on to queen. Fight guard. Drops paint brush. Paint 
* used as disguise to sneak up on queen and hear evil plan to turn all 
* citizens and creatures into cards to be her servants (you realise the card 
* guards were once creatures of the forest). Rabbit runs in, you notice a spade 
* forming on his forehead. He tells you the only way to stop her and turn the 
* cards back is to defeat her in a fight. If you defeat her, you become the 
* rightful queen of the forest and can banish her. She overhears you talking to 
* the rabbit and she turns her staff to him and immeadiately he becomes a card.
* He can no longer talk. The queen is angry and challenges you to a duel. You 
* defeat her. The rabbit and all other cards turn back to their original form. 
* You take the staff from the queen and have the choice to turn her into a card 
* or banish her from the forest. You then ascend your throne and are crowned and 
* the game ends.
*/
public class WonderlandGame{
	/*
	* Creates a new game.
	*/
	public static void main(String[] args){
		Locations game = new Locations();
		game = null;
		System.gc();
		System.runFinalization();
		System.exit(0);
	}
}