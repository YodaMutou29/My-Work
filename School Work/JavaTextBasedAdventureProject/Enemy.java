/**
 * title: Enemy.java
 * description: This class contains the methods for 
 * the enemies' attacks and health. It also contains 
 * information about enemies such as their names.
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
 * public Enemy(String enemy){<BR>
 	Creates an enemy object with a name and current 
	health.

 * public void setCurrentHealth(int damage){<BR>
 	Setter method for the currentHealth variable.
	Does not allow for negative health.

 * public int getCurrentHealth(){<BR>
 	Getter function for the currentHealth variable.

 * public boolean healthStatus(){<BR>
 	Tells how many health points the enemy has and whether they've 
	been defeated or not.

 * public void enemyAttack(Inventory invent){<BR>
 	Plays out a turn in fight for the enemy.

 * public boolean fightMechanics(Inventory invent, Weapons weapon){<BR>
 	Plays out a fight for Alice.

 * public String getEnemyName(){<BR>
 	Getter method for the enemy name.
 * </P>
 */

/************************************************************
 * VARIABLES
 ************************************************************
 * <H3> Variables Used </H3>
 *
 * <P>
 *	Scanner scan = new Scanner(System.in); - the Scanner used 
 *	in this class
 *
 *	private String enemyName; - the name of the enemy
 *
 *	private int currentHealth; - the enemy's health points
 * </P>
 */
/*
* ROUGH DRAFT ENEMIES
* bat attacks while falling in hole (dives at you)
* caterpillar attacks before you can get mushroom (blows smoke)
* guard (throws paint at you which stuns you, then spins to cut you)
* queen of hearts is final boss (she does a jump pound thing)
*/
import java.util.Scanner;

public class Enemy{

	//the Scanner used in this class
	Scanner scan = new Scanner(System.in);

	//the name of the enemy
	private String enemyName;

	/*
	* Creates an enemy object with a name and current 
	* health.
	*
	* @param String enemy 			the name of the enemy
	*/
	public Enemy(String enemy){
		enemyName = enemy;
		currentHealth = 100;
	}

	//the enemy's health points
	private int currentHealth;

	/*
	* Setter method for the currentHealth variable.
	* Does not allow for negative health.
	*
	* @param int damage 		the damage done to the enemy
	*/
	public void setCurrentHealth(int damage){
		currentHealth = currentHealth - damage;
		if (currentHealth < 0){
			currentHealth = 0;
		}
	}

	/*
	* Getter function for the currentHealth variable.
	*
	* @return int currentHealth 		the enemy's health points
	*/
	public int getCurrentHealth(){
		return currentHealth;
	}

	/*
	* Tells how many health points the enemy has and whether they've 
	* been defeated or not.
	*
	* @return boolean 			returns true if the enemy has been defeated 
	* 							otherwise returns false
	*/
	public boolean healthStatus(){
		System.out.println("The " + enemyName + " now has " + currentHealth 
			+ " health points.");
		if(currentHealth <= 0){
			System.out.println("You've defeated the " + enemyName);
			return true;
		}
		return false;
	}

	/*
	* Plays out a turn in fight for the enemy.
	* 
	* @param Inventory invent 			the player's inventory
	*/
	public void enemyAttack(Inventory invent){
		System.out.println("The " + enemyName + " attacks you!");
		invent.hearts = invent.hearts - (float)(0.25);
		System.out.println("You lose 1/4 of a heart and now have " + invent.hearts + " hearts.");
	}

	/*
	* Plays out a fight for Alice.
	* 
	* @param Inventory invent 			the player's inventory
	* @param Weapons weapon 			the player's weapon
	*
	* @return boolean 					returns true if enemy is defeated
	*/
	public boolean fightMechanics(Inventory invent, Weapons weapon){
		while(healthStatus() == false){
			System.out.println("Press enter to continue fight.");
			if((scan.nextLine()).equals("")){
				enemyAttack(invent);
				weapon.attack(this);
			}
		}
		return true;
	}

	/*
	* Getter method for the enemy name.
	*
	* @return String enemyName 			the enemy's name
	*/
	public String getEnemyName(){
		return enemyName;
	}

}