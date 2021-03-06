#ifndef PROJECT_KEYBOARDINPUT_HPP
#define PROJECT_KEYBOARDINPUT_HPP

#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"

using namespace std;
using namespace sf;


class KeyboardInput {
    struct Button {
        bool up, down, right, left, jump, enter;
    };

private:

    // Variables pour les événements et les bouttons du jeu
    Event event;
    Button button;

    Sound           _sound;
    SoundBuffer     _stageClearSound;
    SoundBuffer     _jumpSound;
    SoundBuffer     _stompSound;
    Music           _musicBackground;
    enum {
        up, down, right, left, jump, enter
    };

public:

    // Constructeur, on initialise toutes les entrées à faux
    KeyboardInput() {
        button.left = false;
        button.right = false;
        button.up = false;
        button.down = false;
        button.jump = false;
        button.enter = false;
    }

    // Accesseur des entrées
    Button getButton() const {
        return button;
    }

    // Setteur des entrées
    void setButton(int theButton, bool state) {
        switch (theButton) {
            case left:
                button.left = state;
                break;

            case right:
                button.right = state;
                break;

            case up:
                button.up = state;
                break;

            case down:
                button.down = state;
                break;

            case jump:
                button.jump = state;
                break;

            case enter:
                button.enter = state;
                break;
        }
    }

    // Pour gérer le clavier
    void inputManagement(RenderWindow &window) { getKeyboardInput(window); }

    void playJumpSound()
    {
        if(!_jumpSound.loadFromFile("soundsV2/jump.wav"))
            cout << L"Le son pour Jump na pas pu être chargé" << endl;
        else
        {
            _sound.setBuffer(_jumpSound);
            _sound.setVolume(100.0);
            _sound.play();
        }
    }


    void playStompSound()
    {
        if(!_stompSound.loadFromFile("sounds/stomp.wav"))
            cout << L"Le son de Stomp n'a pas pu être chargé" << endl;
        else
        {
            _sound.setBuffer(_stompSound);
            _sound.play();
        }
    }




    // Permet de récupérer les input depuis la fenêtre de jeu
    void getKeyboardInput(RenderWindow &window) {
        // Boucle des événements
        while (window.pollEvent(event)) {
            // Gestion des différents cas d'événements
            switch (event.type) {
                // Si on ferme la fenêtre
                case Event::Closed:
                    window.close();
                    break;

                    // Si on appuie sur une touche du clavier
                case Event::KeyPressed:
                    // On regarde sur quelle touche on a appuyé
                    switch (event.key.code) {
                        case Keyboard::Space:
                            button.jump = true;
                            playJumpSound();
                            break;

                        case Keyboard::Up:
                            button.up = true;
                            break;

                        case Keyboard::Down:
                            button.down = true;
                            break;

                        case Keyboard::Left:
                            button.left = true;
                            break;

                        case Keyboard::Right:
                            button.right = true;
                            break;

                        case Keyboard::Return:
                            button.enter = true;
                            break;

                        default:
                            break;
                    }
                    break;

                    // Si on relâche une touche du clavier
                case Event::KeyReleased:
                    // On regarde quelle touche a été relâchée
                    switch (event.key.code) {
                        case Keyboard::Space:
                            button.jump = false;
                            break;

                        case Keyboard::Up:
                            button.up = false;
                            break;

                        case Keyboard::Down:
                            button.down = false;
                            break;

                        case Keyboard::Left:
                            button.left = false;
                            break;

                        case Keyboard::Right:
                            button.right = false;
                            break;

                        case Keyboard::Return:
                            button.enter = false;
                            break;

                        default:
                            break;
                    }
                    break;
                    // Pas d'autre événement
                default:
                    break;
            }
        }
    }

};

#endif //PROJECT_KEYBOARDINPUT_HPP
