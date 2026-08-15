#include "validate.hpp"
#include <SFML/Graphics.hpp>
using namespace std;
int main(){
    Board a=Board();
    a.display();
    cout<<"\n";
    sf::RenderWindow window(
        sf::VideoMode({480, 480}),
        "Chess Board"
    );
    sf::Texture black_pawn;
    (void)black_pawn.loadFromFile("texture/B_pawn.png");

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

        for(int r=0;r<8;r++)
        {
            for(int c=0;c<8;c++)
            {
                sf::RectangleShape square({60.f,60.f});
                square.setPosition({60.f*c,60.f*r});

                if((r+c)%2==0)
                    square.setFillColor(
                        sf::Color(240,217,181)
                    );
                else
                    square.setFillColor(
                        sf::Color(181,136,99)
                    );

                window.draw(square);
            }
        }
        for(int c = 0; c < 8; c++){
                sf::Sprite pawn(black_pawn);
                pawn.setPosition({c * 60.f, 60.f});
                window.draw(pawn);
            }

        window.display();
    }
    // cout<<validate(a,7,4,6,4)<<endl;
    // cout<<validate(a,7,1,5,0)<<endl;
    // cout<<validate(a,7,0,7,5)<<endl;
    // cout<<validate(a,4,0,4,7)<<endl;
}