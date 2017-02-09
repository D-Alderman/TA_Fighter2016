/*
 * Story.cpp
 * Story controls all the story elements of the game
 *
 *  Created on: Jul 20, 2016
 *      Author: celxius
 */

#include <iostream>
#include "Story.h"

using namespace std;

//openingStory starts the story off
void openingStory() {
	cout << "\nYou awake with a start. Today is finally the day! You are going to start your epic journey to become the top TA \n"
			"in all of COP3503. You've trained for months, and finally you feel ready. You head out to your first challenge. \n";
}

//chakraIntro introduces Chakra
void chakraIntro() {
	cout << endl;
	cout << "Your quest for class domination takes you into the early morning, where you spend your free time at the French Fry sculpture on campus. \n"
			"Every morning you gather here to train in the arts of Code, and every day you feel yourself get stronger. \n"
			"Today is different however. There is another person training in your spot." << endl << endl;
	cout << "\"I've been waiting for you\" the stranger says. \"I've heard stories about a student who was training to \n"
			"become the best fighter this side of COP3503, and I heard that this is where they spend their mornings.\"\n"
			"\"Imagine my surprise when I discovered that it was you.\" \n"
			"\"I will test your convictions here and now.\"\n"
			"\"Prepare yourself!\" ";
	cout << endl << endl;
	cout << "Rudrasis Chakraborty challenges you to a battle!" << endl;
}

//chakraOutro plays when he is defeated
void chakraOutro() {
	cout << "\nWhen the dust clears, only one person is left standing outside the French Fry sculpture. \n"
			"You stand over TA Chakraborty, and help him up to his feet. \n"
			"\"That was an excellent battle.\" he says to you \"You just may have what it takes to be the top TA in this class.\"\n"
			"\"Go forth, and find your next challege!\"\n"
			"And with that, you move forward to the next fight.";
	cout << endl << endl;
}

//islamIntro introduces Islam
void islamIntro() {
	cout << endl;
	cout << "Your path to be the best TA in the class takes you to the bowels of the computer science building. You've heard the \n"
			"legends of a TA who was once the strongest, and think that he could teach you how to achieve your dreams. \n"
			"As you approach the lab rooms the air grows heavy, and you can feel the energy cackling in the air. \n"
			"You see a lone man coding at a keyboard, the furious pounding of the keys is the only sound in the room. \n"
			"After a few moments, the sounds at the keyboard stop, and the man stands up. "
			"When is is up, he turns towards you...and without a word he extends his arm out in challenge" << endl;
	cout << endl << endl;
	cout << "Minhazul Islam challenges you to a battle!" << endl;

}

//islamOutro plays when he is defeated
void islamOutro() {
	cout << "\nTA Islam reels back from your last blow, but seems to gather himself without falling over. \n"
			"He brushes himself off and sits at the computer he was at prior to your fight. He nods at you and points to the door, all without uttering a word. \n"
			"He then sets back to coding what he was working on...\n"
			"You nod in return, and walk out to face your next challenge.";
	cout << endl << endl;
}

//mishraIntro introduces Mishra
void mishraIntro() {
	cout << "You walk into the classroom at the bottom of the computer science building, and you find doors open. They almost look inviting. \n"
			"As you step into the class, you see Professor Mishra standing near the front welcoming you in. \n"
			"\"I have been waiting for you to arrive.\" he says. \"Ever since the first class, I had a sneaking suspicion that you would be the one who would challenge me in the end.\"\n"
			"\"Well, let us not waste any time, let's get on with it.\" He waves his arms, and the doors to the classroom close. The white screen lifts up, and the lights get brighter. \n"
			"He motions for you to come forward and claim the spot as top Professor.";
	cout << endl << endl;
	cout << "Subhankar Mishra challenges you to a battle!" << endl;
}

//mishraOutro plays when he is defeated
void mishraOutro() {
	cout << "Professor Mishra lets out a thunderous applause. \"That was truly magnificent! A battle worthy of the Professor title. I am proud to be able to pass it along to \n"
			" someone who deserves it. Please step forward and kneel.\"\n"
			"You walk up to the front of the classroom and kneel before Professor Mishra. From today onward you will be known as Professor! Now go forward and educate others in the "
			"ways of C++. Your skills will surely survive the tests of time!" << endl << endl;

	cout << "At last, you have completed your goal of becoming the Professor of the COP3503 class! You feel a deep sense of pride within. You vow to continue honing your skills so that \n"
			"you will be ready for all the challenges ahead of you.";
	cout << endl << endl;
}

//watneyIntro introduces Watney
void watneyIntro() {
	cout << "\nYou are overcome with elation at being designated the new Professor of the COP3503 class. You decide to head over to the Reitz Union, to celebrate by watching a movie \n"
			"and getting some popcorn at Gator Nights. As you walk over the North Lawn, your eyes are inexplicably drawn to the sky. One of the stars \n"
			"is twinkling a bit brighter than the rest. You take a moment to stare at it, and you realize that it is no star, it's an object...something is \n"
			"falling. It's getting closer and closer. It's a ship! You take cover behind a tree and shield yourself from the crash!" << endl << endl;

	cout << "The bay doors open up, and you can hear the pressure being released. Steam emerges from the door, and out pops an astronaut. He finds you behind the tree. \n"
			"\"My name is Watney, Mark Watney. And I was stranded out in space. I had heard of a class of students who sent me a program \n"
			"that would triangulate my distance to my ship from any point on Mars, and they designed a communications tool using the hexadecimal \n"
			"language. I heard that they did this as the result of an assignment for their class. What they don't know is that their professor launched \n"
			"me in that ship...just to get their students to code a solution to a real problem!\"" << endl << endl;

	cout << "\"I'm looking for their professor...I know that they are near. My sensors indicate the presence of a strong professor nearby.\" \n"
			"He checks his sensor watch, and baffled, looks at you again. \"It was you! You're the one who sent me up there. At long last, I will \n"
			"have my revenge!\"";
	cout << endl << endl;
	cout << "Mark Watney challenges you to a battle!" << endl;
}

//watneyOutro plays when he is defeated
void watneyOutro() {
	cout << "The astronaut staggers to his knees and grips his chest. You take this brief moment to explain that you are the newly appointed Professor, \n"
			"and not the one who sent him into space. You show him your new badge and title. \n"
			"\"I see...says the astronaut...so it wasn't you. My quest for vengeance continues then...\"\n"
			"And just as quickly as he came, he was gone." << endl << endl;

	cout << "It had certainly been an odd encounter, but you decide to put it out of your mind. Determined to relax, you head into the \n"
			"Reitz Union, and watch the movie playing in the auditorium.";

	cout << endl << endl;
}

//starknightIntro introduces Starknight
void starknightIntro() {
	cout << "The movie was fantastic! The popcorn was at the perfect level of salty and all-around it was an A+ evening. \n"
			"You decide to make your way back home, and head over to the Reitz Union bus stop. As you exit out to the amphitheater \n"
			"there appears to be a bright light out by the seats closest to the water. Naturally, you move to investigate. \n"
			"You reach your hand out to touch the light, and you can feel a strange pull. It feels as if your hands are being tugged \n"
			"away from your body. You are lifted up off of the ground, and vanish in a flash of light." << endl << endl;

	cout << "You travel through the expanses of space, and within mere minutes, find yourself on a planet. There is just one \n"
			"inhabitant. She doesn't say a single word to you.\n"
			"\"...\"\n\"...\"\n\"...\"\n" << endl;

	cout << "Lucy Starknight challenges you to a battle!" << endl;
}

//starknightOutro plays when she is defeated
void starknightOutro() {
	cout << "\"...\"\n\"...\"\n\"...\"\n" << endl;
	cout << "Credits \n"
			"Lead Programmer: Damian Alderman \n\n"
			"Lead Writer: Damian Alderman" << endl << endl;
}
