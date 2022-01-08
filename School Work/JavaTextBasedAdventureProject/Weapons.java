/**
 * title: Weapons.java
 * description: This class contains the methods for 
 * weapon creation and attack.
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
 * public Weapons(){<BR>
 	Creates a Weapons object that can use any of the methods 
	or variables in the class.

 * public void makeWeapon(String clas){<BR>
 	Creates a weapon based on the class chosen by the player.

 * public void assassinWeapon(){<BR>
 	Makes a dagger for the assassin class.

 * public void wizardWeapon(){<BR>
 	Makes a wand for the wizard class.

 * public void shapeshiftWeapon(){<BR>
 	Makes a wolf form necklace for the shapeshifter class.

 * public void attack(Enemy enemy){<BR>
 	Implements Alice's attack and has a 1/3 chance of missing the 
	target.
 * </P>
 */

/************************************************************
 * VARIABLES
 ************************************************************
 * <H3> Variables Used </H3>
 *
 * <P>
 *	String name; - name of the weapon
 *
 *	int attackDamage; - amount of damage the weapon does
 * </P>
 */
public class Weapons{

	/*
	* Creates a Weapons object that can use any of the methods 
	* or variables in the class.
	*/
	public Weapons(){
		
	}

	//name of the weapon
	String name;

	//amount of damage the weapon does
	int attackDamage;

	/*
	* Creates a weapon based on the class chosen by the player.
	*
	* @param String clas 		the class of the character
	*/
	public void makeWeapon(String clas){

		switch(clas){
		case "assassin":
			assassinWeapon();
			break;

		case "wizard":
			wizardWeapon();
			break;

		case "shapeshifter":
			shapeshiftWeapon();
			break;

		default:
			break;
		}//end of switch statement
	}//end of makeWeapon method

	/*
	* Makes a dagger for the assassin class.
	*/
	public void assassinWeapon(){
		//damage is a random number between 30 and 60
		name = "dagger";
		attackDamage = (int)((Math.random() * 30) + 30);
		System.out.println("You have found a dagger with " + attackDamage + " attack damage!");
		System.out.println();
	}

	/*
	* Makes a wand for the wizard class.
	*/
	public void wizardWeapon(){
		name = "wand";
		attackDamage = (int)((Math.random() * 30) + 30);
		System.out.println("You have found a wand with " + attackDamage + " attack damage!");
		System.out.println();
	}

	/*
	* Makes a wolf form necklace for the shapeshifter class.
	*/
	public void shapeshiftWeapon(){
		name = "necklace";
		attackDamage = (int)((Math.random() * 30) + 30);
		System.out.println("You have found a necklace with " + attackDamage + " attack damage!");
		System.out.println();
	}	

	/*
	* Implements Alice's attack and has a 1/3 chance of missing the 
	* target.
	*
	* @param Enemy enemy 		the enemy Alice is fighting
	*/
	public void attack(Enemy enemy){
		int chance = (int)((Math.random() * 3) + 1);
		System.out.println("*****ATTACK*****");
		if(chance > 1){
			System.out.println("You attack the target and do " + attackDamage + " damage.");
			enemy.setCurrentHealth(attackDamage);
		}else{
			System.out.println("Your attack missed!");
		}
	}
}