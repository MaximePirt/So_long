#include <ncurses.h>

int	main(void)
{
	initscr();            // Initialisation de ncurses
	keypad(stdscr, TRUE); // Activation du mode clavier étendu

	while (1)
	{
		int ch = getch(); // Lecture de la touche
		printw("Code de la touche : %d\n", ch);
		// Affichage du code de la touche
		refresh();
		// Rafraîchissement de l'affichage
	}

	endwin(); // Fermeture de ncurses
	return (0);
}