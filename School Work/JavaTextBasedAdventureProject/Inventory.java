/**
 * title: Inventory.java
 * description: This class contains the methods for the 
 * bag and hearts storage.
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
 * public Inventory(){<BR>
 	Creates an Inventory object that can use all the methods 
	and variables in this class.

 * public void heartMeter(float add){<BR>
 	Adds hearts to the player's heart count and output 
	the number of hearts they have.

 * public String openBag(){<BR>
 	Outputs the items currently in the player's bag and 
	calls the appropriate methods to find use an item 
	if the player says they want to use something.

 * public String useItem(){<BR>
 	Determines which item the player wants to use and calls 
	findItem() to check if that item is in the player's bag.

 * public void itemUses(String item){<BR>
 	Contains the uses for each of the items and uses a switch 
	statement to determine which item uses should be returned.

 * public boolean findItem(String item){<BR>
 	Checks to see if a certain item is in the 
	player's bag.

 * public void cannotUseItem(){<BR>
 	Informs user that the item they want to use cannot 
	be used and asks if they want to use another item.

 * public void addToBag(String item){<BR>
 	Adds an item to the player's bag.

 * public boolean searchBag(String item){<BR>
 	Checks if an item is in the bag.
 * </P>
 */

/************************************************************
 * VARIABLES
 ************************************************************
 * <H3> Variables Used </H3>
 *
 * <P>
 *	Scanner scan = new Scanner(System.in); - 
 *	the Scanner used in this class
 *
 *	String answer; - the user's answer
 *
 *	ArrayList<String> bag = new ArrayList<String>(); - 
 *	the bag containing the user's items
 *
 *	float hearts = 3; - number of hearts the player has
 * 
 *	boolean found; - true when an item has been found
 * </P>
 */
import java.util.*;

public class Inventory{
	/*
	* Creates an Inventory object that can use all the methods 
	* and variables in this class.
	*/
	public Inventory(){
		
	}

	//the Scanner used in this class
	Scanner scan = new Scanner(System.in);

	//the user's answer
	String answer;

	//the bag containing the user's items
	ArrayList<String> bag = new ArrayList<String>();

	//number of hearts the player has
	float hearts = 3;

	/*
	* Adds hearts to the player's heart count and output 
	* the number of hearts they have.
	*
	* @param float add 		the number of hearts to add
	* 						(a negative number subtracts hearts)
	*/
	public void heartMeter(float add){
		hearts = hearts + add;
		System.out.println("You have " + hearts + " hearts.");
		if(hearts <= 0){
			System.out.println("You ran out of hearts!");
			System.out.println("\nGAME OVER");
			System.exit(0);
		}
	}

	/*
	* Outputs the items currently in the player's bag and 
	* calls the appropriate methods to find use an item 
	* if the player says they want to use something.
	*
	* @return String answer 		the current answer
	*/
	public String openBag(){
		System.out.println("Here are the items in your bag: \n");
		for(int i = 0; i < bag.size(); i++){
			System.out.println("\t" + (i + 1) + ". " + bag.get(i));
			if (i == (bag.size() - 1)){
				System.out.println();
			}
		}
		System.out.println("Would you like to use one of the " 
			+ "items?");
		answer = scan.nextLine();
		if(answer.equals("yes")){
			answer = useItem();
		}else{
			System.out.println("You've closed your bag.");
			answer = "noAnswer";
		}
		return answer;
	}
	
	/*
	* Determines which item the player wants to use and calls 
	* findItem() to check if that item is in the player's bag.
	* 
	* @return String answer 		the current answer
	*/
	public String useItem(){
		System.out.println("Which item do you want to use?");
		answer = scan.nextLine();
			while (findItem(answer) == false){
				System.out.println("Item not found. Contradiction.");
				openBag();
				answer = scan.nextLine();
			}
		System.out.println("Here are the things you can do with this "
			+ "item:");
		itemUses(answer);
		return answer;
	}

	/*
	* Contains the uses for each of the items and uses a switch 
	* statement to determine which item uses should be returned.
	*
	* @param String item 		the item the player wants to use 
	*/
	public void itemUses(String item){
		switch(item){
			case "matches":
			case "candlestick":
			case "pick axe":
				System.out.println("	a) swing axe");
				System.out.println("	b) drop axe");
				break;
			case "potion":
				System.out.println("	a) drink potion");
				break;
			case "piece of metal":
		}
	}

	//true when an item has been found
	boolean found;

	/*
	* Checks to see if a certain item is in the 
	* player's bag.
	*
	* @param String item 		the item being searched for 
	*
	* @return boolean 			returns true if item has been found,
	* 							otherwise returns false
	*/
	public boolean findItem(String item){
		for(int i = 0; i < bag.size(); i++){
			if(item.equals(bag.get(i))){
					System.out.println("Item found.");
					answer = bag.get(i);
					return true;
			}else{
				try{
					if(Integer.parseInt(item) == (i + 1)){
						System.out.println("Item found.");
						answer = bag.get(i);
						return true;
					}
				}catch(NumberFormatException e){
				}
			}
		}
		return false;
	}

	/*
	* Informs user that the item they want to use cannot 
	* be used and asks if they want to use another item.
	*/
	public void cannotUseItem(){
		System.out.println("You can't do anything with that"
			+ " right now. \nDo you want to use another item?");
		if((scan.next()).equals("yes")){
			openBag();
		}else{
			System.out.println("You have closed your bag.");
		}
	}

	/*
	* Adds an item to the player's bag.
	*
	* @param String item 		item being added to the bag
	*/
	public void addToBag(String item){
		bag.add(item);
	}

	/*
	* Checks if an item is in the bag.
	* 
	* @param String item 		the item being searched for
	*
	* @return boolean 			returns true if item is found,
	* 							otherwise returns false
	*/
	public boolean searchBag(String item){
		return bag.contains(item);
	}
}